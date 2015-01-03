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
	
	float angle = math::toDegrees<float>(math::angle(entity->getPosition(), m_route.getCurrentWaypoint().getPosition()));
	entity->setVelocity(sf::Vector2<float>(std::cos(angle)*5, std::sin(angle)*5));
	entity->setPosition(sf::Vector2<float>(entity->getPosition().x + entity->getVelocity().x, entity->getPosition().y + entity->getVelocity().y));
	m_route.update(entity->getPosition());
}

void GoToState::exit(entity::TestEntity* entity)
{

}

bool GoToState::criteria(entity::TestEntity* entity) const
{
	return false;
}

GoToState* GoToState::instance()
{
	static GoToState instance;
	return &instance;
}
