#include "TestStates.hpp"
#include "../entity/TestEntity.hpp"
#include "../util/Math.hpp"
#include <iostream>
#include <random>
#include <SFML/Window/Mouse.hpp>

using namespace state;
using namespace test;

// PatrolState
void PatrolState::enter(entity::TestEntity* entity)
{
	entity->color = sf::Color(100, 225, 100);
}

void PatrolState::execute(entity::TestEntity* entity)
{
	m_patrol.update(entity->getPosition());
	entity->setVelocity(m_patrol.getVelocity(entity->getPosition(), 2.5f));

	if (criteria(entity))
	{
		m_patrol.reset();
		entity->getStateMachine()->changeState(new RouteState(sf::Mouse::getPosition()), entity);
	}
}

void PatrolState::exit(entity::TestEntity* entity)
{

}

bool PatrolState::criteria(entity::TestEntity* entity) const
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

PatrolState* PatrolState::instance()
{
	static PatrolState instance;
	return &instance;
}


// RouteState
void RouteState::enter(entity::TestEntity* entity)
{
	entity->color = sf::Color(225, 100, 100);
}

void RouteState::execute(entity::TestEntity* entity)
{
	if (!m_route.destinationReached())
	{
		m_route.update(entity->getPosition());
		entity->setVelocity(m_route.getVelocity(entity->getPosition(), 5));
	}

	if (criteria(entity))
	{
		m_route.reset();
		entity->getStateMachine()->changeState(new PatrolState(), entity);
	}
}

void RouteState::exit(entity::TestEntity* entity)
{

}

bool RouteState::criteria(entity::TestEntity* entity) const
{
	return m_route.destinationReached();
}

RouteState* RouteState::instance()
{
	static RouteState instance;
	return &instance;
}
