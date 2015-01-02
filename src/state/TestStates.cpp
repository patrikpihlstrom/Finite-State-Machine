#include "TestStates.hpp"
#include "../entity/TestEntity.hpp"
#include <iostream>

void TestState::enter(TestEntity* entity)
{

}

void TestState::execute(TestEntity* entity)
{
	entity->setPosition(sf::Vector2<float>(500, 500));
}

void TestState::exit(TestEntity* entity)
{

}

bool TestState::criteria(TestEntity* entity) const
{

}

TestState* TestState::instance()
{
	static TestState instance;
	return &instance;
}
