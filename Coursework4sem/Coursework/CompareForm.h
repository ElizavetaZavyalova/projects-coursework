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
		std::cout << "Введите дату:";
		return 10000 * String::cout_in_range(0, 2060, "Введите год ")+\
		       100 * String::cout_in_range(0, 12, "Введите Месяц ")+\
		       String::cout_in_range(0, 31, "Введите День ");

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
		 
		std::cout << "Введите Родственников:";
		return String::cout_in_range(0, 2, "Кол-во Родителей ")+\
		     String::cout_in_range(0, 100, "Введите кол-во Братьев ")+\
		     String::cout_in_range(0, 100, "Введите кол-во Сестер ");
	 

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
		 
		std::cout << "Введите Рaботу:";
		std::cout << "Выберите профиль вашей работы:\n";
		std::cout << "1 Гомунитарный\n";
		std::cout << "2 Технический\n";
		std::cout << "3 Естественный\n";
		std::cout << "4 Физический(Спортивный)\n";
		std::cout << "5 Творчиский\n";
		return String::cout_in_range(1, 5, "Введите цифру")*1000+\
		       String::cout_in_range(0, 10, "Оценка работы ")*10+\
		       String::cout_in_range(0, 7, "Кол-во рабочих дней ");
		 

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
		 
		return String::cout_in_range(0, 1, "Коледж\n1(да)0(нет) ") * 100 + \
			String::cout_in_range(0, 1, "Высшее\n1(да)0(нет) ") * 10 + \
			String::cout_in_range(0, 1, "Школа\n1(да)0(нет) ");
		 

	}
	int set_key_from_form(BaseForm* base) override{
		if (dynamic_cast<Form*>(base)) {
			return (reinterpret_cast<Form*>(base)->study).get_mini_education();
		}
		//Todo exeption
	}


};


 






 