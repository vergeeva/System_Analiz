#pragma once
#include<cstdlib>
#include<ctime>
using namespace System;


public ref class OBJECT
{
private:
	array <String^>^ Object; //Объекты или свойства
	int Count;//Количество объектов или свойств
public:
	bool Empty(); //Проверка на пустоту
	bool Full(); //Проверка на переполненность
	bool Add(String^ pr); //Добавить
	bool Delete(String^ pr); //Удалить
	String^ Random_Object(); //Сгенерировать рандомный объект
	bool Clear(); //Удалить все
	bool Upload_to(String^ pr); //Загрузить в файл
	bool Take_from(String^ pr); //Взять из файла
	bool View(System::Windows::Forms::ListBox^ LB); //Показать в ЛистБокс
};