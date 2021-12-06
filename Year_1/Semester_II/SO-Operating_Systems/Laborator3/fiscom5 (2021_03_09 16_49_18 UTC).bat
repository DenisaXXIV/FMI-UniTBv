set var=%1
shift
:repeta
shift
if "%0"=="" goto :sfarsit
if exist %0 (
find "%var%" %0 >>cautari.txt
) else (
echo "%0 nu exista"
)
goto :repeta
:sfarsit