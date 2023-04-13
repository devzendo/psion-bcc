@echo off
call version
echo Making Psistack release version %ver%
pause
cd gui
call clean
cd ..\kernel
call clean
cd ..\socket
call clean
cd ..\stackif
call clean
cd ..\..
rem Now in "My Documents" - all archive files are created there
pkzip -urPex -xpsistack\help\*.* -xpsistack\gui\procomm.* -xpsistack\docmast\*.* src%ver%.zip psistack\*.*
cd psistack\docmast
pkzip -uex ..\..\doca4%ver%.zip ownera4.ps techa4.ps ..\doc\*.txt 
pkzip -uex ..\..\docle%ver%.zip ownerle.ps techle.ps ..\doc\*.txt
pkzip -urPex ..\..\docht%ver%.zip ownerht\*.* techht\*.* ..\doc\*.txt
cd ..\gui
pkzip -urPex ..\..\bin%ver%.zip psistack.app psilogvu.als psiscred.als 3a.bat siena.bat wrka.bat emul.bat 
pkzip -urPex ..\..\bin%ver%.zip ..\doc\*.txt
pkzip -urPex ..\..\bin%ver%.zip ..\win95\*.* ..\linux\*.* ..\os2\*.* ..\mac\*.*
cd ..\..
echo Please insert a Zip disk, and press return
pause
echo Copying SRC%VER%.ZIP to the disk...
copy src%ver%.zip d:
echo Copying DOCA4%VER%.ZIP to the disk...
copy doca4%ver%.zip d:
echo Copying DOCLE%VER%.ZIP to the disk...
copy docle%ver%.zip d:
echo Copying DOCHT%VER%.ZIP to the disk...
copy docht%ver%.zip d:
echo Copying BIN%VER%.ZIP to the disk...
copy bin%ver%.zip d:
cd psistack

