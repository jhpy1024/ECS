#ifndef WORLD_HPP
#define WORLD_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "BaseComponent.hpp"

using EntityComponents = std::unordered_map<std::string, std::shared_ptr<BaseComponent>>;
using EntityMap = std::unordered_map<unsigned, EntityComponents>;

class World
{
    public:
        World();

        unsigned createEntity();
        void removeEntity(unsigned id);
        bool hasEntity(unsigned id) const;
        void removeAllEntities();

    private:
        EntityMap m_Entities;
        unsigned m_LatestEntityID;
};

#endif
