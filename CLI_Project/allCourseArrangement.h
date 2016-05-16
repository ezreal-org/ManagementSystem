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
	/// allCourseArrangement ժҪ
	/// </summary>
	public ref class allCourseArrangement : public System::Windows::Forms::Form
	{
	public:
		//5-9 �ſα������ĳɿγ̴���+��ʦ����
		allCourseArrangement(int type) //����typeȷ���������ſλ����޸��ſ�,0��������
		{
			this->type = type;
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~allCourseArrangement()
		{
			if (components)
			{
				delete components;
			}
		}
	private:int type;
	private: System::Windows::Forms::TextBox^  tb_classRoom;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tb_classTime;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  arrangeButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  courseArrangementList;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox_teacher;
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
			this->deleteButton = (gcnew System::Windows::Forms::Button());
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
			this->label3->Text = L"����λ�ã�";
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
			this->groupBox1->Text = L"�ſ���Ϣ";
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
			this->label4->Text = L"�ον�ʦ��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 12);
			this->label2->TabIndex = 6;
			this->label2->Text = L"�Ͽ�ʱ�䣺";
			// 
			// arrangeButton
			// 
			this->arrangeButton->Location = System::Drawing::Point(421, 197);
			this->arrangeButton->Name = L"arrangeButton";
			this->arrangeButton->Size = System::Drawing::Size(75, 23);
			this->arrangeButton->TabIndex = 10;
			this->arrangeButton->Text = L"�ſ�";
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
			this->label1->Text = L"�γ��б�";
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
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(314, 197);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 10;
			this->deleteButton->Text = L"ɾ��";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &allCourseArrangement::deleteButton_Click);
			// 
			// allCourseArrangement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(577, 239);
			this->Controls->Add(this->courseArrangementList);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->arrangeButton);
			this->Controls->Add(this->label1);
			this->Name = L"allCourseArrangement";
			this->Text = L"�ſ�";
			this->Load += gcnew System::EventHandler(this, &allCourseArrangement::allCourseArrangement_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void initCourseArrangementList()
		{
			this->courseArrangementList->Items->Clear();
			AcademicStaff *staff = new AcademicStaff();
			string courseName;
			char courseId[20];
			cli::array<String ^> ^list = staff->getAllCourseId();
			for each (String ^a in list) {
				sprintf(courseId, "%s", a);
				courseName = staff->readCourseInfo(courseId)->getCourseName();
				a += " ";
				a += gcnew String(courseName.c_str());
				this->courseArrangementList->Items->Add(a);
			}
			delete staff;
		}
	private: System::Void allCourseArrangement_Load(System::Object^  sender, System::EventArgs^  e) {
		//��courseArrangementList��ʾ�����ſα�ժҪ��Ϣ
		initCourseArrangementList();

		//��ʼ���ο���ʦ����ѡ��
		string teaName;
		char teacherId[20];
		AcademicStaff *staff = new AcademicStaff();
		comboBox_teacher->Items->Clear();
		comboBox_teacher->Items->Add("--ѡ���ον�ʦ--");
		cli::array<String ^> ^list = staff->getAllTeacherId();
		for each(String ^tid in list) {
			sprintf(teacherId, "%s", tid);
			teaName = staff->readTeacherInfo(teacherId)->getName();
			tid += "_";
			tid += gcnew String(teaName.c_str());
			comboBox_teacher->Items->Add(tid);
		}

		delete staff;
	}
			 // 5-9 �ſα������޸�
	private: System::Void courseArrangementList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (!type) {  //�����ſ�ʱ
			tb_classRoom->Text = "";
			tb_classTime->Text = "";
			this->comboBox_teacher->SelectedIndex = 0;
			return;
		}
		char cIdTid[20];
		string strTemp;
		String ^courseIdTeaId, ^teaId;
		AcademicStaff *staff = new AcademicStaff();
		//��ȡ�γ�id
		courseIdTeaId = courseArrangementList->SelectedItem->ToString()->Substring(0, courseArrangementList->SelectedItem->ToString()->IndexOf(","));
		sprintf(cIdTid, "%s", courseIdTeaId);
		courseArrangement *p = staff->readCourseArrangement(cIdTid);
		//��ʼ���ο���ʦCombox
		this->comboBox_teacher->SelectedIndex = 0;
		tb_classRoom->Text = "";
		tb_classTime->Text = "";
		if (p != nullptr) {
			strTemp = p->getTeacherId();
			teaId = gcnew String(strTemp.c_str());
			//ѡ��ָ�����ον�ʦ
			for (int i = 0; i < comboBox_teacher->Items->Count; i++) {
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
			MessageBox::Show("�ſγɹ�...");
		}
		delete staff, p;
	}
			 // 5-9 �޸��ſα�����
	private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		char cIdTid[20];
		sprintf(cIdTid, "%s", courseArrangementList->SelectedItem->ToString()->Substring(0, courseArrangementList->SelectedItem->ToString()->IndexOf(",")));
		AcademicStaff *staff = new AcademicStaff();
		if (staff->deleteCourseArrangement(cIdTid)) {
			MessageBox::Show("ɾ���ɹ�...");
			tb_classRoom->Text = "";
			tb_classTime->Text = "";
		}
		initCourseArrangementList(); //�����ſ��б�
		delete staff;
	}
};
}
