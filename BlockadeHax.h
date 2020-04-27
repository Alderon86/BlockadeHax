#pragma once
#include "Console.h"
#include "Runtime.h"

struct BlockadeHax {
	static void Inject()
	{
		Console::ShowConsole("Blockade3D Hax");

		std::cin.get();
	}
};