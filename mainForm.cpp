#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	binaryTree::mainForm form; 
	Application::Run(% form);
}

//array<String^>^ arg