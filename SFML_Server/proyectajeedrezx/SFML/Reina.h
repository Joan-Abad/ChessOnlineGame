#pragma once
#include "Pieza.h"
class Reina : public Pieza
{
public:
	Reina(ManejoConexiones & MC);
	void MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);
};

