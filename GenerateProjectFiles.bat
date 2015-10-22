@echo off
"%UE4%\Engine\Binaries\DotNET\UnrealBuildTool.exe" -projectfiles -game -engine "%~dp0Game.uproject"
