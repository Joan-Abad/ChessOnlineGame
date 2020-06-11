#pragma once
#include "SFML/Graphics.hpp"

class GameOverScreen
{
public:
	GameOverScreen();
	void drawGameOverScreen(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text textoFinal;

public:
	sf::Text &getTextoFinal() { return textoFinal; };
};

