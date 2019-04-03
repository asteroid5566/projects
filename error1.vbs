dim count
set object = wscript.CreateObject("wscript.shell")

do
object.run "error2.vbs"
count = count + 1
loop until count = 20
