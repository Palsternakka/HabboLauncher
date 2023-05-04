#include "pch.h"

#include "Form.h"

using namespace System::Windows::Forms;

[System::STAThreadAttribute]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew HabboLauncherCpp::Form());
  return 0;
}