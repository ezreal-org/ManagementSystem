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
		//��¼
		UserTable* login(char* id, char* passwd, LoginUserType type) //��ͬtype��Ӧ��ͬ�����û���¼�ļ�
		{
			//Լ��type=0Ϊϵͳ����Ա,1Ϊ����Ա,2Ϊ��ʦ,3Ϊ˶ʿ��,4Ϊ������
			char buffer[100];
			char loginInfo[100];
			ifstream input;
			char *path = "C:\\managementSystem\\login\\admin.txt";
			if (type == LoginUserType::LOGIN_ADMIN) {   //����Ա
				input.open(path, ios::in);  //�ı��ļ���ȡ
				if (!input) { MessageBox::Show("�ļ���д�쳣��"); return nullptr; }
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
				if (!p) return nullptr; //�û���������
				//��¼����û������˶ʿ��/������typeδ֪(-1)��У���û��������Ƿ�һ�£�����Ա/��ʦУ������
				if (strcmp(p->getPasswd(), passwd) == 0 && (p->getType() == (int)type || type == LoginUserType::LOGIN_STUDENT)) {
					return p;
				}
				return nullptr; //�û������벻ƥ��
			}
		}
		//�޸�����
		bool updateInfo(int type, char* id, char* oldpw, char *passwd)
		{
			UserTable *p = new UserTable();
			p = readLoginInfo(id);
			if (strcmp(oldpw, p->getPasswd()) == 0 && p->getType() == type) { //У��ɹ�
				p->setPasswd(passwd);
				writeLoginInfo(p); //�޸����룬д���ļ�
				return true;
			}
			delete p;
			return false;
		}
		//д��¼�˻�
		bool writeLoginInfo(UserTable *p)
		{
			ofstream output;
			char path[100];
			sprintf(path, "C:\\managementSystem\\login\\%s.dat", p->getId());
			output.open(path, ios::out | ios::binary);
			if (!output) { MessageBox::Show("�ļ���д�쳣!"); return false; }
			output.write((char*)p, sizeof(UserTable));
			output.close();
			delete p;
			return true;
		}
		//����¼�˻�
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
		//ɾ����¼�˻�
		bool deleteLoginInfo(char *id){
			char path[100];
			sprintf(path, "C:\\managementSystem\\login\\%s.dat", id);
			if (!remove(path)) { //ɾ���ɹ�remove����0
				return true;
			}
			return false;
		}
		//ɾ������Ա/��ʦ��Ϣ
		bool deleteStaffInfo(char *id, int type)
		{
			char path[100];
			if(type== (int)UserTypeCode::USER_ACADEMICSTAFF) //����Ա
				sprintf(path, "C:\\managementSystem\\staff\\academicStaff\\%s.dat", id);
			else if(type == (int)UserTypeCode::USER_TEACHER)
				sprintf(path, "C:\\managementSystem\\staff\\teacher\\%s.dat", id);
			if (!remove(path)) { //ɾ���ɹ�
				return true;
			}
			return false;
		}
		//ɾ��ѧ����Ϣ
		bool deleteStuInfo(char *id, int type)
		{
			char path[100];
			if (type == (int)UserTypeCode::USER_GRADUATE) //�о���
				sprintf(path, "C:\\managementSystem\\stu\\graduate\\%s.dat", id);
			else if (type == (int)UserTypeCode::USER_UNDERGRADUATE)
				sprintf(path, "C:\\managementSystem\\stu\\undergraduate\\%s.dat", id);
			if (!remove(path)) { //ɾ���ɹ�
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
			f.read((char*)p, sizeof(Major));
			f.close();
			return p;
		}
		//д�ſα�
		bool writeCourseArrangement(courseArrangement *p)
		{
			fstream f;
			char path[100];
			sprintf(path, "C:\\managementSystem\\courseArrangement\\%s.dat", p->getCourseId());
			f.open(path, ios::out | ios::binary);
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return nullptr; }
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
			if (!f) { MessageBox::Show("�ļ���д�쳣!"); return false; }
			f.write((char*)p, sizeof(UndergraduateTable));
			f.close();
			return true;
		}
		cli::array<String^>^ readAllStuId(int type) //ѧ������
		{
			String ^dir;
			if (type == (int)UserTypeCode::USER_GRADUATE)			//˶ʿ��
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
				MessageBox::Show("�ļ���д�쳣!"); return nullptr;
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
				MessageBox::Show("�ļ���д�쳣!"); return nullptr;
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
				MessageBox::Show("�ļ���д�쳣��");
				return nullptr;
			}
			
		}
		//�������ſα�id
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
				MessageBox::Show("�ļ���д�쳣��");
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
				MessageBox::Show("�ļ���д�쳣��");
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
				MessageBox::Show("�ļ���д�쳣��");
				return nullptr;
			}
		}
	};
	
}