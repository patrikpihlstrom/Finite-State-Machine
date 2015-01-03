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
		BaseEntity() :
			m_position(sf::Vector2<float>(1280/2, 720/2)),
			m_velocity(sf::Vector2<float>(0, 0))
		{}

		virtual ~BaseEntity()
		{}

		virtual void update() = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		sf::Vector2<float> getPosition() const
		{
			return m_position;
		}

		sf::Vector2<float> getVelocity() const
		{
			return m_velocity;
		}

		void setPosition(const sf::Vector2f& position)
		{
			m_position = position;
		}

		void setVelocity(const sf::Vector2f& velocity)
		{
			m_velocity = velocity;
		}

	protected:
		sf::Vector2<float> m_position, m_velocity;
	};
}
