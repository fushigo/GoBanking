#pragma once

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
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;



	private: System::Windows::Forms::Label^ pin;
	private: System::Windows::Forms::TextBox^ pinInput;



	private: System::Windows::Forms::Label^ nominal;
	private: System::Windows::Forms::TextBox^ nominalInput;




	private: System::Windows::Forms::Label^ recipientsAccNum;
	private: System::Windows::Forms::TextBox^ recipientsAccInput;
	private: System::Windows::Forms::Label^ customerAccNum;




	private: System::Windows::Forms::TextBox^ customerAccInput;



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
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->pin = (gcnew System::Windows::Forms::Label());
			this->pinInput = (gcnew System::Windows::Forms::TextBox());
			this->nominal = (gcnew System::Windows::Forms::Label());
			this->nominalInput = (gcnew System::Windows::Forms::TextBox());
			this->recipientsAccNum = (gcnew System::Windows::Forms::Label());
			this->recipientsAccInput = (gcnew System::Windows::Forms::TextBox());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->transferMainPanel->SuspendLayout();
			this->transferInputPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// transferMainPanel
			// 
			this->transferMainPanel->Controls->Add(this->transferInputPanel);
			this->transferMainPanel->Controls->Add(this->label1);
			this->transferMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->transferMainPanel->ForeColor = System::Drawing::Color::White;
			this->transferMainPanel->Location = System::Drawing::Point(350, 0);
			this->transferMainPanel->Name = L"transferMainPanel";
			this->transferMainPanel->Size = System::Drawing::Size(1050, 900);
			this->transferMainPanel->TabIndex = 0;
			// 
			// transferInputPanel
			// 
			this->transferInputPanel->Controls->Add(this->btnTransfer);
			this->transferInputPanel->Controls->Add(this->panel4);
			this->transferInputPanel->Controls->Add(this->panel3);
			this->transferInputPanel->Controls->Add(this->panel6);
			this->transferInputPanel->Controls->Add(this->panel7);
			this->transferInputPanel->Controls->Add(this->pin);
			this->transferInputPanel->Controls->Add(this->pinInput);
			this->transferInputPanel->Controls->Add(this->nominal);
			this->transferInputPanel->Controls->Add(this->nominalInput);
			this->transferInputPanel->Controls->Add(this->recipientsAccNum);
			this->transferInputPanel->Controls->Add(this->recipientsAccInput);
			this->transferInputPanel->Controls->Add(this->customerAccNum);
			this->transferInputPanel->Controls->Add(this->customerAccInput);
			this->transferInputPanel->Location = System::Drawing::Point(76, 175);
			this->transferInputPanel->Name = L"transferInputPanel";
			this->transferInputPanel->Size = System::Drawing::Size(500, 474);
			this->transferInputPanel->TabIndex = 2;
			// 
			// btnTransfer
			// 
			this->btnTransfer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnTransfer->FlatAppearance->BorderSize = 0;
			this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTransfer->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->btnTransfer->Location = System::Drawing::Point(27, 382);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Size = System::Drawing::Size(220, 60);
			this->btnTransfer->TabIndex = 38;
			this->btnTransfer->Text = L"Transfer";
			this->btnTransfer->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(27, 350);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(200, 5);
			this->panel4->TabIndex = 34;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(27, 272);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(450, 5);
			this->panel3->TabIndex = 33;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(27, 194);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(450, 5);
			this->panel6->TabIndex = 32;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(27, 116);
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
			this->pin->Location = System::Drawing::Point(23, 288);
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
			this->pinInput->Location = System::Drawing::Point(27, 319);
			this->pinInput->MaxLength = 15;
			this->pinInput->Name = L"pinInput";
			this->pinInput->Size = System::Drawing::Size(200, 20);
			this->pinInput->TabIndex = 26;
			this->pinInput->UseSystemPasswordChar = true;
			// 
			// nominal
			// 
			this->nominal->AutoSize = true;
			this->nominal->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->nominal->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->nominal->Location = System::Drawing::Point(23, 210);
			this->nominal->Name = L"nominal";
			this->nominal->Size = System::Drawing::Size(151, 20);
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
			this->nominalInput->Location = System::Drawing::Point(27, 241);
			this->nominalInput->MaxLength = 100;
			this->nominalInput->Name = L"nominalInput";
			this->nominalInput->Size = System::Drawing::Size(450, 20);
			this->nominalInput->TabIndex = 24;
			// 
			// recipientsAccNum
			// 
			this->recipientsAccNum->AutoSize = true;
			this->recipientsAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->recipientsAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->recipientsAccNum->Location = System::Drawing::Point(23, 132);
			this->recipientsAccNum->Name = L"recipientsAccNum";
			this->recipientsAccNum->Size = System::Drawing::Size(201, 20);
			this->recipientsAccNum->TabIndex = 23;
			this->recipientsAccNum->Text = L"No. Rekening Penerima";
			// 
			// recipientsAccInput
			// 
			this->recipientsAccInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->recipientsAccInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->recipientsAccInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->recipientsAccInput->ForeColor = System::Drawing::Color::White;
			this->recipientsAccInput->Location = System::Drawing::Point(27, 163);
			this->recipientsAccInput->MaxLength = 16;
			this->recipientsAccInput->Name = L"recipientsAccInput";
			this->recipientsAccInput->Size = System::Drawing::Size(450, 20);
			this->recipientsAccInput->TabIndex = 22;
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(23, 54);
			this->customerAccNum->Name = L"customerAccNum";
			this->customerAccNum->Size = System::Drawing::Size(197, 20);
			this->customerAccNum->TabIndex = 21;
			this->customerAccNum->Text = L"No. Rekening Pengirim";
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(64, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 70);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Transfer";
			// 
			// Transfer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->transferMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Transfer";
			this->Text = L"Transfer";
			this->transferMainPanel->ResumeLayout(false);
			this->transferMainPanel->PerformLayout();
			this->transferInputPanel->ResumeLayout(false);
			this->transferInputPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
