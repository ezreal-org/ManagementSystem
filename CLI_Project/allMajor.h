#pragma once

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// allMajor ժҪ
	/// </summary>
	public ref class allMajor : public System::Windows::Forms::Form
	{
	public:
		allMajor(void)
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
		~allMajor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  M_CreditBox;
	protected: 
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  M_NameBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  modifyButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  majorList;
	private: System::Windows::Forms::Button^  deleteButton;



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
			this->M_CreditBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->M_NameBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->modifyButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->majorList = (gcnew System::Windows::Forms::ListBox());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// M_CreditBox
			// 
			this->M_CreditBox->Location = System::Drawing::Point(92, 70);
			this->M_CreditBox->Name = L"M_CreditBox";
			this->M_CreditBox->Size = System::Drawing::Size(103, 21);
			this->M_CreditBox->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 12);
			this->label3->TabIndex = 8;
			this->label3->Text = L"����ѧ�֣�";
			// 
			// M_NameBox
			// 
			this->M_NameBox->Location = System::Drawing::Point(92, 30);
			this->M_NameBox->Name = L"M_NameBox";
			this->M_NameBox->Size = System::Drawing::Size(103, 21);
			this->M_NameBox->TabIndex = 7;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->M_CreditBox);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->M_NameBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(241, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(217, 120);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��ϸ��Ϣ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 6;
			this->label2->Text = L"רҵ���ƣ�";
			// 
			// modifyButton
			// 
			this->modifyButton->Location = System::Drawing::Point(361, 165);
			this->modifyButton->Name = L"modifyButton";
			this->modifyButton->Size = System::Drawing::Size(75, 23);
			this->modifyButton->TabIndex = 10;
			this->modifyButton->Text = L"�޸�";
			this->modifyButton->UseVisualStyleBackColor = true;
			this->modifyButton->Click += gcnew System::EventHandler(this, &allMajor::modifyButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 12);
			this->label1->TabIndex = 9;
			this->label1->Text = L"רҵ�б�";
			// 
			// majorList
			// 
			this->majorList->FormattingEnabled = true;
			this->majorList->ItemHeight = 12;
			this->majorList->Location = System::Drawing::Point(26, 39);
			this->majorList->Name = L"majorList";
			this->majorList->Size = System::Drawing::Size(199, 136);
			this->majorList->TabIndex = 12;
			this->majorList->SelectedIndexChanged += gcnew System::EventHandler(this, &allMajor::majorList_SelectedIndexChanged);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(264, 165);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 10;
			this->deleteButton->Text = L"ɾ��";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &allMajor::deleteButton_Click);
			// 
			// allMajor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(494, 197);
			this->Controls->Add(this->majorList);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->modifyButton);
			this->Controls->Add(this->label1);
			this->Name = L"allMajor";
			this->Text = L"����רҵ";
			this->Load += gcnew System::EventHandler(this, &allMajor::allMajor_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void initMajorList() //��majorList��ʾ����רҵժҪ��Ϣ
		{
			this->majorList->Items->Clear();
			AcademicStaff *staff = new AcademicStaff();
			string name;
			char id[20];
			cli::array<String ^> ^list = staff->getAllMajorSummarayInfo();
			for each (String ^a in list) {
				sprintf(id, "%s", a);
				name = staff->readMajorInfo(id)->getMajorName();
				a += " ";
				a += gcnew String(name.c_str());
				this->majorList->Items->Add(a);
			}
			if (this->majorList->Items->Count > 0) {
				this->majorList->SelectedIndex = 0;
			}
			delete staff;
		}
#pragma endregion
	private: System::Void allMajor_Load(System::Object^  sender, System::EventArgs^  e) {
		//��majorList��ʾ����רҵժҪ��Ϣ
		initMajorList();
	}
private: System::Void majorList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	char id[50],scoreArray[20];
	//��ȡרҵID�ֶ�
	sprintf(id, "%s", majorList->SelectedItem->ToString()->Substring(0, majorList->SelectedItem->ToString()->IndexOf(" ")));
	AcademicStaff *staff = new AcademicStaff();
	Major *p = staff->readMajorInfo(id);
	string strTemp;
	strTemp = p->getMajorName();
	M_NameBox->Text = gcnew String(strTemp.c_str());
	sprintf(scoreArray, "%d", p->getRequiredScore());
	strTemp = scoreArray;
	M_CreditBox->Text = gcnew String(strTemp.c_str());
	delete staff;
}
private: System::Void modifyButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char id[50];
	int score;
	char majorName[50];
	//��ȡרҵid�ֶ�
	sprintf(id, "%s", majorList->SelectedItem->ToString()->Substring(0, majorList->SelectedItem->ToString()->IndexOf(" ")));
	AcademicStaff *staff = new AcademicStaff();
	Major *p = staff->readMajorInfo(id);
	sprintf(majorName, "%s", M_NameBox->Text);
	score = Convert::ToInt16(this->M_CreditBox->Text->ToString());
	p->setMajorName(majorName);
	p->setRequiredScore(score);
	if (staff->writeMajor(p)) {
		MessageBox::Show("�޸ĳɹ�...");
	}
	delete staff,p;
}
private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	char id[50];
	sprintf(id, "%s", majorList->SelectedItem->ToString()->Substring(0, majorList->SelectedItem->ToString()->IndexOf(" ")));
	AcademicStaff *staff = new AcademicStaff();
	if (staff->deleteMajor(id)) {
		MessageBox::Show("ɾ���ɹ�...");
	}
	initMajorList(); //����רҵ�б�
	delete staff;
}
};
}
