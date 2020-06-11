#include "Pieza.h"
#include "Rey.h"
#include "SFML/Network.hpp"
#include <vector>
Pieza::Pieza() 
{
}


void Pieza::InvalidarMovimiento(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
{
	int x = posicionPiezas[1].x;
	int y = posicionPiezas[1].y;

	MC->fichaNumeroJugador = -1;

	MC->tengoFiebrePeroEstoyFeliz--;

	for (int i = 0; i < clientes.size(); i++)
	{
		sf::Packet packet;
		packet.clear();
		if (i == 0)
		{
			if (MC->cliente1 == true)
			{
				packet << MC->fichaNumeroJugador << x << y << nombrePieza << idFicha << MC->cliente1 << comerFicha;
			}
			else
			{
				MC->cliente1 = false;
				packet << MC->fichaNumeroJugador << x << y << nombrePieza << idFicha << MC->cliente1 << comerFicha;
			}
		}
		else if (i == 1)
		{

			if (MC->cliente2 == true)
			{
				packet << MC->fichaNumeroJugador << x << y << nombrePieza << idFicha << MC->cliente2 << comerFicha;
			}
			else
			{
				MC->cliente2 = false;
				packet << MC->fichaNumeroJugador << x << y << nombrePieza << idFicha << MC->cliente2 << comerFicha;
			}
		}

		clientes[i]->send(packet);
		packet.clear();

		std::cout << "\nEnviando Datazos a cliente " << i;
	}
}

void Pieza::ValidarMovimiento(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
{
	int x = posicionPiezas[1].x;
	int y = posicionPiezas[1].y;
	bool muevesFicha = false;

	bool empezarPartida = true;
	sf::Packet pEmpiezaLaPartida;
	
	MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.x = x * 64;
	
	MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.y = y * 64;

	int xFinal = MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.x;
	int yFinal = MC->tablero->piezas[MC->fichaNumeroJugador]->posicionPieza.y;

	for (int i = 0; i < clientes.size(); i++)
	{
		sf::Packet packet;
		if (MC->firstCheck == true)
		{
			if (i == 0)
			{
				MC->cliente1 = false;
				packet << MC->fichaNumeroJugador << xFinal << yFinal << nombrePieza << idFicha << MC->cliente1 << comerFicha;
			}
			else if (i == 1)
			{
				MC->cliente2 = true;
				packet << MC->fichaNumeroJugador << xFinal << yFinal << nombrePieza << idFicha << MC->cliente2 << comerFicha;
				MC->firstCheck = false;
			}
		}
		else
		{
			if (i == 0)
			{
				if (MC->cliente1 == true)
				{
					MC->cliente1 = false;
					packet << MC->fichaNumeroJugador << xFinal << yFinal << nombrePieza << idFicha << MC->cliente1 << comerFicha;
				}
				else
				{
					MC->cliente1 = true;
					packet << MC->fichaNumeroJugador << xFinal << yFinal << nombrePieza << idFicha << MC->cliente1 << comerFicha;
				}
			}
			else if (i == 1)
			{

				if (MC->cliente2 == true)
				{
					MC->cliente2 = false;
					packet << MC->fichaNumeroJugador << xFinal << yFinal << nombrePieza << idFicha << MC->cliente2 << comerFicha;
				}
				else
				{
					MC->cliente2 = true;
					packet << MC->fichaNumeroJugador << xFinal << yFinal << nombrePieza << idFicha << MC->cliente2 << comerFicha;
				}
			}

		}
		clientes[i]->send(packet);
		std::cout << "\nEnviando Datazos a cliente " << i;
	}

}

void Pieza::MovimientoPieza(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
{

}


sf::Sprite& Pieza::GetSprite()
{
	return sprite;
}



	