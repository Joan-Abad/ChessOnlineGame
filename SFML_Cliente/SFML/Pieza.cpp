#include "Pieza.h"
#include "Rey.h"

Pieza::Pieza(Tablero& tablero, ColorPieza CP) 
{
	this->tablero = &tablero;
	//this->tipoDePieza = tipoDePieza;
	colorPieza = CP;
}

void Pieza::ComePieza(sf::Vector2f NuevaPosicion)
{
	/*
	for (int i = 0; i < tablero->GetPiezas().size(); i++)
	{
		Pieza* piezaDet = tablero->GetPiezas()[i];

		sf::Vector2f posicionPiezaTablero = { piezaDet->GetSprite().getPosition().x / 64, piezaDet->GetSprite().getPosition().y / 64 };
		if ((posicionPiezaTablero.x == posicionFichaComprobacion.x - 1 && posicionPiezaTablero.y == posicionFichaComprobacion.y - 1) && piezaDet->colorPieza == tablero->PI->ColorFichasJugador)
		{
			moverHaciaDelante = false;
			piezaDet = nullptr;
			delete piezaDet;
			i = tablero->GetPiezas().size();
		}

		if ((tablero->GetPiezas()[i]->GetSprite().getPosition() == NuevaPosicion) && (tablero->GetPiezas()[i]->colorPieza != tablero->PI->ColorFichasJugador)) {
			
			if (tablero->GetPiezas()[i]->GetTipoPieza() == eRey) {
				tablero->PI->gameStatus = FinalDeLaPartida;
			}
			delete(tablero->GetPiezas()[i]);
			tablero->GetPiezas().erase(tablero->GetPiezas().begin() + i);
			i = tablero->GetPiezas().size();
			std::cout << "lol come";			
		}

		
	}
	*/
}

void Pieza::MovimientoPieza(sf::Vector2i posicionPiezas)
{
	std::cout << "el elo boost del meu amic platino";
}

void Pieza::ComprobarSiFichaHaMuerto(Pieza * pieza, int iteratorRase, sf::Vector2i nuevaPosicion, sf::Vector2f antiguaPosicion, std::string PiezaEnviar)
{
	/*
	//La pieza es de un color diferente
	if (pieza->colorPieza != tablero->PI->ColorFichasJugador)
	{
		Rey* posibleRey = dynamic_cast<Rey*>(pieza);

		if (posibleRey)
		{
			tablero->PI->gameStatus = FinalDeLaPartida;
		}
		if(pieza->GetSprite().getPosition().x/64 == nuevaPosicion.x && pieza->GetSprite().getPosition().y / 64 == nuevaPosicion.y)
		{
			std::cout << "\nComer Ficha";
			delete (pieza);
			tablero->GetPiezas().erase(tablero->GetPiezas().begin() + iteratorRase);
			sf::Vector2f posicionPieza
			{
			(nuevaPosicion.x) * Utils::getTamanoPieza(*tablero->PI->window),
			(nuevaPosicion.y) * Utils::getTamanoPieza(*tablero->PI->window)
			};
			sprite.setPosition(posicionPieza);
			tablero->PI->PiezaEscojidaParaEnviar = PiezaEnviar;
		}
	}
	//La pieza es del mismo color
	else
	{
			sprite.setPosition(antiguaPosicion);

	}
	*/
}

sf::Sprite& Pieza::GetSprite()
{
	return sprite;
}

//posicion ficha [0] = posicion pieza;
//Posicion Ficha [1] = posicion deseada;

//Movimiento de fichas no funciona mirarlo cuando la cabeza no este apunto de expolotar
//1 - calculem malament les posicions 20%
//2 - NO estem fent referencia directa al puntero que toca



	