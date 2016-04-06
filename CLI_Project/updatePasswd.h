#pragma once

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// updatePassword 摘要
	/// </summary>
	public ref class updatePasswd : public System::Windows::Forms::Form
	{
	public:
		updatePasswd(UserTable *login)
		{
			thisLogin = login;
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~updatePasswd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::PictureBox^  setUseSysPScharPic;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  newPsBoxAgain;
	private: System::Windows::Forms::TextBox^  newPsBox;
	private: System::Windows::Forms::TextBox^  oldPsBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  subButton;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(updatePasswd::typeid));
			this->setUseSysPScharPic = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->newPsBoxAgain = (gcnew System::Windows::Forms::TextBox());
			this->newPsBox = (gcnew System::Windows::Forms::TextBox());
			this->oldPsBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->subButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->setUseSysPScharPic))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// setUseSysPScharPic
			// 
			this->setUseSysPScharPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"setUseSysPScharPic.Image")));
			this->setUseSysPScharPic->Location = System::Drawing::Point(319, 32);
			this->setUseSysPScharPic->Name = L"setUseSysPScharPic";
			this->setUseSysPScharPic->Size = System::Drawing::Size(23, 19);
			this->setUseSysPScharPic->TabIndex = 6;
			this->setUseSysPScharPic->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->setUseSysPScharPic);
			this->groupBox1->Controls->Add(this->newPsBoxAgain);
			this->groupBox1->Controls->Add(this->newPsBox);
			this->groupBox1->Controls->Add(this->oldPsBox);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"楷体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(127, 22);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(385, 169);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"输 入";
			// 
			// newPsBoxAgain
			// 
			this->newPsBoxAgain->Location = System::Drawing::Point(104, 112);
			this->newPsBoxAgain->Name = L"newPsBoxAgain";
			this->newPsBoxAgain->Size = System::Drawing::Size(207, 26);
			this->newPsBoxAgain->TabIndex = 5;
			this->newPsBoxAgain->UseSystemPasswordChar = true;
			// 
			// newPsBox
			// 
			this->newPsBox->Location = System::Drawing::Point(104, 71);
			this->newPsBox->Name = L"newPsBox";
			this->newPsBox->Size = System::Drawing::Size(208, 26);
			this->newPsBox->TabIndex = 4;
			this->newPsBox->UseSystemPasswordChar = true;
			// 
			// oldPsBox
			// 
			this->oldPsBox->Location = System::Drawing::Point(104, 28);
			this->oldPsBox->Name = L"oldPsBox";
			this->oldPsBox->Size = System::Drawing::Size(209, 26);
			this->oldPsBox->TabIndex = 3;
			this->oldPsBox->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"再次输入";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"新密码";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"原始密码";
			// 
			// subButton
			// 
			this->subButton->Font = (gcnew System::Drawing::Font(L"楷体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->subButton->Location = System::Drawing::Point(266, 197);
			this->subButton->Name = L"subButton";
			this->subButton->Size = System::Drawing::Size(78, 26);
			this->subButton->TabIndex = 3;
			this->subButton->Text = L"修 改";
			this->subButton->UseVisualStyleBackColor = true;
			this->subButton->Click += gcnew System::EventHandler(this, &updatePasswd::subButton_Click);
			// 
			// updatePasswd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(639, 244);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->subButton);
			this->Name = L"updatePasswd";
			this->Text = L"修改密码";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->setUseSysPScharPic))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void subButton_Click(System::Object^  sender, System::EventArgs^  e) {
		User *user = new User();
		char id[20];
		char oldPasswd[20];
		char newPasswd[20];
		sprintf(id, "%s", thisLogin->getId());
		sprintf(oldPasswd, "%s", this->oldPsBox->Text);
		sprintf(newPasswd, "%s", this->newPsBox->Text);
		if (this->newPsBox->Text != this->newPsBoxAgain->Text)
		{
			MessageBox::Show("确保两次密码输入一致！");
			return;
		}
		if (user->updatePasswd(thisLogin->getType(), id, oldPasswd, newPasswd)) //在updateInfo函数返回前name等数组空间是有效的
		{														//一般只要不在return的时候用局部地址就ok
			MessageBox::Show("修改成功，即将返回...");
			this->Close();
		}
		else { MessageBox::Show("请输入正确原密码！"); }
	}
};
}
