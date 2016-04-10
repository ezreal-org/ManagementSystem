#pragma once
#include "storage.h"
#include <iostream>
#include <string>
namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// stuList 摘要
	/// </summary>
	public ref class stuList : public System::Windows::Forms::Form
	{
	public:
		stuList(void)
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
		~stuList()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^  showInfoPanel;
	private: System::Windows::Forms::Button^  modifyButton;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;






































	private: System::Windows::Forms::Button^  delete_button;
	private: System::Windows::Forms::ComboBox^  stuListTypeCombox;
	private: System::Windows::Forms::ListView^  lv_allStu;
	private: System::Windows::Forms::ColumnHeader^  idNum;
	private: System::Windows::Forms::ColumnHeader^  name;
	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::TabControl^  stuInfo;
	private:
	private: System::Windows::Forms::TabPage^  basicInfo;
	public:
	private: System::Windows::Forms::TextBox^  tb_major;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::PictureBox^  photo;
	private: System::Windows::Forms::Button^  lookButton;
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
	private: System::Windows::Forms::TabPage^  addInfo;
	private: System::Windows::Forms::RichTextBox^  noteText;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::CheckBox^  isTalent;
	private: System::Windows::Forms::MaskedTextBox^  IDMaskedTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TabPage^  undergradePage;
	private: System::Windows::Forms::TextBox^  highSchoolBox;
	private: System::Windows::Forms::TextBox^  CEEMBox;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TabPage^  graduatesPage;
	private: System::Windows::Forms::TextBox^  reseaInteBox;
	private: System::Windows::Forms::TextBox^  graduateSchoolBox;
	private: System::Windows::Forms::TextBox^  tutorNameBox;
	private: System::Windows::Forms::TextBox^  entMarkBox;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;

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
			this->showInfoPanel = (gcnew System::Windows::Forms::Panel());
			this->modifyButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->stuListTypeCombox = (gcnew System::Windows::Forms::ComboBox());
			this->lv_allStu = (gcnew System::Windows::Forms::ListView());
			this->idNum = (gcnew System::Windows::Forms::ColumnHeader());
			this->name = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->stuInfo = (gcnew System::Windows::Forms::TabControl());
			this->basicInfo = (gcnew System::Windows::Forms::TabPage());
			this->tb_major = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->photo = (gcnew System::Windows::Forms::PictureBox());
			this->lookButton = (gcnew System::Windows::Forms::Button());
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
			this->addInfo = (gcnew System::Windows::Forms::TabPage());
			this->noteText = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->isTalent = (gcnew System::Windows::Forms::CheckBox());
			this->IDMaskedTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->undergradePage = (gcnew System::Windows::Forms::TabPage());
			this->highSchoolBox = (gcnew System::Windows::Forms::TextBox());
			this->CEEMBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->graduatesPage = (gcnew System::Windows::Forms::TabPage());
			this->reseaInteBox = (gcnew System::Windows::Forms::TextBox());
			this->graduateSchoolBox = (gcnew System::Windows::Forms::TextBox());
			this->tutorNameBox = (gcnew System::Windows::Forms::TextBox());
			this->entMarkBox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->stuInfo->SuspendLayout();
			this->basicInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photo))->BeginInit();
			this->addInfo->SuspendLayout();
			this->undergradePage->SuspendLayout();
			this->graduatesPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// showInfoPanel
			// 
			this->showInfoPanel->Location = System::Drawing::Point(222, -4);
			this->showInfoPanel->Margin = System::Windows::Forms::Padding(6);
			this->showInfoPanel->Name = L"showInfoPanel";
			this->showInfoPanel->Size = System::Drawing::Size(1220, 384);
			this->showInfoPanel->TabIndex = 2;
			// 
			// modifyButton
			// 
			this->modifyButton->Location = System::Drawing::Point(780, 408);
			this->modifyButton->Margin = System::Windows::Forms::Padding(6);
			this->modifyButton->Name = L"modifyButton";
			this->modifyButton->Size = System::Drawing::Size(235, 46);
			this->modifyButton->TabIndex = 3;
			this->modifyButton->Text = L"修   改";
			this->modifyButton->UseVisualStyleBackColor = true;
			this->modifyButton->Click += gcnew System::EventHandler(this, &stuList::modifyButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(392, 408);
			this->delete_button->Margin = System::Windows::Forms::Padding(6);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(260, 46);
			this->delete_button->TabIndex = 5;
			this->delete_button->Text = L"删  除";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &stuList::delete_button_Click);
			// 
			// stuListTypeCombox
			// 
			this->stuListTypeCombox->FormattingEnabled = true;
			this->stuListTypeCombox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"硕士生", L"本科生" });
			this->stuListTypeCombox->Location = System::Drawing::Point(16, 13);
			this->stuListTypeCombox->Margin = System::Windows::Forms::Padding(6);
			this->stuListTypeCombox->Name = L"stuListTypeCombox";
			this->stuListTypeCombox->Size = System::Drawing::Size(256, 32);
			this->stuListTypeCombox->TabIndex = 8;
			this->stuListTypeCombox->SelectedIndexChanged += gcnew System::EventHandler(this, &stuList::stuListTypeCombox_SelectedIndexChanged);
			// 
			// lv_allStu
			// 
			this->lv_allStu->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->idNum, this->name });
			this->lv_allStu->Location = System::Drawing::Point(16, 65);
			this->lv_allStu->Margin = System::Windows::Forms::Padding(6);
			this->lv_allStu->Name = L"lv_allStu";
			this->lv_allStu->Size = System::Drawing::Size(256, 326);
			this->lv_allStu->TabIndex = 7;
			this->lv_allStu->UseCompatibleStateImageBehavior = false;
			this->lv_allStu->View = System::Windows::Forms::View::Details;
			this->lv_allStu->SelectedIndexChanged += gcnew System::EventHandler(this, &stuList::lv_allStu_SelectedIndexChanged);
			// 
			// idNum
			// 
			this->idNum->Text = L"学号";
			// 
			// name
			// 
			this->name->Text = L"姓名";
			this->name->Width = 66;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->stuInfo);
			this->panel1->Location = System::Drawing::Point(288, 13);
			this->panel1->Margin = System::Windows::Forms::Padding(6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1188, 384);
			this->panel1->TabIndex = 6;
			// 
			// stuInfo
			// 
			this->stuInfo->Controls->Add(this->basicInfo);
			this->stuInfo->Controls->Add(this->addInfo);
			this->stuInfo->Controls->Add(this->undergradePage);
			this->stuInfo->Controls->Add(this->graduatesPage);
			this->stuInfo->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stuInfo->Location = System::Drawing::Point(6, 32);
			this->stuInfo->Margin = System::Windows::Forms::Padding(6);
			this->stuInfo->Name = L"stuInfo";
			this->stuInfo->SelectedIndex = 0;
			this->stuInfo->Size = System::Drawing::Size(1170, 346);
			this->stuInfo->TabIndex = 1;
			// 
			// basicInfo
			// 
			this->basicInfo->Controls->Add(this->tb_major);
			this->basicInfo->Controls->Add(this->label8);
			this->basicInfo->Controls->Add(this->photo);
			this->basicInfo->Controls->Add(this->lookButton);
			this->basicInfo->Controls->Add(this->picTbox);
			this->basicInfo->Controls->Add(this->noTbox);
			this->basicInfo->Controls->Add(this->nameTbox);
			this->basicInfo->Controls->Add(this->label5);
			this->basicInfo->Controls->Add(this->label4);
			this->basicInfo->Controls->Add(this->genderCombox);
			this->basicInfo->Controls->Add(this->label3);
			this->basicInfo->Controls->Add(this->label2);
			this->basicInfo->Controls->Add(this->birthPicker);
			this->basicInfo->Controls->Add(this->label1);
			this->basicInfo->Location = System::Drawing::Point(4, 42);
			this->basicInfo->Margin = System::Windows::Forms::Padding(6);
			this->basicInfo->Name = L"basicInfo";
			this->basicInfo->Padding = System::Windows::Forms::Padding(6);
			this->basicInfo->Size = System::Drawing::Size(1162, 300);
			this->basicInfo->TabIndex = 0;
			this->basicInfo->Text = L"基本信息";
			this->basicInfo->UseVisualStyleBackColor = true;
			// 
			// tb_major
			// 
			this->tb_major->Enabled = false;
			this->tb_major->Location = System::Drawing::Point(294, 106);
			this->tb_major->Margin = System::Windows::Forms::Padding(6);
			this->tb_major->Name = L"tb_major";
			this->tb_major->Size = System::Drawing::Size(196, 44);
			this->tb_major->TabIndex = 25;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(208, 118);
			this->label8->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 33);
			this->label8->TabIndex = 24;
			this->label8->Text = L"专业";
			// 
			// photo
			// 
			this->photo->Location = System::Drawing::Point(950, 30);
			this->photo->Margin = System::Windows::Forms::Padding(6);
			this->photo->Name = L"photo";
			this->photo->Size = System::Drawing::Size(178, 206);
			this->photo->TabIndex = 23;
			this->photo->TabStop = false;
			// 
			// lookButton
			// 
			this->lookButton->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lookButton->Location = System::Drawing::Point(748, 190);
			this->lookButton->Margin = System::Windows::Forms::Padding(6);
			this->lookButton->Name = L"lookButton";
			this->lookButton->Size = System::Drawing::Size(150, 62);
			this->lookButton->TabIndex = 22;
			this->lookButton->Text = L"浏 览";
			this->lookButton->UseVisualStyleBackColor = true;
			this->lookButton->Click += gcnew System::EventHandler(this, &stuList::lookButton_Click);
			// 
			// picTbox
			// 
			this->picTbox->Location = System::Drawing::Point(188, 190);
			this->picTbox->Margin = System::Windows::Forms::Padding(6);
			this->picTbox->Name = L"picTbox";
			this->picTbox->Size = System::Drawing::Size(520, 44);
			this->picTbox->TabIndex = 21;
			// 
			// noTbox
			// 
			this->noTbox->Location = System::Drawing::Point(616, 106);
			this->noTbox->Margin = System::Windows::Forms::Padding(6);
			this->noTbox->Name = L"noTbox";
			this->noTbox->Size = System::Drawing::Size(300, 44);
			this->noTbox->TabIndex = 19;
			// 
			// nameTbox
			// 
			this->nameTbox->Location = System::Drawing::Point(120, 30);
			this->nameTbox->Margin = System::Windows::Forms::Padding(6);
			this->nameTbox->Name = L"nameTbox";
			this->nameTbox->Size = System::Drawing::Size(242, 44);
			this->nameTbox->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 196);
			this->label5->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(143, 33);
			this->label5->TabIndex = 20;
			this->label5->Text = L"头像信息";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(524, 112);
			this->label4->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 33);
			this->label4->TabIndex = 18;
			this->label4->Text = L"学号";
			// 
			// genderCombox
			// 
			this->genderCombox->FormattingEnabled = true;
			this->genderCombox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"男", L"女" });
			this->genderCombox->Location = System::Drawing::Point(120, 106);
			this->genderCombox->Margin = System::Windows::Forms::Padding(6);
			this->genderCombox->Name = L"genderCombox";
			this->genderCombox->Size = System::Drawing::Size(72, 41);
			this->genderCombox->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(32, 118);
			this->label3->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 33);
			this->label3->TabIndex = 16;
			this->label3->Text = L"性别";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(460, 40);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 33);
			this->label2->TabIndex = 15;
			this->label2->Text = L"出生日期";
			// 
			// birthPicker
			// 
			this->birthPicker->Location = System::Drawing::Point(616, 28);
			this->birthPicker->Margin = System::Windows::Forms::Padding(6);
			this->birthPicker->Name = L"birthPicker";
			this->birthPicker->Size = System::Drawing::Size(300, 44);
			this->birthPicker->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 42);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 33);
			this->label1->TabIndex = 12;
			this->label1->Text = L"姓名";
			// 
			// addInfo
			// 
			this->addInfo->Controls->Add(this->noteText);
			this->addInfo->Controls->Add(this->label7);
			this->addInfo->Controls->Add(this->isTalent);
			this->addInfo->Controls->Add(this->IDMaskedTextBox);
			this->addInfo->Controls->Add(this->label6);
			this->addInfo->Location = System::Drawing::Point(4, 42);
			this->addInfo->Margin = System::Windows::Forms::Padding(6);
			this->addInfo->Name = L"addInfo";
			this->addInfo->Padding = System::Windows::Forms::Padding(6);
			this->addInfo->Size = System::Drawing::Size(1162, 300);
			this->addInfo->TabIndex = 1;
			this->addInfo->Text = L"附加信息";
			this->addInfo->UseVisualStyleBackColor = true;
			// 
			// noteText
			// 
			this->noteText->Location = System::Drawing::Point(174, 82);
			this->noteText->Margin = System::Windows::Forms::Padding(6);
			this->noteText->Name = L"noteText";
			this->noteText->Size = System::Drawing::Size(926, 172);
			this->noteText->TabIndex = 4;
			this->noteText->Text = L"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(18, 116);
			this->label7->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(143, 33);
			this->label7->TabIndex = 3;
			this->label7->Text = L"备注信息";
			// 
			// isTalent
			// 
			this->isTalent->AutoSize = true;
			this->isTalent->Location = System::Drawing::Point(634, 22);
			this->isTalent->Margin = System::Windows::Forms::Padding(6);
			this->isTalent->Name = L"isTalent";
			this->isTalent->Size = System::Drawing::Size(201, 37);
			this->isTalent->TabIndex = 2;
			this->isTalent->Text = L"是否特长生";
			this->isTalent->UseVisualStyleBackColor = true;
			// 
			// IDMaskedTextBox
			// 
			this->IDMaskedTextBox->Location = System::Drawing::Point(200, 12);
			this->IDMaskedTextBox->Margin = System::Windows::Forms::Padding(6);
			this->IDMaskedTextBox->Mask = L"000000-00000000-000A";
			this->IDMaskedTextBox->Name = L"IDMaskedTextBox";
			this->IDMaskedTextBox->Size = System::Drawing::Size(342, 44);
			this->IDMaskedTextBox->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 30);
			this->label6->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(143, 33);
			this->label6->TabIndex = 0;
			this->label6->Text = L"身份证号";
			// 
			// undergradePage
			// 
			this->undergradePage->Controls->Add(this->highSchoolBox);
			this->undergradePage->Controls->Add(this->CEEMBox);
			this->undergradePage->Controls->Add(this->label16);
			this->undergradePage->Controls->Add(this->label17);
			this->undergradePage->Location = System::Drawing::Point(4, 42);
			this->undergradePage->Margin = System::Windows::Forms::Padding(6);
			this->undergradePage->Name = L"undergradePage";
			this->undergradePage->Padding = System::Windows::Forms::Padding(6);
			this->undergradePage->Size = System::Drawing::Size(1162, 300);
			this->undergradePage->TabIndex = 2;
			this->undergradePage->Text = L"本科生";
			this->undergradePage->UseVisualStyleBackColor = true;
			// 
			// highSchoolBox
			// 
			this->highSchoolBox->Location = System::Drawing::Point(184, 14);
			this->highSchoolBox->Margin = System::Windows::Forms::Padding(6);
			this->highSchoolBox->Name = L"highSchoolBox";
			this->highSchoolBox->Size = System::Drawing::Size(254, 44);
			this->highSchoolBox->TabIndex = 9;
			// 
			// CEEMBox
			// 
			this->CEEMBox->Location = System::Drawing::Point(644, 12);
			this->CEEMBox->Margin = System::Windows::Forms::Padding(6);
			this->CEEMBox->Name = L"CEEMBox";
			this->CEEMBox->Size = System::Drawing::Size(110, 44);
			this->CEEMBox->TabIndex = 7;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(28, 24);
			this->label16->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(143, 33);
			this->label16->TabIndex = 8;
			this->label16->Text = L"毕业高中";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(490, 22);
			this->label17->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(143, 33);
			this->label17->TabIndex = 6;
			this->label17->Text = L"高考成绩";
			// 
			// graduatesPage
			// 
			this->graduatesPage->Controls->Add(this->reseaInteBox);
			this->graduatesPage->Controls->Add(this->graduateSchoolBox);
			this->graduatesPage->Controls->Add(this->tutorNameBox);
			this->graduatesPage->Controls->Add(this->entMarkBox);
			this->graduatesPage->Controls->Add(this->label18);
			this->graduatesPage->Controls->Add(this->label19);
			this->graduatesPage->Controls->Add(this->label20);
			this->graduatesPage->Controls->Add(this->label21);
			this->graduatesPage->Location = System::Drawing::Point(4, 42);
			this->graduatesPage->Margin = System::Windows::Forms::Padding(6);
			this->graduatesPage->Name = L"graduatesPage";
			this->graduatesPage->Padding = System::Windows::Forms::Padding(6);
			this->graduatesPage->Size = System::Drawing::Size(1162, 300);
			this->graduatesPage->TabIndex = 3;
			this->graduatesPage->Text = L"硕士生";
			this->graduatesPage->UseVisualStyleBackColor = true;
			// 
			// reseaInteBox
			// 
			this->reseaInteBox->Location = System::Drawing::Point(720, 138);
			this->reseaInteBox->Margin = System::Windows::Forms::Padding(6);
			this->reseaInteBox->Name = L"reseaInteBox";
			this->reseaInteBox->Size = System::Drawing::Size(196, 44);
			this->reseaInteBox->TabIndex = 15;
			// 
			// graduateSchoolBox
			// 
			this->graduateSchoolBox->Location = System::Drawing::Point(720, 24);
			this->graduateSchoolBox->Margin = System::Windows::Forms::Padding(6);
			this->graduateSchoolBox->Name = L"graduateSchoolBox";
			this->graduateSchoolBox->Size = System::Drawing::Size(196, 44);
			this->graduateSchoolBox->TabIndex = 14;
			// 
			// tutorNameBox
			// 
			this->tutorNameBox->Location = System::Drawing::Point(206, 146);
			this->tutorNameBox->Margin = System::Windows::Forms::Padding(6);
			this->tutorNameBox->Name = L"tutorNameBox";
			this->tutorNameBox->Size = System::Drawing::Size(196, 44);
			this->tutorNameBox->TabIndex = 13;
			// 
			// entMarkBox
			// 
			this->entMarkBox->Location = System::Drawing::Point(206, 30);
			this->entMarkBox->Margin = System::Windows::Forms::Padding(6);
			this->entMarkBox->Name = L"entMarkBox";
			this->entMarkBox->Size = System::Drawing::Size(196, 44);
			this->entMarkBox->TabIndex = 12;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(556, 150);
			this->label18->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(143, 33);
			this->label18->TabIndex = 11;
			this->label18->Text = L"研究方向";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(550, 36);
			this->label19->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(143, 33);
			this->label19->TabIndex = 10;
			this->label19->Text = L"毕业院校";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(44, 152);
			this->label20->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(143, 33);
			this->label20->TabIndex = 9;
			this->label20->Text = L"导师姓名";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(38, 38);
			this->label21->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(143, 33);
			this->label21->TabIndex = 8;
			this->label21->Text = L"入学成绩";
			// 
			// stuList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1485, 498);
			this->Controls->Add(this->stuListTypeCombox);
			this->Controls->Add(this->lv_allStu);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->delete_button);
			this->Controls->Add(this->modifyButton);
			this->Controls->Add(this->showInfoPanel);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"stuList";
			this->Text = L"学生列表";
			this->Load += gcnew System::EventHandler(this, &stuList::stuList_Load);
			this->panel1->ResumeLayout(false);
			this->stuInfo->ResumeLayout(false);
			this->basicInfo->ResumeLayout(false);
			this->basicInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->photo))->EndInit();
			this->addInfo->ResumeLayout(false);
			this->addInfo->PerformLayout();
			this->undergradePage->ResumeLayout(false);
			this->undergradePage->PerformLayout();
			this->graduatesPage->ResumeLayout(false);
			this->graduatesPage->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void stuList_Load(System::Object^  sender, System::EventArgs^  e) {
		stuListTypeCombox->SelectedIndex = 0;
		addStuToList((int)UserTypeCode::USER_GRADUATE);
	}

	private: System::Void modifyButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->modifyButton->Text == "修 改") {
			setAllControler(true);
			this->nameTbox->Enabled = false; //学号姓名不可更改
			this->noTbox->Enabled = false;
			this->tb_major->Enabled = false;
			this->modifyButton->Text = "提 交";
		}
		else {
			//创建新对象，更新文件系统
			String ^name = nameTbox->Text;
			String ^birthStr = birthPicker->Text;
			int  gender = genderCombox->SelectedIndex;
			String ^ stuNo = noTbox->Text;
			String ^picPath = picTbox->Text;
			String ^idNo = IDMaskedTextBox->Text;
			String ^noteStr = noteText->Text;
			bool isTal = isTalent->Checked;
			int year, month, day;

			DateTime t;
			t = DateTime::Parse(birthStr);
			year = Convert::ToInt16(t.Year.ToString());
			month = Convert::ToInt16(t.Month.ToString());
			day = Convert::ToInt16(t.Day.ToString());

			AcademicStaff *staff = new AcademicStaff();
			if (stuListTypeCombox->SelectedIndex == 0){ //硕士生
				GraduateTable* pm1 = new GraduateTable();
				pm1->setId((char*)(Marshal::StringToHGlobalAnsi(stuNo)).ToPointer());
				pm1->setName((char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer());
				pm1->setSex(gender);
				pm1->setBirthday(year, month, day);
				pm1->setIdNumber((char*)(Marshal::StringToHGlobalAnsi(idNo)).ToPointer());
				pm1->setExtraInfo((char*)(Marshal::StringToHGlobalAnsi(noteStr)).ToPointer());
				pm1->setIsTalent(isTal);
				pm1->setMajor((char*)(Marshal::StringToHGlobalAnsi(tb_major->Text)).ToPointer());
				pm1->setPicpath((char*)(Marshal::StringToHGlobalAnsi(picPath)).ToPointer());
				pm1->setEntranceScore(Convert::ToInt16(entMarkBox->Text->ToString()));
				pm1->setUndergraduateSchool((char*)(Marshal::StringToHGlobalAnsi(graduateSchoolBox->Text)).ToPointer());
				pm1->setSupervisorName((char*)(Marshal::StringToHGlobalAnsi(tutorNameBox->Text)).ToPointer());
				pm1->setResearchInterests((char*)(Marshal::StringToHGlobalAnsi(reseaInteBox->Text)).ToPointer());
				staff->writeGraduate(pm1);

				delete pm1;
			}
			else{
				UndergraduateTable* pm1 = new UndergraduateTable();
				pm1->setId((char*)(Marshal::StringToHGlobalAnsi(stuNo)).ToPointer());
				pm1->setName((char*)(Marshal::StringToHGlobalAnsi(name)).ToPointer());
				pm1->setSex(gender);
				pm1->setBirthday(year, month, day);
				pm1->setIdNumber((char*)(Marshal::StringToHGlobalAnsi(idNo)).ToPointer());
				pm1->setExtraInfo((char*)(Marshal::StringToHGlobalAnsi(noteStr)).ToPointer());
				pm1->setIsTalent(isTal);
				pm1->setMajor((char*)(Marshal::StringToHGlobalAnsi(tb_major->Text)).ToPointer());
				pm1->setPicpath((char*)(Marshal::StringToHGlobalAnsi(picPath)).ToPointer());
				pm1->setScore(Convert::ToInt16(CEEMBox->Text->ToString()));
				pm1->setSchoolName((char*)(Marshal::StringToHGlobalAnsi(highSchoolBox->Text)).ToPointer());
				staff->writeUndergraduate(pm1);
				delete pm1;
			}
			this->modifyButton->Text = "修 改";
			setAllControler(false);
			delete staff;
		}

	}

	private: void setAllControler(bool status) {
		this->nameTbox->Enabled = status;
		this->birthPicker->Enabled = status;
		this->genderCombox->Enabled = status;
		this->noTbox->Enabled = status;
		this->picTbox->Enabled = status;
		this->tb_major->Enabled = status;
		this->lookButton->Enabled = status;
		this->IDMaskedTextBox->Enabled = status;
		this->isTalent->Enabled = status;
		this->noteText->Enabled = status;
		this->highSchoolBox->Enabled = status;
		this->CEEMBox->Enabled = status;
		this->entMarkBox->Enabled = status;
		this->graduateSchoolBox->Enabled = status;
		this->tutorNameBox->Enabled = status;
		this->reseaInteBox->Enabled = status;
	}

 private: void addStuToList(int type) { //学号+姓名
	 this->lv_allStu->Items->Clear();
	 AcademicStaff *staff = new AcademicStaff();
	 char id[20];
	 cli::array<String ^> ^list = staff->getAllStuSummaryInfo(type);
	 String ^stuName;
	 string name;
	 for each (String ^a in list) {
		 sprintf(id, "%s", a);
		 if (type == (int)UserTypeCode::USER_GRADUATE){
			 name = staff->readGraduateInfo(id)->getName();
			 stuName = gcnew String(name.c_str());
		 }
		 else if (type == (int)UserTypeCode::USER_UNDERGRADUATE) {
			 name = staff->readUndergraduateInfo(id)->getName();
			 stuName = gcnew String(name.c_str());
		 }
		 ListViewItem ^listItem = gcnew ListViewItem(a);
		 listItem->SubItems->Add(stuName);
		 lv_allStu->Items->Add(listItem);
	 }
	 delete staff;
 }

	private: System::Void lookButton_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
		picTbox->Text = openFileDialog1->FileName;
		photo->ImageLocation = picTbox->Text;
	}

private: System::Void delete_button_Click(System::Object^  sender, System::EventArgs^  e) {
	AcademicStaff *staff = new AcademicStaff();
	char id[20];
	sprintf(id, "%s", (char*)(Marshal::StringToHGlobalAnsi(noTbox->Text)).ToPointer());
	if (staff->deleteStuAccount(id)) {
		MessageBox::Show("删除成功");
	}
	int index = stuListTypeCombox->SelectedIndex;
	addStuToList(index+3); //更新列表
	delete staff;
}
private: System::Void stuListTypeCombox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	int index = stuListTypeCombox->SelectedIndex;
	addStuToList(index + 3);
	stuInfo->TabPages->Remove(graduatesPage);
	stuInfo->TabPages->Remove(undergradePage);
	if (index == 0) {
		stuInfo->TabPages->Add(graduatesPage);
	}
	else {
		stuInfo->TabPages->Add(undergradePage);
	}
}
private: System::Void lv_allStu_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	String^ stuIdNum;
	ListView::SelectedListViewItemCollection^ stu = this->lv_allStu->SelectedItems;
	System::Collections::IEnumerator^ myEnum = stu->GetEnumerator();
	while (myEnum->MoveNext()){ //返回一个集合
		ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
		stuIdNum = item->Text;
	}
	if (stuIdNum == nullptr) return;
	char id[20];
	sprintf(id, "%s", stuIdNum);
	AcademicStaff *staff = new AcademicStaff();
	if (stuListTypeCombox->SelectedIndex == 0){ //硕士生
		GraduateTable* pm1;
		pm1 = staff->readGraduateInfo(id);
		//更新panel中的个人信息,用string中转
		string str = pm1->getName(); //姓名
		this->nameTbox->Text = gcnew String(str.c_str());
		str = pm1->getMajor(); //专业
		this->tb_major->Text = gcnew String(str.c_str());
		str = pm1->getPicpath(); //图片路径
		this->picTbox->Text = gcnew String(str.c_str());
		str = pm1->getExtraInfo(); //附加信息
		this->noteText->Text = gcnew String(str.c_str());
		str = pm1->getId();   //学号
		this->noTbox->Text = gcnew String(str.c_str());
		str = pm1->getIdNumber();  //身份证号
		this->IDMaskedTextBox->Text = gcnew String(str.c_str());
		//日期
		char birBuf[5]; //string没有重载+int，用sprint函数用birBuf中转
		int year, month, day;
		pm1->getBirthday(year, month, day);
		sprintf(birBuf, "%d", year);
		str = birBuf;
		str += "年";
		sprintf(birBuf, "%d", month);
		str += birBuf;
		str += "月";
		sprintf(birBuf, "%d", day);
		str += birBuf;
		str += "日";
		this->birthPicker->Text = gcnew String(str.c_str());
		this->isTalent->Checked = pm1->getIsTalent(); //是否特长
		this->genderCombox->SelectedIndex = pm1->getSex(); //性别
		str = pm1->getSupervisorName();
		this->tutorNameBox->Text = gcnew String(str.c_str()); //导师姓名
		str = pm1->getUndergraduateSchool();
		this->graduateSchoolBox->Text = gcnew String(str.c_str()); //本科学校
		str = pm1->getResearchInterests();
		this->reseaInteBox->Text = gcnew String(str.c_str()); //研究领域
		char temp[5];
		sprintf(temp, "%d", pm1->getEntranceScore());
		str = temp;
		this->entMarkBox->Text = gcnew String(str.c_str());
		delete pm1;
	}
	else{
		UndergraduateTable* pm1;
		pm1 = staff->readUndergraduateInfo(id);
		//更新panel中的个人信息,用string中转
		string str = pm1->getName(); //姓名
		this->nameTbox->Text = gcnew String(str.c_str());
		str = pm1->getMajor(); //专业
		this->tb_major->Text = gcnew String(str.c_str());
		str = pm1->getPicpath(); //图片路径
		this->picTbox->Text = gcnew String(str.c_str());
		str = pm1->getExtraInfo(); //附加信息
		this->noteText->Text = gcnew String(str.c_str());
		str = pm1->getId();   //学号
		this->noTbox->Text = gcnew String(str.c_str());
		str = pm1->getIdNumber();  //身份证号
		this->IDMaskedTextBox->Text = gcnew String(str.c_str());
		//日期
		char birBuf[5]; //string没有重载+int，用sprint函数用birBuf中转
		int year, month, day;
		pm1->getBirthday(year, month, day);
		sprintf(birBuf, "%d", year);
		str = birBuf;
		str += "年";
		sprintf(birBuf, "%d", month);
		str += birBuf;
		str += "月";
		sprintf(birBuf, "%d", day);
		str += birBuf;
		str += "日";
		this->birthPicker->Text = gcnew String(str.c_str());
		this->isTalent->Checked = pm1->getIsTalent(); //是否特长
		this->genderCombox->SelectedIndex = pm1->getSex(); //性别
		str = pm1->getSchoolName();
		this->highSchoolBox->Text = gcnew String(str.c_str()); //导师姓名
		char temp[5];
		sprintf(temp, "%d", pm1->getScore());
		str = temp;
		this->CEEMBox->Text = gcnew String(str.c_str());
		delete pm1;
	}
	setAllControler(false);
	this->modifyButton->Text = "修 改";
	photo->ImageLocation = picTbox->Text;
	delete staff;
}
};


}
