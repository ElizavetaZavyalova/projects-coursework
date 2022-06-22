#pragma once
//#include "Splay_parent.h"
#include <list>
#include "Form.h"
#include <forward_list>
#include <fstream>
#include <chrono>
#include <cstdio> 
#include <windows.h>
#include <filesystem>
#include <iostream>
#include <execution>
#include "CompareForm.h"
#include <exception>

#define COUNT_ELEMENT 5

 
class MiniForm {

	enum position { date = 0, birth = 1, work = 2, study = 3, relatives = 4 };
	std::vector<Key*> keys;
public:
	std::vector<int> founds;
	void clear() {
		for (int i = 0; i < COUNT_ELEMENT; i++) {
			founds[i] = -1;
		}
	}
	MiniForm() {
		for (int i = 0; i < COUNT_ELEMENT; i++) {
			founds.push_back(-1);
		}
		keys.push_back(new DataKey());
		keys.push_back(new DataKey());
		keys.push_back(new WorkKey());
		keys.push_back(new EducationKey());
		keys.push_back(new RelativesKey());
	};

	void set_position(const int& position) {
		founds[position] = keys[position]->input_form();
	}
	void set_from_form(BaseForm* form) {
		int j = 0;
		for (auto key = keys.begin(); key != keys.end(); key++) {
			founds[j] = (*key)->set_key_from_form(form); j++;
		}
	}
	~MiniForm() {
		for (auto key = keys.begin(); key != keys.end(); key++) {
			delete (*key);
		}
	}
};

struct baseId {
	std::string id;
	virtual bool is_correct(const MiniForm& miniform, std::list<int>* numbers=nullptr) { return 0; };
	std::string& get_id() { return this->id; }
};
struct IdSplay:public baseId {
	std::vector<Splay<int>::SplayNode*> ptrs;
	virtual bool is_correct(const MiniForm& miniform , std::list<int>*numbers=nullptr)override {
		int count = 0;
		for (auto mini = miniform.founds.begin(); mini != miniform.founds.end(); mini++) {
			if (*mini != -1) {
				numbers->push_back(count);
				if (ptrs[count]->data != *mini) {
					numbers->clear();
					return 0;
				}
			}
			count++;
		}
		return 1;

	}
};

struct IdForwardList:public baseId {
	std::vector<std::forward_list <std::pair<int, std::list<IdForwardList*>>>::iterator> ptrs;
	virtual bool is_correct(const MiniForm& miniform,std::list<int>* numbers=nullptr)override {
		int count = 0;
		for (auto mini = miniform.founds.begin(); mini != miniform.founds.end(); mini++) {
			if (*mini != -1) {
				if ((++(ptrs[count]))->first != *mini) {
					return 0;
				}
			}
			count++;
		}
		return 1;
	}
};

 
class BaseCollection
{protected:
	 
public:
	virtual void Insert(BaseForm*form) = 0;
	virtual void Remove(std::string& name) = 0;
	virtual  std::list<baseId*>* Find(const MiniForm& miniform) =0;
	virtual void Remove_id(baseId* id, std::string& name) = 0;
	virtual Form* get_Form(std::string& name) = 0;
	virtual ~BaseCollection() = default;
};

class Collection
{    
protected:
	std::string BaseName = "D:\\Progaming_projects\\Visual_projects\\Kursevork\\Kursevork\\DataBase\\";
	std::list<baseId*> ids;
	std::string set_form(Form* form) {
		std::string name = std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
		std::string file_name = BaseName + name + "txt";
		std::ofstream file(file_name);
		file << (*form);
		file.close();
		return name;
	}
	int find_start(const MiniForm& miniform) {
		int count = 0;
		for (auto mini = miniform.founds.begin(); mini != miniform.founds.end(); mini++) {
			if (*mini != -1) {
				return count;
			}
			count++;
		}
		return -1;
	}
	void remove_form(std::string& name) {
		std::string file_name = BaseName + name + ".txt";
		if (remove((file_name).c_str()) != 0) {            // удаление файла file.txt
			throw std::exception("Не коректный id");
		}
	}
public:
    virtual ~Collection() {
		for (auto id = ids.begin(); id != ids.end(); id++) {
			delete (*id);
	    }
	 };
};

class ForwardListCollection :public Collection, public BaseCollection {
	std::vector<std::forward_list <std::pair<int, std::list<IdForwardList*>>>> names;
	void insert_form(Form* form, const std::string& name) {
		IdForwardList* id = new IdForwardList();
		id->id = name;
		//id->form = form;
		MiniForm miniform;
		miniform.set_from_form(form);
		delete form;
		ids.push_back(id);
		int count = 0;
		for (auto mini = miniform.founds.begin(); mini != miniform.founds.end(); mini++) {
			bool in_name = 0; auto iter = names[count].before_begin();
			for (auto name = names[count].begin(); name != names[count].end(); name++) {
				if (name->first == (*mini)) {
					name->second.push_front(id);
					//id->iter.push_back(name->second.begin());
					id->ptrs.push_back(iter);
					in_name = 1;  
					break;
				}
				iter++;
			}
			if (!in_name) {
				std::pair<int, std::list<IdForwardList*>>pair;
				pair.first = (*mini);
				pair.second.push_front(id);
				names[count].push_front(pair);
				//id->iter.push_back(names[count].begin()->second.begin());
				id->ptrs.push_back(names[count].before_begin());
			}
			count++;
		}


	}

public:
	Form* get_Form(std::string& name)override {
		std::string file_name = BaseName + name + ".txt";
		std::ifstream file(file_name);
		Form* form = new Form();
		file >> (*form);
		file.close();
		return form;

	}
	void Remove_id(baseId* baseid, std::string& name) override {
		if (dynamic_cast<IdForwardList*>(baseid)) {
			auto id = reinterpret_cast<IdForwardList*>(baseid);
			auto plases = (id->ptrs);
			int count = 0;
			for (auto iter = plases.begin(); iter != plases.end(); iter++) {
				auto plase = (*iter); ++plase;
				plase->second.remove(id);
				if (plase->second.empty()) {
					names[count].erase_after((*iter));
				}
				count++;
			}
			ids.remove(id);
			remove_form(name);
		}
	}
	~ForwardListCollection() {
	}
	ForwardListCollection() {
		for (int i = 0; i < COUNT_ELEMENT; i++) {
			names.push_back(std::forward_list <std::pair<int, std::list<IdForwardList*>>>());
		}
		for (auto& file : std::filesystem::directory_iterator(BaseName)) {
			if (!file.is_directory()) {
				std::basic_string basic_name = file.path().c_str();
				std::string file_name(basic_name.begin() + BaseName.size(), basic_name.end() - 4);
				Form* form = get_Form(file_name);
				insert_form(form, file_name);
			}
		}
	}
	void Insert(BaseForm* form)override {
		if (dynamic_cast<Form*>(form)) {
			std::string id = set_form(reinterpret_cast<Form*>(form));
			insert_form(reinterpret_cast<Form*>(form), id);
			return;
		}
		throw std::exception("Нельзя раскастить в Insert ForwardListCollection");
	}
	std::list<baseId*>* Find(const MiniForm& miniform)override {
		int start = find_start(miniform);
		if (start == -1) {
			throw std::exception("Форма для поиска не задана");
		}
		std::list<baseId*>* ids = new std::list<baseId*>;
		for (auto name = names[start].begin(); name != names[start].end(); name++) {
			if (name->first == miniform.founds[start]) {
				for (auto id = name->second.begin(); id != name->second.end(); id++) {
					if ((*id)->is_correct(miniform, nullptr)) {
						ids->push_back(*id);
					}
				}
			}
		}
		return ids;

	}
	void Remove(std::string& name)override {

		for (auto id = ids.begin(); id != ids.end(); id++) {
			if ((*id)->get_id() == name) {
				Remove_id((*id), name);
				return;
			}

		}
		throw std::exception("Не найдено имя в Remove ForwardListCollection");


	}
};

class SplayCollection :public Collection, public BaseCollection {
		std::vector<Splay<int>> names;
		void insert_form(Form* form, const std::string& name) {
			IdSplay* id = new IdSplay();
			id->id = name;
			//id->form = form;
			MiniForm miniform;
			miniform.set_from_form(form);
			delete form;
			ids.push_back(id);
			int count = 0;
			for (auto mini = miniform.founds.begin(); mini != miniform.founds.end(); mini++) {
				id->ptrs.push_back(names[count].Insert((*mini), id));	count++;
			}


		}
		comparer<int>* compare = nullptr;
	public:
		Form* get_Form(std::string& name)override {
			std::string file_name = BaseName + name + ".txt";
			std::ifstream file(file_name);
			Form* form = new Form();
			file >> (*form);
			file.close();
			return form;

		}
		void Remove_id(baseId* baseid, std::string& name) {
			if (dynamic_cast<IdSplay*>(baseid)) {
				auto id = reinterpret_cast<IdSplay*>(baseid);
				auto nodes = (id->ptrs);
				int count = 0;
				for (auto node = nodes.begin(); node != nodes.end(); node++) {
					names[count].Remove((*node), id);
					count++;
				}
				ids.remove(id);
				remove_form(name);
			}
		}
		~SplayCollection() {
			 
			delete compare;
		}
		SplayCollection() {
			this->compare = new Comparer<int>;
			for (int element = 0; element < COUNT_ELEMENT; element++) {
				names.push_back(Splay<int>());
				names[element].set_compare(compare);
			}
			 
			for (auto& file : std::filesystem::directory_iterator(BaseName.c_str())) {
				if (!file.is_directory()) {
					std::basic_string basic_name = file.path().c_str();
					std::string file_name(basic_name.begin()+BaseName.size(), basic_name.end()-4);
					Form* form = get_Form(file_name);
					insert_form(form, file_name);
				}
			}
		}
		void Insert(BaseForm* form)override {
			if (dynamic_cast<Form*>(form)) {
				std::string id = set_form(reinterpret_cast<Form*>(form));
				insert_form(reinterpret_cast<Form*>(form), id);
				return;
			}
			throw std::exception("Нельзя раскастить в Insert Collection");
		}
		void Remove(std::string& name)override {
			for (auto id = ids.begin(); id != ids.end(); id++) {
				if ((*id)->get_id() == name) {
					Remove_id((*id), name);
					return;
				}
				//Todo exeption
			}
			throw std::exception("ошибка удаления");
		}
		std::list<baseId*>* Find(const MiniForm& miniform)override {
			int start = find_start(miniform);
			if (start == -1) {
				throw std::exception("Форма для поиска не найдена");
			}
			std::list<baseId*>* ids = new std::list<baseId*>;

			std::list<IdSplay*> nodes = names[start].Search(miniform.founds[start], 0);
			for (auto id = nodes.begin(); id != nodes.end(); id++) {
				std::list<int>* nums = new std::list<int>;
				if ((*id)->is_correct(miniform, nums)) {
					ids->push_back(*id);
					if (dynamic_cast<IdSplay*>(*id)) {
						auto node = ((reinterpret_cast<IdSplay*>(*id))->ptrs);
						for (auto num = nums->begin(); num != nums->end(); num++) {
							names[*num].Search(node[*num]);
						}
					}
				}
				delete nums;

			}
			return ids;
		};
    };
