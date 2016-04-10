#pragma once
#include "adIndexForm.h" //引入管理员以及学院端的首页窗体文件
#include "teaIndexForm.h"
#include "stuIndexForm.h"
#include "memberService.h"
#include "staffManagement.h"
#include "typeDefinition.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// LoginForm 摘要
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Panel^  loginPanel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  stuRadio;
	private: System::Windows::Forms::RadioButton^  adRadio;
	private: System::Windows::Forms::TextBox^  psTbox;
	private: System::Windows::Forms::TextBox^  accTbox;
	private: System::Windows::Forms::Label^  psLabel;

	private: System::Windows::Forms::Label^  accLabel;
	private: System::Windows::Forms::Button^  loginButton;


	private: System::Windows::Forms::LinkLabel^  supLink;
	private: System::Windows::Forms::RadioButton^  teaRadio;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->loginPanel = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->teaRadio = (gcnew System::Windows::Forms::RadioButton());
			this->stuRadio = (gcnew System::Windows::Forms::RadioButton());
			this->adRadio = (gcnew System::Windows::Forms::RadioButton());
			this->psTbox = (gcnew System::Windows::Forms::TextBox());
			this->accTbox = (gcnew System::Windows::Forms::TextBox());
			this->psLabel = (gcnew System::Windows::Forms::Label());
			this->accLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->supLink = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->loginPanel->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(293, 293);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// loginPanel
			// 
			this->loginPanel->Controls->Add(this->groupBox1);
			this->loginPanel->Controls->Add(this->label1);
			this->loginPanel->Location = System::Drawing::Point(336, 12);
			this->loginPanel->Name = L"loginPanel";
			this->loginPanel->Size = System::Drawing::Size(322, 219);
			this->loginPanel->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->teaRadio);
			this->groupBox1->Controls->Add(this->stuRadio);
			this->groupBox1->Controls->Add(this->adRadio);
			this->groupBox1->Controls->Add(this->psTbox);
			this->groupBox1->Controls->Add(this->accTbox);
			this->groupBox1->Controls->Add(this->psLabel);
			this->groupBox1->Controls->Add(this->accLabel);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"楷体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->groupBox1->Location = System::Drawing::Point(29, 46);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(273, 169);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"请登录";
			// 
			// teaRadio
			// 
			this->teaRadio->AutoSize = true;
			this->teaRadio->Location = System::Drawing::Point(114, 127);
			this->teaRadio->Name = L"teaRadio";
			this->teaRadio->Size = System::Drawing::Size(67, 23);
			this->teaRadio->TabIndex = 6;
			this->teaRadio->TabStop = true;
			this->teaRadio->Text = L"教师";
			this->teaRadio->UseVisualStyleBackColor = true;
			// 
			// stuRadio
			// 
			this->stuRadio->AutoSize = true;
			this->stuRadio->Location = System::Drawing::Point(187, 127);
			this->stuRadio->Name = L"stuRadio";
			this->stuRadio->Size = System::Drawing::Size(67, 23);
			this->stuRadio->TabIndex = 5;
			this->stuRadio->TabStop = true;
			this->stuRadio->Text = L"学生";
			this->stuRadio->UseVisualStyleBackColor = true;
			// 
			// adRadio
			// 
			this->adRadio->AutoSize = true;
			this->adRadio->Location = System::Drawing::Point(17, 127);
			this->adRadio->Name = L"adRadio";
			this->adRadio->Size = System::Drawing::Size(87, 23);
			this->adRadio->TabIndex = 4;
			this->adRadio->TabStop = true;
			this->adRadio->Text = L"教务员";
			this->adRadio->UseVisualStyleBackColor = true;
			// 
			// psTbox
			// 
			this->psTbox->Location = System::Drawing::Point(72, 86);
			this->psTbox->Name = L"psTbox";
			this->psTbox->Size = System::Drawing::Size(182, 29);
			this->psTbox->TabIndex = 3;
			this->psTbox->UseSystemPasswordChar = true;
			// 
			// accTbox
			// 
			this->accTbox->Location = System::Drawing::Point(72, 40);
			this->accTbox->Name = L"accTbox";
			this->accTbox->Size = System::Drawing::Size(182, 29);
			this->accTbox->TabIndex = 2;
			// 
			// psLabel
			// 
			this->psLabel->AutoSize = true;
			this->psLabel->Location = System::Drawing::Point(6, 89);
			this->psLabel->Name = L"psLabel";
			this->psLabel->Size = System::Drawing::Size(59, 19);
			this->psLabel->TabIndex = 1;
			this->psLabel->Text = L"密 码";
			// 
			// accLabel
			// 
			this->accLabel->AutoSize = true;
			this->accLabel->Location = System::Drawing::Point(7, 43);
			this->accLabel->Name = L"accLabel";
			this->accLabel->Size = System::Drawing::Size(59, 19);
			this->accLabel->TabIndex = 0;
			this->accLabel->Text = L"账 号";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"楷体", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::Color::Gray;
			this->label1->Location = System::Drawing::Point(25, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"欢迎使用本系统";
			// 
			// loginButton
			// 
			this->loginButton->Font = (gcnew System::Drawing::Font(L"楷体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->loginButton->Location = System::Drawing::Point(382, 237);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(237, 41);
			this->loginButton->TabIndex = 2;
			this->loginButton->Text = L"登  录";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &LoginForm::loginButton_Click);
			// 
			// supLink
			// 
			this->supLink->ActiveLinkColor = System::Drawing::Color::Black;
			this->supLink->AutoSize = true;
			this->supLink->LinkBehavior = System::Windows::Forms::LinkBehavior::NeverUnderline;
			this->supLink->LinkColor = System::Drawing::Color::Black;
			this->supLink->Location = System::Drawing::Point(263, 300);
			this->supLink->Name = L"supLink";
			this->supLink->Size = System::Drawing::Size(137, 12);
			this->supLink->TabIndex = 3;
			this->supLink->TabStop = true;
			this->supLink->Text = L"技术支持: 华南理工大学";
			this->supLink->VisitedLinkColor = System::Drawing::Color::Black;
			this->supLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::supLink_LinkClicked);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 317);
			this->Controls->Add(this->supLink);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->loginPanel);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->ShowIcon = false;
			this->Text = L"简易教务管理系统";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->loginPanel->ResumeLayout(false);
			this->loginPanel->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//验证用户的登录信息
		String ^accStr = accTbox->Text;
		String  ^psStr = psTbox->Text;
		char id[20], passwd[20];
		sprintf(id, "%s", accStr);
		sprintf(passwd, "%s", psStr);
		if (adRadio->Checked) {
			AcademicStaff *staff = new AcademicStaff();
			thisLogin = staff->login(id, passwd, LoginUserType::LOGIN_ACADEMICSTAFF);
			if (thisLogin != nullptr) {
				//生成新窗口
				adIndexForm ^ ad = gcnew adIndexForm(thisLogin);
				this->Visible = false;
				ad->Show();
			}
			else {
				MessageBox::Show("账户名或者密码错误");
			}
		}
		else if (teaRadio->Checked) {
			Teacher *teacher = new Teacher();
			thisLogin = teacher->login(id, passwd, LoginUserType::LOGIN_TEACHER);
			if (thisLogin != nullptr){
				teaIndexForm ^tea = gcnew teaIndexForm(thisLogin);
				this->Hide();
				tea->Show();
			}
			else{
				MessageBox::Show("账账户名或者密码错误");
			}
		}
		else if (stuRadio->Checked) { //处理学生端登陆
			Student *stu = new Student();
			thisLogin = stu->login(id, passwd,LoginUserType::LOGIN_STUDENT); //登录界面没有区分研究生本科生,type未知(-1)
			if (thisLogin != nullptr){
				stuIndexForm ^stu = gcnew stuIndexForm(thisLogin);
				this->Hide();
				stu->Show();
			}
			else{
				MessageBox::Show("账户名或者密码错误");
			}
		}
		else{
			//校验系统管理员账户信息
			Admin *admin = new Admin();
			thisLogin = admin->login(id, passwd, LoginUserType::LOGIN_ADMIN);
			if (thisLogin != nullptr){
				staffManagement ^sM = gcnew staffManagement();
				sM->Show();
				this->Hide();
			}
			else{
				MessageBox::Show("账户名或者密码错误");
			}
		}
	}
	private: System::Void supLink_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		try {
			Diagnostics::Process::Start("http://202.38.194.240:8000/cs/szdw/js/xn/17bvfdd0eicq1.xhtml");
		}
		catch (Win32Exception ^) {
			MessageBox::Show("Win32Exception");
		}
	}
};
}
