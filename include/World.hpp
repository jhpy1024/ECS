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
        void registerSystem();

        template <typename T>
        std::shared_ptr<T> addComponent(unsigned id);

        template <typename T>
        bool hasComponent(unsigned id);

        template <typename T>
        bool hasComponents(unsigned id);

        template <typename First, typename Second, typename... Others>
        bool hasComponents(unsigned id);

        template <typename T>
        std::shared_ptr<T> getComponent(unsigned id);

        template <typename T>
        void removeComponent(unsigned id);

        template <typename T>
        std::vector<unsigned> getEntitiesWithComponent();

        template <typename First, typename... Others>
        std::vector<unsigned> getEntitiesWithComponents();

    private:
        EntityMap m_Entities;
        unsigned m_LatestEntityID;

        std::vector<std::shared_ptr<BaseSystem>> m_Systems;
};

#include "World.inl"

#endif
