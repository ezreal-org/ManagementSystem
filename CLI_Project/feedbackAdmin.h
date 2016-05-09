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
			int flag;			//flag��¼�ͻ��˵�״̬��0Ϊ���ߣ�1Ϊ����
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
		~feedbackAdmin() //������Դ
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
	private: Thread^ acceptThread;  //�����߳�
	private: Thread^ keepAlive;     //�����߳�
	private: Thread^ receiveThread;	 //�����߳�
	private: TcpListener^ server;
	private: int clientCx;			//��ǰ�ͻ��˼���
	private:  ClientEntry^ pClientEntryHead; //�ͻ�������ͷ�ڵ�
	private:  ClientEntry^ pClientEntryTail; //�ͻ�������β�ڵ�

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
			this->btn_send->Text = L"����";
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
			this->Text = L"������";
			this->Load += gcnew System::EventHandler(this, &feedbackAdmin::feedbackAdmin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static void clientEntryClean(feedbackAdmin ^pthis)//����ͻ��ˣ�ά���ͻ�������
		{
			char disp[50];
			string dispStr;
			if (pthis->clientCx>0){
				ClientEntry^ pre, ^p;
				pre = p = pthis->pClientEntryHead;
				while (p != nullptr){
					if (p->flag == 0) { //�뿪�Ŀͻ���
						if (p == pthis->pClientEntryHead){
							sprintf(disp, "%s ���뿪...........\r\n", p->name);
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
							sprintf(disp, "%s ���뿪...........\r\n", p->name);
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

		//�����߳�
		static void keepAliveRun(Object^ arg) {
			feedbackAdmin ^pthis = (feedbackAdmin^)(arg);
			int msgLen = 50;
			String^ strSend = gcnew String("");
			cli::array<Byte>^ msg = gcnew cli::array<Byte>(msgLen);
			while (1) {
				if (pthis->clientCx > 0) {
					for (ClientEntry^ p = pthis->pClientEntryHead; p != nullptr; p = p->next) {
						p->flag = 0; //�����пͻ���״̬����Ϊ����
					}
					strSend = "1K"; //������
					msg = Encoding::UTF8->GetBytes(strSend);
					for (ClientEntry^ p = pthis->pClientEntryHead; p != nullptr; p = p->next) {
						try {
							p->sockClient->Send(msg); //�����пͻ��˷�����������
						}
						catch (SocketException^) {
							continue;
						}
					}
				}
				Sleep(2000);//�ȴ�2000ms
							//�����뿪��client
				clientEntryClean(pthis); //���������
			}
		}


		//�����߳�
		static void receiveThreadRun(Object^ arg) {
			feedbackAdmin ^pthis = (feedbackAdmin^)(arg);
			char recvBuf[50];
			string recvStr = "";
			String^ str;
			int msgLen = 50;
			while (1) {
				for (ClientEntry^ p = pthis->pClientEntryHead; p != nullptr; p = p->next) { //�����ͻ����б�
					char name[20];
					sprintf(name, "%s", p->name);
					try {
						if (p->sockClient->Available) {//���׽���������Ϣ�ɽ���
							cli::array<Byte>^ bytes = gcnew cli::array<Byte>(msgLen);
							if (p->sockClient->Receive(bytes) < 0) {
								continue;
							}
							p->flag = 1; //�յ��ͻ�����Ϣ���Ѹÿͻ������óɻ�Ծ״̬
							str = Encoding::UTF8->GetString(bytes);
							sprintf(recvBuf, "%s", str);
							//��һλ��Ϊ��ʶλ�����ֲ�ͬ����Ϣ
							if (recvBuf[0] != '1') { //����ʾ�ǿ�����Ϣ,1��ͷ����Ϣ��ʾ������
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
				Sleep(200); //����CPU����
			}
		}

		//�����߳�
		static void acceptThreadRun(Object^ arg) {
			feedbackAdmin ^pthis = (feedbackAdmin^)(arg);
			int port = 1234;  //�˿ں�Ϊ1234
			int msgLen = 50; //��Ϣ����
			IPAddress^ localAdd = IPAddress::Parse("127.0.0.1");  //������IP��ַΪ��127.0.0.1
			pthis->server = gcnew TcpListener(localAdd, 1234);
			pthis->server->Start();
			Socket^ sockClient = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
			while (pthis->server != nullptr) {
				try {
					sockClient = pthis->server->AcceptSocket();
					//Э�̵õ�client name���ͻ������Ӻ�Լ������������NAME
					cli::array<Byte>^ bytes = gcnew cli::array<Byte>(msgLen);
					if (sockClient->Receive(bytes) > 0) {	//��ӿͻ���ʵ��
						pthis->clientCx++;
						ClientEntry ^ce = gcnew ClientEntry();
						ce->name = Encoding::UTF8->GetString(bytes);
						/*Լ����Ϣ�ĵ�1λΪ���ͱ�ʶ��0��ͷΪNAME��Ϣ��1��ͷΪ��������2��ͷΪ��ͨ��Ϣ����ͨ��Ϣ�Ž�����ʾ*/
						ce->name = ce->name->Substring(1);
						ce->flag = 1;  //�ͻ��˴��ڻ�Ծ״̬
						ce->sockClient = sockClient;
						ce->next = nullptr;
						if (pthis->pClientEntryHead == nullptr) { //ά���ͻ�������
							pthis->pClientEntryHead = ce;
							pthis->pClientEntryTail = ce;
						}
						else {
							pthis->pClientEntryTail->next = ce;
							pthis->pClientEntryTail = ce;
						}
						char temp[50];
						sprintf(temp, "%s", ce->name);
						sprintf(temp, "ѧ��(%s),������....\r\n", ce->name);
						string str = temp;
						pthis->tb_history->Text += gcnew String(str.c_str());
						//����ʷ��Ϣ��tb_history��������ҳ�����
						pthis->tb_history->SelectionStart = pthis->tb_history->Text->Length;
						pthis->tb_history->ScrollToCaret();
					}
				}
				catch (SocketException^) {
					continue;
				}
				Sleep(200);//����CPU����
			}
		}


	private: System::Void feedbackAdmin_Load(System::Object^  sender, System::EventArgs^  e) {
		clientCx = 0;
		acceptThread = gcnew Thread(gcnew ParameterizedThreadStart(feedbackAdmin::acceptThreadRun));
		//���ξ�̬��Ա�̺߳���������thisָ��
		acceptThread->Start(this);  //accept�̺߳������������
		keepAlive = gcnew Thread(gcnew ParameterizedThreadStart(feedbackAdmin::keepAliveRun));
		keepAlive->Start(this);     //keepAlive�̺߳������������
		receiveThread = gcnew Thread(gcnew ParameterizedThreadStart(feedbackAdmin::receiveThreadRun));
		receiveThread->Start(this);    //receive�̺߳������������
		this->stuList->Hide();

	}
	private: System::Void btn_send_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!(this->tb_send->Text->Contains("@"))) {
			//���͸������û�
			this->tb_history->Text += ("��������: " + this->tb_send->Text + "\r\n");
			this->tb_history->SelectionStart = this->tb_history->Text->Length;
			this->tb_history->ScrollToCaret();
			String^ sendStr = gcnew String("");
			sendStr = "2"; //��Ϣ��һλ������Ϣ�����ͣ�2Ϊ��ͨ��Ϣ
			sendStr += this->tb_send->Text->ToString();
			this->tb_send->Text = "";
			for (ClientEntry^ p = pClientEntryHead; p != nullptr; p = p->next) {
				try {
					p->sockClient->Send(Encoding::UTF8->GetBytes(sendStr)); //������Ϣ
				}
				catch (SocketException^) {
					continue;
				}
			}
		}
		else { //ֻ���͸�ָ���û�
			char peerName[20]; //�����͵Ŀͻ�������
			char thisName[20]; //��ǰ����Ŀͻ�������
			int indexOfBlank = this->tb_send->Text->IndexOf(" ");
			sprintf(peerName, "%s", this->tb_send->Text->Substring(1, indexOfBlank - 1));
			String^ sendStr = gcnew String("2");
			sendStr += this->tb_send->Text->Substring(indexOfBlank + 1);
			for (ClientEntry^ p = pClientEntryHead; p != nullptr; p = p->next) {
				sprintf(thisName, "%s", p->name);
				if (strcmp(thisName, peerName) == 0) { //�ҵ�@��Ӧ�ͻ����׽���
					p->sockClient->Send(Encoding::UTF8->GetBytes(sendStr));
					this->tb_history->Text += ("�� " + p->name);
					this->tb_history->Text += ":";
					this->tb_history->Text += (this->tb_send->Text->Substring(indexOfBlank + 1) + "\r\n");
					this->tb_history->SelectionStart = this->tb_history->Text->Length;
					this->tb_history->ScrollToCaret();
					this->tb_send->Text = "";
					return;
				}
			} // for ѭ������
		}//if ������
	} // btn_send_Click�����������

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
