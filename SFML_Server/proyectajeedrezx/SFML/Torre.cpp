#include "Torre.h"
#include <string>
#include "Utils.h"
#include "Rey.h"

Torre::Torre(ManejoConexiones& MC) : Pieza()
{
	this->MC = &MC;
}

void Torre::MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
{

	sf::Vector2i PosicionConvertida0 = { posicionPiezas[0].x * 64, posicionPiezas[0].y * 64 };
	sf::Vector2i PosicionConvertida1 = { posicionPiezas[1].x * 64, posicionPiezas[1].y * 64 };

	MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.x = PosicionConvertida1.x * 64;

	MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.y = PosicionConvertida1.y * 64;

	// Mirar a que direción va la ficha
	int xDifference = posicionPiezas[1].x - posicionPiezas[0].x;
	int yDifference = posicionPiezas[1].y - posicionPiezas[0].y;

	// Guardamos todas las posiciones a la que la torre se puede mover
	std::vector<sf::Vector2i> posiblesPosiciones;

	// Posición final limite a la cual la torre se puede mover. 
	sf::Vector2i posXY;

	// Variable para sumar todas las posibles posiciones de la torre. 
	int contador = 1;

	// Contador para saber que ficha eliminar del tablero si nos comemos una ficha. 
	int numeroFichaAComer = -1;


	// Jugador quiere mover torre hacia abajo // 10/10 no tocar más
	if (yDifference > 0)
	{
		bool fichaComida = false;
		// Rellenamos el vector posiblesPosiciones con todas las posiciones posibles de la torre según a que direción haya ido.
		for (int i = posicionPiezas[0].y + 1; i < 8; i++)
		{
			sf::Vector2i posiblePosicion{
			posicionPiezas[0].x * 64,  i * 64
			};

			posiblesPosiciones.push_back(posiblePosicion);
			contador++;
		}

		// Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero.
		for (int i = 0; i < MC->tablero->piezas.size(); i++)
		{
			int tableroX = MC->tablero->piezas[i]->posicionPieza.x;
			int tableroY = MC->tablero->piezas[i]->posicionPieza.y;

			for (int j = 0; j < posiblesPosiciones.size(); j++)
			{

				Utils::PrintVector2(MC->tablero->piezas[i]->posicionPieza);
				// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha.
				// Recojiendo el primer valor y acabamos el for, nos aseguramos tener el valor más cercano a la torre.
				if ((tableroX == posiblesPosiciones[j].x) && (tableroY == posiblesPosiciones[j].y))
				{

					/*if (tableroX != PosicionConvertida1.x && tableroY != PosicionConvertida1.y)
					{*/
					// Posicion máxima a la que se puede ir
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;
					numeroFichaAComer = i;
					
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.y -= 64;
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
							posXY.y += 64;
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
		if (PosicionConvertida1.y == posXY.y && PosicionConvertida0.x == PosicionConvertida1.x)
		{
			if (numeroFichaAComer > -1 && MC->jugadorQuiereComerFicha == true)
			{
				// Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
				// De esta manera parecerá que la pieza no se ha movido. 

				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
			else
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
		}
		// En caso de que la torre no vaya a su máximo rango...
		else if (PosicionConvertida1.y < posXY.y && PosicionConvertida1.x == PosicionConvertida1.x)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
		//Movimiento inválido
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
	}
	// Jugador quiere mover torre hacia arriba // 10/10 no tocar más 
	else if (yDifference < 0)
	{
		contador = 1;
		int numeroFichaAComer = -1;

		// Rellenamos el vector posiblesPosiciones con todas las posiciones posibles de la torre según a que direción haya ido. 
		for (int i = posicionPiezas[0].y - 1; i >= 0; i--)
		{
			sf::Vector2i posiblePosicion{
			posicionPiezas[0].x * 64, (posicionPiezas[0].y - contador) * 64
			};

			posiblesPosiciones.push_back(posiblePosicion);
			contador++;
		}

		// Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
		for (int i = 0; i < MC->tablero->piezas.size(); i++)
		{
			//Recorremos todas las posiciones del tablero server
			int tableroX = MC->tablero->piezas[i]->posicionPieza.x;
			int tableroY = MC->tablero->piezas[i]->posicionPieza.y;

			for (int j = 0; j < posiblesPosiciones.size(); j++)
			{
				//
				int spritePosX = MC->posicionInicial.x * 64;
				int spritePosY = MC->posicionInicial.y * 64;

				// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
				// En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 

				if ((tableroX == posiblesPosiciones[j].x) && (tableroY == posiblesPosiciones[j].y))
				{
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;

					//Jugador mueve fichas blancas
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
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
							posXY.y -= 64;
						}
					}
					/*if (MC->tablero->piezas[i]->colorPiece == colorFicha)
					{
						if()
					}*/

					numeroFichaAComer = i;

				}
			}
		}

		// Si la torre va a su máxima rango(posible pieza)
		if (PosicionConvertida1.y == posXY.y && PosicionConvertida0.x == PosicionConvertida1.x)
		{
			if (numeroFichaAComer > -1 && MC->jugadorQuiereComerFicha == true)
			{
				// Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
				// De esta manera parecerá que la pieza no se ha movido. 

				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
			else
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
		}
		// En caso de que la torre no vaya a su máximo rango...
		else if (PosicionConvertida1.y > posXY.y&& PosicionConvertida1.x == PosicionConvertida1.x)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
		//Movimiento inválido
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
	}

	//Mover torre hacia la izquierda // 10/10 no tocar
	else if (xDifference < 0)
	{

		contador = 1;
		int fichaABorrar = -1;
		bool fichaComida = false;
		sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };

		// Rellenamos el vector posiblesPosiciones con todas las posiciones posibles de la torre según a que direción haya ido.
		for (int i = posicionPiezas[0].x - 1; i >= 0; i--)
		{
			sf::Vector2i posiblePosicion{
			i, posicionPiezas[0].y
			};

			posiblesPosiciones.push_back(posiblePosicion);
			contador++;
		}

		// Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha.
		// Recojiendo el primer valor y acabamos el for, nos aseguramos tener el valor más cercano a la torre.
		for (int i = 0; i < MC->tablero->piezas.size(); i++)
		{
			for (int j = 0; j < posiblesPosiciones.size(); j++)
			{
				sf::Vector2f antiguaPosicion = { sprite.getPosition().x / 64, sprite.getPosition().y / 64 };

				int tableroX = MC->tablero->piezas[i]->posicionPieza.x / 64;
				int tableroY = MC->tablero->piezas[i]->posicionPieza.y / 64;
				int piezaX = sprite.getPosition().x / 64;
				int piezaY = sprite.getPosition().y / 64;
				if ((posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY))
				{
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;
					fichaABorrar = i;
					fichaComida = true;
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.x += 1;
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
						}
					}
				}
				else if (fichaComida == false)
				{
					posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];

				}


			}
		}

		//  Si la pieza se mueve en su limite
		if (posicionPiezas[1].x > posXY.x&& posicionPiezas[0].y == posicionPiezas[1].y)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
		//  Si llega al limite
		else if (posicionPiezas[1].x == posXY.x)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}


	}
	//Mover torre hacia la derecha // 10/10 no tocar
	else if (xDifference > 0)
	{
		contador = 1;
		int fichaABorrar = -1;
		sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };

		for (int i = posicionPiezas[0].x; i < 7; i++)
		{
			sf::Vector2i posiblePosicion{
			posicionPiezas[0].x + contador, posicionPiezas[0].y
			};

			posiblesPosiciones.push_back(posiblePosicion);
			contador++;
		}

		for (int i = 0; i < MC->tablero->piezas.size(); i++)
		{
			for (int j = 0; j < posiblesPosiciones.size(); j++)
			{

				int tableroX = MC->tablero->piezas[i]->posicionPieza.x / 64;
				int tableroY = MC->tablero->piezas[i]->posicionPieza.y / 64;
				// Existe alguna ficha en las posiciones posibles?
				if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
				{
					// Posicion máxima a la que se puede ir
					posXY.x = posiblesPosiciones[j].x;
					posXY.y = posiblesPosiciones[j].y;

					//Jugador mueve fichas blancas
					if (colorFicha == 0)
					{
						//Ficha en tablero es blanca
						if (MC->tablero->piezas[i]->colorPiece == Blanca)
						{
							posXY.x -= 1;
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
						}
					}

					fichaABorrar = i;

					j = posiblesPosiciones.size();
					i = MC->tablero->piezas.size();
				}

				else
				{
					posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
				}
			}
		}

		//  Si la torre se mueve al rango máximo permitido, comprobar si hay ficha a la que se pueda comer.
		if (posicionPiezas[1].x == posXY.x)
		{
			if (fichaABorrar > -1)
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			}
			else
			{
				ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);

			}
		}

		else if (posicionPiezas[1].x < posXY.x && posicionPiezas[0].y == posicionPiezas[1].y)
		{
			ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}
		else
		{
			InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
		}

	}

}

