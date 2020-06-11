#include "Alfil.h"

Alfil::Alfil(Tablero& tablero, ColorPieza CP) : Pieza(tablero, CP)
{
	nombrePieza = "alfil";
	float tamañoPieza = Utils::getTamanoPieza(*this->tablero->ventanaActiva);
	Utils::InitializeSprite(sprite, texture, CP, "../img/Alfil");
	Utils::SetSpriteSize(sprite, tamañoPieza);
}

void Alfil::MovimientoPieza(sf::Vector2i posicionPiezas)
{
		sf::Vector2f posicionPieza
			{
			float (posicionPiezas.x),
			float (posicionPiezas.y)
		};
		sprite.setPosition(posicionPieza);
	//moverHaciaDelante = true;
	//std::vector <sf::Vector2i> posiblesPosiciones;
	//int contador = 1;
	//bool fillValues = true;
	//bool movimientoFueraDeRango = true;
	//int numeroFichaAComer = 0;
	//bool fichaMovida = false;
	//sf::Vector2i posXY;
	////Mirar a que direción va la ficha
	//int xDifference = posicionPiezas[1].x - posicionPiezas[0].x;
	//int yDifference = posicionPiezas[1].y - posicionPiezas[0].y;


	////Mover el alfil arriba a la izquierda
	//if (xDifference < 0 && yDifference < 0)
	//{
	//	int X = posicionPiezas[0].x;
	//	int Y = posicionPiezas[0].y;

	//	while (fillValues)
	//	{
	//		X--;
	//		Y--;

	//		sf::Vector2i posicionPosible = { X, Y };
	//		posiblesPosiciones.push_back(posicionPosible);

	//		if (X == 0 || Y == 0 || X == 7 || Y == 7)
	//			fillValues = false;
	//	}

	//	//Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
	//	for (int j = 0; j < posiblesPosiciones.size(); j++)
	//	{
	//		for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//		{


	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;

	//			int spritePosX = sprite.getPosition().x / 64;
	//			int spritePosY = sprite.getPosition().y / 64;

	//			//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//			//En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 
	//			if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
	//			{
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				numeroFichaAComer = i;
	//				fichaMovida = true;
	//				i = tablero->GetPiezas().size();
	//				j = posiblesPosiciones.size();
	//			}
	//			if (fichaMovida == false)
	//			{
	//				posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
	//			}


	//		}
	//	}

	//	//Si la torre va a su máxima rango(posible pieza)
	//	if (posicionPiezas[1].y == posXY.y && posicionPiezas[1].x == posXY.x)
	//	{
	//		if (numeroFichaAComer > -1)
	//		{
	//			//Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
	//			//De esta manera parecerá que la pieza no se ha movido. 
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };


	//			int x = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().x / 64;
	//			int y = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().y / 64;

	//			sprite.setPosition(posicionPiezas[1].x * 64, posicionPiezas[1].y * 64);
	//			tablero->PI->PiezaEscojidaParaEnviar = "alfil";

	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;

	//			//Si estamos encima de alguna pieza, comprobar que color es y si nos la podemos comer. 
	//			if (x == piezaX && y == piezaY)
	//			{
	//				ComprobarSiFichaHaMuerto(tablero->GetPiezas()[numeroFichaAComer], numeroFichaAComer, posicionPiezas[1], antiguaPosicion, "alfil");
	//			}
	//		}
	//		else
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}
	//	if (posicionPiezas[1].y > posXY.y&& posicionPiezas[1].x > posXY.x)
	//	{
	//		for (int i = 0; i < posiblesPosiciones.size(); i++)
	//		{
	//			if (posiblesPosiciones[i] == posicionPiezas[1])
	//			{
	//				movimientoFueraDeRango = false;
	//			}
	//		}

	//		if (movimientoFueraDeRango == false)
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}

	//}
	////Abajo a la izquierda
	//else if (xDifference < 0 && yDifference > 0)
	//{
	//	std::cout << "\nAlfil quiere ir abajo a la izquierda";

	//	int X = posicionPiezas[0].x;
	//	int Y = posicionPiezas[0].y;

	//	while (fillValues)
	//	{
	//		X--;
	//		Y++;

	//		sf::Vector2i posicionPosible = { X, Y };
	//		posiblesPosiciones.push_back(posicionPosible);

	//		if (X == 0 || Y == 0 || X == 7 || Y == 7)
	//			fillValues = false;
	//	}

	//	for (int j = 0; j < posiblesPosiciones.size(); j++)
	//	{
	//		for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//		{
	//			//Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 



	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;

	//			int spritePosX = sprite.getPosition().x / 64;
	//			int spritePosY = sprite.getPosition().y / 64;

	//			//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//			//En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 
	//			if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
	//			{
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				numeroFichaAComer = i;
	//				i = tablero->GetPiezas().size();
	//				j = posiblesPosiciones.size();
	//				fichaMovida = true;
	//			}
	//			if (fichaMovida == false)
	//			{
	//				posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
	//			}
	//		}

	//	}

	//	if (posicionPiezas[1].y == posXY.y && posicionPiezas[1].x == posXY.x)
	//	{
	//		if (numeroFichaAComer > -1)
	//		{
	//			//Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
	//			//De esta manera parecerá que la pieza no se ha movido. 
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };


	//			int x = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().x / 64;
	//			int y = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().y / 64;

	//			sprite.setPosition(posicionPiezas[1].x * 64, posicionPiezas[1].y * 64);
	//			tablero->PI->PiezaEscojidaParaEnviar = "alfil";

	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;

	//			//Si estamos encima de alguna pieza, comprobar que color es y si nos la podemos comer. 
	//			if (x == piezaX && y == piezaY)
	//			{
	//				ComprobarSiFichaHaMuerto(tablero->GetPiezas()[numeroFichaAComer], numeroFichaAComer, posicionPiezas[1], antiguaPosicion, "alfil");

	//			}
	//		}
	//		else
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}
	//	if (posicionPiezas[1].y < posXY.y && posicionPiezas[1].x > posXY.x)
	//	{
	//		for (int i = 0; i < posiblesPosiciones.size(); i++)
	//		{
	//			if (posiblesPosiciones[i] == posicionPiezas[1])
	//			{
	//				movimientoFueraDeRango = false;
	//			}
	//		}

	//		if (movimientoFueraDeRango == false)
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}

	//}
	////Arriba a la derecha
	//else if (xDifference > 0 && yDifference < 0)
	//{
	//	int X = posicionPiezas[0].x;
	//	int Y = posicionPiezas[0].y;

	//	while (fillValues)
	//	{
	//		X++;
	//		Y--;

	//		sf::Vector2i posicionPosible = { X, Y };
	//		posiblesPosiciones.push_back(posicionPosible);

	//		if (X == 0 || Y == 0 || X == 7 || Y == 7)
	//			fillValues = false;
	//	}

	//	//Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
	//	for (int j = 0; j < posiblesPosiciones.size(); j++)
	//	{
	//		for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//		{


	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;

	//			int spritePosX = sprite.getPosition().x / 64;
	//			int spritePosY = sprite.getPosition().y / 64;

	//			//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//			//En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 
	//			if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
	//			{
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				numeroFichaAComer = i;
	//				i = tablero->GetPiezas().size();
	//				j = posiblesPosiciones.size();
	//				fichaMovida = true;
	//			}
	//			if (fichaMovida == false)
	//			{
	//				posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
	//			}




	//		}
	//	}

	//	//Si la torre va a su máxima rango(posible pieza)
	//	if (posicionPiezas[1].y == posXY.y && posicionPiezas[1].x == posXY.x)
	//	{
	//		if (numeroFichaAComer > -1)
	//		{
	//			//Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
	//			//De esta manera parecerá que la pieza no se ha movido. 
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };


	//			int x = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().x / 64;
	//			int y = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().y / 64;

	//			sprite.setPosition(posicionPiezas[1].x * 64, posicionPiezas[1].y * 64);
	//			tablero->PI->PiezaEscojidaParaEnviar = "alfil";

	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;

	//			//Si estamos encima de alguna pieza, comprobar que color es y si nos la podemos comer. 
	//			if (x == piezaX && y == piezaY)
	//			{
	//				ComprobarSiFichaHaMuerto(tablero->GetPiezas()[numeroFichaAComer], numeroFichaAComer, posicionPiezas[1], antiguaPosicion, "alfil");

	//			}
	//		}
	//		else
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}

	//	//En caso de que la torre no vaya a su máximo rango...
	//	if (posicionPiezas[1].y > posXY.y&& posicionPiezas[1].x < posXY.x)
	//	{
	//		for (int i = 0; i < posiblesPosiciones.size(); i++)
	//		{
	//			if (posiblesPosiciones[i] == posicionPiezas[1])
	//			{
	//				movimientoFueraDeRango = false;
	//			}
	//		}

	//		if (movimientoFueraDeRango == false)
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}




	//	}
	//}
	////Abajo a la derecha
	//else if (xDifference > 0 && yDifference > 0)
	//{
	//	std::cout << "\nAlfil quiere ir abajo a la derecha";
	//	int X = posicionPiezas[0].x;
	//	int Y = posicionPiezas[0].y;

	//	while (fillValues)
	//	{
	//		X++;
	//		Y++;

	//		sf::Vector2i posicionPosible = { X, Y };
	//		posiblesPosiciones.push_back(posicionPosible);

	//		if (X == 0 || Y == 0 || X == 7 || Y == 7)
	//			fillValues = false;
	//	}

	//	//Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
	//	for (int j = 0; j < posiblesPosiciones.size(); j++)
	//	{
	//		for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//		{


	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;

	//			int spritePosX = sprite.getPosition().x / 64;
	//			int spritePosY = sprite.getPosition().y / 64;

	//			//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//			//En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 
	//			if ((posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY) && (posicionPiezas[0].y < posiblesPosiciones[j].y && posicionPiezas[0].x < posiblesPosiciones[j].x))
	//			{
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				numeroFichaAComer = i;
	//				i = tablero->GetPiezas().size();
	//				j = posiblesPosiciones.size();
	//			}
	//			else
	//			{
	//				posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];

	//			}


	//		}
	//	}

	//	//Si la torre va a su máxima rango(posible pieza)
	//	if (posicionPiezas[1].y == posXY.y && posicionPiezas[1].x == posXY.x)
	//	{
	//		if (numeroFichaAComer > -1)
	//		{
	//			//Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
	//			//De esta manera parecerá que la pieza no se ha movido. 
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };


	//			int x = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().x / 64;
	//			int y = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().y / 64;

	//			sprite.setPosition(posicionPiezas[1].x * 64, posicionPiezas[1].y * 64);
	//			tablero->PI->PiezaEscojidaParaEnviar = "alfil";

	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;

	//			//Si estamos encima de alguna pieza, comprobar que color es y si nos la podemos comer. 
	//			if (x == piezaX && y == piezaY)
	//			{
	//				ComprobarSiFichaHaMuerto(tablero->GetPiezas()[numeroFichaAComer], numeroFichaAComer, posicionPiezas[1], antiguaPosicion, "alfil");

	//			}
	//		}
	//		else
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}

	//	//En caso de que la torre no vaya a su máximo rango...
	//	if (posicionPiezas[1].y < posXY.y && posicionPiezas[1].x < posXY.x)
	//	{
	//		for (int i = 0; i < posiblesPosiciones.size(); i++)
	//		{
	//			if (posiblesPosiciones[i] == posicionPiezas[1])
	//			{
	//				movimientoFueraDeRango = false;
	//			}
	//		}

	//		if (movimientoFueraDeRango == false)
	//		{
	//			sf::Vector2f posicionPieza
	//			{
	//			(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//			(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//			};
	//			sprite.setPosition(posicionPieza);
	//		}
	//	}

	//}
}
