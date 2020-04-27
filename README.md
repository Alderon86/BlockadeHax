# VRMeme
A proof of concept il2cpp cheat for VRChat that I scrapped which shows you how to cheat on an il2cpp unity game. <br />
```cs
auto Assembly = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");

		auto Class = Runtime::il2cpp_class_from_name(Assembly, "VRC", "PlayerManager");

		auto Method = Runtime::il2cpp_class_get_method_from_name(Class, "ǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄǄ", 0); //First function to return Player[];

		auto Result = Runtime::il2cpp_runtime_invoke(Method, NULL, NULL);```
