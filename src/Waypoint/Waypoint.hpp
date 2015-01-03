#pragma once
#include <SFML/System/Vector2.hpp>

template <typename T>
class Waypoint
{
private:
	sf::Vector2<T> m_position;

public:
	Waypoint(const sf::Vector2<T>& position) :
		m_position(position)
	{}

	sf::Vector2<T> getPosition() const
	{
		return m_position;
	}
};
