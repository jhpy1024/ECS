#ifndef BASE_SYSTEM_HPP
#define BASE_SYSTEM_HPP

#include <string>
#include <memory>
#include <unordered_map>

#include "BaseComponent.hpp"

using EntityComponents = std::unordered_map<std::string, std::shared_ptr<BaseComponent>>;
using EntityMap = std::unordered_map<unsigned, EntityComponents>;

class BaseSystem
{
    public:
        virtual void handleInput(EntityMap& entities);
        virtual void update(float delta, EntityMap& entities);
        virtual void draw(EntityMap& entities);
};

#endif
