#pragma once

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// addMajor 摘要
	/// </summary>
	public ref class addMajor : public System::Windows::Forms::Form
	{
	public:
		addMajor(void)
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
		~addMajor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  submitButton;
	private: System::Windows::Forms::TextBox^  tb_requiredScore;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_majorName;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  l_majorCode;
	private: System::Windows::Forms::TextBox^  tb_majorCode;
	private: System::Windows::Forms::RadioButton^  underGraduateRadio;
	private: System::Windows::Forms::RadioButton^  radioButton2;

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
			this->tb_requiredScore = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_majorName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->l_majorCode = (gcnew System::Windows::Forms::Label());
			this->tb_majorCode = (gcnew System::Windows::Forms::TextBox());
			this->underGraduateRadio = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(496, 26);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(75, 23);
			this->submitButton->TabIndex = 9;
			this->submitButton->Text = L"确  定";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &addMajor::submitButton_Click);
			// 
			// tb_requiredScore
			// 
			this->tb_requiredScore->Location = System::Drawing::Point(345, 27);
			this->tb_requiredScore->Name = L"tb_requiredScore";
			this->tb_requiredScore->Size = System::Drawing::Size(104, 21);
			this->tb_requiredScore->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(250, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 12);
			this->label2->TabIndex = 7;
			this->label2->Text = L"毕业所需学分：";
			// 
			// tb_majorName
			// 
			this->tb_majorName->Location = System::Drawing::Point(98, 27);
			this->tb_majorName->Name = L"tb_majorName";
			this->tb_majorName->Size = System::Drawing::Size(100, 21);
			this->tb_majorName->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 12);
			this->label1->TabIndex = 5;
			this->label1->Text = L"专业名称：";
			// 
			// l_majorCode
			// 
			this->l_majorCode->AutoSize = true;
			this->l_majorCode->Location = System::Drawing::Point(26, 72);
			this->l_majorCode->Name = L"l_majorCode";
			this->l_majorCode->Size = System::Drawing::Size(65, 12);
			this->l_majorCode->TabIndex = 10;
			this->l_majorCode->Text = L"专业代码：";
			// 
			// tb_majorCode
			// 
			this->tb_majorCode->Location = System::Drawing::Point(98, 66);
			this->tb_majorCode->Name = L"tb_majorCode";
			this->tb_majorCode->Size = System::Drawing::Size(100, 21);
			this->tb_majorCode->TabIndex = 6;
			// 
			// underGraduateRadio
			// 
			this->underGraduateRadio->AutoSize = true;
			this->underGraduateRadio->Location = System::Drawing::Point(252, 72);
			this->underGraduateRadio->Name = L"underGraduateRadio";
			this->underGraduateRadio->Size = System::Drawing::Size(59, 16);
			this->underGraduateRadio->TabIndex = 11;
			this->underGraduateRadio->TabStop = true;
			this->underGraduateRadio->Text = L"本科生";
			this->underGraduateRadio->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(345, 72);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(59, 16);
			this->radioButton2->TabIndex = 11;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"硕士生";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// addMajor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(627, 123);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->underGraduateRadio);
			this->Controls->Add(this->l_majorCode);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->tb_requiredScore);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb_majorCode);
			this->Controls->Add(this->tb_majorName);
			this->Controls->Add(this->label1);
			this->Name = L"addMajor";
			this->Text = L"新增专业";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e) {
		AcademicStaff *staff = new AcademicStaff();
		Major *p = new Major();
		int type,score;
		if (underGraduateRadio->Checked) type = (int)UserTypeCode::USER_UNDERGRADUATE; //本科生
		else type = (int)UserTypeCode::USER_GRADUATE;
		score = Convert::ToInt16(tb_requiredScore->Text->ToString());
		p->setMajorCode((char*)(Marshal::StringToHGlobalAnsi(tb_majorCode->Text)).ToPointer());
		p->setMajorName((char*)(Marshal::StringToHGlobalAnsi(tb_majorName->Text)).ToPointer());
		p->setType(type);
		p->setRequiredScore(score);
		if (staff->writeMajor(p)) {
			MessageBox::Show("添加成功...");
		}
		delete staff, p;
	}
};
}
