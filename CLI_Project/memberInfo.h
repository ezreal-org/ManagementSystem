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

	//生日字段的特殊性，估可使用结构体或者类来定义一个对象的生日情况；本案例使用类；
	class Birthday{  
	public:
		int year;
		int month;
		int day;
	};
	public class UserTable{//管理员类、学生类基类
	public:
		/*
			由于类属性属于私有成员，需提供接口给外部访问,因此提供一系列Set 与 get 方法
			set方法：用于设置对象的私有属性值； get方法：用于获取对象的私有属性值；
			以下类设计相似
		*/
		void setId(char* id){	strcpy(this->id, id);}
		char* getId(){	return id;}
		void setType(int type){	this->type = type;}
		int getType(){	return this->type;}
		void setPasswd(char* passwd){	strcpy(this->passwd, passwd);}
		char* getPasswd(){	return this->passwd;}

	private:
		char id[20]; //用户id，教师为职工编号，学生为学号
		int type;    //用户类型
		char passwd[20];   //密码；
	};

	public class AcademicStaffTable :public UserTable{ //教务员类
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
	public class TeacherTable :public UserTable { //教师
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
	public class StudentTable :public UserTable{ //学生基类
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
		char idNumber[50]; //身份证号
		bool isTalent;
		char extraInfo[100];
	};
	public class GraduateTable : public StudentTable{ //硕士生
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
		char undergraduateSchool[20]; //本科学校
		char supervisorName[20]; //导师姓名
		int entranceScore; //入学成绩
		char researchInterests[20]; //研究方向
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
		int score; //高考成绩
		char school[20]; //毕业高中
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

	public class selectedCourse //选课表
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

	public class courseArrangement //排课表
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