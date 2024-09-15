@echo off
:: Check if the source file is provided
call :check_input "%~1"

:: OPTIONAL Set the path to GCC executable
::set GCC_PATH=C:\MinGW\bin\gcc.exe
set GCC_PATH=gcc

:: Get the source file
set SOURCE_FILE=%~1
:: Get the base name of the source file (without extension)
for %%f in ("%SOURCE_FILE%") do set FILE_NAME=%%~nf

:: Set payload path
if "%~2"=="-e" (
    set PAYLOAD=".\payload_encrypted\payload.c"
    echo Encrypted payload set
) else (
    set PAYLOAD=".\payload\payload.c"
    echo Normal payload set
)

:: Compile the source file
echo Compiling %SOURCE_FILE%...
"%GCC_PATH%" "%SOURCE_FILE%" "%PAYLOAD%" -o "%FILE_NAME%.exe" "-lwininet"

:: Check if compilation succeeded
if %ERRORLEVEL% equ 0 (
    echo Compilation successful: %FILE_NAME%.exe
    exit 0
) else (
    echo Compilation failed.
    exit 1
)

:check_input
if "%~1"=="" (
    :: Check if input file is specified
    echo Usage: %~nx0 source_file
    exit 1
) else if "%~1"==".\payload\payload.c" (
    echo %~1 is not meant to be compiled
    exit 1
) else if "%~1"==".\payload_encrypted\payload.c" (
    echo %~1 is not meant to be compiled
    exit 1
) else if not exist "%~1" (
    :: Check if the source file exists
    echo Source file not found: %~1
    exit 1
)