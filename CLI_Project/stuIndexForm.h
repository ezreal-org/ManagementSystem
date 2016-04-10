#pragma once
#include "selectCourse.h"
#include "courseSelected.h"
#include "updatePasswd.h"
#include "stuInfo.h"

namespace ManagementSystemV5 {

#pragma once
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// adFormNew 摘要
	/// </summary>
	public ref class stuIndexForm : public System::Windows::Forms::Form
	{
	public:
		stuIndexForm(UserTable* login)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			this->thisLogin = login;
			timer1->Start();
			this->IsMdiContainer = true;
			this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~stuIndexForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable *thisLogin;
	private: System::Windows::Forms::MenuStrip^  stuIndexMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  courseManageItem;
	private: System::Windows::Forms::ToolStripMenuItem^  selectNewCourseItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allSelectedCoursesItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;


	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  NowData;
	private: System::Windows::Forms::ToolStripMenuItem^  selfInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resetPSItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allSelfInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpItem;
	private: System::Windows::Forms::ToolStripMenuItem^  responseItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutSysItem;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  NowTime;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitItem;
	private: System::Windows::Forms::ToolStripMenuItem^  成绩管理ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  checkAllGradeItem;

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->stuIndexMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->selfInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetPSItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allSelfInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->courseManageItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selectNewCourseItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allSelectedCoursesItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->helpItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->responseItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutSysItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->NowData = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->NowTime = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->成绩管理ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkAllGradeItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stuIndexMenu->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// stuIndexMenu
			// 
			this->stuIndexMenu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->stuIndexMenu->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->stuIndexMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->selfInfoItem, this->courseManageItem,
					this->成绩管理ToolStripMenuItem, this->helpItem
			});
			this->stuIndexMenu->Location = System::Drawing::Point(0, 0);
			this->stuIndexMenu->Name = L"stuIndexMenu";
			this->stuIndexMenu->Size = System::Drawing::Size(714, 28);
			this->stuIndexMenu->TabIndex = 0;
			this->stuIndexMenu->Text = L"menuStrip1";
			// 
			// selfInfoItem
			// 
			this->selfInfoItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->resetPSItem,
					this->allSelfInfoItem
			});
			this->selfInfoItem->Name = L"selfInfoItem";
			this->selfInfoItem->Size = System::Drawing::Size(85, 24);
			this->selfInfoItem->Text = L"个人中心";
			// 
			// resetPSItem
			// 
			this->resetPSItem->Name = L"resetPSItem";
			this->resetPSItem->Size = System::Drawing::Size(174, 24);
			this->resetPSItem->Text = L"修改密码";
			this->resetPSItem->Click += gcnew System::EventHandler(this, &stuIndexForm::resetPsword_Click);
			// 
			// allSelfInfoItem
			// 
			this->allSelfInfoItem->Name = L"allSelfInfoItem";
			this->allSelfInfoItem->Size = System::Drawing::Size(174, 24);
			this->allSelfInfoItem->Text = L"查询个人信息";
			this->allSelfInfoItem->Click += gcnew System::EventHandler(this, &stuIndexForm::selfInfoItem_Click);
			// 
			// courseManageItem
			// 
			this->courseManageItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->selectNewCourseItem,
					this->allSelectedCoursesItem, this->toolStripSeparator1
			});
			this->courseManageItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->courseManageItem->Name = L"courseManageItem";
			this->courseManageItem->Size = System::Drawing::Size(85, 24);
			this->courseManageItem->Text = L"课程管理";
			// 
			// selectNewCourseItem
			// 
			this->selectNewCourseItem->Name = L"selectNewCourseItem";
			this->selectNewCourseItem->Size = System::Drawing::Size(152, 24);
			this->selectNewCourseItem->Text = L"新增选课";
			this->selectNewCourseItem->Click += gcnew System::EventHandler(this, &stuIndexForm::selectCourseItem_Click);
			// 
			// allSelectedCoursesItem
			// 
			this->allSelectedCoursesItem->Name = L"allSelectedCoursesItem";
			this->allSelectedCoursesItem->Size = System::Drawing::Size(152, 24);
			this->allSelectedCoursesItem->Text = L"选课查询";
			this->allSelectedCoursesItem->Click += gcnew System::EventHandler(this, &stuIndexForm::allSelectedCoursesItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// helpItem
			// 
			this->helpItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->responseItem,
					this->aboutSysItem, this->exitItem
			});
			this->helpItem->Name = L"helpItem";
			this->helpItem->Size = System::Drawing::Size(53, 24);
			this->helpItem->Text = L"帮助";
			// 
			// responseItem
			// 
			this->responseItem->Name = L"responseItem";
			this->responseItem->Size = System::Drawing::Size(152, 24);
			this->responseItem->Text = L"反馈信息";
			this->responseItem->Click += gcnew System::EventHandler(this, &stuIndexForm::responseItem_Click);
			// 
			// aboutSysItem
			// 
			this->aboutSysItem->Name = L"aboutSysItem";
			this->aboutSysItem->Size = System::Drawing::Size(152, 24);
			this->aboutSysItem->Text = L"关于系统";
			this->aboutSysItem->Click += gcnew System::EventHandler(this, &stuIndexForm::aboutSysItem_Click);
			// 
			// exitItem
			// 
			this->exitItem->Name = L"exitItem";
			this->exitItem->Size = System::Drawing::Size(152, 24);
			this->exitItem->Text = L"注销";
			this->exitItem->Click += gcnew System::EventHandler(this, &stuIndexForm::exitItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->NowData, this->toolStripStatusLabel2,
					this->NowTime
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 294);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(714, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// NowData
			// 
			this->NowData->Name = L"NowData";
			this->NowData->Size = System::Drawing::Size(0, 17);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 17);
			// 
			// NowTime
			// 
			this->NowTime->Name = L"NowTime";
			this->NowTime->Size = System::Drawing::Size(32, 17);
			this->NowTime->Text = L"时间";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &stuIndexForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(557, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 24);
			this->label1->TabIndex = 2;
			// 
			// 成绩管理ToolStripMenuItem
			// 
			this->成绩管理ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkAllGradeItem });
			this->成绩管理ToolStripMenuItem->Name = L"成绩管理ToolStripMenuItem";
			this->成绩管理ToolStripMenuItem->Size = System::Drawing::Size(85, 24);
			this->成绩管理ToolStripMenuItem->Text = L"成绩管理";
			// 
			// checkAllGradeItem
			// 
			this->checkAllGradeItem->Name = L"checkAllGradeItem";
			this->checkAllGradeItem->Size = System::Drawing::Size(152, 24);
			this->checkAllGradeItem->Text = L"成绩查询";
			this->checkAllGradeItem->Click += gcnew System::EventHandler(this, &stuIndexForm::checkAllGradeItem_Click);
			// 
			// stuIndexForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 316);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->stuIndexMenu);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->stuIndexMenu;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"stuIndexForm";
			this->ShowIcon = false;
			this->Text = L"简易教务管理系统 - 学生端";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &stuIndexForm::stuIndexForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &stuIndexForm::adIndexForm_v4_Load);
			this->stuIndexMenu->ResumeLayout(false);
			this->stuIndexMenu->PerformLayout();
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

		String ^hstr = (h<10) ? ("0" + h.ToString()) : h.ToString();
		String ^mstr = (m<10) ? ("0" + m.ToString()) : m.ToString();
		String ^sstr = (s<10) ? ("0" + s.ToString()) : s.ToString();
		String ^monstr = (mon<10) ? ("0" + mon.ToString()) : mon.ToString();
		String ^datestr = (date<10) ? ("0" + date.ToString()) : date.ToString();

		String ^ dateStr = "当前时间： " + year.ToString() + "-" + monstr + "-" + datestr + "  ";
		String ^ timeStr = hstr + ":" + mstr + ":" + sstr;
		this->NowData->Text = dateStr;
		this->NowTime->Text = timeStr;
	}
	private: System::Void aboutSysItem_Click(System::Object^  sender, System::EventArgs^  e) {
		HelpInfo ^help = gcnew HelpInfo();
		help->StartPosition = FormStartPosition::CenterScreen;
		help->Name = "help";
		help->Show();
	}
	private: System::Void resetPsword_Click(System::Object^  sender, System::EventArgs^  e) {
		updatePasswd ^update = gcnew updatePasswd(thisLogin);
		update->Name = "updatePasswd";
		update->MdiParent = this;
		update->StartPosition = FormStartPosition::CenterParent;
		update->WindowState = FormWindowState::Maximized;
		update->Show();
	}

	private: System::Void adIndexForm_v4_Load(System::Object^  sender, System::EventArgs^  e) {
		string id = thisLogin->getId();
		this->label1->Text = "欢 迎 ";
		this->label1->Text += gcnew String(id.c_str());

	}
	private: System::Void selfInfoItem_Click(System::Object^  sender, System::EventArgs^  e) {
		stuInfo ^stuIn = gcnew stuInfo(thisLogin);
		stuIn->Name = "stuInfo";
		stuIn->MdiParent = this;
		stuIn->StartPosition = FormStartPosition::CenterParent;
		stuIn->WindowState = FormWindowState::Maximized;
		stuIn->Show();
	}
	private: System::Void selectCourseItem_Click(System::Object^  sender, System::EventArgs^  e) {
		selectCourse ^sC = gcnew selectCourse(thisLogin);
		sC->Name = "selectCourse";
		sC->MdiParent = this;
		sC->StartPosition = FormStartPosition::CenterParent;
		sC->WindowState = FormWindowState::Maximized;
		sC->Show();
	}
	private: System::Void allSelectedCoursesItem_Click(System::Object^  sender, System::EventArgs^  e) {
		courseSelected ^cS = gcnew courseSelected(thisLogin);
		cS->Name = "courseSelected";
		cS->MdiParent = this;
		cS->StartPosition = FormStartPosition::CenterParent;
		cS->WindowState = FormWindowState::Maximized;
		cS->Show();
	}
	private: System::Void checkAllGradeItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("本模块将在第五章进行实现");
	}
	private: System::Void exitItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		Application::OpenForms["loginForm1"]->Show();
	}
	private: System::Void responseItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("本模块将在第七章进行实现");
	}
	private: System::Void stuIndexForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
	}
	};

}
