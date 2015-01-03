#pragma once
#include <vector>
#include "Waypoint.hpp"
#include "../util/Math.hpp"
#include <iostream>

template <typename T>
class Route
{
private:
	std::vector<Waypoint<T>> m_waypoints;
	unsigned int m_index;

public:
	Route() :
		m_index(0)
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
			m_index = 0;
		}
	}

	const Waypoint<T>& getCurrentWaypoint() const
	{
		return m_waypoints[m_index];
	}

	void update(const sf::Vector2<T>& entityPosition)
	{
		if (math::distance<float>(entityPosition, getCurrentWaypoint().getPosition()) <= 86)
		{
			//std::cout << "Incrementing.\n";
			increment();
		}
	}
};
