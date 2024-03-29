#include "Application.hpp"

Application::Application()
{
	run();
}

Application::~Application()
{

}

void Application::initialize()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 32;

	m_window.create(sf::VideoMode(1280, 720), "Finite State Machine", sf::Style::Close, settings);

	m_running = true;
	m_active = true;

	m_testEntity = entity::TestEntity();
}

void Application::run()
{
	initialize();

	sf::Clock dt;
	sf::Time deltaTime;
	sf::Time updateTime = sf::seconds(1.f/60.f);

	while(m_running)
	{
		deltaTime += dt.getElapsedTime();
		dt.restart();

		handleEvents();
		render();
		while (deltaTime >= updateTime && m_active)
		{
			update(deltaTime);
			deltaTime -= updateTime;
		}
	}
}

void Application::handleEvents()
{
	sf::Event event;

	while(m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_running = false;
			}
		}
	}
}

void Application::update(sf::Time & p_deltaTime)
{
	m_testEntity.update();
}

void Application::render()
{
	m_window.clear(sf::Color(46, 46, 46));

	m_window.draw(m_testEntity);

	m_window.display();
}
