#include "Caballo.h"

Caballo::Caballo(ManejoConexiones& MC) 
{
    this->MC = &MC;
}
 
 void Caballo::MovimientoPieza(sf::Vector2i posicionPiezas[2])
 {
 	moverHaciaDelante = true;
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
 		
	/*
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

			for (int j = 0; j < MC->tablero->piezas.size(); j++)
			{
				if (MC->tablero->piezas[j]->posicionPieza == nuevaPos)
				{
					if (MC->tablero->piezas[j]->colorPieza != tablero->PI->ColorFichasJugador)
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
	}
	*/
 }

 void Caballo::MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
 {
	 bool movimientoValido = false; 
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
			 ValidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
			 movimientoValido = true;
			 i = posiblesPosiciones2.size();
		 }
	 }

	 if (movimientoValido == false)
	 {
		 InvalidarMovimiento(posicionPiezas, clientes, idFicha, colorFicha, comerFicha);
	 }
	 
 }
