#include <iostream>

#include "World.hpp"
#include "BaseSystem.hpp"

struct PosComp : BaseComponent
{
    PosComp() : BaseComponent("Pos") {} 

    int x;
    int y;
};

class TestSystem : public BaseSystem
{
    public:
        void handleInput(World& world) override
        {
        }

        void update(float delta, World& world) override
        {
            for (auto ent : world.getEntitiesWithComponent<PosComp>())
            {
                auto pos = world.getComponent<PosComp>(ent);
                pos->x += 10;
                pos->y += 20;
            }
        }

        void draw(World& world) override
        {
        }
};

int main()
{
    World world;
    world.registerSystem<TestSystem>();

    auto entity = world.createEntity();
    auto position = world.addComponent<PosComp>(entity);
    std::printf("Position before (%d,%d)\n", position->x, position->y);

    world.handleInput();
    world.update(1.f);
    world.draw();

    std::printf("Position after (%d,%d)\n", position->x, position->y);
    return 0;
}
