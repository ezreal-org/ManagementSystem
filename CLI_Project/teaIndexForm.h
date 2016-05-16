#pragma once
#include "addNewCourse.h"
#include "recordGrade.h"
#include "memberInfo.h"
#include "memberService.h"
#include "updatePasswd.h"
#include "ChartForm.h"

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
	private: System::Windows::Forms::MenuStrip^  teaIndexMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  selfInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resetPSItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allSelfInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  courseArrangeItem;

	private: System::Windows::Forms::ToolStripMenuItem^  recordGradeItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutSysItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  nowDate;
	private: System::Windows::Forms::ToolStripStatusLabel^  nowTime;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::ToolStripMenuItem^  exit;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  �ɼ�����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  checkAllGradeItem;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// ����������������
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->teaIndexMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->selfInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetPSItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allSelfInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->courseArrangeItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recordGradeItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->helpItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutSysItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ɼ�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkAllGradeItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->nowDate = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->nowTime = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->teaIndexMenu->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// teaIndexMenu
			// 
			this->teaIndexMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->selfInfoItem, this->courseArrangeItem,
					this->�ɼ�����ToolStripMenuItem, this->helpItem
			});
			this->teaIndexMenu->Location = System::Drawing::Point(0, 0);
			this->teaIndexMenu->Name = L"teaIndexMenu";
			this->teaIndexMenu->Size = System::Drawing::Size(714, 28);
			this->teaIndexMenu->TabIndex = 0;
			this->teaIndexMenu->Text = L"teaIndexMenu";
			// 
			// selfInfoItem
			// 
			this->selfInfoItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->resetPSItem,
					this->allSelfInfoItem
			});
			this->selfInfoItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->selfInfoItem->Name = L"selfInfoItem";
			this->selfInfoItem->Size = System::Drawing::Size(85, 24);
			this->selfInfoItem->Text = L"��������";
			// 
			// resetPSItem
			// 
			this->resetPSItem->Name = L"resetPSItem";
			this->resetPSItem->Size = System::Drawing::Size(174, 24);
			this->resetPSItem->Text = L"�޸�����";
			this->resetPSItem->Click += gcnew System::EventHandler(this, &teaIndexForm::resetPSItem_Click);
			// 
			// allSelfInfoItem
			// 
			this->allSelfInfoItem->Name = L"allSelfInfoItem";
			this->allSelfInfoItem->Size = System::Drawing::Size(174, 24);
			this->allSelfInfoItem->Text = L"��ѯ������Ϣ";
			this->allSelfInfoItem->Click += gcnew System::EventHandler(this, &teaIndexForm::allSelfInfoItem_Click);
			// 
			// courseArrangeItem
			// 
			this->courseArrangeItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->recordGradeItem,
					this->toolStripSeparator1
			});
			this->courseArrangeItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->courseArrangeItem->Name = L"courseArrangeItem";
			this->courseArrangeItem->Size = System::Drawing::Size(85, 24);
			this->courseArrangeItem->Text = L"�γ̹���";
			// 
			// recordGradeItem
			// 
			this->recordGradeItem->Name = L"recordGradeItem";
			this->recordGradeItem->Size = System::Drawing::Size(152, 24);
			this->recordGradeItem->Text = L"�ɼ�¼��";
			this->recordGradeItem->Click += gcnew System::EventHandler(this, &teaIndexForm::recordGradeItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// helpItem
			// 
			this->helpItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutSysItem,
					this->exit
			});
			this->helpItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->helpItem->Name = L"helpItem";
			this->helpItem->Size = System::Drawing::Size(53, 24);
			this->helpItem->Text = L"����";
			// 
			// aboutSysItem
			// 
			this->aboutSysItem->Name = L"aboutSysItem";
			this->aboutSysItem->Size = System::Drawing::Size(142, 24);
			this->aboutSysItem->Text = L"����ϵͳ";
			this->aboutSysItem->Click += gcnew System::EventHandler(this, &teaIndexForm::aboutSysItem_Click);
			// 
			// exit
			// 
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(142, 24);
			this->exit->Text = L"ע��";
			this->exit->Click += gcnew System::EventHandler(this, &teaIndexForm::exit_Click);
			// 
			// �ɼ�����ToolStripMenuItem
			// 
			this->�ɼ�����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkAllGradeItem });
			this->�ɼ�����ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->�ɼ�����ToolStripMenuItem->Name = L"�ɼ�����ToolStripMenuItem";
			this->�ɼ�����ToolStripMenuItem->Size = System::Drawing::Size(85, 24);
			this->�ɼ�����ToolStripMenuItem->Text = L"�ɼ�����";
			// 
			// checkAllGradeItem
			// 
			this->checkAllGradeItem->Name = L"checkAllGradeItem";
			this->checkAllGradeItem->Size = System::Drawing::Size(152, 22);
			this->checkAllGradeItem->Text = L"�ɼ�ͳ��";
			this->checkAllGradeItem->Click += gcnew System::EventHandler(this, &teaIndexForm::checkAllGradeItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nowDate, this->toolStripStatusLabel2,
					this->nowTime
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 295);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(714, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// nowDate
			// 
			this->nowDate->Name = L"nowDate";
			this->nowDate->Size = System::Drawing::Size(32, 17);
			this->nowDate->Text = L"����";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 17);
			// 
			// nowTime
			// 
			this->nowTime->Name = L"nowTime";
			this->nowTime->Size = System::Drawing::Size(32, 17);
			this->nowTime->Text = L"ʱ��";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &teaIndexForm::timer1_Tick);
			// 
			// teaIndexForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 317);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->teaIndexMenu);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->teaIndexMenu;
			this->Name = L"teaIndexForm";
			this->Text = L"���׽������ϵͳ-��ʦ��";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &teaIndexForm::teaIndexForm_FormClosing);
			this->teaIndexMenu->ResumeLayout(false);
			this->teaIndexMenu->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		DateTime monment = DateTime::Now;
		int year = monment.Year;
		int mon = monment.Month;
		int date = monment.Day;

		int h = monment.Hour;
		int m = monment.Minute;
		int s = monment.Second;

		String ^ dateStr = "��ǰʱ�䣺" + year.ToString() + "-" + mon.ToString() + "-" + date.ToString() + "  ";
		String ^ timeStr = (h % 12).ToString() + ":" + m.ToString() + ":" + s.ToString();
		this->nowDate->Text = dateStr;
		this->nowTime->Text = timeStr;
	}
	private: System::Void resetPSItem_Click(System::Object^  sender, System::EventArgs^  e) {
		updatePasswd ^update = gcnew updatePasswd(thisLogin);
		update->Name = "updatePasswd";
		update->MdiParent = this;
		update->StartPosition = FormStartPosition::CenterParent;
		update->WindowState = FormWindowState::Maximized;
		update->Show();
	}
	private: System::Void aboutSysItem_Click(System::Object^  sender, System::EventArgs^  e) {
		HelpInfo ^help = gcnew HelpInfo();
		help->StartPosition = FormStartPosition::CenterScreen;
		help->Name = "help";
		help->Show();
	}
	private: System::Void allSelfInfoItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("�μ�ѧ����ѯ������Ϣ");
	}
	private: System::Void recordGradeItem_Click(System::Object^  sender, System::EventArgs^  e) {
		recordGrade ^record = gcnew recordGrade(thisLogin);
		record->Name = "record";
		record->MdiParent = this;
		record->StartPosition = FormStartPosition::CenterParent;
		record->WindowState = FormWindowState::Maximized;
		record->Show();
	}
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		Application::OpenForms["loginForm1"]->Show();
	}
	private: System::Void teaIndexForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
	}
	private: System::Void checkAllGradeItem_Click(System::Object^  sender, System::EventArgs^  e) {
		ChartForm ^cF = gcnew ChartForm(thisLogin);
		cF->Name = "chartform";
		cF->MdiParent = this;
		cF->StartPosition = FormStartPosition::CenterParent;
		cF->WindowState = FormWindowState::Maximized;
		cF->Show();
	}
	};
}
