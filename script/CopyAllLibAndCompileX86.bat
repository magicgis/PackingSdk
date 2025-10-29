title 读取toml的版本号，并更新到各个sdk
call ..\UpdateVersion.exe
title 处理C#SDK
::拷贝dll并编译C# SDK
call CopyLibAndCompile_C#.bat x86
title 处理C++SDK
::拷贝dll并编译C++ SDK
call CopyLibAndCompile_C++.bat x86
title 处理JavaSDK
::拷贝dll并编译Java SDK
call CopyLibAndCompile_Java.bat x86
title 处理SDK结束x86
pause