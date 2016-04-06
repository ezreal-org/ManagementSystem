#pragma once
#include "memberInfo.h"
#include "TypeDefinition.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

namespace ManagementSystemV5 {
	using namespace System;
	using namespace System::IO;
	public ref class Storage{
	public:
		//登录
		UserTable* login(char* id, char* passwd, LoginUserType type) //不同type对应不同类型用户登录文件
		{
			//约定type=0为系统管理员,1为教务员,2为教师,3为硕士生,4为本科生
			char buffer[100];
			char loginInfo[100];
			ifstream input;
			char *path = "C:\\managementSystem\\login\\admin.txt";
			if (type == LoginUserType::LOGIN_ADMIN) {   //管理员
				input.open(path, ios::in);  //文本文件读取
				if (!input) { MessageBox::Show("文件读写异常！"); return nullptr; }
				sprintf(loginInfo, "%s|%s|%d", id, passwd, type);
				while (!input.eof()) {
					input.getline(buffer, 100);
					if (!strcmp(loginInfo, buffer)) {
						input.close();
						UserTable *p = new UserTable();
						p->setId(id);
						p->setPasswd(passwd);
						p->setType((int)type);
						return p;
					}
				}
			}
			else {
				UserTable *p = new UserTable();
				p = readLoginInfo(id);
				if (!p) return nullptr; //用户名不存在
				//登录界面没有区分硕士生/本科生type未知(-1)，校验用户名密码是否一致，教务员/教师校验类型
				if (strcmp(p->getPasswd(), passwd) == 0 && (p->getType() == (int)type || type == LoginUserType::LOGIN_STUDENT)) {
					return p;
				}
				return nullptr; //用户名密码不匹配
			}
		}
		//修改密码
		bool updateInfo(int type, char* id, char* oldpw, char *passwd)
		{
			UserTable *p = new UserTable();
			p = readLoginInfo(id);
			if (strcmp(oldpw, p->getPasswd()) == 0 && p->getType() == type) { //校验成功
				p->setPasswd(passwd);
				writeLoginInfo(p); //修改密码，写入文件
				return true;
			}
			delete p;
			return false;
		}
		//写登录账户
		bool writeLoginInfo(UserTable *p)
		{
			ofstream output;
			char path[100];
			sprintf(path, "C:\\managementSystem\\login\\%s.dat", p->getId());
			output.open(path, ios::out | ios::binary);
			if (!output) { MessageBox::Show("文件读写异常!"); return false; }
			output.write((char*)p, sizeof(UserTable));
			output.close();
			delete p;
			return true;
		}
		//读登录账户
		UserTable* readLoginInfo(char *id)
		{
			UserTable *p = new UserTable();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\login\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { return nullptr; }
			f.read((char*)p, sizeof(UserTable));
			return p;
		}
		//删除登录账户
		bool deleteLoginInfo(char *id){
			char path[100];
			sprintf(path, "C:\\managementSystem\\login\\%s.dat", id);
			if (!remove(path)) { //删除成功remove返回0
				return true;
			}
			return false;
		}
		//删除教务员/教师信息
		bool deleteStaffInfo(char *id, int type)
		{
			char path[100];
			if(type== (int)UserTypeCode::USER_ACADEMICSTAFF) //教务员
				sprintf(path, "C:\\managementSystem\\staff\\academicStaff\\%s.dat", id);
			else if(type == (int)UserTypeCode::USER_TEACHER)
				sprintf(path, "C:\\managementSystem\\staff\\teacher\\%s.dat", id);
			if (!remove(path)) { //删除成功
				return true;
			}
			return false;
		}
		//删除学生信息
		bool deleteStuInfo(char *id, int type)
		{
			char path[100];
			if (type == (int)UserTypeCode::USER_GRADUATE) //研究生
				sprintf(path, "C:\\managementSystem\\stu\\graduate\\%s.dat", id);
			else if (type == (int)UserTypeCode::USER_UNDERGRADUATE)
				sprintf(path, "C:\\managementSystem\\stu\\undergraduate\\%s.dat", id);
			if (!remove(path)) { //删除成功
				return true;
			}
			return false;
		}
		bool writeCourse(Course *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\course\\%s.dat", p->getCourseCode());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(Course));
			f.close();
			return true;
		}
		Course* readCourse(char *id)
		{
			Course *p = new Course();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\course\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p, sizeof(Course));
			f.close();
			return p;
		}
		bool writeMajor(Major *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\major\\%s.dat", p->getMajorCode());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(Major));
			f.close();
			return true;
		}
		Major* readMajor(char *id)
		{
			Major *p = new Major();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\major\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p, sizeof(Major));
			f.close();
			return p;
		}
		//写排课表
		bool writeCourseArrangement(courseArrangement *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\courseArrangement\\%s.dat", p->getCourseId());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(courseArrangement));
			f.close();
			return true;
		}
		courseArrangement* readCourseArrangement(char *id)
		{
			courseArrangement *p = new courseArrangement();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\courseArrangement\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) {  return nullptr; }
			f.read((char*)p, sizeof(courseArrangement));
			f.close();
			return p;
		}
		bool writeSelectedCourse(selectedCourse *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\selectedCourses\\%s %s.dat", p->getCourseId(), p->getStuId());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(selectedCourse));
			f.close();
			return true;
		}
		selectedCourse* readSelectedCourse(char *id)
		{
			selectedCourse *p = new selectedCourse();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\selectedCourses\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p, sizeof(selectedCourse));
			f.close();
			return p;
		}
		AcademicStaffTable* readAcademicStaffInfo(char *id)
		{
			AcademicStaffTable*  p1 = new AcademicStaffTable();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\staff\\academicStaff\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p1, sizeof(AcademicStaffTable));
			f.close();
			return p1;
		}
		bool writeAcademicStaff(AcademicStaffTable *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\staff\\academicStaff\\%s.dat", p->getId());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(AcademicStaffTable));
			f.close();
			return true;
		}
		TeacherTable* readTeacherInfo(char *id)
		{
			TeacherTable*  p1 = new TeacherTable();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\staff\\teacher\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p1, sizeof(TeacherTable));
			f.close();
			return p1;
		}
		bool writeTeacher(TeacherTable* p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\staff\\teacher\\%s.dat", p->getId());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(TeacherTable));
			f.close();
			return true;
		}
		GraduateTable* readGraduateInfo(char *id)
		{
			GraduateTable*  p1 = new GraduateTable();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\stu\\graduate\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p1, sizeof(GraduateTable));
			f.close();
			return p1;
		}
		bool writeGraduate(GraduateTable *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\stu\\graduate\\%s.dat", p->getId());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(GraduateTable));
			f.close();
			return true;
		}
		UndergraduateTable* readUndergradateInfo(char *id)
		{
			UndergraduateTable*  p1 = new UndergraduateTable();
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\stu\\undergraduate\\%s.dat", id);
			f.open(path, ios::in | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return nullptr; }
			f.read((char*)p1, sizeof(UndergraduateTable));
			f.close();
			return p1;
		}
		bool writeUndergraduate(UndergraduateTable *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\stu\\undergraduate\\%s.dat", p->getId(), p->getName());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("文件读写异常!"); return false; }
			f.write((char*)p, sizeof(UndergraduateTable));
			f.close();
			return true;
		}
		cli::array<String^>^ readAllStuId(int type) //学生类型
		{
			String ^dir;
			if (type == (int)UserTypeCode::USER_GRADUATE)			//硕士生
				dir = "C:\\managementSystem\\stu\\graduate\\";
			else if(type == (int)UserTypeCode::USER_UNDERGRADUATE)
				dir = "C:\\managementSystem\\stu\\undergraduate\\";
			String^ pattern = "*.dat";
			try {
				IO::DirectoryInfo ^directoryInfo = gcnew DirectoryInfo(dir);
				cli::array<FileInfo^>^fileCollection = directoryInfo->GetFiles(pattern);
				cli::array<String^>^ retString = gcnew cli::array<String^>(fileCollection->Length);
				for (int i = 0; i < fileCollection->Length; i++){
					retString[i] = fileCollection[i]->Name->Substring(0, fileCollection[i]->Name->IndexOf("."));
				}
				return retString;
			}
			catch (System::ArgumentException ^) {
				MessageBox::Show("文件读写异常!"); return nullptr;
			}
		}
		cli::array<String^>^ readAllLoginAcountId() {
			String ^dir;
			dir = "C:\\managementSystem\\login\\";
			String^ pattern = "*.dat";
			try {
				IO::DirectoryInfo ^directoryInfo = gcnew DirectoryInfo(dir);
				cli::array<FileInfo^>^fileCollection = directoryInfo->GetFiles(pattern);
				cli::array<String^>^ retString = gcnew cli::array<String^>(fileCollection->Length);
				for (int i = 0; i < fileCollection->Length; i++) {
					retString[i] = fileCollection[i]->Name->Substring(0, fileCollection[i]->Name->IndexOf("."));
				}
				return retString;
			}
			catch (System::ArgumentException^) {
				MessageBox::Show("文件读写异常!"); return nullptr;
			}
			
		}
		cli::array<String^>^ readAllMajorId()
		{
			String ^dir;
			dir = "C:\\managementSystem\\major\\";
			String^ pattern = "*.dat";
			try {
				IO::DirectoryInfo ^directoryInfo = gcnew DirectoryInfo(dir);
				cli::array<FileInfo^>^fileCollection = directoryInfo->GetFiles(pattern);
				cli::array<String^>^ retString = gcnew cli::array<String^>(fileCollection->Length);
				for (int i = 0; i < fileCollection->Length; i++) {
					retString[i] = fileCollection[i]->Name->Substring(0, fileCollection[i]->Name->IndexOf("."));
				}
				return retString;
			}
			catch (System::ArgumentException^) {
				MessageBox::Show("文件读写异常！");
				return nullptr;
			}
			
		}
		//读所有排课表id
		cli::array<String^>^ readAllCourseArrangementId()
		{
			String ^dir;
			dir = "C:\\managementSystem\\courseArrangement\\";
			String^ pattern = "*.dat";
			try {
				IO::DirectoryInfo ^directoryInfo = gcnew DirectoryInfo(dir);
				cli::array<FileInfo^>^fileCollection = directoryInfo->GetFiles(pattern);
				cli::array<String^>^ retString = gcnew cli::array<String^>(fileCollection->Length);
				for (int i = 0; i < fileCollection->Length; i++) {
					retString[i] = fileCollection[i]->Name->Substring(0, fileCollection[i]->Name->IndexOf("."));
				}
				return retString;
			}
			catch (System::ArgumentException^) {
				MessageBox::Show("文件读写异常！");
				return nullptr;
			}
		}
		cli::array<String^>^ readAllSelectedCourseId()
		{
			String ^dir;
			dir = "C:\\managementSystem\\selectedCourses\\";
			String^ pattern = "*.dat";
			try {
				IO::DirectoryInfo ^directoryInfo = gcnew DirectoryInfo(dir);
				cli::array<FileInfo^>^fileCollection = directoryInfo->GetFiles(pattern);
				cli::array<String^>^ retString = gcnew cli::array<String^>(fileCollection->Length);
				for (int i = 0; i < fileCollection->Length; i++){
					retString[i] = fileCollection[i]->Name->Substring(0, fileCollection[i]->Name->IndexOf("."));
				}
				return retString;
			}
			catch (System::ArgumentException^) {
				MessageBox::Show("文件读写异常！");
				return nullptr;
			}
		}
		cli::array<String^>^ readAllCourseId()
		{
			String ^dir;
			dir = "C:\\managementSystem\\course\\";
			String^ pattern = "*.dat";
			try {
				IO::DirectoryInfo ^directoryInfo = gcnew DirectoryInfo(dir);
				cli::array<FileInfo^>^fileCollection = directoryInfo->GetFiles(pattern);
				cli::array<String^>^ retString = gcnew cli::array<String^>(fileCollection->Length);
				for (int i = 0; i < fileCollection->Length; i++) {
					retString[i] = fileCollection[i]->Name->Substring(0, fileCollection[i]->Name->IndexOf("."));
				}
				return retString;
			}
			catch (System::ArgumentException^) {
				MessageBox::Show("文件读写异常！");
				return nullptr;
			}
		}
	};
	
}