#pragma once
#include "memberInfo.h"
#include  "typeDefinition.h"   //枚举类型定义文件
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//名空间ManagementSystemV5的定义开始
namespace ManagementSystemV5 {
	using namespace System;
	using namespace System::IO;
	using namespace System::Data::Odbc;
	using namespace Runtime::InteropServices;

	//Storage类定义开始
	public ref class Storage
	{
	private:
		OdbcConnection^ Conn;  //数据库连接对象
		OdbcDataAdapter ^adapter; //sql命令和数据源的桥接对象
		DataSet^ set; //结果缓存集

					  /*   dbConnect方法用于初始化数据库连接。该函数使用指定的用户名、密码访问数据源，接下来用sql语句和数据库连接创建桥接对象，再从桥接对象中填充set结果集合，并创建tableName指定的表对象，然后程序就可以通过tableName去操作set中的数据 */
		bool dbConnect(String^ sql, String ^tableName) { //tableName为想要填充的数据表
			try { //获得数据库连接，UI、PWD分别为访问mangement数据库的用户名和密码
				Conn = gcnew OdbcConnection("DSN=managementSystemV5;UI=root;PWD=tk;");
				//用指定sql语句、数据库连接创建桥接对象
				adapter = gcnew OdbcDataAdapter(sql, Conn);
				set = gcnew DataSet();
				adapter->Fill(set, tableName); //从adatper中填充set，创建tableName指定的表对象
			}
			catch (System::SystemException^) {
				MessageBox::Show("数据库连接异常！");
				return false;
			}
			return true;
		}// dbConnect方法定义结束

		 /* getRowById方法用于获得数据表对象行数据。该函数使用主键获得指定数据表中指定的数据行。具体思路是从数据缓存set中获取tableName指定的数据表，接下来给数据表指定主键，再通过主键来查询数据表，得到相应的数据行。数据表的主键可能不止一个属性字段，如：选课表selectedCouse的主键为课程id和学生id组成。为了更好的扩展性，getRowById函数的参数设计为要操作的数据表名称tableName，构成该表主键的字段数组primaryKeyList以及相应属性的值keyForFind */
		DataRow^ getRowById(String ^tableName, cli::array<String ^>^ primaryKeyList, cli::array<String ^>^ keyForFind) {
			DataTable^ table = set->Tables[tableName];
			DataRow^ newRow;
			cli::array<DataColumn^>^ keys = gcnew cli::array<DataColumn^>(primaryKeyList->Length);
			for (int i = 0; i < primaryKeyList->Length; i++) { //设置主键
				keys[i] = table->Columns[primaryKeyList[i]];
			}
			table->PrimaryKey = keys;
			try {
				newRow = table->Rows->Find(keyForFind);
			}
			catch (System::SystemException^) {
				return nullptr;
			}
			return newRow;
		}// getRowById方法定义结束

		 /* persistent方法用于保存对数据表的修改。使用DataSet对数据缓存进行修改删除等操作时，需要显示地调用DataAdapter->Update()保存对数据表的修改，然后调用AcceptChanges()与数据库同步*/
		bool persistent(String ^tableName) {
			DataSet^ updateSet;
			try {
				updateSet = set->GetChanges();
				if (updateSet) {
					OdbcCommandBuilder^ b = gcnew OdbcCommandBuilder(adapter);
					adapter->Update(updateSet, tableName);
					set->AcceptChanges();
				}
			}
			catch (Exception^) {
				MessageBox::Show("数据库存储异常!");
				return false;
			}
			return true;
		} // persistent方法定义结束
	public:
		/*  login是登录方法。用户使用账号、密码、用户类型登录时,先调用下文要介绍的使用账号查询数据库的readLoginInfo方法，传入用户账号，返回该账号对应的登录对象，接下来通过返回的登录对象的密码字段、类 型字段和用户输入值进行比较，完成登录验证。*/
		UserTable* login(char* id, char* passwd, LoginUserType type) {
			String ^sql = "select * from usertable";
			if (!dbConnect(sql, "usertable")) return false; //数据库连接失败
			UserTable *p = new UserTable();
			p = readLoginInfo(id);
			if (p == nullptr) return nullptr; //不存在id
											  //校验用户名、密码是否一致，教务员/教师校验类型
			if (strcmp(p->getPasswd(), passwd) == 0 && (p->getType() == (int)type || type == LoginUserType::LOGIN_STUDENT)) {
				return p;
			}
			return nullptr; //用户名密码不匹配
		} //login方法定义结束

		  /*readLoginInfo方法 使用账号查询数据库。该函数传入要读取的对象id，返回该id对应的登录对象。当对象不存在时返回nullptr。readLoginInfo函数先调用dbConnect函数初始化数据库连接，同时创建login表对象，接下来指定 login表主键为‘id’，调用getRowById函数获取登录对象id对应的数据行row，然后用数据行row 的值设置登录对象的各个属性。*/
		UserTable* readLoginInfo(char *id) {
			UserTable *p = new UserTable();
			dbConnect("select * from usertable;", "usertable");
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("usertable", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setId((char*)Marshal::StringToHGlobalAnsi((String^)(row["id"])).ToPointer());
			p->setPasswd((char*)Marshal::StringToHGlobalAnsi((String^)(row["passwd"]))
				.ToPointer());
			p->setType((int)(row["type"]));
			return p;
		} // readLoginInfo方法定义结束
		  /*writeLoginInfo方法写登陆信息表。使用DataSet进行数据库读写时，用户对结果集Set的修改、删除操作对应着对数据库中数据表的操作，最后再需要显式地把修改同步到数据库。writeLoginInfo方法先调用dbConnect函数初始化数 据库连接并创建login表对象，接下来指定login表主键为‘id’，调用getRowById函数，根据返回 的row是否为空来检测要写入的登录对象以前是否存在，当存在时先删除。然后创建新数据newRow，用待写入的登录对象的属性设置新行的字段，调用table-> Rows- Add(newRow)  把新行添加至数据表，最后调用persistent函数保存对login表的修改。写课程表、选课表、专业表、学生表的方法类似。*/
		bool writeLoginInfo(UserTable *p) {
			if (!dbConnect("select * from usertable;", "usertable")) {
				return false;
			}
			DataTable^ table = set->Tables["usertable"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getId();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id"; //指定主键为id字段
			DataRow^ row = getRowById("usertable", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getId();
			newRow["id"] = gcnew String(temp.c_str());
			newRow["type"] = p->getType();
			temp = p->getPasswd();
			newRow["passwd"] = gcnew String(temp.c_str());
			table->Rows->Add(newRow);
			if (!persistent("usertable")) {
				return false;
			}
			return true;
		}  // writeLoginInfo方法定义结束

		   // updateInfo()为修改密码函数，用于修改密码
		bool updateInfo(int type, char* id, char* oldpw, char *passwd) {
			UserTable *p = new UserTable();
			p = readLoginInfo(id); //调用读取用户信息函数
			if (strcmp(oldpw, p->getPasswd()) == 0 && p->getType() == type) { //校验成功
				p->setPasswd(passwd);
				writeLoginInfo(p); //将密码信息重新写回数据文件
				return true;
			}
			delete p;
			return false;
		} // updateInfo方法定义结束

		  // deleteLoginInfo()函数的功能是删除用户的登录信息；通过ID删除对应数据表行
		bool deleteLoginInfo(char *id) {
			if (!dbConnect("select * from usertable;", "usertable")) return false;
			DataTable^ table = set->Tables["usertable"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("usertable", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent("usertable")) {
					return true;
				}
			}
			return false;
		}// deleteLoginInfo方法定义结束

		 //deleteCourse()函数的功能是从数据表中删除课程信息
		bool deleteCourse(char *id) {
			if (!dbConnect("select * from course;", "course")) return false;
			DataTable^ table = set->Tables["course"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "courseCode";
			DataRow^ row = getRowById("course", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent("course")) {
					return true;
				}
			}
			return false;
		}//deleteCourse方法定义结束

		 // writeCourse()函数的功能是：将课程信息写入数据表。
		bool writeCourse(Course *p) {
			if (!dbConnect("select * from course;", "course")) return false;
			DataTable^ table = set->Tables["course"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getCourseCode();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "courseCode";
			DataRow^ row = getRowById("course", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getCourseCode();
			newRow["courseCode"] = gcnew String(temp.c_str());
			temp = p->getCourseName();
			newRow["courseName"] = gcnew String(temp.c_str());
			newRow["type"] = p->getType();
			newRow["credit"] = p->getCredit();
			table->Rows->Add(newRow);
			if (persistent("course")) return true;
			return false;
		}// writeCourse方法定义结束
		 // readCourse()函数的功能是从数据表中读取课程信息
		Course* readCourse(char *id) {
			Course *p = new Course();
			if (!dbConnect("select * from course;", "course")) return nullptr;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "courseCode";
			DataRow^ row = getRowById("course", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setCourseCode(id);
			p->setCourseName((char*)Marshal::StringToHGlobalAnsi((String^)
				(row["courseName"])).ToPointer());
			p->setType((int)(row["type"]));
			p->setCredit((int)row["credit"]);
			return p;
		}// readCourse方法定义结束

		 //deleteMajor()函数的功能是从数据表中删除某一专业信息
		bool deleteMajor(char *id) {
			if (!dbConnect("select * from major;", "major")) return false;
			DataTable^ table = set->Tables["major"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "majorCode";
			DataRow^ row = getRowById("major", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent("major")) { //保存修改
					return true;
				}
			}
			return false;
		}//deleteMajor方法定义结束

		 // writeMajor()函数的功能是将专业信息写入数据表
		bool writeMajor(Major *p) {
			if (!dbConnect("select * from major;", "major")) return false;
			DataTable^ table = set->Tables["major"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getMajorCode();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "majorCode";
			DataRow^ row = getRowById("major", primaryKeyList, keyForFind);
			if (row != nullptr) { //删掉行
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getMajorCode();
			newRow["majorCode"] = gcnew String(temp.c_str());
			temp = p->getMajorName();
			newRow["majorName"] = gcnew String(temp.c_str());
			newRow["type"] = p->getType();
			newRow["requiredScore"] = p->getRequiredScore();
			table->Rows->Add(newRow); //加入新行
			if (persistent("major")) return true;
			return false;
		}// writeMajor方法定义结束

		 // readMajor()函数的功能是从数据表中读取专业信息
		Major* readMajor(char *id) {
			Major *p = new Major();
			if (!dbConnect("select * from major;", "major")) return false;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "majorCode"; // 指定主键
			DataRow^ row = getRowById("major", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setMajorCode(id);
			p->setMajorName((char*)Marshal::StringToHGlobalAnsi((String^)
				(row["majorName"])).ToPointer());
			p->setType((int)(row["type"]));
			p->setRequiredScore((int)row["requiredScore"]);
			return p;
		}// readMajor方法定义结束

		 //deleteCourseArrangement()的功能是从数据表中删除某一条排课记录
		bool deleteCourseArrangement(char *id) {
			if (!dbConnect("select * from courseArrangement;", "courseArrangement"))
				return false;
			DataTable^ table = set->Tables["courseArrangement"];
			string temp = id;
			String ^cIdTeaId = gcnew String(temp.c_str());
			//主键为 courseId 和 teacherId 的组合
			String ^courseId = cIdTeaId->Substring(0, cIdTeaId->IndexOf(" "));
			String ^teacherId = cIdTeaId->Substring(cIdTeaId->IndexOf(" ") + 1);
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			keyForFind[0] = courseId;
			keyForFind[1] = teacherId;
			primaryKeyList[0] = "courseId";
			primaryKeyList[1] = "teacherId";
			DataRow^ row = getRowById("courseArrangement", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent("courseArrangement")) {
					return true;
				}
			}
			return false;
		}//deleteCourseArrangement方法定义结束

		 // writeCourseArrangement()函数的功能是将排课信息写入数据表
		bool writeCourseArrangement(courseArrangement *p) {
			if (!dbConnect("select * from coursearrangement;", "coursearrangement"))
				return false;
			DataTable^ table = set->Tables["coursearrangement"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			string strKey = p->getCourseId();
			keyForFind[0] = gcnew String(strKey.c_str());
			strKey = p->getTeacherId();
			keyForFind[1] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "courseId";
			primaryKeyList[1] = "teacherId";
			DataRow^ row = getRowById("coursearrangement", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getCourseId();
			newRow["courseId"] = gcnew String(temp.c_str());
			temp = p->getTeacherId();
			newRow["teacherId"] = gcnew String(temp.c_str());
			temp = p->getTime();
			newRow["classTime"] = gcnew String(temp.c_str());
			temp = p->getClassRoom();
			newRow["classRoom"] = gcnew String(temp.c_str());
			table->Rows->Add(newRow);
			if (persistent("coursearrangement")) return true;
			return false;
		} // writeCourseArrangement方法定义结束

		  // readCourseArrangement()函数的功能是从数据表中读取排课信息
		courseArrangement* readCourseArrangement(char *id) {
			courseArrangement *p = new courseArrangement();
			if (!dbConnect("select * from coursearrangement;", "coursearrangement"))
				return nullptr;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			string temp = id;
			String ^cIdTeaId = gcnew String(temp.c_str());
			//主键为 courseId 和 teacherId 的组合
			String ^courseId = cIdTeaId->Substring(0, cIdTeaId->IndexOf(" "));
			String ^teacherId = cIdTeaId->Substring(cIdTeaId->IndexOf(" ") + 1);
			keyForFind[0] = courseId;
			keyForFind[1] = teacherId;
			primaryKeyList[0] = "courseId";
			primaryKeyList[1] = "teacherId";
			DataRow^ row = getRowById("coursearrangement", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setCourseId(id);
			p->setTeacherId((char*)Marshal::StringToHGlobalAnsi((String^)
				(row["teacherId"])).ToPointer());
			p->setTime((char*)Marshal::StringToHGlobalAnsi((String^)
				(row["classTime"])).ToPointer());
			p->setClassRoom((char*)Marshal::StringToHGlobalAnsi((String ^)
				(row["classRoom"])).ToPointer());
			return p;
		}// readCourseArrangement方法定义结束

		bool deleteSelectedCourse(char *id) {
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return false;
			DataTable^ table = set->Tables["selectedcourse"];
			string temp = id;
			String ^cIdstuId = gcnew String(temp.c_str());
			//主键为 courseId 和 stuId 的组合
			String ^courseId = cIdstuId->Substring(0, cIdstuId->IndexOf(" "));
			String ^stuId = cIdstuId->Substring(cIdstuId->IndexOf(" ") + 1);
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			keyForFind[0] = courseId;
			keyForFind[1] = stuId;
			primaryKeyList[0] = "courseId";
			primaryKeyList[1] = "stuId";
			DataRow^ row = getRowById("selectedcourse", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent("selectedcourse")) {
					return true;
				}
			}
			return false;
		}//deleteSelectedCourse方法定义结束

		 // writeSelectedCourse ()函数的功能是将选课信息写入数据表
		bool writeSelectedCourse(selectedCourse *p) {
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return false;
			DataTable^ table = set->Tables["selectedcourse"];
			//主键为 courseId 和 stuId 的组合 
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			string strKey = p->getCourseId();
			keyForFind[0] = gcnew String(strKey.c_str());
			strKey = p->getStuId();
			keyForFind[1] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "courseId";
			primaryKeyList[1] = "stuId";
			DataRow^ row = getRowById("selectedcourse", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getCourseId();
			newRow["courseId"] = gcnew String(temp.c_str());
			temp = p->getStuId();
			newRow["stuId"] = gcnew String(temp.c_str());
			newRow["score"] = p->getScore();
			table->Rows->Add(newRow);
			if (persistent("selectedcourse")) return true;
			return false;
		}// writeSelectedCourse方法定义结束

		 // readSelectedCourse()函数的功能是：从数据表中读取选课信息
		selectedCourse* readSelectedCourse(char *id) {
			selectedCourse *p = new selectedCourse();
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return nullptr;
			string temp = id;
			String ^cIdstuId = gcnew String(temp.c_str());
			//主键为 courseId 和 stuId 的组合
			String ^courseId = cIdstuId->Substring(0, cIdstuId->IndexOf(" "));
			String ^stuId = cIdstuId->Substring(cIdstuId->IndexOf(" ") + 1);
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			keyForFind[0] = courseId;
			keyForFind[1] = stuId;
			primaryKeyList[0] = "courseId";
			primaryKeyList[1] = "stuId";
			DataRow^ row = getRowById("selectedcourse", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setCourseId((char*)Marshal::StringToHGlobalAnsi((String ^)
				(row["courseId"])).ToPointer());
			p->setStuId((char*)Marshal::StringToHGlobalAnsi((String ^)
				(row["stuId"])).ToPointer());
			p->setScore((int)(row["score"]));
			return p;
		}// readSelectedCourse方法定义结束
		 // writeAcademicStaff()函数的功能是将教务员信息写入数据表
		bool writeAcademicStaff(AcademicStaffTable *p) {
			if (!dbConnect("select * from academicstaff;", "academicstaff")) return false;
			DataTable^ table = set->Tables["academicstaff"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getId();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("academicstaff", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getId();
			newRow["id"] = gcnew String(temp.c_str());
			temp = p->getName();
			newRow["name"] = gcnew String(temp.c_str());
			temp = p->getDepartment();
			newRow["department"] = gcnew String(temp.c_str());
			table->Rows->Add(newRow);
			if (persistent("academicstaff")) return true;
			return false;
		}// writeAcademicStaff方法定义结束

		 // writeTeacher()函数的功能是将任课老师信息写入数据表
		bool writeTeacher(TeacherTable *p) {
			if (!dbConnect("select * from teacher;", "teacher")) return false;
			DataTable^ table = set->Tables["teacher"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getId();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("teacher", primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
			}
			string temp;
			DataRow^ newRow = table->NewRow();
			temp = p->getId();
			newRow["id"] = gcnew String(temp.c_str());
			temp = p->getName();
			newRow["name"] = gcnew String(temp.c_str());
			temp = p->getTeacherTitle();
			newRow["teacherTitle"] = gcnew String(temp.c_str());
			table->Rows->Add(newRow);
			if (persistent("teacher")) return true;
			return false;
		}// writeTeacher方法定义结束

		 // readTeacherInfo()函数的功能是读取任课老师信息
		TeacherTable* readTeacherInfo(char *id) {
			TeacherTable *p = new TeacherTable();
			if (!dbConnect("select * from teacher;", "teacher")) return nullptr;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("teacher", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setId(id);
			p->setName((char*)Marshal::StringToHGlobalAnsi((String ^)
				(row["name"])).ToPointer());
			p->setTeacherTitle((char*)Marshal::StringToHGlobalAnsi((String ^)
				(row["teacherTitle"])).ToPointer());
			return p;
		}// readTeacherInfo方法定义结束

		 //deleteStaffInfo()函数的功能是从数据表中删除选中的教职工(教师与教务员)信息
		bool deleteStaffInfo(char *id, int type) {
			String ^sql, ^tableName;
			sql = "select * from ";
			if (type == (int)UserTypeCode::USER_ACADEMICSTAFF) tableName =
				"academicstaff";
			else if (type == (int)UserTypeCode::USER_TEACHER) tableName = "teacher";
			sql += tableName;
			if (!dbConnect(sql, tableName)) return false;
			DataTable^ table = set->Tables[tableName];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById(tableName, primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent(tableName)) return true;
			}
			return false;
		}//deleteStaffInfo方法定义结束

		 //deleteStuInfo()函数功能为从数据表中删除某一条学生信息记录
		bool deleteStuInfo(char *id, int type) {
			String ^sql, ^tableName;
			sql = "select * from ";
			if (type == (int)UserTypeCode::USER_GRADUATE) tableName = "graduate";
			else if (type == (int)UserTypeCode::USER_UNDERGRADUATE) tableName =
				"undergraduate";
			sql += tableName;
			if (!dbConnect(sql, tableName)) return false;
			DataTable^ table = set->Tables[tableName];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById(tableName, primaryKeyList, keyForFind);
			if (row != nullptr) {
				row->Delete();
				if (persistent(tableName)) return true;
			}
			return false;
		}//deleteStuInfo方法定义结束

		 // readGraduateInfo()函数的功能是从数据表中读取硕士生信息
		GraduateTable* readGraduateInfo(char *id) {
			if (!dbConnect("select * from graduate;", "graduate")) return nullptr;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string temp = id;
			keyForFind[0] = gcnew String(temp.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("graduate", primaryKeyList, keyForFind);
			if (row != nullptr) {
				GraduateTable* pm1 = new GraduateTable();
				char id[20];
				char name[20];
				int sex;
				int type;
				Birthday birthday;
				char major[30];
				char picPath[50];
				char idNumber[50];
				bool isTalent;
				char extraInfo[100];
				char undergraduateSchool[20]; //本科学校
				char supervisorName[20]; //导师姓名
				int entranceScore; //入学成绩
				char researchInterests[20]; //研究方向
				sprintf(id, "%s", (String^)row["id"]);
				sprintf(name, "%s", (String^)row["name"]);
				sprintf(extraInfo, "%s", (String^)row["extraInfo"]);
				sprintf(major, "%s", (String^)row["major"]);
				sprintf(picPath, "%s", (String^)row["picPath"]);
				sprintf(idNumber, "%s", (String^)row["idNum"]);
				sprintf(undergraduateSchool, "%s", (String^)row["undergraduateSchool"]);
				sprintf(supervisorName, "%s", (String^)row["supervisorName"]);
				sprintf(researchInterests, "%s", (String^)row["researchInterests"]);
				sex = (int)row["sex"];
				type = (int)row["type"];
				entranceScore = (int)row["entranceScore"];
				birthday.year = (int)row["birthYear"];
				birthday.month = (int)row["birthmonth"];
				birthday.day = (int)row["birthday"];
				isTalent = (int)row["isTalent"];
				//设置对象属性
				pm1->setId(id);
				pm1->setName(name);
				pm1->setType(type);
				pm1->setExtraInfo(extraInfo);
				pm1->setMajor(major);
				pm1->setPicpath(picPath);
				pm1->setIdNumber(idNumber);
				pm1->setSex(sex);
				pm1->setBirthday(birthday.year, birthday.month, birthday.day);
				pm1->setIsTalent(isTalent);
				pm1->setUndergraduateSchool(undergraduateSchool);
				pm1->setSupervisorName(supervisorName);
				pm1->setEntranceScore(entranceScore);
				pm1->setResearchInterests(researchInterests);
				return pm1;
			}
			return nullptr;
		}// readGraduateInfo方法定义结束

		 // readUndergradateInfo()函数的功能是从数据表中读取本科生信息
		UndergraduateTable* readUndergradateInfo(char *id) {
			if (!dbConnect("select * from undergraduate;", "undergraduate"))
				return nullptr;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string temp = id;
			keyForFind[0] = gcnew String(temp.c_str());
			primaryKeyList[0] = "id";
			DataRow^ row = getRowById("undergraduate", primaryKeyList, keyForFind);
			if (row != nullptr) {
				UndergraduateTable* pm1 = new UndergraduateTable();
				char id[20];
				char name[20];
				int sex;
				int type;
				Birthday birthday;
				char major[30];
				char picPath[50];
				char idNumber[50];
				bool isTalent;
				char extraInfo[100];
				int score;
				char school[50];
				sprintf(id, "%s", (String^)row["id"]);
				sprintf(name, "%s", (String^)row["name"]);
				sprintf(extraInfo, "%s", (String^)row["extraInfo"]);
				sprintf(major, "%s", (String^)row["major"]);
				sprintf(picPath, "%s", (String^)row["picPath"]);
				sprintf(idNumber, "%s", (String^)row["idNum"]);
				sprintf(school, "%s", (String^)row["school"]);
				sex = (int)row["sex"];
				type = (int)row["type"];
				birthday.year = (int)row["birthYear"];
				birthday.month = (int)row["birthmonth"];
				birthday.day = (int)row["birthday"];
				isTalent = (int)row["isTalent"];
				score = (int)row["score"];
				pm1->setId(id);
				pm1->setName(name);
				pm1->setType(type);
				pm1->setExtraInfo(extraInfo);
				pm1->setMajor(major);
				pm1->setPicpath(picPath);
				pm1->setIdNumber(idNumber);
				pm1->setSex(sex);
				pm1->setBirthday(birthday.year, birthday.month, birthday.day);
				pm1->setIsTalent(isTalent);
				pm1->setScore(score);
				pm1->setSchoolName(school);
				return pm1;
			}
			return nullptr;
		}// readUndergradateInfo方法定义结束

		 // writeGraduate()函数的功能是将硕士生信息写入数据表
		bool writeGraduate(GraduateTable *p) {
			if (!dbConnect("select * from graduate;", "graduate")) return false;
			DataTable^ table = set->Tables["graduate"];
			DataRow^ row;
			DataRow^ newRow = table->NewRow();
			string str;
			str = p->getId();
			newRow["id"] = gcnew String(str.c_str());
			str = p->getName();
			newRow["name"] = gcnew String(str.c_str());
			str = p->getMajor();
			newRow["major"] = gcnew String(str.c_str());
			newRow["sex"] = p->getSex();
			newRow["type"] = p->getType();
			newRow["entranceScore"] = p->getEntranceScore();
			int year, month, day;
			p->getBirthday(year, month, day);
			newRow["birthYear"] = year;
			newRow["birthMonth"] = month;
			newRow["birthDay"] = day;
			newRow["isTalent"] = p->getIsTalent();
			str = p->getPicpath();
			newRow["picPath"] = gcnew String(str.c_str());
			str = p->getExtraInfo();
			newRow["extraInfo"] = gcnew String(str.c_str());
			str = p->getIdNumber();
			newRow["idNum"] = gcnew String(str.c_str());
			str = p->getUndergraduateSchool();
			newRow["undergraduateSchool"] = gcnew String(str.c_str());
			str = p->getSupervisorName();
			newRow["supervisorName"] = gcnew String(str.c_str());
			str = p->getResearchInterests();
			newRow["researchInterests"] = gcnew String(str.c_str());

			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string temp = p->getId();
			keyForFind[0] = gcnew String(temp.c_str());
			primaryKeyList[0] = "id";
			row = getRowById("graduate", primaryKeyList, keyForFind);
			if (row != nullptr) { //修改
				row->Delete();	//可以简单的先删除,再添加,也可以直接修改row
			}
			table->Rows->Add(newRow);
			if (persistent("graduate")) return true;
			return false;
		}// writeGraduate方法定义结束

		 // writeUndergraduate()函数的功能是将本科生信息写入数据表
		bool writeUndergraduate(UndergraduateTable *p) {
			if (!dbConnect("select * from undergraduate;", "undergraduate")) return false;
			DataTable^ table = set->Tables["undergraduate"];
			DataRow^ row;
			DataRow^ newRow = table->NewRow();
			string str;
			str = p->getId();
			newRow["id"] = gcnew String(str.c_str());
			str = p->getName();
			newRow["name"] = gcnew String(str.c_str());
			str = p->getMajor();
			newRow["major"] = gcnew String(str.c_str());
			newRow["sex"] = p->getSex();
			newRow["type"] = p->getType();
			newRow["score"] = p->getScore();
			int year, month, day;
			p->getBirthday(year, month, day);
			newRow["birthYear"] = year;
			newRow["birthMonth"] = month;
			newRow["birthDay"] = day;
			newRow["isTalent"] = p->getIsTalent();
			str = p->getPicpath();
			newRow["picPath"] = gcnew String(str.c_str());
			str = p->getExtraInfo();
			newRow["extraInfo"] = gcnew String(str.c_str());
			str = p->getIdNumber();
			newRow["idNum"] = gcnew String(str.c_str());
			str = p->getSchoolName();
			newRow["school"] = gcnew String(str.c_str());

			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string temp = p->getId();
			keyForFind[0] = gcnew String(temp.c_str());
			primaryKeyList[0] = "id";
			row = getRowById("undergraduate", primaryKeyList, keyForFind);
			if (row != nullptr) { //修改
				row->Delete();	//可以简单的先删除,再添加,也可以直接修改row
			}
			table->Rows->Add(newRow);
			if (persistent("undergraduate")) return true;
			return false;
		}// writeUndergraduate方法定义结束

		 /* readAllLoginAcountId方法是获取所有用户ID。 在访问数据库时，还有一类操作很常用，即获取指定数据表的所有行。如：学生选课时，获取所有可供选择的课程ID；教师录入成绩时，获取所有修读所授课程的学生ID；教务员管理所有学生信息时，获取所有被管理学生的ID等。如管理员要获得登陆表(UserTable)中所有用户账号时，先调用dbConnect函数初始化数据库连接并创建usertable表，再使用set->Tables["usertable"]获得刚创建的usertable表，其中table->Rows->Count 为usertable数据表的行数，接下来使用table->Rows[index]或者for each(DataRow^ row in table->Rows)即可访问数据表中所有的数据行。*/
		cli::array<String^>^ readAllLoginAcountId() {
			if (!dbConnect("select * from usertable;", "usertable")) return nullptr;
			DataTable^ table = set->Tables["usertable"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["id"]);
			}
			return retString;
		}// readAllLoginAcountId方法定义结束

		 // readAllStuId()函数的功能是读取所有本科生或所有硕士生的学号
		cli::array<String^>^ readAllStuId(int type) { //学生类型
			String ^tableName;
			if (type == (int)UserTypeCode::USER_GRADUATE) //研究生
				tableName = "graduate";
			else if (type == (int)UserTypeCode::USER_UNDERGRADUATE)
				tableName = "undergraduate";
			String ^sql = "select * from ";
			sql += tableName;
			if (!dbConnect(sql, tableName)) return nullptr;
			DataTable^ table = set->Tables[tableName];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["id"]);
			}
			return retString;
		} //readAllStuId方法定义结束

		  // readAllMajorId ()函数的功能是获取所有专业代码
		cli::array<String^>^ readAllMajorId() {
			if (!dbConnect("select * from major;", "major")) return nullptr;
			DataTable^ table = set->Tables["major"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["majorCode"]);
			}
			return retString;
		}// readAllMajorId方法定义结束

		 // readAllCourseArrangementId()函数的功能是获取所有排课表(courseId+teacherId)
		cli::array<String^>^ readAllCourseArrangementId() {
			if (!dbConnect("select * from coursearrangement;", "coursearrangement"))
				return nullptr;
			DataTable^ table = set->Tables["coursearrangement"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index] = (String^)(row["courseId"]);
				retString[index] += " ";
				retString[index++] += (String^)(row["teacherId"]);
			}
			return retString;
		}// readAllCourseArrangementId方法定义结束

		 // readAllSelectedCourseId()函数的功能是获取所有选课标识信息（学号和课程号）
		cli::array<String^>^ readAllSelectedCourseId() {
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return nullptr;
			DataTable^ table = set->Tables["selectedcourse"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index] = (String^)(row["courseId"]);
				retString[index] += " ";
				retString[index++] += (String^)(row["stuId"]);
			}
			return retString;
		}// readAllSelectedCourseId方法定义结束

		 // readAllCourseId()函数的功能是读取所有课程的课程号
		cli::array<String^>^ readAllCourseId() {
			if (!dbConnect("select * from course;", "course")) return nullptr;
			DataTable^ table = set->Tables["course"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["courseCode"]);
			}
			return retString;
		}// readAllCourseId方法定义结束
	}; 	//Storage类定义结束
}  //名空间ManagementSystemV5结束
