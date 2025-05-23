#pragma once

#include <iostream>
#include <ctime>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class helperRich
{
	
	public: void getDateTimeForRichTextBox(RichTextBox^ richTextBox)
	{
		time_t seconds = time(NULL);
		tm timeinfo;
		localtime_s(&timeinfo, &seconds);
	
		char buffer[26];
		asctime_s(buffer, sizeof(buffer), &timeinfo);
		richTextBox->AppendText(gcnew String(buffer));
	}

	 //functions
	//change font from quick panel
	public: void ToggleFontStyle(FontStyle style, System::Windows::Forms::RichTextBox^ richTextBox1, Label^ notifications)
	{
		// checking if there is a selected text.
		if (richTextBox1->SelectionLength > 0)
		{
			// Getting the current font of the selected text
			System::Drawing::Font^ currentFont = richTextBox1->SelectionFont;
	
			if (currentFont != nullptr)
			{
				// Switching the specified style (XOR)
				FontStyle newStyle = currentFont->Style ^ style;
	
				// Applying a new font
				richTextBox1->SelectionFont = gcnew System::Drawing::Font(
					currentFont->FontFamily,
					currentFont->Size,
					newStyle,
					currentFont->Unit
				);
			}
			notifications->Text = "the font change was successful";
		}
		else
		{
			//If nothing is highlighted, change the font for the entire text.
			System::Drawing::Font^ currentFont = richTextBox1->Font;
			FontStyle newStyle = currentFont->Style ^ style;
	
			richTextBox1->Font = gcnew System::Drawing::Font(
				currentFont->FontFamily,
				currentFont->Size,
				newStyle,
				currentFont->Unit
			);
			notifications->Text = "the font change was successful";
		}
	
	}

	//Initialize for scrollbar
	public: void InitiliazeScrollBar(RichTextBox^ richTextBox1, HScrollBar^ hScrollBar1)
	{
		int textWidth = GetTextWidth(richTextBox1);

		// Setting the scroll settings
		hScrollBar1->Minimum = 0;
		hScrollBar1->Maximum = 0;
		hScrollBar1->LargeChange = richTextBox1->ClientSize.Width;
		hScrollBar1->SmallChange = 20;
	}

	private: int GetTextWidth(RichTextBox^ richTextBox1)
	{
		Graphics^ G = richTextBox1->CreateGraphics();

		// Measuring the width of the entire text
		SizeF textSize = G->MeasureString(richTextBox1->Text,
			richTextBox1->Font,
			Int32::MaxValue,
			StringFormat::GenericTypographic);

		delete G;
		return (int)textSize.Width;
	}

};
