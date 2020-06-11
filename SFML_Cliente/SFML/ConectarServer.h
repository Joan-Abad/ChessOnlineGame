#pragma once
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include "GameLoop.h"
#include <thread>

class ConectarServer
{
public:
	ConectarServer();
	

private:
	//Conexión con el servidor
	sf::TcpSocket* servidor;

	//Ventana de la partida
	sf::RenderWindow* window;

	//Loop que controla la partida
	GameLoop* gameLoop;

};

