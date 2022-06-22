#pragma once
#include "BaseForm.h"
 
#include "Splay.h"
#include <vector>
 
 
 

class Key{
public:
	virtual int input_form()=0;
	virtual int set_key_from_form(BaseForm* base)=0;
	virtual ~Key() = default;

};

class DataKey : public Key {
public:
	int input_form()override {
		int data = 0;
		std::cout << "������� ����:";
		return 10000 * String::cout_in_range(0, 2060, "������� ��� ")+\
		       100 * String::cout_in_range(0, 12, "������� ����� ")+\
		       String::cout_in_range(0, 31, "������� ���� ");

	}
	int set_key_from_form(BaseForm* base)override {
		if (dynamic_cast<Form*>(base)) {
			return (reinterpret_cast<Form*>(base)->today).get_minidata();
		}
		//Todo exeption
	}
	 

};


class RelativesKey : public Key {
public:
	int input_form( )override {
		 
		std::cout << "������� �������������:";
		return String::cout_in_range(0, 2, "���-�� ��������� ")+\
		     String::cout_in_range(0, 100, "������� ���-�� ������� ")+\
		     String::cout_in_range(0, 100, "������� ���-�� ������ ");
	 

	}
	int set_key_from_form(BaseForm* base)override {
		if (dynamic_cast<Form*>(base)) {
			return (reinterpret_cast<Form*>(base)->parent).get_miniparents() + \
				(reinterpret_cast<Form*>(base)->relatives).get_mini_brothers_sisters();
		}
		//Todo exeption
	}


};

class WorkKey : public Key {
public:
	int input_form()override {
		 
		std::cout << "������� �a����:";
		std::cout << "�������� ������� ����� ������:\n";
		std::cout << "1 ������������\n";
		std::cout << "2 �����������\n";
		std::cout << "3 ������������\n";
		std::cout << "4 ����������(����������)\n";
		std::cout << "5 ����������\n";
		return String::cout_in_range(1, 5, "������� �����")*1000+\
		       String::cout_in_range(0, 10, "������ ������ ")*10+\
		       String::cout_in_range(0, 7, "���-�� ������� ���� ");
		 

	}
	int set_key_from_form(BaseForm* base)override {
		if (dynamic_cast<Form*>(base)) {
			return (reinterpret_cast<Form*>(base)->job).get_mini_work();
		}
		//Todo exeption
	}


};


class EducationKey : public Key {
public:
	int input_form()override {
		 
		return String::cout_in_range(0, 1, "������\n1(��)0(���) ") * 100 + \
			String::cout_in_range(0, 1, "������\n1(��)0(���) ") * 10 + \
			String::cout_in_range(0, 1, "�����\n1(��)0(���) ");
		 

	}
	int set_key_from_form(BaseForm* base) override{
		if (dynamic_cast<Form*>(base)) {
			return (reinterpret_cast<Form*>(base)->study).get_mini_education();
		}
		//Todo exeption
	}


};


 






 