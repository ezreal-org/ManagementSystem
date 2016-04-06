#pragma once
#include "memberService.h"
#include "memberInfo.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// allCourseArrangement 摘要
	/// </summary>
	public ref class allCourseArrangement : public System::Windows::Forms::Form
	{
	public:
		allCourseArrangement(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~allCourseArrangement()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tb_classRoom;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tb_classTime;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  arrangeButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  courseArrangementList;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox_teacher;




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
			this->tb_classRoom = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_classTime = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_teacher = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->arrangeButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->courseArrangementList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_classRoom
			// 
			this->tb_classRoom->Location = System::Drawing::Point(92, 70);
			this->tb_classRoom->Name = L"tb_classRoom";
			this->tb_classRoom->Size = System::Drawing::Size(140, 21);
			this->tb_classRoom->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 8;
			this->label3->Text = L"课室位置：";
			// 
			// tb_classTime
			// 
			this->tb_classTime->Location = System::Drawing::Point(92, 30);
			this->tb_classTime->Name = L"tb_classTime";
			this->tb_classTime->Size = System::Drawing::Size(140, 21);
			this->tb_classTime->TabIndex = 7;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox_teacher);
			this->groupBox1->Controls->Add(this->tb_classRoom);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->tb_classTime);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(264, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(255, 152);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"排课信息";
			// 
			// comboBox_teacher
			// 
			this->comboBox_teacher->FormattingEnabled = true;
			this->comboBox_teacher->Location = System::Drawing::Point(94, 113);
			this->comboBox_teacher->Name = L"comboBox_teacher";
			this->comboBox_teacher->Size = System::Drawing::Size(138, 20);
			this->comboBox_teacher->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 12);
			this->label4->TabIndex = 8;
			this->label4->Text = L"任课教师：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 6;
			this->label2->Text = L"上课时间：";
			// 
			// arrangeButton
			// 
			this->arrangeButton->Location = System::Drawing::Point(384, 197);
			this->arrangeButton->Name = L"arrangeButton";
			this->arrangeButton->Size = System::Drawing::Size(75, 23);
			this->arrangeButton->TabIndex = 10;
			this->arrangeButton->Text = L"排课";
			this->arrangeButton->UseVisualStyleBackColor = true;
			this->arrangeButton->Click += gcnew System::EventHandler(this, &allCourseArrangement::arrangeButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 9;
			this->label1->Text = L"课程列表";
			// 
			// courseArrangementList
			// 
			this->courseArrangementList->FormattingEnabled = true;
			this->courseArrangementList->ItemHeight = 12;
			this->courseArrangementList->Location = System::Drawing::Point(26, 39);
			this->courseArrangementList->Name = L"courseArrangementList";
			this->courseArrangementList->Size = System::Drawing::Size(210, 148);
			this->courseArrangementList->TabIndex = 12;
			this->courseArrangementList->SelectedIndexChanged += gcnew System::EventHandler(this, &allCourseArrangement::courseArrangementList_SelectedIndexChanged);
			// 
			// allCourseArrangement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(577, 239);
			this->Controls->Add(this->courseArrangementList);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->arrangeButton);
			this->Controls->Add(this->label1);
			this->Name = L"allCourseArrangement";
			this->Text = L"排课";
			this->Load += gcnew System::EventHandler(this, &allCourseArrangement::allCourseArrangement_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void allCourseArrangement_Load(System::Object^  sender, System::EventArgs^  e) {
		//在courseArrangementList显示所以排课表摘要信息
		this->courseArrangementList->Items->Clear();
		AcademicStaff *staff = new AcademicStaff();
		string courseName, teaName;
		char courseId[20], teacherId[20];
		int type;
		cli::array<String ^> ^list = staff->getAllCourseId();
		for each (String ^a in list){
			sprintf(courseId, "%s", a);
			courseName = staff->readCourseInfo(courseId)->getCourseName();
			type = staff->readCourseInfo(courseId)->getType();
			a += " ";
			a += gcnew String(courseName.c_str());
			this->courseArrangementList->Items->Add(a);
		}
		//初始化任课老师Combox
		comboBox_teacher->Items->Clear();
		comboBox_teacher->Items->Add("--选择任课教师--");
		list = staff->getAllTeacherId();
		for each(String ^tid in list) {
			sprintf(teacherId, "%s", tid);
			teaName = staff->readTeacherInfo(teacherId)->getName();
			tid += "_";
			tid += gcnew String(teaName.c_str());
			comboBox_teacher->Items->Add(tid);
		}
		delete staff;
	}
	private: System::Void courseArrangementList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		char courseId[20];
		string strTemp;
		String ^selectedCourseId,^teaId;
		AcademicStaff *staff = new AcademicStaff();
		//获取课程id
		selectedCourseId = courseArrangementList->SelectedItem->ToString()->Substring(0, courseArrangementList->SelectedItem->ToString()->IndexOf(" "));
		sprintf(courseId, "%s",selectedCourseId );
		courseArrangement *p = staff->readCourseArrangement(courseId);
		//初始化任课老师Combox
		this->comboBox_teacher->SelectedIndex = 0;
		if (p != nullptr) {
			strTemp = p->getTeacherId();
			teaId = gcnew String(strTemp.c_str());
			//选中指定的任课教师
			for (int i = 0; i < comboBox_teacher->Items->Count;i++) {
				if (comboBox_teacher->Items[i]->ToString()->Contains(teaId)) {
					comboBox_teacher->SelectedIndex = i;
					break;
				}
			}
			strTemp = p->getClassRoom();
			tb_classRoom->Text = gcnew String(strTemp.c_str());
			strTemp = p->getTime();
			tb_classTime->Text = gcnew String(strTemp.c_str());
		}
		delete staff;
	}
	private: System::Void arrangeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		char courseId[50];
		char classRoom[50], classTime[20],teacherId[20];
		sprintf(courseId, "%s", courseArrangementList->SelectedItem->ToString()->Substring(0, courseArrangementList->SelectedItem->ToString()->IndexOf(" ")));
		AcademicStaff *staff = new AcademicStaff();
		courseArrangement *p = new courseArrangement();
		sprintf(classRoom, "%s", tb_classRoom->Text);
		sprintf(classTime, "%s", tb_classTime->Text);
		sprintf(teacherId, "%s", comboBox_teacher->SelectedItem->ToString()->Substring(0,comboBox_teacher->SelectedItem->ToString()->IndexOf("_")));
		p->setClassRoom(classRoom);
		p->setTime(classTime);
		p->setCourseId(courseId);
		p->setTeacherId(teacherId);
		if (staff->writeCourseArrangement(p)) {
			MessageBox::Show("排课成功...");
		}
		delete staff, p;
	}
	};
}
