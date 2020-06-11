#include "ConectarServer.h"
#include <iostream>
#include <string>

ConectarServer::ConectarServer()
{
	servidor = new sf::TcpSocket;
	gameLoop = nullptr;

	
	//Conectar con el server
	sf::Socket::Status status = servidor->connect("127.0.0.1", 53000);


	if (status != sf::Socket::Done)
		std::cerr << "\nError, no te has podido conectar correctamente.";
	else
	{
		std::cout << "\nSe ha conectado correctamente al servidor.";

		gameLoop = new GameLoop(*servidor);
	}
}
