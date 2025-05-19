#pragma once

namespace NotepadCPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private:
		RichTextBox^ richTextBoxToSearch;
		int lastFoundPosition;
		int currentMatchIndex;
		List<int>^ foundPositions;
		String^ currentSearchText;
		Color originalBackColor;

	public:
		MyForm1(RichTextBox^ richTextBox)
		{
			InitializeComponent();
			richTextBoxToSearch = richTextBox;
			lastFoundPosition = 0;
			currentMatchIndex = -1;
			foundPositions = gcnew List<int>();
			radioButtonDown->Checked = true;
			originalBackColor = richTextBoxToSearch->BackColor;
		}

	protected:
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Button^ find_next;
		System::Windows::Forms::Button^ cancel;
		System::Windows::Forms::RadioButton^ radioButtonTop;
		System::Windows::Forms::CheckBox^ checkBoxCase_Sens;
		System::Windows::Forms::CheckBox^ checkBoxTextWrapping;
		System::Windows::Forms::RadioButton^ radioButtonDown;
		System::Windows::Forms::Label^ label2;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->find_next = (gcnew System::Windows::Forms::Button());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->radioButtonTop = (gcnew System::Windows::Forms::RadioButton());
			this->checkBoxCase_Sens = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxTextWrapping = (gcnew System::Windows::Forms::CheckBox());
			this->radioButtonDown = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"What:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(74, 14);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(177, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// find_next
			// 
			this->find_next->Location = System::Drawing::Point(257, 12);
			this->find_next->Name = L"find_next";
			this->find_next->Size = System::Drawing::Size(75, 23);
			this->find_next->TabIndex = 2;
			this->find_next->Text = L"Find next";
			this->find_next->UseVisualStyleBackColor = true;
			this->find_next->Click += gcnew System::EventHandler(this, &MyForm1::find_next_Click);
			// 
			// cancel
			// 
			this->cancel->Location = System::Drawing::Point(257, 45);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(75, 23);
			this->cancel->TabIndex = 3;
			this->cancel->Text = L"Cancel";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &MyForm1::cancel_Click);
			// 
			// radioButtonTop
			// 
			this->radioButtonTop->AutoSize = true;
			this->radioButtonTop->Location = System::Drawing::Point(139, 74);
			this->radioButtonTop->Name = L"radioButtonTop";
			this->radioButtonTop->Size = System::Drawing::Size(44, 17);
			this->radioButtonTop->TabIndex = 4;
			this->radioButtonTop->TabStop = true;
			this->radioButtonTop->Text = L"Top";
			this->radioButtonTop->UseVisualStyleBackColor = true;
			this->radioButtonTop->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::radioButton1_CheckedChanged);
			// 
			// checkBoxCase_Sens
			// 
			this->checkBoxCase_Sens->AutoSize = true;
			this->checkBoxCase_Sens->Location = System::Drawing::Point(12, 51);
			this->checkBoxCase_Sens->Name = L"checkBoxCase_Sens";
			this->checkBoxCase_Sens->Size = System::Drawing::Size(94, 17);
			this->checkBoxCase_Sens->TabIndex = 5;
			this->checkBoxCase_Sens->Text = L"Case-sensitive";
			this->checkBoxCase_Sens->UseVisualStyleBackColor = true;
			this->checkBoxCase_Sens->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBoxCase_Sens_CheckedChanged);
			// 
			// checkBoxTextWrapping
			// 
			this->checkBoxTextWrapping->AutoSize = true;
			this->checkBoxTextWrapping->Location = System::Drawing::Point(12, 74);
			this->checkBoxTextWrapping->Name = L"checkBoxTextWrapping";
			this->checkBoxTextWrapping->Size = System::Drawing::Size(93, 17);
			this->checkBoxTextWrapping->TabIndex = 6;
			this->checkBoxTextWrapping->Text = L"Text wrapping";
			this->checkBoxTextWrapping->UseVisualStyleBackColor = true;
			this->checkBoxTextWrapping->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBoxTextWrapping_CheckedChanged);
			// 
			// radioButtonDown
			// 
			this->radioButtonDown->AutoSize = true;
			this->radioButtonDown->Location = System::Drawing::Point(195, 74);
			this->radioButtonDown->Name = L"radioButtonDown";
			this->radioButtonDown->Size = System::Drawing::Size(53, 17);
			this->radioButtonDown->TabIndex = 7;
			this->radioButtonDown->TabStop = true;
			this->radioButtonDown->Text = L"Down";
			this->radioButtonDown->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(164, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Direction";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(341, 121);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButtonDown);
			this->Controls->Add(this->checkBoxTextWrapping);
			this->Controls->Add(this->checkBoxCase_Sens);
			this->Controls->Add(this->radioButtonTop);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->find_next);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(360, 160);
			this->MinimumSize = System::Drawing::Size(341, 159);
			this->Name = L"MyForm1";
			this->Text = L"Find";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm1::MyForm1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {}
		System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {}
		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}

	//exit
	private: System::Void MyForm1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		ResetTextHighlighting();
	}

		// Search for text with backlight
	private: System::Void find_next_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ searchText = textBox1->Text;
		if (String::IsNullOrEmpty(searchText))
		{
			MessageBox::Show("Please enter search text", "Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// If the search text has changed, we search for all matches again.
		if (currentSearchText != searchText)
		{
			FindAllMatches(searchText);
			currentSearchText = searchText;
			currentMatchIndex = -1;
		}

		if (foundPositions->Count == 0)
		{
			MessageBox::Show("Text not found", "Information",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// Navigating through found matches
		if (radioButtonDown->Checked)
		{
			currentMatchIndex = (currentMatchIndex + 1) % foundPositions->Count;
		}
		else
		{
			currentMatchIndex = (currentMatchIndex - 1 + foundPositions->Count) % foundPositions->Count;
		}

		HighlightCurrentMatch(searchText);
	}

		   //Search for all matches
	private: void FindAllMatches(String^ searchText)
	{
		foundPositions->Clear();
		richTextBoxToSearch->SelectAll();
		richTextBoxToSearch->SelectionBackColor = originalBackColor;

		RichTextBoxFinds options = checkBoxCase_Sens->Checked ?
			RichTextBoxFinds::MatchCase : RichTextBoxFinds::None;

		int startPos = 0;
		int textLength = richTextBoxToSearch->TextLength;
		int searchLength = searchText->Length;

		while (startPos < textLength)
		{
			int foundPos = richTextBoxToSearch->Find(searchText, startPos, textLength, options);
			if (foundPos == -1) break;

			foundPositions->Add(foundPos);
			startPos = foundPos + searchLength;
		}
	}

		   // Highlighting the current match
	private: void HighlightCurrentMatch(String^ searchText)
	{
		if (currentMatchIndex >= 0 && currentMatchIndex < foundPositions->Count)
		{
			int pos = foundPositions[currentMatchIndex];
			richTextBoxToSearch->Select(pos, searchText->Length);
			richTextBoxToSearch->SelectionBackColor = Color::Yellow;
			richTextBoxToSearch->ScrollToCaret();
		}
	}

		   // Closing the form
	private: System::Void cancel_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Restoring the original color before closing
		ResetTextHighlighting();
		this->Close();
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// Resetting the search when the text changes
		currentSearchText = nullptr;
	}

		   //Method for resetting the backlight
	private: void ResetTextHighlighting()
	{
		richTextBoxToSearch->SelectAll();
		richTextBoxToSearch->SelectionBackColor = originalBackColor;
		richTextBoxToSearch->DeselectAll();
	}


	private: System::Void checkBoxCase_Sens_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (currentSearchText != nullptr)
		{
			FindAllMatches(currentSearchText);
			if (foundPositions->Count > 0 && currentMatchIndex >= 0)
				HighlightCurrentMatch(currentSearchText);
			else
				ResetTextHighlighting();
		}
	}
	private: System::Void checkBoxTextWrapping_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		//on the top
	}
};
}