dim a
dim b
dim c
a=0
b=0
c=0
while a=0 or b=0 or c=0
	x=msgbox("Windows 10 �w�g����B�@�A�ߧY����?", 2+48, "Micorsoft Windows")
if x = 3 Then
	y=msgbox ("�P�A�۳B���o�q�ɶ��ڹL�o�ܧּ֡C",0+16,"ĵ�i�A�q���Y�N�ۧھP��")
	WScript.Sleep 300
	a=1
End If
	if x = 4 Then
	z=msgbox ("�����G���Q���A���",0+16,"������@�ӥ�����bug")
	WScript.Sleep 300
	b=1
End If
if x = 5 Then		
	dim count
	do
	z=msgbox ("�A�����ڰ�!",0+16,"Bang!")
	count = count + 1
	loop until count = 8
	c=1
	WScript.Sleep 300
End If
Wend
WScript.Sleep 500