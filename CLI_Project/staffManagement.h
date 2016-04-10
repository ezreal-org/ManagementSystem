#pragma once
#include "typeDefinition.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// staffManagement 摘要
	/// </summary>
	public ref class staffManagement : public System::Windows::Forms::Form
	{
	public:
		staffManagement(void)
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
		~staffManagement()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^  staffCheckedList;
	private: System::Windows::Forms::Button^  deleteButton;
	private: System::Windows::Forms::Button^  addButton;
	protected:



	private: System::Windows::Forms::TextBox^  idTbox;
	private: System::Windows::Forms::RadioButton^  academicStaffRadio;
	private: System::Windows::Forms::RadioButton^  teaRadio;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  l_logout;
	private: System::Windows::Forms::Panel^  academicStaffPanel;
	private: System::Windows::Forms::TextBox^  departNameTBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  AcaStaffNameTBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  teaPanel;
	private: System::Windows::Forms::TextBox^  teaTitleTbox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  teaNameTbox;
	private: System::Windows::Forms::Label^  label5;


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
			this->staffCheckedList = (gcnew System::Windows::Forms::CheckedListBox());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->idTbox = (gcnew System::Windows::Forms::TextBox());
			this->academicStaffRadio = (gcnew System::Windows::Forms::RadioButton());
			this->teaRadio = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->l_logout = (gcnew System::Windows::Forms::Label());
			this->academicStaffPanel = (gcnew System::Windows::Forms::Panel());
			this->departNameTBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->AcaStaffNameTBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->teaPanel = (gcnew System::Windows::Forms::Panel());
			this->teaTitleTbox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->teaNameTbox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->academicStaffPanel->SuspendLayout();
			this->teaPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// staffCheckedList
			// 
			this->staffCheckedList->CheckOnClick = true;
			this->staffCheckedList->Font = (gcnew System::Drawing::Font(L"楷体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->staffCheckedList->FormattingEnabled = true;
			this->staffCheckedList->Location = System::Drawing::Point(26, 120);
			this->staffCheckedList->Name = L"staffCheckedList";
			this->staffCheckedList->Size = System::Drawing::Size(253, 67);
			this->staffCheckedList->TabIndex = 0;
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(291, 137);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 1;
			this->deleteButton->Text = L"删除";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &staffManagement::deleteButton_Click);
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(291, 22);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(75, 23);
			this->addButton->TabIndex = 2;
			this->addButton->Text = L"添加";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &staffManagement::addButton_Click);
			// 
			// idTbox
			// 
			this->idTbox->Location = System::Drawing::Point(60, 24);
			this->idTbox->Name = L"idTbox";
			this->idTbox->Size = System::Drawing::Size(100, 21);
			this->idTbox->TabIndex = 3;
			// 
			// academicStaffRadio
			// 
			this->academicStaffRadio->AutoSize = true;
			this->academicStaffRadio->Location = System::Drawing::Point(167, 26);
			this->academicStaffRadio->Name = L"academicStaffRadio";
			this->academicStaffRadio->Size = System::Drawing::Size(59, 16);
			this->academicStaffRadio->TabIndex = 4;
			this->academicStaffRadio->TabStop = true;
			this->academicStaffRadio->Text = L"教务员";
			this->academicStaffRadio->UseVisualStyleBackColor = true;
			this->academicStaffRadio->CheckedChanged += gcnew System::EventHandler(this, &staffManagement::academicStaffRadio_CheckedChanged);
			// 
			// teaRadio
			// 
			this->teaRadio->AutoSize = true;
			this->teaRadio->Location = System::Drawing::Point(232, 26);
			this->teaRadio->Name = L"teaRadio";
			this->teaRadio->Size = System::Drawing::Size(47, 16);
			this->teaRadio->TabIndex = 4;
			this->teaRadio->TabStop = true;
			this->teaRadio->Text = L"教师";
			this->teaRadio->UseVisualStyleBackColor = true;
			this->teaRadio->CheckedChanged += gcnew System::EventHandler(this, &staffManagement::teaRadio_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 5;
			this->label1->Text = L"工号";
			// 
			// l_logout
			// 
			this->l_logout->AutoSize = true;
			this->l_logout->ForeColor = System::Drawing::Color::DimGray;
			this->l_logout->Location = System::Drawing::Point(368, 4);
			this->l_logout->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->l_logout->Name = L"l_logout";
			this->l_logout->Size = System::Drawing::Size(29, 12);
			this->l_logout->TabIndex = 6;
			this->l_logout->Text = L"注销";
			this->l_logout->Click += gcnew System::EventHandler(this, &staffManagement::l_logout_Click);
			// 
			// academicStaffPanel
			// 
			this->academicStaffPanel->Controls->Add(this->departNameTBox);
			this->academicStaffPanel->Controls->Add(this->label3);
			this->academicStaffPanel->Controls->Add(this->AcaStaffNameTBox);
			this->academicStaffPanel->Controls->Add(this->label2);
			this->academicStaffPanel->Location = System::Drawing::Point(12, 57);
			this->academicStaffPanel->Name = L"academicStaffPanel";
			this->academicStaffPanel->Size = System::Drawing::Size(354, 57);
			this->academicStaffPanel->TabIndex = 7;
			// 
			// departNameTBox
			// 
			this->departNameTBox->Location = System::Drawing::Point(220, 17);
			this->departNameTBox->Name = L"departNameTBox";
			this->departNameTBox->Size = System::Drawing::Size(100, 21);
			this->departNameTBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(175, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"部门";
			// 
			// AcaStaffNameTBox
			// 
			this->AcaStaffNameTBox->Location = System::Drawing::Point(48, 18);
			this->AcaStaffNameTBox->Name = L"AcaStaffNameTBox";
			this->AcaStaffNameTBox->Size = System::Drawing::Size(100, 21);
			this->AcaStaffNameTBox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 0;
			this->label2->Text = L"姓名";
			// 
			// teaPanel
			// 
			this->teaPanel->Controls->Add(this->teaTitleTbox);
			this->teaPanel->Controls->Add(this->label4);
			this->teaPanel->Controls->Add(this->teaNameTbox);
			this->teaPanel->Controls->Add(this->label5);
			this->teaPanel->Location = System::Drawing::Point(12, 57);
			this->teaPanel->Name = L"teaPanel";
			this->teaPanel->Size = System::Drawing::Size(354, 57);
			this->teaPanel->TabIndex = 8;
			// 
			// teaTitleTbox
			// 
			this->teaTitleTbox->Location = System::Drawing::Point(220, 17);
			this->teaTitleTbox->Name = L"teaTitleTbox";
			this->teaTitleTbox->Size = System::Drawing::Size(100, 21);
			this->teaTitleTbox->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(175, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 12);
			this->label4->TabIndex = 2;
			this->label4->Text = L"职称";
			// 
			// teaNameTbox
			// 
			this->teaNameTbox->Location = System::Drawing::Point(48, 18);
			this->teaNameTbox->Name = L"teaNameTbox";
			this->teaNameTbox->Size = System::Drawing::Size(100, 21);
			this->teaNameTbox->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 12);
			this->label5->TabIndex = 0;
			this->label5->Text = L"姓名";
			// 
			// staffManagement
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(420, 205);
			this->Controls->Add(this->teaPanel);
			this->Controls->Add(this->academicStaffPanel);
			this->Controls->Add(this->l_logout);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->teaRadio);
			this->Controls->Add(this->academicStaffRadio);
			this->Controls->Add(this->idTbox);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->staffCheckedList);
			this->Name = L"staffManagement";
			this->Text = L"职工管理";
			this->Load += gcnew System::EventHandler(this, &staffManagement::staffManagement_Load);
			this->academicStaffPanel->ResumeLayout(false);
			this->academicStaffPanel->PerformLayout();
			this->teaPanel->ResumeLayout(false);
			this->teaPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void l_logout_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::OpenForms["loginForm1"]->Show();
		this->Hide();
	}
	private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Admin admin;
		if (academicStaffRadio->Checked) {
			AcademicStaffTable *p = new AcademicStaffTable();
			p->setId((char*)Marshal::StringToHGlobalAnsi(idTbox->Text).ToPointer());
			p->setType(1);
			p->setPasswd("abc123");
			p->setName((char*)Marshal::StringToHGlobalAnsi(AcaStaffNameTBox->Text).ToPointer());
			p->setDepartment((char*)Marshal::StringToHGlobalAnsi(departNameTBox->Text).ToPointer());
			if (admin.addAcademicStaff(p)) {
				MessageBox::Show("添加成功");
			}
			delete p;
		}
		else {
			TeacherTable *p = new TeacherTable();
			p->setId((char*)Marshal::StringToHGlobalAnsi(idTbox->Text).ToPointer());
			p->setType(2);
			p->setPasswd("abc123");
			p->setName((char*)Marshal::StringToHGlobalAnsi(teaNameTbox->Text).ToPointer());
			p->setTeacherTitle((char*)Marshal::StringToHGlobalAnsi(teaTitleTbox->Text).ToPointer());
			if (admin.addTeacher(p)) {
				MessageBox::Show("添加成功");
			}
			delete p;
		}
		updateList();
	}
	private:void updateList()
	{
		char id[20];
		staffCheckedList->Items->Clear();
		Admin *admin = new Admin();
		cli::array<String^>^ list = admin->getAllStaffId();
		for each(String ^item in list)
		{
			sprintf(id, "%s", item);
			if (admin->readStaffBasicInfo(id)->getType() == (int)UserTypeCode::USER_ACADEMICSTAFF) item += " 教务员";
			else item += " 教师";
			staffCheckedList->Items->Add(item);
		}
	}
	private: System::Void staffManagement_Load(System::Object^  sender, System::EventArgs^  e) {
		updateList();
		academicStaffRadio->Checked = true;
		this->teaPanel->Visible = false;
		this->academicStaffPanel->Visible = true;
	}
	private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Admin *admin = new Admin();
		String ^idStr;
		int successCount = 0;
		for (int i = 0; i < staffCheckedList->CheckedIndices->Count; i++) {
			idStr = staffCheckedList->Items[staffCheckedList->CheckedIndices[i]]->ToString();
			idStr = idStr->Substring(0, idStr->IndexOf(" "));
			successCount += admin->deleteAccount((char*)Marshal::StringToHGlobalAnsi(idStr).ToPointer());
		}
		if (successCount == staffCheckedList->CheckedIndices->Count) {
			MessageBox::Show("删除成功");
		}	
		updateList();
		delete admin;
	}
	private: System::Void academicStaffRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->academicStaffRadio->Checked) {
			this->teaPanel->Visible = false;
			this->academicStaffPanel->Visible = true;
		}
	}
	private: System::Void teaRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->teaRadio->Checked) {
			this->teaPanel->Visible = true;
			this->academicStaffPanel->Visible = false;
		}
	}
	};
}
