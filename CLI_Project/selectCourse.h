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
	/// selectCourse 摘要
	/// </summary>
	public ref class selectCourse : public System::Windows::Forms::Form
	{
	public:
		selectCourse(UserTable *login)
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
		~selectCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::Button^  submitButton;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckedListBox^  coursesNeededSelectedList;
	private: System::Windows::Forms::ListBox^  coursesHasSelectedList;
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
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->coursesHasSelectedList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->coursesNeededSelectedList = (gcnew System::Windows::Forms::CheckedListBox());
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(238, 248);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(92, 23);
			this->submitButton->TabIndex = 5;
			this->submitButton->Text = L"提 交";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &selectCourse::submitButton_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->coursesHasSelectedList);
			this->groupBox2->Location = System::Drawing::Point(410, 28);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(199, 213);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"已选";
			// 
			// coursesHasSelectedList
			// 
			this->coursesHasSelectedList->FormattingEnabled = true;
			this->coursesHasSelectedList->ItemHeight = 12;
			this->coursesHasSelectedList->Location = System::Drawing::Point(14, 20);
			this->coursesHasSelectedList->Name = L"coursesHasSelectedList";
			this->coursesHasSelectedList->Size = System::Drawing::Size(173, 172);
			this->coursesHasSelectedList->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->coursesNeededSelectedList);
			this->groupBox1->Location = System::Drawing::Point(37, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(349, 213);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"可选课程";
			// 
			// coursesNeededSelectedList
			// 
			this->coursesNeededSelectedList->CheckOnClick = true;
			this->coursesNeededSelectedList->FormattingEnabled = true;
			this->coursesNeededSelectedList->Location = System::Drawing::Point(16, 20);
			this->coursesNeededSelectedList->Name = L"coursesNeededSelectedList";
			this->coursesNeededSelectedList->Size = System::Drawing::Size(311, 180);
			this->coursesNeededSelectedList->TabIndex = 0;
			this->coursesNeededSelectedList->SelectedIndexChanged += gcnew System::EventHandler(this, &selectCourse::coursesNeededSelectedList_SelectedIndexChanged);
			// 
			// selectCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(631, 283);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"selectCourse";
			this->Text = L"选修课程";
			this->Load += gcnew System::EventHandler(this, &selectCourse::selectCourse_Load);
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void coursesNeededSelectedList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		coursesHasSelectedList->Items->Clear();
		for (int i = 0; i<coursesNeededSelectedList->CheckedIndices->Count; i++) {
			coursesHasSelectedList->Items->Add(coursesNeededSelectedList->Items[coursesNeededSelectedList->CheckedIndices[i]]);
		}
	}
	private: System::Void selectCourse_Load(System::Object^  sender, System::EventArgs^  e) {
		char  cidTid[20], teacherId[20], courseId[20];
		string courseName, teacherName, classRoom, classTime;
		courseArrangement *p = new courseArrangement();
		coursesNeededSelectedList->Items->Clear();
		Student *stu = new Student();
		cli::array<String^>^ list = stu->getAllCourseArrangementId();
		cli::array<String^>^ selectedCourseIdList = stu->getAllSelfSelectedCourses(thisLogin->getId());
		for each(String ^item in list)
		{
			// 5-9 
			sprintf(cidTid, "%s", item);
			sprintf(courseId, "%s", item->Substring(0, item->IndexOf(" ")));
			p = stu->readCourseArrangement(cidTid);
			if (strlen(p->getClassRoom()) < 2) continue; //为排课程不能选
			bool isExsit = false;
			for each(String ^cid in selectedCourseIdList)
				if (item->Contains(cid))
				{
					isExsit = true;
					break;
				}
			if (isExsit) continue; //已选课程不能选
			if (stu->readCourseInfo(courseId)->getType() == thisLogin->getType())
			{
				strcpy(teacherId, p->getTeacherId());
				teacherName = stu->readTeacherInfo(teacherId)->getName();
				courseName = stu->readCourseInfo(courseId)->getCourseName();
				classRoom = p->getClassRoom();
				classTime = p->getTime();

				item += " ";
				item += gcnew String(courseName.c_str());
				item += ",";
				item += gcnew String(teacherName.c_str());
				item += ",";
				item += gcnew String(classRoom.c_str());
				item += ",";
				item += gcnew String(classTime.c_str());
				coursesNeededSelectedList->Items->Add(item);
			}
		}
	}

	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^idStr;
		char id[20];
		int successCount = 0;
		for (int i = 0; i<coursesNeededSelectedList->CheckedIndices->Count; i++) {
			idStr = coursesNeededSelectedList->Items[coursesNeededSelectedList->CheckedIndices[i]]->ToString();
			idStr = idStr->Substring(0, idStr->IndexOf(" "));
			//学生选课
			sprintf(id, "%s", idStr);
			selectedCourse *p = new selectedCourse();
			p->setCourseId(id);
			p->setStuId(thisLogin->getId());
			p->setScore(0);
			Student *stu = new Student();
			successCount += stu->writeSelectedCourse(p);
		}
		if (successCount == coursesNeededSelectedList->CheckedIndices->Count) {
			MessageBox::Show("选课已成功添加..");
		}
	}
	};
}
