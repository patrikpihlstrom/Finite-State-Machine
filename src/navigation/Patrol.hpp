#pragma once
#include <vector>
#include <cassert>
#include "Waypoint.hpp"
#include "../util/Math.hpp"
#include <iostream>

template <typename T>
class Patrol
{
private:
	std::vector<Waypoint<T>> m_waypoints;
	unsigned int m_index, m_count;
	bool m_endOfLine;

public:
	Patrol() :
		m_index(0),
		m_count(0),
		m_endOfLine(false)
	{}

	~Patrol()
	{}

	void addWaypoint(const Waypoint<T> waypoint)
	{
		m_waypoints.push_back(waypoint);
	}

	void increment()
	{
		m_index++;

		m_endOfLine = false;

		if (m_index >= m_waypoints.size())
		{
			m_index = 0;
			m_count++;

			m_endOfLine = true;
		}
	}

	const Waypoint<T>& getCurrentWaypoint() const
	{
		assert(m_index < m_waypoints.size());

		return m_waypoints[m_index];
	}

	void update(const sf::Vector2<T>& entityPosition)
	{
		float distance = math::distance<T>(entityPosition, getCurrentWaypoint().getPosition());
		
		if (distance == 0)
		{
			increment();
		}
	}

	sf::Vector2<T> getVelocity(const sf::Vector2<T>& entityPosition, const float desiredSpeed = 10) const
	{
		float angle = math::toDegrees<T>(math::angle<T>(entityPosition, getCurrentWaypoint().getPosition()));
		float distance = math::distance<T>(entityPosition, getCurrentWaypoint().getPosition());

		float velx = (getCurrentWaypoint().getPosition().x - entityPosition.x)/distance;
		float vely = (getCurrentWaypoint().getPosition().y - entityPosition.y)/distance;

		if (desiredSpeed < distance)
		{
			velx *= desiredSpeed;
			vely *= desiredSpeed;
		}
		else
		{
			velx *= distance;
			vely *= distance;
		}

		return sf::Vector2<T>(velx, vely);
	}

	unsigned int getCount() const
	{
		return m_count;
	}

	bool endOfLine() const
	{
		return m_endOfLine;
	}

	void reset()
	{
		m_index = 0;
		m_count = 0;
		m_endOfLine = false;
	}
};
