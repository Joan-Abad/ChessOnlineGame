#include "Rey.h"

Rey::Rey(ManejoConexiones& MC) 
{
    this->MC = &MC;
}
 

 void Rey::MovimientoPiezaValido(sf::Vector2i posicionPiezas[2], std::vector<sf::TcpSocket*> clientes, int idFicha, int colorFicha, bool comerFicha)
 {
     bool movimientoValido = false;
     std::vector <sf::Vector2i> posiblesPosiciones2;
     sf::Vector2f posAntigua = sprite.getPosition();

     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 1, posicionPiezas[0].y));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x, posicionPiezas[0].y - 1));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 1, posicionPiezas[0].y + 1));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x + 1, posicionPiezas[0].y - 1));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 1, posicionPiezas[0].y + 1));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 1, posicionPiezas[0].y - 1));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x, posicionPiezas[0].y + 1));
     posiblesPosiciones2.push_back(sf::Vector2i(posicionPiezas[0].x - 1, posicionPiezas[0].y));

     for (int i = 0; i < posiblesPosiciones2.size(); i++) {
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
