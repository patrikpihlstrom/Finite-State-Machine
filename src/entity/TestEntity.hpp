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
		TestEntity() :
			BaseEntity()
		{
			m_stateMachine = new StateMachine<TestEntity>();
			m_stateMachine->setCurrentState(state::test::GoToState::instance());
		}

		~TestEntity()
		{}

		void update()
		{
			m_stateMachine->update(this);
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			sf::CircleShape circleShape(16);
			circleShape.setPosition(m_position);
			circleShape.setFillColor(sf::Color(100, 225, 100));

			target.draw(circleShape, states);
		}

		StateMachine<TestEntity>* getStateMachine() const
		{
			return m_stateMachine;
		}
	};
}
