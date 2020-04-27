#pragma once
#include "Console.h"
#include "Runtime.h"

struct VRMeme {
	static void Inject()
	{
		Console::ShowConsole("VRMeme");


		std::cin.get();
	}
};