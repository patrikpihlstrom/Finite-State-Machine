#include "TestStates.hpp"
#include "../entity/TestEntity.hpp"
#include "../util/Math.hpp"
#include <iostream>

using namespace state;
using namespace test;

void GoToState::enter(entity::TestEntity* entity)
{

}

void GoToState::execute(entity::TestEntity* entity)
{
	if (m_route == NULL || !m_route->destinationReached())
	{
		m_route->update(entity->getPosition());
		entity->setVelocity(m_route->getVelocity(entity->getPosition(), 5));

		if (m_route->destinationReached())
		{
			delete m_route;
		}
	}
	else
	{
		m_patrol.update(entity->getPosition());
		entity->setVelocity(m_patrol.getVelocity(entity->getPosition(), 2.5f));
	}
}

void GoToState::exit(entity::TestEntity* entity)
{

}

bool GoToState::criteria(entity::TestEntity* entity) const
{
	return m_patrol.destinationReached();
}

GoToState* GoToState::instance()
{
	static GoToState instance;
	return &instance;
}
