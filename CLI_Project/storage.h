#pragma once
#include "memberInfo.h"
#include  "typeDefinition.h"   //ö�����Ͷ����ļ�
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//���ռ�ManagementSystemV5�Ķ��忪ʼ
namespace ManagementSystemV5 {
	using namespace System;
	using namespace System::IO;
	using namespace System::Data::Odbc;
	using namespace Runtime::InteropServices;

	//Storage�ඨ�忪ʼ
	public ref class Storage
	{
	private:
		OdbcConnection^ Conn;  //���ݿ����Ӷ���
		OdbcDataAdapter ^adapter; //sql���������Դ���ŽӶ���
		DataSet^ set; //������漯

					  /*   dbConnect�������ڳ�ʼ�����ݿ����ӡ��ú���ʹ��ָ�����û����������������Դ����������sql�������ݿ����Ӵ����ŽӶ����ٴ��ŽӶ��������set������ϣ�������tableNameָ���ı����Ȼ�����Ϳ���ͨ��tableNameȥ����set�е����� */
		bool dbConnect(String^ sql, String ^tableName) { //tableNameΪ��Ҫ�������ݱ�
			try { //������ݿ����ӣ�UI��PWD�ֱ�Ϊ����mangement���ݿ���û���������
				Conn = gcnew OdbcConnection("DSN=managementSystemV5;UI=root;PWD=tk;");
				//��ָ��sql��䡢���ݿ����Ӵ����ŽӶ���
				adapter = gcnew OdbcDataAdapter(sql, Conn);
				set = gcnew DataSet();
				adapter->Fill(set, tableName); //��adatper�����set������tableNameָ���ı����
			}
			catch (System::SystemException^) {
				MessageBox::Show("���ݿ������쳣��");
				return false;
			}
			return true;
		}// dbConnect�����������

		 /* getRowById�������ڻ�����ݱ���������ݡ��ú���ʹ���������ָ�����ݱ���ָ���������С�����˼·�Ǵ����ݻ���set�л�ȡtableNameָ�������ݱ������������ݱ�ָ����������ͨ����������ѯ���ݱ��õ���Ӧ�������С����ݱ���������ܲ�ֹһ�������ֶΣ��磺ѡ�α�selectedCouse������Ϊ�γ�id��ѧ��id��ɡ�Ϊ�˸��õ���չ�ԣ�getRowById�����Ĳ������ΪҪ���������ݱ�����tableName�����ɸñ��������ֶ�����primaryKeyList�Լ���Ӧ���Ե�ֵkeyForFind */
		DataRow^ getRowById(String ^tableName, cli::array<String ^>^ primaryKeyList, cli::array<String ^>^ keyForFind) {
			DataTable^ table = set->Tables[tableName];
			DataRow^ newRow;
			cli::array<DataColumn^>^ keys = gcnew cli::array<DataColumn^>(primaryKeyList->Length);
			for (int i = 0; i < primaryKeyList->Length; i++) { //��������
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
		}// getRowById�����������

		 /* persistent�������ڱ�������ݱ���޸ġ�ʹ��DataSet�����ݻ�������޸�ɾ���Ȳ���ʱ����Ҫ��ʾ�ص���DataAdapter->Update()��������ݱ���޸ģ�Ȼ�����AcceptChanges()�����ݿ�ͬ��*/
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
				MessageBox::Show("���ݿ�洢�쳣!");
				return false;
			}
			return true;
		} // persistent�����������
	public:
		/*  login�ǵ�¼�������û�ʹ���˺š����롢�û����͵�¼ʱ,�ȵ�������Ҫ���ܵ�ʹ���˺Ų�ѯ���ݿ��readLoginInfo�����������û��˺ţ����ظ��˺Ŷ�Ӧ�ĵ�¼���󣬽�����ͨ�����صĵ�¼����������ֶΡ��� ���ֶκ��û�����ֵ���бȽϣ���ɵ�¼��֤��*/
		UserTable* login(char* id, char* passwd, LoginUserType type) {
			String ^sql = "select * from usertable";
			if (!dbConnect(sql, "usertable")) return false; //���ݿ�����ʧ��
			UserTable *p = new UserTable();
			p = readLoginInfo(id);
			if (p == nullptr) return nullptr; //������id
											  //У���û����������Ƿ�һ�£�����Ա/��ʦУ������
			if (strcmp(p->getPasswd(), passwd) == 0 && (p->getType() == (int)type || type == LoginUserType::LOGIN_STUDENT)) {
				return p;
			}
			return nullptr; //�û������벻ƥ��
		} //login�����������

		  /*readLoginInfo���� ʹ���˺Ų�ѯ���ݿ⡣�ú�������Ҫ��ȡ�Ķ���id�����ظ�id��Ӧ�ĵ�¼���󡣵����󲻴���ʱ����nullptr��readLoginInfo�����ȵ���dbConnect������ʼ�����ݿ����ӣ�ͬʱ����login����󣬽�����ָ�� login������Ϊ��id��������getRowById������ȡ��¼����id��Ӧ��������row��Ȼ����������row ��ֵ���õ�¼����ĸ������ԡ�*/
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
		} // readLoginInfo�����������
		  /*writeLoginInfo����д��½��Ϣ��ʹ��DataSet�������ݿ��дʱ���û��Խ����Set���޸ġ�ɾ��������Ӧ�Ŷ����ݿ������ݱ�Ĳ������������Ҫ��ʽ�ذ��޸�ͬ�������ݿ⡣writeLoginInfo�����ȵ���dbConnect������ʼ���� �ݿ����Ӳ�����login����󣬽�����ָ��login������Ϊ��id��������getRowById���������ݷ��� ��row�Ƿ�Ϊ�������Ҫд��ĵ�¼������ǰ�Ƿ���ڣ�������ʱ��ɾ����Ȼ�󴴽�������newRow���ô�д��ĵ�¼����������������е��ֶΣ�����table-> Rows- Add(newRow)  ��������������ݱ�������persistent���������login����޸ġ�д�γ̱�ѡ�α�רҵ��ѧ����ķ������ơ�*/
		bool writeLoginInfo(UserTable *p) {
			if (!dbConnect("select * from usertable;", "usertable")) {
				return false;
			}
			DataTable^ table = set->Tables["usertable"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getId();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "id"; //ָ������Ϊid�ֶ�
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
		}  // writeLoginInfo�����������

		   // updateInfo()Ϊ�޸����뺯���������޸�����
		bool updateInfo(int type, char* id, char* oldpw, char *passwd) {
			UserTable *p = new UserTable();
			p = readLoginInfo(id); //���ö�ȡ�û���Ϣ����
			if (strcmp(oldpw, p->getPasswd()) == 0 && p->getType() == type) { //У��ɹ�
				p->setPasswd(passwd);
				writeLoginInfo(p); //��������Ϣ����д�������ļ�
				return true;
			}
			delete p;
			return false;
		} // updateInfo�����������

		  // deleteLoginInfo()�����Ĺ�����ɾ���û��ĵ�¼��Ϣ��ͨ��IDɾ����Ӧ���ݱ���
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
		}// deleteLoginInfo�����������

		 //deleteCourse()�����Ĺ����Ǵ����ݱ���ɾ���γ���Ϣ
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
		}//deleteCourse�����������

		 // writeCourse()�����Ĺ����ǣ����γ���Ϣд�����ݱ�
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
		}// writeCourse�����������
		 // readCourse()�����Ĺ����Ǵ����ݱ��ж�ȡ�γ���Ϣ
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
		}// readCourse�����������

		 //deleteMajor()�����Ĺ����Ǵ����ݱ���ɾ��ĳһרҵ��Ϣ
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
				if (persistent("major")) { //�����޸�
					return true;
				}
			}
			return false;
		}//deleteMajor�����������

		 // writeMajor()�����Ĺ����ǽ�רҵ��Ϣд�����ݱ�
		bool writeMajor(Major *p) {
			if (!dbConnect("select * from major;", "major")) return false;
			DataTable^ table = set->Tables["major"];
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = p->getMajorCode();
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "majorCode";
			DataRow^ row = getRowById("major", primaryKeyList, keyForFind);
			if (row != nullptr) { //ɾ����
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
			table->Rows->Add(newRow); //��������
			if (persistent("major")) return true;
			return false;
		}// writeMajor�����������

		 // readMajor()�����Ĺ����Ǵ����ݱ��ж�ȡרҵ��Ϣ
		Major* readMajor(char *id) {
			Major *p = new Major();
			if (!dbConnect("select * from major;", "major")) return false;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(1);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(1);
			string strKey = id;
			keyForFind[0] = gcnew String(strKey.c_str());
			primaryKeyList[0] = "majorCode"; // ָ������
			DataRow^ row = getRowById("major", primaryKeyList, keyForFind);
			if (row == nullptr) return nullptr;
			p->setMajorCode(id);
			p->setMajorName((char*)Marshal::StringToHGlobalAnsi((String^)
				(row["majorName"])).ToPointer());
			p->setType((int)(row["type"]));
			p->setRequiredScore((int)row["requiredScore"]);
			return p;
		}// readMajor�����������

		 //deleteCourseArrangement()�Ĺ����Ǵ����ݱ���ɾ��ĳһ���ſμ�¼
		bool deleteCourseArrangement(char *id) {
			if (!dbConnect("select * from courseArrangement;", "courseArrangement"))
				return false;
			DataTable^ table = set->Tables["courseArrangement"];
			string temp = id;
			String ^cIdTeaId = gcnew String(temp.c_str());
			//����Ϊ courseId �� teacherId �����
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
		}//deleteCourseArrangement�����������

		 // writeCourseArrangement()�����Ĺ����ǽ��ſ���Ϣд�����ݱ�
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
		} // writeCourseArrangement�����������

		  // readCourseArrangement()�����Ĺ����Ǵ����ݱ��ж�ȡ�ſ���Ϣ
		courseArrangement* readCourseArrangement(char *id) {
			courseArrangement *p = new courseArrangement();
			if (!dbConnect("select * from coursearrangement;", "coursearrangement"))
				return nullptr;
			cli::array<String^>^ keyForFind = gcnew cli::array<String^>(2);
			cli::array<String^>^ primaryKeyList = gcnew cli::array<String^>(2);
			string temp = id;
			String ^cIdTeaId = gcnew String(temp.c_str());
			//����Ϊ courseId �� teacherId �����
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
		}// readCourseArrangement�����������

		bool deleteSelectedCourse(char *id) {
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return false;
			DataTable^ table = set->Tables["selectedcourse"];
			string temp = id;
			String ^cIdstuId = gcnew String(temp.c_str());
			//����Ϊ courseId �� stuId �����
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
		}//deleteSelectedCourse�����������

		 // writeSelectedCourse ()�����Ĺ����ǽ�ѡ����Ϣд�����ݱ�
		bool writeSelectedCourse(selectedCourse *p) {
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return false;
			DataTable^ table = set->Tables["selectedcourse"];
			//����Ϊ courseId �� stuId ����� 
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
		}// writeSelectedCourse�����������

		 // readSelectedCourse()�����Ĺ����ǣ������ݱ��ж�ȡѡ����Ϣ
		selectedCourse* readSelectedCourse(char *id) {
			selectedCourse *p = new selectedCourse();
			if (!dbConnect("select * from selectedcourse;", "selectedcourse"))
				return nullptr;
			string temp = id;
			String ^cIdstuId = gcnew String(temp.c_str());
			//����Ϊ courseId �� stuId �����
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
		}// readSelectedCourse�����������
		 // writeAcademicStaff()�����Ĺ����ǽ�����Ա��Ϣд�����ݱ�
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
		}// writeAcademicStaff�����������

		 // writeTeacher()�����Ĺ����ǽ��ο���ʦ��Ϣд�����ݱ�
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
		}// writeTeacher�����������

		 // readTeacherInfo()�����Ĺ����Ƕ�ȡ�ο���ʦ��Ϣ
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
		}// readTeacherInfo�����������

		 //deleteStaffInfo()�����Ĺ����Ǵ����ݱ���ɾ��ѡ�еĽ�ְ��(��ʦ�����Ա)��Ϣ
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
		}//deleteStaffInfo�����������

		 //deleteStuInfo()��������Ϊ�����ݱ���ɾ��ĳһ��ѧ����Ϣ��¼
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
		}//deleteStuInfo�����������

		 // readGraduateInfo()�����Ĺ����Ǵ����ݱ��ж�ȡ˶ʿ����Ϣ
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
				char undergraduateSchool[20]; //����ѧУ
				char supervisorName[20]; //��ʦ����
				int entranceScore; //��ѧ�ɼ�
				char researchInterests[20]; //�о�����
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
				//���ö�������
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
		}// readGraduateInfo�����������

		 // readUndergradateInfo()�����Ĺ����Ǵ����ݱ��ж�ȡ��������Ϣ
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
		}// readUndergradateInfo�����������

		 // writeGraduate()�����Ĺ����ǽ�˶ʿ����Ϣд�����ݱ�
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
			if (row != nullptr) { //�޸�
				row->Delete();	//���Լ򵥵���ɾ��,�����,Ҳ����ֱ���޸�row
			}
			table->Rows->Add(newRow);
			if (persistent("graduate")) return true;
			return false;
		}// writeGraduate�����������

		 // writeUndergraduate()�����Ĺ����ǽ���������Ϣд�����ݱ�
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
			if (row != nullptr) { //�޸�
				row->Delete();	//���Լ򵥵���ɾ��,�����,Ҳ����ֱ���޸�row
			}
			table->Rows->Add(newRow);
			if (persistent("undergraduate")) return true;
			return false;
		}// writeUndergraduate�����������

		 /* readAllLoginAcountId�����ǻ�ȡ�����û�ID�� �ڷ������ݿ�ʱ������һ������ܳ��ã�����ȡָ�����ݱ�������С��磺ѧ��ѡ��ʱ����ȡ���пɹ�ѡ��Ŀγ�ID����ʦ¼��ɼ�ʱ����ȡ�����޶����ڿγ̵�ѧ��ID������Ա��������ѧ����Ϣʱ����ȡ���б�����ѧ����ID�ȡ������ԱҪ��õ�½��(UserTable)�������û��˺�ʱ���ȵ���dbConnect������ʼ�����ݿ����Ӳ�����usertable����ʹ��set->Tables["usertable"]��øմ�����usertable������table->Rows->Count Ϊusertable���ݱ��������������ʹ��table->Rows[index]����for each(DataRow^ row in table->Rows)���ɷ������ݱ������е������С�*/
		cli::array<String^>^ readAllLoginAcountId() {
			if (!dbConnect("select * from usertable;", "usertable")) return nullptr;
			DataTable^ table = set->Tables["usertable"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["id"]);
			}
			return retString;
		}// readAllLoginAcountId�����������

		 // readAllStuId()�����Ĺ����Ƕ�ȡ���б�����������˶ʿ����ѧ��
		cli::array<String^>^ readAllStuId(int type) { //ѧ������
			String ^tableName;
			if (type == (int)UserTypeCode::USER_GRADUATE) //�о���
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
		} //readAllStuId�����������

		  // readAllMajorId ()�����Ĺ����ǻ�ȡ����רҵ����
		cli::array<String^>^ readAllMajorId() {
			if (!dbConnect("select * from major;", "major")) return nullptr;
			DataTable^ table = set->Tables["major"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["majorCode"]);
			}
			return retString;
		}// readAllMajorId�����������

		 // readAllCourseArrangementId()�����Ĺ����ǻ�ȡ�����ſα�(courseId+teacherId)
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
		}// readAllCourseArrangementId�����������

		 // readAllSelectedCourseId()�����Ĺ����ǻ�ȡ����ѡ�α�ʶ��Ϣ��ѧ�źͿγ̺ţ�
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
		}// readAllSelectedCourseId�����������

		 // readAllCourseId()�����Ĺ����Ƕ�ȡ���пγ̵Ŀγ̺�
		cli::array<String^>^ readAllCourseId() {
			if (!dbConnect("select * from course;", "course")) return nullptr;
			DataTable^ table = set->Tables["course"];
			cli::array<String^>^ retString = gcnew cli::array<String^>(table->Rows->Count);
			int index = 0;
			for each(DataRow^ row in table->Rows) {
				retString[index++] = (String^)(row["courseCode"]);
			}
			return retString;
		}// readAllCourseId�����������
	}; 	//Storage�ඨ�����
}  //���ռ�ManagementSystemV5����
