Dim WshShell

Set WshShell = WScript.CreateObject("WScript.Shell")

WshShell.Run "cmd /c "+WScript.Arguments.Item(1)+"\..\..\script\links\KEIL\s9070_build.bat "+WScript.Arguments.Item(0)+" "+WScript.Arguments.Item(1), 0
