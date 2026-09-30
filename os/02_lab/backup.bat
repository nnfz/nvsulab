@echo off
chcp 65001 >nul
if "%~1"=="" goto usage
if "%~2"=="" goto usage
if "%~3"=="" goto usage
set "DEST=%~1"
set "EXT=%~2"
if not exist "%DEST%\" (
    mkdir "%DEST%"
    echo Создан резервный каталог: %DEST%
)
shift
shift
:loop
if "%~1"=="" goto done
if exist "%~1\" (
    echo Копирование из %~1
    for %%e in (%EXT%) do xcopy "%~1\*.%%e" "%DEST%\" /Y /I
) else (
    echo Каталог не найден: %~1
)
shift
goto loop
:done
echo Резервное копирование завершено
exit /b 0
:usage
echo Использование: backup.bat каталог_копии "расширения" каталог1 [каталог2 ...]
echo Пример: backup.bat D:\backup "txt,doc,xls" C:\docs D:\work
exit /b 1
