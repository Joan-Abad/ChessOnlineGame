#include "Torre.h"
#include <string>
#include "Utils.h"
#include "Rey.h"

Torre::Torre(Tablero& tablero, ColorPieza CP) : Pieza(tablero, CP)
{
	nombrePieza = "torre";
	float tamañoPieza = Utils::getTamanoPieza(*this->tablero->ventanaActiva);
	Utils::InitializeSprite(sprite, texture, CP, "../img/Torre");
	Utils::SetSpriteSize(sprite, tamañoPieza);
}


void Torre::MovimientoPieza(sf::Vector2i posicionPiezas)
{
	//tablero->PI->PiezaEscojidaParaEnviar = "torre";

	sf::Vector2f posicionPieza
	{
		float(posicionPiezas.x),
		float(posicionPiezas.y)
	};
	sprite.setPosition(posicionPieza);

	////Mirar a que direción va la ficha
	//int xDifference = posicionPiezas[1].x - posicionPiezas[0].x;
	//int yDifference = posicionPiezas[1].y - posicionPiezas[0].y;

	////Guardamos todas las posiciones a la que la torre se puede mover
	//std::vector<sf::Vector2i> posiblesPosiciones;

	////Posición final limite a la cual la torre se puede mover. 
	//sf::Vector2i posXY;

	////Variable para sumar todas las posibles posiciones de la torre. 
	//int contador = 1; 

	////Contador para saber que ficha eliminar del tablero si nos comemos una ficha. 
	//int numeroFichaAComer = -1;


	////Jugador quiere mover torre hacia abajo
	//if (yDifference > 0)
	//{
	//	//Rellenamos el vector posiblesPosiciones con todas las posiciones posibles de la torre según a que direción haya ido. 
	//	for (int i = posicionPiezas[0].y + 1; i < 8; i++)
	//	{
	//		sf::Vector2i posiblePosicion{
	//		posicionPiezas[0].x, i
	//		};

	//		posiblesPosiciones.push_back(posiblePosicion);
	//		contador++;
	//	}

	//	//Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
	//	for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//	{
	//		for (int j = 0; j < posiblesPosiciones.size(); j++)
	//		{
	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;

	//			//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//			//Recojiendo el primer valor y acabamos el for, nos aseguramos tener el valor más cercano a la torre. 
	//			if (posiblesPosiciones[j].x == tableroX	&& posiblesPosiciones[j].y == tableroY)
	//			{
	//				//Posicion máxima a la que se puede ir
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				numeroFichaAComer = i;
	//				j = posiblesPosiciones.size();
	//				i = tablero->GetPiezas().size();
	//			}
	//			else
	//			{
	//				posXY = posiblesPosiciones[posiblesPosiciones.size() - 1];
	//			}
	//		}
	//	}

	//	
	//	//Si la torre va a su máxima rango(posible pieza)
	//	if (posicionPiezas[1].y == posXY.y && posicionPiezas[0].x == posicionPiezas[1].x)
	//	{
	//		if (numeroFichaAComer > -1)
	//		{
	//			//Guardamos su posicion antigua
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };

	//			int x = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().x / 64;
	//			int y = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().y / 64;

	//			//cambiamos su posicion
	//			sprite.setPosition((posicionPiezas[1].x) * 64, (posicionPiezas[1].y) * 64);

	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;

	//			//Comprobamos que no este encima de ninguna otra pieza. 
	//			if (x == piezaX && y == piezaY)
	//			{
	//					ComprobarSiFichaHaMuerto(tablero->GetPiezas()[numeroFichaAComer], numeroFichaAComer, posicionPiezas[1], antiguaPosicion, "torre");
	//				
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
	//	//Si la torre se ha movido a menos de su máximo rango permitido. 
	//	if (posicionPiezas[1].y < posXY.y && posicionPiezas[0].x == posicionPiezas[1].x)
	//	{
	//		sf::Vector2f posicionPieza
	//		{
	//		(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//		(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//		};

	//		sprite.setPosition(posicionPieza);
	//	}
	//	
	//}
	////Jugador quiere mover torre hacia arriba
	//else if (yDifference < 0)
	//{
	//	contador = 1;
	//	int numeroFichaAComer = -1;

	//	//Rellenamos el vector posiblesPosiciones con todas las posiciones posibles de la torre según a que direción haya ido. 
	//	for (int i = posicionPiezas[0].y -1; i >= 0; i--)
	//	{
	//		sf::Vector2i posiblePosicion{
	//		posicionPiezas[0].x, posicionPiezas[0].y - contador
	//		};

	//		posiblesPosiciones.push_back(posiblePosicion);
	//		contador++;
	//	}

	//	//Revisamos las fichas y nos quedaremos en posXY el límite al cual la torre puede moverse, teniendo en cuenta las fichas del tablero. 
	//	for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//	{
	//		for (int j = 0; j < posiblesPosiciones.size(); j++)
	//		{
	//			
	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64 ;

	//			int spritePosX = sprite.getPosition().x / 64;
	//			int spritePosY = sprite.getPosition().y / 64;
	//			
	//			//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//			//En caso correcto, guardaremos el valor y seguiremos buscando, de esta manera el último valor será el que esté más cerca de la torre. 
	//			if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
	//			{
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				numeroFichaAComer = i;
	//			}

	//			
	//		}
	//	}

	//	//Si la torre va a su máxima rango(posible pieza)
	//	if (posicionPiezas[1].y == posXY.y && posicionPiezas[0].x == posicionPiezas[1].x)
	//	{
	//		if (numeroFichaAComer > -1)
	//		{
	//			//Guardamos la posición antigua para devloverla a su sitio en caso de que coma una pieza y sea del mismo color.
	//			//De esta manera parecerá que la pieza no se ha movido. 
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };


	//			int x = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().x / 64;
	//			int y = tablero->GetPiezas()[numeroFichaAComer]->GetSprite().getPosition().y / 64;

	//			sprite.setPosition(posicionPiezas[1].x * 64, posicionPiezas[1].y * 64);


	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;

	//			//Si estamos encima de alguna pieza, comprobar que color es y si nos la podemos comer. 
	//			if (x == piezaX && y == piezaY)
	//			{
	//					ComprobarSiFichaHaMuerto(tablero->GetPiezas()[numeroFichaAComer], numeroFichaAComer, posicionPiezas[1], antiguaPosicion, "torre");
	//				
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
	//	
	//	//En caso de que la torre no vaya a su máximo rango...
	//	if (posicionPiezas[1].y > posXY.y && posicionPiezas[0].x == posicionPiezas[1].x)
	//	{
	//		sf::Vector2f posicionPieza
	//		{
	//		(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//		(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//		};
	//		sprite.setPosition(posicionPieza);
	//	}
	//}

	////Mover la torre hacia la derecha
	//else if (xDifference > 0)
	//{
	//	contador = 1;
	//	int fichaABorrar = -1; 
	//	sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y};

	//	for (int i = posicionPiezas[0].x; i < 7; i++)
	//	{
	//		sf::Vector2i posiblePosicion{
	//		posicionPiezas[0].x + contador, posicionPiezas[0].y
	//		};

	//		posiblesPosiciones.push_back(posiblePosicion);
	//		contador++;
	//	}

	//	for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//	{
	//		for (int j = 0; j < posiblesPosiciones.size(); j++)
	//		{				

	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;
	//			//Existe alguna ficha en las posiciones posibles?
	//			if (posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY)
	//			{
	//				//Posicion máxima a la que se puede ir
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				fichaABorrar = i;

	//				j = posiblesPosiciones.size();
	//				i = tablero->GetPiezas().size();					
	//			}

	//			else
	//			{
	//				posXY = posiblesPosiciones[posiblesPosiciones.size() -1];
	//				
	//			}
	//		}
	//	}
	//	
	//	// Si la torre se mueve al rango máximo permitido, comprobar si hay ficha a la que se pueda comer. 
	//	if (posicionPiezas[1].x == posXY.x)
	//	{
	//		if (fichaABorrar > -1)
	//		ComprobarSiFichaHaMuerto(tablero->GetPiezas()[fichaABorrar], fichaABorrar, posicionPiezas[1], antiguaPosicion, "torre");
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
	//	//
	//	if (posicionPiezas[1].x < posXY.x && posicionPiezas[0].y == posicionPiezas[1].y)
	//	{
	//		sf::Vector2f posicionPieza
	//		{
	//		(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//		(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//		};
	//		sprite.setPosition(posicionPieza);
	//	}

	//}
	////Mover torre hacia la izquierda
	//else if(xDifference < 0)
	//{

	//	contador = 1; 
	//	int fichaABorrar = -1;

	//	sf::Vector2f antiguaPosicion = { sprite.getPosition().x, sprite.getPosition().y };

	//	//Rellenamos el vector posiblesPosiciones con todas las posiciones posibles de la torre según a que direción haya ido. 
	//	for (int i = posicionPiezas[0].x - 1; i >= 0; i--)
	//	{
	//		sf::Vector2i posiblePosicion{
	//		i, posicionPiezas[0].y
	//		};

	//		posiblesPosiciones.push_back(posiblePosicion);
	//		contador++;
	//	}

	//	//Comprobar si alguna de nuestras posibles posiciones de ir coincide con alguna ficha. 
	//	//Recojiendo el primer valor y acabamos el for, nos aseguramos tener el valor más cercano a la torre. 
	//	for (int i = 0; i < tablero->GetPiezas().size(); i++)
	//	{
	//		for (int j = 0; j < posiblesPosiciones.size(); j++)
	//		{
	//			sf::Vector2f antiguaPosicion = { sprite.getPosition().x / 64, sprite.getPosition().y / 64 };

	//			int tableroX = tablero->GetPiezas()[i]->GetSprite().getPosition().x / 64;
	//			int tableroY = tablero->GetPiezas()[i]->GetSprite().getPosition().y / 64;
	//			int piezaX = sprite.getPosition().x / 64;
	//			int piezaY = sprite.getPosition().y / 64;
	//			if ((posiblesPosiciones[j].x == tableroX && posiblesPosiciones[j].y == tableroY) )
	//			{	
	//				posXY.x = posiblesPosiciones[j].x;
	//				posXY.y = posiblesPosiciones[j].y;
	//				fichaABorrar = i; 
	//			}
	//			

	//		}
	//	}

	//	// Si la pieza se mueve en su limite
	//	if (posicionPiezas[1].x > posXY.x && posicionPiezas[0].y == posicionPiezas[1].y)
	//	{
	//		sf::Vector2f posicionPieza
	//		{
	//		(posicionPiezas[1].x) * Utils::getTamanoPieza(*tablero->PI->window),
	//		(posicionPiezas[1].y) * Utils::getTamanoPieza(*tablero->PI->window)
	//		};
	//		sprite.setPosition(posicionPieza);
	//	}
	//	// Si llega al limite
	//	if (posicionPiezas[1].x == posXY.x )
	//	{
	//		if(fichaABorrar > -1)
	//		ComprobarSiFichaHaMuerto(tablero->GetPiezas()[fichaABorrar], fichaABorrar, posicionPiezas[1], antiguaPosicion, "torre");
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
	//	
	//}
}


