#pragma once

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// addNewCourse 摘要
	/// </summary>
	public ref class addNewCourse : public System::Windows::Forms::Form
	{
	public:
		addNewCourse()
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
		~addNewCourse()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  courseNameTbox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  courseCreditTbox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RadioButton^  underGraduateCourseRadio;
	private: System::Windows::Forms::RadioButton^  graduateRadio;
	private: System::Windows::Forms::Button^  submitButton;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  courseCodeTbox;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->courseNameTbox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->courseCreditTbox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->underGraduateCourseRadio = (gcnew System::Windows::Forms::RadioButton());
			this->graduateRadio = (gcnew System::Windows::Forms::RadioButton());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->courseCodeTbox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(70, 84);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"课程名称：";
			// 
			// courseNameTbox
			// 
			this->courseNameTbox->Location = System::Drawing::Point(198, 72);
			this->courseNameTbox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->courseNameTbox->Name = L"courseNameTbox";
			this->courseNameTbox->Size = System::Drawing::Size(196, 35);
			this->courseNameTbox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(456, 78);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"学分：";
			// 
			// courseCreditTbox
			// 
			this->courseCreditTbox->Location = System::Drawing::Point(550, 72);
			this->courseCreditTbox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->courseCreditTbox->Name = L"courseCreditTbox";
			this->courseCreditTbox->Size = System::Drawing::Size(196, 35);
			this->courseCreditTbox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(408, 182);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"课程类型：";
			// 
			// underGraduateCourseRadio
			// 
			this->underGraduateCourseRadio->AutoSize = true;
			this->underGraduateCourseRadio->Location = System::Drawing::Point(550, 178);
			this->underGraduateCourseRadio->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->underGraduateCourseRadio->Name = L"underGraduateCourseRadio";
			this->underGraduateCourseRadio->Size = System::Drawing::Size(112, 29);
			this->underGraduateCourseRadio->TabIndex = 5;
			this->underGraduateCourseRadio->TabStop = true;
			this->underGraduateCourseRadio->Text = L"本科生";
			this->underGraduateCourseRadio->UseVisualStyleBackColor = true;
			// 
			// graduateRadio
			// 
			this->graduateRadio->AutoSize = true;
			this->graduateRadio->Location = System::Drawing::Point(678, 178);
			this->graduateRadio->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->graduateRadio->Name = L"graduateRadio";
			this->graduateRadio->Size = System::Drawing::Size(112, 29);
			this->graduateRadio->TabIndex = 6;
			this->graduateRadio->TabStop = true;
			this->graduateRadio->Text = L"硕士生";
			this->graduateRadio->UseVisualStyleBackColor = true;
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(368, 292);
			this->submitButton->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(170, 46);
			this->submitButton->TabIndex = 7;
			this->submitButton->Text = L"提 交";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &addNewCourse::submitButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(70, 178);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(137, 25);
			this->label4->TabIndex = 0;
			this->label4->Text = L"课程代码：";
			// 
			// courseCodeTbox
			// 
			this->courseCodeTbox->Location = System::Drawing::Point(198, 170);
			this->courseCodeTbox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->courseCodeTbox->Name = L"courseCodeTbox";
			this->courseCodeTbox->Size = System::Drawing::Size(196, 35);
			this->courseCodeTbox->TabIndex = 1;
			// 
			// addNewCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(908, 402);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->graduateRadio);
			this->Controls->Add(this->underGraduateCourseRadio);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->courseCreditTbox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->courseCodeTbox);
			this->Controls->Add(this->courseNameTbox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"addNewCourse";
			this->Text = L"添加课程";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		AcademicStaff *staff = new AcademicStaff();
		Course *p = new Course();
		char courseCode[20]; //课程代码
		char courseName[20]; //课程名
		int credit;
		int type;
		sprintf(courseCode, "%s", courseCodeTbox->Text);
		sprintf(courseName, "%s", courseNameTbox->Text);
		credit = Convert::ToInt16(courseCreditTbox->Text->ToString());
		if (underGraduateCourseRadio->Checked) type = (int)UserTypeCode::USER_UNDERGRADUATE; //本科生
		else type = (int)UserTypeCode::USER_GRADUATE;
		p->setCredit(credit);
		p->setCourseCode(courseCode);
		p->setCourseName(courseName);
		p->setType(type);
		//添加课程
		if (staff->writeCourse(p)) {
			MessageBox::Show("添加成功!");
		}
		delete p,staff;
	}
};
}
