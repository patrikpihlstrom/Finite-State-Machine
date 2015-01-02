#pragma once
#include "BaseState.hpp"
#include <SFML/System/Vector2.hpp>

	class TestEntity;

	class TestState : public BaseState<TestEntity>
	{
	private:
		TestState()
		{}
		
		TestState(const TestState&);
		TestState& operator=(const TestState&);

	public:
		static TestState* instance();
		
		void enter(TestEntity* entity);
		void execute(TestEntity* entity);
		void exit(TestEntity* entity);

		bool criteria(TestEntity* entity) const;
	};
