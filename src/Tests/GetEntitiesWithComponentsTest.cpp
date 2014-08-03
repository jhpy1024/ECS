#include <cassert>
#include <iostream>

#include "World.hpp"

struct FirstComp : BaseComponent
{
    FirstComp() : BaseComponent("First") {}
};

struct SecondComp : BaseComponent
{
    SecondComp() : BaseComponent("Second") {}
};

struct ThirdComp : BaseComponent
{
    ThirdComp() : BaseComponent("Third") {}
};

/* int main() */
/* { */
/*     World world; */

/*     auto ent1 = world.createEntity(); */
/*     auto ent2 = world.createEntity(); */
/*     auto ent3 = world.createEntity(); */

/*      // ent1: FirstComp, SecondComp, ThirdComp */
/*      // ent2: SecondComp, ThirdComp */
/*      // ent3: ThirdComp */

/*     world.addComponent<FirstComp>(ent1); */
/*     world.addComponent<SecondComp>(ent1); */
/*     world.addComponent<ThirdComp>(ent1); */

/*     world.addComponent<SecondComp>(ent2); */
/*     world.addComponent<ThirdComp>(ent2); */

/*     world.addComponent<ThirdComp>(ent3); */

/*     auto ents = world.getEntitiesWithComponents<FirstComp,SecondComp,ThirdComp>(); */
/*     std::vector<unsigned> expected = { ent1 }; */
/*     assert(ents == expected); */

/*     ents = world.getEntitiesWithComponents<SecondComp, ThirdComp>(); */
/*     expected = { ent2, ent1 }; */
/*     assert(ents == expected); */

/*     ents = world.getEntitiesWithComponents<ThirdComp>(); */
/*     expected = { ent3, ent2, ent1 }; */
/*     assert(ents == expected); */

/*     return 0; */
/* } */
