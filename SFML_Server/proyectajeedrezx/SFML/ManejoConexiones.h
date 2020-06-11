#pragma once
#include "SFML/Network.hpp"
#include <thread>
#include "Tablero.h"

enum estadoPartida
{
	e_ComprobarTurno,

};
class Tablero;
class ManejoConexiones
{
public: 
	ManejoConexiones();
	Tablero* tablero;

private:
	//Jugadores
	const int maximoNumeroJugadores = 2;
	int numeroJugadores = 0; 

	//Tcp info
	sf::TcpListener listener;
	sf::TcpSocket client;
	std::vector <sf::TcpSocket*> clientes;

	//Variables necesarias para empezar la partida
	std::vector<std::string> nombreJugadores;
	estadoPartida e_EstadoPartida;
	bool empezarPartida = true;

	//Open listen para server
	void OpenListener();

public:

	//Variables entre server y clientes
	void ComprobarConexiones();
	bool cliente1;
	bool cliente2;
	bool firstCheck = true;
	int fichaNumeroJugador = -1;
	bool jugadorQuiereComerFicha = false;
	int tengoFiebrePeroEstoyFeliz = 0;
	int fichaAComer;
	sf::Vector2i posicionInicial;
	sf::Vector2i posicionFinal;

};

