#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "Pieza.h"
#include "Utils.h"
#include "PlayerInput.h"

class PlayerInput;
class Pieza;

class Tablero
{
public:
	Tablero(sf::RenderWindow &window, std::vector<sf::Vector2f>& posiciones);

private:
	//1 = negro
	//2 = blanco
	int tablero[8][8] = {
	{ 1,2,1,2,1,2,1,2 },
	{ 2,1,2,1,2,1,2,1 },
	{ 1,2,1,2,1,2,1,2 },
	{ 2,1,2,1,2,1,2,1 },
	{ 1,2,1,2,1,2,1,2 },
	{ 2,1,2,1,2,1,2,1 },
	{ 1,2,1,2,1,2,1,2 },
	{ 2,1,2,1,2,1,2,1 } };

	
	//vector de cuadrados para guardarlos
	std::vector <Pieza*> piezas;


	void CrearPiezas(sf::RenderWindow& window, std::vector<sf::Vector2f>& posiciones);

public:
	inline std::vector <Pieza*>& GetPiezas() { return piezas; };
	void DibujarTablero(sf::RenderWindow& window);
	sf::RenderWindow* ventanaActiva;
	std::vector <sf::RectangleShape> cuadrados;

	
};

