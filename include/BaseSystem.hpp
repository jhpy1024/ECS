#ifndef BASE_SYSTEM_HPP
#define BASE_SYSTEM_HPP

class World;
class BaseSystem
{
    public:
        virtual void handleInput(World& world);
        virtual void update(float delta, World& world);
        virtual void draw(World& world);
};

#endif
