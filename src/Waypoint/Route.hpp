#pragma once
#include <vector>
#include "Waypoint.hpp"

template <typename T>
class Route
{
private:
	std::vector<const Waypoint<T>> m_waypoints;
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
	}

	const Waypoint<T>& getCurrentWaypoint() const
	{
		return m_waypoints[m_index];
	}
};
