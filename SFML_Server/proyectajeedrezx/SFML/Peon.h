#pragma once
#include "Pieza.h"
#include <SFML/Network.hpp>
#include <vector>

class Peon : public Pieza
{
public:
	Peon(ManejoConexiones & MC);
	void MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);
};

