echo ================Java SDK==========================
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll ..\java\PackingSdk\lib\x64\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\release\packing.dll.lib ..\java\PackingSdk\Lib\x64\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\release\packingcli.exe ..\java\PackingSdk\Lib\x64\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\release\rsa.dll ..\java\PackingSdk\Lib\x64\rsa.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll ..\java\PackingSdk\Lib\x86\packing.dll
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packing.dll.lib ..\java\PackingSdk\Lib\x86\packing.dll.lib
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\packingcli.exe ..\java\PackingSdk\Lib\x86\packingcli.exe
echo f| xcopy /F /Y ..\..\Packing\target\i686-win7-windows-msvc\release\rsa.dll ..\java\PackingSdk\Lib\x86\rsa.dll
echo 在环境变量中增加名称为JDK_BIN_PATH的环境变量，其值为你本机JDK的bin路径，例如F:\ProgramFiles\Java\jdk1.8.0_144\bin
::如果是直接打开bat，则更新版本
if "%1"=="" call ..\UpdateVersion.exe
::java的bin的默认路径
set jdkBinPath=F:\ProgramFiles\Java\jdk1.8.0_144\bin
::如果配置了环境变量，则取环境变量的值
if "%JDK_BIN_PATH%" neq "" set jdkBinPath=%JDK_BIN_PATH%
cd ../java
title 正在删除临时文件
rd /s /q bin_cmd
md bin_cmd
cd bin_cmd
md META-INF
echo f| xcopy /F /Y ..\PackingSdk\MANIFEST.MF .\META-INF\MANIFEST.MF
cd ..
title 正在编译
"%jdkBinPath%\javac.exe" -sourcepath src -d bin_cmd -encoding utf8 -Djava.ext.dirs=PackingSdk\lib PackingSdk\src\*.java PackingSdk\src\com\xmplatform\knest\*.java PackingSdk\src\com\xmplatform\knest\input\*.java PackingSdk\src\com\xmplatform\knest\output\*.java PackingSdk\src\com\xmplatform\knest\tests\*.java
"%jdkBinPath%\jar.exe" cvfm PackingSdk\Build\packingSdk.jar bin_cmd\META-INF\MANIFEST.MF -C bin_cmd/ . 
rd /s /q bin_cmd
title 正在删除不必要的文件
rd /s /q "PackingSdk/.idea"
rd /s /q "PackingSdk/logs"
rd /s /q "PackingSdk/out"
title 结束
if "%1"=="" pause