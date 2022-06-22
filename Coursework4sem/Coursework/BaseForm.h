#pragma once
#include <iostream>
#include <vector>
#include "Splay_parent.h"
#include <string>

 
class MiniForm;
class Key;
class DataKey;
class ForenameKey;
class RelativesKey;
class WorkKey;
class EducationKey;

class String :public std::string {

public:
	String() :std::string() {

	}
	String(const char* str) :std::string(str) {

	}
	friend std::istream& operator >> (std::istream& in, String& str) {
		char c = ' ';
		while (c == ' '||c=='\n') {
			in >> c;
		}
		while (c != '\n') {
			(c == ' ') ? (str += '_') : (str += c);
			c = in.get();
		}
		return in;
	}
	friend std::ostream& operator << (std::ostream& out, const String& str) {

		for (auto c = str.begin(); c != str.end(); c++) {
			(*c == '_') ? (out << ' ') : (out << *c);
		}
		return out;
	}
	void get_random() {
		*this += rand() % 25 + 65;
		int k = rand() % 30 + 1;
		for (int i = 0; i < k; i++) {
			*this += rand() % 25 + 97;

		}
		return;
	}
	static void input_vector(std::vector<String>& information, std::string str = "") {
		String inf = "";

		std::cout<<"Если тока (для завешения <end>), то значит все.\n";
		std::cout << str<< "(для завешения <end>):";
		std::cin >> inf;
		while (inf != "end") {
			information.push_back(inf);
			inf = "";
			std::cout << str<<"(для завешения <end>):";
			std::cin >> inf;
		}
	}
	static int cout_in_range(const int& first, const int& second, const std::string&str ) {
		int num = -9;
		do{
			std::cout << str<<"["<<first<<";"<<second<<"]: ";
			std::cin >> num;
		}while (!(first <= num && num <= second));
		return num;
	}
	 

};

 
class BaseForm {

public:

	virtual void input_form(bool random = 0) = 0;
	virtual void output_form() = 0;
	virtual ~BaseForm() = default;

};

class BaseFormFactoryMetod{

public:

	virtual BaseForm* create(bool rand=0) const = 0;
	virtual ~BaseFormFactoryMetod() = default;
	 

};

 

