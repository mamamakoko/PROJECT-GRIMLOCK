<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class MainForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(MainForm))
        Me.Panel3 = New System.Windows.Forms.Panel()
        Me.timeEvent = New System.Windows.Forms.Label()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Timer2 = New System.Windows.Forms.Timer(Me.components)
        Me.StudentPanel = New System.Windows.Forms.Panel()
        Me.btnSettings = New System.Windows.Forms.Button()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.lblSection = New System.Windows.Forms.Label()
        Me.lblName = New System.Windows.Forms.Label()
        Me.Panel2 = New System.Windows.Forms.Panel()
        Me.lblStudentNumber = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.PictureBoxStudent = New System.Windows.Forms.PictureBox()
        Me.timeListView = New System.Windows.Forms.ListView()
        Me.timeIn = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.timeOut = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.Panel1 = New System.Windows.Forms.Panel()
        Me.Panel3.SuspendLayout()
        Me.StudentPanel.SuspendLayout()
        CType(Me.PictureBoxStudent, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Panel1.SuspendLayout()
        Me.SuspendLayout()
        '
        'Panel3
        '
        Me.Panel3.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Panel3.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.Panel3.BackColor = System.Drawing.Color.SlateGray
        Me.Panel3.Controls.Add(Me.timeEvent)
        Me.Panel3.Location = New System.Drawing.Point(435, 0)
        Me.Panel3.Name = "Panel3"
        Me.Panel3.Size = New System.Drawing.Size(494, 55)
        Me.Panel3.TabIndex = 2
        '
        'timeEvent
        '
        Me.timeEvent.Anchor = System.Windows.Forms.AnchorStyles.Right
        Me.timeEvent.AutoSize = True
        Me.timeEvent.BackColor = System.Drawing.Color.Transparent
        Me.timeEvent.Font = New System.Drawing.Font("Montserrat", 14.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.timeEvent.ForeColor = System.Drawing.Color.White
        Me.timeEvent.Location = New System.Drawing.Point(178, 14)
        Me.timeEvent.Name = "timeEvent"
        Me.timeEvent.Size = New System.Drawing.Size(307, 26)
        Me.timeEvent.TabIndex = 0
        Me.timeEvent.Text = "September 30, 2024  00:00:00"
        Me.timeEvent.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Timer1
        '
        Me.Timer1.Interval = 1000
        '
        'Timer2
        '
        '
        'StudentPanel
        '
        Me.StudentPanel.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.StudentPanel.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.StudentPanel.BackColor = System.Drawing.Color.Azure
        Me.StudentPanel.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center
        Me.StudentPanel.Controls.Add(Me.btnSettings)
        Me.StudentPanel.Controls.Add(Me.Label4)
        Me.StudentPanel.Controls.Add(Me.lblSection)
        Me.StudentPanel.Controls.Add(Me.lblName)
        Me.StudentPanel.Controls.Add(Me.Panel2)
        Me.StudentPanel.Controls.Add(Me.lblStudentNumber)
        Me.StudentPanel.Controls.Add(Me.Label2)
        Me.StudentPanel.Controls.Add(Me.Label1)
        Me.StudentPanel.Controls.Add(Me.PictureBoxStudent)
        Me.StudentPanel.Location = New System.Drawing.Point(0, 0)
        Me.StudentPanel.Name = "StudentPanel"
        Me.StudentPanel.Size = New System.Drawing.Size(434, 579)
        Me.StudentPanel.TabIndex = 0
        '
        'btnSettings
        '
        Me.btnSettings.Anchor = CType((System.Windows.Forms.AnchorStyles.Bottom Or System.Windows.Forms.AnchorStyles.Left), System.Windows.Forms.AnchorStyles)
        Me.btnSettings.BackColor = System.Drawing.Color.Transparent
        Me.btnSettings.FlatAppearance.BorderSize = 0
        Me.btnSettings.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.btnSettings.Image = Global.RFID_Arduino_User_Data_Interface.My.Resources.Resources.setting_24px_
        Me.btnSettings.Location = New System.Drawing.Point(0, 541)
        Me.btnSettings.Name = "btnSettings"
        Me.btnSettings.Size = New System.Drawing.Size(38, 38)
        Me.btnSettings.TabIndex = 14
        Me.btnSettings.UseVisualStyleBackColor = False
        '
        'Label4
        '
        Me.Label4.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Montserrat ExtraBold", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(47, 37)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(335, 29)
        Me.Label4.TabIndex = 13
        Me.Label4.Text = "Welcome to NAS Laboratory!"
        '
        'lblSection
        '
        Me.lblSection.AutoSize = True
        Me.lblSection.Font = New System.Drawing.Font("Montserrat", 12.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblSection.Location = New System.Drawing.Point(153, 503)
        Me.lblSection.Name = "lblSection"
        Me.lblSection.Size = New System.Drawing.Size(92, 24)
        Me.lblSection.TabIndex = 11
        Me.lblSection.Text = "Waiting..."
        Me.lblSection.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'lblName
        '
        Me.lblName.AutoSize = True
        Me.lblName.Font = New System.Drawing.Font("Montserrat", 12.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblName.Location = New System.Drawing.Point(153, 454)
        Me.lblName.Name = "lblName"
        Me.lblName.Size = New System.Drawing.Size(92, 24)
        Me.lblName.TabIndex = 10
        Me.lblName.Text = "Waiting..."
        Me.lblName.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Panel2
        '
        Me.Panel2.BackColor = System.Drawing.Color.CadetBlue
        Me.Panel2.Location = New System.Drawing.Point(443, 0)
        Me.Panel2.Name = "Panel2"
        Me.Panel2.Size = New System.Drawing.Size(486, 44)
        Me.Panel2.TabIndex = 9
        '
        'lblStudentNumber
        '
        Me.lblStudentNumber.AutoSize = True
        Me.lblStudentNumber.Font = New System.Drawing.Font("Montserrat", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.lblStudentNumber.Location = New System.Drawing.Point(155, 379)
        Me.lblStudentNumber.Name = "lblStudentNumber"
        Me.lblStudentNumber.Size = New System.Drawing.Size(121, 27)
        Me.lblStudentNumber.TabIndex = 4
        Me.lblStudentNumber.Text = "123456789"
        Me.lblStudentNumber.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Montserrat", 12.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(39, 503)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(91, 24)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Section  :"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Montserrat", 12.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(58, 454)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(72, 24)
        Me.Label1.TabIndex = 2
        Me.Label1.Text = "Name :"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'PictureBoxStudent
        '
        Me.PictureBoxStudent.BackColor = System.Drawing.Color.Transparent
        Me.PictureBoxStudent.Image = CType(resources.GetObject("PictureBoxStudent.Image"), System.Drawing.Image)
        Me.PictureBoxStudent.Location = New System.Drawing.Point(92, 113)
        Me.PictureBoxStudent.Name = "PictureBoxStudent"
        Me.PictureBoxStudent.Size = New System.Drawing.Size(250, 250)
        Me.PictureBoxStudent.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBoxStudent.TabIndex = 0
        Me.PictureBoxStudent.TabStop = False
        '
        'timeListView
        '
        Me.timeListView.Alignment = System.Windows.Forms.ListViewAlignment.SnapToGrid
        Me.timeListView.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.timeListView.BackColor = System.Drawing.SystemColors.ButtonFace
        Me.timeListView.Columns.AddRange(New System.Windows.Forms.ColumnHeader() {Me.timeIn, Me.timeOut})
        Me.timeListView.Font = New System.Drawing.Font("Montserrat", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.timeListView.GridLines = True
        Me.timeListView.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.Nonclickable
        Me.timeListView.HideSelection = False
        Me.timeListView.Location = New System.Drawing.Point(3, 11)
        Me.timeListView.Margin = New System.Windows.Forms.Padding(3, 5, 3, 5)
        Me.timeListView.MultiSelect = False
        Me.timeListView.Name = "timeListView"
        Me.timeListView.Scrollable = False
        Me.timeListView.ShowGroups = False
        Me.timeListView.Size = New System.Drawing.Size(498, 518)
        Me.timeListView.TabIndex = 0
        Me.timeListView.UseCompatibleStateImageBehavior = False
        Me.timeListView.View = System.Windows.Forms.View.Details
        '
        'timeIn
        '
        Me.timeIn.Text = "Time in"
        Me.timeIn.Width = 240
        '
        'timeOut
        '
        Me.timeOut.Text = "Time Out"
        Me.timeOut.Width = 240
        '
        'Panel1
        '
        Me.Panel1.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.Panel1.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.Panel1.BackColor = System.Drawing.Color.LightBlue
        Me.Panel1.Controls.Add(Me.timeListView)
        Me.Panel1.Location = New System.Drawing.Point(435, 50)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(501, 529)
        Me.Panel1.TabIndex = 1
        '
        'MainForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoSize = True
        Me.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.BackColor = System.Drawing.Color.White
        Me.ClientSize = New System.Drawing.Size(929, 578)
        Me.Controls.Add(Me.Panel3)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.StudentPanel)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "MainForm"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = " "
        Me.Panel3.ResumeLayout(False)
        Me.Panel3.PerformLayout()
        Me.StudentPanel.ResumeLayout(False)
        Me.StudentPanel.PerformLayout()
        CType(Me.PictureBoxStudent, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Panel1.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents StudentPanel As Panel
    Friend WithEvents PictureBoxStudent As PictureBox
    Friend WithEvents Label1 As Label
    Friend WithEvents lblStudentNumber As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Panel2 As Panel
    Friend WithEvents Panel3 As Panel
    Friend WithEvents timeEvent As Label
    Friend WithEvents lblSection As Label
    Friend WithEvents lblName As Label
    Friend WithEvents Timer1 As Timer
    Friend WithEvents Timer2 As Timer
    Friend WithEvents Label4 As Label
    Friend WithEvents btnSettings As Button
    Friend WithEvents timeListView As ListView
    Friend WithEvents timeIn As ColumnHeader
    Friend WithEvents timeOut As ColumnHeader
    Friend WithEvents Panel1 As Panel
End Class
