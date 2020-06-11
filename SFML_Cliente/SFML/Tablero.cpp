#include "Tablero.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"
#include "Peon.h"

Tablero::Tablero(sf::RenderWindow& window, std::vector<sf::Vector2f> &posiciones)
{

	ventanaActiva = &window;

	//Crear rectangulo
	sf::RectangleShape cuadrado;
	cuadrado.setSize(sf::Vector2f(window.getSize().x/8, window.getSize().y/8));
	cuadrado.setPosition(0, 0);
	
	//loop rellenar cuadrados de color blanco y negro
	for (int i = 0; i < 8; i++) {		
		for (int j = 0; j < 8; j++) {
			// si es 1 es negro, sino, es blanco
			if (tablero[i][j] == 1) 
				cuadrado.setFillColor(sf::Color::Black);
			
			else
				cuadrado.setFillColor(sf::Color::White);

			cuadrados.push_back(cuadrado);
			cuadrado.move(0, window.getSize().y / 8);
		}
		cuadrado.setPosition(cuadrado.getPosition().x, 0);
		cuadrado.move( window.getSize().x/8, 0);
	}

	CrearPiezas(window, posiciones);
	
}

void Tablero::CrearPiezas(sf::RenderWindow& window, std::vector<sf::Vector2f>& posiciones)
{
	sf::Vector2f PosicionPiezas{ 0,0 };
	Pieza* pieza = nullptr;

	for (int i = 0; i < 32; i++)
	{
		switch (i)
		{
			//FICHAS NEGRAS
			//TORRES
		case 0:
		case 7: 
			pieza = new Torre(*this, Negra);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//CABALLO
		case 1:  
		case 6:
			pieza = new Caballo(*this, Negra);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//Alfil

		case 2:
		case 5:
			pieza = new Alfil(*this, Negra);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//Rey
		case 3:
			pieza = new Rey(*this, Negra);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//Reina
		case 4: 
			pieza = new Reina(*this, Negra);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//FICHAS BLANCAS
			//Torre
		case 24:
		case 31:
			pieza = new Torre(*this, Blanca);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//Caballo
		case 25:
		case 30:
			pieza = new Caballo(*this, Blanca);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//Alfil
		case 26:
		case 29:
			pieza = new Alfil(*this, Blanca);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			//Rey
		case 27:  
			pieza = new Rey(*this, Blanca);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
			// Reina
		case 28:
			pieza = new Reina(*this, Blanca);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
			break;
		}
		
		if (i > 7 && i < 16)
		{
			pieza = new Peon(*this, Negra);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
		}

		if (i > 15 && i < 24)
		{
			pieza = new Peon(*this, Blanca);
			pieza->GetSprite().setPosition(posiciones[i].x, posiciones[i].y);
			piezas.push_back(pieza);
		}

		

	}
	std::cout << "numero de piezas: " << piezas.size();
}

void Tablero::DibujarTablero(sf::RenderWindow& window)
{
	//recorre todo el vector solo y dibuja 
	for (auto cuadrado : cuadrados) {
		window.draw(cuadrado);
	}
	for (auto pieza : piezas) {
		window.draw(pieza->GetSprite());
	}
}
	