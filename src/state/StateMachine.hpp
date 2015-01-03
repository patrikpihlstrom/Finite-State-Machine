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
	state::BaseState<entity_type>* m_previousState;
	state::BaseState<entity_type>* m_globalState;

public:
	StateMachine() :
		m_currentState(NULL),
		m_previousState(NULL),
		m_globalState(NULL)
	{}
	
	virtual ~StateMachine(){}

	void setCurrentState(state::BaseState<entity_type>* state)
	{
		m_currentState = state;
	}

	void setPreviousState(state::BaseState<entity_type>* state)
	{
		m_previousState = state;
	}

	void setGlobalState(state::BaseState<entity_type>* state)
	{
		m_globalState = state;
	}
	
	void update(entity_type* entity)
	{
		if (m_globalState)
		{
			m_globalState->execute(entity);
		}

		if (m_currentState)
		{
			m_currentState->execute(entity);
		}
	}

	void changeState(state::BaseState<entity_type>* newState, entity_type* entity)
	{
		assert(newState && "<StateMachine::ChangeState>: trying to change to NULL state");

		m_previousState = m_currentState;

		m_currentState->exit(entity);

		m_currentState = newState;

		m_currentState->enter(entity);
	}

	void revertToPreviousState()
	{
		changeState(m_previousState);
	}

	bool isInState(const state::BaseState<entity_type>& state) const
	{
		return typeid(*m_currentState) == typeid(state);
	}
};
