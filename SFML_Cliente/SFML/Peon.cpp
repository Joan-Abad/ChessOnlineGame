#include "Peon.h"
#include <vector>

Peon::Peon(Tablero& tablero, ColorPieza CP) : Pieza(tablero,CP)
{
	nombrePieza = "peon";
	float tamañoPieza = Utils::getTamanoPieza(*this->tablero->ventanaActiva);
	Utils::InitializeSprite(sprite, texture, CP, "../img/Peon");
	Utils::SetSpriteSize(sprite, tamañoPieza);
}

void Peon::MovimientoPieza(sf::Vector2i posicionPiezas)
{
	sf::Vector2f nuevaPosicionDelPeon = {
			float(posicionPiezas.x),
			 float(posicionPiezas.y)
	};
	sprite.setPosition(nuevaPosicionDelPeon);
	/*bool moverHaciaDelante = true;
	int movimientoPeon;
	//Mover hacia arriba si es blanca
	if (tablero->PI->ColorFichasJugador == Blanca)
		movimientoPeon = -1;
	//Mover hacia abajo si es negra
	else
		movimientoPeon = 1;
	//Movimiento hacia adelante

	//Check Collision 
	for (int i = 0; i < tablero->GetPiezas().size(); i++)
	{
		Pieza* piezaDet = tablero->GetPiezas()[i];
		
		sf::Vector2f posicionPiezaTablero = { piezaDet->GetSprite().getPosition().x / 64, piezaDet->GetSprite().getPosition().y / 64 };
		if (primeraTiradaDeLaFicha == true && (posicionPiezaTablero.x == posicionPiezas[1].x && posicionPiezaTablero.y == posicionPiezas[1].y + movimientoPeon))
		{
			moverHaciaDelante = false;
			piezaDet = nullptr;
			delete piezaDet;
			primeraTiradaDeLaFicha = false;
			sf::Vector2f nuevaPosicionDelPeon = {
				(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
				 posicionPiezas[1].y * Utils::getTamanoPieza(*tablero->PI->window)
			};
			sprite.setPosition(nuevaPosicionDelPeon);
		}
		if ((posicionPiezaTablero.x == posicionPiezas[1].x && posicionPiezaTablero.y == posicionPiezas[1].y))
		{
			moverHaciaDelante = false;
			piezaDet = nullptr;
			delete piezaDet;
		}
		
		
	}
	//Mover pieza un espacio
	if (posicionPiezas[0].x == posicionPiezas[1].x && posicionPiezas[0].y + 1 * movimientoPeon == posicionPiezas[1].y && moverHaciaDelante == true) {
		sf::Vector2f nuevaPosicionDelPeon = {
				(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
				 posicionPiezas[1].y * Utils::getTamanoPieza(*tablero->PI->window) 
		};
		sprite.setPosition(nuevaPosicionDelPeon);

		primeraTiradaDeLaFicha = false;
		tablero->PI->marcadorPieza.setOutlineColor(sf::Color::Transparent);

	}
	//Movimiento hacia adelante x2
	else if (primeraTiradaDeLaFicha == true && (posicionPiezas[0].x == posicionPiezas[1].x && posicionPiezas[0].y + 2 * movimientoPeon == posicionPiezas[1].y) && moverHaciaDelante == true) {
		sf::Vector2f nuevaPosicionDelPeon = {
				(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
				 posicionPiezas[1].y * Utils::getTamanoPieza(*tablero->PI->window)
		};
		sprite.setPosition(nuevaPosicionDelPeon);

		primeraTiradaDeLaFicha = false;
		tablero->PI->marcadorPieza.setOutlineColor(sf::Color::Transparent);

	}
	//Comer
	else if (posicionPiezas[0].x - 1 * (movimientoPeon * -1) == posicionPiezas[1].x && posicionPiezas[0].y - 1 * (movimientoPeon * -1) == posicionPiezas[1].y ||
		posicionPiezas[0].x + 1 * (movimientoPeon * -1) == posicionPiezas[1].x && posicionPiezas[0].y - 1 * (movimientoPeon * -1) == posicionPiezas[1].y) {
		sf::Vector2f nuevaPosicionDelPeon = {
			(posicionPiezas[1].x - 1) * Utils::getTamanoPieza(*tablero->PI->window),
			 posicionPiezas[1].y * Utils::getTamanoPieza(*tablero->PI->window) - Utils::getTamanoPieza(*tablero->PI->window)
		};
		for (int i = 0; i < tablero->GetPiezas().size(); i++)
		{
			//preguntar a la carmen si los peones al llegar a la "base" del enemigo pueden transformarse en reina
			sf::Vector2f nuevaPosicionDelPeon = {
					(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
					(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
			};

			//Si nos comemos una ficha 
			if (tablero->GetPiezas()[i]->GetSprite().getPosition() == nuevaPosicionDelPeon && tablero->GetPiezas()[i]->colorPieza != tablero->PI->ColorFichasJugador) 
				ComprobarSiFichaHaMuerto(tablero->GetPiezas()[i], i, sf::Vector2i(nuevaPosicionDelPeon.x / 64, nuevaPosicionDelPeon.y / 64), sf::Vector2f(posicionPiezas[0].x * 64, posicionPiezas[0].y * 64), "peon");
			
		}
	}*/
}

