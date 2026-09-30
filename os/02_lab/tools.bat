@echo off
chcp 65001 >nul
:menu
cls
echo ==== Помощник пользователя ====
echo 1 - Информация о системе
echo 2 - Сетевые настройки
echo 3 - Очистка временных файлов
echo 4 - Свободное место на дисках
echo 5 - Выключение компьютера через N секунд
echo 6 - Отмена выключения
echo 0 - Выход
choice /c 1234560 /n /m "Ваш выбор: "
set SEL=%errorlevel%
if %SEL%==7 exit /b 0
if %SEL%==1 goto sysinfo
if %SEL%==2 goto net
if %SEL%==3 goto clean
if %SEL%==4 goto disks
if %SEL%==5 goto shut
if %SEL%==6 goto abort
goto menu
:sysinfo
echo Компьютер: %COMPUTERNAME%
echo Пользователь: %USERNAME%
echo Дата: %DATE% %TIME%
systeminfo | findstr /b /c:"Название ОС" /c:"OS Name" /c:"Тип системы" /c:"System Type"
pause
goto menu
:net
ipconfig | findstr /i "IPv4"
pause
goto menu
:clean
choice /c YN /m "Удалить файлы из %TEMP%"
if errorlevel 2 goto menu
del /q /f /s "%TEMP%\*.*" 2>nul
echo Очистка выполнена
pause
goto menu
:disks
for %%d in (C D E F G H) do if exist %%d:\ (
    echo Диск %%d:
    dir %%d:\ | findstr /c:"free" /c:"свободно"
)
pause
goto menu
:shut
set /p SEC=Секунд до выключения: 
shutdown /s /t %SEC%
pause
goto menu
:abort
shutdown /a
pause
goto menu
