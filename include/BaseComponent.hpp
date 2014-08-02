#ifndef BASE_COMPONENT_HPP
#define BASE_COMPONENT_HPP

#include <string>

struct BaseComponent
{
    BaseComponent(const std::string& id);

    const std::string ID;
};

#endif
