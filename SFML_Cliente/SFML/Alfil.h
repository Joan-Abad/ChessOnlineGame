#pragma once
#include "Pieza.h"

extern enum ColorPieza;
class Alfil : public Pieza
{
public:
	Alfil(Tablero& tablero, ColorPieza CP);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
};

