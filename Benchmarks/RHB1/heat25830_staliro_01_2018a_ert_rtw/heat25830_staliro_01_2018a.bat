
call "setup_msvc.bat"

cd .

if "%1"=="" (nmake  -f heat25830_staliro_01_2018a.mk all) else (nmake  -f heat25830_staliro_01_2018a.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1