echo ================C# SDK==========================
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll ..\c#\PackingSdk\Lib\x64\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll.lib ..\c#\PackingSdk\Lib\x64\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\release\packingcli.exe ..\c#\PackingSdk\Lib\x64\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\release\rsa.dll ..\c#\PackingSdk\Lib\x64\rsa.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll ..\c#\PackingSdk\Lib\x86\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll.lib ..\c#\PackingSdk\Lib\x86\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packingcli.exe ..\c#\PackingSdk\Lib\x86\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\rsa.dll ..\c#\PackingSdk\Lib\x86\rsa.dll
echo 在环境变量中增加名称为VS_DEV_PATH的环境变量，其值为你本机vs的编译器的路径，例如C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\devenv.exe
::如果是直接打开bat，则更新版本
if "%1"=="" call ..\UpdateVersion.exe
::vs的默认路径
set devenvPath="D:\ProgramFiles\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe"
::如果配置了环境变量，则取环境变量的值
if "%VS_DEV_PATH%" neq "" set devenvPath=%VS_DEV_PATH%
title 正在编译Any CPU
%devenvPath% ../c#/PackingSdk/PackingSdk.sln /Build "Release|Any CPU"
title 正在删除不必要的文件
rd /s /q "../c#/PackingSdk/.vs"
rd /s /q "../c#/PackingSdk/ConsoleProject/obj"
rd /s /q "../c#/PackingSdk/TestProject/obj"
rd /s /q "../c#/PackingSdk/Build/obj"
rd /s /q "../c#/PackingSdk/Build/Debug"
title 编译结束
::如果是直接打开bat，则暂停，否则直接退出
if "%1"=="" pause