@echo off
chcp 65001 >nul
if "%~1"=="" goto usage
set "REPORT=%TEMP%\report_%COMPUTERNAME%.txt"
echo Отчёт о корневых каталогах > "%REPORT%"
echo Компьютер: %COMPUTERNAME% >> "%REPORT%"
echo Дата: %DATE% %TIME% >> "%REPORT%"
echo. >> "%REPORT%"
for %%d in (C D E F G H I J K L M N O P Q R S T U V W X Y Z) do (
    if exist %%d:\ (
        echo ===== Диск %%d: ===== >> "%REPORT%"
        dir %%d:\ >> "%REPORT%"
        echo. >> "%REPORT%"
    )
)
if not exist "%~1\" (
    echo Сетевой каталог недоступен: %~1
    echo Отчёт сохранён локально: %REPORT%
    exit /b 2
)
copy /Y "%REPORT%" "%~1\report_%COMPUTERNAME%.txt"
echo Отчёт скопирован в %~1
exit /b 0
:usage
echo Использование: report.bat сетевой_каталог
echo Пример: report.bat \\server\share\reports
exit /b 1
