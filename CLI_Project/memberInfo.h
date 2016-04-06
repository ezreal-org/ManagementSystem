#pragma once
#include <cstring>
using namespace std;

namespace ManagementSystemV5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//�����ֶε������ԣ�����ʹ�ýṹ�������������һ����������������������ʹ���ࣻ
	class Birthday{  
	public:
		int year;
		int month;
		int day;
	};
	public class UserTable{//����Ա�ࡢѧ�������
	public:
		/*
			��������������˽�г�Ա�����ṩ�ӿڸ��ⲿ����,����ṩһϵ��Set �� get ����
			set�������������ö����˽������ֵ�� get���������ڻ�ȡ�����˽������ֵ��
			�������������
		*/
		void setId(char* id){	strcpy(this->id, id);}
		char* getId(){	return id;}
		void setType(int type){	this->type = type;}
		int getType(){	return this->type;}
		void setPasswd(char* passwd){	strcpy(this->passwd, passwd);}
		char* getPasswd(){	return this->passwd;}

	private:
		char id[20]; //�û�id����ʦΪְ����ţ�ѧ��Ϊѧ��
		int type;    //�û�����
		char passwd[20];   //���룻
	};

	public class AcademicStaffTable :public UserTable{ //����Ա��
	public:
		void setName(char *name)
		{
			strcpy(this->name, name);
		}
		void setDepartment(char *department)
		{
			strcpy(this->department, department);
		}
		char* getName()
		{
			return this->name;
		}
		char* getDepartment()
		{
			return this->department;
		}
	private:
		char name[20];
		char department[20];
	};
	public class TeacherTable :public UserTable { //��ʦ
	public:
		void setName(char *name)
		{
			strcpy(this->name, name);
		}
		void setTeacherTitle(char *title)
		{
			strcpy(this->teacherTitle, title);
		}
		char* getName()
		{
			return this->name;
		}
		char* getTeacherTitle()
		{
			return this->teacherTitle;
		}
	private:
		char name[20];
		char teacherTitle[20];
	};
	public class StudentTable :public UserTable{ //ѧ������
	public:
		char* getName(){
			return this->name;
		}
		void setName(char* name){
			strcpy(this->name, name);
		}
		void setSex(int sex){
			this->sex = sex;
		}
		int getSex()
		{
			return sex;
		}
		void getBirthday(int &y, int &m, int &d)
		{
			y = birthday.year;
			m = birthday.month;
			d = birthday.day;
		}
		void setBirthday(int y, int m, int d)
		{
			this->birthday.year = y;
			this->birthday.month = m;
			this->birthday.day = d;
		}
		char* getMajor()
		{
			return this->major;
		}
		void setMajor(char *major)
		{
			strcpy(this->major, major);
		}
		char* getPicpath()
		{
			return this->picPath;
		}
		void setPicpath(char* path)
		{
			strcpy(this->picPath, path);
		}
		char* getIdNumber()
		{
			return this->idNumber;
		}
		void setIdNumber(char* idNum)
		{
			strcpy(this->idNumber, idNum);
		}
		bool getIsTalent()
		{
			return isTalent;
		}
		void setIsTalent(bool talent)
		{
			this->isTalent = talent;
		}
		char* getExtraInfo()
		{
			return this->extraInfo;
		}
		void setExtraInfo(char* info)
		{
			strcpy(this->extraInfo, info);
		}
	private:
		char name[20];
		int sex;
		Birthday birthday;
		char major[30];
		char picPath[50];
		char idNumber[50]; //���֤��
		bool isTalent;
		char extraInfo[100];
	};
	public class GraduateTable : public StudentTable{ //˶ʿ��
	public:
		char* getUndergraduateSchool(){
			return this->undergraduateSchool;
		}
		void setUndergraduateSchool(char* school){
			strcpy(this->undergraduateSchool, school);
		}
		char* getSupervisorName(){
			return this->supervisorName;
		}
		void setSupervisorName(char* supervisor){
			strcpy(this->supervisorName, supervisor);
		}
		char* getResearchInterests(){
			return this->researchInterests;
		}
		void setResearchInterests(char* interests){
			strcpy(this->researchInterests, interests);
		}
		void setEntranceScore(int score){
			this->entranceScore = score;
		}
		int getEntranceScore(){
			return this->entranceScore;
		}
	private:
		char undergraduateSchool[20]; //����ѧУ
		char supervisorName[20]; //��ʦ����
		int entranceScore; //��ѧ�ɼ�
		char researchInterests[20]; //�о�����
	};

	public class UndergraduateTable : public StudentTable{
	public:
		void setScore(int score)
		{
			this->score = score;
		}
		int getScore()
		{
			return score;
		}
		char* getSchoolName()
		{
			return this->school;
		}
		void setSchoolName(char* school)
		{
			strcpy(this->school, school);
		}
	private:
		int score; //�߿��ɼ�
		char school[20]; //��ҵ����
	};

	public class Major
	{
	public:
		void setRequiredScore(int score)
		{
			this->requiredScore = score;
		}
		int getRequiredScore()
		{
			return requiredScore;
		}
		char* getMajorName()
		{
			return this->majorName;
		}
		void setMajorName(char* name)
		{
			strcpy(this->majorName, name);
		}
		char* getMajorCode()
		{
			return majorCode;
		}
		void setMajorCode(char *code)
		{
			strcpy(majorCode, code);
		}
		int getType()
		{
			return type;
		}
		void setType(int type)
		{
			this->type = type;
		}
	private:
		char majorCode[20];
		char majorName[30];
		int type;
		int requiredScore;
	};

	public class Course
	{
	public:
		char* getCourseCode()
		{
			return this->courseCode;
		}
		char* getCourseName()
		{
			return this->courseName;
		}
		int getType()
		{
			return this->type;
		}
		int getCredit()
		{
			return this->credit;
		}
		void setCourseCode(char *code)
		{
			strcpy(courseCode, code);
		}
		void setCourseName(char *name)
		{
			strcpy(courseName, name);
		}
		void setType(int type)
		{
			this->type = type;
		}
		void setCredit(int score)
		{
			credit = score;
		}
	private:
		char courseCode[20];
		char courseName[20];
		int type;
		int credit;
	};

	public class selectedCourse //ѡ�α�
	{
	public:
		void setCourseId(char *id)
		{
			strcpy(courseId, id);
		}
		void setStuId(char *id)
		{
			strcpy(stuId, id);
		}
		void setScore(int score)
		{
			this->score = score;
		}
		char* getCourseId()
		{
			return courseId;
		}
		char* getStuId()
		{
			return stuId;
		}
		int getScore()
		{
			return this->score;
		}
	private:
		char courseId[20];
		char stuId[20];
		int score;
	};

	public class courseArrangement //�ſα�
	{
	public:
		void setCourseId(char *id)
		{
			strcpy(courseId, id);
		}
		void setTeacherId(char *id)
		{
			strcpy(teacherId, id);
		}
		void setTime(char *time)
		{
			strcpy(this->time, time);
		}
		void setClassRoom(char *room)
		{
			strcpy(classRoom, room);
		}
		char* getCourseId()
		{
			return courseId;
		}
		char* getTeacherId()
		{
			return teacherId;
		}
		char* getTime()
		{
			return time;
		}
		char* getClassRoom()
		{
			return classRoom;
		}
	private:
		char courseId[20];
		char teacherId[20];
		char time[20];
		char classRoom[20];
	};
}