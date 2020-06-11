#pragma once
#include "Pieza.h"
class Rey : public Pieza
{
public:
	Rey(ManejoConexiones & MC);
	void MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);
};

