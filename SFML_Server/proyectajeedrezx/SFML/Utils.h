#pragma once
#include "SFML/Graphics.hpp"
#include <string>

extern enum ColorPieza;
class Pieza; 
class Utils
{
public:
	Utils();

	static float &getTamanoPieza(sf::RenderWindow& window);
	static void DebugPieza(Pieza& pieza);
	static void InitializeSprite(sf::Sprite& sprite, sf::Texture& texture, ColorPieza CP, std::string address);
	
	
	static void SetSpriteSize(sf::Sprite &sprite, float scaleXY);
	static void SetSpriteSize(sf::Sprite& sprite, sf::Vector2f scaleXY);
	

	static void PrintVector2(sf::Vector2f vector2);
	static void PrintVector2(sf::Vector2i vector2);
};

