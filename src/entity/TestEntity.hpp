#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "BaseEntity.hpp"
#include "../state/StateMachine.hpp"
#include "../state/TestStates.hpp"

namespace entity
{
	class TestEntity : public BaseEntity
	{
	private:
		StateMachine<TestEntity>* m_stateMachine;
	
	public:
		sf::Color color;

		TestEntity() :
			BaseEntity()
		{
			m_stateMachine = new StateMachine<TestEntity>();
			m_stateMachine->setCurrentState(new state::test::PatrolState());
		}

		~TestEntity()
		{}

		void update()
		{
			m_position += m_velocity;
			m_stateMachine->update(this);
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			sf::CircleShape circleShape(16);
			circleShape.setOrigin(sf::Vector2f(16, 16));
			circleShape.setPosition(m_position);
			circleShape.setFillColor(color);

			target.draw(circleShape, states);
		}

		StateMachine<TestEntity>* getStateMachine() const
		{
			return m_stateMachine;
		}
	};
}
