#include "PlayerInput.h"

PlayerInput::PlayerInput(sf::RenderWindow &window, Tablero& tablero)
{
	//this->MuevesFicha = MuevesPieza;
	gameStatus = EnPartida;
	ColorFichasJugador = Blanca;

	this->window = &window;
	this->tablero = &tablero;

	MuevesFicha = NULL;

	sf::Vector2f cursorSize = { 1,1 };
	cursor.setSize(cursorSize);
	cursor.setFillColor(sf::Color::Transparent);
	cursor.setOrigin(cursor.getSize().x / 2, cursor.getSize().y / 2);
	
	//Marcador
	marcadorPieza.setOutlineColor(sf::Color::Transparent);
	marcadorPieza.setOutlineThickness(1.6f);
	marcadorPieza.setFillColor(sf::Color::Transparent);
	marcadorPieza.setSize(sf::Vector2f(Utils::getTamanoPieza(window) - Utils::getTamanoPieza(window)/60, Utils::getTamanoPieza(window) - Utils::getTamanoPieza(window) /60));
	colorDePieza = NULL;

	
}

void PlayerInput::MouseDetection(sf::TcpSocket *socket, bool &gameOver, sf::Event& event)
{

	if (firstClick == false)
	{
		//system("cls");
		firstClick = true;
	}
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
			gameOver = true;
		}
		
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isPressed == false) {
			//std::cout << "Ha clicado el loco este";
			isPressed = true;
			if (isPressed == true) {
				mousePosition = sf::Mouse::getPosition(*window);
				if ((mousePosition.x > 0 && mousePosition.x < window->getSize().x) &&
					mousePosition.y > 0 && mousePosition.y < window->getSize().y)
				{
					cursor.setPosition(sf::Vector2f(mousePosition));
					MouseCheckInteraction(socket);
				}
			}
		}
		
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false) {
			//std::cout << "Ha desclicado";
			isPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			ColorFichasJugador = Negra;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			ColorFichasJugador = Blanca;
	}
}
	
}

void PlayerInput::drawCursor(sf::RenderWindow& window)
{
	window.draw(cursor);
	window.draw(marcadorPieza);
}

void PlayerInput::MouseCheckInteraction(sf::TcpSocket* socket)
{

	if (MuevesFicha == true) {

		sf::Packet sendPacket;

		//recorre todas las piezas del tablero
		for (int i = 0; i < tablero->GetPiezas().size(); i++) {
			//comprobar si has cojido alguna ficha
			if (cursor.getGlobalBounds().intersects(tablero->GetPiezas()[i]->GetSprite().getGlobalBounds()))
			{
				if (!PiezaEscojida && i != tablero->GetPiezas().size())
				{
					PiezaEscojida = tablero->GetPiezas()[i];
					if (PiezaEscojida->colorPieza == ColorFichasJugador)
					{
						//actualizamos las posicion del marcador
						marcadorPieza.setPosition(PiezaEscojida->GetSprite().getPosition());
						posiciones[0] = sf::Vector2i(PiezaEscojida->GetSprite().getPosition().x / Utils::getTamanoPieza(*window), PiezaEscojida->GetSprite().getPosition().y / Utils::getTamanoPieza(*window));
						marcadorPieza.setOutlineColor(sf::Color::Red);
						fichaNumero = i;
						i = tablero->GetPiezas().size();
						//sendPacket << ;
					}
				}

			}
			else if (PiezaEscojida) {
				posiciones[1] = sf::Vector2i(int(mousePosition.x / Utils::getTamanoPieza(*window)), int(mousePosition.y / Utils::getTamanoPieza(*window)));
				Utils::PrintVector2(posiciones[1]);


				

				for (int i = 0; i < tablero->GetPiezas().size(); i++)
				{
					if (tablero->GetPiezas()[i]->GetSprite().getPosition().x == posiciones[1].x * Utils::getTamanoPieza(*window) &&
						tablero->GetPiezas()[i]->GetSprite().getPosition().y == posiciones[1].y * Utils::getTamanoPieza(*window))
					{
						comerFicha = true;
						PiezaAComer = i;
						i = tablero->GetPiezas().size();
					}
					else
					{
						PiezaAComer = -1;
						comerFicha = false;
					}
				}


				//Mueves Ficha = Te toca mover 
				//Color pieza = Blancas o negras
				//Ficha numero = Para saber que ficha se refiere (ID)
				//NombrePieza = "peon", "alfil"
				//Posiciones[0] = 0-7 posicion de la ficha en el tablero
				//Posiciones[1] = 0-7 posicion de la ficha deseada 
				//ComerFicha = Puede comer ficha

				
				sendPacket << fichaNumero << MuevesFicha << ColorFichasJugador << 
				PiezaAComer << PiezaEscojida->nombrePieza <<
				posiciones[0].x << posiciones[0].y << 
				posiciones[1].x << posiciones[1].y << comerFicha;
				socket->send(sendPacket);

				



				aceptarPartida = true;

				PiezaEscojida = nullptr;
				i = tablero->GetPiezas().size();
				marcadorPieza.setOutlineColor(sf::Color::Transparent);


			}
		}
	}
}
	
	

