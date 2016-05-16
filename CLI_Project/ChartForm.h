#pragma once
#include "storage.h"
#include "memberInfo.h"
#include "memberService.h"
#include "TypeDefinition.h"

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ChartForm ժҪ
	/// </summary>
	public ref class ChartForm : public System::Windows::Forms::Form
	{
	public:
		ChartForm(UserTable *user)
		{
			this->loginUser = user;
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//

			cli::array<Color > ^temp = { Color::Aqua ,Color::LightSalmon,Color::LightSeaGreen,Color::LightSlateGray,Color::Lime,Color::Magenta,
				Color::Blue, Color::Maroon,Color::MediumAquamarine,Color::MediumOrchid,Color::MediumPurple,Color::Chartreuse,Color::Brown,
				Color::Olive,Color::Crimson,Color::DarkSalmon,Color::DarkSlateBlue,Color::DarkTurquoise ,Color::PaleVioletRed,Color::Gray,
				Color::LawnGreen,Color::LightBlue,Color::Violet ,Color::SkyBlue,Color::SandyBrown ,Color::Indigo };
			this->colorArray = temp;
			setDataType(this->loginUser->getType());
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~ChartForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:cli::array<Color> ^colorArray;
	protected:int *dataArray;
	protected:int dataArrayLen;
	protected:int valueOfXGrid;
	protected:int valueOfYGrid;
	protected:String ^xLabel;  //�����꣬���������
	protected:String ^yLabel;
	protected:String ^title; // ͼ�����
	private: UserTable *loginUser;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  dataTypeCombox;
	private: System::Windows::Forms::Button^  cleanButton;
	private: System::Windows::Forms::Button^  pieButton;

	private: System::Windows::Forms::Button^  polylineButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  histogramButton;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  indexLabel;
	private: System::Windows::Forms::ComboBox^  indexCombox;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataTypeCombox = (gcnew System::Windows::Forms::ComboBox());
			this->cleanButton = (gcnew System::Windows::Forms::Button());
			this->pieButton = (gcnew System::Windows::Forms::Button());
			this->polylineButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->histogramButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->indexLabel = (gcnew System::Windows::Forms::Label());
			this->indexCombox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(170, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 14);
			this->label2->TabIndex = 15;
			this->label2->Text = L"���ݲ�ѯѡ��";
			// 
			// dataTypeCombox
			// 
			this->dataTypeCombox->FormattingEnabled = true;
			this->dataTypeCombox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"��ѡ���ѯ��������" });
			this->dataTypeCombox->Location = System::Drawing::Point(276, 19);
			this->dataTypeCombox->Name = L"dataTypeCombox";
			this->dataTypeCombox->Size = System::Drawing::Size(146, 20);
			this->dataTypeCombox->TabIndex = 14;
			this->dataTypeCombox->SelectedIndexChanged += gcnew System::EventHandler(this, &ChartForm::dataTypeCombox_SelectedIndexChanged);
			// 
			// cleanButton
			// 
			this->cleanButton->Location = System::Drawing::Point(48, 350);
			this->cleanButton->Name = L"cleanButton";
			this->cleanButton->Size = System::Drawing::Size(75, 23);
			this->cleanButton->TabIndex = 13;
			this->cleanButton->Text = L"���";
			this->cleanButton->UseVisualStyleBackColor = true;
			this->cleanButton->Click += gcnew System::EventHandler(this, &ChartForm::cleanButton_Click);
			// 
			// pieButton
			// 
			this->pieButton->Location = System::Drawing::Point(48, 272);
			this->pieButton->Name = L"pieButton";
			this->pieButton->Size = System::Drawing::Size(75, 23);
			this->pieButton->TabIndex = 12;
			this->pieButton->Text = L"����ͼ";
			this->pieButton->UseVisualStyleBackColor = true;
			this->pieButton->Click += gcnew System::EventHandler(this, &ChartForm::pieButton_Click);
			// 
			// polylineButton
			// 
			this->polylineButton->Location = System::Drawing::Point(48, 187);
			this->polylineButton->Name = L"polylineButton";
			this->polylineButton->Size = System::Drawing::Size(75, 23);
			this->polylineButton->TabIndex = 11;
			this->polylineButton->Text = L"����ͼ";
			this->polylineButton->UseVisualStyleBackColor = true;
			this->polylineButton->Click += gcnew System::EventHandler(this, &ChartForm::polylineButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(24, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 19);
			this->label1->TabIndex = 10;
			this->label1->Text = L"ѧ����Ϣͳ��";
			// 
			// histogramButton
			// 
			this->histogramButton->Location = System::Drawing::Point(48, 96);
			this->histogramButton->Name = L"histogramButton";
			this->histogramButton->Size = System::Drawing::Size(75, 23);
			this->histogramButton->TabIndex = 9;
			this->histogramButton->Text = L"ֱ��ͼ";
			this->histogramButton->UseVisualStyleBackColor = true;
			this->histogramButton->Click += gcnew System::EventHandler(this, &ChartForm::histogramButton_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(179, 60);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(500, 351);
			this->panel1->TabIndex = 8;
			// 
			// indexLabel
			// 
			this->indexLabel->AutoSize = true;
			this->indexLabel->Location = System::Drawing::Point(446, 24);
			this->indexLabel->Name = L"indexLabel";
			this->indexLabel->Size = System::Drawing::Size(17, 12);
			this->indexLabel->TabIndex = 16;
			this->indexLabel->Text = L"\"\"";
			// 
			// indexCombox
			// 
			this->indexCombox->FormattingEnabled = true;
			this->indexCombox->Location = System::Drawing::Point(516, 20);
			this->indexCombox->Name = L"indexCombox";
			this->indexCombox->Size = System::Drawing::Size(163, 20);
			this->indexCombox->TabIndex = 17;
			this->indexCombox->SelectedIndexChanged += gcnew System::EventHandler(this, &ChartForm::indexCombox_SelectedIndexChanged);
			// 
			// ChartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(702, 430);
			this->Controls->Add(this->indexCombox);
			this->Controls->Add(this->indexLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataTypeCombox);
			this->Controls->Add(this->cleanButton);
			this->Controls->Add(this->pieButton);
			this->Controls->Add(this->polylineButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->histogramButton);
			this->Controls->Add(this->panel1);
			this->Name = L"ChartForm";
			this->Text = L"ͳ����Ϣ";
			this->Load += gcnew System::EventHandler(this, &ChartForm::ChartForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//�����ʼ��
	private: System::Void ChartForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->indexCombox->Visible = false;
		this->indexLabel->Visible = false;
	}

			 /*
			 ��XY�᣺Ĭ�����̶ȴ�0��ʼ���������壺x��̶ȵ�����ÿ��ֵ���٣� Y��̶ȵ�����ÿ��ֵ����
			 */
	private: Graphics ^ drawXYByPara(int xPointsNum, int valueOfOneXGrid, int yPointsNum, int valueOfOneYGrid) {
		Pen ^ XYPen = gcnew Pen(Color::Red, 2.0f);
		XYPen->LineJoin = Drawing2D::LineJoin::Miter;
		//pen->EndCap = LineCap::ArrowAnchor; //�˾仰�û���������ļ�ͷ����������Ч�����ã������ֶ���ӣ�
		Graphics ^mg = this->panel1->CreateGraphics();
		Drawing::Font ^font = gcnew Drawing::Font("����", 8);
		SolidBrush ^fontBrush = gcnew SolidBrush(Color::Red);

		//xy����
		mg->DrawLine(XYPen, 50, 310, 50, 10);
		mg->DrawLine(XYPen, 450, 310, 50, 310);
		//xy��˵��ͷ
		mg->DrawLine(XYPen, 50, 10, 45, 15);
		mg->DrawLine(XYPen, 50, 10, 55, 15);
		mg->DrawLine(XYPen, 450, 310, 445, 305);
		mg->DrawLine(XYPen, 450, 310, 445, 315);

		//���ݲ�����xy�����������ÿ���̶ȳ���
		int yLen = 280 / yPointsNum;  //y�᳤300��������20����ֵ����˿̻��̶ȵĳ���ʣ��280
		int xLen = 380 / xPointsNum;  //X�᳤400�� �����˶���20���أ�ʣ��380��
		int currentX = 0, currentY = 0;

		//�̻�Y���Ͽ̶ȵ�
		for (int i = 1; i <= yPointsNum; i++) {
			currentY += yLen;
			String ^s1 = "" + i * valueOfOneYGrid;
			mg->DrawLine(XYPen, 48, 310 - currentY, 52, 310 - currentY);
			mg->DrawString(s1, font, fontBrush, 25, 310 - currentY);
		}
		mg->DrawString(yLabel, font, fontBrush, 5, 10);

		//�̻�X���Ͽ̶ȵ�
		for (int i = 1; i <= xPointsNum; i++) {
			currentX += xLen;
			String ^s1 = "" + i * valueOfOneXGrid;
			mg->DrawLine(XYPen, 50 + currentX, 308, 50 + currentX, 312);
			mg->DrawString(s1, font, fontBrush, 45 + currentX, 315);
		}
		mg->DrawString(xLabel, font, fontBrush, 460, 315);
		delete XYPen;
		return mg;
	}

			 /*
			 ��ֱ��ͼ�� ������Դ���ݣ����鳤�ȣ�X��̶ȼ��ֵ,�Լ�Y��̶ȵ������
			 */
	private:void drawHistogram(int data[], int dataLen, int valueOfOneXGrid, int valueOfOneYGrid) {
		int maxOfData = getMax(data, dataLen); //��ȡ����ֵ��Ȼ��õ�Y��ÿһ�̶ȼ�����٣�
		if (maxOfData == 0) {
			MessageBox::Show("����ͳ������");
			return;
		}
		maxOfData = maxOfData % 10 == 0 ? maxOfData : ((maxOfData / 10) + 1) * 10;
		int yPointsNum = maxOfData / valueOfOneYGrid;

		Pen ^rectPen = gcnew Pen(Color::Black, 1.5f);
		SolidBrush ^rectBrush = gcnew SolidBrush(Color::LightBlue);

		Graphics ^mg = drawXYByPara(dataLen, valueOfOneXGrid, yPointsNum, valueOfOneYGrid); //��xy��  //���ݲ�����xy�����������ÿ���̶ȳ���
		int yLen = 280 / yPointsNum;  //y�᳤300��������20����ֵ����˿̻��̶ȵĳ���ʣ��280
		int xLen = 380 / dataLen;  //X�᳤400�� �����˶���20���أ�ʣ��380��
		int currentX = 50, currentY = 0; //X��ǰ��Ԥ��

		for (int i = 0; i <dataLen; i++) {
			// VS��Y�᷽������ѧ��Y�᷽���෴�������Ҫ��Y�᳤�ȣ���ȥ��ǰ�����ȣ��õ���Y����ֵ��
			int height = (data[i] * yLen) / valueOfOneYGrid;
			int startY = 310 - height;

			//�����ȡ��ɫ��
			rectPen->Color = getRamColor(i);
			rectBrush->Color = getRamColor(i);
			mg->FillRectangle(rectBrush, currentX, startY, xLen, height); //�����ɫ
			mg->DrawRectangle(rectPen, currentX, startY, xLen, height);   //��ߣ�
			currentX += xLen;
		}

		//���²���һ��XY�᣻
		drawXYByPara(dataLen, valueOfOneXGrid, yPointsNum, valueOfOneYGrid);
		Drawing::Font ^font = gcnew Drawing::Font("����", 12);
		SolidBrush ^fontBrush = gcnew SolidBrush(Color::Black);
		mg->DrawString(title, font, fontBrush, 180, 15);  //����ͼ�����
		delete rectPen;
		delete rectBrush;
		delete fontBrush;
	}

			/*
			������ͼ�� ������Դ���ݣ����鳤�ȣ�X��̶ȼ��ֵ,�Լ�Y��̶ȵ������
			����ͼ�൱�ںܶ���߶����Ӷ��ɣ���˻�������ͼ��Ҫһ��һ��������
			*/
	private:void drawPolyline(int data[], int dataLen, int valueOfOneXGrid, int valueOfOneYGrid) {
		int maxOfData = getMax(data, dataLen); //��ȡ����ֵ��Ȼ��õ�Y��ÿһ�̶ȼ�����٣�
		if (maxOfData == 0) {
			MessageBox::Show("����ͳ������");
			return;
		}
		maxOfData = maxOfData % 10 == 0 ? maxOfData : ((maxOfData / 10) + 1) * 10;
		int numOfYPoint = maxOfData / valueOfOneYGrid;

		//���ݲ�����xy�����������ÿ���̶ȳ���
		int yLen = 280 / numOfYPoint;  //y�᳤300��������20����ֵ����˿̻��̶ȵĳ���ʣ��280
		int xLen = 380 / dataLen;  //X�᳤400�� �����˶���20���أ�ʣ��380��
		int currentX = 50 + xLen*0.5, currentY = 0; //X��ǰ��Ԥ��

													//�õ���һ���������
		int height = (data[0] * yLen) / valueOfOneYGrid;
		int startY = 310 - height;

		Point current = Point(currentX, startY); //��һ���㣻
		Pen ^linePen = gcnew Pen(getRamColor(15), 3.0f);
		Graphics ^mg = drawXYByPara(dataLen, valueOfOneXGrid, numOfYPoint, valueOfOneYGrid); //����������
		for (int i = 1; i < dataLen; i++) {  //���������㣬 ������ߣ�
			currentX += xLen;
			height = (data[i] * yLen) / valueOfOneYGrid;
			startY = 310 - height;
			Point point = Point(currentX, startY);
			mg->DrawLine(linePen, current, point);
			current = point;
		}


		drawXYByPara(dataLen, valueOfOneXGrid, numOfYPoint, valueOfOneYGrid); //�ٴ����һ��XY�᣻
		Drawing::Font ^font = gcnew Drawing::Font("����", 12);
		SolidBrush ^fontBrush = gcnew SolidBrush(Color::Black);
		mg->DrawString(title, font, fontBrush, 180, 15);  //����ͼ�����
		delete linePen;
		delete fontBrush;
	}

			/*
			��������ͼ����Ҫ������������������Դ�����ݳ��ȣ�ÿһ����������ʾ��ʵ���ݵ�������ɼ�10-20�֣���һ�����α�ʾ
			*/
	private:void drawSector(int data[], int dataLen, int valueOfOneSector) {
		double *b = new double[dataLen];
		int sum = 0;
		for (int i = 0; i <dataLen; i++) {
			sum += data[i];
		}
		if (sum == 0) {
			MessageBox::Show("����ͳ������");
			return;
		}
		for (int i = 0; i <dataLen; i++) {
			b[i] = data[i] * 330 * 1.0 / sum;
		}

		Graphics ^my = this->panel1->CreateGraphics();
		Pen ^piePen = gcnew Pen(Color::Brown, 2.0f);
		SolidBrush ^pieBrush = gcnew SolidBrush(Color::Brown);
		Drawing::Font ^strFont = gcnew Drawing::Font("����", 12);
		SolidBrush ^strBrush = gcnew SolidBrush(Color::Red);
		double current = 0;
		String ^subLabel = "����";

		for (int i = 0; i <dataLen; i++) {
			double x = data[i] * 1.0 / sum;
			String ^s = x.ToString("P");
			String ^ str = (i)*valueOfOneSector + " - " + (i + 1)*valueOfOneSector + " :" + s;
			piePen->Color = getRamColor(i);
			pieBrush->Color = getRamColor(i);
			strBrush->Color = getRamColor(i);

			my->DrawPie(piePen, 80, 80, 250, 200, current, b[i]);
			my->FillPie(pieBrush, 80, 80, 250, 200, current, b[i]);
			my->DrawString(str, strFont, strBrush, 350, 50 + i * 25);
			current += b[i] + 3;
		}
		strBrush->Color = Color::Black;
		my->DrawString(title, strFont, strBrush, 100, 25);  //����ͼ�����
		my->DrawString(xLabel, strFont, strBrush, 345, 25);
		my->DrawString(subLabel, strFont, strBrush, 395, 25);
		delete piePen;
		delete pieBrush;
		delete strBrush;
	}

			/*
			��ȡ���������ֵ
			*/
	private:int getMax(int a[], int len) {
		int max = a[0];
		for (int i = 1; i<len; i++) {
			if (max<a[i])max = a[i];
		}
		return max;
	}

			/*
			�����ȡ��ɫ����
			*/
	private:Color getRamColor(int i) {
		Random ^t = gcnew Random(i);
		int r = t->Next() % 26;
		return colorArray[r];
	}

			/*
			��ջ�������������
			*/
	private:void cleanAll() {
		Graphics ^my = this->panel1->CreateGraphics();
		Color color = BackColor; //��ȡ������ɫ
		my->Clear(color);  //��գ�
	}

			/*
			ͨ��רҵid����ȡĳרҵ����ѧ������ѧ�ֲַ��������
			*/
	private:void getMajorCreditInfo(String ^marjorID) {
		AcademicStaff * acaStaff = new AcademicStaff();
		Major * m = acaStaff->readMajorInfo((char*)Marshal::StringToHGlobalAnsi(marjorID).ToPointer());
		int size = m->getRequiredScore() / 10 + 1;
		int * numOfArray = new int[size]();
		cli::array<int >^ source = acaStaff->getOneMajorStuCreditDistribution(m);

		for each(int src in source) {
			if (src == (size / 10 + 1) * 10)numOfArray[size--]++;
			else if (src % 10 == 0 || src != 0) { numOfArray[src / 10]++; }
			else numOfArray[src / 10]++;
		}

		this->dataArrayLen = size;
		this->valueOfXGrid = 10;  //����X����ÿһ���̶���ʵ����ʾ��ֵ����ѯѧ�֣���Ϊ10��ÿһ�����
		this->valueOfYGrid = 5;  //��������5��ÿһ�������
		dataArray = new int[this->dataArrayLen];
		for (int i = 0; i < this->dataArrayLen; i++) {
			this->dataArray[i] = numOfArray[i];
		}
	}
			/*
			ͨ���γ�ID ����ȡѡ�޸ÿγ�����ѧ���ɼ��ֲ�����
			*/
	private: void getCourseGradeInfo(String ^courseID) {
		String ^courseCode;
		char id[20];
		Teacher *tea = new Teacher();
		int numOfArray[10] = { 0,0,0,0,0,0,0,0,0,0 };
		cli::array<int >^ source = tea->getOneCourseScoreDistribution((char *)(Marshal::StringToHGlobalAnsi(courseID).ToPointer()));

		for each(int src in source) {
			if (src >= 100)numOfArray[9]++;
			else if (src % 10 == 0 || src != 0) { numOfArray[src / 10]++; }
			else numOfArray[src / 10]++;
		}
		this->dataArrayLen = sizeof(numOfArray) / sizeof(int);
		this->valueOfXGrid = 10;  //����X����ÿһ���̶���ʵ����ʾ��ֵ���˴���ѯ�ɼ�����Ϊ10��ÿһ�����
		this->valueOfYGrid = 5;  //��������5��ÿһ�������
		dataArray = new int[this->dataArrayLen];

		int a[] = { 1,3,8,10,15,20,30,25,10,5 };
		for (int i = 0; i < this->dataArrayLen; i++) {
			cout << numOfArray[i] << " ";
			this->dataArray[i] = numOfArray[i] + a[i];
		}
	}

			 /*
			 ͨ��ѧ��ID ��ȡѧ�����гɼ����ݣ����л�ͼ��
			 */
	private:void getStuGradeInfo(String ^stuID) {
		Student * stu = new Student();
		int numOfArray[10] = { 0,0,0,0,0,0,0,0,0,0 };
		cli::array < String ^ >^  allCourse = stu->getAllSelfSelectedCourses((char *)(Marshal::StringToHGlobalAnsi(stuID).ToPointer()));

		for each (String ^ cid in allCourse) {
			cid += " ";
			cid += stuID;
			selectedCourse *p = stu->getSelectedCourseInfo((char *)Marshal::StringToHGlobalAnsi(cid).ToPointer());
			int src = p->getScore();
			if (src >= 100)numOfArray[9]++;
			else if (src % 10 == 0 || src != 0) { numOfArray[src / 10]++; }
			else numOfArray[src / 10]++;
		}

		this->dataArrayLen = sizeof(numOfArray) / sizeof(int);
		this->valueOfXGrid = 10;  //����X����ÿһ���̶���ʵ����ʾ��ֵ���˴���ѯ�ɼ�����Ϊ10��ÿһ�����
		this->valueOfYGrid = 1;  //��������5��ÿһ�������
		dataArray = new int[this->dataArrayLen];

		//int a[] = { 0,0,0,0,0,1,2,20,15,6 };
		for (int i = 0; i < this->dataArrayLen; i++) {
			this->dataArray[i] = numOfArray[i];// +a[i];
		}
	}

			/*
			�����û�����ݣ����ÿɲ�ѯ���������ѡ��
			*/
	private:void setDataType(int type) {
		int t = type;
		switch (t) {
		case (int)UserTypeCode::USER_ACADEMICSTAFF: { //����Ա
			if (dataTypeCombox->Items->Count>0)dataTypeCombox->Items->Clear();
			dataTypeCombox->Items->Add(gcnew String("��ѯ��רҵѧ��ѧ���޶����"));
			dataTypeCombox->Items->Add(gcnew String("��ѯ���γ̳ɼ�"));
			dataTypeCombox->Items->Add(gcnew String("��ѯ��ѧ���γ̳ɼ�ͳ��"));
			break;
		}
		case (int)UserTypeCode::USER_TEACHER: {   //��ʦ
			if (dataTypeCombox->Items->Count>0)dataTypeCombox->Items->Clear();
			dataTypeCombox->Items->Add(gcnew String("��ѯ���γ̳ɼ�"));
			break;
		}
		default: { //����ϵͳ����Ա�޷����ʸý��棬��������û���������Ϊ��ѧ��
			if (dataTypeCombox->Items->Count>0)dataTypeCombox->Items->Clear();
			dataTypeCombox->Items->Add(gcnew String("��ѯ�γ̳ɼ�ͳ��"));
			dataTypeCombox->Visible = false;
			indexCombox->Visible = false;
			indexLabel->Visible = false;
			label2->Visible = false;

			string stuid = this->loginUser->getId();
			String ^myID = gcnew String(stuid.c_str());
			getStuGradeInfo(myID);
			xLabel = "�ɼ�";
			yLabel = "��Ŀ��";
			title = "ѧ�����˳ɼ��ֲ����";
			break;
		}
		}
	}

			//ѡ��ĳһ������в�ѯ��
	private: System::Void dataTypeCombox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int userType = this->loginUser->getType(); //��ȡ��ǰ��¼�û�����

		if (userType == (int)UserTypeCode::USER_ACADEMICSTAFF) { //����Ա��¼
			int selectedIndex = dataTypeCombox->SelectedIndex; //�������ѯ����������
			this->indexLabel->Visible = true;
			this->indexCombox->Visible = true;
			switch (selectedIndex) {
			case 0: {  //ѡ��dataTypeCombox�е�һ���ѯĳһרҵѧ��ѧ���޶����
				indexLabel->Text = "��ѡ��רҵ��";
				xLabel = "ѧ�ֶ�";
				yLabel = "����";
				title = "ѧ���ѻ�ѧ�ֲַ����";
				indexCombox->Items->Clear();
				//���ļ��У���ȡ����רҵ����������ѡ���У�
				AcademicStaff *staff;
				Major *p;
				char idName[50];
				string strTemp;
				cli::array<String ^> ^list = staff->getAllMajorSummarayInfo();
				for each (String ^a in list) {
					sprintf(idName, "%s", a);
					p = staff->readMajorInfo(idName);
					strTemp = idName;
					strTemp += "-";
					strTemp += p->getMajorName();
					strTemp += p->getType() == ((int)UserTypeCode::USER_GRADUATE) ? "-˶ʿ" : "-����";
					indexCombox->Items->Add(gcnew String(strTemp.c_str()));
				}
				break;
			}
			case 1: {  //ѡ��dataTypeCombox�ڶ�� ��ѯ���γ�ѧ���ɼ�
				indexLabel->Text = "��ѡ��γ̣�";
				xLabel = "�ɼ�";
				yLabel = "����";
				title = "�ÿ�ѧ���ɼ��ֲ����";
				indexCombox->Items->Clear();
				//���ļ��У���ȡ���пγ̣���������ѡ���У�
				char id[20];
				string courseName;
				Student *stu = new Student();
				AcademicStaff *acastaff = new AcademicStaff();
				cli::array<String^>^ list = stu->getAllCourseArrangementId();
				for each(String ^item in list) {
					String ^cid = (item->Split(' '))[0];
					sprintf(id, "%s", cid);
					cout << id << endl;
					Course * c = acastaff->readCourseInfo(id);
					courseName = c->getCourseName();

					item += "-";
					item += gcnew String(courseName.c_str());
					item += c->getType() == ((int)UserTypeCode::USER_GRADUATE) ? "-˶ʿ" : "-����";
					indexCombox->Items->Add(item);
				}
				break;
			}
			default: {
				indexLabel->Text = "��ѡ��ѧ����";
				xLabel = "�ɼ�";
				yLabel = "�γ���";
				title = "ѧ�����޿γ̳ɼ����";
				indexCombox->Items->Clear();
				//���ļ��У���ȡ����ѧ������������ѡ���У�
				AcademicStaff *staff;
				char id[20];
				cli::array<String ^> ^list = staff->getAllStuSummaryInfo(3);
				cli::array<String ^> ^list1 = staff->getAllStuSummaryInfo(4);
				String ^stuName;
				string name;
				for each (String ^a in list) {
					sprintf(id, "%s", a);
					GraduateTable *gradStu = staff->readGraduateInfo(id);
					name = gradStu->getId();
					name += "-";
					name += gradStu->getName();
					stuName = gcnew String(name.c_str());
					indexCombox->Items->Add(stuName);
				}
				for each (String ^a in list1) {
					sprintf(id, "%s", a);
					UndergraduateTable * undstu = staff->readUndergraduateInfo(id);
					name = undstu->getId();
					name += "-";
					name += staff->readUndergraduateInfo(id)->getName();
					stuName = gcnew String(name.c_str());
					indexCombox->Items->Add(stuName);
				}
				break;
			}
			}
		}
		else {   //ϵͳ����Ա�޷����ʸý��棬 ѧ���û�����ÿؼ�����һ��������������µ���Ϊ��ʦ��¼
			indexLabel->Text = "��ѡ��γ̣�";
			xLabel = "�ɼ�";
			yLabel = "����";
			title = "�γ�ѧ���ɼ��ֲ����";
			//�˴���ȡ�����οογ̣� ����������ѡ��
			indexCombox->Items->Clear();
			char id[20];
			string courseName;
			Teacher *tea = new Teacher();
			cli::array<String^>^ list = tea->getSelfTeachCourseCode(loginUser->getId());
			for each(String ^item in list) {
				String ^cid = (item->Split(' '))[0];
				sprintf(id, "%s", cid);
				cout << id << endl;
				Course * c = tea->readCourseInfo(id);
				courseName = c->getCourseName();

				item += "-";
				item += gcnew String(courseName.c_str());
				item += c->getType() == ((int)UserTypeCode::USER_GRADUATE) ? "-˶ʿ" : "-����";
				indexCombox->Items->Add(item);
			}

			this->indexLabel->Visible = true;
			this->indexCombox->Visible = true;
		}
	}

			 //�����ѯĳһ������
	private: System::Void indexCombox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int searchType = dataTypeCombox->SelectedIndex;
		int searchIndex = indexCombox->SelectedIndex;
		String ^name = indexCombox->SelectedItem->ToString();
		String ^ id = (name->Split('-'))[0];

		if (loginUser->getType() == (int)UserTypeCode::USER_ACADEMICSTAFF) {  // ����Ա��¼
			switch (searchType) {
			case 0: {
				getMajorCreditInfo(id);   //��ѯ��רҵѧ��ѧ���޶����
				break;
			}
			case 1: {
				id = (id->Split(' '))[0];
				getCourseGradeInfo(id);  //��ѯ���γ�ѧ���ɼ��ֲ����
				break;
			}
			default: {
				getStuGradeInfo(id);    //��ѯѧ�����Ƴɼ��ֲ����
				break;
			}
			}
		}

		if (loginUser->getType() == (int)UserTypeCode::USER_TEACHER) {
			id = (id->Split(' '))[0];
			getCourseGradeInfo(id); //��ѯ���γ�ѧ���ɼ��ֲ����
		}

	}

			 //ֱ��ͼ��ť�¼���Ӧ
	private: System::Void histogramButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataArray == nullptr || this->valueOfXGrid == 0 || this->valueOfYGrid == 0 || getMax(this->dataArray, this->dataArrayLen) <= 0) {
			MessageBox::Show("δ��ȡ��ѯ����");
		}
		else {
			cleanAll();
			drawHistogram(this->dataArray, this->dataArrayLen, this->valueOfXGrid, this->valueOfYGrid);
		}
	}

			 //����ͼ��ť�¼���Ӧ
	private: System::Void polylineButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataArray == nullptr || this->valueOfXGrid == 0 || this->valueOfYGrid == 0 || getMax(this->dataArray, this->dataArrayLen) <= 0) {
			MessageBox::Show("δ��ȡ��ѯ����");
		}
		else {
			cleanAll();
			drawPolyline(this->dataArray, this->dataArrayLen, this->valueOfXGrid, this->valueOfYGrid);
		}
	}

			 //����ͼ��ť�¼���Ӧ
	private: System::Void pieButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataArray == nullptr || this->valueOfXGrid == 0 || getMax(this->dataArray, this->dataArrayLen) <= 0) {
			MessageBox::Show("δ��ȡ��ѯ����");
		}
		else {
			cleanAll();
			drawSector(this->dataArray, this->dataArrayLen, this->valueOfXGrid);
		}
	}

			 //�����ť�¼���Ӧ
	private: System::Void cleanButton_Click(System::Object^  sender, System::EventArgs^  e) {
		cleanAll();
	}
	};
}
