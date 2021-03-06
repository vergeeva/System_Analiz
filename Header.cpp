#include "Header.h"
using namespace System::IO;
#define MAX_SIZE 100

OBJECT::OBJECT()
{
	Object = gcnew array <String^>(MAX_SIZE);
	Count = 0;
}

bool OBJECT::In(String^ f)
{
	for (int i = 0; i < Count; i++)
	{
		if (Object[i] == f) return 1;
	}
	return 0;
}


bool OBJECT::Empty()
{
	return Count == 0;
}

bool OBJECT::Full()
{
	return Count == MAX_SIZE;
}

bool OBJECT::Add(String^ pr)
{
	if (!Full()&& !In(pr))
	{
		this->Object[Count] = pr;
		this->Count++;
		return 1;
	}
	else return 0;
}

bool OBJECT::Delete(String^ pr)
{
	if (!Empty())
	{
		for (int i = 0; i < Count; i++)
		{
			if (Object[i] == pr)
			{
				for (int k = i; k < Count; k++)
				{
					Object[k] = Object[k + 1];
				}
				Count--;
				return 1;
			}
		}
	}
	return 0;
}

String^ OBJECT::Random_Object()
{
	srand(time(NULL));
	int i = 0 + rand()%(Count);
	return Object[i];
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
	My_SW->Write(Line);
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
		i++;
	}
	SR->Close();
	return true;
}

bool OBJECT::View(System::Windows::Forms::ListBox^ LB)
{
	LB->Items->Clear();
	for (int i = 0; i < Count; i++)
	{
		LB->Items->Add(Object[i]);
	}
	return true;
}
