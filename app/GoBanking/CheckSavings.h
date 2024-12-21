#pragma once

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CheckSavings
	/// </summary>
	public ref class CheckSavings : public System::Windows::Forms::Form
	{
	public:
		CheckSavings(void)
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
		~CheckSavings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ checkSavingsMainPanel;
	private: System::Windows::Forms::Label^ checkSav;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ customerAccNum;
	private: System::Windows::Forms::TextBox^ customerAccInput;
	private: System::Windows::Forms::Button^ btnCheckSavings;

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
			this->checkSavingsMainPanel = (gcnew System::Windows::Forms::Panel());
			this->checkSav = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->btnCheckSavings = (gcnew System::Windows::Forms::Button());
			this->checkSavingsMainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkSavingsMainPanel
			// 
			this->checkSavingsMainPanel->Controls->Add(this->btnCheckSavings);
			this->checkSavingsMainPanel->Controls->Add(this->panel7);
			this->checkSavingsMainPanel->Controls->Add(this->customerAccNum);
			this->checkSavingsMainPanel->Controls->Add(this->customerAccInput);
			this->checkSavingsMainPanel->Controls->Add(this->checkSav);
			this->checkSavingsMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->checkSavingsMainPanel->ForeColor = System::Drawing::Color::White;
			this->checkSavingsMainPanel->Location = System::Drawing::Point(350, 0);
			this->checkSavingsMainPanel->Name = L"checkSavingsMainPanel";
			this->checkSavingsMainPanel->Size = System::Drawing::Size(1050, 900);
			this->checkSavingsMainPanel->TabIndex = 0;
			// 
			// checkSav
			// 
			this->checkSav->AutoSize = true;
			this->checkSav->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->checkSav->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkSav->Location = System::Drawing::Point(64, 60);
			this->checkSav->Name = L"checkSav";
			this->checkSav->Size = System::Drawing::Size(850, 70);
			this->checkSav->TabIndex = 6;
			this->checkSav->Text = L"Data dan Riwayat Tabungan";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(76, 244);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(450, 5);
			this->panel7->TabIndex = 34;
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(72, 182);
			this->customerAccNum->Name = L"customerAccNum";
			this->customerAccNum->Size = System::Drawing::Size(196, 20);
			this->customerAccNum->TabIndex = 33;
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
			this->customerAccInput->Location = System::Drawing::Point(76, 213);
			this->customerAccInput->MaxLength = 50;
			this->customerAccInput->Name = L"customerAccInput";
			this->customerAccInput->Size = System::Drawing::Size(450, 20);
			this->customerAccInput->TabIndex = 32;
			// 
			// btnCheckSavings
			// 
			this->btnCheckSavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnCheckSavings->FlatAppearance->BorderSize = 0;
			this->btnCheckSavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCheckSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnCheckSavings->Location = System::Drawing::Point(543, 199);
			this->btnCheckSavings->Name = L"btnCheckSavings";
			this->btnCheckSavings->Size = System::Drawing::Size(100, 50);
			this->btnCheckSavings->TabIndex = 39;
			this->btnCheckSavings->Text = L"Cek";
			this->btnCheckSavings->UseVisualStyleBackColor = false;
			// 
			// CheckSavings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->checkSavingsMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"CheckSavings";
			this->Text = L"CheckSavings";
			this->checkSavingsMainPanel->ResumeLayout(false);
			this->checkSavingsMainPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
