#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>
#include "BaseForm.h"
#include <map>
 


 

class Form:public BaseForm
{
	static std::vector<int> daysWork;
	static std::vector<int> likejob;
	static std::vector<int> education;
	static std::vector<int> jobprofile;
	friend class DataKey;
	friend class ForenameKey;
	friend class RelativesKey;
	friend class WorkKey;
	friend class EducationKey;
	struct Data:public BaseForm {
		int year = 2000;
		int month = 1;
		int day = 1;
	public:
		int get_minidata() {
			return (year) * 10000 + (month) * 100 + (day);
		}
		void output_form() {
			std::cout << "\nДата:";
			std::cout << "\nДень:" << day;
			std::cout << "\nМесяц:" << day;
			std::cout << "\nГод:" << year;
		}
		void input_form(bool random = 0)override {
			this->input_year(random);
			this->input_month(random);
			this->input_day(random);
		}
		void input_year(bool random = 0) {
			if (random) {
				year = rand() % 150 + 1900;
				return;
			}
			std::cout << "Введите год:";
			std::cin >> year;
		}
		void input_month(bool random = 0) {
			if (random) {
				month = rand() % 13+1;
				return;
			}
			std::cout << "Введите месяц:";
			std::cin >> month;
		}
		void input_day(bool random = 0) {
			if (random) {
				month = rand() % 28 + 1;
				return;
			}
			std::cout << "Введите день:";
			std::cin >> day;
		}
		friend std::ofstream& operator<<(std::ofstream& out, const   Data& object) {
			out << std::to_string(object.year) << " " << std::to_string(object.month) << " " << std::to_string(object.day);
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Data& object) {
			std::string str = "";
			in >> str;
			object.year = atoi(str.c_str());
			in >> str;
			object.month = atoi(str.c_str());
			in >> str;
			object.day = atoi(str.c_str());
			return in;
		}

	};
	struct Forename :public BaseForm { 
		std::string name = "";
		std::string surname = "";
		std::string patronymic = "";
		Data birth;
	public:
		void output_form() {
			std::cout << "\nИнформация о человеке:";
			std::cout << "\nФамилия:"<<surname;
			std::cout << "\nИмя:" << name;
			std::cout << "\nОтчество:" << patronymic;
			birth.output_form();
		}
		void input_form(bool random=0)override {
			this->input_surname(random);
			this->input_name(random);
			this->input_patronymic(random);
			this->input_birth(random);
		}
		void input_name(bool random=0) {
			if (random) {
				String str;
				str.get_random();
				name=str;
				return;
			}
			std::cout << "Введите имя:";
			std::cin >> name;
		}
		void input_surname(bool random=0) {
			if (random) {
				String str;
				str.get_random();
				surname = str;
				return;
			}
			std::cout << "Введите фамилию:";
			std::cin >> surname;
		}
		void input_patronymic(bool random=0) {
			if (random) {
				String str;
				str.get_random();
				patronymic = str;
				return;
			}
			std::cout << "Введите отчество:";
			std::cin >> patronymic;
		}
		void input_birth(bool random = 0) {
			if (random) {
				birth.input_form(random);
				return;
			}
			std::cout << "Введите дату рождения:\n";
			birth.input_form();
			
		}
		friend std::ofstream& operator<<(std::ofstream& out, const Forename& object) {
			out << object.name << " " << object.surname << " " << object.patronymic << " ";
			out<< object.birth;
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Forename& object) {
			in >> object.name;
			in >> object.surname;
			in >> object.patronymic;
			in >> object.birth;
			return in;
		}
	};  
	struct Parents :public BaseForm {
		enum Parent {
			only_mother = 1, only_father = 2, all = 3, no_one = 4
		};
		int size = all;
		Forename mother;
		Forename father;
	public:
		int get_miniparents() {
			if (size == only_mother || size == only_father) {
				return 1;
			}
			if (size == all) {
				return 2;
			}
			if (size == no_one) {
				return 0;
			}
		}
		void output_form() {
			std::cout << "\nИнформация о Родителях:";
			if (size == only_mother || size == all) {
				mother.output_form();
			}
			if (size == only_father || size == all) {
				father.output_form();
			}
		}
		void input_form(bool random=0)override {
			if (!random) {
				std::cout << "Заполните информацию о родителях:\n";
			}
			this->input_size(random);
			if (size == only_mother || size == all) {
				this->input_mother(random);
			}
			if (size == only_father || size == all) {
				this->input_father(random);
			}
		}
		void input_size(bool random=0) {
			if (random) {
				size = rand() % 4 + 1;
					return;
			}
			std::cout << "Выберите скока у вас родителей:\n";
			std::cout << "1 Тока мама\n";
			std::cout << "2 Тока отец\n";
			std::cout << "3 Оба родителя\n";
			std::cout << "4 Сирота\n";
			std::cout << "Введите цифру:";
			std::cin >> size;
		}
		void input_mother(bool random=0) {
			if (random) {
				mother.input_form(random);
				return;
			}
			std::cout << "Введите данные о матери:\n";
			mother.input_form();
		}
		void input_father(bool random=0) {
			if (random) {
				father.input_form(random);
				return;
			}
			std::cout << "Введите данные об отце:\n";
			father.input_form();
		}
		friend std::ofstream& operator<<(std::ofstream& out, const Parents& object) {
			out << std::to_string(object.size);
			if (object.size == only_mother) {
				out << " ";
				out << object.mother;
			}
			else if (object.size == only_father) {
				out << " ";
				out<<object.father;
			}
			else if (object.size == all) {
				out << " ";
				out << object.mother;
				out << " ";
				out << object.father;
			}
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Parents& object) {
			std::string str = ""; in >> str;
			object.size = atoi(str.c_str());
			if (object.size == only_mother) {
				in >> object.mother;  
			}
			else if (object.size == only_father) {
				in >> object.father;  
			}
			else if (object.size == all) {
				in >> object.mother;  
				in >> object.father;  
			}
			return in;
		}
		 
	};   
	struct BrothersSisters :public BaseForm {
		int sisters_count = 0;
		int brothers_count = 0;
	public:
		int get_mini_brothers_sisters() {
			return sisters_count + brothers_count;
		}
		void output_form() {
			std::cout << "\nИнформация о Братьях с Сестрами:";
			std::cout << "\nБратья:" << brothers_count;
			std::cout << "\nСестры:" << sisters_count;

		}
		void input_form(bool random=0)override {
			if (!random) {
				std::cout << "Заполните информацию о братьях с сестрами:\n";
			}
			this->input_brothers(random);
			this->input_sisters(random);
		}
		void input_sisters(bool random=0) {
			if (random) {
				sisters_count = rand() % 10;
				return;
			}
			std::cout << "Введите кол-во сестер:";
			std::cin >> sisters_count;
	     }
		void input_brothers(bool random=0) {
			if (random) {
				brothers_count = rand() % 10;
				return;
			}
			std::cout << "Введите кол-во братьев:";
			std::cin >> brothers_count;
		}
		friend std::ofstream& operator<<(std::ofstream& out, const BrothersSisters& object) {
			out<< std::to_string(object.sisters_count);
			out << std::to_string(object.brothers_count) << " ";
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, BrothersSisters& object) {
			std::string str = "";
			in >> str;
			object.sisters_count = atoi(str.c_str());
			in >> str;
			object.brothers_count= atoi(str.c_str());
			return in;
		}
	};  
	struct Work :public BaseForm {
		enum Profile {
			humanitarian = 1, technical = 2, naturally = 3, physical =4, creativity=5,
		};
		int type = technical;//1
		std::string name_of_work = "";
		int like_your_job = 0;//1...10
		int working_days = 0; //0...7
	public:
		int get_mini_work() {
			return type*1000+ like_your_job*10+ working_days;
		}
		void output_form() {
			std::cout << "\nИнформация о Работе:";
			std::cout <<"\nТип:"<< (type == 1) ? ("humanitarian") : (type == 2) ? ("technical") : \
				(type == 3) ? ("naturally") : (type == 4) ? ("physical") : ("creativity");
			std::cout << "\nЛюбовь работы:"<< like_your_job;
			std::cout << "\nРабочии дни:" << working_days;
		}
		void input_form(bool random=0) {
			if (!random) {
				std::cout << "Заполните информацию по вашей работе:\n";
			}
			this->input_type(random);
			this->input_name_of_work(random);
			this->input_working_days(random);
			this->input_like_your_job(random);
		}
		void input_type(bool random = 0) {
			if (random) {
				type = rand() % 5 + 1;
				return;
			}
			std::cout << "Выберите профиль вашей работы:\n";
			std::cout << "1 Гомунитарный\n";
			std::cout << "2 Технический\n";
			std::cout << "3 Естественный\n";
			std::cout << "4 Физический(Спортивный)\n";
			std::cout << "5 Творчиский\n";
			std::cout << "Введите цифру:";
			std::cin >> type;

		}
		void input_name_of_work(bool random=0) {
			if (random) {
				String str;
				str.get_random();
				name_of_work=str;
				return;
			}
			std::cout << "Введите название вашей должности:";
			String str;
			std::cin >> str;
			name_of_work=str;
			 
		}
		void input_like_your_job(bool random = 0) {
			if (random) {
				like_your_job = rand() % 10+1;
				return;
			}

			std::cout << "Оцените наскока вы любите свою работу по шкале от 1...10:\n";
			std::cout << "Введите цифру:";
			std::cin >> like_your_job;
		}
		void input_working_days(bool random=0) {
			if (random) {
				working_days = rand() % 7+1;
				return;
			}
			std::cout << "Скока дней в неделю вы работаете введите цифру от 0...7:\n";
			std::cout << "Введите цифру:";
			std::cin >> working_days;
		}
		friend std::ofstream& operator<<(std::ofstream& out, const Work& object) {
			out<<std::to_string(object.type) << " ";
			out << object.name_of_work; out << " ";
			out << std::to_string(object.like_your_job) << " ";
			out << std::to_string(object.working_days);
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Work& object) {
			std::string str = "";
			in >> str;
			object.type = atoi(str.c_str());
			in >> object.name_of_work; 
			in >> str;
			object.like_your_job = atoi(str.c_str());
			in >> str;
			object.working_days = atoi(str.c_str());
			return in;
		}
	};
	struct Education :public BaseForm {
		enum Degree {
			  college=0, higher=1, school = 2,
		};
		bool type[3] = { 0,0,0 };
		std::string names[2];
		bool yes_or_no(bool random=0) {
			if (random) {
				return (rand() % 2);
			}
			int inter = 0;
			std::cout << "1 Да\n";
			std::cout << "2 Нет\n";
			std::cout << "Введите номер:";
			std::cin >> inter;
			return (inter%2);
		}
	public:
		int get_mini_education() {
			return type[0] * 100 + type[1] * 10 + type[2];
		}
		void output_form() {
			std::cout << "\nИнформация об образованни:\n";
			if (type[college]) {
				std::cout << "\nкончил Коледж:" << names[college];
			}
			if (type[higher]) {
				std::cout << "\nОкончил вуз:" << names[higher];
			}
			if (type[school]) {
				std::cout << "\nОкончил школу";
			}
		}
		void input_form (bool random=0)override {
			if (!random) {
				std::cout << "Заполните информацию о вашем образование:\n";
			}
			this->input_school(random);
			this->input_college(random);
			this->input_higher(random);
		}
		void input_school(bool random = 0) {
			if (!random) {
				std::cout << "Окончилили вы школу:\n";
			}
			type[school] = yes_or_no(random);
		}
		void input_college(bool random = 0) {
			if (random) {
				type[college] = yes_or_no(random);
				if (type[college]) {
					String str;
					str.get_random();
					names[college]=str;
				}
				return;
			}
			std::cout << "Имеетели вы СПО:\n";
			type[college] = yes_or_no();
			if (type[college]) {
				std::cout << "Введите название коледжа:\n";
				String str;
				std::cin >> str;
				names[college] = str;
			}
		}
		void input_higher(bool random=0) {
			if (random) {
				type[higher] = yes_or_no(random);
				if (type[higher]) {
					String str;
					str.get_random();
					names[higher]=str;
				}
				return;
			}
			std::cout << "Имеетели вы Высшее:\n";
			type[higher] = yes_or_no();
			if (type[higher]) {
				std::cout << "Введите название вуза:\n";
				String str;
				std::cin>>str;
				names[higher]=str;
			}
		}
		friend std::ofstream& operator<<(std::ofstream& out, const Education& object) {
			for (int i = 0; i < 3; i++) {
				out << " ";
				out<<std::to_string(object.type[i]);
			}
			for (int i = 0; i < 2; i++) {
				if (object.type[i]) {
					out << " ";
					out<<object.names[i];
				}
			}
			return out;
		}
		friend std::ifstream& operator>>(std::ifstream& in, Education& object) {
			for (int i = 0; i < 3; i++) {
				std::string str = "";
				in >> str;
				object.type[i] = atoi(str.c_str());
			}
			for (int i = 0; i < 2; i++) {
				if (object.type[i]) {
					in >> object.names[i];  
				}
			}
			return in;
		}
	};
	 
	Forename name;///6
	Parents parent; //1
	BrothersSisters  relatives; //2
	Education study;//3
	Work job; //4
	Data today; ///3
	
public:
	friend std::ofstream& operator<<(std::ofstream& out, const Form& object) {
		out << object.name << " ";
		out << object.parent << " ";
		out << object.relatives << " ";
		out << object.study << " ";
		out << object.job << " ";
		out << object.today;
		return out;
	}
	friend std::ifstream& operator>>(std::ifstream& in, Form& object) {
		in >> object.name;  
		in >> object.parent;   
		in >> object.relatives;  
		 
		in >> object.study;   
		in >> object.job;   
		in >> object.today;   
		return in;
	}
	void output_form() {
		today.output_form();
		name.output_form();
		parent.output_form();
		relatives.output_form();
		study.output_form();
		job.output_form();
	}
	void input_form(bool random=0) {
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		today.input_form(random);
		name.input_form(random);
		parent.input_form(random);
		relatives.input_form(random);
		study.input_form(random);
		job.input_form(random);
	}
	friend class  BaseComapare;
};



class FormFactoryMethod : public BaseFormFactoryMetod
{
public:
	BaseForm* create(bool rand=0) const override
	{
		Form *f = new Form();
		 
		f->input_form(rand);
		return f;
	}
};