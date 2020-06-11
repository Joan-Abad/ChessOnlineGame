#pragma once
#include "Pieza.h"
class Torre : public Pieza
{
public: 
	Torre(Tablero& tablero, ColorPieza CP);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
};

