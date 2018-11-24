#include <iostream>

#include "scene_manager.h"
#include "scene_manager_fuego.h"
#include "scene_particula.h"
#include "scene_manager_lluvia.h"

int main(int argc, char* argv[])
{
	scene_manager s;
	s.start(argc, argv, "Proyecto Final", 500, 500);

	scene_manager_fuego a;
	a.start(argc, argv, "Proyecto Final", 500, 500);

	scene_manager_lluvia c;
	c.start(argc, argv, "Proyecto Final", 500, 500);

	return 0;
}