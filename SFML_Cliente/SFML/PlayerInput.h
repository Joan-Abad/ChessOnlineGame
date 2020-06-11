#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Tablero.h"
#include "SFML/Network.hpp"

class Pieza;
class Tablero;
extern enum ColorPieza;

enum estadoDelJuego {
	BuscandoPartida,
	EnPartida,
	FinalDeLaPartida
};
class PlayerInput
{
public:
	PlayerInput(sf::RenderWindow &window, Tablero & tablero);

private:
	bool isPressed = false;
	bool firstClick = false;
	sf::Vector2i mousePosition;
	sf::RectangleShape cursor;
	Pieza* piezaBug;
	sf::Vector2i posiciones[2];
	sf::Color markerColor = sf::Color::Red;	
	

public:
	Tablero *tablero;
	sf::RectangleShape marcadorPieza;
	void MouseDetection(sf::TcpSocket* socket, bool& gameOver, sf::Event &event);
	void drawCursor(sf::RenderWindow& window);
	void MouseCheckInteraction(sf::TcpSocket *socket);
	sf::RenderWindow* window;
	ColorPieza ColorFichasJugador;
	estadoDelJuego gameStatus;
	//borrar en el futuro
	std::string PiezaEscojidaParaEnviar;
	bool aceptarPartida = false;
	bool MuevesFicha;
	int colorDePieza;
	bool comerFicha = false;
	int PiezaAComer = -1;
	int fichaNumero = -1;

	Pieza* PiezaEscojida;

};

