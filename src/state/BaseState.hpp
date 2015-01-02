#pragma once
#include <memory>

	template <class entity_type>
	class BaseState
	{
	public:
		virtual ~BaseState(){}

		virtual void enter(entity_type*) = 0;
		virtual void execute(entity_type*) = 0;
		virtual void exit(entity_type*) = 0;

		virtual bool criteria(entity_type*) const = 0;
	};	

