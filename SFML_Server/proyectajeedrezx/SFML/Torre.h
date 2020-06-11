#pragma once
#include "Pieza.h"
class Torre : public Pieza
{
public: 
	Torre(ManejoConexiones& MC);
	void MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha);

};

