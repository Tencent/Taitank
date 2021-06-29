:: Reset errorlevel status so we are not inheriting this state from the calling process:
@call :CLEAN_EXIT
@echo off

pushd %~dp0
set PROJECT_BUILD_DIR=%CD%
popd
SET PROJECT_BUILD_DIR=%PROJECT_BUILD_DIR:\=/%
SET PROJECT_ROOT_DIR=%PROJECT_BUILD_DIR%/..
SET PROJECT_CMAKE_MODULES_PATH=%PROJECT_BUILD_DIR%/modules
@REM SET PATH=%PATH%;you cmake path

:ADDITIONAL_PARAMS_MISSING
pushd %~dp0
python.exe "%PROJECT_BUILD_DIR%/buildtools/cmake_generate_project.py" %1
popd
if %ERRORLEVEL% neq 0 (
    set /p DUMMY=Hit ENTER to continue...
    exit /b %errorlevel%
) else (
    goto CLEAN_EXIT
)

:CLEAN_EXIT
exit /b 0