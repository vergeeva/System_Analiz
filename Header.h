#pragma once
#include<cstdlib>
#include<ctime>
using namespace System;


public ref class OBJECT
{
private:
	array <String^>^ Object; //������� ��� ��������
	int Count;//���������� �������� ��� �������
public:
	bool Empty(); //�������� �� �������
	bool Full(); //�������� �� ���������������
	bool Add(String^ pr); //��������
	bool Delete(String^ pr); //�������
	String^ Random_Object(); //������������� ��������� ������
	bool Clear(); //������� ���
	bool Upload_to(String^ pr); //��������� � ����
	bool Take_from(String^ pr); //����� �� �����
	bool View(System::Windows::Forms::ListBox^ LB); //�������� � ��������
};