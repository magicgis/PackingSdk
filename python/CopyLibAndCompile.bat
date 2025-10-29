echo f| xcopy /F /Y ..\..\target\release\packing.dll PackingSdk\sdk\Lib\x64\packing.dll
echo f| xcopy /F /Y ..\..\target\release\packing.dll.lib PackingSdk\sdk\Lib\x64\packing.dll.lib
echo f| xcopy /F /Y ..\..\target\release\packingcli.exe PackingSdk\sdk\Lib\x64\packingcli.exe
echo f| xcopy /F /Y ..\..\target\release\rsa.dll PackingSdk\sdk\Lib\x64\rsa.dll
echo f| xcopy /E /Y ..\..\target\release\frontend PackingSdk\sdk\Lib\x64\frontend\
echo f| xcopy /F /Y ..\..\target\i686-win7-windows-msvc\release\packing.dll PackingSdk\sdk\Lib\x86\packing.dll
echo f| xcopy /F /Y ..\..\target\i686-win7-windows-msvc\release\packing.dll.lib PackingSdk\sdk\Lib\x86\packing.dll.lib
echo f| xcopy /F /Y ..\..\target\i686-win7-windows-msvc\release\packingcli.exe PackingSdk\sdk\Lib\x86\packingcli.exe
echo f| xcopy /F /Y ..\..\target\i686-win7-windows-msvc\release\rsa.dll PackingSdk\sdk\Lib\x86\rsa.dll
echo f| xcopy /E /Y ..\..\target\i686-win7-windows-msvc\release\frontend PackingSdk\sdk\Lib\x86\frontend\
echo 在环境变量中增加名称为VS_DEV_PATH的环境变量，其值为你本机vs的编译器的路径，例如C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\devenv.exe
echo =========================================================================================
::vs的默认路径
set devenvPath="F:\ProgramFiles\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"
::如果配置了环境变量，则取环境变量的值
if "%VS_DEV_PATH%" neq "" set devenvPath=%VS_DEV_PATH%
title 正在编译32位
%devenvPath% ./PackingSdk/PackingSdk.sln /Build "Release|x86"
title 正在编译64位
%devenvPath% ./PackingSdk/PackingSdk.sln /Build "Release|x64"
title 正在删除不必要的文件
rd /s /q "PackingSdk/.vs"
rd /s /q "PackingSdk/bin"
rd /s /q "PackingSdk/Build/Temp"
rd /s /q "PackingSdk/Build/x64/Debug"
rd /s /q "PackingSdk/Build/x86/Debug"
title 编译结束
::如果是直接打开bat，则暂停，否则直接退出
if "%1"=="" pause