#include "Reina.h"

Reina::Reina(Tablero& tablero, ColorPieza CP) : Pieza(tablero, CP)
{
	nombrePieza = "reina";
	float tamañoPieza = Utils::getTamanoPieza(*this->tablero->ventanaActiva);
	Utils::InitializeSprite(sprite, texture, CP, "../img/Reina");
	Utils::SetSpriteSize(sprite, tamañoPieza);
}

void Reina::MovimientoPieza(sf::Vector2i posicionPiezas)
{
	sf::Vector2f posicionPieza
	{
		float(posicionPiezas.x),
		float(posicionPiezas.y)
	};
	sprite.setPosition(posicionPieza);	
}

