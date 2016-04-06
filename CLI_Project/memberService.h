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
		//登陆
		UserTable* login(char* id, char* passwd, LoginUserType type)
		{
			Storage storage;
			return storage.login(id, passwd, type);
		}
		//修改密码
		bool updatePasswd(int flag, char* idName, char* oldpw, char *passwd)
		{
			Storage storage;
			return storage.updateInfo(flag, idName, oldpw, passwd);
		}
	};

	public  class Admin :public User //系统管理员
	{
	public:
		bool addAcademicStaff(AcademicStaffTable *p) //添加教务员
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
		bool addTeacher(TeacherTable *p) //添加教师
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
		cli::array<String ^>^ getAllStaffId() { //获取所有职工id
			Storage storage;
			vector<string> vstaffId;
			ifstream input;
			UserTable *p = new UserTable();
			cli::array<String^>^list = storage.readAllLoginAcountId(); //获取所有登录账户
			for each(String^ id in list) {
				p = storage.readLoginInfo((char*)Marshal::StringToHGlobalAnsi(id).ToPointer());
				if (p->getType() == (int)UserTypeCode::USER_ACADEMICSTAFF || p->getType() == (int)UserTypeCode::USER_TEACHER) //教务员或及教师
					vstaffId.push_back(p->getId());
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstaffId.size());
			for (int i = 0; i < vstaffId.size(); i++) { //string[] -> String[]
				retList[i] = gcnew String(vstaffId[i].c_str());
			}
			return retList;
		}
		bool deleteAccount(char *id) //通过id删除教师或管理员登陆账户
		{
			Storage storage;
			UserTable *user = storage.readLoginInfo(id);
			if (!storage.deleteLoginInfo(id)) return false;
			if (!storage.deleteStaffInfo(id, user->getType())) return false;
			return true;
		}
		UserTable *readStaffBasicInfo(char *id) //读职工基本信息
		{
			Storage storage;
			return storage.readLoginInfo(id);
		}
	};
	public  class AcademicStaff :public User
	{
	public:
		//通过id查询学生
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
		//添加专业
		bool writeMajor(Major *p)
		{
			Storage storage;
			return storage.writeMajor(p);
		}
		//读专业信息
		Major* readMajorInfo(char *id)
		{
			Storage storage;
			return storage.readMajor(id);
		}
		//为学生创建默认登录表
		bool writeInitLoginInfo(char *id, char *passwd, int type)
		{
			Storage storage;
			UserTable *p = new UserTable();
			p->setId(id);
			p->setPasswd(passwd);
			p->setType(type);
			return storage.writeLoginInfo(p);
		}
		//写学生信息表
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
		bool deleteStuAccount(char *id) //通过id删除学生账户
		{
			Storage storage;
			UserTable *user = storage.readLoginInfo(id);
			if (!storage.deleteLoginInfo(id)) return false;
			if (!storage.deleteStuInfo(id, user->getType())) return false;
			return true;
		}
		//获取某类所有学生摘要信息
		cli::array<String^>^ getAllStuSummaryInfo(int type) //学生类型
		{
			Storage storage;
			return storage.readAllStuId(type);
		}
		//获取所有专业摘要信息
		cli::array<String^>^ getAllMajorSummarayInfo()
		{
			Storage storage;
			return storage.readAllMajorId();
		}
		//获取所有课程id
		cli::array<String^>^ getAllCourseId()
		{
			Storage storage;
			return storage.readAllCourseId();
		}
		//获取所有教师id
		cli::array<String ^>^ getAllTeacherId() { 
			Storage storage;
			vector<string> vstaffId;
			ifstream input;
			UserTable *p = new UserTable();
			cli::array<String^>^list = storage.readAllLoginAcountId(); //获取所有登录账户
			for each(String^ id in list) {
				p = storage.readLoginInfo((char*)Marshal::StringToHGlobalAnsi(id).ToPointer());
				if (p->getType() == (int)UserTypeCode::USER_TEACHER) //教师
					vstaffId.push_back(p->getId());
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstaffId.size());
			for (int i = 0; i < vstaffId.size(); i++) { //string[] -> String[]
				retList[i] = gcnew String(vstaffId[i].c_str());
			}
			return retList;
		}
		//获取某个学生所选的所有课程id
		cli::array<String^>^ getOneStuAllSelectedCoursesId(char *id)
		{
			vector<string> vstr; //存储该学生选课号 （cId + sId）
			String ^stuId;
			string temp = id;
			stuId = gcnew String(temp.c_str());
			Storage storage;
			cli::array<String^>^ list = storage.readAllSelectedCourseId();
			for each(String^ cIdstuId in list) {  //从选课表中筛选出某个学生的所有选课的 课程id
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
		//添加课程
		bool writeCourse(Course *p)
		{
			Storage storage;
			return storage.writeCourse(p);
		}
		//读课程信息
		Course* readCourseInfo(char *idName)
		{
			Storage storage;
			return storage.readCourse(idName);
		}
		//读教师个人信息
		TeacherTable* readTeacherInfo(char *tid)
		{
			Storage storage;
			return storage.readTeacherInfo(tid);
		}
		//读排课表信息
		courseArrangement* readCourseArrangement(char *id)
		{
			Storage storage;
			return storage.readCourseArrangement(id);
		}
		//更新排课表
		bool writeCourseArrangement(courseArrangement *p)
		{
			Storage storage;
			return storage.writeCourseArrangement(p);
		}
		//获取某个学生某门选课的信息
		selectedCourse* getSelectedCourseInfo(char *cIdAndsId)
		{
			Storage storage;
			return storage.readSelectedCourse(cIdAndsId);
		}
		//获取某个专业的所有学生id
		cli::array<String^>^ getOneMajorAllStuId(Major *p)
		{
			vector<string> vstr;
			char stuId[20];
			char majorName[20];
			Storage storage;
			cli::array<String^>^ allList = storage.readAllStuId(p->getType());
			for each(String ^id in allList) { //找出某专业的学生人数用于确定数组大小
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
				if (strcmp(p->getMajorName(), majorName) == 0) { //该专业学生
					vstr.push_back((char*)Marshal::StringToHGlobalAnsi(id).ToPointer());
				}
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vstr.size());
			for (int i = 0; i < vstr.size(); i++) {  // string[] -> String[]
				retList[i] = gcnew String(vstr[i].c_str());
			}
			return retList;
		}
		//统计各专业学生学分取得情况
		cli::array<int>^ getOneMajorStuCreditDistribution(Major *p)
		{
			Storage storage;
			char stuId[20];
			char scId[20];
			Course *cs;
			selectedCourse *sc;
			int countOfStu = 0;
			cli::array<String^>^ stuIdList = getOneMajorAllStuId(p); //获得某专业所有学生ID
			cli::array<int>^ list = gcnew cli::array<int>(stuIdList->Length);
			for each(String ^id in stuIdList) { //对该专业的每个学生
				list[countOfStu] = 0; //开始该学生学分统计
				sprintf(stuId, "%s", id);
				for each(String ^selectCourseId in getOneStuAllSelectedCoursesId(stuId)) { //某 学生的所有选课
					sprintf(scId, "%s %s", selectCourseId, stuId); //组成选课表主键
					sc = getSelectedCourseInfo(scId); //查选课表
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
		//读课程信息
		Course* readCourseInfo(char *id)
		{
			Storage storage;
			return storage.readCourse(id);
		}
		//获得所有自己教授课程代码
		cli::array<String^>^ getSelfTeachCourseCode(char *teaId)
		{
			vector<string> vCourseId;
			Storage storage;
			char courseCode[20], teacherId[20];
			cli::array<String^>^ list = storage.readAllCourseArrangementId(); //读排课表
			for each(String^ item in list) //从所有课程表中筛选出任课教师id为teaId的课程
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
		//获取自己教授的某门课的所有学生id
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
					cIdstuId = cIdstuId->Substring(cIdstuId->IndexOf(" ") + 1); //取学号
					vStuId.push_back((char*)Marshal::StringToHGlobalAnsi(cIdstuId).ToPointer());
				}
			}
			cli::array<String^>^ retList = gcnew cli::array<String^>(vStuId.size());
			for (int i = 0; i < vStuId.size(); i++) {
				retList[i] = gcnew String(vStuId[i].c_str());
			}
			return retList;
		}
		//获取某个学生基本信息通过id + type
		StudentTable* getStuBasicInfo(int type, char *id)
		{
			Storage storage;
			StudentTable *p = nullptr; //学生基类指针
			if (type == (int)UserTypeCode::USER_GRADUATE)
				p = storage.readGraduateInfo(id);
			else if(type == (int)UserTypeCode::USER_UNDERGRADUATE)
				p = storage.readUndergradateInfo(id);
			return p;
		}
		//更新选课表，写入成绩
		bool writeSelectedCourse(selectedCourse *p)
		{
			Storage storage;
			return storage.writeSelectedCourse(p);
		}
		//获取自己教授的一门课程的一个学生选课信息
		selectedCourse* getSelectedCourseInfo(char *cIdstuId)
		{
			Storage storage;
			return storage.readSelectedCourse(cIdstuId);
		}
		//生成自己教授的一门课程的成绩数组
		cli::array<int>^ getOneCourseScoreDistribution(char *cId)
		{
			Storage storage;
			char selectedCourseId[20]; //选课表id
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
		//获取所有排课表主键(cid + tid),用于选课
		cli::array<String^>^ getAllCourseArrangementId()
		{
			Storage storage;
			return storage.readAllCourseArrangementId();
		}
		//读课程信息
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
		//学生选课
		bool writeSelectedCourse(selectedCourse *p)
		{
			Storage storage;
			return storage.writeSelectedCourse(p);
		}
		//获得自己所选的所有课程id
		cli::array<String^>^ getAllSelfSelectedCourses(char *id)
		{
			vector<string> vstr; //存储该学生选课号 （cId + sId）
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
		//获取某一门已选课程信息
		selectedCourse* getSelectedCourseInfo(char *id)
		{
			Storage storage;
			return storage.readSelectedCourse(id);
		}
		//读教师基本信息
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