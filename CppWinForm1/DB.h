#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace MySql::Data;
using namespace System::Windows::Forms;
using namespace System::Collections;


public ref class DB {
private:
	//Database Connection String
	String^ constring = L"server=108.163.238.185;user id=sdosburn_Group1;password=uat1234; database=sdosburn_inventoryfood;persistsecurityinfo=True";
	

	//Database Connection
	MySqlConnection^ connectToDB() {
		String^ constring = L"server=108.163.238.185;user id=sdosburn_Group1;password=uat1234; database=sdosburn_inventoryfood;persistsecurityinfo=True";
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		return conDataBase;
	}
public:
	bool addProductToDB(String^ Name, int category, String^ UPC, String^ Price, String^ quantity) {
		MySqlConnection^ conDataBase = connectToDB();
		//converting text representation of quantity to int for database insertion
		int quant = Convert::ToInt32(quantity);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO products (id,Product_Name, Product_Category,Quantity, UPC) VALUES (NULL,'" + Name + "', '" + category + "', '" + quant + "','" + UPC + "')", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader(); //executes sql command
		}
		catch (Exception^) {
			throw;
			return false;
		}
		return true;
	}
	bool logUserIn(String^ username, String^ password) {
		MySqlConnection^ conDataBase = connectToDB();
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("Select * FROM user_login WHERE username=username", conDataBase);
		MySqlDataReader^ reader;

		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();
			while (reader->Read()) {
				if (username == reader->GetString(2)) return true;
			}
		}
		catch (Exception^) {
			throw;
			return false;
		}
		return true;
	}
	//returns the array list that stores the categories loaded from the database.
	ArrayList^ retrieveCategories() {
		//temp array to store the categories coming back from the db
		ArrayList^ categories = gcnew ArrayList;

		//Database Connection
		MySqlConnection^ conDataBase = connectToDB();
		//SQL Command
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("Select * FROM categories", conDataBase);
		MySqlDataReader^ reader;
		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();//Executes SQL Statement
			while (reader->Read()) {
				categories->Add(reader->GetString(1));
			}
		}
		catch (Exception^) {
			throw;
		}
		return categories;
	}

};
