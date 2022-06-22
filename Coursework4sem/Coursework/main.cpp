#include <iostream>
#include "Form.h"
//#include "Splay.h"
//#include "CompareForm.h"
#include <fstream>
#include <chrono>
#include <filesystem>
#include <forward_list>
#include "Interface.h"
 
 

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "hello_world\n";
	Interface interfase;
	while (true) {
		try {
			interfase.menu();
		}
		catch (std::exception& x) {
			std::cout << x.what();
		}
	}
	return 0;
}