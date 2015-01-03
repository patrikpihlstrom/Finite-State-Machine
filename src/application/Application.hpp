#pragma once
#include <iostream>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../entity/TestEntity.hpp"

class Application
{
public:
	Application();
	~Application();
	
private:
	void initialize();

	void run();

	void handleEvents();
	void update(sf::Time & deltaTime);
	void render();

	bool m_running, m_active;

	sf::RenderWindow m_window;

	entity::TestEntity m_testEntity;
};