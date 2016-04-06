#pragma once
#include "memberInfo.h"
#include "memberService.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// courseSelected 摘要
	/// </summary>
	public ref class courseSelected : public System::Windows::Forms::Form
	{
	public:
		courseSelected(UserTable *login)
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
		~courseSelected()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::ListBox^  coursesHasSelectedList;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  C_NameTbox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  C_CreditTbox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  C_GradeTbox;



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
			this->coursesHasSelectedList = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->C_NameTbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->C_CreditTbox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->C_GradeTbox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// coursesHasSelectedList
			// 
			this->coursesHasSelectedList->FormattingEnabled = true;
			this->coursesHasSelectedList->ItemHeight = 12;
			this->coursesHasSelectedList->Location = System::Drawing::Point(30, 31);
			this->coursesHasSelectedList->Name = L"coursesHasSelectedList";
			this->coursesHasSelectedList->Size = System::Drawing::Size(124, 136);
			this->coursesHasSelectedList->TabIndex = 0;
			this->coursesHasSelectedList->SelectedIndexChanged += gcnew System::EventHandler(this, &courseSelected::coursesHasSelectedList_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(188, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"课程名称：";
			// 
			// C_NameTbox
			// 
			this->C_NameTbox->Location = System::Drawing::Point(259, 31);
			this->C_NameTbox->Name = L"C_NameTbox";
			this->C_NameTbox->Size = System::Drawing::Size(100, 21);
			this->C_NameTbox->TabIndex = 2;
			this->C_NameTbox->TextChanged += gcnew System::EventHandler(this, &courseSelected::C_NameTbox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(190, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"课程学分：";
			// 
			// C_CreditTbox
			// 
			this->C_CreditTbox->Location = System::Drawing::Point(259, 72);
			this->C_CreditTbox->Name = L"C_CreditTbox";
			this->C_CreditTbox->Size = System::Drawing::Size(100, 21);
			this->C_CreditTbox->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(192, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 5;
			this->label3->Text = L"课程成绩：";
			// 
			// C_GradeTbox
			// 
			this->C_GradeTbox->Location = System::Drawing::Point(259, 113);
			this->C_GradeTbox->Name = L"C_GradeTbox";
			this->C_GradeTbox->Size = System::Drawing::Size(100, 21);
			this->C_GradeTbox->TabIndex = 6;
			// 
			// courseSelected
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 195);
			this->Controls->Add(this->C_GradeTbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->C_CreditTbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->C_NameTbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->coursesHasSelectedList);
			this->Name = L"courseSelected";
			this->Text = L"已选课程";
			this->Load += gcnew System::EventHandler(this, &courseSelected::courseSelected_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void coursesHasSelectedList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		String ^courseId;
		String ^courseName;
		String ^courseCredit;
		String ^Score;
		char cId[20]; //课程代码
		char buff[20];
		string temp;
		Student *stu = new Student();
		courseId = coursesHasSelectedList->SelectedItem->ToString();
		courseId = courseId->Substring(0, courseId->IndexOf(" "));//只取课程代码
		sprintf(cId, "%s", courseId);
		Course *cs = new Course();
		cs = stu->readCourseInfo(cId);   //用课程代码检索课程表
		temp = cs->getCourseName();
		courseName = gcnew String(temp.c_str());
		sprintf(buff, "%d", cs->getCredit());
		temp = buff;
		courseCredit = gcnew String(temp.c_str());
		temp = thisLogin->getId();
		courseId += " ";
		courseId += gcnew String(temp.c_str());//加上学生id，来检索选课表，得到课程分数
		char id[20];
		sprintf(id, "%s", courseId);
		selectedCourse *p = new selectedCourse();
		p = stu->getSelectedCourseInfo(id);
		sprintf(buff, "%d", p->getScore());
		temp = buff;
		Score = gcnew String(temp.c_str());

		C_NameTbox->Text = courseName;
		C_CreditTbox->Text = courseCredit;
		C_GradeTbox->Text = Score;

	}
	private: System::Void courseSelected_Load(System::Object^  sender, System::EventArgs^  e) {
		coursesHasSelectedList->Items->Clear();
		Student *stu = new Student();
		Course *p = new Course();
		char courseId[20];
		string name;
		cout << thisLogin->getId() << endl;
		cli::array<String^>^ list = stu->getAllSelfSelectedCourses(thisLogin->getId());
		
		for each(String ^item in list)
		{
			sprintf(courseId, "%s", item);
			p = stu->readCourseInfo(courseId);
			name = p->getCourseName();
			item += " ";
			item += gcnew String(name.c_str());
			coursesHasSelectedList->Items->Add(item);
		}

	}
private: System::Void C_NameTbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
