@echo off

msbuild
if exist x64 (
    for /r %%g in (*.exe) do %%g
    if errorlevel 0 (
        dot -Tpng -o GraphPicture.png graph.dot
        if exist GraphPicture.png (
            GraphPicture.png
            echo Successfully
        ) else ( echo Error: don't exist GraphPicture)
    ) else if errorlevel -1 (
        echo Error: returned -1      
    )
) else ( echo Error: don't exist folder x64)