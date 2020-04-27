# VRMeme
A proof of concept il2cpp cheat for VRChat that I scrapped which shows you how to cheat on an il2cpp unity game. <br />

Example of invoking an il2cpp method: 
```cpp
auto Assembly = Runtime::il2cpp_assembly_get_image("assemblyname"); //Example: Assembly-CSharp

auto Class = Runtime::il2cpp_class_from_name(Assembly, "namespace", "className"); //If the namespace is not there, just pass in ""

auto Method = Runtime::il2cpp_class_get_method_from_name(Class, "methodName", 0); //Pass in the target method's name, so if I wanted to attack a method called KillCurrentPlayer(), I'd pass in the name KillCurrentPlayer by itself.

auto Result = Runtime::il2cpp_runtime_invoke(Method, NULL, NULL); //Execute the method and get the result as an Il2CppObject which you can do whatever you want with.```
