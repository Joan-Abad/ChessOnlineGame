#include "Tablero.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"
#include "Peon.h"

Tablero::Tablero()
{
	CrearPiezas();
}

void Tablero::CrearPiezas()
{
	sf::Vector2f PosicionPiezas{ 0,0 };

	float X = 0, Y = 0;


	for (int i = 0; i < 64; i++)
	{
		if (i > -1 && i < 16)
		{
			Piece* piece = new Piece;
			piece->posicionPieza = sf::Vector2f(X, Y);
			piece->colorPiece = Negra;
			piezas.push_back(piece);
		}
		if (i > 47 && i < 64)
		{
			Piece* piece = new Piece;
			piece->posicionPieza = sf::Vector2f(X, Y);
			piece->colorPiece = Blanca;
			piezas.push_back(piece);
		}
		X += 64;
		
		
		if (i == 7 || i == 15 || i == 23 || i == 31 ||
			i == 38 || i == 47 || i == 55 || i == 63)
		{
			X = 0;
			Y += 64;
		}

	}

	std::cout << "dfsdf";
}


	