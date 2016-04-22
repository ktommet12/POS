#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace MySql::Data;
using namespace System::Windows::Forms;
using namespace System::Collections;

public ref class Category {
public:
	String^ Name;
	int ID;
	Category() {}
	Category(String^ name, int id) {
		Name = name;
		ID = id;
	}
	Category(Object^ obj) {

	}
	
	//Getters for the category
	String^ getName() {
		return Name;
	}
	int getID() {
		return ID;
	}
};
