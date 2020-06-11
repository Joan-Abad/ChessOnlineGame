#pragma once
#include "Pieza.h"

extern enum ColorPieza;
class Alfil : public Pieza
{
public:
	Alfil(ManejoConexiones& MC);
	void MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);

};

