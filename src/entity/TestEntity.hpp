#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "BaseEntity.hpp"
#include "../state/StateMachine.hpp"
#include "../state/TestStates.hpp"


	class TestEntity : public BaseEntity
	{
	private:
		StateMachine<TestEntity>* m_stateMachine;
	
	public:
		TestEntity() :
			BaseEntity()
		{
			m_stateMachine = new StateMachine<TestEntity>();
			m_stateMachine->setCurrentState(TestState::instance());
		}

		~TestEntity()
		{}

		void update()
		{
			m_stateMachine->update(this);
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			sf::CircleShape circleShape(32);
			circleShape.setPosition(m_position);
			circleShape.setFillColor(sf::Color(255, 0, 0));

			target.draw(circleShape, states);
		}

		StateMachine<TestEntity>* getStateMachine() const
		{
			return m_stateMachine;
		}
	};

