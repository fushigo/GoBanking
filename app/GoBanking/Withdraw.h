#pragma once

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Withdraw
	/// </summary>
	public ref class Withdraw : public System::Windows::Forms::Form
	{
	public:
		Withdraw(void)
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
		~Withdraw()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ withdrawMainPanel;
	private: System::Windows::Forms::Panel^ transferInputPanel;
	private: System::Windows::Forms::Button^ btnWithdraw;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ pin;
	private: System::Windows::Forms::TextBox^ pinInput;
	private: System::Windows::Forms::Label^ nominalWithdraw;
	private: System::Windows::Forms::TextBox^ nominalWithdrawInput;
	private: System::Windows::Forms::Label^ customerAccNum;
	private: System::Windows::Forms::TextBox^ customerAccInput;

	private: System::Windows::Forms::Label^ withdrw;
	private: System::Windows::Forms::Panel^ nominalPanel;
	private: System::Windows::Forms::Panel^ pinPanel;


	private: System::Windows::Forms::Panel^ accNumPanel;

	private: System::Windows::Forms::Label^ label2;
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
			this->withdrawMainPanel = (gcnew System::Windows::Forms::Panel());
			this->transferInputPanel = (gcnew System::Windows::Forms::Panel());
			this->btnWithdraw = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->pin = (gcnew System::Windows::Forms::Label());
			this->pinInput = (gcnew System::Windows::Forms::TextBox());
			this->nominalWithdraw = (gcnew System::Windows::Forms::Label());
			this->nominalWithdrawInput = (gcnew System::Windows::Forms::TextBox());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->withdrw = (gcnew System::Windows::Forms::Label());
			this->accNumPanel = (gcnew System::Windows::Forms::Panel());
			this->pinPanel = (gcnew System::Windows::Forms::Panel());
			this->nominalPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->withdrawMainPanel->SuspendLayout();
			this->transferInputPanel->SuspendLayout();
			this->accNumPanel->SuspendLayout();
			this->pinPanel->SuspendLayout();
			this->nominalPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// withdrawMainPanel
			// 
			this->withdrawMainPanel->Controls->Add(this->transferInputPanel);
			this->withdrawMainPanel->Controls->Add(this->withdrw);
			this->withdrawMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->withdrawMainPanel->ForeColor = System::Drawing::Color::White;
			this->withdrawMainPanel->Location = System::Drawing::Point(310, 0);
			this->withdrawMainPanel->Name = L"withdrawMainPanel";
			this->withdrawMainPanel->Size = System::Drawing::Size(1090, 900);
			this->withdrawMainPanel->TabIndex = 0;
			// 
			// transferInputPanel
			// 
			this->transferInputPanel->Controls->Add(this->accNumPanel);
			this->transferInputPanel->Controls->Add(this->nominalPanel);
			this->transferInputPanel->Controls->Add(this->btnWithdraw);
			this->transferInputPanel->Controls->Add(this->pinPanel);
			this->transferInputPanel->Location = System::Drawing::Point(76, 175);
			this->transferInputPanel->Name = L"transferInputPanel";
			this->transferInputPanel->Size = System::Drawing::Size(528, 474);
			this->transferInputPanel->TabIndex = 4;
			// 
			// btnWithdraw
			// 
			this->btnWithdraw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnWithdraw->FlatAppearance->BorderSize = 0;
			this->btnWithdraw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnWithdraw->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->btnWithdraw->Location = System::Drawing::Point(34, 380);
			this->btnWithdraw->Name = L"btnWithdraw";
			this->btnWithdraw->Size = System::Drawing::Size(210, 60);
			this->btnWithdraw->TabIndex = 38;
			this->btnWithdraw->Text = L"Tarik";
			this->btnWithdraw->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(4, 62);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(200, 5);
			this->panel4->TabIndex = 34;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(5, 62);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(450, 5);
			this->panel3->TabIndex = 33;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(5, 62);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(450, 5);
			this->panel7->TabIndex = 31;
			// 
			// pin
			// 
			this->pin->AutoSize = true;
			this->pin->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->pin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->pin->Location = System::Drawing::Point(3, 0);
			this->pin->Name = L"pin";
			this->pin->Size = System::Drawing::Size(38, 20);
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
			this->pinInput->Location = System::Drawing::Point(4, 31);
			this->pinInput->MaxLength = 15;
			this->pinInput->Name = L"pinInput";
			this->pinInput->Size = System::Drawing::Size(200, 20);
			this->pinInput->TabIndex = 26;
			this->pinInput->UseSystemPasswordChar = true;
			// 
			// nominalWithdraw
			// 
			this->nominalWithdraw->AutoSize = true;
			this->nominalWithdraw->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->nominalWithdraw->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->nominalWithdraw->Location = System::Drawing::Point(3, 0);
			this->nominalWithdraw->Name = L"nominalWithdraw";
			this->nominalWithdraw->Size = System::Drawing::Size(174, 20);
			this->nominalWithdraw->TabIndex = 25;
			this->nominalWithdraw->Text = L"Nominal Tarik Tunai";
			// 
			// nominalWithdrawInput
			// 
			this->nominalWithdrawInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->nominalWithdrawInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nominalWithdrawInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->nominalWithdrawInput->ForeColor = System::Drawing::Color::White;
			this->nominalWithdrawInput->Location = System::Drawing::Point(45, 31);
			this->nominalWithdrawInput->MaxLength = 100;
			this->nominalWithdrawInput->Name = L"nominalWithdrawInput";
			this->nominalWithdrawInput->Size = System::Drawing::Size(410, 20);
			this->nominalWithdrawInput->TabIndex = 24;
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(3, 0);
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
			this->customerAccInput->Location = System::Drawing::Point(5, 31);
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
			this->withdrw->Size = System::Drawing::Size(357, 70);
			this->withdrw->TabIndex = 3;
			this->withdrw->Text = L"Tarik Tunai";
			// 
			// accNumPanel
			// 
			this->accNumPanel->Controls->Add(this->customerAccInput);
			this->accNumPanel->Controls->Add(this->customerAccNum);
			this->accNumPanel->Controls->Add(this->panel7);
			this->accNumPanel->Location = System::Drawing::Point(34, 68);
			this->accNumPanel->Name = L"accNumPanel";
			this->accNumPanel->Size = System::Drawing::Size(460, 70);
			this->accNumPanel->TabIndex = 5;
			// 
			// pinPanel
			// 
			this->pinPanel->Controls->Add(this->pin);
			this->pinPanel->Controls->Add(this->panel4);
			this->pinPanel->Controls->Add(this->pinInput);
			this->pinPanel->Location = System::Drawing::Point(34, 276);
			this->pinPanel->Name = L"pinPanel";
			this->pinPanel->Size = System::Drawing::Size(210, 70);
			this->pinPanel->TabIndex = 6;
			// 
			// nominalPanel
			// 
			this->nominalPanel->Controls->Add(this->label2);
			this->nominalPanel->Controls->Add(this->nominalWithdrawInput);
			this->nominalPanel->Controls->Add(this->nominalWithdraw);
			this->nominalPanel->Controls->Add(this->panel3);
			this->nominalPanel->Location = System::Drawing::Point(34, 172);
			this->nominalPanel->Name = L"nominalPanel";
			this->nominalPanel->Size = System::Drawing::Size(460, 70);
			this->nominalPanel->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(4, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 20);
			this->label2->TabIndex = 35;
			this->label2->Text = L"Rp.";
			// 
			// Withdraw
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->withdrawMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Withdraw";
			this->Text = L"Withdraw";
			this->withdrawMainPanel->ResumeLayout(false);
			this->withdrawMainPanel->PerformLayout();
			this->transferInputPanel->ResumeLayout(false);
			this->accNumPanel->ResumeLayout(false);
			this->accNumPanel->PerformLayout();
			this->pinPanel->ResumeLayout(false);
			this->pinPanel->PerformLayout();
			this->nominalPanel->ResumeLayout(false);
			this->nominalPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
