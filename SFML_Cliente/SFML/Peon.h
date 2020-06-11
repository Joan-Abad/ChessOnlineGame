#pragma once
#include "Pieza.h"

class Peon : public Pieza
{
public:
	Peon(Tablero& tablero, ColorPieza CP);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
	
};

