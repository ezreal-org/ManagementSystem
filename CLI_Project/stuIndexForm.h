#pragma once
#include "selectCourse.h"
#include "courseSelected.h"
#include "updatePasswd.h"
#include "stuInfo.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// stuIndexForm 摘要
	/// </summary>
	public ref class stuIndexForm : public System::Windows::Forms::Form
	{
	public:
		stuIndexForm(UserTable *login)
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
		~stuIndexForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(39, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"查询成绩";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &stuIndexForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(193, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 30);
			this->button2->TabIndex = 1;
			this->button2->Text = L"新增选课";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &stuIndexForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(347, 39);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(124, 30);
			this->button3->TabIndex = 2;
			this->button3->Text = L"查询选课";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &stuIndexForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(507, 39);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(124, 30);
			this->button4->TabIndex = 3;
			this->button4->Text = L"个人信息查询";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &stuIndexForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(39, 107);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(124, 30);
			this->button5->TabIndex = 4;
			this->button5->Text = L"修改密码";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &stuIndexForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(507, 107);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(124, 30);
			this->button6->TabIndex = 5;
			this->button6->Text = L"注  销";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &stuIndexForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(193, 107);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(124, 30);
			this->button7->TabIndex = 6;
			this->button7->Text = L"反馈信息";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &stuIndexForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(347, 107);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(124, 30);
			this->button8->TabIndex = 7;
			this->button8->Text = L"关于系统";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &stuIndexForm::button8_Click);
			// 
			// stuIndexForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 180);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"stuIndexForm";
			this->Text = L"简易教务管理系统 - 学生端";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &stuIndexForm::stuIndexForm_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		 MessageBox::Show("本模块将在后续章节实现");
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		 MessageBox::Show("本模块将在后续章节实现");
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		 MessageBox::Show("本模块将在后续章节实现");
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		selectCourse ^sC = gcnew selectCourse(thisLogin);
		sC->Show();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		courseSelected ^c_Sed = gcnew courseSelected(thisLogin);
		c_Sed->Show();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		updatePasswd ^updatePS = gcnew updatePasswd(thisLogin);
		updatePS->Show();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		stuInfo ^stuIn = gcnew stuInfo(thisLogin);
		stuIn->Show();
	}
	private: System::Void stuIndexForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
	}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::OpenForms["loginForm1"]->Show();
	this->Hide();
}
};
}
