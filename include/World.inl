#ifndef WORLD_INL
#define WORLD_INL

#include <vector>
#include <memory>
#include <stdexcept>

template <typename T>
void World::registerSystem()
{
    auto system = std::make_shared<T>();
    m_Systems.push_back(system);
}

template <typename T>
std::shared_ptr<T> World::addComponent(unsigned id)
{
    if (!hasEntity(id))
        throw std::runtime_error("Unable to add component as the entity does not exist.");

    auto component = std::make_shared<T>();
    m_Entities[id][component->ID] = component;

    return component;
}

template <typename T>
bool World::hasComponent(unsigned id)
{
    if (!hasEntity(id))
        throw std::runtime_error("Unable to determine if the entity has that component as the entity does not exist.");

    auto targetComponentID = T().ID;
    return m_Entities[id].count(targetComponentID) > 0;
}

template <typename T>
bool World::hasComponents(unsigned id)
{
    return hasComponent<T>(id);
}

template <typename First, typename Second, typename... Others>
bool World::hasComponents(unsigned id)
{
    return (hasComponent<First>(id) && hasComponents<Second, Others...>(id));
}

template <typename T>
std::shared_ptr<T> World::getComponent(unsigned id)
{
    auto targetComponentID = T().ID;

    if (!hasEntity(id))
        throw std::runtime_error("Unable to get component from entity as the entity does not exist.");

    if (!hasComponent<T>(id))
        throw std::runtime_error("Unable to get component from entity as the component does not exist.");

    for (auto& componentMap : m_Entities[id])
    {
        auto currentComponentID = componentMap.first;
        if (currentComponentID == targetComponentID)
            return std::static_pointer_cast<T>(componentMap.second);
    }

    return nullptr;
}

template <typename T>
void World::removeComponent(unsigned id)
{
    auto targetComponentID = T().ID;

    if (!hasEntity(id))
        throw std::runtime_error("Unable to remove component from entity as the entity does not exist.");

    if (!hasComponent<T>(id))
        throw std::runtime_error("Unable to remove component from entity as the component does not exist.");

    m_Entities[id].erase(targetComponentID);
}

template <typename T>
std::vector<unsigned> World::getEntitiesWithComponent()
{
    std::vector<unsigned> entities;

    for (auto& pair : m_Entities)
        if (hasComponent<T>(pair.first))
            entities.push_back(pair.first);

    return entities;
}

template <typename First, typename... Others>
std::vector<unsigned> World::getEntitiesWithComponents()
{
    std::vector<unsigned> entities;

    for (auto& pair : m_Entities)
        if (hasComponents<First, Others...>(pair.first))
            entities.push_back(pair.first);

    return entities;
}

#endif
