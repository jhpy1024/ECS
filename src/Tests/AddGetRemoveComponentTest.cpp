#include "World.hpp"
#include "BaseComponent.hpp"

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

    std::printf("Has PositionComponent: %d\n", world.hasComponent<PositionComponent>(entity));
    std::printf("Has OtherComponent: %d\n", world.hasComponent<OtherComponent>(entity));
    std::printf("Position (%f,%f)\n", posComp->x, posComp->y);

    world.removeComponent<PositionComponent>(entity);

    std::printf("Has PositionComponent: %d\n", world.hasComponent<PositionComponent>(entity));
    std::printf("Has OtherComponent: %d\n", world.hasComponent<OtherComponent>(entity));

    world.getComponent<PositionComponent>(entity);

    return 0;
}
