#include <windows.h>
#include <string>

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Windows::Forms;

/// <summary>
/// Helper class for printing RichTextBox content
/// </summary>
public ref class PrintHelper
{
private:
    RichTextBox^ richTextBox;          
    String^ textToPrint;               
    PrintDocument^ printDoc;           

    /// <summary>
    /// Handles the actual printing of each page
    /// </summary>
    void PrintPageHandler(Object^ sender, PrintPageEventArgs^ e)
    {
        // Create font for printing
        Font^ printFont = gcnew Font("Arial", 10);

        // Calculate lines per page (convert to float explicitly to avoid warning)
        float linesPerPage = static_cast<float>(e->MarginBounds.Height) / printFont->GetHeight(e->Graphics);

        float yPos = 0;
        int count = 0;
        float leftMargin = static_cast<float>(e->MarginBounds.Left);   // Explicit conversion
        float topMargin = static_cast<float>(e->MarginBounds.Top);     // Explicit conversion

        // Print each line until page is full or text ends
        while (count < linesPerPage && count < richTextBox->Lines->Length)
        {
            String^ line = richTextBox->Lines[count];
            yPos = topMargin + (count * printFont->GetHeight(e->Graphics));
            e->Graphics->DrawString(line, printFont, Brushes::Black, leftMargin, yPos);
            count++;
        }

        // Check if more pages needed
        e->HasMorePages = (count < richTextBox->Lines->Length);
    }

public:
    /// <summary>
    /// Constructor - initializes printing components
    /// </summary>
    PrintHelper(RichTextBox^ rTextBox) : richTextBox(rTextBox)
    {
        textToPrint = rTextBox->Text;
        printDoc = gcnew PrintDocument();
        printDoc->PrintPage += gcnew PrintPageEventHandler(this, &PrintHelper::PrintPageHandler);
    }

    /// <summary>
    /// Shows print dialog and initiates printing
    /// </summary>
    void Print(Label^ notificationsLabel)
    {
        PrintDialog^ printDialog = gcnew PrintDialog();
        printDialog->Document = printDoc;

        if (printDialog->ShowDialog() == DialogResult::OK)
        {
            try
            {
                printDoc->Print();
                notificationsLabel->Text = "Printing completed successfully";
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Printing error: " + ex->Message,
                    "Print Error",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Error);
                notificationsLabel->Text = "Printing failed";
            }
        }
    }
};