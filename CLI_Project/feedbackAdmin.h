#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

namespace ManagementSystemV5 {

	using namespace System;
	using namespace Net;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Net::Sockets;
	using namespace System::Text;

	/// <summary>
	/// feedbackAdmin ????
	/// </summary>
	public ref class feedbackAdmin : public System::Windows::Forms::Form
	{
	public:
		ref class ClientEntry
		{
		public:
			String^ name;
			Socket^ sockClient;
			int flag;			//flag记录客户端的状态，0为离线，1为在线
			ClientEntry^ next;
		};

		feedbackAdmin(void)
		{
			InitializeComponent();
			pClientEntryHead = nullptr;
			pClientEntryTail = nullptr;
			server = nullptr;
			acceptThread = nullptr;
			receiveThread = nullptr;
			keepAlive = nullptr;

			//
			//TODO:  
			//
		}

	protected:
		/// <summary>
		/// 
		/// </summary>
		~feedbackAdmin() //清理资源
		{
			if (components){
				delete components;
			}
			if (server != nullptr)
				server->Stop();
			if (acceptThread != nullptr && acceptThread->IsAlive)
				acceptThread->Abort();
		//	printf("clear serverThread.... totel %d \n", clientCx);
			//all client thread clean

			if (receiveThread != nullptr && receiveThread->IsAlive)
				receiveThread->Abort();

			for (ClientEntry^ p = pClientEntryHead; p != nullptr; p = p->next){
				p->sockClient->Close();
			}
			if (keepAlive != nullptr && keepAlive->IsAlive)
				keepAlive->Abort();

		}
	private: System::Windows::Forms::TextBox^  tb_history;
	protected:
	private: System::Windows::Forms::TextBox^  tb_send;
	private: System::Windows::Forms::Button^  btn_send;
	private: Thread^ acceptThread;  //接收线程
	private: Thread^ keepAlive;     //心跳线程
	private: Thread^ receiveThread;	 //接收线程
	private: TcpListener^ server;
	private: int clientCx;			//当前客户端计数
	private:  ClientEntry^ pClientEntryHead; //客户端链表头节点
	private:  ClientEntry^ pClientEntryTail; //客户端链表尾节点

	private: System::Windows::Forms::ListBox^  stuList;

	protected:

	private:
		/// <summary>
		/// 
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_history = (gcnew System::Windows::Forms::TextBox());
			this->tb_send = (gcnew System::Windows::Forms::TextBox());
			this->btn_send = (gcnew System::Windows::Forms::Button());
			this->stuList = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// tb_history
			// 
			this->tb_history->Enabled = false;
			this->tb_history->Location = System::Drawing::Point(12, 12);
			this->tb_history->Multiline = true;
			this->tb_history->Name = L"tb_history";
			this->tb_history->ReadOnly = true;
			this->tb_history->Size = System::Drawing::Size(283, 113);
			this->tb_history->TabIndex = 0;
			// 
			// tb_send
			// 
			this->tb_send->Location = System::Drawing::Point(12, 141);
			this->tb_send->Name = L"tb_send";
			this->tb_send->Size = System::Drawing::Size(182, 21);
			this->tb_send->TabIndex = 4;
			this->tb_send->TextChanged += gcnew System::EventHandler(this, &feedbackAdmin::tb_send_TextChanged);
			// 
			// btn_send
			// 
			this->btn_send->Location = System::Drawing::Point(220, 141);
			this->btn_send->Name = L"btn_send";
			this->btn_send->Size = System::Drawing::Size(75, 23);
			this->btn_send->TabIndex = 3;
			this->btn_send->Text = L"发送";
			this->btn_send->UseVisualStyleBackColor = true;
			this->btn_send->Click += gcnew System::EventHandler(this, &feedbackAdmin::btn_send_Click);
			// 
			// stuList
			// 
			this->stuList->FormattingEnabled = true;
			this->stuList->ItemHeight = 12;
			this->stuList->Location = System::Drawing::Point(25, 165);
			this->stuList->Name = L"stuList";
			this->stuList->Size = System::Drawing::Size(59, 88);
			this->stuList->TabIndex = 5;
			this->stuList->SelectedIndexChanged += gcnew System::EventHandler(this, &feedbackAdmin::listBox1_SelectedIndexChanged);
			// 
			// feedbackAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 180);
			this->Controls->Add(this->stuList);
			this->Controls->Add(this->tb_send);
			this->Controls->Add(this->btn_send);
			this->Controls->Add(this->tb_history);
			this->Name = L"feedbackAdmin";
			this->Text = L"处理反馈";
			this->Load += gcnew System::EventHandler(this, &feedbackAdmin::feedbackAdmin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static void clientEntryClean(feedbackAdmin ^pthis)//清理客户端，维护客户端链表
		{
			char disp[50];
			string dispStr;
			if (pthis->clientCx>0){
				ClientEntry^ pre, ^p;
				pre = p = pthis->pClientEntryHead;
				while (p != nullptr){
					if (p->flag == 0) { //离开的客户端
						if (p == pthis->pClientEntryHead){
							sprintf(disp, "%s 已离开...........\r\n", p->name);
							dispStr = disp;
							pthis->tb_history->Text += gcnew String(dispStr.c_str());
							pthis->tb_history->SelectionStart = pthis->tb_history->Text->Length;
							pthis->tb_history->ScrollToCaret();
							pthis->pClientEntryHead = p->next;
							pre = p;
							p = p->next;
							delete pre;
							pre = p;
							pthis->clientCx--;
						}
						else{
							sprintf(disp, "%s 已离开...........\r\n", p->name);
							dispStr = disp;
							pthis->tb_history->Text += gcnew String(dispStr.c_str());
							pthis->tb_history->SelectionStart = pthis->tb_history->Text->Length;
							pthis->tb_history->ScrollToCaret();
							pre->next = p->next;
							delete p;
							p = pre->next;
							pthis->clientCx--;
						}

					}
					else //
					{
						pre = p;
						p = p->next;
					}
				}
				pthis->pClientEntryTail = pre;
			}
		}

		//心跳线程
		static void keepAliveRun(Object^ arg) {
			feedbackAdmin ^pthis = (feedbackAdmin^)(arg);
			int msgLen = 50;
			String^ strSend = gcnew String("");
			cli::array<Byte>^ msg = gcnew cli::array<Byte>(msgLen);
			while (1) {
				if (pthis->clientCx > 0) {
					for (ClientEntry^ p = pthis->pClientEntryHead; p != nullptr; p = p->next) {
						p->flag = 0; //把所有客户端状态设置为离线
					}
					strSend = "1K"; //心跳包
					msg = Encoding::UTF8->GetBytes(strSend);
					for (ClientEntry^ p = pthis->pClientEntryHead; p != nullptr; p = p->next) {
						try {
							p->sockClient->Send(msg); //给所有客户端发送心跳检测包
						}
						catch (SocketException^) {
							continue;
						}
					}
				}
				Sleep(2000);//等待2000ms
							//清理离开的client
				clientEntryClean(pthis); //定义见下文
			}
		}


		//接收线程
		static void receiveThreadRun(Object^ arg) {
			feedbackAdmin ^pthis = (feedbackAdmin^)(arg);
			char recvBuf[50];
			string recvStr = "";
			String^ str;
			int msgLen = 50;
			while (1) {
				for (ClientEntry^ p = pthis->pClientEntryHead; p != nullptr; p = p->next) { //遍历客户端列表
					char name[20];
					sprintf(name, "%s", p->name);
					try {
						if (p->sockClient->Available) {//该套接字上有消息可接收
							cli::array<Byte>^ bytes = gcnew cli::array<Byte>(msgLen);
							if (p->sockClient->Receive(bytes) < 0) {
								continue;
							}
							p->flag = 1; //收到客户端消息即把该客户端设置成活跃状态
							str = Encoding::UTF8->GetString(bytes);
							sprintf(recvBuf, "%s", str);
							//第一位作为标识位，区分不同类信息
							if (recvBuf[0] != '1') { //仅显示非控制消息,1开头的消息表示心跳包
								char disp[50];
								sprintf(disp, "%s: %s ...\r\n", name, recvBuf + 1);
								recvStr = disp;
								pthis->tb_history->Text += gcnew String(recvStr.c_str());
								pthis->tb_history->SelectionStart = pthis->tb_history->Text->Length;
								pthis->tb_history->ScrollToCaret();
							}
						}
					}
					catch (SocketException^) { continue; }
				}
				Sleep(200); //减少CPU负担
			}
		}

		//接受线程
		static void acceptThreadRun(Object^ arg) {
			feedbackAdmin ^pthis = (feedbackAdmin^)(arg);
			int port = 1234;  //端口号为1234
			int msgLen = 50; //消息长度
			IPAddress^ localAdd = IPAddress::Parse("127.0.0.1");  //服务器IP地址为：127.0.0.1
			pthis->server = gcnew TcpListener(localAdd, 1234);
			pthis->server->Start();
			Socket^ sockClient = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
			while (pthis->server != nullptr) {
				try {
					sockClient = pthis->server->AcceptSocket();
					//协商得到client name，客户端连接后约定会主动发送NAME
					cli::array<Byte>^ bytes = gcnew cli::array<Byte>(msgLen);
					if (sockClient->Receive(bytes) > 0) {	//添加客户端实体
						pthis->clientCx++;
						ClientEntry ^ce = gcnew ClientEntry();
						ce->name = Encoding::UTF8->GetString(bytes);
						/*约定消息的第1位为类型标识，0开头为NAME消息，1开头为心跳包，2开头为普通消息。普通消息才进行显示*/
						ce->name = ce->name->Substring(1);
						ce->flag = 1;  //客户端处于活跃状态
						ce->sockClient = sockClient;
						ce->next = nullptr;
						if (pthis->pClientEntryHead == nullptr) { //维护客户端链表
							pthis->pClientEntryHead = ce;
							pthis->pClientEntryTail = ce;
						}
						else {
							pthis->pClientEntryTail->next = ce;
							pthis->pClientEntryTail = ce;
						}
						char temp[50];
						sprintf(temp, "%s", ce->name);
						sprintf(temp, "学生(%s),已连接....\r\n", ce->name);
						string str = temp;
						pthis->tb_history->Text += gcnew String(str.c_str());
						//把历史消息框tb_history滚动条翻页到最后
						pthis->tb_history->SelectionStart = pthis->tb_history->Text->Length;
						pthis->tb_history->ScrollToCaret();
					}
				}
				catch (SocketException^) {
					continue;
				}
				Sleep(200);//减少CPU负担
			}
		}


	private: System::Void feedbackAdmin_Load(System::Object^  sender, System::EventArgs^  e) {
		clientCx = 0;
		acceptThread = gcnew Thread(gcnew ParameterizedThreadStart(feedbackAdmin::acceptThreadRun));
		//带参静态成员线程函数，传入this指针
		acceptThread->Start(this);  //accept线程函数定义见下文
		keepAlive = gcnew Thread(gcnew ParameterizedThreadStart(feedbackAdmin::keepAliveRun));
		keepAlive->Start(this);     //keepAlive线程函数定义见下文
		receiveThread = gcnew Thread(gcnew ParameterizedThreadStart(feedbackAdmin::receiveThreadRun));
		receiveThread->Start(this);    //receive线程函数定义见下文
		this->stuList->Hide();

	}
	private: System::Void btn_send_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!(this->tb_send->Text->Contains("@"))) {
			//发送给所有用户
			this->tb_history->Text += ("对所有人: " + this->tb_send->Text + "\r\n");
			this->tb_history->SelectionStart = this->tb_history->Text->Length;
			this->tb_history->ScrollToCaret();
			String^ sendStr = gcnew String("");
			sendStr = "2"; //消息第一位代表消息的类型，2为普通消息
			sendStr += this->tb_send->Text->ToString();
			this->tb_send->Text = "";
			for (ClientEntry^ p = pClientEntryHead; p != nullptr; p = p->next) {
				try {
					p->sockClient->Send(Encoding::UTF8->GetBytes(sendStr)); //发送消息
				}
				catch (SocketException^) {
					continue;
				}
			}
		}
		else { //只发送给指定用户
			char peerName[20]; //待发送的客户端姓名
			char thisName[20]; //当前处理的客户端姓名
			int indexOfBlank = this->tb_send->Text->IndexOf(" ");
			sprintf(peerName, "%s", this->tb_send->Text->Substring(1, indexOfBlank - 1));
			String^ sendStr = gcnew String("2");
			sendStr += this->tb_send->Text->Substring(indexOfBlank + 1);
			for (ClientEntry^ p = pClientEntryHead; p != nullptr; p = p->next) {
				sprintf(thisName, "%s", p->name);
				if (strcmp(thisName, peerName) == 0) { //找到@对应客户端套接字
					p->sockClient->Send(Encoding::UTF8->GetBytes(sendStr));
					this->tb_history->Text += ("对 " + p->name);
					this->tb_history->Text += ":";
					this->tb_history->Text += (this->tb_send->Text->Substring(indexOfBlank + 1) + "\r\n");
					this->tb_history->SelectionStart = this->tb_history->Text->Length;
					this->tb_history->ScrollToCaret();
					this->tb_send->Text = "";
					return;
				}
			} // for 循环结束
		}//if 语句结束
	} // btn_send_Click函数定义结束

	private: System::Void tb_send_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->tb_send->Text == "@"){
			this->stuList->Items->Clear();
			for (ClientEntry^ p = pClientEntryHead; p != nullptr; p = p->next){
				this->stuList->Items->Add(p->name);
			}
			this->stuList->Show();
		}
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		this->tb_send->Text += this->stuList->SelectedItem->ToString();
		this->tb_send->Text += " ";
		this->stuList->Hide();
	}
	};
}
