echo ================C# SDK==========================
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll ..\c#\PackingSdk\Lib\x64\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll.lib ..\c#\PackingSdk\Lib\x64\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\release\packingcli.exe ..\c#\PackingSdk\Lib\x64\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\release\rsa.dll ..\c#\PackingSdk\Lib\x64\rsa.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll ..\c#\PackingSdk\Lib\x86\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll.lib ..\c#\PackingSdk\Lib\x86\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packingcli.exe ..\c#\PackingSdk\Lib\x86\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\rsa.dll ..\c#\PackingSdk\Lib\x86\rsa.dll
echo �ڻ�����������������ΪVS_DEV_PATH�Ļ�����������ֵΪ�㱾��vs�ı�������·��������C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\devenv.exe
::�����ֱ�Ӵ�bat������°汾
if "%1"=="" call ..\UpdateVersion.exe
::vs��Ĭ��·��
set devenvPath="D:\ProgramFiles\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe"
::��������˻�����������ȡ����������ֵ
if "%VS_DEV_PATH%" neq "" set devenvPath=%VS_DEV_PATH%
title ���ڱ���Any CPU
%devenvPath% ../c#/PackingSdk/PackingSdk.sln /Build "Release|Any CPU"
title ����ɾ������Ҫ���ļ�
rd /s /q "../c#/PackingSdk/.vs"
rd /s /q "../c#/PackingSdk/ConsoleProject/obj"
rd /s /q "../c#/PackingSdk/TestProject/obj"
rd /s /q "../c#/PackingSdk/Build/obj"
rd /s /q "../c#/PackingSdk/Build/Debug"
title �������
::�����ֱ�Ӵ�bat������ͣ������ֱ���˳�
if "%1"=="" pause