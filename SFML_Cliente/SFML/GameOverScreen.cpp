#include "GameOverScreen.h"
#include <iostream>

GameOverScreen::GameOverScreen()
{
	if (font.loadFromFile("../Fonts/Stilda.otf"))
	{
		textoFinal.setFont(font);
		textoFinal.setCharacterSize(48);
		textoFinal.setFillColor(sf::Color::Black);
	}
	else
	{
		std::cerr << "No se ha cargado el otf correctamente";
	}
}

void GameOverScreen::drawGameOverScreen(sf::RenderWindow& window)
{
	window.draw(textoFinal);
}
