#pragma once
#include "memberService.h"
#include "typeDefinition.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// allCourse 摘要
	/// </summary>
	public ref class allCourse : public System::Windows::Forms::Form
	{
	public:
		allCourse(void)
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
		~allCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  courseList;
	protected:

	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  CourseCreditBox;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  courseNameBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  deleteButton;
	private: System::Windows::Forms::Button^  modifyButton;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  CourseTypeCombox;


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
			this->courseList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->CourseTypeCombox = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CourseCreditBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->courseNameBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->modifyButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// courseList
			// 
			this->courseList->FormattingEnabled = true;
			this->courseList->ItemHeight = 24;
			this->courseList->Location = System::Drawing::Point(23, 58);
			this->courseList->Margin = System::Windows::Forms::Padding(6);
			this->courseList->Name = L"courseList";
			this->courseList->Size = System::Drawing::Size(394, 268);
			this->courseList->TabIndex = 17;
			this->courseList->SelectedIndexChanged += gcnew System::EventHandler(this, &allCourse::courseList_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->CourseTypeCombox);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->CourseCreditBox);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->courseNameBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(453, 58);
			this->groupBox1->Margin = System::Windows::Forms::Padding(6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(6);
			this->groupBox1->Size = System::Drawing::Size(434, 240);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"详细信息";
			// 
			// CourseTypeCombox
			// 
			this->CourseTypeCombox->FormattingEnabled = true;
			this->CourseTypeCombox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"研究生", L"本科生" });
			this->CourseTypeCombox->Location = System::Drawing::Point(192, 182);
			this->CourseTypeCombox->Name = L"CourseTypeCombox";
			this->CourseTypeCombox->Size = System::Drawing::Size(194, 32);
			this->CourseTypeCombox->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(46, 189);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(137, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"课程类型：";
			// 
			// CourseCreditBox
			// 
			this->CourseCreditBox->Location = System::Drawing::Point(185, 122);
			this->CourseCreditBox->Margin = System::Windows::Forms::Padding(6);
			this->CourseCreditBox->Name = L"CourseCreditBox";
			this->CourseCreditBox->Size = System::Drawing::Size(202, 35);
			this->CourseCreditBox->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(47, 124);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"学  分：";
			// 
			// courseNameBox
			// 
			this->courseNameBox->Location = System::Drawing::Point(184, 50);
			this->courseNameBox->Margin = System::Windows::Forms::Padding(6);
			this->courseNameBox->Name = L"courseNameBox";
			this->courseNameBox->Size = System::Drawing::Size(202, 35);
			this->courseNameBox->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 56);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"课程名称：";
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(499, 310);
			this->deleteButton->Margin = System::Windows::Forms::Padding(6);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(150, 46);
			this->deleteButton->TabIndex = 14;
			this->deleteButton->Text = L"删除";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &allCourse::deleteButton_Click);
			// 
			// modifyButton
			// 
			this->modifyButton->Location = System::Drawing::Point(693, 310);
			this->modifyButton->Margin = System::Windows::Forms::Padding(6);
			this->modifyButton->Name = L"modifyButton";
			this->modifyButton->Size = System::Drawing::Size(150, 46);
			this->modifyButton->TabIndex = 15;
			this->modifyButton->Text = L"修改";
			this->modifyButton->UseVisualStyleBackColor = true;
			this->modifyButton->Click += gcnew System::EventHandler(this, &allCourse::modifyButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 28);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 25);
			this->label1->TabIndex = 13;
			this->label1->Text = L"课程列表";
			// 
			// allCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(925, 413);
			this->Controls->Add(this->courseList);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->modifyButton);
			this->Controls->Add(this->label1);
			this->Name = L"allCourse";
			this->Text = L"所有课程";
			this->Load += gcnew System::EventHandler(this, &allCourse::allCourse_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void initCourseList() //在CourseList显示所有课程摘要信息
		{
			this->courseList->Items->Clear();
			AcademicStaff *staff = new AcademicStaff();
			string name;
			char id[20];
			cli::array<String ^> ^list = staff->getAllCourseId();
			for each (String ^a in list) {
				sprintf(id, "%s", a);
				name = staff->readCourseInfo(id)->getCourseName();
				a += " ";
				a += gcnew String(name.c_str());
				this->courseList->Items->Add(a);
			}
			if (this->courseList->Items->Count > 0) {
				this->courseList->SelectedIndex = 0;
			}
			delete staff;
		}

	private: System::Void allCourse_Load(System::Object^  sender, System::EventArgs^  e) {
		//在courseList显示所有课程摘要信息
		initCourseList();
	}
private: System::Void courseList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	char id[50], scoreArray[20];
	//获取课程ID字段
	sprintf(id, "%s", courseList->SelectedItem->ToString()->Substring(0, courseList->SelectedItem->ToString()->IndexOf(" ")));
	AcademicStaff *staff = new AcademicStaff();
	Course *p = staff->readCourseInfo(id);
	string strTemp;
	strTemp = p->getCourseName();
	courseNameBox->Text = gcnew String(strTemp.c_str());
	sprintf(scoreArray, "%d", p->getCredit());
	strTemp = scoreArray;
	CourseCreditBox->Text = gcnew String(strTemp.c_str());
	if (p->getType() == (int)UserTypeCode::USER_GRADUATE) {
		CourseTypeCombox->SelectedIndex = 0;
	}
	else if (p->getType() == (int)UserTypeCode::USER_UNDERGRADUATE)
	{
		CourseTypeCombox->SelectedIndex = 1;
	}
	delete staff;
}
private: System::Void modifyButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char id[50];
	int score;
	char courseName[50];
	//获取课程id字段
	sprintf(id, "%s", courseList->SelectedItem->ToString()->Substring(0, courseList->SelectedItem->ToString()->IndexOf(" ")));
	AcademicStaff *staff = new AcademicStaff();
	Course *p = new Course();
	p->setCourseCode(id);
	sprintf(courseName, "%s", courseNameBox->Text);
	score = Convert::ToInt16(this->CourseCreditBox->Text->ToString());
	p->setCourseName(courseName);
	p->setCredit(score);
	if (CourseTypeCombox->SelectedIndex == 0) {
		p->setType((int)UserTypeCode::USER_GRADUATE);
	}
	else if (CourseTypeCombox->SelectedIndex == 1) {
		p->setType((int)UserTypeCode::USER_UNDERGRADUATE);
	}
	if (staff->writeCourse(p)) {
		MessageBox::Show("修改成功...");
	}
	delete staff, p;
}
private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char id[50];
	sprintf(id, "%s", courseList->SelectedItem->ToString()->Substring(0, courseList->SelectedItem->ToString()->IndexOf(" ")));
	AcademicStaff *staff = new AcademicStaff();
	if (staff->deleteCourse(id)) {
		MessageBox::Show("删除成功...");
	}
	initCourseList(); //更新课程列表
	delete staff;
}
};
}
