dim a
dim b
dim c
a=0
b=0
c=0
while a=0 or b=0 or c=0
	x=msgbox("Windows 10 已經停止運作，立即中止?", 2+48, "Micorsoft Windows")
if x = 3 Then
	y=msgbox ("與你相處的這段時間我過得很快樂。",0+16,"警告，電腦即將自我銷毀")
	WScript.Sleep 300
	a=1
End If
	if x = 4 Then
	z=msgbox ("它似乎不想讓你找到",0+16,"偵測到一個未知的bug")
	WScript.Sleep 300
	b=1
End If
if x = 5 Then		
	dim count
	do
	z=msgbox ("再忽略我啊!",0+16,"Bang!")
	count = count + 1
	loop until count = 8
	c=1
	WScript.Sleep 300
End If
Wend
WScript.Sleep 500