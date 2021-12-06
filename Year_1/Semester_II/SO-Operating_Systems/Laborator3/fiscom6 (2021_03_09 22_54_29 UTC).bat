:repeta
shift
if "%0" == "" goto :sfarsit
if exist %0 (
copy concatenari.txt+%0 concatenari.txt
) else (
echo "%0 nu exista"
)
goto :repeta
type concatenari.txt
:sfarsit