@echo off
:: 显示欢迎信息
echo Welcome to the Personal Diary Application
echo ------------------------------------------
echo Please choose an option:
echo 1. Add a new diary entry
echo 2. List diary entries by date range
echo 3. Show a diary entry by date
echo 4. Remove a diary entry
echo 5. Exit
echo ------------------------------------------

:: 用户选择操作
set /p option="Enter your choice (1-5): "

:: 根据用户输入的选项执行相应的程序
if "%option%"=="1" (
    echo You chose to add a new diary entry.
    pdadd.exe
) else if "%option%"=="2" (
    echo You chose to list diary entries by date range.
    pdlist.exe
) else if "%option%"=="3" (
    echo You chose to show a diary entry by date.
    pdshow.exe
) else if "%option%"=="4" (
    echo You chose to remove a diary entry.
    pdremove.exe
) else if "%option%"=="5" (
    echo Exiting the program. Goodbye!
    exit
) else (
    echo Invalid option, please try again.
)

:: 返回主菜单
pause
diary.bat
