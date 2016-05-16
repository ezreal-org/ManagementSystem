#pragma once
#include "addNewCourse.h"
#include "recordGrade.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// teaIndexForm ժҪ
	/// </summary>
	public ref class teaIndexForm : public System::Windows::Forms::Form
	{
	public:
		teaIndexForm(UserTable *login)
		{
			thisLogin = login;
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~teaIndexForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;

	private: System::Windows::Forms::Button^  recordGradeButton;
	private: System::Windows::Forms::Button^  checkAllGradeButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Label^  label1;

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
			this->recordGradeButton = (gcnew System::Windows::Forms::Button());
			this->checkAllGradeButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// recordGradeButton
			// 
			this->recordGradeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->recordGradeButton->Location = System::Drawing::Point(54, 41);
			this->recordGradeButton->Name = L"recordGradeButton";
			this->recordGradeButton->Size = System::Drawing::Size(142, 36);
			this->recordGradeButton->TabIndex = 3;
			this->recordGradeButton->Text = L"¼��ɼ�";
			this->recordGradeButton->UseVisualStyleBackColor = true;
			this->recordGradeButton->Click += gcnew System::EventHandler(this, &teaIndexForm::recordGradeButton_Click);
			// 
			// checkAllGradeButton
			// 
			this->checkAllGradeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->checkAllGradeButton->Location = System::Drawing::Point(263, 41);
			this->checkAllGradeButton->Name = L"checkAllGradeButton";
			this->checkAllGradeButton->Size = System::Drawing::Size(142, 36);
			this->checkAllGradeButton->TabIndex = 4;
			this->checkAllGradeButton->Text = L"�ɼ��ֲ�";
			this->checkAllGradeButton->UseVisualStyleBackColor = true;
			this->checkAllGradeButton->Click += gcnew System::EventHandler(this, &teaIndexForm::checkAllGradeButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->exitButton->Location = System::Drawing::Point(465, 41);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(142, 36);
			this->exitButton->TabIndex = 5;
			this->exitButton->Text = L"ע��";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &teaIndexForm::exitButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(575, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 12);
			this->label1->TabIndex = 6;
			this->label1->Text = L"label1";
			// 
			// teaIndexForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(693, 128);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->checkAllGradeButton);
			this->Controls->Add(this->recordGradeButton);
			this->Name = L"teaIndexForm";
			this->Text = L"���׽������ϵͳ - ��ʦ��";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &teaIndexForm::teaIndexForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &teaIndexForm::teaIndexForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void recordGradeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		recordGrade ^record = gcnew recordGrade(thisLogin);
		record->Show();
			 }
	private: System::Void teaIndexForm_Load(System::Object^  sender, System::EventArgs^  e) {
		string strTemp;
		strTemp = thisLogin->getId();
		this->label1->Text = "��ӭ ";
		this->label1->Text += gcnew String(strTemp.c_str());
			 }
private: System::Void teaIndexForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	Application::Exit();
}
private: System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::OpenForms["loginForm1"]->Show();
	this->Hide();
}
private: System::Void checkAllGradeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		  MessageBox::Show("��ģ�齫�ں����½�ʵ��");
		 }
};
}
