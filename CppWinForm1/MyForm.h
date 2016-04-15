#pragma once
#include <string>
#include <array>
#include <map>

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace MySql::Data;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			addCategories();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_ok;
	private: System::Windows::Forms::TextBox^  tb_Message;
	private: System::Windows::Forms::TextBox^  tb_username;
	private: System::Windows::Forms::TextBox^  tb_password;
	private: System::Windows::Forms::Button^  btn_login;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tb_name;
	private: System::Windows::Forms::TextBox^  tb_upc;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tb_price;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tb_quantity;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btn_addProduct;
	private: System::Windows::Forms::Button^  btn_clearFields;
	private: System::Windows::Forms::ComboBox^  cmb_category;
	private: System::Windows::Forms::Label^  label5;

	private: ArrayList^ categories = gcnew ArrayList;



	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_ok = (gcnew System::Windows::Forms::Button());
			this->tb_Message = (gcnew System::Windows::Forms::TextBox());
			this->tb_username = (gcnew System::Windows::Forms::TextBox());
			this->tb_password = (gcnew System::Windows::Forms::TextBox());
			this->btn_login = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_name = (gcnew System::Windows::Forms::TextBox());
			this->tb_upc = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_price = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_quantity = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btn_addProduct = (gcnew System::Windows::Forms::Button());
			this->btn_clearFields = (gcnew System::Windows::Forms::Button());
			this->cmb_category = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_ok
			// 
			this->btn_ok->Location = System::Drawing::Point(387, 187);
			this->btn_ok->Name = L"btn_ok";
			this->btn_ok->Size = System::Drawing::Size(167, 23);
			this->btn_ok->TabIndex = 0;
			this->btn_ok->Text = L"Ok";
			this->btn_ok->UseVisualStyleBackColor = true;
			this->btn_ok->Click += gcnew System::EventHandler(this, &MyForm::btn_ok_Click);
			// 
			// tb_Message
			// 
			this->tb_Message->Location = System::Drawing::Point(327, 12);
			this->tb_Message->Multiline = true;
			this->tb_Message->Name = L"tb_Message";
			this->tb_Message->Size = System::Drawing::Size(264, 169);
			this->tb_Message->TabIndex = 1;
			// 
			// tb_username
			// 
			this->tb_username->Location = System::Drawing::Point(12, 13);
			this->tb_username->Name = L"tb_username";
			this->tb_username->Size = System::Drawing::Size(118, 20);
			this->tb_username->TabIndex = 2;
			// 
			// tb_password
			// 
			this->tb_password->Location = System::Drawing::Point(12, 39);
			this->tb_password->Name = L"tb_password";
			this->tb_password->Size = System::Drawing::Size(118, 20);
			this->tb_password->TabIndex = 3;
			// 
			// btn_login
			// 
			this->btn_login->Location = System::Drawing::Point(39, 66);
			this->btn_login->Name = L"btn_login";
			this->btn_login->Size = System::Drawing::Size(75, 23);
			this->btn_login->TabIndex = 4;
			this->btn_login->Text = L"Log In";
			this->btn_login->UseVisualStyleBackColor = true;
			this->btn_login->Click += gcnew System::EventHandler(this, &MyForm::btn_login_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 283);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Product Name";
			// 
			// tb_name
			// 
			this->tb_name->Location = System::Drawing::Point(93, 280);
			this->tb_name->Name = L"tb_name";
			this->tb_name->Size = System::Drawing::Size(121, 20);
			this->tb_name->TabIndex = 6;
			// 
			// tb_upc
			// 
			this->tb_upc->BackColor = System::Drawing::Color::White;
			this->tb_upc->Enabled = false;
			this->tb_upc->Location = System::Drawing::Point(93, 329);
			this->tb_upc->Name = L"tb_upc";
			this->tb_upc->Size = System::Drawing::Size(121, 20);
			this->tb_upc->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 332);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"UPC:";
			// 
			// tb_price
			// 
			this->tb_price->Location = System::Drawing::Point(93, 355);
			this->tb_price->Name = L"tb_price";
			this->tb_price->Size = System::Drawing::Size(121, 20);
			this->tb_price->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 358);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Price (optional)";
			// 
			// tb_quantity
			// 
			this->tb_quantity->Location = System::Drawing::Point(93, 381);
			this->tb_quantity->Name = L"tb_quantity";
			this->tb_quantity->Size = System::Drawing::Size(121, 20);
			this->tb_quantity->TabIndex = 12;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 384);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Quantity";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(217, 327);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 23);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Scan Barcode";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btn_addProduct
			// 
			this->btn_addProduct->Location = System::Drawing::Point(55, 407);
			this->btn_addProduct->Name = L"btn_addProduct";
			this->btn_addProduct->Size = System::Drawing::Size(75, 23);
			this->btn_addProduct->TabIndex = 14;
			this->btn_addProduct->Text = L"Add Product";
			this->btn_addProduct->UseVisualStyleBackColor = true;
			this->btn_addProduct->Click += gcnew System::EventHandler(this, &MyForm::btn_addProduct_Click);
			// 
			// btn_clearFields
			// 
			this->btn_clearFields->Location = System::Drawing::Point(136, 407);
			this->btn_clearFields->Name = L"btn_clearFields";
			this->btn_clearFields->Size = System::Drawing::Size(75, 23);
			this->btn_clearFields->TabIndex = 15;
			this->btn_clearFields->Text = L"Clear Fields";
			this->btn_clearFields->UseVisualStyleBackColor = true;
			this->btn_clearFields->Click += gcnew System::EventHandler(this, &MyForm::btn_clearFields_Click);
			// 
			// cmb_category
			// 
			this->cmb_category->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_category->FormattingEnabled = true;
			this->cmb_category->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Test1", L"Test2", L"Test3", L"Test4" });
			this->cmb_category->Location = System::Drawing::Point(93, 304);
			this->cmb_category->Name = L"cmb_category";
			this->cmb_category->Size = System::Drawing::Size(121, 21);
			this->cmb_category->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(39, 307);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Category";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 593);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->cmb_category);
			this->Controls->Add(this->btn_clearFields);
			this->Controls->Add(this->btn_addProduct);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tb_quantity);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tb_price);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tb_upc);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb_name);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_login);
			this->Controls->Add(this->tb_password);
			this->Controls->Add(this->tb_username);
			this->Controls->Add(this->tb_Message);
			this->Controls->Add(this->btn_ok);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

			map<string, int> categories;

		}
#pragma endregion
private: 
	void clearAddProductFields() {
	tb_upc->Text = "";
	tb_name->Text = "";
	tb_price->Text = "";
	tb_upc->Text = "";
	tb_quantity->Text = "";
	}
	bool TestString(String^ str) {
		if (String::IsNullOrWhiteSpace(str)) return true;
		else return false;
	}

private: MySqlConnection^ connectToDB() {
	String^ constring = L"server=108.163.238.185;user id=sdosburn_Group1;password=uat1234; database=sdosburn_inventoryfood;persistsecurityinfo=True";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	return conDataBase;
}
private: 
	System::Void btn_ok_Click(System::Object^  sender, System::EventArgs^  e) {
		
	String^ constring = L"server=108.163.238.185;user id=sdosburn_Group1;password=uat1234; database=sdosburn_inventoryfood;persistsecurityinfo=True";
	MySqlConnection^ conDataBase = gcnew MySqlConnection(constring);
	MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM products", conDataBase);
	MySqlDataReader^ myReader;
	try {
		conDataBase->Open();
		myReader = cmdDataBase->ExecuteReader(); //Add the SQL Query
		while(myReader->Read()){
			tb_Message->Text += "\r\n";
			tb_Message->Text += ("ID: " + myReader->GetInt32(0) + "\r\n");
			tb_Message->Text += "Product Name: " + myReader->GetString(1) + "\r\n";
		}
	}
	catch (Exception^ex)
	{
		MessageBox::Show(ex->Message);
	}


}
	System::Void btn_login_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ username = tb_username->Text;
		String^ password = tb_password->Text;
		MySqlConnection^ conDataBase = connectToDB();
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM user_login WHERE username=username", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader(); //Add the SQL Query
			bool isLoggedIn = false;
			
			while (myReader->Read()) {
				if (password == myReader->GetString(2)) {
					tb_Message->Text = "You have been successfully logged in.";
					isLoggedIn = true;
				}
			}
			if (!isLoggedIn) tb_Message->Text = "Incorrect Password";

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}
	System::Void btn_clearFields_Click(System::Object^  sender, System::EventArgs^  e) {
		clearAddProductFields();
	}

	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		tb_upc->Text = "62398163986365";
	}

public:
	bool addProductToDB(String^ Name, int category, String^ UPC, String^ Price, String^ quantity) {
		MySqlConnection^ conDataBase = connectToDB();
		//int quant = System::Convert::ToInt32(quantity);
		int quant = 100;

		//MessageBox::Show(Name);
		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("INSERT INTO products (id,Product_Name, Product_Category,Quantity, UPC) VALUES (NULL,'"+Name+"', '"+category+"', '"+quant+"','"+UPC+"')", conDataBase);
		MySqlDataReader^ myReader;

		try {
			conDataBase->Open();
			myReader = cmdDataBase->ExecuteReader(); //executes sql command
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Database Error", MessageBoxButtons::OK);
			return false;
		}
		return true;
	}
private: System::Void btn_addProduct_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ Name = tb_name->Text;
	String^ productUPC = tb_upc->Text;
	String^ productPrice = tb_price->Text;
	String^ productQuantity = tb_quantity->Text;
	String^ productCategory = cmb_category->Text;

	if (TestString(Name)) {
		MessageBox::Show("Name field is Required but was left empty");
	}
	else if (TestString(productUPC)) {
		MessageBox::Show("UPC field is Required but was left empty");
	}
	else if (TestString(productCategory)) {
		MessageBox::Show("Product Category was not selected");
	}
	else {
		int cat;
		try {
			for (int i = 0; i < categories->Count; i++) {
				if (Convert::ToString(categories[i]) == Convert::ToString(productCategory)) {
					cat = i;
				}
			}
			
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
		bool result = addProductToDB(Name, cat+1, productUPC, productPrice, productQuantity);
		if (result) {
			tb_Message->Text = "Product Successfully Added";
			clearAddProductFields();
		}
		else tb_Message->Text = "Problem Adding Product To Inventory";
	}

}
private: 
	void addCategories() {
		MySqlConnection^ DB = connectToDB();//Database Connection

		MySqlCommand^ cmdDataBase = gcnew MySqlCommand("SELECT * FROM categories", DB);
		MySqlDataReader^ myReader;

		try {
			DB->Open();
			myReader = cmdDataBase->ExecuteReader(); //executes sql command
			tb_Message->Text = "";
			cmb_category->Items->Clear();
			while (myReader->Read())
			{
				cmb_category->Items->Add(myReader->GetString(1));
				categories->Add(myReader->GetString(1));
				categories->TrimToSize();
			}
			for (int i = 0; i < categories->Count; i++) {
				tb_Message->Text += Convert::ToString(i) + categories[i];
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}

	}
};
}
