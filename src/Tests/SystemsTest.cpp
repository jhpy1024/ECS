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
        void handleInput(EntityMap& entities) override
        {
            std::printf("handleInput() - %lu entities\n", entities.size());
        }

        void update(float delta, EntityMap& entities) override
        {
            std::printf("update() - %lu entities\n", entities.size());

            for (auto& pair : entities)
            {
                auto pos = std::static_pointer_cast<PosComp>(pair.second["Pos"]);
                pos->x += 10;
                pos->y += 20;
            }
        }

        void draw(EntityMap& entities) override
        {
            std::printf("draw() - %lu entities\n", entities.size());
        }
};

/* int main() */
/* { */
/*     World world; */
/*     world.registerSystem<TestSystem>(); */

/*     auto entity = world.createEntity(); */
/*     auto position = world.addComponent<PosComp>(entity); */
/*     std::printf("Position before (%d,%d)\n", position->x, position->y); */

/*     world.handleInput(); */
/*     world.update(1.f); */
/*     world.draw(); */

/*     std::printf("Position after (%d,%d)\n", position->x, position->y); */
/*     return 0; */
/* } */
