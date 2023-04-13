@echo off
call version
echo Making bcc source archive version %ver%
pause
cd ..
pkzip -urPex bccs%ver%.zip bcc\*.*
cd bcc
echo Please insert a ZIP disk, and press return
pause
echo Copying BCCS%VER%.ZIP to the ZIP disk...
copy ..\bccs%ver%.zip d:
