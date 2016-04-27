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
	/// ChartForm 摘要
	/// </summary>
	public ref class ChartForm : public System::Windows::Forms::Form
	{
	public:
		ChartForm(UserTable *user)
		{
			this->loginUser = user;
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
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
		/// 清理所有正在使用的资源。
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
	protected:String ^xLabel;  //横坐标，纵坐标标题
	protected:String ^yLabel;
	protected:String ^title; // 图标标题
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
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(170, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 14);
			this->label2->TabIndex = 15;
			this->label2->Text = L"数据查询选择：";
			// 
			// dataTypeCombox
			// 
			this->dataTypeCombox->FormattingEnabled = true;
			this->dataTypeCombox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"请选择查询数据类型" });
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
			this->cleanButton->Text = L"清空";
			this->cleanButton->UseVisualStyleBackColor = true;
			this->cleanButton->Click += gcnew System::EventHandler(this, &ChartForm::cleanButton_Click);
			// 
			// pieButton
			// 
			this->pieButton->Location = System::Drawing::Point(48, 272);
			this->pieButton->Name = L"pieButton";
			this->pieButton->Size = System::Drawing::Size(75, 23);
			this->pieButton->TabIndex = 12;
			this->pieButton->Text = L"扇形图";
			this->pieButton->UseVisualStyleBackColor = true;
			this->pieButton->Click += gcnew System::EventHandler(this, &ChartForm::pieButton_Click);
			// 
			// polylineButton
			// 
			this->polylineButton->Location = System::Drawing::Point(48, 187);
			this->polylineButton->Name = L"polylineButton";
			this->polylineButton->Size = System::Drawing::Size(75, 23);
			this->polylineButton->TabIndex = 11;
			this->polylineButton->Text = L"折线图";
			this->polylineButton->UseVisualStyleBackColor = true;
			this->polylineButton->Click += gcnew System::EventHandler(this, &ChartForm::polylineButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"楷体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(24, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 19);
			this->label1->TabIndex = 10;
			this->label1->Text = L"学生信息统计";
			// 
			// histogramButton
			// 
			this->histogramButton->Location = System::Drawing::Point(48, 96);
			this->histogramButton->Name = L"histogramButton";
			this->histogramButton->Size = System::Drawing::Size(75, 23);
			this->histogramButton->TabIndex = 9;
			this->histogramButton->Text = L"直方图";
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
			this->Text = L"统计信息";
			this->Load += gcnew System::EventHandler(this, &ChartForm::ChartForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//窗体初始化
	private: System::Void ChartForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->indexCombox->Visible = false;
		this->indexLabel->Visible = false;
	}

			 /*
			 画XY轴：默认起点刻度从0开始；参数意义：x轴刻度点数，每格值多少， Y轴刻度点数，每格值多少
			 */
	private: Graphics ^ drawXYByPara(int xPointsNum, int valueOfOneXGrid, int yPointsNum, int valueOfOneYGrid) {
		Pen ^ XYPen = gcnew Pen(Color::Red, 2.0f);
		XYPen->LineJoin = Drawing2D::LineJoin::Miter;
		//pen->EndCap = LineCap::ArrowAnchor; //此句话用户画坐标轴的箭头，但是由于效果不好，我们手动添加；
		Graphics ^mg = this->panel1->CreateGraphics();
		Drawing::Font ^font = gcnew Drawing::Font("宋体", 8);
		SolidBrush ^fontBrush = gcnew SolidBrush(Color::Red);

		//xy坐标
		mg->DrawLine(XYPen, 50, 310, 50, 10);
		mg->DrawLine(XYPen, 450, 310, 50, 310);
		//xy轴端点箭头
		mg->DrawLine(XYPen, 50, 10, 45, 15);
		mg->DrawLine(XYPen, 50, 10, 55, 15);
		mg->DrawLine(XYPen, 450, 310, 445, 305);
		mg->DrawLine(XYPen, 450, 310, 445, 315);

		//根据参数的xy轴点数，计算每个刻度长度
		int yLen = 280 / yPointsNum;  //y轴长300，顶端留20像素值，因此刻画刻度的长度剩余280
		int xLen = 380 / xPointsNum;  //X轴长400， 给顶端都留20像素，剩余380；
		int currentX = 0, currentY = 0;

		//刻画Y轴上刻度点
		for (int i = 1; i <= yPointsNum; i++) {
			currentY += yLen;
			String ^s1 = "" + i * valueOfOneYGrid;
			mg->DrawLine(XYPen, 48, 310 - currentY, 52, 310 - currentY);
			mg->DrawString(s1, font, fontBrush, 25, 310 - currentY);
		}
		mg->DrawString(yLabel, font, fontBrush, 5, 10);

		//刻画X轴上刻度点
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
			 画直方图， 参数：源数据，数组长度，X轴刻度间隔值,以及Y轴刻度点个数；
			 */
	private:void drawHistogram(int data[], int dataLen, int valueOfOneXGrid, int valueOfOneYGrid) {
		int maxOfData = getMax(data, dataLen); //获取最大的值，然后得到Y轴每一刻度间隔多少；
		if (maxOfData == 0) {
			MessageBox::Show("暂无统计数据");
			return;
		}
		maxOfData = maxOfData % 10 == 0 ? maxOfData : ((maxOfData / 10) + 1) * 10;
		int yPointsNum = maxOfData / valueOfOneYGrid;

		Pen ^rectPen = gcnew Pen(Color::Black, 1.5f);
		SolidBrush ^rectBrush = gcnew SolidBrush(Color::LightBlue);

		Graphics ^mg = drawXYByPara(dataLen, valueOfOneXGrid, yPointsNum, valueOfOneYGrid); //画xy轴  //根据参数的xy轴点数，计算每个刻度长度
		int yLen = 280 / yPointsNum;  //y轴长300，顶端留20像素值，因此刻画刻度的长度剩余280
		int xLen = 380 / dataLen;  //X轴长400， 给顶端都留20像素，剩余380；
		int currentX = 50, currentY = 0; //X轴前段预留

		for (int i = 0; i <dataLen; i++) {
			// VS中Y轴方向与数学中Y轴方向相反，因此需要用Y轴长度，减去当前柱长度，得到其Y坐标值；
			int height = (data[i] * yLen) / valueOfOneYGrid;
			int startY = 310 - height;

			//随机获取颜色；
			rectPen->Color = getRamColor(i);
			rectBrush->Color = getRamColor(i);
			mg->FillRectangle(rectBrush, currentX, startY, xLen, height); //填充颜色
			mg->DrawRectangle(rectPen, currentX, startY, xLen, height);   //描边；
			currentX += xLen;
		}

		//重新补描一下XY轴；
		drawXYByPara(dataLen, valueOfOneXGrid, yPointsNum, valueOfOneYGrid);
		Drawing::Font ^font = gcnew Drawing::Font("宋体", 12);
		SolidBrush ^fontBrush = gcnew SolidBrush(Color::Black);
		mg->DrawString(title, font, fontBrush, 180, 15);  //绘制图标标题
		delete rectPen;
		delete rectBrush;
		delete fontBrush;
	}

			/*
			画折线图， 参数：源数据，数组长度，X轴刻度间隔值,以及Y轴刻度点个数；
			折线图相当于很多段线段链接而成，因此绘制折线图需要一段一段来画；
			*/
	private:void drawPolyline(int data[], int dataLen, int valueOfOneXGrid, int valueOfOneYGrid) {
		int maxOfData = getMax(data, dataLen); //获取最大的值，然后得到Y轴每一刻度间隔多少；
		if (maxOfData == 0) {
			MessageBox::Show("暂无统计数据");
			return;
		}
		maxOfData = maxOfData % 10 == 0 ? maxOfData : ((maxOfData / 10) + 1) * 10;
		int numOfYPoint = maxOfData / valueOfOneYGrid;

		//根据参数的xy轴点数，计算每个刻度长度
		int yLen = 280 / numOfYPoint;  //y轴长300，顶端留20像素值，因此刻画刻度的长度剩余280
		int xLen = 380 / dataLen;  //X轴长400， 给顶端都留20像素，剩余380；
		int currentX = 50 + xLen*0.5, currentY = 0; //X轴前段预留

													//得到第一个点的坐标
		int height = (data[0] * yLen) / valueOfOneYGrid;
		int startY = 310 - height;

		Point current = Point(currentX, startY); //第一个点；
		Pen ^linePen = gcnew Pen(getRamColor(15), 3.0f);
		Graphics ^mg = drawXYByPara(dataLen, valueOfOneXGrid, numOfYPoint, valueOfOneYGrid); //绘制坐标轴
		for (int i = 1; i < dataLen; i++) {  //绘制其他点， 连点成线；
			currentX += xLen;
			height = (data[i] * yLen) / valueOfOneYGrid;
			startY = 310 - height;
			Point point = Point(currentX, startY);
			mg->DrawLine(linePen, current, point);
			current = point;
		}


		drawXYByPara(dataLen, valueOfOneXGrid, numOfYPoint, valueOfOneYGrid); //再次描绘一下XY轴；
		Drawing::Font ^font = gcnew Drawing::Font("宋体", 12);
		SolidBrush ^fontBrush = gcnew SolidBrush(Color::Black);
		mg->DrawString(title, font, fontBrush, 180, 15);  //绘制图标标题
		delete linePen;
		delete fontBrush;
	}

			/*
			绘制扇形图，需要传递三个参数：数据源，数据长度，每一个扇形所表示真实数据的区域，如成绩10-20分，用一个扇形表示
			*/
	private:void drawSector(int data[], int dataLen, int valueOfOneSector) {
		double *b = new double[dataLen];
		int sum = 0;
		for (int i = 0; i <dataLen; i++) {
			sum += data[i];
		}
		if (sum == 0) {
			MessageBox::Show("暂无统计数据");
			return;
		}
		for (int i = 0; i <dataLen; i++) {
			b[i] = data[i] * 330 * 1.0 / sum;
		}

		Graphics ^my = this->panel1->CreateGraphics();
		Pen ^piePen = gcnew Pen(Color::Brown, 2.0f);
		SolidBrush ^pieBrush = gcnew SolidBrush(Color::Brown);
		Drawing::Font ^strFont = gcnew Drawing::Font("隶书", 12);
		SolidBrush ^strBrush = gcnew SolidBrush(Color::Red);
		double current = 0;
		String ^subLabel = "比例";

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
		my->DrawString(title, strFont, strBrush, 100, 25);  //绘制图标标题
		my->DrawString(xLabel, strFont, strBrush, 345, 25);
		my->DrawString(subLabel, strFont, strBrush, 395, 25);
		delete piePen;
		delete pieBrush;
		delete strBrush;
	}

			/*
			获取数组中最大值
			*/
	private:int getMax(int a[], int len) {
		int max = a[0];
		for (int i = 1; i<len; i++) {
			if (max<a[i])max = a[i];
		}
		return max;
	}

			/*
			随机获取颜色函数
			*/
	private:Color getRamColor(int i) {
		Random ^t = gcnew Random(i);
		int r = t->Next() % 26;
		return colorArray[r];
	}

			/*
			清空画板中所有内容
			*/
	private:void cleanAll() {
		Graphics ^my = this->panel1->CreateGraphics();
		Color color = BackColor; //获取背景颜色
		my->Clear(color);  //清空；
	}

			/*
			通过专业id，获取某专业所有学生已修学分分布情况数据
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
		this->valueOfXGrid = 10;  //设置X轴中每一个刻度真实所表示的值，查询学分，设为10分每一间隔；
		this->valueOfYGrid = 5;  //纵坐标则5人每一个间隔；
		dataArray = new int[this->dataArrayLen];
		for (int i = 0; i < this->dataArrayLen; i++) {
			this->dataArray[i] = numOfArray[i];
		}
	}
			/*
			通过课程ID ，获取选修该课程所有学生成绩分布数据
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
		this->valueOfXGrid = 10;  //设置X轴中每一个刻度真实所表示的值，此处查询成绩，设为10分每一间隔；
		this->valueOfYGrid = 5;  //纵坐标则5人每一个间隔；
		dataArray = new int[this->dataArrayLen];

		int a[] = { 1,3,8,10,15,20,30,25,10,5 };
		for (int i = 0; i < this->dataArrayLen; i++) {
			cout << numOfArray[i] << " ";
			this->dataArray[i] = numOfArray[i] + a[i];
		}
	}

			 /*
			 通过学生ID 获取学生所有成绩数据，进行绘图；
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
		this->valueOfXGrid = 10;  //设置X轴中每一个刻度真实所表示的值，此处查询成绩，设为10分每一间隔；
		this->valueOfYGrid = 1;  //纵坐标则5人每一个间隔；
		dataArray = new int[this->dataArrayLen];

		//int a[] = { 0,0,0,0,0,1,2,20,15,6 };
		for (int i = 0; i < this->dataArrayLen; i++) {
			this->dataArray[i] = numOfArray[i];// +a[i];
		}
	}

			/*
			根据用户的身份，设置可查询项，置于下拉选框
			*/
	private:void setDataType(int type) {
		int t = type;
		switch (t) {
		case (int)UserTypeCode::USER_ACADEMICSTAFF: { //教务员
			if (dataTypeCombox->Items->Count>0)dataTypeCombox->Items->Clear();
			dataTypeCombox->Items->Add(gcnew String("查询各专业学生学分修读情况"));
			dataTypeCombox->Items->Add(gcnew String("查询各课程成绩"));
			dataTypeCombox->Items->Add(gcnew String("查询各学生课程成绩统计"));
			break;
		}
		case (int)UserTypeCode::USER_TEACHER: {   //教师
			if (dataTypeCombox->Items->Count>0)dataTypeCombox->Items->Clear();
			dataTypeCombox->Items->Add(gcnew String("查询各课程成绩"));
			break;
		}
		default: { //由于系统管理员无法访问该界面，因此余下用户都可以认为是学生
			if (dataTypeCombox->Items->Count>0)dataTypeCombox->Items->Clear();
			dataTypeCombox->Items->Add(gcnew String("查询课程成绩统计"));
			dataTypeCombox->Visible = false;
			indexCombox->Visible = false;
			indexLabel->Visible = false;
			label2->Visible = false;

			string stuid = this->loginUser->getId();
			String ^myID = gcnew String(stuid.c_str());
			getStuGradeInfo(myID);
			xLabel = "成绩";
			yLabel = "科目数";
			title = "学生个人成绩分布情况";
			break;
		}
		}
	}

			//选择某一大类进行查询；
	private: System::Void dataTypeCombox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int userType = this->loginUser->getType(); //获取当前登录用户类型

		if (userType == (int)UserTypeCode::USER_ACADEMICSTAFF) { //教务员登录
			int selectedIndex = dataTypeCombox->SelectedIndex; //获得所查询的数据类型
			this->indexLabel->Visible = true;
			this->indexCombox->Visible = true;
			switch (selectedIndex) {
			case 0: {  //选中dataTypeCombox中第一项：查询某一专业学生学分修读情况
				indexLabel->Text = "请选择专业：";
				xLabel = "学分段";
				yLabel = "人数";
				title = "学生已获学分分布情况";
				indexCombox->Items->Clear();
				//从文件中，获取所有专业，置于下拉选框中；
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
					strTemp += p->getType() == ((int)UserTypeCode::USER_GRADUATE) ? "-硕士" : "-本科";
					indexCombox->Items->Add(gcnew String(strTemp.c_str()));
				}
				break;
			}
			case 1: {  //选中dataTypeCombox第二项： 查询各课程学生成绩
				indexLabel->Text = "请选择课程：";
				xLabel = "成绩";
				yLabel = "人数";
				title = "该科学生成绩分布情况";
				indexCombox->Items->Clear();
				//从文件中，获取所有课程，置于下拉选框中；
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
					item += c->getType() == ((int)UserTypeCode::USER_GRADUATE) ? "-硕士" : "-本科";
					indexCombox->Items->Add(item);
				}
				break;
			}
			default: {
				indexLabel->Text = "请选择学生：";
				xLabel = "成绩";
				yLabel = "课程数";
				title = "学生已修课程成绩情况";
				indexCombox->Items->Clear();
				//从文件中，获取所有学生，置于下拉选框中；
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
		else {   //系统管理员无法访问该界面， 学生用户无需该控件做进一步索引，因此余下的则为教师登录
			indexLabel->Text = "请选择课程：";
			xLabel = "成绩";
			yLabel = "人数";
			title = "课程学生成绩分布情况";
			//此处读取所有任课课程， 并置于下拉选框
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
				item += c->getType() == ((int)UserTypeCode::USER_GRADUATE) ? "-硕士" : "-本科";
				indexCombox->Items->Add(item);
			}

			this->indexLabel->Visible = true;
			this->indexCombox->Visible = true;
		}
	}

			 //具体查询某一类数据
	private: System::Void indexCombox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		int searchType = dataTypeCombox->SelectedIndex;
		int searchIndex = indexCombox->SelectedIndex;
		String ^name = indexCombox->SelectedItem->ToString();
		String ^ id = (name->Split('-'))[0];

		if (loginUser->getType() == (int)UserTypeCode::USER_ACADEMICSTAFF) {  // 教务员登录
			switch (searchType) {
			case 0: {
				getMajorCreditInfo(id);   //查询各专业学生学分修读情况
				break;
			}
			case 1: {
				id = (id->Split(' '))[0];
				getCourseGradeInfo(id);  //查询各课程学生成绩分布情况
				break;
			}
			default: {
				getStuGradeInfo(id);    //查询学生各科成绩分布情况
				break;
			}
			}
		}

		if (loginUser->getType() == (int)UserTypeCode::USER_TEACHER) {
			id = (id->Split(' '))[0];
			getCourseGradeInfo(id); //查询各课程学生成绩分布情况
		}

	}

			 //直方图按钮事件响应
	private: System::Void histogramButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataArray == nullptr || this->valueOfXGrid == 0 || this->valueOfYGrid == 0 || getMax(this->dataArray, this->dataArrayLen) <= 0) {
			MessageBox::Show("未获取查询数据");
		}
		else {
			cleanAll();
			drawHistogram(this->dataArray, this->dataArrayLen, this->valueOfXGrid, this->valueOfYGrid);
		}
	}

			 //折线图按钮事件响应
	private: System::Void polylineButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataArray == nullptr || this->valueOfXGrid == 0 || this->valueOfYGrid == 0 || getMax(this->dataArray, this->dataArrayLen) <= 0) {
			MessageBox::Show("未获取查询数据");
		}
		else {
			cleanAll();
			drawPolyline(this->dataArray, this->dataArrayLen, this->valueOfXGrid, this->valueOfYGrid);
		}
	}

			 //扇形图按钮事件响应
	private: System::Void pieButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->dataArray == nullptr || this->valueOfXGrid == 0 || getMax(this->dataArray, this->dataArrayLen) <= 0) {
			MessageBox::Show("未获取查询数据");
		}
		else {
			cleanAll();
			drawSector(this->dataArray, this->dataArrayLen, this->valueOfXGrid);
		}
	}

			 //清楚按钮事件响应
	private: System::Void cleanButton_Click(System::Object^  sender, System::EventArgs^  e) {
		cleanAll();
	}
	};
}
