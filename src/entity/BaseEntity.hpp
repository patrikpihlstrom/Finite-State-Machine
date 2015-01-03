#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace entity
{
	class BaseEntity : public sf::Drawable
	{
	public:
		BaseEntity()
		{}

		virtual ~BaseEntity()
		{}

		virtual void update() = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		void setPosition(const sf::Vector2f& position)
		{
			m_position = position;
		}

		sf::Vector2<float> getPosition() const
		{
			return m_position;
		}

		sf::Vector2<float> getVelocity() const
		{
			return m_velocity;
		}

	protected:
		sf::Vector2<float> m_position, m_velocity;
	};
}
