#pragma once
#include "SFML/Graphics.hpp"
#include <thread>
#include "SFML/Network.hpp"
#include "Tablero.h"
#include "PlayerInput.h"
#include "GameOverScreen.h"

enum EstadosDeLaPartida
{
	e_Nada, 
	e_ConectarAPartida,
	e_MovimientoFicha
};

enum DibujarPartida
{
	e_PartidaX, 
	e_GameOver
};

class GameLoop
{
public: 
	GameLoop(sf::TcpSocket& socket);
	~GameLoop();
private:
	//Window
	sf::RenderWindow* window;

	//WindowSize
	float ScreenX = 512;
	float ScreenY = 512;

	//Controlador de los estados de la partida
	EstadosDeLaPartida e_Partida;

	//Enum que controla el dibujado de la parida
	DibujarPartida e_DibujarPartida;

	//Thread para recibir información del servidor
	std::thread listenThread;

	//Start listening and recieving packages from server
	bool startListening;

	//Recieve packet de part del server

	//bool que controla cuando se va a abrir la ventana
	bool startTheGame;

	//bool que maneja el loop principal, si es false se cierra la aplicación
	bool gameOver;

	//ColorFicha: Blanco = 0, Negro = 1
	int colorFicha;

	//Nombre del jugador, se le proporciona al unirse al servidor
	std::string nombrejugador;

	//Te toca mover ficha
	bool teTocaMoverFicha;

	//Puntero que guardara la conexión con el servidor
	sf::TcpSocket* servidor;

	//función que se va a lanzar con el thread
	void t_ListenFunction();

	//Abrir la ventana y el juego en si
	void AbrirVentana();

	//Controlar todo el input del jugador
	void InputJugador();

	//Dibujar toda la parte gráfica de la partida
	void DibujarPartida();

	//Tablero donde pasa la partida
	Tablero* tablero;

	//Handle player input 
	PlayerInput* playerInput;

	//Game over screen
	GameOverScreen *GOS;

	//Variables Pieza A Recibir
	int FichaX;
	int FichaY;
	bool comerFicha;
	int FichaAComer;
	bool muevesFicha;
	std::string nombrePieza;
	int fichaJugador;

	std::vector < sf::Vector2f > posicionesParaLasPiezas;

public: 
	//Loop de la partida
	void ComenzarPartida();

	
};
