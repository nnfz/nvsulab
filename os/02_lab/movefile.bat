@echo off
chcp 65001 >nul
if "%~1"=="" goto usage
if "%~2"=="" goto usage
if not exist "%~1" (
    echo Исходный файл не найден: %~1
    exit /b 2
)
if not exist "%~2\" mkdir "%~2"
copy /Y "%~1" "%~2\%~nx1"
if errorlevel 1 (
    echo Ошибка копирования
    exit /b 3
)
choice /c YN /m "Удалить файл из исходного каталога"
if errorlevel 2 goto keep
del "%~1"
echo Файл перемещён
exit /b 0
:keep
echo Исходный файл сохранён, выполнено копирование
exit /b 0
:usage
echo Использование: movefile.bat файл каталог_назначения
exit /b 1
