#pragma once
#include "Security.h"
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace MySql::Data;
using namespace System::Windows::Forms;
using namespace System::Collections;

public ref class DB {
private:
	//Database Connection String
	String^ constring = L"server=108.163.238.185;user id=sdosburn_Group1;password=uat1234; database=sdosburn_inventoryfood;persistsecurityinfo=True";
	
	ArrayList^ categories = gcnew ArrayList;	//categories array
	UTF8Encoding^ utf8 = gcnew UTF8Encoding;	//security encoding
	Service^ security = gcnew Service;			//security class variable

	//Database Connection
	MySqlConnection^ connectToDB() {
		MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
		return conDataBase;
	}
	void retrieveCategories() {
		//temp array to store the categories coming back from the db
		ArrayList^ DBcategories = gcnew ArrayList;

		//Database Connection
		MySqlConnection^ conDataBase = connectToDB();
		//SQL Command
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("Select * FROM categories", conDataBase);
		MySqlDataReader^ reader;
		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();//Executes SQL Statement
			while (reader->Read()) {
				String^ categoryName = reader->GetString(1);
				DBcategories->Add(categoryName);
			}
			categories = DBcategories;
		}
		catch (Exception^) {
			throw;
		}
	}
public:
	//standard function that adds a product to the database without a sale price
	bool addProductToDB(String^ Name, int category, String^ UPC, String^ quantity) {
		//Database Connection
		MySqlConnection^ conDataBase = connectToDB();

		//converting text representation of quantity to int for database insertion
		int quant = Convert::ToInt32(quantity);

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO products (id,Product_Name, Product_Category,Quantity, UPC) VALUES (NULL,'" + Name + "', '" + category + "', '" + quant + "','" + UPC + "')", conDataBase);

		try {
			conDataBase->Open();
			cmdDataBase->ExecuteReader(); //executes sql command
		}
		catch (Exception^) {
			throw;
			return false;
		}
		return true;
	}
	bool addProductToDB(String^ Name, int category, String^ UPC, String^ quantity, String^ Price) {
		MySqlConnection^ conDataBase = connectToDB();//Database Connection

		//SQL Statement
		MySqlCommand^ SQL = gcnew MySqlCommand("INSERT INTO products (id, Product_Name, Product_Category, Quantity, Price, UPC) VALUES (NULL,'" + Name + "', '" + category + "', '" + quantity + "','" + Price + "','" + UPC + "')", conDataBase);
		try {
			conDataBase->Open();
			SQL->ExecuteReader();//Executes SQL Statement
		}
		catch (Exception^)
		{
			throw;//throws exception back to calling function
			return false;
		}
		return true;//if no errors ocurred that means product was successfully added and return true.
	}
	bool logUserIn(String^ username, String^ password) {
		MySqlConnection^ conDataBase = connectToDB();
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("Select * FROM user_login WHERE username='" + username + "'", conDataBase);
		MySqlDataReader^ reader;

		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();

			while (reader->Read()) {
				//password retrieved from the database
				String^ encPassword = reader->GetString(2);
				//password provided by the user
				String^ userPass = toString(security->EncryptText(utf8, password));
				//compare returned string to password provided by user
				if (userPass == encPassword) return true;
				else return false;
			}
		}
		catch (Exception^) {
			throw;
		}
		return false;
	}
	ArrayList^ getCategories() {
		//if this is the first time the categories are requested, retrieve categories and return the categories Array
		if (categories->Count == 0) {
			retrieveCategories();
			return categories;
		}
		//otherwise just return the categories Array
		else return categories;
	}
	//returns the array list that stores the categories loaded from the database.
	//deletes product from database by Name
	bool deleteProduct(String^ name) {
		MySqlConnection^ conDataBase = connectToDB();
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("DELETE FROM products WHERE Product_Name='" + name + "'", conDataBase);
		MySqlDataReader^ reader;

		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();
			if (reader->RecordsAffected == 1)
				return true;
			else return false;
		}
		catch (Exception^) {
			throw;
			return false;
		}
	}
	bool createNewUser(String^ username, String^ password) {
		MySqlConnection^ conDataBase = connectToDB();
		
		//array<Byte>^ test = security->EncryptText(utf8, password);
		String^ encPassword = toString(security->EncryptText(utf8, password));
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO user_login (id, username, password) VALUES (NULL, '" + username + "', '" + encPassword + "')" , conDataBase);
		MySqlDataReader^ reader;

		try {
			conDataBase->Open();
			reader = cmdDataBase->ExecuteReader();
			if (reader->RecordsAffected == 1) return true;
			else return false;
		}
		catch (Exception^) {
			throw;
		}
	}
	private:
		//converts the password byte array to a string for either db insertion or user login
		String^ toString(array<Byte>^ arr) {
			//String^ teest1 = gcnew String(byte);
			String^ test;
			for (int i = 0; i < arr->Length; i++) {
				test += arr[i] + " ";
			}
			return test;
		}
};
