#include "loginForm.h"

using namespace ManagementSystemV5; //�Լ��������ռ�

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoginForm ^login = gcnew LoginForm();
	login->Name = "loginForm1";
	Application::Run(login);
	return 0;
}
