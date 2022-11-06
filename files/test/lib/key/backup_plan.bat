echo off
color 0A

set MODULE_NAME=mykey
set NAME_MY=lib%MODULE_NAME%.a
set HEADER=-I"..\..\include"

set FILENAME=get
echo "gcc -c %FILENAME%.c %HEADER%"
gcc -c "%FILENAME%.c" %HEADER%
set OBJ="%FILENAME%.o"

set FILENAME=display
echo "gcc -c  %FILENAME%.c %HEADER%"
gcc -c "%FILENAME%.c" %HEADER%
set OBJ=%OBJ% "%FILENAME%.o"

set FILENAME=initialise
echo "gcc -c  %FILENAME%.c %HEADER%"
gcc -c "%FILENAME%.c" %HEADER%
set OBJ=%OBJ% "%FILENAME%.o"

echo "ar rc %NAME_MY% %OBJ%"
ar rc %NAME_MY% %OBJ%
echo "Done for %MODULE_NAME%"