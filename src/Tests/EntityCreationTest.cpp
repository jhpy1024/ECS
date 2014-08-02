#include <chrono>
#include <fstream>
#include <iostream>

#include "World.hpp"

/* int main() */
/* { */
/*     World world; */

/*     std::ofstream outputFile("out.csv"); */

/*     for (unsigned n = 100; n <= 10000000; n += 100000) */
/*     { */
/*         std::chrono::time_point<std::chrono::system_clock> startTime = std::chrono::system_clock::now(); */
/*         for (unsigned i = 0; i < n; ++i) */
/*             world.createEntity(); */
/*         std::chrono::time_point<std::chrono::system_clock> endTime = std::chrono::system_clock::now(); */
/*         std::chrono::duration<double> elapsedTime = endTime - startTime; */
/*         std::cout << "Created " << n << " entities in " << elapsedTime.count() << " seconds" << std::endl; */

/*         outputFile << n << "," << elapsedTime.count() << std::endl; */

/*         world.removeAllEntities(); */
/*     } */

/*     return 0; */
/* } */
