#pragma once
#include <iostream>
#include <fstream>
#include "Collection.h"
#include <functional>

class Interface
{
	MiniForm miniform;
	std::list<baseId*>* list = nullptr;
	std::string basename = "D:\\Progaming_projects\\Visual_projects\\Kursevork\\Kursevork\\DataBase\\";
	BaseCollection* collection = nullptr;
	BaseFormFactoryMetod* factory = nullptr;
public:
	~Interface() {
		delete list;
		delete collection;
		delete factory;
	}
	void set_compare() {
		while (true) {
			std::cout << "�������� ��������� ������:\n";
			std::cout << "1.���� ��������.\n";
			std::cout << "2.���� ����e���\n";
			std::cout << "3.������.\n";
			std::cout << "4.�����.\n";
			std::cout << "5.������������.\n";
			std::cout << "7.�������� ���� �����.\n";
			std::cout << "8.���������.\n";
			int form = String::cout_in_range(1, 8, "");
			if (form == 7) {
			}
			else if (form == 8) {
				return;
			}
			else {
				miniform.set_position(--form);
			}
		}

	}
	void create_form(bool random = 0) {
		if (random) {
			std::cout << "������� ���-�� ����:";
			int count = 0;
			std::cin >> count;
			for (int i = 0; i < count; i++) {
				BaseForm* form = factory->create(random);
				collection->Insert(form);
			}
			return;
		}
		BaseForm* form = factory->create(random);
		collection->Insert(form);
	}
	void find_forms() {
		if (list != nullptr) {
			delete list;
		}
		list = collection->Find(miniform);
		std::cout << "���� ������� �����:\n";
		for (auto element = list->begin(); element != list->end(); element++) {
			std::cout <<"id:"<< ((*element)->get_id()) << "\n";
		}

	}
	void get_form() {
		std::cout << "������� id �����:";
		std::string id ="";
		std::cin >> id;
		Form* form = this->collection->get_Form(id);
		form->output_form();
		delete form;
	}
	void delete_form() {
		std::cout << "������� id �����:";
		std::string id;
		std::cin >> id;
		collection->Remove(id);
	}
	void chose_collection() {
		std::cout << "1.Splay.\n";
		std::cout << "2.forvar_list.\n";
		int  chose = String::cout_in_range(1, 2, "������� ���������");
		if (chose == 1) {
			delete collection;
			collection = new SplayCollection;
		}
		else {
			delete collection;
			collection = new ForwardListCollection;
		}
	}
	Interface():Interface(new SplayCollection) {
		factory = new FormFactoryMethod;
		 
	}
	Interface(BaseCollection* collection) {

		this->collection= collection ;
		factory = new FormFactoryMethod;
	}
	void menu() {
		while (1) {
			std::cout << "�������� ��� ������:\n";
			std::cout << "1.������ ��������� ��� ������.\n";
			std::cout << "2.������� �����.\n";
			std::cout << "3.������� ��������� �����.\n";
			std::cout << "4.����� �����.\n";
			std::cout << "5.������� �����.\n";
			std::cout << "6.���������� �����.\n";
			std::cout << "7.������������� �������.\n";
			std::cout << "8.���������� �������.\n";
			std::cout << "9.������� ���������.\n";
			int chose = 0;
			std::cin >> chose;
			switch (chose) {
			case 1:
				set_compare();
				break;
			case 2:
				create_form();
				break;
			case 3:
				create_form(1);
				break;
			case 4:
				find_forms();
				break;
			case 5:
				delete_form();
				break;
			case 6:
				get_form();
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				chose_collection();
				break;
			};
		}
	}

};

