#pragma once
#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace math
{
	template <typename T>
	float distance(const sf::Vector2<T>& a, const sf::Vector2<T>& b)
	{
		return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
	}
}