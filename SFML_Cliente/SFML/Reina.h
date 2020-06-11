#pragma once
#include "Pieza.h"
class Reina : public Pieza
{
public:
	Reina(Tablero& tablero, ColorPieza CP);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
};

