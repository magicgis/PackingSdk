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
echo �ڻ�����������������ΪVS_DEV_PATH�Ļ�����������ֵΪ�㱾��vs�ı�������·��������C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\devenv.exe
echo =========================================================================================
::vs��Ĭ��·��
set devenvPath="F:\ProgramFiles\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"
::��������˻�����������ȡ����������ֵ
if "%VS_DEV_PATH%" neq "" set devenvPath=%VS_DEV_PATH%
title ���ڱ���32λ
%devenvPath% ./PackingSdk/PackingSdk.sln /Build "Release|x86"
title ���ڱ���64λ
%devenvPath% ./PackingSdk/PackingSdk.sln /Build "Release|x64"
title ����ɾ������Ҫ���ļ�
rd /s /q "PackingSdk/.vs"
rd /s /q "PackingSdk/bin"
rd /s /q "PackingSdk/Build/Temp"
rd /s /q "PackingSdk/Build/x64/Debug"
rd /s /q "PackingSdk/Build/x86/Debug"
title �������
::�����ֱ�Ӵ�bat������ͣ������ֱ���˳�
if "%1"=="" pause