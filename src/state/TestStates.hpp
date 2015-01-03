#pragma once
#include "BaseState.hpp"
#include <SFML/System/Vector2.hpp>

namespace entity
{
	class TestEntity;
}

namespace state
{
	namespace test
	{
		class TestState : public BaseState<entity::TestEntity>
		{
		private:
			TestState()
			{}
			
			TestState(const TestState&);
			TestState& operator=(const TestState&);

		public:
			static TestState* instance();
			
			void enter(entity::TestEntity* entity);
			void execute(entity::TestEntity* entity);
			void exit(entity::TestEntity* entity);

			bool criteria(entity::TestEntity* entity) const;
		};
	}
}
