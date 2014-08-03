#ifndef WORLD_INL
#define WORLD_INL

template <typename T>
void World::registerSystem()
{
    auto system = std::make_shared<T>();
    m_Systems.push_back(system);
}

template <typename T>
std::shared_ptr<BaseComponent> World::addComponent(unsigned id)
{
    if (!hasEntity(id))
    {
        std::cerr << "[Error] Unable to add component to entity as it does not exist"
            << " so returning nullptr." << std::endl;
        return nullptr;
    }

    auto component = std::make_shared<T>();
    m_Entities[id][component->ID] = component;

    return component;
}

template <typename T>
bool World::hasComponent(unsigned id)
{
    if (!hasEntity(id))
    {
        std::cerr << "[Error] Unable to check if entity has that component as the entity does not exist." << std::endl;
        return false;
    }

    auto targetComponentID = T().ID;
    return m_Entities[id].count(targetComponentID) > 0;
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
    {
        std::cerr << "[Error] Unable to get component with ID \"" << targetComponentID << "\" because the entity does not exist"
            << " so returning nullptr." << std::endl;
        return nullptr;
    }

    if (!hasComponent<T>(id))
    {
        std::cerr << "[Error] Unable to get component with ID \"" << targetComponentID << "\" because it does not exist" 
            << " so returning nullptr." << std::endl;
        return nullptr;
    }

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
    {
        std::cerr << "[Error] Unable to remove component with ID \"" << targetComponentID << "\" because the entity does not exist."
            << std::endl;
        return;
    }

    if (!hasComponent<T>(id))
    {
        std::cerr << "[Error] Unable to remove component with ID \"" << targetComponentID << "\" because it does not exist."
            << std::endl;
        return;
    }

    m_Entities[id].erase(targetComponentID);
}

#endif
