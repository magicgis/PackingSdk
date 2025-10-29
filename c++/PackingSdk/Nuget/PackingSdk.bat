chcp 65001 > nul
::检查是否存在以 .nupkg 为后缀的文件，如果有，就删除它们
dir /B *.nupkg > nul 2>&1
if %errorlevel% equ 0 (
::  存在以 .nupkg 为后缀的文件，删除它们
    del /Q *.nupkg
    echo delete all nupkg file success
) else (
    echo nupkg file not found
)
::运行打包
nuget pack PackingSdk.nuspec
title PackingSdk打包结束
pause