#include "GameLoop.h"
#include <iostream>
#include "Rey.h"
#include "Pieza.h"

GameLoop::GameLoop(sf::TcpSocket & socket) 
{
	//Initializar variable e_Partida
	e_Partida = e_ConectarAPartida;

	//Inizializar window
	window = nullptr;

	//Inizializar variables que manejan el juego
	startTheGame = false; 
	gameOver = false; 
	startListening = true; 

	//Guardar conexión con el servidor
	servidor = &socket;
	
	if (servidor)
	{
		listenThread = std::thread(&GameLoop::t_ListenFunction, this);
		listenThread.detach();

		ComenzarPartida();
	}
}

GameLoop::~GameLoop()
{
	delete tablero;
	delete window;	
}

void GameLoop::ComenzarPartida()
{

	while (gameOver == false)
	{
		if (startTheGame == true)
		{
			AbrirVentana();
			
		}
		else
		{

		}
	}

}
void GameLoop::t_ListenFunction()
{

	while (startListening)
	{
			std::cout << startListening << std::endl;
			//Si el game loop se ha podido inizializar correctamente
			sf::Packet recievePacket;

			servidor->receive(recievePacket);

			switch (e_Partida)
			{
			case e_ConectarAPartida:
				float X;
				float Y;
				if (recievePacket >> startTheGame >> colorFicha >> nombrejugador)
				{
					
					
					for (int i = 0; i < 64; i++)
					{
						if(recievePacket >> X >> Y)
						posicionesParaLasPiezas.push_back(sf::Vector2f(X,Y));
					}
					std::cout << "\nSe ha recibido correctamente los datos";
					//Creamor un player input para gestionar todos los controles del jugador
				}
				
				
				break;

			case e_MovimientoFicha:
				
				if (recievePacket >> fichaJugador >> FichaX >> FichaY >> nombrePieza >> FichaAComer >> muevesFicha >> comerFicha)
				{
					std::cout << "\nSe han recibido correctamente los datos breo";
					if (fichaJugador > -1)
					{
						playerInput->MuevesFicha = muevesFicha;

						tablero->GetPiezas()[fichaJugador]->MovimientoPieza(sf::Vector2i(FichaX, FichaY));
						if (comerFicha == true)
						{

							Rey* rey = dynamic_cast<Rey*>(tablero->GetPiezas()[FichaAComer]);
							
							if (rey)
							{
								GOS = new GameOverScreen();

								if (rey->colorPieza != playerInput->ColorFichasJugador)
								{
									GOS->getTextoFinal().setString("Has ganado!");
								}
								else
								{
									GOS->getTextoFinal().setString("Has perdido!");
								}
								
								GOS->getTextoFinal().setPosition(window->getSize().x / 3, window->getSize().y / 2.5f);								
								e_DibujarPartida = e_GameOver;
							}
							delete(tablero->GetPiezas()[FichaAComer]);
							tablero->GetPiezas().erase(tablero->GetPiezas().begin() + FichaAComer);
						}
					}
				}
				break;

			case e_Nada:
				break;
			}	
	}
}

void GameLoop::AbrirVentana()
{
		window = new sf::RenderWindow(sf::VideoMode(ScreenX, ScreenY), "Ajedrez Online");

		//Creamos el tablero
		tablero = new Tablero(*window, posicionesParaLasPiezas);

		//Creamos player Input
		playerInput = new PlayerInput(*window, *tablero);

		for (int i = 0; i < playerInput->tablero->GetPiezas().size(); i++)
		{
			if (colorFicha == playerInput->tablero->GetPiezas()[i]->colorPieza)
			{
				playerInput->tablero->GetPiezas()[i]->GetSprite().setColor(sf::Color::Cyan);
			}
		}

			if (colorFicha == 0)
			{
				playerInput->ColorFichasJugador = Blanca;
				playerInput->MuevesFicha = true;
			}
			else if (colorFicha == 1)
			{
				playerInput->ColorFichasJugador = Negra;
				playerInput->MuevesFicha = false;
			}
		

		e_Partida = e_MovimientoFicha;

		while (window->isOpen())
		{
			//Los controles del jugador
			InputJugador();

			//Dibujar toda la parte gráfica de la partida
			DibujarPartida();
		}
	
}

void GameLoop::InputJugador()
{
	sf::Event event;

	if (playerInput)
	{
		playerInput->MouseDetection(servidor, gameOver, event);
	}
}

void GameLoop::DibujarPartida()
{
	if (!GOS)
	{
		window->clear(sf::Color::Red);
		tablero->DibujarTablero(*window);
		playerInput->drawCursor(*window);
		window->display();
	}
	else
	{
		window->clear(sf::Color::White);
		GOS->drawGameOverScreen(*window);
		window->display();
	};
}

