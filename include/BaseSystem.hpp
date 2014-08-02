#ifndef BASE_SYSTEM_HPP
#define BASE_SYSTEM_HPP

#include "World.hpp"

class BaseSystem
{
    public:
        virtual void handleInput(EntityMap& entities);
        virtual void update(float delta, EntityMap& entities);
        virtual void draw(EntityMap& entities);
};

#endif
