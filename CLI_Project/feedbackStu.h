#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Net;
	using namespace System::Text;
	using namespace Runtime::InteropServices;

	/// <summary>
	/// feedbackStu 
	/// </summary>
	public ref class feedbackStu : public System::Windows::Forms::Form
	{
	public:
		feedbackStu(void)
		{
			InitializeComponent();
			//
			//TODO:  
			//
		}

	protected:
		/// <summary>
		/// 
		/// </summary>
		~feedbackStu()
		{
			if (sockClient != nullptr) //关闭套接字
				sockClient->Close();
			if (recvThread != nullptr && recvThread->IsAlive) //终止接收线程
				recvThread->Abort();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tb_send;
	private: System::Windows::Forms::Button^  btn_send;
	private: System::Windows::Forms::TextBox^  tb_history;
	private:  Thread  ^recvThread;
	private:  Socket  ^sockClient;
	private:
		/// <summary>
		/// 
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 
		/// 
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_send = (gcnew System::Windows::Forms::TextBox());
			this->btn_send = (gcnew System::Windows::Forms::Button());
			this->tb_history = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// tb_send
			// 
			this->tb_send->Location = System::Drawing::Point(24, 282);
			this->tb_send->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->tb_send->Name = L"tb_send";
			this->tb_send->Size = System::Drawing::Size(360, 35);
			this->tb_send->TabIndex = 7;
			// 
			// btn_send
			// 
			this->btn_send->Location = System::Drawing::Point(440, 282);
			this->btn_send->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->btn_send->Name = L"btn_send";
			this->btn_send->Size = System::Drawing::Size(150, 46);
			this->btn_send->TabIndex = 6;
			this->btn_send->Text = L"发送";
			this->btn_send->UseVisualStyleBackColor = true;
			this->btn_send->Click += gcnew System::EventHandler(this, &feedbackStu::btn_send_Click);
			// 
			// tb_history
			// 
			this->tb_history->Enabled = false;
			this->tb_history->Location = System::Drawing::Point(24, 24);
			this->tb_history->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->tb_history->Multiline = true;
			this->tb_history->Name = L"tb_history";
			this->tb_history->ReadOnly = true;
			this->tb_history->Size = System::Drawing::Size(562, 222);
			this->tb_history->TabIndex = 5;
			// 
			// feedbackStu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 358);
			this->Controls->Add(this->tb_send);
			this->Controls->Add(this->btn_send);
			this->Controls->Add(this->tb_history);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"feedbackStu";
			this->Text = L"反馈";
			this->Load += gcnew System::EventHandler(this, &feedbackStu::feedbackStu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//线程函数须为全局函数或者静态函数
		static void receiveThreadRun(Object^ arg)
		{
		//	printf("client-----recvThread created success....\n");
			feedbackStu^ pthis = (feedbackStu^)arg;
			char recvBuf[50];
			String^ str = gcnew String("");
			while (1){
				try {
					str = "";
					cli::array<Byte>^ bytes = gcnew cli::array<Byte>(50);
					Array::Clear(bytes, 0, bytes->Length);
					pthis->sockClient->Receive(bytes);
					str += Encoding::UTF8->GetString(bytes);
				}
				catch (SocketException^){
					return;
				}
				sprintf(recvBuf, "%s", str);
				if (strcmp(recvBuf, "1K") == 0){ //心跳包
					str = "1";
					str += pthis->Name;
					cli::array<Byte>^ replyArray = gcnew cli::array<Byte>(50);
					Array::Clear(replyArray, 0, replyArray->Length);
					replyArray = Encoding::UTF8->GetBytes(str);
					pthis->sockClient->Send(replyArray);
				}
				else{ //普通消息
					//显示普通消息，并把历史纪录滚动到最后
					pthis->tb_history->Text += "管理员: ";
					pthis->tb_history->Text += str->Substring(1);
					pthis->tb_history->Text += "\r\n";
					pthis->tb_history->SelectionStart = pthis->tb_history->Text->Length;
					pthis->tb_history->ScrollToCaret();

				}
			}
		}

		//connect
	private: System::Void feedbackStu_Load(System::Object^  sender, System::EventArgs^  e) {
		int port = 1234;
		int msgLen = 50;
		IPAddress^ ipAdderess = IPAddress::Parse("127.0.0.1");
		IPEndPoint^ remoteEP = gcnew IPEndPoint(ipAdderess, port);
		sockClient = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
		sockClient->Connect(remoteEP);
		String ^str = "0";  //约定0开头的为名字报文
		str += this->Name;
		cli::array<Byte>^ nameBuf = gcnew cli::array<Byte>(msgLen);
		nameBuf = Encoding::UTF8->GetBytes(str);
		this->sockClient->Send(nameBuf); //先发送自己名字让管理员知道
		//create receive Thread
		recvThread = gcnew Thread(gcnew ParameterizedThreadStart(feedbackStu::receiveThreadRun));//启动recv线程
		recvThread->Start(this);
	}
	private: System::Void btn_send_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ sendStr = gcnew String("");
		sendStr = "2";
		sendStr += this->tb_send->Text->ToString();
		this->sockClient->Send(Encoding::UTF8->GetBytes(sendStr));
		this->tb_history->Text += (this->Name + " : " + this->tb_send->Text + "\r\n");
		this->tb_send->Text = "";
		this->tb_history->SelectionStart = this->tb_history->Text->Length;
		this->tb_history->ScrollToCaret();
	}
	};
}
