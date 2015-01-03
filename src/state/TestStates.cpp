#include "TestStates.hpp"
#include "../entity/TestEntity.hpp"
#include <iostream>

using namespace state;
using namespace test;

void TestState::enter(entity::TestEntity* entity)
{

}

void TestState::execute(entity::TestEntity* entity)
{
	entity->setPosition(sf::Vector2<float>(500, 500));
}

void TestState::exit(entity::TestEntity* entity)
{

}

bool TestState::criteria(entity::TestEntity* entity) const
{

}

TestState* TestState::instance()
{
	static TestState instance;
	return &instance;
}
