#pragma once

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// recordGrade 摘要
	/// </summary>
	public ref class recordGrade : public System::Windows::Forms::Form
	{
	public:
		recordGrade(UserTable *login)
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
		~recordGrade()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ListBox^  coursesList;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ListBox^  stuOfCourseList;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  recordButton;
	private: System::Windows::Forms::TextBox^  markTextbox;
	private: System::Windows::Forms::Label^  stuName;
	private: System::Windows::Forms::Label^  courseName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->coursesList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->stuOfCourseList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->stuName = (gcnew System::Windows::Forms::Label());
			this->courseName = (gcnew System::Windows::Forms::Label());
			this->recordButton = (gcnew System::Windows::Forms::Button());
			this->markTextbox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->coursesList);
			this->groupBox1->Location = System::Drawing::Point(13, 26);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(130, 233);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"课程";
			// 
			// coursesList
			// 
			this->coursesList->FormattingEnabled = true;
			this->coursesList->ItemHeight = 12;
			this->coursesList->Location = System::Drawing::Point(11, 21);
			this->coursesList->Name = L"coursesList";
			this->coursesList->Size = System::Drawing::Size(113, 184);
			this->coursesList->TabIndex = 0;
			this->coursesList->SelectedIndexChanged += gcnew System::EventHandler(this, &recordGrade::coursesList_SelectedIndexChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->stuOfCourseList);
			this->groupBox2->Location = System::Drawing::Point(157, 26);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(181, 233);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"选课学生名单";
			// 
			// stuOfCourseList
			// 
			this->stuOfCourseList->FormattingEnabled = true;
			this->stuOfCourseList->ItemHeight = 12;
			this->stuOfCourseList->Location = System::Drawing::Point(11, 24);
			this->stuOfCourseList->Name = L"stuOfCourseList";
			this->stuOfCourseList->Size = System::Drawing::Size(160, 184);
			this->stuOfCourseList->TabIndex = 0;
			this->stuOfCourseList->SelectedIndexChanged += gcnew System::EventHandler(this, &recordGrade::stuOfCourseList_SelectedIndexChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->stuName);
			this->groupBox3->Controls->Add(this->courseName);
			this->groupBox3->Controls->Add(this->recordButton);
			this->groupBox3->Controls->Add(this->markTextbox);
			this->groupBox3->Location = System::Drawing::Point(357, 33);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(124, 226);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"成绩";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(56, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(11, 12);
			this->label4->TabIndex = 4;
			this->label4->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 12);
			this->label2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 12);
			this->label1->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 12);
			this->label3->TabIndex = 3;
			this->label3->Text = L"分数：";
			// 
			// stuName
			// 
			this->stuName->AutoSize = true;
			this->stuName->Location = System::Drawing::Point(8, 57);
			this->stuName->Name = L"stuName";
			this->stuName->Size = System::Drawing::Size(41, 12);
			this->stuName->TabIndex = 3;
			this->stuName->Text = L"学生：";
			// 
			// courseName
			// 
			this->courseName->AutoSize = true;
			this->courseName->Location = System::Drawing::Point(7, 28);
			this->courseName->Name = L"courseName";
			this->courseName->Size = System::Drawing::Size(41, 12);
			this->courseName->TabIndex = 2;
			this->courseName->Text = L"课程：";
			// 
			// recordButton
			// 
			this->recordButton->Location = System::Drawing::Point(21, 163);
			this->recordButton->Name = L"recordButton";
			this->recordButton->Size = System::Drawing::Size(80, 23);
			this->recordButton->TabIndex = 1;
			this->recordButton->Text = L"录 入";
			this->recordButton->UseVisualStyleBackColor = true;
			this->recordButton->Click += gcnew System::EventHandler(this, &recordGrade::recordButton_Click);
			// 
			// markTextbox
			// 
			this->markTextbox->Location = System::Drawing::Point(21, 115);
			this->markTextbox->Name = L"markTextbox";
			this->markTextbox->Size = System::Drawing::Size(80, 21);
			this->markTextbox->TabIndex = 0;
			// 
			// recordGrade
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 281);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"recordGrade";
			this->Text = L"录入成绩";
			this->Load += gcnew System::EventHandler(this, &recordGrade::recordGrade_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void recordGrade_Load(System::Object^  sender, System::EventArgs^  e) {
		coursesList->Items->Clear();
		char id[20];
		string courseName;
		Teacher *tea = new Teacher();
		cli::array<String^>^ list = tea->getSelfTeachCourseCode(thisLogin->getId());
		for each(String ^item in list)
		{
			sprintf(id, "%s", item);
			courseName = tea->readCourseInfo(id)->getCourseName();
			item += " ";
			item += gcnew String(courseName.c_str());
			coursesList->Items->Add(item);
		}
	}
private: System::Void coursesList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	String ^courseCode;
	char id[20];
	string stuName;
	Teacher *tea = new Teacher();
	StudentTable *p;
	courseCode = coursesList->SelectedItem->ToString();
	courseCode = courseCode->Substring(0, courseCode->IndexOf(" "));
	sprintf(id, "%s", courseCode);
	cli::array<String^>^ list = tea->getAllSelectedStuIdByCourseId(id);
	Course *cs = new Course();
	cs = tea->readCourseInfo(id);
	stuOfCourseList->Items->Clear();
	for each(String^ item in list){
		sprintf(id, "%s", item);
		p = tea->getStuBasicInfo(cs->getType(), id);
		if (p != nullptr) {
			stuName = p->getName();
			item += " ";
			item += gcnew String(stuName.c_str());
			stuOfCourseList->Items->Add(item);
		}
	}
}
private: System::Void stuOfCourseList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	
	Teacher *tea = new Teacher();
	String ^courseName;
	String ^courseId;
	String ^stuId;
	String ^stuName;
	char sId[20];
	char cId[20];
	char selectedCourseCode[40]; // 选课表主键：课程id + 学生 id
	char score[20];
	string sc;
	courseName = coursesList->SelectedItem->ToString();
	courseId = courseName->Substring(0, courseName->IndexOf(" "));
	courseName = courseName->Substring(courseName->IndexOf(" ") + 1);
	stuName = stuOfCourseList->SelectedItem->ToString();
	stuId = stuName->Substring(0, stuName->IndexOf(" "));
	stuName = stuName->Substring(stuName->IndexOf(" ") + 1);
	sprintf(sId, "%s", stuId);
	sprintf(cId, "%s", courseId);
	sprintf(selectedCourseCode, "%s %s", cId, sId);
	sprintf(score, "%d", tea->getSelectedCourseInfo(selectedCourseCode)->getScore());
	sc = score;
	label1->Text = courseName;
	label2->Text = stuName;
	label4->Text = gcnew String(sc.c_str());
}
private: System::Void recordButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char id[20];
	char cId[20];
	String ^courseId;
	String ^stuId;
	courseId = coursesList->SelectedItem->ToString();
	courseId = courseId->Substring(0, courseId->IndexOf(" "));
	stuId = stuOfCourseList->SelectedItem->ToString();
	stuId = stuId->Substring(0, stuId->IndexOf(" "));
	sprintf(id, "%s", stuId);
	sprintf(cId, "%s", courseId);
	int score;
	score = Convert::ToInt16(markTextbox->Text->ToString());
	selectedCourse *sc = new selectedCourse();
	sc->setCourseId(cId);
	sc->setStuId(id);
	sc->setScore(score);
	Teacher *tea = new Teacher();
	if (tea->writeSelectedCourse(sc)) {
		MessageBox::Show("成绩已录入！");
	}
	label4->Text = markTextbox->Text;
	markTextbox->Text = "";
	delete tea;
}
};
}
