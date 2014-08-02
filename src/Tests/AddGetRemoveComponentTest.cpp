#include "World.hpp"
#include "BaseComponent.hpp"

#include <cassert>
#include <iostream>

struct PositionComponent : BaseComponent
{
    PositionComponent()
        : BaseComponent("Position")
        , x(1.f)
        , y(2.f)
    {
    }

    float x;
    float y;
};

struct OtherComponent : BaseComponent
{
    OtherComponent()
        : BaseComponent("Other")
    {
    }
};

int main()
{
    World world;

    auto entity = world.createEntity();
    world.addComponent<PositionComponent>(entity);
    world.addComponent<OtherComponent>(entity);
    auto posComp = world.getComponent<PositionComponent>(entity);

    assert(world.hasComponent<PositionComponent>(entity) == true);
    assert(world.hasComponent<OtherComponent>(entity) == true);

    world.removeComponent<PositionComponent>(entity);

    assert(world.hasComponent<PositionComponent>(entity) == false);
    assert(world.hasComponent<OtherComponent>(entity) == true);

    return 0;
}
