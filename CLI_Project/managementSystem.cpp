#include "loginForm.h"

using namespace ManagementSystemV5; //自己的命名空间

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
