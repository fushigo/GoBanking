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
	/// Summary for Transfer
	/// </summary>
	public ref class Transfer : public System::Windows::Forms::Form
	{
	public:
		Transfer(void)
		{
			InitializeComponent();
			loadDropdownData();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Transfer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ transferMainPanel;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ transferInputPanel;

	private: System::Windows::Forms::Button^ btnTransfer;




	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;





	private: System::Windows::Forms::Label^ pin;
	private: System::Windows::Forms::TextBox^ pinInput;



	private: System::Windows::Forms::Label^ nominal;
	private: System::Windows::Forms::TextBox^ nominalInput;




	private: System::Windows::Forms::Label^ recipientsAccNum;

	private: System::Windows::Forms::Label^ customerAccNum;





	private: System::Windows::Forms::Panel^ customerAccInputPanel;
	private: System::Windows::Forms::Panel^ pinInputPanel;




	private: System::Windows::Forms::Panel^ nominalInputPanel;

	private: System::Windows::Forms::Panel^ recipientsAccInputPanel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ dropDownMenuSend;
	private: System::Windows::Forms::ComboBox^ dropDownMenuReceive;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ dropDownDana;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;




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
			this->transferMainPanel = (gcnew System::Windows::Forms::Panel());
			this->transferInputPanel = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dropDownDana = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pinInputPanel = (gcnew System::Windows::Forms::Panel());
			this->pin = (gcnew System::Windows::Forms::Label());
			this->pinInput = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->nominalInputPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nominal = (gcnew System::Windows::Forms::Label());
			this->nominalInput = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->recipientsAccInputPanel = (gcnew System::Windows::Forms::Panel());
			this->dropDownMenuReceive = (gcnew System::Windows::Forms::ComboBox());
			this->recipientsAccNum = (gcnew System::Windows::Forms::Label());
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->customerAccInputPanel = (gcnew System::Windows::Forms::Panel());
			this->dropDownMenuSend = (gcnew System::Windows::Forms::ComboBox());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->transferMainPanel->SuspendLayout();
			this->transferInputPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->pinInputPanel->SuspendLayout();
			this->nominalInputPanel->SuspendLayout();
			this->recipientsAccInputPanel->SuspendLayout();
			this->customerAccInputPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// transferMainPanel
			// 
			this->transferMainPanel->Controls->Add(this->transferInputPanel);
			this->transferMainPanel->Controls->Add(this->label1);
			this->transferMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->transferMainPanel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->transferMainPanel->ForeColor = System::Drawing::Color::White;
			this->transferMainPanel->Location = System::Drawing::Point(222, 0);
			this->transferMainPanel->Margin = System::Windows::Forms::Padding(2);
			this->transferMainPanel->Name = L"transferMainPanel";
			this->transferMainPanel->Size = System::Drawing::Size(818, 640);
			this->transferMainPanel->TabIndex = 0;
			// 
			// transferInputPanel
			// 
			this->transferInputPanel->Controls->Add(this->panel1);
			this->transferInputPanel->Controls->Add(this->pinInputPanel);
			this->transferInputPanel->Controls->Add(this->nominalInputPanel);
			this->transferInputPanel->Controls->Add(this->recipientsAccInputPanel);
			this->transferInputPanel->Controls->Add(this->btnTransfer);
			this->transferInputPanel->Controls->Add(this->customerAccInputPanel);
			this->transferInputPanel->Location = System::Drawing::Point(34, 173);
			this->transferInputPanel->Margin = System::Windows::Forms::Padding(2);
			this->transferInputPanel->Name = L"transferInputPanel";
			this->transferInputPanel->Size = System::Drawing::Size(750, 385);
			this->transferInputPanel->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->label4->Location = System::Drawing::Point(102, 0);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 16);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Saldo :";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->dropDownDana);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(385, 16);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(345, 57);
			this->panel1->TabIndex = 40;
			// 
			// dropDownDana
			// 
			this->dropDownDana->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dropDownDana->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->dropDownDana->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->dropDownDana->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dropDownDana->ForeColor = System::Drawing::Color::White;
			this->dropDownDana->FormattingEnabled = true;
			this->dropDownDana->Location = System::Drawing::Point(4, 32);
			this->dropDownDana->Margin = System::Windows::Forms::Padding(2);
			this->dropDownDana->MaxDropDownItems = 100;
			this->dropDownDana->Name = L"dropDownDana";
			this->dropDownDana->Size = System::Drawing::Size(338, 24);
			this->dropDownDana->TabIndex = 3;
			this->dropDownDana->Tag = L"";
			this->dropDownDana->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &Transfer::dropDownDana_DrawItem);
			this->dropDownDana->SelectedIndexChanged += gcnew System::EventHandler(this, &Transfer::dropDownDana_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->label3->Location = System::Drawing::Point(1, 0);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(97, 16);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Sumber Dana";
			// 
			// pinInputPanel
			// 
			this->pinInputPanel->Controls->Add(this->pin);
			this->pinInputPanel->Controls->Add(this->pinInput);
			this->pinInputPanel->Controls->Add(this->panel4);
			this->pinInputPanel->Location = System::Drawing::Point(16, 243);
			this->pinInputPanel->Margin = System::Windows::Forms::Padding(2);
			this->pinInputPanel->Name = L"pinInputPanel";
			this->pinInputPanel->Size = System::Drawing::Size(158, 57);
			this->pinInputPanel->TabIndex = 42;
			// 
			// pin
			// 
			this->pin->AutoSize = true;
			this->pin->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->pin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->pin->Location = System::Drawing::Point(0, 0);
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
			this->pinInput->Location = System::Drawing::Point(3, 25);
			this->pinInput->Margin = System::Windows::Forms::Padding(2);
			this->pinInput->MaxLength = 15;
			this->pinInput->Name = L"pinInput";
			this->pinInput->Size = System::Drawing::Size(150, 16);
			this->pinInput->TabIndex = 26;
			this->pinInput->UseSystemPasswordChar = true;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(3, 50);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(150, 4);
			this->panel4->TabIndex = 34;
			// 
			// nominalInputPanel
			// 
			this->nominalInputPanel->Controls->Add(this->label2);
			this->nominalInputPanel->Controls->Add(this->nominal);
			this->nominalInputPanel->Controls->Add(this->nominalInput);
			this->nominalInputPanel->Controls->Add(this->panel3);
			this->nominalInputPanel->Location = System::Drawing::Point(16, 167);
			this->nominalInputPanel->Margin = System::Windows::Forms::Padding(2);
			this->nominalInputPanel->Name = L"nominalInputPanel";
			this->nominalInputPanel->Size = System::Drawing::Size(345, 57);
			this->nominalInputPanel->TabIndex = 41;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(0, 25);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 16);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Rp.";
			// 
			// nominal
			// 
			this->nominal->AutoSize = true;
			this->nominal->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->nominal->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->nominal->Location = System::Drawing::Point(0, 0);
			this->nominal->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->nominal->Name = L"nominal";
			this->nominal->Size = System::Drawing::Size(124, 16);
			this->nominal->TabIndex = 25;
			this->nominal->Text = L"Nominal Transfer";
			// 
			// nominalInput
			// 
			this->nominalInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->nominalInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nominalInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nominalInput->ForeColor = System::Drawing::Color::White;
			this->nominalInput->Location = System::Drawing::Point(33, 25);
			this->nominalInput->Margin = System::Windows::Forms::Padding(2);
			this->nominalInput->MaxLength = 100;
			this->nominalInput->Name = L"nominalInput";
			this->nominalInput->Size = System::Drawing::Size(308, 16);
			this->nominalInput->TabIndex = 24;
			this->nominalInput->TextChanged += gcnew System::EventHandler(this, &Transfer::nominalInput_TextChanged);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(3, 50);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(338, 4);
			this->panel3->TabIndex = 33;
			// 
			// recipientsAccInputPanel
			// 
			this->recipientsAccInputPanel->Controls->Add(this->dropDownMenuReceive);
			this->recipientsAccInputPanel->Controls->Add(this->recipientsAccNum);
			this->recipientsAccInputPanel->Location = System::Drawing::Point(16, 92);
			this->recipientsAccInputPanel->Margin = System::Windows::Forms::Padding(2);
			this->recipientsAccInputPanel->Name = L"recipientsAccInputPanel";
			this->recipientsAccInputPanel->Size = System::Drawing::Size(345, 57);
			this->recipientsAccInputPanel->TabIndex = 40;
			// 
			// dropDownMenuReceive
			// 
			this->dropDownMenuReceive->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dropDownMenuReceive->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->dropDownMenuReceive->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dropDownMenuReceive->ForeColor = System::Drawing::Color::White;
			this->dropDownMenuReceive->FormattingEnabled = true;
			this->dropDownMenuReceive->Location = System::Drawing::Point(4, 32);
			this->dropDownMenuReceive->Margin = System::Windows::Forms::Padding(2);
			this->dropDownMenuReceive->MaxDropDownItems = 100;
			this->dropDownMenuReceive->Name = L"dropDownMenuReceive";
			this->dropDownMenuReceive->Size = System::Drawing::Size(338, 24);
			this->dropDownMenuReceive->TabIndex = 43;
			this->dropDownMenuReceive->Tag = L"";
			this->dropDownMenuReceive->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &Transfer::dropDownMenuReceive_DrawItem);
			this->dropDownMenuReceive->SelectedIndexChanged += gcnew System::EventHandler(this, &Transfer::dropDownMenuReceive_SelectedIndexChanged);
			// 
			// recipientsAccNum
			// 
			this->recipientsAccNum->AutoSize = true;
			this->recipientsAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->recipientsAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->recipientsAccNum->Location = System::Drawing::Point(0, 0);
			this->recipientsAccNum->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->recipientsAccNum->Name = L"recipientsAccNum";
			this->recipientsAccNum->Size = System::Drawing::Size(160, 16);
			this->recipientsAccNum->TabIndex = 23;
			this->recipientsAccNum->Text = L"No. Identitas Penerima";
			// 
			// btnTransfer
			// 
			this->btnTransfer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnTransfer->FlatAppearance->BorderSize = 0;
			this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTransfer->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->btnTransfer->Location = System::Drawing::Point(16, 318);
			this->btnTransfer->Margin = System::Windows::Forms::Padding(2);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Size = System::Drawing::Size(165, 49);
			this->btnTransfer->TabIndex = 38;
			this->btnTransfer->Text = L"Transfer";
			this->btnTransfer->UseVisualStyleBackColor = false;
			this->btnTransfer->Click += gcnew System::EventHandler(this, &Transfer::btnTransfer_Click);
			// 
			// customerAccInputPanel
			// 
			this->customerAccInputPanel->Controls->Add(this->dropDownMenuSend);
			this->customerAccInputPanel->Controls->Add(this->customerAccNum);
			this->customerAccInputPanel->Location = System::Drawing::Point(16, 16);
			this->customerAccInputPanel->Margin = System::Windows::Forms::Padding(2);
			this->customerAccInputPanel->Name = L"customerAccInputPanel";
			this->customerAccInputPanel->Size = System::Drawing::Size(345, 57);
			this->customerAccInputPanel->TabIndex = 39;
			// 
			// dropDownMenuSend
			// 
			this->dropDownMenuSend->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dropDownMenuSend->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->dropDownMenuSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->dropDownMenuSend->ForeColor = System::Drawing::Color::White;
			this->dropDownMenuSend->FormattingEnabled = true;
			this->dropDownMenuSend->Location = System::Drawing::Point(4, 32);
			this->dropDownMenuSend->Margin = System::Windows::Forms::Padding(2);
			this->dropDownMenuSend->MaxDropDownItems = 100;
			this->dropDownMenuSend->Name = L"dropDownMenuSend";
			this->dropDownMenuSend->Size = System::Drawing::Size(338, 24);
			this->dropDownMenuSend->TabIndex = 3;
			this->dropDownMenuSend->Tag = L"";
			this->dropDownMenuSend->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &Transfer::dropDownMenuSend_DrawItem);
			this->dropDownMenuSend->SelectedIndexChanged += gcnew System::EventHandler(this, &Transfer::dropDownMenuSend_SelectedIndexChanged);
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(1, 0);
			this->customerAccNum->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->customerAccNum->Name = L"customerAccNum";
			this->customerAccNum->Size = System::Drawing::Size(157, 16);
			this->customerAccNum->TabIndex = 21;
			this->customerAccNum->Text = L"No. Identitas Pengirim";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(25, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Transfer";
			// 
			// Transfer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1040, 640);
			this->Controls->Add(this->transferMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Transfer";
			this->Text = L"Transfer";
			this->Load += gcnew System::EventHandler(this, &Transfer::Transfer_Load);
			this->transferMainPanel->ResumeLayout(false);
			this->transferMainPanel->PerformLayout();
			this->transferInputPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->pinInputPanel->ResumeLayout(false);
			this->pinInputPanel->PerformLayout();
			this->nominalInputPanel->ResumeLayout(false);
			this->nominalInputPanel->PerformLayout();
			this->recipientsAccInputPanel->ResumeLayout(false);
			this->recipientsAccInputPanel->PerformLayout();
			this->customerAccInputPanel->ResumeLayout(false);
			this->customerAccInputPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: PopupForm^ currentPopup;

// Transfer base Form
private: System::Void Transfer_Load(System::Object^ sender, System::EventArgs^ e) {
	// dropDownMenuSend
	this->dropDownMenuSend->Items->Insert(0, "-- Pilih Nasabah --");
	this->dropDownMenuSend->SelectedIndex = 0;

	// dropDownMenuReceive

	this->dropDownMenuReceive->Items->Insert(0, "-- Pilih Penerima --");
	this->dropDownMenuReceive->SelectedIndex = 0;

	this->dropDownDana->Items->Insert(0, "-- Pilih Sumber Dana --");
	this->dropDownDana->SelectedIndex = 0;
}

// ============================ btnTransfer ==========================
private:
	System::Void btnTransfer_Click(System::Object^ sender, System::EventArgs^ e) {
		ShowConfirmationPopup();
	}

	System::Void ShowConfirmationPopup() {
		CloseCurrentPopup();

		currentPopup = gcnew PopupForm();
		currentPopup->SetMessage("Apakah Anda yakin ingin melanjutkan transfer?");
		currentPopup->SetActionButton1("Konfirmasi", gcnew EventHandler(this, &Transfer::OnConfirmTransfer));
		currentPopup->SetActionButton2("Batal", gcnew EventHandler(this, &Transfer::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void OnConfirmTransfer(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			ProcessTransfer();
		}
	}

	// ===================================== Random simulation for test ======================================
	System::Void ProcessTransfer() {
		// Random success/fail simulation
		Random^ rand = gcnew Random();
		bool isSuccess = (rand->Next(100) < 70); // 70% success rate
		ShowResultPopup(isSuccess);
	}
	// ===================================== Random simulation for test end ======================================

	System::Void ShowResultPopup(bool isSuccess) {
		currentPopup = gcnew PopupForm();
		if (isSuccess) {
			currentPopup->SetMessage("Transfer berhasil!");
			currentPopup->SetActionButton1("OK", gcnew EventHandler(this, &Transfer::OnResultConfirmed));
		}
		else {
			currentPopup->SetMessage("Transfer gagal!");
			currentPopup->SetActionButton1("Coba Lagi", gcnew EventHandler(this, &Transfer::OnRetryTransfer));
		}
		currentPopup->SetActionButton2("Tutup", gcnew EventHandler(this, &Transfer::OnClose));
		currentPopup->ShowPopup();
	}

	System::Void OnResultConfirmed(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void OnRetryTransfer(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			ShowConfirmationPopup();
		}
	}

	System::Void OnClose(System::Object^ sender, System::EventArgs^ e) {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
		}
	}

	System::Void CloseCurrentPopup() {
		if (currentPopup != nullptr) {
			currentPopup->ClosePopup();
			currentPopup = nullptr;
		}
	}
	// ============================ btnTransfer End ==========================

	// ============================ dropDownMenuSend =============================
	private: System::Void dropDownMenuSend_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dropDownMenuSend_DrawItem(System::Object^ sender, DrawItemEventArgs^ e) {
		if (e->Index < 0) return;

		// Custom colors
		Color normalColor = Color::FromArgb(110, 84, 181);      // Normal background
		Color hoverColor = Color::FromArgb(128, 128, 255);      // Hover/Selected background
		Color textColor = Color::White;                         // Text color

		// Set the background color based on selection state
		if ((e->State & DrawItemState::Selected) == DrawItemState::Selected)
			e->Graphics->FillRectangle(gcnew SolidBrush(hoverColor), e->Bounds);
		else
			e->Graphics->FillRectangle(gcnew SolidBrush(normalColor), e->Bounds);

		// Draw the text
		e->Graphics->DrawString(dropDownMenuSend->Items[e->Index]->ToString(),
			e->Font, gcnew SolidBrush(textColor),
			e->Bounds, StringFormat::GenericDefault);
	}
	// ============================ dropDownMenuSend End =============================

	// ============================ dropDownMenuReceive =============================
	private: System::Void dropDownMenuReceive_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dropDownMenuReceive_DrawItem(System::Object^ sender, DrawItemEventArgs^ e) {
		if (e->Index < 0) return;

		// Custom colors
		Color normalColor = Color::FromArgb(110, 84, 181);      // Normal background
		Color hoverColor = Color::FromArgb(128, 128, 255);      // Hover/Selected background
		Color textColor = Color::White;                         // Text color

		// Set the background color based on selection state
		if ((e->State & DrawItemState::Selected) == DrawItemState::Selected)
			e->Graphics->FillRectangle(gcnew SolidBrush(hoverColor), e->Bounds);
		else
			e->Graphics->FillRectangle(gcnew SolidBrush(normalColor), e->Bounds);

		// Draw the text
		e->Graphics->DrawString(dropDownMenuReceive->Items[e->Index]->ToString(),
			e->Font, gcnew SolidBrush(textColor),
			e->Bounds, StringFormat::GenericDefault);
	}
	
	private: System::Void dropDownDana_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dropDownDana_DrawItem(System::Object^ sender, DrawItemEventArgs^ e) {
		if (e->Index < 0) return;

		// Custom colors
		Color normalColor = Color::FromArgb(110, 84, 181);      // Normal background
		Color hoverColor = Color::FromArgb(128, 128, 255);      // Hover/Selected background
		Color textColor = Color::White;                         // Text color

		// Set the background color based on selection state
		if ((e->State & DrawItemState::Selected) == DrawItemState::Selected)
			e->Graphics->FillRectangle(gcnew SolidBrush(hoverColor), e->Bounds);
		else
			e->Graphics->FillRectangle(gcnew SolidBrush(normalColor), e->Bounds);

		// Draw the text
		e->Graphics->DrawString(dropDownDana->Items[e->Index]->ToString(),
			e->Font, gcnew SolidBrush(textColor),
			e->Bounds, StringFormat::GenericDefault);
	}
		  void loadDropdownData();
		   // ============================ dropDownMenuSend End =============================
private: System::Void nominalInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
