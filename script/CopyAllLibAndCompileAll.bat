title ��ȡtoml�İ汾�ţ������µ�����sdk
call ..\UpdateVersion.exe
title ����C#SDK
::����dll������C# SDK
call CopyLibAndCompile_C#.bat all
title ����C++SDK
::����dll������C++ SDK
call CopyLibAndCompile_C++.bat all
title ����JavaSDK
::����dll������Java SDK
call CopyLibAndCompile_Java.bat all
title ����SDK����all
pause