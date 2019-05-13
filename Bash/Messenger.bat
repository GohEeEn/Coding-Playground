:: =============================================
:: Batch Script : Simple messenger by using cmd
:: =============================================

@echo off	
:: Turn off the command echoing



cls					
:: Clear the screen

title CMD Messenger
:: Program Name

set /p "name= USER	: "
:: Specifies the username, computer name or messaging name (defined with 'net name command') that you want to send the message to 

set /p "ip= IP	: "
:: echo %name% Joined the chat (%time%::%date%)

:A
:: A predefined label in the batch program, like a line pointer

set /p "msg=[%TIME:~0,8%] %name% >> "
:: Display the list of environment variables on the current system
:: Substring Extraction : %var:~id_start, id_end%

:: echo [%name%]: %msg%
:: msg * /server: %ip% /v /w %msg%

:: net send %ip%
:: %msg%
:: Provides various network services, depending on the command used
:: Come to a dead end : net send command not longer been used after window vista
:: Alternative command msg only available in pro edition

pause
:: Command that prompts the user and waits for a line of input to be entered
:: Display : Press anything to continue

goto A
:: Return to the given line pointer mes (like loop)