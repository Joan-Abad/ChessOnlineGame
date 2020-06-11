#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Tablero.h"

class Pieza;
class Tablero;
extern enum ColorPieza;

enum estadoDelJuego {
	BuscandoPartida,
	EnPartida,
	FinalDeLaPartida
};
class PlayerInput
{
public:
	PlayerInput();

private:
	bool isPressed = false;
	bool firstClick = false;
	sf::Vector2i mousePosition;
	Pieza* PiezaEscojida;
	Pieza* piezaBug;
	sf::Vector2i posiciones[2];
	sf::Color markerColor = sf::Color::Red;	
		
public:
	Tablero *tablero;
	ColorPieza ColorFichasJugador;
	estadoDelJuego gameStatus;
};

