#pragma once
#include "DB.h"
#include "Category.h"
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddProduct
	/// </summary>
	public ref class AddProduct : public System::Windows::Forms::Form
	{
	public:
		AddProduct(void)
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
		~AddProduct()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tb_name;
	private: System::Windows::Forms::TextBox^  tb_UPC;


	private: System::Windows::Forms::TextBox^  tb_quantity;

	private: System::Windows::Forms::TextBox^  tb_price;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  cmb_categories;
	private: System::Windows::Forms::Label^  label6;
			 ArrayList^ categories = gcnew ArrayList;
			 DB^ db = gcnew DB;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddProduct::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tb_name = (gcnew System::Windows::Forms::TextBox());
			this->tb_UPC = (gcnew System::Windows::Forms::TextBox());
			this->tb_quantity = (gcnew System::Windows::Forms::TextBox());
			this->tb_price = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->cmb_categories = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(105, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Add New Product";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(95, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Product Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(104, 165);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Product UPC:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(85, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Product Quantity:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(53, 116);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Product Price (optional):";
			// 
			// tb_name
			// 
			this->tb_name->Location = System::Drawing::Point(179, 63);
			this->tb_name->Name = L"tb_name";
			this->tb_name->Size = System::Drawing::Size(120, 20);
			this->tb_name->TabIndex = 5;
			// 
			// tb_UPC
			// 
			this->tb_UPC->Location = System::Drawing::Point(179, 164);
			this->tb_UPC->Name = L"tb_UPC";
			this->tb_UPC->ReadOnly = true;
			this->tb_UPC->Size = System::Drawing::Size(122, 20);
			this->tb_UPC->TabIndex = 6;
			// 
			// tb_quantity
			// 
			this->tb_quantity->Location = System::Drawing::Point(180, 139);
			this->tb_quantity->Name = L"tb_quantity";
			this->tb_quantity->Size = System::Drawing::Size(120, 20);
			this->tb_quantity->TabIndex = 7;
			// 
			// tb_price
			// 
			this->tb_price->Location = System::Drawing::Point(179, 112);
			this->tb_price->Name = L"tb_price";
			this->tb_price->Size = System::Drawing::Size(120, 20);
			this->tb_price->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Add Product";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddProduct::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(221, 190);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(78, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Reset Fields:";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(307, 165);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Scan Barcode";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AddProduct::button3_Click);
			// 
			// cmb_categories
			// 
			this->cmb_categories->FormattingEnabled = true;
			this->cmb_categories->Location = System::Drawing::Point(179, 86);
			this->cmb_categories->Name = L"cmb_categories";
			this->cmb_categories->Size = System::Drawing::Size(120, 21);
			this->cmb_categories->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(82, 92);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(92, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Product Category:";
			// 
			// AddProduct
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(425, 265);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->cmb_categories);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tb_price);
			this->Controls->Add(this->tb_quantity);
			this->Controls->Add(this->tb_UPC);
			this->Controls->Add(this->tb_name);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddProduct";
			this->Text = L"AddProduct";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			bool TestString(String^ str) {
				//if the string is empty or contains nothing but whitespace will return true
				if (String::IsNullOrWhiteSpace(str)) return true;
				else return false;
			}
	private: 
		void addCategories() {
			cmb_categories->Items->Clear();
			categories = db->getCategories();
			for (int i = 0; i < categories->Count; i++) {
				cmb_categories->Items->Add(categories[i]);
			}
		}
		void clearAddProductFields() {
			tb_UPC->Text = "";
			tb_name->Text = "";
			tb_price->Text = "";
			tb_quantity->Text = "";
		}
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
String^ Name = tb_name->Text;
			String^ productUPC = tb_UPC->Text;
			String^ productPrice = tb_price->Text;
			String^ productQuantity = tb_quantity->Text;
			String^ productCategory = cmb_categories->Text;


			//simple validation of input fields
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
					//determing the integer representation of category
					for (int i = 0; i < categories->Count; i++) {
						//when category matches set cat to the index of category
						if (Convert::ToString(categories[i]) == Convert::ToString(productCategory)) {
							cat = i + 1;
						}
					}
					//calls add product function which adds the product to the database
					bool result, priceSuccess;
					//if the price field is not empty
					if (!TestString(productPrice)) {
						try {
							Decimal^ Price = Convert::ToDecimal(productPrice);
							result = db->addProductToDB(Name, cat, productUPC, productQuantity, productPrice);
						}
						catch (FormatException^ ex) {
							throw;
						}
					}
					else {
						result = db->addProductToDB(Name, cat, productUPC, productQuantity);
					}
					if (result) {
						MessageBox::Show("Product Successfully Added");
						clearAddProductFields();
					}
					else {
						MessageBox::Show("Problem Adding Product To Inventory");
					}
				}
				catch (Exception^ ex) {
					MessageBox::Show(ex->Message);
				}
		}
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	tb_UPC->Text = "53917538396714";
}
};
}
