#include "ManejoConexiones.h"
#include <iostream>
#include "Pieza.h"
#include "Peon.h"
#include "Torre.h"
#include "Utils.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"

ManejoConexiones::ManejoConexiones() 
{
	//Abrimos puero para escuchar
	OpenListener();

	//Nombres de los jugadores
	nombreJugadores.push_back("JC");
	nombreJugadores.push_back("Gerard");

	//TODO
	e_EstadoPartida = e_ComprobarTurno;

	//Turnos clientes
	cliente1 = NULL;
	cliente2 = NULL;
	fichaAComer = NULL;
	tablero = new Tablero();
}

//Perfecto
void ManejoConexiones::OpenListener()
{
	if (listener.listen(53000) != sf::Socket::Done)
		std::cout << "Not listening";
	else
		std::cout << "Listening correctly.";
	
}

void ManejoConexiones::ComprobarConexiones()
{
	//Conectar jugadores si es menor al máximo permitido(2)
	while (numeroJugadores < maximoNumeroJugadores)
	{
		sf::TcpSocket* cliente = new sf::TcpSocket;
		if (listener.accept(*cliente) == sf::Socket::Done)
		{
			std::cout << "\nSe ha conectado correctamente el jugador " << numeroJugadores;
			numeroJugadores++;
			clientes.push_back(cliente);
		}
	}

	//Enviar datos a los clientes para ver quien empieza partida
	//Perfecto
	for(int i = 0; i < clientes.size(); i++)
	{
		//Empezar Partida
		sf::Packet pEmpiezaLaPartida;
		
		
		pEmpiezaLaPartida << empezarPartida << i << nombreJugadores[i];

		for (int i = 0; i < tablero->piezas.size(); i++)
		{
			pEmpiezaLaPartida << tablero->piezas[i]->posicionPieza.x;
			pEmpiezaLaPartida << tablero->piezas[i]->posicionPieza.y;
		}

		clientes[i]->send(pEmpiezaLaPartida);

		std::cout << "\nSe ha enviado los datos al cliente: " << i;
	}

	std::cout << "\n\nSe ha llegado al límite de jugadores permitidos (" << numeroJugadores << ")";

	std::string ficha;

	//0 = Blanco, 1 = Negro
	int colorFicha = NULL; 
	bool muevesFicha = NULL;
	while (true)
	{
		switch (e_EstadoPartida)
		{
		case e_ComprobarTurno:

			for (tengoFiebrePeroEstoyFeliz = 0; tengoFiebrePeroEstoyFeliz < clientes.size(); tengoFiebrePeroEstoyFeliz++)
			{
				sf::Packet recievePacket;

				clientes[tengoFiebrePeroEstoyFeliz]->receive(recievePacket);

				if (recievePacket >> fichaNumeroJugador >> muevesFicha >> colorFicha >> fichaAComer >> ficha >> posicionInicial.x >> posicionInicial.y >> posicionFinal.x >> posicionFinal.y >> jugadorQuiereComerFicha)
				{

					std::cout << "\nSe han recibido correctamente los datos. ";
					std::cout << "\nFicha: " << ficha;

					std::cout << "\nPosicion Inicial:";
					Utils::PrintVector2(posicionInicial);
					Utils::PrintVector2(posicionFinal);

					sf::Vector2i Posiciones[2] = { posicionInicial, posicionFinal };

					if (ficha == "peon")
					{
						Peon peon(*this);
						peon.MovimientoPiezaValido(Posiciones,clientes, fichaAComer, colorFicha, jugadorQuiereComerFicha);
					}
					else if(ficha == "torre")
					{
						Torre torre(*this);
						torre.MovimientoPiezaValido(Posiciones, clientes, fichaAComer, colorFicha, jugadorQuiereComerFicha);
					}
					else if (ficha == "alfil")
					{
						Alfil alfil(*this);
						alfil.MovimientoPiezaValido(Posiciones, clientes, fichaAComer, colorFicha, jugadorQuiereComerFicha);
					}
					else if (ficha == "caballo")
					{
						Caballo caballo(*this);
						caballo.MovimientoPiezaValido(Posiciones, clientes, fichaAComer, colorFicha, jugadorQuiereComerFicha);
					}
					else if (ficha == "rey")
					{
						Rey rey(*this);
						rey.MovimientoPiezaValido(Posiciones, clientes, fichaAComer, colorFicha, jugadorQuiereComerFicha);
					}
					else if (ficha == "reina")
					{
						Reina reina(*this);
						reina.MovimientoPiezaValido(Posiciones, clientes, fichaAComer, colorFicha, jugadorQuiereComerFicha);
					}
					recievePacket.clear();
				}
			}

		}
	}
}
