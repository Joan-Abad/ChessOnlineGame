#pragma once
#include "SFML/Graphics.hpp"
#include "Utils.h"
#include <iostream>
#include"PlayerInput.h"
#include <vector>
#include "Tablero.h"
enum TiposPiezas{
	eAlfil,
	ePeon,
	eTorre,
	eRey,
	eReina,
	eCaballo
};
enum ColorPieza
{
	Blanca,
	Negra
};
class PlayerInput;
class Tablero;

class Pieza
{
public:
	Pieza(Tablero& tablero, ColorPieza CP);

private:
	sf::Vector2i posicionFichaComprobacion;

protected: 
	sf::Texture texture;
	sf::Sprite sprite;
	Tablero* tablero = nullptr;
	TiposPiezas tipoDePieza;
	void ComprobarSiFichaHaMuerto(Pieza* pieza, int iteratorRase, sf::Vector2i nuevaPosicion, sf::Vector2f antiguaPosicion, std::string PiezaEnviar);
	void ComePieza(sf::Vector2f NuevaPosicion);
	bool moverHaciaDelante;

public:
	inline TiposPiezas& GetTipoPieza() { return tipoDePieza; }
	sf::Sprite &GetSprite();
	bool primeraTiradaDeLaFicha = true;
	virtual void MovimientoPieza(sf::Vector2i posicionPiezas);
	ColorPieza colorPieza;
	std::string nombrePieza;
};

