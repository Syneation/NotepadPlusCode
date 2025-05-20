#pragma once

#include "HelperReplace.h"

namespace NotepadCPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		RichTextBox^ richTextBoxToSearch;
		int lastFoundPosition;
		int currentMatchIndex;
		List<int>^ foundPositions;
		System::Windows::Forms::Label^ notifications;
		String^ currentSearchText;
		Color originalBackColor;

	public:
		MyForm2(RichTextBox^ rtb) : richTextBoxToSearch(rtb)
		{

			if (rtb == nullptr || rtb->IsDisposed)
				throw gcnew ArgumentNullException("RichTextBox must be valid and not disposed");

			InitializeComponent();

			lastFoundPosition = 0;
			currentMatchIndex = -1;
			foundPositions = gcnew List<int>();
			currentSearchText = nullptr;
			originalBackColor = richTextBoxToSearch->BackColor;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;


	private: System::Windows::Forms::CheckBox^ checkBoxCase;
	private: System::Windows::Forms::CheckBox^ checkBoxWrapping;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkBoxCase = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxWrapping = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(2, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"What:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(2, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Than:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 60);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(174, 20);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(75, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(171, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(262, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Find Next...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(262, 52);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Replace";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(262, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(96, 27);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Replace All";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm2::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(262, 114);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(96, 29);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Cancel";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm2::button4_Click);
			// 
			// checkBoxCase
			// 
			this->checkBoxCase->AutoSize = true;
			this->checkBoxCase->Location = System::Drawing::Point(12, 98);
			this->checkBoxCase->Name = L"checkBoxCase";
			this->checkBoxCase->Size = System::Drawing::Size(94, 17);
			this->checkBoxCase->TabIndex = 10;
			this->checkBoxCase->Text = L"Case-sensitive";
			this->checkBoxCase->UseVisualStyleBackColor = true;
			// 
			// checkBoxWrapping
			// 
			this->checkBoxWrapping->AutoSize = true;
			this->checkBoxWrapping->Location = System::Drawing::Point(12, 121);
			this->checkBoxWrapping->Name = L"checkBoxWrapping";
			this->checkBoxWrapping->Size = System::Drawing::Size(93, 17);
			this->checkBoxWrapping->TabIndex = 11;
			this->checkBoxWrapping->Text = L"Text wrapping";
			this->checkBoxWrapping->UseVisualStyleBackColor = true;
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(393, 155);
			this->Controls->Add(this->checkBoxWrapping);
			this->Controls->Add(this->checkBoxCase);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximumSize = System::Drawing::Size(409, 194);
			this->MinimumSize = System::Drawing::Size(409, 194);
			this->Name = L"MyForm2";
			this->Text = L"Replace";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm2::MyForm2_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: void ResetTextHighlighting()
	{
		richTextBoxToSearch->SelectAll();
		richTextBoxToSearch->SelectionBackColor = originalBackColor;
		richTextBoxToSearch->DeselectAll();
	}
	//exit
	private: System::Void MyForm2_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		ResetTextHighlighting();
	}


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	//findnext
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		
		HelperReplace helperReplace;

		String^ searchText = textBox2->Text;

		if (richTextBoxToSearch == nullptr || richTextBoxToSearch->IsDisposed)
		{
			MessageBox::Show("RichTextBox is not available", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (String::IsNullOrEmpty(searchText))
			return;

		helperReplace.findNext(searchText, checkBoxCase->Checked, true, richTextBoxToSearch,
			notifications, checkBoxWrapping, lastFoundPosition);
	}

	//Replace button
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HelperReplace helperReplace;

		String^ searchText = textBox2->Text;
		String^ replaceText = textBox1->Text;

		if (String::IsNullOrEmpty(searchText))
			return;

		// If there's a selection and it matches the search text, replace it
		if (richTextBoxToSearch->SelectedText->Equals(searchText,
			checkBoxCase->Checked ? StringComparison::CurrentCulture : StringComparison::CurrentCultureIgnoreCase))
		{
			richTextBoxToSearch->SelectedText = replaceText;
		}

		helperReplace.findNext(searchText, checkBoxCase->Checked, true, richTextBoxToSearch, notifications,
			checkBoxWrapping, lastFoundPosition);
	}

	//Replace All btn
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HelperReplace helperReplace;

		String^ searchText = textBox2->Text;
		String^ replaceText = textBox1->Text;

		helperReplace.ReplaceAll(searchText, replaceText, checkBoxCase->Checked, richTextBoxToSearch, notifications);
	}

	//btn cancel
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HelperReplace helperReplace;

		helperReplace.ResetTextHighlighting(richTextBoxToSearch, originalBackColor);
		this->Close();
	}
	//input
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		currentSearchText = nullptr;
		lastFoundPosition = 0; //Reset search position when search text changes
	}

	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->ActiveControl = textBox2; //Set focus to search textBox when form loads
	}
	
};
}
