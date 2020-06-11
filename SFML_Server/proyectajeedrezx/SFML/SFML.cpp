#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include "PlayerInput.h"
#include "Pieza.h"
#include "Torre.h"
#include <thread>
#include "ManejoConexiones.h"

//SERVER

int main()
{
	ManejoConexiones Conexiones;
	Conexiones.ComprobarConexiones();

	return 0;
}

