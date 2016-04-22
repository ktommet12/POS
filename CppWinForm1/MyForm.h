#pragma once
#include <string>
#include "DB.h"
#include "AddProduct.h"
#include "Security.h"

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace MySql::Data;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::TextBox^  tb_deleteName;
	private: System::Windows::Forms::Button^  cmd_delete;

	
	//Non Auto Generated Variables
	private:
			 ArrayList^ categories = gcnew ArrayList;
			 DB^ db = gcnew DB;
	private: System::Windows::Forms::TextBox^  tb_newUsername;
	private: System::Windows::Forms::TextBox^  tb_newPassword;



	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
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
			this->tb_deleteName = (gcnew System::Windows::Forms::TextBox());
			this->cmd_delete = (gcnew System::Windows::Forms::Button());
			this->tb_newUsername = (gcnew System::Windows::Forms::TextBox());
			this->tb_newPassword = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
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
			this->btn_login->Location = System::Drawing::Point(30, 65);
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
			this->btn_addProduct->Location = System::Drawing::Point(105, 180);
			this->btn_addProduct->Name = L"btn_addProduct";
			this->btn_addProduct->Size = System::Drawing::Size(109, 23);
			this->btn_addProduct->TabIndex = 14;
			this->btn_addProduct->Text = L"Add New Product";
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
			// tb_deleteName
			// 
			this->tb_deleteName->Location = System::Drawing::Point(435, 203);
			this->tb_deleteName->Name = L"tb_deleteName";
			this->tb_deleteName->Size = System::Drawing::Size(121, 20);
			this->tb_deleteName->TabIndex = 18;
			// 
			// cmd_delete
			// 
			this->cmd_delete->Location = System::Drawing::Point(422, 229);
			this->cmd_delete->Name = L"cmd_delete";
			this->cmd_delete->Size = System::Drawing::Size(134, 23);
			this->cmd_delete->TabIndex = 19;
			this->cmd_delete->Text = L"Delete Product";
			this->cmd_delete->UseVisualStyleBackColor = true;
			this->cmd_delete->Click += gcnew System::EventHandler(this, &MyForm::cmd_delete_Click);
			// 
			// tb_newUsername
			// 
			this->tb_newUsername->Location = System::Drawing::Point(470, 514);
			this->tb_newUsername->Name = L"tb_newUsername";
			this->tb_newUsername->Size = System::Drawing::Size(121, 20);
			this->tb_newUsername->TabIndex = 20;
			// 
			// tb_newPassword
			// 
			this->tb_newPassword->Location = System::Drawing::Point(470, 540);
			this->tb_newPassword->Name = L"tb_newPassword";
			this->tb_newPassword->Size = System::Drawing::Size(121, 20);
			this->tb_newPassword->TabIndex = 21;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(457, 566);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 23);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Create New User";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(389, 517);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Username:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(389, 542);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(56, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Password:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 593);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->tb_newPassword);
			this->Controls->Add(this->tb_newUsername);
			this->Controls->Add(this->cmd_delete);
			this->Controls->Add(this->tb_deleteName);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"POS";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	bool TestString(String^ str) {
		//if the string is empty or contains nothing but whitespace will return true
		if (String::IsNullOrWhiteSpace(str)) return true;
		else return false;
	}

private:
	System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		tb_upc->Text = "62398163986365";//temp barcode used for testing 
	}

private: System::Void btn_addProduct_Click(System::Object^  sender, System::EventArgs^  e) {
	AddProduct^ add = gcnew AddProduct;
	add->ShowDialog();
}
private: 
	System::Void btn_login_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ username = tb_username->Text;
		String^ password = tb_password->Text;
		bool result = db->logUserIn(username, password);
		if (result) {
			MessageBox::Show("You have been successfully logged in");
			tb_username->Text = "";
			tb_password->Text = "";
		}
		else MessageBox::Show("Incorrect Username/Password");
}
private: System::Void cmd_delete_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ name = tb_deleteName->Text;
	try {
		bool result = db->deleteProduct(name);
		if (result) {
			MessageBox::Show("Product Removed Successfully");
		}
		else
			MessageBox::Show("Item not found in Database");

	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ username = tb_newUsername->Text;
	String^ password = tb_newPassword->Text;
	if (TestString(username) || TestString(password)) {
		MessageBox::Show("Username/Password was required but not provided");
	}
	else {
		db->createNewUser(username, password);
	}

}
};
}