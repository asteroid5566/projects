[void][reflection.assembly]::LoadWithPartialName(
"System.Windows.Forms")
$form = new-object Windows.Forms.Form
$form.Text = "powershell²�����"
$Text = New-Object Windows.Forms.RichTextBox
$Text.text = "

               Hello World!"
$Text.Dock = "fill"
$form.controls.add($Text)
$form.ShowDialog()