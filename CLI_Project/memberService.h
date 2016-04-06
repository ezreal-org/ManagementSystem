#pragma once
#include "memberInfo.h"
#include "TypeDefinition.h"
#include "storage.h"
#include <vector>

namespace ManagementSystemV5 {
	using namespace Runtime::InteropServices;

	public class User
	{
	public:
		//��½
		UserTable* login(char* id, char* passwd, LoginUserType type)
		{
			Storage storage;
			return storage.login(id, passwd, type);
		}
		//�޸�����
		bool updatePasswd(int flag, char* idName, char* oldpw, char *passwd)
		{
			Storage storage;
			return storage.updateInfo(flag, idName, oldpw, passwd);
		}
	};

	public  class Admin :public User //ϵͳ����Ա
	{
	public:
		bool addAcademicStaff(AcademicStaffTable *p) //��ӽ���Ա
		{
			Storage storage;
			UserTable *pu = new UserTable();
			pu->setId(p->getId());
			pu->setPasswd(p->getPasswd());
			pu->setType(p->getType());
			if (!storage.writeLoginInfo(pu)) return false;
			if (!storage.writeAcademicStaff(p)) return false;
			return true;
		}
		bool addTeacher(TeacherTable *p) //��ӽ�ʦ
		{
			Storage storage;
			UserTable *pu = new UserTable();
			pu->setId(p->getId());
			pu->setPasswd(p->getPasswd());
			pu->setType(p->getType());
			if (!storage.writeLoginInfo(pu)) return false;
			if (!storage.writeTeacher(p)) return false;
			return true;
		}
		cli::array<String ^>^ getAllStaffId() { //��ȡ����ְ��id
			Storage storage;
			vector<string> vstaffId;
			ifstream input;
			UserTable *p = new UserTable();
			cli::array<String^>^list = storage.readAllLoginAcountId(); //��ȡ���е�¼�˻�
			for each(String^ id in list) {
				p = storage.readLoginInfo((char*)Marshal::StringToHGlobalAnsi(id).ToPointer());
				if (p->getType() == (int)UserTypeCode::USER_ACADEMICSTAFF || p->getType() == (int)UserTypeCode::USER_TEACHER) //����Ա�򼰽�ʦ
					vstaffId.push_back(p->getId());
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstaffId.size());
			for (int i = 0; i < vstaffId.size(); i++) { //string[] -> String[]
				retList[i] = gcnew String(vstaffId[i].c_str());
			}
			return retList;
		}
		bool deleteAccount(char *id) //ͨ��idɾ����ʦ�����Ա��½�˻�
		{
			Storage storage;
			UserTable *user = storage.readLoginInfo(id);
			if (!storage.deleteLoginInfo(id)) return false;
			if (!storage.deleteStaffInfo(id, user->getType())) return false;
			return true;
		}
		UserTable *readStaffBasicInfo(char *id) //��ְ��������Ϣ
		{
			Storage storage;
			return storage.readLoginInfo(id);
		}
	};
	public  class AcademicStaff :public User
	{
	public:
		//ͨ��id��ѯѧ��
		GraduateTable* readGraduateInfo(char *id)
		{
			Storage storage;
			return storage.readGraduateInfo(id);
		}
		UndergraduateTable* readUndergraduateInfo(char *id)
		{
			Storage storage;
			return storage.readUndergradateInfo(id);
		}
		//���רҵ
		bool writeMajor(Major *p)
		{
			Storage storage;
			return storage.writeMajor(p);
		}
		//��רҵ��Ϣ
		Major* readMajorInfo(char *id)
		{
			Storage storage;
			return storage.readMajor(id);
		}
		//Ϊѧ������Ĭ�ϵ�¼��
		bool writeInitLoginInfo(char *id, char *passwd, int type)
		{
			Storage storage;
			UserTable *p = new UserTable();
			p->setId(id);
			p->setPasswd(passwd);
			p->setType(type);
			return storage.writeLoginInfo(p);
		}
		//дѧ����Ϣ��
		bool writeGraduate(GraduateTable *p)
		{
			Storage storage;
			return storage.writeGraduate(p);
		}
		bool writeUndergraduate(UndergraduateTable *p)
		{
			Storage storage;
			return storage.writeUndergraduate(p);
		}
		bool deleteStuAccount(char *id) //ͨ��idɾ��ѧ���˻�
		{
			Storage storage;
			UserTable *user = storage.readLoginInfo(id);
			if (!storage.deleteLoginInfo(id)) return false;
			if (!storage.deleteStuInfo(id, user->getType())) return false;
			return true;
		}
		//��ȡĳ������ѧ��ժҪ��Ϣ
		cli::array<String^>^ getAllStuSummaryInfo(int type) //ѧ������
		{
			Storage storage;
			return storage.readAllStuId(type);
		}
		//��ȡ����רҵժҪ��Ϣ
		cli::array<String^>^ getAllMajorSummarayInfo()
		{
			Storage storage;
			return storage.readAllMajorId();
		}
		//��ȡ���пγ�id
		cli::array<String^>^ getAllCourseId()
		{
			Storage storage;
			return storage.readAllCourseId();
		}
		//��ȡ���н�ʦid
		cli::array<String ^>^ getAllTeacherId() { 
			Storage storage;
			vector<string> vstaffId;
			ifstream input;
			UserTable *p = new UserTable();
			cli::array<String^>^list = storage.readAllLoginAcountId(); //��ȡ���е�¼�˻�
			for each(String^ id in list) {
				p = storage.readLoginInfo((char*)Marshal::StringToHGlobalAnsi(id).ToPointer());
				if (p->getType() == (int)UserTypeCode::USER_TEACHER) //��ʦ
					vstaffId.push_back(p->getId());
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstaffId.size());
			for (int i = 0; i < vstaffId.size(); i++) { //string[] -> String[]
				retList[i] = gcnew String(vstaffId[i].c_str());
			}
			return retList;
		}
		//��ȡĳ��ѧ����ѡ�����пγ�id
		cli::array<String^>^ getOneStuAllSelectedCoursesId(char *id)
		{
			vector<string> vstr; //�洢��ѧ��ѡ�κ� ��cId + sId��
			String ^stuId;
			string temp = id;
			stuId = gcnew String(temp.c_str());
			Storage storage;
			cli::array<String^>^ list = storage.readAllSelectedCourseId();
			for each(String^ cIdstuId in list) {  //��ѡ�α���ɸѡ��ĳ��ѧ��������ѡ�ε� �γ�id
				String ^ sid = (cIdstuId->Split(' '))[1];
				if (sid == stuId) {
					vstr.push_back((char*)(Marshal::StringToHGlobalAnsi(cIdstuId->Substring(0, cIdstuId->IndexOf(" ")))).ToPointer());
				}
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstr.size());
			for (int i = 0; i < vstr.size(); i++) {  // string[] -> String[]
				retList[i] = gcnew String(vstr[i].c_str());
			}
			return retList;
		}
		//��ӿγ�
		bool writeCourse(Course *p)
		{
			Storage storage;
			return storage.writeCourse(p);
		}
		//���γ���Ϣ
		Course* readCourseInfo(char *idName)
		{
			Storage storage;
			return storage.readCourse(idName);
		}
		//����ʦ������Ϣ
		TeacherTable* readTeacherInfo(char *tid)
		{
			Storage storage;
			return storage.readTeacherInfo(tid);
		}
		//���ſα���Ϣ
		courseArrangement* readCourseArrangement(char *id)
		{
			Storage storage;
			return storage.readCourseArrangement(id);
		}
		//�����ſα�
		bool writeCourseArrangement(courseArrangement *p)
		{
			Storage storage;
			return storage.writeCourseArrangement(p);
		}
		//��ȡĳ��ѧ��ĳ��ѡ�ε���Ϣ
		selectedCourse* getSelectedCourseInfo(char *cIdAndsId)
		{
			Storage storage;
			return storage.readSelectedCourse(cIdAndsId);
		}
		//��ȡĳ��רҵ������ѧ��id
		cli::array<String^>^ getOneMajorAllStuId(Major *p)
		{
			vector<string> vstr;
			char stuId[20];
			char majorName[20];
			Storage storage;
			cli::array<String^>^ allList = storage.readAllStuId(p->getType());
			for each(String ^id in allList) { //�ҳ�ĳרҵ��ѧ����������ȷ�������С
				sprintf(stuId, "%s", id);
				if (p->getType() == (int)UserTypeCode::USER_GRADUATE) {
					sprintf(majorName, "%s", storage.readGraduateInfo(stuId)->getMajor());
				}
				else if(p->getType() == (int)UserTypeCode::USER_UNDERGRADUATE){
					sprintf(majorName, "%s", storage.readUndergradateInfo(stuId)->getMajor());
				}
				else {
					return nullptr;
				}
				if (strcmp(p->getMajorName(), majorName) == 0) { //��רҵѧ��
					vstr.push_back((char*)Marshal::StringToHGlobalAnsi(id).ToPointer());
				}
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstr.size());
			for (int i = 0; i < vstr.size(); i++) {  // string[] -> String[]
				retList[i] = gcnew String(vstr[i].c_str());
			}
			return retList;
		}
		//ͳ�Ƹ�רҵѧ��ѧ��ȡ�����
		cli::array<int>^ getOneMajorStuCreditDistribution(Major *p)
		{
			Storage storage;
			char stuId[20];
			char scId[20];
			Course *cs;
			selectedCourse *sc;
			int countOfStu = 0;
			cli::array<String^>^ stuIdList = getOneMajorAllStuId(p); //���ĳרҵ����ѧ��ID
			cli::array<int>^ list = gcnew cli::array<int>(stuIdList->Length);
			for each(String ^id in stuIdList) { //�Ը�רҵ��ÿ��ѧ��
				list[countOfStu] = 0; //��ʼ��ѧ��ѧ��ͳ��
				sprintf(stuId, "%s", id);
				for each(String ^selectCourseId in getOneStuAllSelectedCoursesId(stuId)) { //ĳ ѧ��������ѡ��
					sprintf(scId, "%s %s", selectCourseId, stuId); //���ѡ�α�����
					sc = getSelectedCourseInfo(scId); //��ѡ�α�
					if (sc->getScore() > 59) {
						cs = readCourseInfo(sc->getCourseId());
						list[countOfStu] += cs->getCredit();
					}
				}
				countOfStu++;
			}
			return list;
		}

	};

	public  class Teacher :public User
	{
	public:
		//���γ���Ϣ
		Course* readCourseInfo(char *id)
		{
			Storage storage;
			return storage.readCourse(id);
		}
		//��������Լ����ڿγ̴���
		cli::array<String^>^ getSelfTeachCourseCode(char *teaId)
		{
			vector<string> vCourseId;
			Storage storage;
			char courseCode[20], teacherId[20];
			cli::array<String^>^ list = storage.readAllCourseArrangementId(); //���ſα�
			for each(String^ item in list) //�����пγ̱���ɸѡ���ον�ʦidΪteaId�Ŀγ�
			{
				sprintf(courseCode, "%s", item);
				strcpy(teacherId, storage.readCourseArrangement(courseCode)->getTeacherId());
				if (strcmp(teaId, teacherId) == 0)
					vCourseId.push_back(courseCode);
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vCourseId.size());
			for (int i = 0; i < vCourseId.size(); i++) // string[] -> String[]
			{
				retList[i] = gcnew String(vCourseId[i].c_str());
			}
			return retList;
		}
		//��ȡ�Լ����ڵ�ĳ�ſε�����ѧ��id
		cli::array<String^>^ getAllSelectedStuIdByCourseId(char *id)
		{
			vector<string> vStuId;
			Storage storage;
			String ^courseId;
			string temp = id;
			courseId = gcnew String(temp.c_str());
			cli::array<String^>^ list = storage.readAllSelectedCourseId();
			for each(String^ cIdstuId in list) {
				if (cIdstuId->Contains(courseId)) {
					cIdstuId = cIdstuId->Substring(cIdstuId->IndexOf(" ") + 1); //ȡѧ��
					vStuId.push_back((char*)Marshal::StringToHGlobalAnsi(cIdstuId).ToPointer());
				}
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vStuId.size());
			for (int i = 0; i < vStuId.size(); i++) {
				retList[i] = gcnew String(vStuId[i].c_str());
			}
			return retList;
		}
		//��ȡĳ��ѧ��������Ϣͨ��id + type
		StudentTable* getStuBasicInfo(int type, char *id)
		{
			Storage storage;
			StudentTable *p = nullptr; //ѧ������ָ��
			if (type == (int)UserTypeCode::USER_GRADUATE)
				p = storage.readGraduateInfo(id);
			else if(type == (int)UserTypeCode::USER_UNDERGRADUATE)
				p = storage.readUndergradateInfo(id);
			return p;
		}
		//����ѡ�α�д��ɼ�
		bool writeSelectedCourse(selectedCourse *p)
		{
			Storage storage;
			return storage.writeSelectedCourse(p);
		}
		//��ȡ�Լ����ڵ�һ�ſγ̵�һ��ѧ��ѡ����Ϣ
		selectedCourse* getSelectedCourseInfo(char *cIdstuId)
		{
			Storage storage;
			return storage.readSelectedCourse(cIdstuId);
		}
		//�����Լ����ڵ�һ�ſγ̵ĳɼ�����
		cli::array<int>^ getOneCourseScoreDistribution(char *cId)
		{
			Storage storage;
			char selectedCourseId[20]; //ѡ�α�id
			cli::array<String^>^ stuIdList = getAllSelectedStuIdByCourseId(cId);
			cli::array<int>^ list = gcnew cli::array<int>(stuIdList->Length);
			for (int i = 0; i < stuIdList->Length; i++)
			{
				sprintf(selectedCourseId, "%s %s", cId, stuIdList[i]);
				list[i] = getSelectedCourseInfo(selectedCourseId)->getScore();
			}
			return list;
		}
	};

	public class Student :public User
	{
	public:
		//��ȡ�����ſα�����(cid + tid),����ѡ��
		cli::array<String^>^ getAllCourseArrangementId()
		{
			Storage storage;
			return storage.readAllCourseArrangementId();
		}
		//���γ���Ϣ
		Course* readCourseInfo(char *idName)
		{
			Storage storage;
			return storage.readCourse(idName);
		}
		courseArrangement* readCourseArrangement(char *id)
		{
			Storage storage;
			return storage.readCourseArrangement(id);
		}
		//ѧ��ѡ��
		bool writeSelectedCourse(selectedCourse *p)
		{
			Storage storage;
			return storage.writeSelectedCourse(p);
		}
		//����Լ���ѡ�����пγ�id
		cli::array<String^>^ getAllSelfSelectedCourses(char *id)
		{
			vector<string> vstr; //�洢��ѧ��ѡ�κ� ��cId + sId��
			String ^stuId;
			string temp = id;
			stuId = gcnew String(temp.c_str());
			Storage storage;
			cli::array<String^>^ list = storage.readAllSelectedCourseId();
			for each(String^ item in list) {
				String ^ sid = (item->Split(' '))[1];
				if (sid == stuId) {
					vstr.push_back((char*)(Marshal::StringToHGlobalAnsi(item->Substring(0, item->IndexOf(" ")))).ToPointer());
				}
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstr.size());
			for (int i = 0; i < vstr.size(); i++) { // string[] -> String[]
				retList[i] = gcnew String(vstr[i].c_str());
			}
			return retList;
		}
		//��ȡĳһ����ѡ�γ���Ϣ
		selectedCourse* getSelectedCourseInfo(char *id)
		{
			Storage storage;
			return storage.readSelectedCourse(id);
		}
		//����ʦ������Ϣ
		TeacherTable* readTeacherInfo(char *tid)
		{
			Storage storage;
			return storage.readTeacherInfo(tid);
		}
	};
	public  class Graduate :public Student
	{
	public:
		GraduateTable *getSelfInfo(char *id)
		{
			Storage storage;
			return  storage.readGraduateInfo(id);
		}
	};
	public  class Undergraduate :public Student
	{
	public:
		UndergraduateTable *getSelfInfo(char *id)
		{
			Storage storage;
			return storage.readUndergradateInfo(id);
		}
	};

}