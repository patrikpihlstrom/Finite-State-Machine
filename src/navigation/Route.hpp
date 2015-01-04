#pragma once
#include <vector>
#include <cassert>
#include "Waypoint.hpp"
#include "../util/Math.hpp"
#include <iostream>

template <typename T>
class Route
{
private:
	std::vector<Waypoint<T>> m_waypoints;
	unsigned int m_index;
	bool m_destinationReached;

public:
	Route() :
		m_index(0),
		m_destinationReached(false)
	{}

	~Route()
	{}

	void addWaypoint(const Waypoint<T> waypoint)
	{
		m_waypoints.push_back(waypoint);
	}

	void increment()
	{
		m_index++;

		if (m_index >= m_waypoints.size())
		{
			m_destinationReached = true;
		}
	}

	const Waypoint<T>& getCurrentWaypoint() const
	{
		assert(m_index < m_waypoints.size());

		return m_waypoints[m_index];
	}

	void update(const sf::Vector2<T>& entityPosition)
	{
		if (!m_destinationReached)
		{
			float distance = math::distance<T>(entityPosition, getCurrentWaypoint().getPosition());
			
			if (distance == 0)
			{
				increment();
			}
		}
	}

	sf::Vector2<T> getVelocity(const sf::Vector2<T>& entityPosition, const float desiredSpeed = 10) const
	{
		if (!m_destinationReached)
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
		else
		{
			return sf::Vector2<T>(0, 0);
		}
	}

	bool destinationReached() const
	{
		return m_destinationReached;
	}

	void reset()
	{
		m_index = 0;
		m_destinationReached = 0;
	}
};
