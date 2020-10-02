#include "Header.h"
using namespace System::IO;
#define MAX_SIZE 100

bool OBJECT::Add(String^ pr)
{
	return false;
}

bool OBJECT::Delete(String^ pr)
{

	return false;
}

String^ OBJECT::Random_Object()
{
	throw gcnew System::NotImplementedException();
	// TODO: вставьте здесь оператор return
}

bool OBJECT::Clear()
{
	Count = 0;
	return true;
}

bool OBJECT::Upload_to(String^ pr)
{
	StreamWriter^ My_SW = gcnew StreamWriter(pr);
	for (int i = 0; i < Count-1; i++)
	{
		
		String^ Line = gcnew String("");
		Line = this->Object[i] + "\n";
		My_SW->Write(Line);
	}
	String ^Line = this->Object[Count - 1];
	My_SW->Close();
	return false;
}

bool OBJECT::Take_from(String^ pr)
{
	StreamReader^ SR = gcnew StreamReader(pr);
	String^ str = gcnew String("");
	int i = 0;
	while (str = SR->ReadLine()) {
		Object[i] = str;
		Count++;
	}
	SR->Close();
	return true;
}

bool OBJECT::View(System::Windows::Forms::ListBox^ LB)
{
	for (int i = 0; i < Count; i++)
	{
		LB->Items->Add(Object[i]);
	}
	return true;
}
