@echo off
title IP Configuration Info
color 0A

echo ========================================
echo        IP CONFIGURATION DETAILS
echo ========================================
echo.

echo [1] BASIC IP CONFIG:
echo ----------------------------------------
ipconfig
echo.

echo [2] DETAILED IP CONFIG:
echo ----------------------------------------
ipconfig /all
echo.

echo [3] DNS CACHE:
echo ----------------------------------------
ipconfig /displaydns
echo.

echo ========================================
echo Done!
pause
