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
	private: System::Windows::Forms::Button^  deleteButton;




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
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// coursesHasSelectedList
			// 
			this->coursesHasSelectedList->FormattingEnabled = true;
			this->coursesHasSelectedList->ItemHeight = 24;
			this->coursesHasSelectedList->Location = System::Drawing::Point(60, 62);
			this->coursesHasSelectedList->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->coursesHasSelectedList->Name = L"coursesHasSelectedList";
			this->coursesHasSelectedList->Size = System::Drawing::Size(244, 268);
			this->coursesHasSelectedList->TabIndex = 0;
			this->coursesHasSelectedList->SelectedIndexChanged += gcnew System::EventHandler(this, &courseSelected::coursesHasSelectedList_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(376, 70);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"课程名称：";
			// 
			// C_NameTbox
			// 
			this->C_NameTbox->Location = System::Drawing::Point(518, 62);
			this->C_NameTbox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->C_NameTbox->Name = L"C_NameTbox";
			this->C_NameTbox->Size = System::Drawing::Size(196, 35);
			this->C_NameTbox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(380, 150);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"课程学分：";
			// 
			// C_CreditTbox
			// 
			this->C_CreditTbox->Location = System::Drawing::Point(518, 144);
			this->C_CreditTbox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->C_CreditTbox->Name = L"C_CreditTbox";
			this->C_CreditTbox->Size = System::Drawing::Size(196, 35);
			this->C_CreditTbox->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(384, 234);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"课程成绩：";
			// 
			// C_GradeTbox
			// 
			this->C_GradeTbox->Location = System::Drawing::Point(518, 226);
			this->C_GradeTbox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->C_GradeTbox->Name = L"C_GradeTbox";
			this->C_GradeTbox->Size = System::Drawing::Size(196, 35);
			this->C_GradeTbox->TabIndex = 6;
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(474, 303);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(137, 46);
			this->deleteButton->TabIndex = 7;
			this->deleteButton->Text = L"删除选课";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &courseSelected::deleteButton_Click);
			// 
			// courseSelected
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 390);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->C_GradeTbox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->C_CreditTbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->C_NameTbox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->coursesHasSelectedList);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
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

	 void initCoursesHasSelectedList()
	{
		coursesHasSelectedList->Items->Clear();
		Student *stu = new Student();
		Course *p = new Course();
		char courseId[20];
		string name;
		cli::array<String^>^ list = stu->getAllSelfSelectedCourses(thisLogin->getId());

		for each(String ^item in list){
			sprintf(courseId, "%s", item);
			p = stu->readCourseInfo(courseId);
			name = p->getCourseName();
			item += " ";
			item += gcnew String(name.c_str());
			coursesHasSelectedList->Items->Add(item);
		}
	}
	private: System::Void courseSelected_Load(System::Object^  sender, System::EventArgs^  e) {
		initCoursesHasSelectedList();

	}
private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char courseid[50],cIdStuId[50];
	sprintf(courseid,"%s",coursesHasSelectedList->SelectedItem->ToString()->Substring(0, coursesHasSelectedList->SelectedItem->ToString()->IndexOf(" ")));
	sprintf(cIdStuId, "%s %s", courseid, thisLogin->getId()); //得到选课表主键(课程id + 学生id)
	Student *stu = new Student();
	if (stu->getSelectedCourseInfo(cIdStuId)->getScore() > 0) {
		MessageBox::Show("不能删除已有成绩课程");
		delete stu;
		return;
	}
	if (stu->deleteSelfSelectedCourse(cIdStuId)) {
		MessageBox::Show("删除成功...");
		delete stu;
	}
	initCoursesHasSelectedList(); //更新已选课程列表
	
}
};
}
