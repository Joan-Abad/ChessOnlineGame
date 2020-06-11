#pragma once
#include "Pieza.h"
class Caballo : public Pieza
{
public:
	Caballo(ManejoConexiones& MC);
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas[2]);
	void MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);

};

