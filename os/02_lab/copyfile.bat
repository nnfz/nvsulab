@echo off
chcp 65001 >nul
if "%~1"=="" goto usage
if "%~2"=="" goto usage
if not exist "%~1" (
    echo Исходный файл не найден: %~1
    exit /b 2
)
if not exist "%~2\" mkdir "%~2"
if exist "%~2\%~nx1" (
    echo ВНИМАНИЕ: файл %~nx1 уже существует в каталоге %~2
    choice /c YN /m "Перезаписать"
    if errorlevel 2 goto cancel
)
copy /Y "%~1" "%~2\"
exit /b 0
:cancel
echo Копирование отменено
exit /b 0
:usage
echo Использование: copyfile.bat файл каталог_назначения
exit /b 1
