#pragma once
#include "Category.h"
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
		}
		return true;
	}
	//returns the array list that stores the categories loaded from the database.
	ArrayList^ retrieveCategories() {
		//temp array to store the categories coming back from the db
		ArrayList^ categories = gcnew ArrayList;
		// array<Category^>^ categories;
		//List<Category^> categories;
		//Database Connection
		MySqlConnection^ conDataBase = connectToDB();
		//SQL Command
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("Select * FROM categories", conDataBase);
		MySqlDataReader^ reader;
		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();//Executes SQL Statement
			while (reader->Read()) {
				Category^ category = gcnew Category(reader->GetString(1), reader->GetInt32(0));
				categories->Add(category);
			}
		}
		catch (Exception^) {
			throw;
		}
		return categories;//returns the arraylist containing the categories
	}
	bool deleteProduct(String^ name) {
		MySqlConnection^ conDataBase = connectToDB();
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM products WHERE Product_Name='" + name + "'", conDataBase);
		MySqlDataReader^ reader;

		try {
			conDataBase->Open();
			cmdDataBase->ExecuteReader();
			return true;//if product was successfully removed return true notify success of removal
		}
		catch (Exception^) {
			throw;
		}
		return false;
	}

};
