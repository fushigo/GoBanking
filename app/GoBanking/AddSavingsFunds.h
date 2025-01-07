#pragma once

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



	private: System::Windows::Forms::Panel^ panel7;






	private: System::Windows::Forms::Label^ customerAccNum;
	private: System::Windows::Forms::TextBox^ customerAccInput;
	private: System::Windows::Forms::Label^ withdrw;
	private: System::Windows::Forms::Panel^ nominalInputPanel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ nominalSavings;
	private: System::Windows::Forms::TextBox^ addSavingsInput;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ pinInputPanel;
	private: System::Windows::Forms::Label^ pinLabel;

	private: System::Windows::Forms::TextBox^ pinInput;
	private: System::Windows::Forms::Panel^ panel2;
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
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->withdrw = (gcnew System::Windows::Forms::Label());
			this->nominalInputPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nominalSavings = (gcnew System::Windows::Forms::Label());
			this->addSavingsInput = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pinInputPanel = (gcnew System::Windows::Forms::Panel());
			this->pinLabel = (gcnew System::Windows::Forms::Label());
			this->pinInput = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->addSavingsMainPanel->SuspendLayout();
			this->transferInputPanel->SuspendLayout();
			this->nominalInputPanel->SuspendLayout();
			this->pinInputPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// addSavingsMainPanel
			// 
			this->addSavingsMainPanel->Controls->Add(this->transferInputPanel);
			this->addSavingsMainPanel->Controls->Add(this->withdrw);
			this->addSavingsMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->addSavingsMainPanel->ForeColor = System::Drawing::Color::White;
			this->addSavingsMainPanel->Location = System::Drawing::Point(310, 0);
			this->addSavingsMainPanel->Name = L"addSavingsMainPanel";
			this->addSavingsMainPanel->Size = System::Drawing::Size(1090, 900);
			this->addSavingsMainPanel->TabIndex = 0;
			// 
			// transferInputPanel
			// 
			this->transferInputPanel->Controls->Add(this->pinInputPanel);
			this->transferInputPanel->Controls->Add(this->nominalInputPanel);
			this->transferInputPanel->Controls->Add(this->btnAddSavings);
			this->transferInputPanel->Controls->Add(this->panel7);
			this->transferInputPanel->Controls->Add(this->customerAccNum);
			this->transferInputPanel->Controls->Add(this->customerAccInput);
			this->transferInputPanel->Location = System::Drawing::Point(76, 175);
			this->transferInputPanel->Name = L"transferInputPanel";
			this->transferInputPanel->Size = System::Drawing::Size(500, 474);
			this->transferInputPanel->TabIndex = 6;
			// 
			// btnAddSavings
			// 
			this->btnAddSavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnAddSavings->FlatAppearance->BorderSize = 0;
			this->btnAddSavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->btnAddSavings->Location = System::Drawing::Point(27, 382);
			this->btnAddSavings->Name = L"btnAddSavings";
			this->btnAddSavings->Size = System::Drawing::Size(220, 60);
			this->btnAddSavings->TabIndex = 38;
			this->btnAddSavings->Text = L"Tabung";
			this->btnAddSavings->UseVisualStyleBackColor = false;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(27, 116);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(450, 5);
			this->panel7->TabIndex = 31;
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(23, 54);
			this->customerAccNum->Name = L"customerAccNum";
			this->customerAccNum->Size = System::Drawing::Size(196, 20);
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
			this->customerAccInput->Location = System::Drawing::Point(27, 85);
			this->customerAccInput->MaxLength = 50;
			this->customerAccInput->Name = L"customerAccInput";
			this->customerAccInput->Size = System::Drawing::Size(450, 20);
			this->customerAccInput->TabIndex = 20;
			// 
			// withdrw
			// 
			this->withdrw->AutoSize = true;
			this->withdrw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->withdrw->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->withdrw->Location = System::Drawing::Point(64, 60);
			this->withdrw->Name = L"withdrw";
			this->withdrw->Size = System::Drawing::Size(576, 70);
			this->withdrw->TabIndex = 5;
			this->withdrw->Text = L"Tambah Tabungan";
			// 
			// nominalInputPanel
			// 
			this->nominalInputPanel->Controls->Add(this->label2);
			this->nominalInputPanel->Controls->Add(this->nominalSavings);
			this->nominalInputPanel->Controls->Add(this->addSavingsInput);
			this->nominalInputPanel->Controls->Add(this->panel1);
			this->nominalInputPanel->Location = System::Drawing::Point(27, 138);
			this->nominalInputPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->nominalInputPanel->Name = L"nominalInputPanel";
			this->nominalInputPanel->Size = System::Drawing::Size(460, 70);
			this->nominalInputPanel->TabIndex = 42;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(0, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 20);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Rp.";
			// 
			// nominalSavings
			// 
			this->nominalSavings->AutoSize = true;
			this->nominalSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->nominalSavings->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->nominalSavings->Location = System::Drawing::Point(0, 0);
			this->nominalSavings->Name = L"nominalSavings";
			this->nominalSavings->Size = System::Drawing::Size(164, 20);
			this->nominalSavings->TabIndex = 25;
			this->nominalSavings->Text = L"Nominal Tabungan";
			// 
			// addSavingsInput
			// 
			this->addSavingsInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->addSavingsInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addSavingsInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->addSavingsInput->ForeColor = System::Drawing::Color::White;
			this->addSavingsInput->Location = System::Drawing::Point(44, 31);
			this->addSavingsInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addSavingsInput->MaxLength = 100;
			this->addSavingsInput->Name = L"addSavingsInput";
			this->addSavingsInput->Size = System::Drawing::Size(411, 20);
			this->addSavingsInput->TabIndex = 24;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(4, 62);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(451, 5);
			this->panel1->TabIndex = 33;
			// 
			// pinInputPanel
			// 
			this->pinInputPanel->Controls->Add(this->pinLabel);
			this->pinInputPanel->Controls->Add(this->pinInput);
			this->pinInputPanel->Controls->Add(this->panel2);
			this->pinInputPanel->Location = System::Drawing::Point(27, 230);
			this->pinInputPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pinInputPanel->Name = L"pinInputPanel";
			this->pinInputPanel->Size = System::Drawing::Size(211, 70);
			this->pinInputPanel->TabIndex = 43;
			// 
			// pinLabel
			// 
			this->pinLabel->AutoSize = true;
			this->pinLabel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->pinLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->pinLabel->Location = System::Drawing::Point(0, 0);
			this->pinLabel->Name = L"pinLabel";
			this->pinLabel->Size = System::Drawing::Size(38, 20);
			this->pinLabel->TabIndex = 27;
			this->pinLabel->Text = L"PIN";
			// 
			// pinInput
			// 
			this->pinInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pinInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pinInput->ForeColor = System::Drawing::Color::White;
			this->pinInput->Location = System::Drawing::Point(5, 31);
			this->pinInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pinInput->MaxLength = 15;
			this->pinInput->Name = L"pinInput";
			this->pinInput->Size = System::Drawing::Size(200, 20);
			this->pinInput->TabIndex = 26;
			this->pinInput->UseSystemPasswordChar = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(5, 62);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 5);
			this->panel2->TabIndex = 34;
			// 
			// AddSavingsFunds
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->addSavingsMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AddSavingsFunds";
			this->Text = L"AddSavingsFunds";
			this->addSavingsMainPanel->ResumeLayout(false);
			this->addSavingsMainPanel->PerformLayout();
			this->transferInputPanel->ResumeLayout(false);
			this->transferInputPanel->PerformLayout();
			this->nominalInputPanel->ResumeLayout(false);
			this->nominalInputPanel->PerformLayout();
			this->pinInputPanel->ResumeLayout(false);
			this->pinInputPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
