#ifndef WORLD_HPP
#define WORLD_HPP

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "BaseSystem.hpp"
#include "BaseComponent.hpp"

using EntityComponents = std::unordered_map<std::string, std::shared_ptr<BaseComponent>>;
using EntityMap = std::unordered_map<unsigned, EntityComponents>;

class World
{
    public:
        World();

        void handleInput();
        void update(float delta);
        void draw();

        unsigned createEntity();
        void removeEntity(unsigned id);
        void removeAllEntities();
        bool hasEntity(unsigned id) const;

        template <typename T>
        void registerSystem()
        {
            auto system = std::make_shared<T>();
            m_Systems.push_back(system);
        }

        template <typename T>
        std::shared_ptr<BaseComponent> addComponent(unsigned id)
        {
            if (!hasEntity(id))
            {
                std::cerr << "[Error] Unable to add component to entity as it does not exist"
                          << " so returning nullptr." << std::endl;
                return nullptr;
            }

            auto component = std::make_shared<T>();
            m_Entities[id][component->ID] = component;

            return component;
        }

        template <typename T>
        bool hasComponent(unsigned id)
        {
            if (!hasEntity(id))
            {
                std::cerr << "[Error] Unable to check if entity has that component as the entity does not exist." << std::endl;
                return false;
            }

            auto targetComponentID = T().ID;
            return m_Entities[id].count(targetComponentID) > 0;
        }

        template <typename First, typename Second, typename... Others>
        bool hasComponents(unsigned id)
        {
            return (hasComponent<First>(id) && hasComponents<Second, Others...>(id));
        }

        template <typename T>
        std::shared_ptr<T> getComponent(unsigned id)
        {
            auto targetComponentID = T().ID;

            if (!hasEntity(id))
            {
                std::cerr << "[Error] Unable to get component with ID \"" << targetComponentID << "\" because the entity does not exist"
                          << " so returning nullptr." << std::endl;
                return nullptr;
            }

            if (!hasComponent<T>(id))
            {
                std::cerr << "[Error] Unable to get component with ID \"" << targetComponentID << "\" because it does not exist" 
                          << " so returning nullptr." << std::endl;
                return nullptr;
            }

            for (auto& componentMap : m_Entities[id])
            {
                auto currentComponentID = componentMap.first;
                if (currentComponentID == targetComponentID)
                    return std::static_pointer_cast<T>(componentMap.second);
            }

            return nullptr;
        }

        template <typename T>
        void removeComponent(unsigned id)
        {
            auto targetComponentID = T().ID;

            if (!hasEntity(id))
            {
                std::cerr << "[Error] Unable to remove component with ID \"" << targetComponentID << "\" because the entity does not exist."
                          << std::endl;
                return;
            }

            if (!hasComponent<T>(id))
            {
                std::cerr << "[Error] Unable to remove component with ID \"" << targetComponentID << "\" because it does not exist."
                          << std::endl;
                return;
            }

            m_Entities[id].erase(targetComponentID);
        }

    private:
        EntityMap m_Entities;
        unsigned m_LatestEntityID;

        std::vector<std::shared_ptr<BaseSystem>> m_Systems;
};

#endif
