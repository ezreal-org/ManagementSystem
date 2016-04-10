#pragma once
namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// HelpInfo 摘要
	/// </summary>
	public ref class HelpInfo : public System::Windows::Forms::Form
	{
	public:
		HelpInfo(void)
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
		~HelpInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TreeView^  infoTree;
	private: System::Windows::Forms::RichTextBox^  contentDetailBox;

	protected:

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
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"研发环境"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"开发工具"));
			System::Windows::Forms::TreeNode^  treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"系统说明", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
				treeNode1,
					treeNode2
			}));
			System::Windows::Forms::TreeNode^  treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"系统角色"));
			System::Windows::Forms::TreeNode^  treeNode5 = (gcnew System::Windows::Forms::TreeNode(L"功能详解"));
			System::Windows::Forms::TreeNode^  treeNode6 = (gcnew System::Windows::Forms::TreeNode(L"系统功能介绍", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
				treeNode4,
					treeNode5
			}));
			System::Windows::Forms::TreeNode^  treeNode7 = (gcnew System::Windows::Forms::TreeNode(L"联系我们"));
			System::Windows::Forms::TreeNode^  treeNode8 = (gcnew System::Windows::Forms::TreeNode(L"目录", gcnew cli::array< System::Windows::Forms::TreeNode^  >(3) {
				treeNode3,
					treeNode6, treeNode7
			}));
			this->infoTree = (gcnew System::Windows::Forms::TreeView());
			this->contentDetailBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// infoTree
			// 
			this->infoTree->Font = (gcnew System::Drawing::Font(L"楷体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->infoTree->ItemHeight = 25;
			this->infoTree->Location = System::Drawing::Point(19, 9);
			this->infoTree->Margin = System::Windows::Forms::Padding(10);
			this->infoTree->Name = L"infoTree";
			treeNode1->Name = L"cpOne_1";
			treeNode1->Text = L"研发环境";
			treeNode2->Name = L"cpOne_2";
			treeNode2->Text = L"开发工具";
			treeNode3->Name = L"cpOne";
			treeNode3->Text = L"系统说明";
			treeNode4->Name = L"cpTwo_1";
			treeNode4->Text = L"系统角色";
			treeNode5->Name = L"cpTwo_2";
			treeNode5->Text = L"功能详解";
			treeNode6->Name = L"cpTwo";
			treeNode6->Text = L"系统功能介绍";
			treeNode7->Name = L"cpThree";
			treeNode7->Text = L"联系我们";
			treeNode8->Name = L"root";
			treeNode8->Text = L"目录";
			this->infoTree->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode8 });
			this->infoTree->Size = System::Drawing::Size(161, 301);
			this->infoTree->TabIndex = 0;
			this->infoTree->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &HelpInfo::infoTree_AfterSelect);
			// 
			// contentDetailBox
			// 
			this->contentDetailBox->Location = System::Drawing::Point(194, 9);
			this->contentDetailBox->Name = L"contentDetailBox";
			this->contentDetailBox->Size = System::Drawing::Size(475, 301);
			this->contentDetailBox->TabIndex = 1;
			this->contentDetailBox->Text = L"";
			this->contentDetailBox->TextChanged += gcnew System::EventHandler(this, &HelpInfo::richTextBox1_TextChanged);
			// 
			// HelpInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(681, 322);
			this->Controls->Add(this->contentDetailBox);
			this->Controls->Add(this->infoTree);
			this->Name = L"HelpInfo";
			this->Text = L"帮助信息";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void infoTree_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
		//从文件中展示出文本信息；
		if (infoTree->SelectedNode->Text == "目录") {
			return;
		}
		String ^filename = "C:\\managementSystem\\helpInfo \\" + infoTree->SelectedNode->Text + ".rtf";
		try {
			contentDetailBox->LoadFile(filename);
		}
		catch (Exception ^ ex) {
			MessageBox::Show("暂无该小节内容");
		}
	}
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
