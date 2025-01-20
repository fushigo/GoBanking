#pragma once
#include "PopupForm.h"

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddSavingsFunds
	/// </summary>
	public ref class AddSavingsFunds : public System::Windows::Forms::Form
	{
	public:
		AddSavingsFunds(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddSavingsFunds()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ addSavingsMainPanel;
	private: System::Windows::Forms::Panel^ transferInputPanel;
	private: System::Windows::Forms::Button^ btnAddSavings;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ pin;
	private: System::Windows::Forms::TextBox^ pinInput;
	private: System::Windows::Forms::Label^ nominalSavings;

	private: System::Windows::Forms::TextBox^ addSavingsInput;

	private: System::Windows::Forms::Label^ customerAccNum;
	private: System::Windows::Forms::TextBox^ customerAccInput;
	private: System::Windows::Forms::Label^ withdrw;
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
			this->addSavingsMainPanel = (gcnew System::Windows::Forms::Panel());
			this->transferInputPanel = (gcnew System::Windows::Forms::Panel());
			this->btnAddSavings = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->pin = (gcnew System::Windows::Forms::Label());
			this->pinInput = (gcnew System::Windows::Forms::TextBox());
			this->nominalSavings = (gcnew System::Windows::Forms::Label());
			this->addSavingsInput = (gcnew System::Windows::Forms::TextBox());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->withdrw = (gcnew System::Windows::Forms::Label());
			this->addSavingsMainPanel->SuspendLayout();
			this->transferInputPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// addSavingsMainPanel
			// 
			this->addSavingsMainPanel->Controls->Add(this->transferInputPanel);
			this->addSavingsMainPanel->Controls->Add(this->withdrw);
			this->addSavingsMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->addSavingsMainPanel->ForeColor = System::Drawing::Color::White;
			this->addSavingsMainPanel->Location = System::Drawing::Point(222, 0);
			this->addSavingsMainPanel->Margin = System::Windows::Forms::Padding(2);
			this->addSavingsMainPanel->Name = L"addSavingsMainPanel";
			this->addSavingsMainPanel->Size = System::Drawing::Size(818, 640);
			this->addSavingsMainPanel->TabIndex = 0;
			// 
			// transferInputPanel
			// 
			this->transferInputPanel->Controls->Add(this->btnAddSavings);
			this->transferInputPanel->Controls->Add(this->panel4);
			this->transferInputPanel->Controls->Add(this->panel3);
			this->transferInputPanel->Controls->Add(this->panel7);
			this->transferInputPanel->Controls->Add(this->pin);
			this->transferInputPanel->Controls->Add(this->pinInput);
			this->transferInputPanel->Controls->Add(this->nominalSavings);
			this->transferInputPanel->Controls->Add(this->addSavingsInput);
			this->transferInputPanel->Controls->Add(this->customerAccNum);
			this->transferInputPanel->Controls->Add(this->customerAccInput);
			this->transferInputPanel->Location = System::Drawing::Point(57, 142);
			this->transferInputPanel->Margin = System::Windows::Forms::Padding(2);
			this->transferInputPanel->Name = L"transferInputPanel";
			this->transferInputPanel->Size = System::Drawing::Size(375, 385);
			this->transferInputPanel->TabIndex = 6;
			// 
			// btnAddSavings
			// 
			this->btnAddSavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnAddSavings->FlatAppearance->BorderSize = 0;
			this->btnAddSavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->btnAddSavings->Location = System::Drawing::Point(20, 310);
			this->btnAddSavings->Margin = System::Windows::Forms::Padding(2);
			this->btnAddSavings->Name = L"btnAddSavings";
			this->btnAddSavings->Size = System::Drawing::Size(165, 49);
			this->btnAddSavings->TabIndex = 38;
			this->btnAddSavings->Text = L"Tabung";
			this->btnAddSavings->UseVisualStyleBackColor = false;
			this->btnAddSavings->Click += gcnew System::EventHandler(this, &AddSavingsFunds::btnAddSavings_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(20, 221);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(150, 4);
			this->panel4->TabIndex = 34;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(20, 158);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(338, 4);
			this->panel3->TabIndex = 33;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(20, 94);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(338, 4);
			this->panel7->TabIndex = 31;
			// 
			// pin
			// 
			this->pin->AutoSize = true;
			this->pin->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->pin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->pin->Location = System::Drawing::Point(17, 171);
			this->pin->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->pin->Name = L"pin";
			this->pin->Size = System::Drawing::Size(31, 16);
			this->pin->TabIndex = 27;
			this->pin->Text = L"PIN";
			// 
			// pinInput
			// 
			this->pinInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pinInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pinInput->ForeColor = System::Drawing::Color::White;
			this->pinInput->Location = System::Drawing::Point(20, 196);
			this->pinInput->Margin = System::Windows::Forms::Padding(2);
			this->pinInput->MaxLength = 15;
			this->pinInput->Name = L"pinInput";
			this->pinInput->Size = System::Drawing::Size(150, 16);
			this->pinInput->TabIndex = 26;
			this->pinInput->UseSystemPasswordChar = true;
			this->pinInput->TextChanged += gcnew System::EventHandler(this, &AddSavingsFunds::pinInput_TextChanged);
			// 
			// nominalSavings
			// 
			this->nominalSavings->AutoSize = true;
			this->nominalSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->nominalSavings->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->nominalSavings->Location = System::Drawing::Point(17, 107);
			this->nominalSavings->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->nominalSavings->Name = L"nominalSavings";
			this->nominalSavings->Size = System::Drawing::Size(241, 16);
			this->nominalSavings->TabIndex = 25;
			this->nominalSavings->Text = L"Nominal uang yang ingin di tabung";
			// 
			// addSavingsInput
			// 
			this->addSavingsInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->addSavingsInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addSavingsInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->addSavingsInput->ForeColor = System::Drawing::Color::White;
			this->addSavingsInput->Location = System::Drawing::Point(20, 132);
			this->addSavingsInput->Margin = System::Windows::Forms::Padding(2);
			this->addSavingsInput->MaxLength = 100;
			this->addSavingsInput->Name = L"addSavingsInput";
			this->addSavingsInput->Size = System::Drawing::Size(338, 16);
			this->addSavingsInput->TabIndex = 24;
			this->addSavingsInput->TextChanged += gcnew System::EventHandler(this, &AddSavingsFunds::addSavingsInput_TextChanged);
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(17, 44);
			this->customerAccNum->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->customerAccNum->Name = L"customerAccNum";
			this->customerAccNum->Size = System::Drawing::Size(161, 16);
			this->customerAccNum->TabIndex = 21;
			this->customerAccNum->Text = L"No. Rekening Nasabah";
			// 
			// customerAccInput
			// 
			this->customerAccInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->customerAccInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->customerAccInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->customerAccInput->ForeColor = System::Drawing::Color::White;
			this->customerAccInput->Location = System::Drawing::Point(20, 69);
			this->customerAccInput->Margin = System::Windows::Forms::Padding(2);
			this->customerAccInput->MaxLength = 50;
			this->customerAccInput->Name = L"customerAccInput";
			this->customerAccInput->Size = System::Drawing::Size(338, 16);
			this->customerAccInput->TabIndex = 20;
			this->customerAccInput->TextChanged += gcnew System::EventHandler(this, &AddSavingsFunds::customerAccInput_TextChanged);
			// 
			// withdrw
			// 
			this->withdrw->AutoSize = true;
			this->withdrw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->withdrw->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->withdrw->Location = System::Drawing::Point(48, 49);
			this->withdrw->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->withdrw->Name = L"withdrw";
			this->withdrw->Size = System::Drawing::Size(460, 55);
			this->withdrw->TabIndex = 5;
			this->withdrw->Text = L"Tambah Tabungan";
			// 
			// AddSavingsFunds
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1040, 640);
			this->Controls->Add(this->addSavingsMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddSavingsFunds";
			this->Text = L"AddSavingsFunds";
			this->addSavingsMainPanel->ResumeLayout(false);
			this->addSavingsMainPanel->PerformLayout();
			this->transferInputPanel->ResumeLayout(false);
			this->transferInputPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		PopupForm^ currentPopup;

		System::Void ShowConfirmationPopup();

		System::Void OnConfirmAddSavings(System::Object^ sender, System::EventArgs^ e);
		System::Void ProcessAddSavings();

		System::Void ShowResultPopup(bool isSuccess, String^ message);
		System::Void OnResultConfirmed(System::Object^ sender, System::EventArgs^ e);
		System::Void OnRetryAddSavings(System::Object^ sender, System::EventArgs^ e);

		System::Void OnClose(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseCurrentPopup();
		System::Void btnAddSavings_Click(System::Object^ sender, System::EventArgs^ e);
private: 
	System::Void customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void addSavingsInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void pinInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
