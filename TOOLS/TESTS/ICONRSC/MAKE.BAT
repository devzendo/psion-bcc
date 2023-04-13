@echo off
call checkvid
if exist %1.pr goto custom
tsc /m unnamed.pr /smain=%1 /%jpivid%
goto end
:custom
tsc /m %1.pr /smain=%1 /%jpivid%
:end
