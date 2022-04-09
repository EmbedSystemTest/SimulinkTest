
set skipSetupArg=%1
if "%skipSetupArg%" NEQ "skip_setup_msvc" (
call "setup_msvc.bat"
)

cd .
nmake -f AbstractFuelControl_M1.mk  RSIM_SOLVER_SELECTION=1 PCMATLABROOT="C:\\AppInstall\\Matlab" EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 EXTMODE_TRANSPORT=0 TMW_EXTMODE_TESTING=0 RSIM_PARAMETER_LOADING=1 OPTS="-DRT -DRSIM_PARAMETER_LOADING -DTID01EQ=1"
@if errorlevel 1 goto error_exit
exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1