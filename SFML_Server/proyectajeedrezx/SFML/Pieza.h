#pragma once
#include "SFML/Graphics.hpp"
#include "Utils.h"
#include <iostream>
#include"PlayerInput.h"
#include <vector>
#include "Tablero.h"
#include "SFML/Network.hpp"
#include "ManejoConexiones.h"

enum ColorPieza
{
	Blanca,
	Negra
};
class PlayerInput;
class Tablero;
class ManejoConexiones;

class Pieza
{
public:
	Pieza();

private:
	sf::Vector2i posicionFichaComprobacion;

protected: 
	sf::Texture texture;
	sf::Sprite sprite;
	std::string nombrePieza;
	Tablero* tablero = nullptr;

	bool moverHaciaDelante;
	bool quiereComerFicha = false; 

	void InvalidarMovimiento(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);
	void ValidarMovimiento(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);


	
public:
	sf::Sprite &GetSprite();
	bool primeraTiradaDeLaFicha = true;
	
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);
	
	ColorPieza colorPieza;

	ManejoConexiones* MC = nullptr;
};

