echo ================Java SDK==========================
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll ..\java\PackingSdk\lib\x64\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll.lib ..\java\PackingSdk\Lib\x64\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\release\packingcli.exe ..\java\PackingSdk\Lib\x64\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\release\rsa.dll ..\java\PackingSdk\Lib\x64\rsa.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll ..\java\PackingSdk\Lib\x86\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll.lib ..\java\PackingSdk\Lib\x86\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packingcli.exe ..\java\PackingSdk\Lib\x86\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\rsa.dll ..\java\PackingSdk\Lib\x86\rsa.dll
echo �ڻ�����������������ΪJDK_BIN_PATH�Ļ�����������ֵΪ�㱾��JDK��bin·��������F:\ProgramFiles\Java\jdk1.8.0_144\bin
::�����ֱ�Ӵ�bat������°汾
if "%1"=="" call ..\UpdateVersion.exe
::java��bin��Ĭ��·��
set jdkBinPath=F:\ProgramFiles\Java\jdk1.8.0_144\bin
::��������˻�����������ȡ����������ֵ
if "%JDK_BIN_PATH%" neq "" set jdkBinPath=%JDK_BIN_PATH%
cd ../java
title ����ɾ����ʱ�ļ�
rd /s /q bin_cmd
md bin_cmd
cd bin_cmd
md META-INF
echo f| xcopy /F /Y ..\PackingSdk\MANIFEST.MF .\META-INF\MANIFEST.MF
cd ..
title ���ڱ���
"%jdkBinPath%\javac.exe" -sourcepath src -d bin_cmd -encoding utf8 -Djava.ext.dirs=PackingSdk\lib PackingSdk\src\*.java PackingSdk\src\com\xmplatform\knest\*.java PackingSdk\src\com\xmplatform\knest\input\*.java PackingSdk\src\com\xmplatform\knest\output\*.java PackingSdk\src\com\xmplatform\knest\tests\*.java
"%jdkBinPath%\jar.exe" cvfm PackingSdk\Build\packingSdk.jar bin_cmd\META-INF\MANIFEST.MF -C bin_cmd/ . 
rd /s /q bin_cmd
title ����ɾ������Ҫ���ļ�
rd /s /q "PackingSdk/.idea"
rd /s /q "PackingSdk/logs"
rd /s /q "PackingSdk/out"
title ����
if "%1"=="" pause