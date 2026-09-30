@echo off
chcp 65001 >nul
if "%~1"=="" goto usage
if not exist "%~1" (
    echo В текущем каталоге нет файла %~1
    exit /b 2
)
set FOUND=0
for /f "delims=" %%f in ('dir /s /b "%TEMP%\%~1" 2^>nul') do (
    set FOUND=1
    echo Найден: %%f
    fc "%%f" "%~1"
)
if "%FOUND%"=="0" echo Файл %~1 не найден в %TEMP%
exit /b 0
:usage
echo Использование: findtmp.bat имя_файла
exit /b 1
