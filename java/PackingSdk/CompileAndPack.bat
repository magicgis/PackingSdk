echo ================��������==========================
echo �ڻ�����������������ΪJDK_BIN_PATH�Ļ�����������ֵΪ�㱾��JDK��bin·��������F:\ProgramFiles\Java\jdk1.8.0_144\bin
::java��bin��Ĭ��·��
set jdkBinPath=F:\ProgramFiles\Java\jdk1.8.0_144\bin
::��������˻�����������ȡ����������ֵ
if "%JDK_BIN_PATH%" neq "" set jdkBinPath=%JDK_BIN_PATH%
cd ../
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
title ��������ɣ����ɵ�jar��·��ΪPackingSdk\Build\packingSdk.jar
if "%1"=="" pause