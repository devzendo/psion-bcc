@echo off
goto X%1X
:Xv0X
:XoffX
set jpivid=v0
echo VID is now OFF
goto :end
:Xv2X
:XonX
set jpivid=v2
echo VID is now ON
goto :end
:XX
call checkvid
goto %jpivid%
:v0
echo VID is OFF
goto end
:v2
echo VID is ON
:end

