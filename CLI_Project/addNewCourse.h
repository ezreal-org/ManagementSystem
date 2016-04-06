#pragma once

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// addNewCourse ժҪ
	/// </summary>
	public ref class addNewCourse : public System::Windows::Forms::Form
	{
	public:
		addNewCourse()
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
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
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
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
			this->label1->Location = System::Drawing::Point(35, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�γ����ƣ�";
			// 
			// courseNameTbox
			// 
			this->courseNameTbox->Location = System::Drawing::Point(99, 36);
			this->courseNameTbox->Name = L"courseNameTbox";
			this->courseNameTbox->Size = System::Drawing::Size(100, 21);
			this->courseNameTbox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(228, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 12);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ѧ�֣�";
			// 
			// courseCreditTbox
			// 
			this->courseCreditTbox->Location = System::Drawing::Point(275, 36);
			this->courseCreditTbox->Name = L"courseCreditTbox";
			this->courseCreditTbox->Size = System::Drawing::Size(100, 21);
			this->courseCreditTbox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(204, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 4;
			this->label3->Text = L"�γ����ͣ�";
			// 
			// underGraduateCourseRadio
			// 
			this->underGraduateCourseRadio->AutoSize = true;
			this->underGraduateCourseRadio->Location = System::Drawing::Point(275, 89);
			this->underGraduateCourseRadio->Name = L"underGraduateCourseRadio";
			this->underGraduateCourseRadio->Size = System::Drawing::Size(59, 16);
			this->underGraduateCourseRadio->TabIndex = 5;
			this->underGraduateCourseRadio->TabStop = true;
			this->underGraduateCourseRadio->Text = L"������";
			this->underGraduateCourseRadio->UseVisualStyleBackColor = true;
			// 
			// graduateRadio
			// 
			this->graduateRadio->AutoSize = true;
			this->graduateRadio->Location = System::Drawing::Point(339, 89);
			this->graduateRadio->Name = L"graduateRadio";
			this->graduateRadio->Size = System::Drawing::Size(59, 16);
			this->graduateRadio->TabIndex = 6;
			this->graduateRadio->TabStop = true;
			this->graduateRadio->Text = L"˶ʿ��";
			this->graduateRadio->UseVisualStyleBackColor = true;
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(184, 146);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(85, 23);
			this->submitButton->TabIndex = 7;
			this->submitButton->Text = L"�� ��";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &addNewCourse::submitButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(35, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"�γ̴��룺";
			// 
			// courseCodeTbox
			// 
			this->courseCodeTbox->Location = System::Drawing::Point(99, 85);
			this->courseCodeTbox->Name = L"courseCodeTbox";
			this->courseCodeTbox->Size = System::Drawing::Size(100, 21);
			this->courseCodeTbox->TabIndex = 1;
			// 
			// addNewCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 201);
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
			this->Name = L"addNewCourse";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		AcademicStaff *staff = new AcademicStaff();
		Course *p = new Course();
		char courseCode[20]; //�γ̴���
		char courseName[20]; //�γ���
		int credit;
		int type;
		sprintf(courseCode, "%s", courseCodeTbox->Text);
		sprintf(courseName, "%s", courseNameTbox->Text);
		credit = Convert::ToInt16(courseCreditTbox->Text->ToString());
		if (underGraduateCourseRadio->Checked) type = (int)UserTypeCode::USER_UNDERGRADUATE; //������
		else type = (int)UserTypeCode::USER_GRADUATE;
		p->setCredit(credit);
		p->setCourseCode(courseCode);
		p->setCourseName(courseName);
		p->setType(type);
		//��ӿγ�
		if (staff->writeCourse(p)) {
			MessageBox::Show("��ӳɹ�!");
		}
		delete p,staff;
	}
};
}
