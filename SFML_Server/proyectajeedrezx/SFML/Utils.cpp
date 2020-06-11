#include "Utils.h"
#include "Pieza.h"

Utils::Utils()
{
}

float& Utils::getTamanoPieza(sf::RenderWindow& window)
{
	float medidaPieza = window.getSize().x / 8;
	return medidaPieza;
	//  TODO: Insertar una instrucción "return" aquí
}

void Utils::DebugPieza(Pieza& pieza)
{
	std::cout << "\n\nPosicion pieza: ";
	std::cout << "\nX: " << pieza.GetSprite().getPosition().x / 64;
	std::cout << "\nY: " << pieza.GetSprite().getPosition().y / 64;

	std::cout << "\n\n";

	}

void Utils::InitializeSprite(sf::Sprite& sprite, sf::Texture& texture, ColorPieza CP, std::string address)
{
	if (CP == Negra)
	{
		address += "N.png";
		if (texture.loadFromFile(address))
			std::cout << "\n " << address << " cargado correctamente.";
		else
			std::cout << address << " no se ha podido cargar correctamente.";
	}
	else
	{
		address += "B.png";
		if (texture.loadFromFile(address))
			std::cout << "\n " << address << " cargado correctamente.";
		else
			std::cout << address << " no se ha podido cargar correctamente.";
	}

	sprite.setTexture(texture);
}

void Utils::SetSpriteSize(sf::Sprite& sprite, float scaleXY)
{
	sprite.setScale(scaleXY / static_cast<float>(sprite.getTexture()->getSize().x), 
	scaleXY / static_cast<float>(sprite.getTexture()->getSize().x));
}

void Utils::SetSpriteSize(sf::Sprite& sprite, sf::Vector2f scaleXY)
{
	sprite.setScale(scaleXY.x / static_cast<float>(sprite.getTexture()->getSize().x),
	scaleXY.y/ static_cast<float>(sprite.getTexture()->getSize().x));
}

void Utils::PrintVector2(sf::Vector2f vector2)
{
	std::cout << "\n\nPrinting vector 2: ";
	std::cout << "\nX: " << vector2.x;
	std::cout << "\nY: " << vector2.y;
}

void Utils::PrintVector2(sf::Vector2i vector2)
{
	std::cout << "\n\nPrinting vector 2: ";
	std::cout << "\nX: " << vector2.x;
	std::cout << "\nY: " << vector2.y;
}


