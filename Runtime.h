#pragma once
#include "Types.h"
#include <Windows.h>

typedef Il2CppString* (*il2cpp_string_new_t)(const char* str);
typedef Il2CppImage* (*il2cpp_assembly_get_image_t)(Il2CppAssembly* assembly);
typedef Il2CppAssembly* (*il2cpp_domain_assembly_open_t)(Il2CppDomain* domain, const char* name);
typedef Il2CppClass* (*il2cpp_class_from_name_t)(Il2CppImage* assembly, const char* name_space, const char* name);
typedef Il2CppMethod* (*il2cpp_class_get_method_from_name_t)(Il2CppClass* klass, const char* name, int paramcount);
typedef Il2CppObject* (*il2cpp_runtime_invoke_t)(Il2CppMethod* method, void* obj, void** params, Il2CppObject* exec);
typedef Il2CppArray* (*il2cpp_array_new_t)(Il2CppClass* klass, uint32_t length);

struct Runtime {
	static HMODULE GetIL2CPPModule()
	{
		auto mod = GetModuleHandle(L"GameAssembly.dll");

		if (mod != NULL)
		{
			return mod;
		}
	}
	static Il2CppImage* il2cpp_assembly_get_image(const char* name)
	{
		auto il2cpp_assembly_get_image = (il2cpp_assembly_get_image_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_assembly_get_image");
		auto assembly = (il2cpp_domain_assembly_open_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_domain_assembly_open");

		return il2cpp_assembly_get_image(assembly(NULL, name));
	}
	static Il2CppClass* il2cpp_class_from_name(Il2CppImage* assembly, const char* name_space, const char* name)
	{
		auto il2cpp_class_from_name = (il2cpp_class_from_name_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_class_from_name");

		return il2cpp_class_from_name(assembly, name_space, name);
	}
	static Il2CppMethod* il2cpp_class_get_method_from_name(Il2CppClass* klass, const char* name, int paramcount)
	{
		auto il2cpp_class_get_method_from_name = (il2cpp_class_get_method_from_name_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_class_get_method_from_name");

		return il2cpp_class_get_method_from_name(klass, name, paramcount);
	}
	static Il2CppObject* il2cpp_runtime_invoke(Il2CppMethod* method, void* obj, void** params)
	{
		auto il2cpp_runtime_invoke = (il2cpp_runtime_invoke_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_runtime_invoke");

		return il2cpp_runtime_invoke(method, obj, params, NULL);
	}
	static Il2CppArray* il2cpp_array_new(Il2CppClass* klass, uint32_t length)
	{
		auto il2cpp_array_new = (il2cpp_array_new_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_array_new");

		return il2cpp_array_new(klass, length);
	}
	static Il2CppString* il2cpp_string_new(const char* str)
	{
		auto il2cpp_string = (il2cpp_string_new_t)GetProcAddress(GetIL2CPPModule(), "il2cpp_string_new");

		return il2cpp_string(str);
	}
};