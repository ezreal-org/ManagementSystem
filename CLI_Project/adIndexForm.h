#pragma once
#include "addStu.h"
#include "stuList.h"
#include "addMajor.h"
#include "allMajor.h"
#include "updatePasswd.h"
#include "allCourseArrangement.h"
#include "addNewCourse.h"
#include "allCourse.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// adIndexForm 晡猁
	/// </summary>
	public ref class adIndexForm : public System::Windows::Forms::Form
	{
	public:
		adIndexForm(UserTable* login)
		{
			this->thisLogin = login;
			InitializeComponent();
			//
			//TODO:  婓森揭氝樓凳婖滲杅測鎢
			//
		}

	protected:
		/// <summary>
		/// ?燴垀衄淏婓妏蚚腔訧埭﹝
		/// </summary>
		~adIndexForm()
		{
			if (components)
			{
			//	delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::Label^  welLabel;
	private: System::Windows::Forms::Button^  addStuButton;
	private: System::Windows::Forms::Button^  allStuButton;
	private: System::Windows::Forms::Button^  allCourseButton;



	private: System::Windows::Forms::Button^  addMajorButton;
	private: System::Windows::Forms::Button^  resetPSButton;
	private: System::Windows::Forms::Button^  allMajorButton;
	private: System::Windows::Forms::Button^  selfInfoButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Button^  msgResponseButton;
	private: System::Windows::Forms::Button^  aboutSysButton;
	private: System::Windows::Forms::Button^  courseArrangementButton;
	private: System::Windows::Forms::Button^  addCourseButton;








	private:
		/// <summary>
		/// 斛剒腔扢數?曹講﹝
		/// </summary>
		System::ComponentModel::Container ^components;


		//暮翹絞?腔蚚誧
	public:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 扢數?盓厥垀剒腔源楊 - 祥猁党蜊
		/// 妏蚚測鎢晤憮?党蜊森源楊腔囀?﹝
		/// </summary>
		void InitializeComponent(void)
		{
			this->welLabel = (gcnew System::Windows::Forms::Label());
			this->addStuButton = (gcnew System::Windows::Forms::Button());
			this->allStuButton = (gcnew System::Windows::Forms::Button());
			this->allCourseButton = (gcnew System::Windows::Forms::Button());
			this->addMajorButton = (gcnew System::Windows::Forms::Button());
			this->resetPSButton = (gcnew System::Windows::Forms::Button());
			this->allMajorButton = (gcnew System::Windows::Forms::Button());
			this->selfInfoButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->msgResponseButton = (gcnew System::Windows::Forms::Button());
			this->aboutSysButton = (gcnew System::Windows::Forms::Button());
			this->courseArrangementButton = (gcnew System::Windows::Forms::Button());
			this->addCourseButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// welLabel
			// 
			this->welLabel->AutoSize = true;
			this->welLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->welLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->welLabel->Location = System::Drawing::Point(44, 26);
			this->welLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->welLabel->Name = L"welLabel";
			this->welLabel->Size = System::Drawing::Size(96, 44);
			this->welLabel->TabIndex = 0;
			this->welLabel->Text = L"欢迎";
			// 
			// addStuButton
			// 
			this->addStuButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->addStuButton->Location = System::Drawing::Point(52, 136);
			this->addStuButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->addStuButton->Name = L"addStuButton";
			this->addStuButton->Size = System::Drawing::Size(284, 72);
			this->addStuButton->TabIndex = 1;
			this->addStuButton->Text = L"添加学生";
			this->addStuButton->UseVisualStyleBackColor = true;
			this->addStuButton->Click += gcnew System::EventHandler(this, &adIndexForm::button1_Click);
			// 
			// allStuButton
			// 
			this->allStuButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->allStuButton->Location = System::Drawing::Point(398, 138);
			this->allStuButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->allStuButton->Name = L"allStuButton";
			this->allStuButton->Size = System::Drawing::Size(284, 70);
			this->allStuButton->TabIndex = 2;
			this->allStuButton->Text = L"所有学生";
			this->allStuButton->UseVisualStyleBackColor = true;
			this->allStuButton->Click += gcnew System::EventHandler(this, &adIndexForm::button2_Click);
			// 
			// allCourseButton
			// 
			this->allCourseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->allCourseButton->Location = System::Drawing::Point(52, 290);
			this->allCourseButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->allCourseButton->Name = L"allCourseButton";
			this->allCourseButton->Size = System::Drawing::Size(284, 72);
			this->allCourseButton->TabIndex = 4;
			this->allCourseButton->Text = L"所有课程";
			this->allCourseButton->UseVisualStyleBackColor = true;
			this->allCourseButton->Click += gcnew System::EventHandler(this, &adIndexForm::allCourseButton_Click);
			// 
			// addMajorButton
			// 
			this->addMajorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->addMajorButton->Location = System::Drawing::Point(764, 138);
			this->addMajorButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->addMajorButton->Name = L"addMajorButton";
			this->addMajorButton->Size = System::Drawing::Size(284, 72);
			this->addMajorButton->TabIndex = 5;
			this->addMajorButton->Text = L"新增专业";
			this->addMajorButton->UseVisualStyleBackColor = true;
			this->addMajorButton->Click += gcnew System::EventHandler(this, &adIndexForm::addMajorButton_Click);
			// 
			// resetPSButton
			// 
			this->resetPSButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->resetPSButton->Location = System::Drawing::Point(398, 290);
			this->resetPSButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->resetPSButton->Name = L"resetPSButton";
			this->resetPSButton->Size = System::Drawing::Size(284, 72);
			this->resetPSButton->TabIndex = 6;
			this->resetPSButton->Text = L"密码修改";
			this->resetPSButton->UseVisualStyleBackColor = true;
			this->resetPSButton->Click += gcnew System::EventHandler(this, &adIndexForm::resetPSButton_Click);
			// 
			// allMajorButton
			// 
			this->allMajorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->allMajorButton->Location = System::Drawing::Point(1112, 138);
			this->allMajorButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->allMajorButton->Name = L"allMajorButton";
			this->allMajorButton->Size = System::Drawing::Size(284, 72);
			this->allMajorButton->TabIndex = 7;
			this->allMajorButton->Text = L"所有专业";
			this->allMajorButton->UseVisualStyleBackColor = true;
			this->allMajorButton->Click += gcnew System::EventHandler(this, &adIndexForm::allMajorButton_Click);
			// 
			// selfInfoButton
			// 
			this->selfInfoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->selfInfoButton->Location = System::Drawing::Point(764, 290);
			this->selfInfoButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->selfInfoButton->Name = L"selfInfoButton";
			this->selfInfoButton->Size = System::Drawing::Size(284, 72);
			this->selfInfoButton->TabIndex = 8;
			this->selfInfoButton->Text = L"个人信息";
			this->selfInfoButton->UseVisualStyleBackColor = true;
			this->selfInfoButton->Click += gcnew System::EventHandler(this, &adIndexForm::selfInfoButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->exitButton->Location = System::Drawing::Point(1112, 430);
			this->exitButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(284, 72);
			this->exitButton->TabIndex = 9;
			this->exitButton->Text = L"注  销";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &adIndexForm::exitButton_Click);
			// 
			// msgResponseButton
			// 
			this->msgResponseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->msgResponseButton->Location = System::Drawing::Point(1112, 290);
			this->msgResponseButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->msgResponseButton->Name = L"msgResponseButton";
			this->msgResponseButton->Size = System::Drawing::Size(284, 72);
			this->msgResponseButton->TabIndex = 10;
			this->msgResponseButton->Text = L"信息反馈处理";
			this->msgResponseButton->UseVisualStyleBackColor = true;
			this->msgResponseButton->Click += gcnew System::EventHandler(this, &adIndexForm::msgResponseButton_Click);
			// 
			// aboutSysButton
			// 
			this->aboutSysButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->aboutSysButton->Location = System::Drawing::Point(764, 430);
			this->aboutSysButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->aboutSysButton->Name = L"aboutSysButton";
			this->aboutSysButton->Size = System::Drawing::Size(284, 72);
			this->aboutSysButton->TabIndex = 11;
			this->aboutSysButton->Text = L"关于系统";
			this->aboutSysButton->UseVisualStyleBackColor = true;
			this->aboutSysButton->Click += gcnew System::EventHandler(this, &adIndexForm::aboutSysButton_Click);
			// 
			// courseArrangementButton
			// 
			this->courseArrangementButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->courseArrangementButton->Location = System::Drawing::Point(398, 430);
			this->courseArrangementButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->courseArrangementButton->Name = L"courseArrangementButton";
			this->courseArrangementButton->Size = System::Drawing::Size(284, 72);
			this->courseArrangementButton->TabIndex = 12;
			this->courseArrangementButton->Text = L"排课";
			this->courseArrangementButton->UseVisualStyleBackColor = true;
			this->courseArrangementButton->Click += gcnew System::EventHandler(this, &adIndexForm::courseArrangementButton_Click);
			// 
			// addCourseButton
			// 
			this->addCourseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->addCourseButton->Location = System::Drawing::Point(52, 430);
			this->addCourseButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->addCourseButton->Name = L"addCourseButton";
			this->addCourseButton->Size = System::Drawing::Size(284, 72);
			this->addCourseButton->TabIndex = 12;
			this->addCourseButton->Text = L"添加课程";
			this->addCourseButton->UseVisualStyleBackColor = true;
			this->addCourseButton->Click += gcnew System::EventHandler(this, &adIndexForm::addCourseButton_Click);
			// 
			// adIndexForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1464, 586);
			this->Controls->Add(this->addCourseButton);
			this->Controls->Add(this->courseArrangementButton);
			this->Controls->Add(this->aboutSysButton);
			this->Controls->Add(this->msgResponseButton);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->selfInfoButton);
			this->Controls->Add(this->allMajorButton);
			this->Controls->Add(this->resetPSButton);
			this->Controls->Add(this->addMajorButton);
			this->Controls->Add(this->allCourseButton);
			this->Controls->Add(this->allStuButton);
			this->Controls->Add(this->addStuButton);
			this->Controls->Add(this->welLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"adIndexForm";
			this->ShowIcon = false;
			this->Text = L"简易教务管理系统 - 教务员端";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &adIndexForm::adIndexForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &adIndexForm::adIndexForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Application::OpenForms["addStu"] == nullptr) {
			addStu ^adone = gcnew addStu();
			adone->Show();
		}
		else {
			Application::OpenForms["addStu"]->Show(); 
		}
	}
	private: System::Void adIndexForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		Application::OpenForms["loginForm1"]->Close();

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		if (Application::OpenForms["stuList"] == nullptr) {
			stuList ^showList = gcnew stuList();
			showList->Show();
		}
		else {
			//窗体已经存在， 应该把它显示出来，而不是从新定义一个
			Application::OpenForms["stuList"]->Show();

		}
	}
	
private: System::Void adIndexForm_Load(System::Object^  sender, System::EventArgs^  e) {
	string str = thisLogin->getId();
	this->welLabel->Text = "欢迎 "+ gcnew String(str.c_str());
}
private: System::Void addMajorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	addMajor ^addM= gcnew addMajor();
	addM->Show();
}
private: System::Void allMajorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	allMajor ^ allM = gcnew allMajor();
	allM->Show();
}
private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::OpenForms["loginForm1"]->Show();
	this->Hide();
}
private: System::Void resetPSButton_Click(System::Object^  sender, System::EventArgs^  e) {
	updatePasswd ^update = gcnew updatePasswd(thisLogin);
	update->Show();
}
private: System::Void selfInfoButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("本模块将在后续章节实现");
		 }
		 //5-9
private: System::Void courseArrangementButton_Click(System::Object^  sender, System::EventArgs^  e) {
	allCourseArrangement ^courseArrange = gcnew allCourseArrangement(0);
	courseArrange->Show();
}
private: System::Void addCourseButton_Click(System::Object^  sender, System::EventArgs^  e) {
	addNewCourse ^addCourse = gcnew addNewCourse();
	addCourse->Show();
}
private: System::Void msgResponseButton_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("本模块将在后续章节实现");
		 }
private: System::Void aboutSysButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 MessageBox::Show("本模块将在后续章节实现");
		 }
private: System::Void allCourseButton_Click(System::Object^  sender, System::EventArgs^  e) {
	allCourse ^ac = gcnew allCourse();
	ac->Show();
	}
};
}
