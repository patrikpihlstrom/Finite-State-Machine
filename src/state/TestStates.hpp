#pragma once
#include "BaseState.hpp"
#include "../Waypoint/Route.hpp"
#include <SFML/System/Vector2.hpp>

namespace entity
{
	class TestEntity;
}

namespace state
{
	namespace test
	{
		class GoToState : public BaseState<entity::TestEntity>
		{
		private:
			Route<float> m_route;

			GoToState()
			{
				m_route.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 - 128, 720/2 - 128)));
				m_route.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 + 128, 720/2 - 128)));
				m_route.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 + 128, 720/2 + 128)));
				m_route.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 - 128, 720/2 + 128)));
			}
			
			GoToState(const GoToState&);
			GoToState& operator=(const GoToState&);

		public:
			static GoToState* instance();
			
			void enter(entity::TestEntity* entity);
			void execute(entity::TestEntity* entity);
			void exit(entity::TestEntity* entity);

			bool criteria(entity::TestEntity* entity) const;
		};
	}
}
