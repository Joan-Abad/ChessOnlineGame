#pragma once
#include "Pieza.h"
class Caballo : public Pieza
{
public:
	Caballo(Tablero& tablero, ColorPieza CP);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
};

