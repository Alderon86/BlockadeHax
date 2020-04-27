#pragma once
#include <vector>
#include "Player.h"
#include "Types.h"
#include "Runtime.h"

struct PlayerManager {
	static Il2CppObject* GetAllPlayers()
	{
		auto Assembly = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");

		auto Class = Runtime::il2cpp_class_from_name(Assembly, "VRC", "PlayerManager");

		auto Method = Runtime::il2cpp_class_get_method_from_name(Class, "ǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄ", 0); //First function to return Player[];

		auto Result = Runtime::il2cpp_runtime_invoke(Method, NULL, NULL);

		return Result;
	}

};