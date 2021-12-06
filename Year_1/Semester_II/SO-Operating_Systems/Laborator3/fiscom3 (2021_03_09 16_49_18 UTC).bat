:repeta
shift
if "%0"=="" goto :sfarsit
if exist %0 (
del %0
) else (
echo "Fisier inexistent"
)
goto :repeta
:sfarsit