#pragma once
#include "BaseState.hpp"
#include <typeinfo>
#include <cassert>
#include <memory>

template <class entity_type>
class StateMachine
{
private:
	state::BaseState<entity_type>* m_currentState;
	state::BaseState<entity_type>* m_globalState;

	bool newCurrentState, newGlobalState;

public:
	StateMachine() :
		m_currentState(NULL),
		m_globalState(NULL),
		newCurrentState(false),
		newGlobalState(false)
	{}
	
	virtual ~StateMachine(){}

	void setCurrentState(state::BaseState<entity_type>* state)
	{
		m_currentState = state;

		newCurrentState = true;
	}

	void setGlobalState(state::BaseState<entity_type>* state)
	{
		m_globalState = state;

		newGlobalState = true;
	}
	
	void update(entity_type* entity)
	{
		if (m_globalState)
		{
			if (newGlobalState)
			{
				m_globalState->enter(entity);
				newGlobalState = false;
			}

			m_globalState->execute(entity);
		}

		if (m_currentState)
		{
			if (newCurrentState)
			{
				m_currentState->enter(entity);
				newCurrentState = false;
			}

			m_currentState->execute(entity);
		}
	}

	void changeState(state::BaseState<entity_type>* newState, entity_type* entity)
	{
		assert(newState && "<StateMachine::changeState>: trying to change to NULL state");

		m_currentState->exit(entity);

		delete m_currentState;

		m_currentState = newState;

		m_currentState->enter(entity);
	}

	bool isInState(const state::BaseState<entity_type>& state) const
	{
		return typeid(*m_currentState) == typeid(state);
	}

	bool currentStateCriteria(entity_type* entity) const
	{
		return m_currentState->criteria(entity);
	}

	bool globalStateCriteria(entity_type* entity) const
	{
		return m_globalState->criteria(entity);
	}
};
