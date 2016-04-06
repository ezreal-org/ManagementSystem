#pragma once
#include "storage.h"
#include "memberInfo.h"
#include "memberService.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	/// <summary>
	/// addStu 晡猁
	/// </summary>
	public ref class addStu : public System::Windows::Forms::Form
	{
	public:
		addStu(void)
		{
			InitializeComponent();
			stuInfo->TabPages->Remove(graduatesPage);
			stuInfo->TabPages->Remove(undergradePage);
			//
			//TODO:  婓森揭氝樓凳婖滲杅測鎢
			//
		}

	protected:
		/// <summary>
		/// ?燴垀衄淏婓妏蚚腔訧埭﹝
		/// </summary>
		~addStu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^  addedInfoPage;
	protected:

	protected:

	private: System::Windows::Forms::RichTextBox^  noteText;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::CheckBox^  isTalentCheckedBox;
	private: System::Windows::Forms::MaskedTextBox^  IDMaskedTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TabPage^  basicInfoPage;

	private: System::Windows::Forms::PictureBox^  photo;
	private: System::Windows::Forms::Button^  picBrowerButton;

	private: System::Windows::Forms::TextBox^  picTbox;
	private: System::Windows::Forms::TextBox^  noTbox;
	private: System::Windows::Forms::TextBox^  nameTbox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  genderCombox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  birthPicker;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TabControl^  stuInfo;
	private: System::Windows::Forms::Button^  resetButton;
	private: System::Windows::Forms::Button^  submitButton;
	private: System::Windows::Forms::OpenFileDialog^  picBrower;
	private: System::Windows::Forms::ComboBox^  typeOfStuCombox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TabPage^  undergradePage;
	private: System::Windows::Forms::TabPage^  graduatesPage;
	private: System::Windows::Forms::TextBox^  CEEMBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  highSchoolBox;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  reseaInteBox;
	private: System::Windows::Forms::TextBox^  graduateSchoolBox;
	private: System::Windows::Forms::TextBox^  tutorNameBox;
	private: System::Windows::Forms::TextBox^  entMarkBox;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ComboBox^  majorCombox;

	private: System::Windows::Forms::Label^  label15;

	private:
		/// <summary>
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// </summary>
		void InitializeComponent(void)
		{
			this->addedInfoPage = (gcnew System::Windows::Forms::TabPage());
			this->noteText = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->isTalentCheckedBox = (gcnew System::Windows::Forms::CheckBox());
			this->IDMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->basicInfoPage = (gcnew System::Windows::Forms::TabPage());
			this->majorCombox = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->typeOfStuCombox = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->photo = (gcnew System::Windows::Forms::PictureBox());
			this->picBrowerButton = (gcnew System::Windows::Forms::Button());
			this->picTbox = (gcnew System::Windows::Forms::TextBox());
			this->noTbox = (gcnew System::Windows::Forms::TextBox());
			this->nameTbox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->genderCombox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->birthPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->stuInfo = (gcnew System::Windows::Forms::TabControl());
			this->undergradePage = (gcnew System::Windows::Forms::TabPage());
			this->highSchoolBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->CEEMBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->graduatesPage = (gcnew System::Windows::Forms::TabPage());
			this->reseaInteBox = (gcnew System::Windows::Forms::TextBox());
			this->graduateSchoolBox = (gcnew System::Windows::Forms::TextBox());
			this->tutorNameBox = (gcnew System::Windows::Forms::TextBox());
			this->entMarkBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->picBrower = (gcnew System::Windows::Forms::OpenFileDialog());
			this->addedInfoPage->SuspendLayout();
			this->basicInfoPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photo))->BeginInit();
			this->stuInfo->SuspendLayout();
			this->undergradePage->SuspendLayout();
			this->graduatesPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// addedInfoPage
			// 
			this->addedInfoPage->Controls->Add(this->noteText);
			this->addedInfoPage->Controls->Add(this->label7);
			this->addedInfoPage->Controls->Add(this->isTalentCheckedBox);
			this->addedInfoPage->Controls->Add(this->IDMaskedTextBox);
			this->addedInfoPage->Controls->Add(this->label6);
			this->addedInfoPage->Location = System::Drawing::Point(4, 26);
			this->addedInfoPage->Name = L"addedInfoPage";
			this->addedInfoPage->Padding = System::Windows::Forms::Padding(3);
			this->addedInfoPage->Size = System::Drawing::Size(577, 135);
			this->addedInfoPage->TabIndex = 1;
			this->addedInfoPage->Text = L"附加信息";
			this->addedInfoPage->UseVisualStyleBackColor = true;
			// 
			// noteText
			// 
			this->noteText->Location = System::Drawing::Point(87, 41);
			this->noteText->Name = L"noteText";
			this->noteText->Size = System::Drawing::Size(465, 88);
			this->noteText->TabIndex = 4;
			this->noteText->Text = L"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 58);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(72, 16);
			this->label7->TabIndex = 3;
			this->label7->Text = L"备注信息";
			// 
			// isTalentCheckedBox
			// 
			this->isTalentCheckedBox->AutoSize = true;
			this->isTalentCheckedBox->Location = System::Drawing::Point(317, 11);
			this->isTalentCheckedBox->Name = L"isTalentCheckedBox";
			this->isTalentCheckedBox->Size = System::Drawing::Size(107, 20);
			this->isTalentCheckedBox->TabIndex = 2;
			this->isTalentCheckedBox->Text = L"是否特长生";
			this->isTalentCheckedBox->UseVisualStyleBackColor = true;
			// 
			// IDMaskedTextBox
			// 
			this->IDMaskedTextBox->Location = System::Drawing::Point(100, 6);
			this->IDMaskedTextBox->Mask = L"000000-00000000-000A";
			this->IDMaskedTextBox->Name = L"IDMaskedTextBox";
			this->IDMaskedTextBox->Size = System::Drawing::Size(173, 26);
			this->IDMaskedTextBox->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 15);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 16);
			this->label6->TabIndex = 0;
			this->label6->Text = L"身份证号";
			// 
			// basicInfoPage
			// 
			this->basicInfoPage->Controls->Add(this->majorCombox);
			this->basicInfoPage->Controls->Add(this->label15);
			this->basicInfoPage->Controls->Add(this->typeOfStuCombox);
			this->basicInfoPage->Controls->Add(this->label8);
			this->basicInfoPage->Controls->Add(this->photo);
			this->basicInfoPage->Controls->Add(this->picBrowerButton);
			this->basicInfoPage->Controls->Add(this->picTbox);
			this->basicInfoPage->Controls->Add(this->noTbox);
			this->basicInfoPage->Controls->Add(this->nameTbox);
			this->basicInfoPage->Controls->Add(this->label5);
			this->basicInfoPage->Controls->Add(this->label4);
			this->basicInfoPage->Controls->Add(this->genderCombox);
			this->basicInfoPage->Controls->Add(this->label3);
			this->basicInfoPage->Controls->Add(this->label2);
			this->basicInfoPage->Controls->Add(this->birthPicker);
			this->basicInfoPage->Controls->Add(this->label1);
			this->basicInfoPage->Location = System::Drawing::Point(4, 26);
			this->basicInfoPage->Name = L"basicInfoPage";
			this->basicInfoPage->Padding = System::Windows::Forms::Padding(3);
			this->basicInfoPage->Size = System::Drawing::Size(577, 135);
			this->basicInfoPage->TabIndex = 0;
			this->basicInfoPage->Text = L"基本信息";
			this->basicInfoPage->UseVisualStyleBackColor = true;
			// 
			// majorCombox
			// 
			this->majorCombox->FormattingEnabled = true;
			this->majorCombox->Location = System::Drawing::Point(171, 54);
			this->majorCombox->Name = L"majorCombox";
			this->majorCombox->Size = System::Drawing::Size(94, 24);
			this->majorCombox->TabIndex = 27;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(130, 57);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(40, 16);
			this->label15->TabIndex = 26;
			this->label15->Text = L"专业";
			// 
			// typeOfStuCombox
			// 
			this->typeOfStuCombox->FormattingEnabled = true;
			this->typeOfStuCombox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"硕士生", L"本科生" });
			this->typeOfStuCombox->Location = System::Drawing::Point(52, 54);
			this->typeOfStuCombox->Name = L"typeOfStuCombox";
			this->typeOfStuCombox->Size = System::Drawing::Size(72, 24);
			this->typeOfStuCombox->TabIndex = 25;
			this->typeOfStuCombox->SelectedIndexChanged += gcnew System::EventHandler(this, &addStu::stuTypeCombox_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(40, 16);
			this->label8->TabIndex = 24;
			this->label8->Text = L"学历";
			// 
			// photo
			// 
			this->photo->Location = System::Drawing::Point(475, 15);
			this->photo->Name = L"photo";
			this->photo->Size = System::Drawing::Size(89, 103);
			this->photo->TabIndex = 23;
			this->photo->TabStop = false;
			// 
			// picBrowerButton
			// 
			this->picBrowerButton->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->picBrowerButton->Location = System::Drawing::Point(374, 95);
			this->picBrowerButton->Name = L"picBrowerButton";
			this->picBrowerButton->Size = System::Drawing::Size(75, 31);
			this->picBrowerButton->TabIndex = 22;
			this->picBrowerButton->Text = L"浏 览";
			this->picBrowerButton->UseVisualStyleBackColor = true;
			this->picBrowerButton->Click += gcnew System::EventHandler(this, &addStu::picBrowerButton_Click);
			// 
			// picTbox
			// 
			this->picTbox->Location = System::Drawing::Point(94, 95);
			this->picTbox->Name = L"picTbox";
			this->picTbox->Size = System::Drawing::Size(262, 26);
			this->picTbox->TabIndex = 21;
			// 
			// noTbox
			// 
			this->noTbox->Location = System::Drawing::Point(317, 53);
			this->noTbox->Name = L"noTbox";
			this->noTbox->Size = System::Drawing::Size(143, 26);
			this->noTbox->TabIndex = 19;
			// 
			// nameTbox
			// 
			this->nameTbox->Location = System::Drawing::Point(49, 13);
			this->nameTbox->Name = L"nameTbox";
			this->nameTbox->Size = System::Drawing::Size(94, 26);
			this->nameTbox->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(72, 16);
			this->label5->TabIndex = 20;
			this->label5->Text = L"头像信息";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(278, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 16);
			this->label4->TabIndex = 18;
			this->label4->Text = L"学号";
			// 
			// genderCombox
			// 
			this->genderCombox->FormattingEnabled = true;
			this->genderCombox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"男", L"女" });
			this->genderCombox->Location = System::Drawing::Point(200, 13);
			this->genderCombox->Name = L"genderCombox";
			this->genderCombox->Size = System::Drawing::Size(44, 24);
			this->genderCombox->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(156, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 16);
			this->label3->TabIndex = 16;
			this->label3->Text = L"性别";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(254, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 16);
			this->label2->TabIndex = 15;
			this->label2->Text = L"出生日期";
			// 
			// birthPicker
			// 
			this->birthPicker->Location = System::Drawing::Point(328, 14);
			this->birthPicker->Name = L"birthPicker";
			this->birthPicker->Size = System::Drawing::Size(132, 26);
			this->birthPicker->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"姓名";
			// 
			// stuInfo
			// 
			this->stuInfo->Controls->Add(this->basicInfoPage);
			this->stuInfo->Controls->Add(this->addedInfoPage);
			this->stuInfo->Controls->Add(this->undergradePage);
			this->stuInfo->Controls->Add(this->graduatesPage);
			this->stuInfo->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stuInfo->Location = System::Drawing::Point(11, 12);
			this->stuInfo->Name = L"stuInfo";
			this->stuInfo->SelectedIndex = 0;
			this->stuInfo->Size = System::Drawing::Size(585, 165);
			this->stuInfo->TabIndex = 0;
			// 
			// undergradePage
			// 
			this->undergradePage->Controls->Add(this->highSchoolBox);
			this->undergradePage->Controls->Add(this->label10);
			this->undergradePage->Controls->Add(this->CEEMBox);
			this->undergradePage->Controls->Add(this->label9);
			this->undergradePage->Location = System::Drawing::Point(4, 26);
			this->undergradePage->Name = L"undergradePage";
			this->undergradePage->Padding = System::Windows::Forms::Padding(3);
			this->undergradePage->Size = System::Drawing::Size(577, 135);
			this->undergradePage->TabIndex = 2;
			this->undergradePage->Text = L"本科生";
			this->undergradePage->UseVisualStyleBackColor = true;
			// 
			// highSchoolBox
			// 
			this->highSchoolBox->Location = System::Drawing::Point(87, 17);
			this->highSchoolBox->Name = L"highSchoolBox";
			this->highSchoolBox->Size = System::Drawing::Size(129, 26);
			this->highSchoolBox->TabIndex = 5;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(9, 22);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(72, 16);
			this->label10->TabIndex = 4;
			this->label10->Text = L"毕业高中";
			// 
			// CEEMBox
			// 
			this->CEEMBox->Location = System::Drawing::Point(317, 16);
			this->CEEMBox->Name = L"CEEMBox";
			this->CEEMBox->Size = System::Drawing::Size(57, 26);
			this->CEEMBox->TabIndex = 3;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(240, 21);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(72, 16);
			this->label9->TabIndex = 2;
			this->label9->Text = L"高考成绩";
			// 
			// graduatesPage
			// 
			this->graduatesPage->Controls->Add(this->reseaInteBox);
			this->graduatesPage->Controls->Add(this->graduateSchoolBox);
			this->graduatesPage->Controls->Add(this->tutorNameBox);
			this->graduatesPage->Controls->Add(this->entMarkBox);
			this->graduatesPage->Controls->Add(this->label14);
			this->graduatesPage->Controls->Add(this->label13);
			this->graduatesPage->Controls->Add(this->label12);
			this->graduatesPage->Controls->Add(this->label11);
			this->graduatesPage->Location = System::Drawing::Point(4, 26);
			this->graduatesPage->Name = L"graduatesPage";
			this->graduatesPage->Size = System::Drawing::Size(577, 135);
			this->graduatesPage->TabIndex = 3;
			this->graduatesPage->Text = L"硕士生";
			this->graduatesPage->UseVisualStyleBackColor = true;
			// 
			// reseaInteBox
			// 
			this->reseaInteBox->Location = System::Drawing::Point(368, 72);
			this->reseaInteBox->Name = L"reseaInteBox";
			this->reseaInteBox->Size = System::Drawing::Size(100, 26);
			this->reseaInteBox->TabIndex = 7;
			// 
			// graduateSchoolBox
			// 
			this->graduateSchoolBox->Location = System::Drawing::Point(368, 15);
			this->graduateSchoolBox->Name = L"graduateSchoolBox";
			this->graduateSchoolBox->Size = System::Drawing::Size(100, 26);
			this->graduateSchoolBox->TabIndex = 6;
			// 
			// tutorNameBox
			// 
			this->tutorNameBox->Location = System::Drawing::Point(111, 76);
			this->tutorNameBox->Name = L"tutorNameBox";
			this->tutorNameBox->Size = System::Drawing::Size(100, 26);
			this->tutorNameBox->TabIndex = 5;
			// 
			// entMarkBox
			// 
			this->entMarkBox->Location = System::Drawing::Point(111, 18);
			this->entMarkBox->Name = L"entMarkBox";
			this->entMarkBox->Size = System::Drawing::Size(100, 26);
			this->entMarkBox->TabIndex = 4;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(286, 78);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(72, 16);
			this->label14->TabIndex = 3;
			this->label14->Text = L"研究方向";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(283, 21);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(72, 16);
			this->label13->TabIndex = 2;
			this->label13->Text = L"毕业院校";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(30, 79);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(72, 16);
			this->label12->TabIndex = 1;
			this->label12->Text = L"导师姓名";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(27, 22);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(72, 16);
			this->label11->TabIndex = 0;
			this->label11->Text = L"入学成绩";
			// 
			// resetButton
			// 
			this->resetButton->Location = System::Drawing::Point(143, 186);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(75, 23);
			this->resetButton->TabIndex = 1;
			this->resetButton->Text = L"重 置";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &addStu::resetButton_Click);
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(297, 186);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(75, 23);
			this->submitButton->TabIndex = 2;
			this->submitButton->Text = L"确 定";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &addStu::submitStuInfo_Click);
			// 
			// picBrower
			// 
			this->picBrower->FileName = L"openFileDialog1";
			// 
			// addStu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(608, 221);
			this->Controls->Add(this->submitButton);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->stuInfo);
			this->Name = L"addStu";
			this->Text = L"学生注册";
			this->addedInfoPage->ResumeLayout(false);
			this->addedInfoPage->PerformLayout();
			this->basicInfoPage->ResumeLayout(false);
			this->basicInfoPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photo))->EndInit();
			this->stuInfo->ResumeLayout(false);
			this->undergradePage->ResumeLayout(false);
			this->undergradePage->PerformLayout();
			this->graduatesPage->ResumeLayout(false);
			this->graduatesPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void resetButton_Click(System::Object^  sender, System::EventArgs^  e) {
		//将所有的控件的值设为初始状态即可；
		this->nameTbox->Text = ""; 
		this->noTbox->Text = "";
		this->picTbox->Text = "";
		this->IDMaskedTextBox->Text = "";
		this->isTalentCheckedBox->Checked = false;
		this->noteText->Text = "";
		this->highSchoolBox->Text ="";
		this ->CEEMBox->Text="";
		this->entMarkBox->Text="";
		this->graduateSchoolBox->Text="";
		this->tutorNameBox->Text="";
		this->reseaInteBox->Text="";
	}
	private: System::Void picBrowerButton_Click(System::Object^  sender, System::EventArgs^  e) {
		picBrower->ShowDialog();
		picTbox->Text = picBrower->FileName;
		photo->ImageLocation = picTbox->Text;

	}
	private: System::Void submitStuInfo_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^name = nameTbox->Text;
		String ^birthStr = birthPicker->Text;
		int  gender = genderCombox->SelectedIndex;
		String ^ stuNo = noTbox->Text;
		String ^picPath = picTbox->Text;
		String ^idNo = IDMaskedTextBox->Text;
		idNo = idNo->Replace("-", "");
		String ^noteStr = noteText->Text;
		bool isTal = isTalentCheckedBox->Checked;
		int year, month, day;

		DateTime t;
		t = DateTime::Parse(birthStr);
		year = Convert::ToInt16(t.Year.ToString());
		month = Convert::ToInt16(t.Month.ToString());
		day = Convert::ToInt16(t.Day.ToString());

		AcademicStaff *staff = new AcademicStaff();
		if (typeOfStuCombox->SelectedIndex == 0) //硕士生
		{
			GraduateTable *pm1 = new GraduateTable();
			pm1->setId((char*)(Marshal::StringToHGlobalAnsi(stuNo)).ToPointer());
			pm1->setName((char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer());
			pm1->setSex(gender);
			pm1->setBirthday(year, month, day);
			pm1->setIdNumber((char*)(Marshal::StringToHGlobalAnsi(idNo)).ToPointer());
			pm1->setExtraInfo((char*)(Marshal::StringToHGlobalAnsi(noteStr)).ToPointer());
			pm1->setIsTalent(isTal);
			pm1->setMajor((char*)(Marshal::StringToHGlobalAnsi(majorCombox->Items[majorCombox->SelectedIndex]->ToString())).ToPointer());
			pm1->setPicpath((char*)(Marshal::StringToHGlobalAnsi(picPath)).ToPointer());
			pm1->setUndergraduateSchool((char*)(Marshal::StringToHGlobalAnsi(graduateSchoolBox->Text)).ToPointer());
			pm1->setSupervisorName((char*)(Marshal::StringToHGlobalAnsi(tutorNameBox->Text)).ToPointer());
			pm1->setResearchInterests((char*)(Marshal::StringToHGlobalAnsi(reseaInteBox->Text)).ToPointer());
			pm1->setEntranceScore(Convert::ToInt16(this->entMarkBox->Text->ToString()));
			pm1->setType(3);
			if (staff->writeGraduate(pm1) && staff->writeInitLoginInfo(pm1->getId(), "123456", 3)) {
				MessageBox::Show("添加成功!");
			}
			delete pm1;
		}
		else
		{
			UndergraduateTable *pm1 = new UndergraduateTable();
			pm1->setId((char*)(Marshal::StringToHGlobalAnsi(stuNo)).ToPointer());
			pm1->setName((char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer());
			pm1->setSex(gender);
			pm1->setBirthday(year, month, day);
			pm1->setIdNumber((char*)(Marshal::StringToHGlobalAnsi(idNo)).ToPointer());
			pm1->setExtraInfo((char*)(Marshal::StringToHGlobalAnsi(noteStr)).ToPointer());
			pm1->setIsTalent(isTal);
			pm1->setMajor((char*)(Marshal::StringToHGlobalAnsi(majorCombox->Items[majorCombox->SelectedIndex]->ToString())).ToPointer());
			pm1->setPicpath((char*)(Marshal::StringToHGlobalAnsi(picPath)).ToPointer());
			pm1->setSchoolName((char*)(Marshal::StringToHGlobalAnsi(highSchoolBox->Text)).ToPointer());
			pm1->setScore(Convert::ToInt16(this->CEEMBox->Text->ToString()));
			pm1->setType(4);
			if (staff->writeUndergraduate(pm1) && staff->writeInitLoginInfo(pm1->getId(), "123456", 4)) {
				MessageBox::Show("添加成功!");
			}
			delete pm1;
		}
		delete staff;
	}

	private: System::Void stuTypeCombox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int index = typeOfStuCombox->SelectedIndex;
		stuInfo->TabPages->Remove(graduatesPage);
		stuInfo->TabPages->Remove(undergradePage);
		if (index == 0) {
			stuInfo->TabPages->Add(graduatesPage);
		}
		else {
			stuInfo->TabPages->Add(undergradePage);
		}
		//初始化专业列表
		majorCombox->Items->Clear();
		AcademicStaff *staff = new AcademicStaff();
		Major *p;
		char idName[50];
		string strTemp;
		cli::array<String ^> ^list = staff->getAllMajorSummarayInfo();
		for each (String ^a in list){
			sprintf(idName, "%s", a);
			p = staff->readMajorInfo(idName);
			if (p->getType() - 3 == index) //约定硕士生、本科生type依次为3，4
			{
				strTemp = p->getMajorName();
				majorCombox->Items->Add(gcnew String(strTemp.c_str()));
			}
		}
		majorCombox->SelectedIndex = 0;
		delete staff;
	}
};
}
