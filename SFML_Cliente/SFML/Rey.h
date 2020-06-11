#pragma once
#include "Pieza.h"
class Rey : public Pieza
{
public:
	Rey(Tablero& tablero, ColorPieza CP);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
};

