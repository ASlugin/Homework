@echo off

for /d %%i in (*) do (
    cd %%i
    for /d %%j in (*) do (
        cd %%j
        if exist *.sln (
            msbuild
            if exist x64 ( 
                cd x64
                for /r %%g in (*.exe) do %%g anyParametr
                if errorlevel 1 (
                    echo Program has not tests
                ) else if errorlevel 0 (
                    echo Tests of program passed
                ) else (
                    echo Tests of program not passed
                )
                cd ..
            )
        ) else (
            for /d %%h in (*) do (
                cd %%h
                if exist *.sln (
                    msbuild
                    if exist x64 ( 
                        cd x64
                        for /r %%g in (*.exe) do %%g anyParametr
                        if errorlevel 1 (
                            echo Program has not tests
                        ) else if errorlevel 0 (
                            echo Tests of program passed
                        ) else (
                            echo Tests of program not passed
                        )
                        cd ..
                    )
                )
                cd ..
            )
        )
        cd ..
    )
    cd ..
)