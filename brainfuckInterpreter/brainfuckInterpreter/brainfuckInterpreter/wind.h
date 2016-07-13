#pragma once

namespace brainfuckInterpreter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// wind 摘要
	/// </summary>
	public ref class wind : public System::Windows::Forms::Form
	{
	public:

		
		wind(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//

		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~wind()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  filenameBox;
	private: System::Windows::Forms::Button^  runButton;
	protected:


	private: System::Windows::Forms::CheckBox^  memfChkBox;

	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(wind::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->filenameBox = (gcnew System::Windows::Forms::TextBox());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->memfChkBox = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Location = System::Drawing::Point(12, 21);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(3);
			this->label1->Size = System::Drawing::Size(97, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"请输入文件名：";
			this->label1->Click += gcnew System::EventHandler(this, &wind::label1_Click);
			// 
			// filenameBox
			// 
			this->filenameBox->Location = System::Drawing::Point(115, 20);
			this->filenameBox->Name = L"filenameBox";
			this->filenameBox->Size = System::Drawing::Size(239, 21);
			this->filenameBox->TabIndex = 1;
			this->filenameBox->Text = L"123.txt";
			this->filenameBox->TextChanged += gcnew System::EventHandler(this, &wind::textBox1_TextChanged);
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(360, 20);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(75, 23);
			this->runButton->TabIndex = 2;
			this->runButton->Text = L"执行";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &wind::button1_Click);
			// 
			// memfChkBox
			// 
			this->memfChkBox->AutoSize = true;
			this->memfChkBox->Location = System::Drawing::Point(471, 21);
			this->memfChkBox->Name = L"memfChkBox";
			this->memfChkBox->Padding = System::Windows::Forms::Padding(3);
			this->memfChkBox->Size = System::Drawing::Size(78, 22);
			this->memfChkBox->TabIndex = 3;
			this->memfChkBox->Text = L"内存跟踪";
			this->memfChkBox->UseVisualStyleBackColor = true;
			this->memfChkBox->CheckedChanged += gcnew System::EventHandler(this, &wind::checkBox1_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"华文新魏", 10.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->ForeColor = System::Drawing::Color::Gray;
			this->label2->Location = System::Drawing::Point(471, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 14);
			this->label2->TabIndex = 4;
			this->label2->Text = L"via 留白君";
			this->label2->Click += gcnew System::EventHandler(this, &wind::label2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->ImageLocation = L"bg.bmp";
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(-3, -4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(564, 87);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &wind::pictureBox1_Click);
			// 
			// wind
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 80);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->memfChkBox);
			this->Controls->Add(this->runButton);
			this->Controls->Add(this->filenameBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"wind";
			this->Text = L"Brainfuck语言解释器";
			this->Load += gcnew System::EventHandler(this, &wind::wind_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void wind_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	system("cls");


	String^ tool = "bfinter ";
	String^ file = filenameBox->Text;
	String^ prtmem = " /p";

	String^ cmd = tool + file;
	if (memfChkBox->Checked)cmd = cmd + prtmem;

	char* cmdline = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cmd);

	system(cmdline);


}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
