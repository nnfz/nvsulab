@echo off
chcp 65001 >nul
if "%~1"=="" goto usage
if not exist "%~1" (
    echo Файл не найден: %~1
    exit /b 2
)
choice /c YN /m "Удалить файл %~1"
if errorlevel 2 goto cancel
del "%~1"
echo Файл удалён
exit /b 0
:cancel
echo Удаление отменено
exit /b 0
:usage
echo Использование: delfile.bat имя_файла
exit /b 1
