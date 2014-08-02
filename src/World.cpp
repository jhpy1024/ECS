#include "World.hpp"

World::World()
    : m_LatestEntityID(0)
{
}

void World::handleInput()
{
    for (auto& system : m_Systems)
        system->handleInput(m_Entities);
}

void World::update(float delta)
{
    for (auto& system : m_Systems)
        system->update(delta, m_Entities);
}

void World::draw()
{
    for (auto& system : m_Systems)
        system->draw(m_Entities);
}

unsigned World::createEntity()
{
    unsigned id = m_LatestEntityID;

    while (hasEntity(id))
        ++id;

    m_LatestEntityID = id;
    m_Entities[id] = EntityComponents();

    return id;
}

void World::removeEntity(unsigned id)
{
    if (hasEntity(id))
        m_Entities.erase(id);
}

void World::removeAllEntities()
{
    m_Entities.clear();
}

bool World::hasEntity(unsigned id) const
{
    return (m_Entities.find(id) != m_Entities.end());
}
