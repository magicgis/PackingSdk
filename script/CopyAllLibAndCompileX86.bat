title ��ȡtoml�İ汾�ţ������µ�����sdk
call ..\UpdateVersion.exe
title ����C#SDK
::����dll������C# SDK
call CopyLibAndCompile_C#.bat x86
title ����C++SDK
::����dll������C++ SDK
call CopyLibAndCompile_C++.bat x86
title ����JavaSDK
::����dll������Java SDK
call CopyLibAndCompile_Java.bat x86
title ����SDK����x86
pause