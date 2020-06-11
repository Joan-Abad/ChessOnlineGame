#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Pieza.h"
#include "Utils.h"
#include "PlayerInput.h"

class PlayerInput;
class Pieza;
struct Piece
{
	ColorPieza colorPiece;
	sf::Vector2f posicionPieza;
};
class Tablero
{
public:
	Tablero();

private:
	void CrearPiezas();
	
public:
	std::vector<Piece*> piezas;


};

