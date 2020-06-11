#include "Peon.h"
#include <vector>
#include <SFML/Network.hpp>

Peon::Peon(ManejoConexiones& MC) : Pieza()
{
	this->MC = &MC;
}

void Peon::MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
{
	MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.x = posicionPiezas[1].x * 64;
	MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.y = posicionPiezas[1].y * 64;

	
	std::cout << "\nPeon";
		nombrePieza = "peon";
	bool moverHaciaDelante = true;
	int movimientoPeon;

	// Mover hacia arriba si es blanca
	if (colorFicha == 0)
		movimientoPeon = -1;
	// Mover hacia abajo si es negra
	else if (colorFicha == 1)
		movimientoPeon = 1;
	// Movimiento hacia adelante

// Check Collision 

	int x = posicionPiezas[1].x;
	int y = posicionPiezas[1].y;

	if (primeraTiradaDeLaFicha == true && (posicionPiezas[0].x == posicionPiezas[1].x && posicionPiezas[0].y == posicionPiezas[1].y + movimientoPeon))
	{
		moverHaciaDelante = false;
	}
	if ((posicionPiezas[0].x == posicionPiezas[1].x && posicionPiezas[0].y == posicionPiezas[1].y))
	{
		moverHaciaDelante = false;
	}


	// Mover pieza un espacio
	if (posicionPiezas[0].x == posicionPiezas[1].x && posicionPiezas[0].y + 1 * movimientoPeon == posicionPiezas[1].y && moverHaciaDelante == true) {

		std::cout << "\nMover un espacio";
		int x = posicionPiezas[1].x;
		int y = posicionPiezas[1].y;
		bool muevesFicha = false;
		primeraTiradaDeLaFicha = false;
		bool empezarPartida = true;
		sf::Packet pEmpiezaLaPartida;

		if (MC->jugadorQuiereComerFicha == false)
		{
			ValidarMovimiento(posicionPiezas,clientes,idFicha,colorFicha,comerFicha);
		}
		else
		{
			InvalidarMovimiento(posicionPiezas,clientes,idFicha,colorFicha,comerFicha);
		}

	}
	// Movimiento hacia adelante x2
	else if (primeraTiradaDeLaFicha == true && (posicionPiezas[0].x == posicionPiezas[1].x && posicionPiezas[0].y + 2 * movimientoPeon == posicionPiezas[1].y) && moverHaciaDelante == true) {
		std::cout << "\nMover dos espacio";


		bool muevesFicha = false;

		bool empezarPartida = true;
		sf::Packet pEmpiezaLaPartida;
		primeraTiradaDeLaFicha = false;
		ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);

	}
	// Comer
	else if (MC->jugadorQuiereComerFicha == true)
	{
		if (posicionPiezas[0].x - 1 * (movimientoPeon * -1) == posicionPiezas[1].x && posicionPiezas[0].y - 1 * (movimientoPeon * -1) == posicionPiezas[1].y ||
			posicionPiezas[0].x + 1 * (movimientoPeon * -1) == posicionPiezas[1].x && posicionPiezas[0].y - 1 * (movimientoPeon * -1) == posicionPiezas[1].y) {
			
			delete(MC->tablero->piezas[MC->fichaAComer]);
			MC->tablero->piezas.erase(MC->tablero->piezas.begin() + MC->fichaAComer);

			ValidarMovimiento(posicionPiezas,clientes,idFicha,colorFicha,comerFicha);

		}
		else
		{
			for (int i = 0; i < clientes.size(); i++)
			{
				sf::Packet packet;
				if (MC)
					packet << MC->cliente1;
				else if (i == 1)
					packet << MC->cliente2;

				clientes[i]->send(packet);
				std::cout << "\nEnviando Datazos a cliente " << i;
			}
		}
	}
	//LLOC ON TOCA, LU QUE TOCA 
	else
	{
		InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
	}
}

