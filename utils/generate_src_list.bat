:: Title:        generate_src_list.bat
:: Description:  Generates a CMakeLists.txt file that contains the current list of 
::               source files located in the /src folder (adapted for windows cmd).
:: Author:       azarrias
:: Date:         20180612
:: Usage:        generate_src_list.bat
::================================================================================
@echo off

set V_PROJECT=tetris
set V_CMAKELISTS_PATH="../src/CMakeLists.txt"
for %%F in (%V_CMAKELISTS_PATH%) do set SRC_RELATIVE_PATH=%%~dpF

echo target_sources(%V_PROJECT% PRIVATE>%V_CMAKELISTS_PATH%
for /f %%G in ('dir /b /a-d /o:n %SRC_RELATIVE_PATH%\*.cpp %SRC_RELATIVE_PATH%\*.c %SRC_RELATIVE_PATH%\*.hpp %SRC_RELATIVE_PATH%\*.h %SRC_RELATIVE_PATH%\*.inl %SRC_RELATIVE_PATH%\*.inc') do echo    ${CMAKE_CURRENT_LIST_DIR}/%%~G>>%V_CMAKELISTS_PATH%
echo )>>%V_CMAKELISTS_PATH%
