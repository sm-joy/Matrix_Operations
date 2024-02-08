@echo off

:: Get the root directory name
for %%I in (.) do set "ROOT_NAME=%%~nxI"

:: Set project directories
set SRC_DIR=src
set BIN_DIR=bin\release
set EXE_NAME=%ROOT_NAME%.exe

:: Create the bin directory if it doesn't exist
if not exist %BIN_DIR% mkdir %BIN_DIR%

:: Compile C++ files
g++ -o %BIN_DIR%\%EXE_NAME% %SRC_DIR%\*.cpp

:: Check if compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b %errorlevel%
)

echo Compilation successful. Executable is in %BIN_DIR%\%EXE_NAME%

