#include <iostream>

#include "scene_manager.h"

int main(int argc, char* argv[])
{
	scene_manager s;
	s.start(argc, argv, "Circle Grid", 400, 400);

	return 0;
}