#include "Caballo.h"

Caballo::Caballo(Tablero& tablero, ColorPieza CP) : Pieza(tablero, CP)
{
	nombrePieza = "caballo";
	float tamañoPieza = Utils::getTamanoPieza(*this->tablero->ventanaActiva);
	Utils::InitializeSprite(sprite, texture, CP, "../img/Caballo");
	Utils::SetSpriteSize(sprite, tamañoPieza);
}

void Caballo::MovimientoPieza(sf::Vector2i posicionPiezas)
{
	//tablero->PI->PiezaEscojidaParaEnviar = "caballo";
	sf::Vector2f posicionPieza
	{
	float(posicionPiezas.x),
	float(posicionPiezas.y)
	};
	sprite.setPosition(posicionPieza);
	/*moverHaciaDelante = true;
	sf::Vector2f posAntigua = sprite.getPosition();
	std::vector <sf::Vector2i> posiblesPosiciones2;

	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 1, posicionPiezas[0].y - 2));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 2, posicionPiezas[0].y - 1));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 2, posicionPiezas[0].y + 1));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 1, posicionPiezas[0].y + 2));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 1, posicionPiezas[0].y + 2));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 2, posicionPiezas[0].y + 1));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 2, posicionPiezas[0].y - 1));
	posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 1, posicionPiezas[0].y - 2));
		
	for (int i = 0; i < posiblesPosiciones2.size(); i++)
	{
		if (posicionPiezas[1].x == posiblesPosiciones2[i].x && posicionPiezas[1].y == posiblesPosiciones2[i].y)
		{
			
			sf::Vector2f nuevaPos
			{
				float(posicionPiezas[1].x * 64),
				float(posicionPiezas[1].y * 64)
			};

			sprite.setPosition(nuevaPos);
			tablero->PI->PiezaEscojidaParaEnviar = "caballo";

			for (int j = 0; j < tablero->GetPiezas().size(); j++)
			{
				if (tablero->GetPiezas()[j]->GetSprite().getPosition() == nuevaPos && tablero->GetPiezas()[j] != this)
				{
					if (tablero->GetPiezas()[j]->colorPieza != tablero->PI->ColorFichasJugador)
					{
						ComprobarSiFichaHaMuerto(tablero->GetPiezas()[j], j, sf::Vector2i(nuevaPos.x / 64, nuevaPos.y / 64), posAntigua, "caballo");
						j = tablero->GetPiezas().size();
						i = posiblesPosiciones2.size();
					}
					else
					{
						sprite.setPosition(posAntigua);
						j = tablero->GetPiezas().size();
						i = posiblesPosiciones2.size();
					}
					
				}
				else
				{
					sprite.setPosition(nuevaPos);
				}
			}			
		}
	}*/
}
