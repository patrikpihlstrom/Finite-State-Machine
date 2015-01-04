#pragma once
#include "BaseState.hpp"
#include "../navigation/Patrol.hpp"
#include "../navigation/Route.hpp"
#include <SFML/System/Vector2.hpp>
#include <memory>

namespace entity
{
	class TestEntity;
}

namespace state
{
	namespace test
	{
		class PatrolState : public BaseState<entity::TestEntity>
		{
		private:
			Patrol<float> m_patrol;

			PatrolState()
			{
				m_patrol.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 - 128, 720/2 + 128)));
				m_patrol.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 + 128, 720/2 + 128)));
				m_patrol.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 + 128, 720/2 - 128)));
				m_patrol.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2 - 128, 720/2 - 128)));
			}
			
			PatrolState(const PatrolState&);
			PatrolState& operator=(const PatrolState&);

		public:
			static PatrolState* instance();
			
			void enter(entity::TestEntity* entity);
			void execute(entity::TestEntity* entity);
			void exit(entity::TestEntity* entity);

			bool criteria(entity::TestEntity* entity) const;
		};

		class RouteState : public BaseState<entity::TestEntity>
		{
		private:
			Route<float> m_route;

			RouteState()
			{
				m_route.addWaypoint(Waypoint<float>(sf::Vector2<float>(0, 0)));
				m_route.addWaypoint(Waypoint<float>(sf::Vector2<float>(1280/2, 720/2)));
			}
			
			RouteState(const RouteState&);
			RouteState& operator=(const RouteState&);

		public:
			static RouteState* instance();
			
			void enter(entity::TestEntity* entity);
			void execute(entity::TestEntity* entity);
			void exit(entity::TestEntity* entity);

			bool criteria(entity::TestEntity* entity) const;
		};
	}
}
