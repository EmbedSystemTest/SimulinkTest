@if not "%MINGW_ROOT%" == "" (@set "PATH=%PATH%;%MINGW_ROOT%")

cd .

if "%1"=="" ("F:\Polyspace\R2020a\bin\win64\gmake"  -f EB_12B.mk all) else ("F:\Polyspace\R2020a\bin\win64\gmake"  -f EB_12B.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
