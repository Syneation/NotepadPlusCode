#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

class HelperReplace 
{
	//Find Next
    public: 
            void findNext(String^ searchText, bool matchCase, bool searchDown, RichTextBox^ richTextBoxToSearch,
        Label^ notifications, CheckBox^ checkBoxWrapping, int% lastFoundPosition)
        {
        try
        {
            // Checking the RichTextBox status
            if (richTextBoxToSearch == nullptr || richTextBoxToSearch->IsDisposed)
            {
                MessageBox::Show("Editor is not available", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            // Checking the search query
            if (String::IsNullOrEmpty(searchText))
                return;

            // Resetting the previous selection
            richTextBoxToSearch->SelectionBackColor = richTextBoxToSearch->BackColor;

            RichTextBoxFinds options = RichTextBoxFinds::None;
            if (matchCase)
                options = static_cast<RichTextBoxFinds>(static_cast<int>(options) | static_cast<int>(RichTextBoxFinds::MatchCase));

            int startPos = searchDown ? Math::Max(0, richTextBoxToSearch->SelectionStart + richTextBoxToSearch->SelectionLength) : 0;
            int endPos = searchDown ? richTextBoxToSearch->Text->Length : Math::Max(0, richTextBoxToSearch->SelectionStart);

            int foundPos = richTextBoxToSearch->Find(searchText, startPos, endPos, options);

            // Processing of search results
            if (foundPos >= 0)
            {
                // Highlighting the found text with color
                richTextBoxToSearch->SelectionStart = foundPos;
                richTextBoxToSearch->SelectionLength = searchText->Length;
                richTextBoxToSearch->SelectionBackColor = Color::FromArgb(255, 255, 200); // Светло-желтый фон
                richTextBoxToSearch->ScrollToCaret();
                lastFoundPosition = foundPos;

                // update notifications
                if (notifications != nullptr)
                    notifications->Text = "Text found at position " + foundPos;
            }
            else if (checkBoxWrapping->Checked)
            {
                // Повторный поиск с начала/конца
                foundPos = richTextBoxToSearch->Find(searchText,
                    searchDown ? 0 : richTextBoxToSearch->Text->Length,
                    searchDown ? richTextBoxToSearch->Text->Length : 0,
                    options);

                if (foundPos >= 0)
                {
                    // Highlighting the found text with color
                    richTextBoxToSearch->SelectionStart = foundPos;
                    richTextBoxToSearch->SelectionLength = searchText->Length;
                    richTextBoxToSearch->SelectionBackColor = Color::FromArgb(255, 255, 200);
                    richTextBoxToSearch->ScrollToCaret();
                    lastFoundPosition = foundPos;

                    if (notifications != nullptr)
                        notifications->Text = "Text found (wrapped) at position " + foundPos;
                }
                else
                {
                    ShowNotFoundMessage(searchText);
                    if (notifications != nullptr)
                        notifications->Text = "Text not found";
                }
            }
            else
            {
                ShowNotFoundMessage(searchText);
                if (notifications != nullptr)
                    notifications->Text = "Text not found";
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Search error: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            if (notifications != nullptr)
                notifications->Text = "Search error occurred";
        }
    }

        void ShowNotFoundMessage(String^ text)
        {
            MessageBox::Show(String::Format("Cannot find \"{0}\"", text),
                "Notepad+", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

		void ResetTextHighlighting(RichTextBox^ richTextBoxToSearch, Color originalBackColor)
		{
			richTextBoxToSearch->SelectionBackColor = originalBackColor;
		}

        //replace all
        void ReplaceAll(String^ searchText, String^ replaceText, bool matchCase, RichTextBox^ richTextBoxToSearch, Label^ notifications)
        {
            try
            {
                // Validate input parameters
                if (richTextBoxToSearch == nullptr || richTextBoxToSearch->IsDisposed)
                {
                    MessageBox::Show("Editor is not available", "Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                // Check if search text is empty
                if (String::IsNullOrEmpty(searchText))
                {
                    if (notifications != nullptr)
                        notifications->Text = "Search text cannot be empty";
                    return;
                }

                int replaceCount = 0;
                int startPos = 0;

                // Set search options based on case sensitivity
                RichTextBoxFinds options = matchCase ? RichTextBoxFinds::MatchCase : RichTextBoxFinds::None;

                // Store original selection color
                Color originalSelectionColor = richTextBoxToSearch->SelectionBackColor;
                Color highlightColor = Color::FromArgb(255, 255, 200); // Light yellow highlight

                // Start search from beginning of document
                richTextBoxToSearch->SelectionStart = 0;
                richTextBoxToSearch->SelectionLength = 0;

                // Suspend UI updates for better performance
                richTextBoxToSearch->SuspendLayout();

                // Main replacement loop
                while (true)
                {
                    // Find next occurrence
                    int foundPos = richTextBoxToSearch->Find(searchText, startPos, richTextBoxToSearch->Text->Length, options);

                    // Exit loop if no more matches found
                    if (foundPos == -1) break;

                    // Highlight found text before replacement
                    richTextBoxToSearch->SelectionStart = foundPos;
                    richTextBoxToSearch->SelectionLength = searchText->Length;
                    richTextBoxToSearch->SelectionBackColor = highlightColor;

                    // Perform the replacement
                    richTextBoxToSearch->SelectedText = replaceText;

                    replaceCount++;
                    startPos = foundPos + replaceText->Length;
                }

                // Restore UI updates
                richTextBoxToSearch->ResumeLayout();

                // Restore original selection color
                richTextBoxToSearch->SelectionBackColor = originalSelectionColor;

                // Show operation results
                if (replaceCount > 0)
                {
                    String^ message = String::Format("Replaced {0} occurrences", replaceCount);
                    MessageBox::Show(message, "Notepad+",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);

                    if (notifications != nullptr)
                        notifications->Text = message;
                }
                else
                {
                    String^ message = "Cannot find \"" + searchText + "\"";
                    MessageBox::Show(message, "Notepad+",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);

                    if (notifications != nullptr)
                        notifications->Text = message;
                }
            }
            catch (Exception^ ex)
            {
                // Ensure UI updates are restored if error occurs
                if (richTextBoxToSearch != nullptr && !richTextBoxToSearch->IsDisposed)
                {
                    richTextBoxToSearch->ResumeLayout();
                }

                MessageBox::Show("Replace error: " + ex->Message, "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);

                if (notifications != nullptr)
                    notifications->Text = "Error during replace operation";
            }
        }

		
};
