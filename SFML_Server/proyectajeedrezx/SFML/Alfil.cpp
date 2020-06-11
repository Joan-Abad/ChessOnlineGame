#include "Alfil.h"


Alfil::Alfil(ManejoConexiones& MC)
{
	this->MC = &MC;
}

void Alfil::MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
{
	moverHaciaDelante = true;
	std::vector <sf::Vector2i> posiblesPosiciones;
	int contador = 1;
	bool fillValues = true;
	bool fichaMovida = false;
	bool movimientoFueraDeRango = true;
	int numeroFichaAComer = 0;

	sf::Vector2i posXY;
	// Mirar a que direción va la ficha
	int xDifference = posicionPiezas[1].x - posicionPiezas[0].x;
	int yDifference = posicionPiezas[1].y - posicionPiezas[0].y;

	// Mover el alfil arriba a la izquierda
	if (xDifference < 0 && yDifference < 0)
	{
		int X = posicionPiezas[0].x;
		int Y = posicionPiezas[0].y;

		while (fillValues)
		{
			X--;
			Y--;

			sf::Vector2i posicionPosible = { X * 64, Y * 64 };
			posiblesPosiciones.push_back(posicionPosible);

			if (X == 0 || Y == 0 || X == 7 || Y == 7)
				fillValues = false;
		}

		// Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
		for (int j = 0; j < posiblesPosiciones.size(); j++)
		{
			for (int i = 0; i < MC->tablero->piezas.size(); i++)
			{
				int tableroX = MC->tablero->piezas[i]->posicionPieza.x;
				int tableroY = MC->tablero->piezas[i]->posicionPieza.y;


				// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
				// En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 
				if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
				{
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;
					numeroFichaAComer = i;
					fichaMovida = true;
					//Jugador mueve fichas blancas
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.x += 64;
							posXY.y += 64;
						}
						//Ficha en tablero es negra
						else
						{
							//Nada
							std::cout << "\nMismo Color";
						}
					}
					//Jugador mueve fichas negras
					else if (colorFicha == 1)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							//Nada
							std::cout << "\nMismo Color";
						}
						//Ficha en tablero es negra
						else
						{
							posXY.x -= 64;
							posXY.y -= 64;
						}
					}
					i = MC->tablero->piezas.size();
					j = posiblesPosiciones.size();
				}
				if (fichaMovida == false)
				{
					posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
				}


			}
		}

		// Si la torre va a su máxima rango(posible pieza)
		if ((posicionPiezas[1].y * 64) == posXY.y && ((posicionPiezas[1].x * 64) == posXY.x))
		{
			if (idFicha > -1)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
			else
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}

		}
		else if ((posicionPiezas[1].y * 64) > posXY.y && (posicionPiezas[1].x * 64 > posXY.x))
		{
			for (int i = 0; i < posiblesPosiciones.size(); i++)
			{
				if (posiblesPosiciones[i].x == posicionPiezas[1].x * 64 && posiblesPosiciones[i].y == posicionPiezas[1].y * 64)
				{
					movimientoFueraDeRango = false;
				}
			}

			if (movimientoFueraDeRango == false)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
		}
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
	}
	// Mover el alfil arriba a la derecha
	else if (xDifference > 0 && yDifference < 0)
	{
		int X = posicionPiezas[0].x;
		int Y = posicionPiezas[0].y;

		while (fillValues)
		{
			X++;
			Y--;

			sf::Vector2i posicionPosible = { X * 64, Y * 64 };
			posiblesPosiciones.push_back(posicionPosible);

			if (X == 0 || Y == 0 || X == 7 || Y == 7)
				fillValues = false;
		}

		// Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero.
		for (int j = 0; j < posiblesPosiciones.size(); j++)
		{
			for (int i = 0; i < MC->tablero->piezas.size(); i++)
			{


				int tableroX = MC->tablero->piezas[i]->posicionPieza.x;
				int tableroY = MC->tablero->piezas[i]->posicionPieza.y;


				// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha.
				// En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre.
				if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
				{
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;
					numeroFichaAComer = i;
					//Jugador mueve fichas blancas
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.x -= 64;
							posXY.y += 64;
						}
						//Ficha en tablero es negra
						else
						{
							//Nada
							std::cout << "\nMismo Color";
						}
					}
					//Jugador mueve fichas negras
					else if (colorFicha == 1)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							//Nada
							std::cout << "\nMismo Color";
						}
						//Ficha en tablero es negra
						else
						{
							posXY.x += 64;
							posXY.y -= 64;
						}
					}
					i = MC->tablero->piezas.size();
					j = posiblesPosiciones.size();
					fichaMovida = true;
				}
				if (fichaMovida == false)
				{
					posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
				}
			}
		}

		// Si el alfil va a su máxima rango(posible pieza)
		if ((posicionPiezas[1].y * 64) == posXY.y && ((posicionPiezas[1].x * 64) == posXY.x))
		{
			if (idFicha > -1)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
			else
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}

		}
		//Si el alfil no llega al límite de su permitido
		else if ((posicionPiezas[1].y * 64) > posXY.y && (posicionPiezas[1].x * 64) < posXY.x)
		{
			for (int i = 0; i < posiblesPosiciones.size(); i++)
			{
				if (posiblesPosiciones[i].x == posicionPiezas[1].x * 64 && posiblesPosiciones[i].y == posicionPiezas[1].y * 64)
				{
					movimientoFueraDeRango = false;
				}
			}

			if (movimientoFueraDeRango == false)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
		}
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
	}
	
	//Mover el alfil abajo a la derecha
	else if (xDifference > 0 && yDifference > 0)
	{
		std::cout << "\nAlfil quiere ir abajo a la derecha";
		int X = posicionPiezas[0].x;
		int Y = posicionPiezas[0].y;

		while (fillValues)
		{
			X++;
			Y++;

			sf::Vector2i posicionPosible = { X , Y };
			posiblesPosiciones.push_back(posicionPosible);

			if (X == 0 || Y == 0 || X == 7 || Y == 7)
				fillValues = false;
		}

		// Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero.
		for (int j = 0; j < posiblesPosiciones.size(); j++)
		{
			for (int i = 0; i < MC->tablero->piezas.size(); i++)
			{


				int tableroX = MC->tablero->piezas[i]->posicionPieza.x / 64;
				int tableroY = MC->tablero->piezas[i]->posicionPieza.y / 64;


				// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha.
				// En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre.
				if ((posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY) && (posicionPiezas[0].y < posiblesPosiciones[j].y && posicionPiezas[0].x < posiblesPosiciones[j].x))
				{
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;
					numeroFichaAComer = i;
					//Jugador mueve fichas blancas
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.x -= 1;
							posXY.y -= 1;
						}
						//Ficha en tablero es negra
						else
						{
							//Nada
							std::cout << "\nMismo Color";
						}
					}
					//Jugador mueve fichas negras
					else if (colorFicha == 1)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							//Nada
							std::cout << "\nMismo Color";
						}
						//Ficha en tablero es negra
						else
						{
							posXY.x += 1;
							posXY.y += 1;
						}
					}
					i = MC->tablero->piezas.size();
					j = posiblesPosiciones.size();
				}
				else
				{
					posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
				}


			}
		}

		// Si la torre va a su máxima rango(posible pieza)
		if (posicionPiezas[1].y == posXY.y && posicionPiezas[1].x == posXY.x)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}

		// En caso de que la torre no vaya a su máximo rango...
		else if (posicionPiezas[1].y < posXY.y && posicionPiezas[1].x < posXY.x)
		{
			for (int i = 0; i < posiblesPosiciones.size(); i++)
			{
				if (posiblesPosiciones[i] == posicionPiezas[1])
				{
					movimientoFueraDeRango = false;
				}
			}

			if (movimientoFueraDeRango == false)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);

			}
		}
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}

	}
	//Mover el alfil abajo a la izquierda
	else if (xDifference < 0 && yDifference > 0)
	{
		std::cout << "\nAlfil quiere ir abajo a la izquierda";

		int X = posicionPiezas[0].x;
		int Y = posicionPiezas[0].y;

		while (fillValues)
		{
			X--;
			Y++;

			sf::Vector2i posicionPosible = { X, Y };
			posiblesPosiciones.push_back(posicionPosible);

			if (X == 0 || Y == 0 || X == 7 || Y == 7)
				fillValues = false;
		}

		for (int j = 0; j < posiblesPosiciones.size(); j++)
		{
			for (int i = 0; i < MC->tablero->piezas.size(); i++)
			{
				// Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero.

				int tableroX = MC->tablero->piezas[i]->posicionPieza.x / 64;
				int tableroY = MC->tablero->piezas[i]->posicionPieza.y / 64;;

				// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha.
				// En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre.
				if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
				{
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;
					numeroFichaAComer = i;

					//Jugador mueve fichas blancas
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.x += 1;
							posXY.y += 1;
						}
						//Ficha en tablero es negra
						else
						{
							//Nada
							std::cout << "\nMismo Color";
						}
					}
					//Jugador mueve fichas negras
					else if (colorFicha == 1)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							//Nada
							std::cout << "\nMismo Color";
						}
						//Ficha en tablero es negra
						else
						{
							posXY.x -= 1;
							posXY.y -= 1;
						}
					}

					i = MC->tablero->piezas.size();
					j = posiblesPosiciones.size();
					fichaMovida = true;
				}
				if (fichaMovida == false)
				{
					posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
				}
			}

		}

		if (posicionPiezas[1].y == posXY.y && posicionPiezas[1].x == posXY.x)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
		else if (posicionPiezas[1].y < posXY.y && posicionPiezas[1].x > posXY.x)
		{
			for (int i = 0; i < posiblesPosiciones.size(); i++)
			{
				if (posiblesPosiciones[i] == posicionPiezas[1])
				{
					movimientoFueraDeRango = false;
				}
			}

			if (movimientoFueraDeRango == false)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
		}
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}

	}
	else
	{
		InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
	}


}
