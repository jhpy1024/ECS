#include <iostream>

#include "World.hpp"
#include "BaseSystem.hpp"

class TestSystem : public BaseSystem
{
    public:
        void handleInput(EntityMap& entities) override
        {
            std::printf("handleInput() - %lu entities\n", entities.size());
        }

        void update(float delta, EntityMap& entities) override
        {
            std::printf("update() - %lu entities\n", entities.size());
        }

        void draw(EntityMap& entities) override
        {
            std::printf("draw() - %lu entities\n", entities.size());
        }
};

int main()
{
    World world;
    world.registerSystem<TestSystem>();
    world.createEntity();

    world.handleInput();
    world.update(1.f);
    world.draw();

    return 0;
}
