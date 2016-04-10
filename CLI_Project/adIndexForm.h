#pragma once
#include "addStu.h"
#include "stuList.h"
#include "addMajor.h"
#include "allMajor.h"
#include "HelpInfo.h"
#include "updatePasswd.h"
#include "allCourseArrangement.h"
#include "addNewCourse.h"

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
	public ref class adIndexForm : public System::Windows::Forms::Form
	{
	public:
		adIndexForm(UserTable* login)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			this->thisLogin = login;
			canQuit = false;
			timer1->Start();
			this->IsMdiContainer = true;
			this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~adIndexForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: UserTable* thisLogin;
	private: bool canQuit;







	protected:


	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  NowDate;














	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  NowTime;
	private: System::Windows::Forms::Timer^  timer1;
			 //private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  show;
	private: System::Windows::Forms::ToolStripMenuItem^  quit;









	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  selfInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  resetPSItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allSelfInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  专业与学生ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addNewMajorItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allMajorsInfoItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addStuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  学生注册ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  allStusItem;
	private: System::Windows::Forms::ToolStripMenuItem^  courseManageItem;
	private: System::Windows::Forms::ToolStripMenuItem^  courseArrange;
	private: System::Windows::Forms::ToolStripMenuItem^  addCourse;
	private: System::Windows::Forms::ToolStripMenuItem^  成绩管理ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  checkGradeItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpItem;
	private: System::Windows::Forms::ToolStripMenuItem^  msgItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutSysItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitItem;
	private: System::Windows::Forms::MenuStrip^  adIndexMenu;













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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(adIndexForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->NowDate = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->NowTime = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->show = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->selfInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetPSItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allSelfInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->专业与学生ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewMajorItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allMajorsInfoItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addStuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->学生注册ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allStusItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->courseManageItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->courseArrange = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourse = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->成绩管理ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkGradeItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msgItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutSysItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adIndexMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->statusStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->adIndexMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->NowDate, this->toolStripStatusLabel2,
					this->NowTime
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 597);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(2, 0, 28, 0);
			this->statusStrip1->Size = System::Drawing::Size(1404, 37);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// NowDate
			// 
			this->NowDate->Name = L"NowDate";
			this->NowDate->Size = System::Drawing::Size(65, 32);
			this->NowDate->Text = L"日期";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 32);
			// 
			// NowTime
			// 
			this->NowTime->Name = L"NowTime";
			this->NowTime->Size = System::Drawing::Size(65, 32);
			this->NowTime->Text = L"时间";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &adIndexForm::timer1_Tick);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->ContextMenuStrip = this->contextMenuStrip1;
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &adIndexForm::notifyIcon1_MouseClick);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->show, this->quit });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(241, 80);
			// 
			// show
			// 
			this->show->Name = L"show";
			this->show->Size = System::Drawing::Size(240, 38);
			this->show->Text = L"显示主界面";
			this->show->Click += gcnew System::EventHandler(this, &adIndexForm::show_Click);
			// 
			// quit
			// 
			this->quit->Name = L"quit";
			this->quit->Size = System::Drawing::Size(240, 38);
			this->quit->Text = L"退出";
			this->quit->Click += gcnew System::EventHandler(this, &adIndexForm::quit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1142, 18);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// selfInfoItem
			// 
			this->selfInfoItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->resetPSItem,
					this->allSelfInfoItem
			});
			this->selfInfoItem->Name = L"selfInfoItem";
			this->selfInfoItem->Size = System::Drawing::Size(157, 41);
			this->selfInfoItem->Text = L"个人中心";
			// 
			// resetPSItem
			// 
			this->resetPSItem->Name = L"resetPSItem";
			this->resetPSItem->Size = System::Drawing::Size(311, 42);
			this->resetPSItem->Text = L"修改密码";
			this->resetPSItem->Click += gcnew System::EventHandler(this, &adIndexForm::resetPassword_Click);
			// 
			// allSelfInfoItem
			// 
			this->allSelfInfoItem->Name = L"allSelfInfoItem";
			this->allSelfInfoItem->Size = System::Drawing::Size(311, 42);
			this->allSelfInfoItem->Text = L"查询个人信息";
			this->allSelfInfoItem->Click += gcnew System::EventHandler(this, &adIndexForm::allSelfInfoItem_Click);
			// 
			// 专业与学生ToolStripMenuItem
			// 
			this->专业与学生ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addNewMajorItem,
					this->allMajorsInfoItem
			});
			this->专业与学生ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->专业与学生ToolStripMenuItem->Name = L"专业与学生ToolStripMenuItem";
			this->专业与学生ToolStripMenuItem->Size = System::Drawing::Size(157, 41);
			this->专业与学生ToolStripMenuItem->Text = L"专业管理";
			// 
			// addNewMajorItem
			// 
			this->addNewMajorItem->Name = L"addNewMajorItem";
			this->addNewMajorItem->Size = System::Drawing::Size(311, 42);
			this->addNewMajorItem->Text = L"新增专业";
			this->addNewMajorItem->Click += gcnew System::EventHandler(this, &adIndexForm::addNewMajorItem_Click);
			// 
			// allMajorsInfoItem
			// 
			this->allMajorsInfoItem->Name = L"allMajorsInfoItem";
			this->allMajorsInfoItem->Size = System::Drawing::Size(311, 42);
			this->allMajorsInfoItem->Text = L"所有专业信息";
			this->allMajorsInfoItem->Click += gcnew System::EventHandler(this, &adIndexForm::allMajorsInfoItem_Click);
			// 
			// addStuItem
			// 
			this->addStuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->学生注册ToolStripMenuItem,
					this->allStusItem
			});
			this->addStuItem->Name = L"addStuItem";
			this->addStuItem->Size = System::Drawing::Size(157, 41);
			this->addStuItem->Text = L"学生管理";
			// 
			// 学生注册ToolStripMenuItem
			// 
			this->学生注册ToolStripMenuItem->Name = L"学生注册ToolStripMenuItem";
			this->学生注册ToolStripMenuItem->Size = System::Drawing::Size(311, 42);
			this->学生注册ToolStripMenuItem->Text = L"学生注册";
			this->学生注册ToolStripMenuItem->Click += gcnew System::EventHandler(this, &adIndexForm::addStu_Click);
			// 
			// allStusItem
			// 
			this->allStusItem->Name = L"allStusItem";
			this->allStusItem->Size = System::Drawing::Size(311, 42);
			this->allStusItem->Text = L"查询学生信息";
			this->allStusItem->Click += gcnew System::EventHandler(this, &adIndexForm::allStuIndo_Click);
			// 
			// courseManageItem
			// 
			this->courseManageItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->courseArrange,
					this->addCourse
			});
			this->courseManageItem->Name = L"courseManageItem";
			this->courseManageItem->Size = System::Drawing::Size(157, 41);
			this->courseManageItem->Text = L"课程管理";
			// 
			// courseArrange
			// 
			this->courseArrange->Name = L"courseArrange";
			this->courseArrange->Size = System::Drawing::Size(247, 42);
			this->courseArrange->Text = L"排课";
			this->courseArrange->Click += gcnew System::EventHandler(this, &adIndexForm::courseArrange_Click);
			// 
			// addCourse
			// 
			this->addCourse->Name = L"addCourse";
			this->addCourse->Size = System::Drawing::Size(247, 42);
			this->addCourse->Text = L"添加课程";
			this->addCourse->Click += gcnew System::EventHandler(this, &adIndexForm::addCourse_Click);
			// 
			// 成绩管理ToolStripMenuItem
			// 
			this->成绩管理ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->checkGradeItem });
			this->成绩管理ToolStripMenuItem->Name = L"成绩管理ToolStripMenuItem";
			this->成绩管理ToolStripMenuItem->Size = System::Drawing::Size(157, 41);
			this->成绩管理ToolStripMenuItem->Text = L"成绩管理";
			// 
			// checkGradeItem
			// 
			this->checkGradeItem->Name = L"checkGradeItem";
			this->checkGradeItem->Size = System::Drawing::Size(247, 42);
			this->checkGradeItem->Text = L"成绩统计";
			this->checkGradeItem->Click += gcnew System::EventHandler(this, &adIndexForm::checkGradeItem_Click);
			// 
			// helpItem
			// 
			this->helpItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->msgItem, this->aboutSysItem,
					this->exitItem
			});
			this->helpItem->Name = L"helpItem";
			this->helpItem->Size = System::Drawing::Size(93, 41);
			this->helpItem->Text = L"帮助";
			// 
			// msgItem
			// 
			this->msgItem->Name = L"msgItem";
			this->msgItem->Size = System::Drawing::Size(311, 42);
			this->msgItem->Text = L"反馈信息处理";
			this->msgItem->Click += gcnew System::EventHandler(this, &adIndexForm::msgItem_Click);
			// 
			// aboutSysItem
			// 
			this->aboutSysItem->Name = L"aboutSysItem";
			this->aboutSysItem->Size = System::Drawing::Size(311, 42);
			this->aboutSysItem->Text = L"关于系统";
			this->aboutSysItem->Click += gcnew System::EventHandler(this, &adIndexForm::aboutSysItem_Click);
			// 
			// exitItem
			// 
			this->exitItem->Name = L"exitItem";
			this->exitItem->Size = System::Drawing::Size(311, 42);
			this->exitItem->Text = L"注销";
			this->exitItem->Click += gcnew System::EventHandler(this, &adIndexForm::exitItem_Click);
			// 
			// adIndexMenu
			// 
			this->adIndexMenu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->adIndexMenu->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->adIndexMenu->ImageScalingSize = System::Drawing::Size(32, 32);
			this->adIndexMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->selfInfoItem, this->专业与学生ToolStripMenuItem,
					this->addStuItem, this->courseManageItem, this->成绩管理ToolStripMenuItem, this->helpItem
			});
			this->adIndexMenu->Location = System::Drawing::Point(0, 0);
			this->adIndexMenu->Name = L"adIndexMenu";
			this->adIndexMenu->Padding = System::Windows::Forms::Padding(6, 4, 0, 4);
			this->adIndexMenu->Size = System::Drawing::Size(1404, 49);
			this->adIndexMenu->TabIndex = 0;
			this->adIndexMenu->Text = L"menuStrip1";
			// 
			// adIndexForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1404, 634);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->adIndexMenu);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->adIndexMenu;
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"adIndexForm";
			this->ShowIcon = false;
			this->Text = L"简易教务管理系统 - 教务员端";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &adIndexForm::adIndexForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &adIndexForm::formClosed);
			this->Load += gcnew System::EventHandler(this, &adIndexForm::adIndexForm_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->adIndexMenu->ResumeLayout(false);
			this->adIndexMenu->PerformLayout();
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

		this->NowDate->Text = dateStr;
		this->NowTime->Text = timeStr;
	}
	private: System::Void aboutSysItem_Click(System::Object^  sender, System::EventArgs^  e) {
		HelpInfo ^help = gcnew HelpInfo();
		help->StartPosition = FormStartPosition::CenterScreen;
		help->Name = "help";
		help->Show();
	}
	private: System::Void resetPassword_Click(System::Object^  sender, System::EventArgs^  e) {
		updatePasswd ^update = gcnew updatePasswd(thisLogin);
		update->Name = "updatePasswd";
		update->MdiParent = this;
		update->StartPosition = FormStartPosition::CenterParent;
		update->WindowState = FormWindowState::Maximized;
		update->Show();
	}
	private: System::Void allStuIndo_Click(System::Object^  sender, System::EventArgs^  e) {
		stuList^ list = gcnew stuList();
		list->Name = "stuList";
		list->MdiParent = this;
		list->StartPosition = FormStartPosition::CenterParent;
		list->WindowState = FormWindowState::Maximized;
		list->Show();
	}
	private: System::Void adIndexForm_Load(System::Object^  sender, System::EventArgs^  e) {
		string id;
		id = thisLogin->getId();
		this->label1->Text = "欢 迎 ";
		this->label1->Text += gcnew String(id.c_str());

	}
	private: System::Void adIndexForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (!canQuit){
			e->Cancel = true;
			this->Hide();
			return;
		}
		Application::Exit();
	}
	private: System::Void notifyIcon1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) //左键显示主窗体
			this->Show();
	}
	private: System::Void show_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Show();
	}
	private: System::Void quit_Click(System::Object^  sender, System::EventArgs^  e) {
		canQuit = true;
		this->Close();
	}


	private: System::Void allSelfInfoItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("相关功能可以参见学生查询个人信息");
	}
	private: System::Void formClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		Application::Exit();
	}
	private: System::Void addStu_Click(System::Object^  sender, System::EventArgs^  e) {
		addStu ^ add = gcnew addStu();
		add->Name = "addStu";
		add->MdiParent = this;
		add->StartPosition = FormStartPosition::CenterParent;
		add->WindowState = FormWindowState::Maximized;
		add->Show();
	}
	private: System::Void addNewMajorItem_Click(System::Object^  sender, System::EventArgs^  e) {
		addMajor ^ add = gcnew addMajor();
		add->Name = "addMajor";
		add->MdiParent = this;
		add->StartPosition = FormStartPosition::CenterParent;
		add->WindowState = FormWindowState::Maximized;
		add->Show();
	}
	private: System::Void allMajorsInfoItem_Click(System::Object^  sender, System::EventArgs^  e) {
		allMajor ^ all = gcnew allMajor();
		all->Name = "allMajor";
		all->MdiParent = this;
		all->StartPosition = FormStartPosition::CenterParent;
		all->WindowState = FormWindowState::Maximized;
		all->Show();
	}
	private: System::Void exitItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::OpenForms["loginForm1"]->Show();
		this->notifyIcon1->Visible = false;
		this->Hide();
	}
	private: System::Void checkGradeItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("该模块将在后续章节案例中讲解");
	}
	private: System::Void courseArrange_Click(System::Object^  sender, System::EventArgs^  e) {
		allCourseArrangement ^courseArrange = gcnew allCourseArrangement();
		courseArrange->Name = "courseArrange";
		courseArrange->MdiParent = this;
		courseArrange->StartPosition = FormStartPosition::CenterParent;
		courseArrange->WindowState = FormWindowState::Maximized;
		courseArrange->Show();
	}
	private: System::Void addCourse_Click(System::Object^  sender, System::EventArgs^  e) {
		addNewCourse ^ addCourse = gcnew addNewCourse();
		addCourse->Name = "addCourse";
		addCourse->MdiParent = this;
		addCourse->StartPosition = FormStartPosition::CenterParent;
		addCourse->WindowState = FormWindowState::Maximized;
		addCourse->Show();
	}
	private: System::Void msgItem_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("该模块将在后续章节案例中讲解");
	}
	};

}
