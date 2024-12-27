#pragma once

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OpenRek
	/// </summary>
	public ref class OpenRek : public System::Windows::Forms::Form
	{
	public:
		OpenRek(void)
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
		~OpenRek()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ openrekMainPanel;
	protected:

	private: System::Windows::Forms::Label^ openrekHeadingLabel;
	private: System::Windows::Forms::Panel^ openrekInputPanel;

	private: System::Windows::Forms::Button^ btnOpenRek;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ address;
	private: System::Windows::Forms::TextBox^ addressInput;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ gender;
	private: System::Windows::Forms::RadioButton^ femaleRadButton;
	private: System::Windows::Forms::RadioButton^ maleRadButton;
	private: System::Windows::Forms::Label^ phonenumber;
	private: System::Windows::Forms::TextBox^ phoneNumberInput;
	private: System::Windows::Forms::Label^ email;
	private: System::Windows::Forms::TextBox^ emailInput;
	private: System::Windows::Forms::Label^ nik;
	private: System::Windows::Forms::TextBox^ nikInput;
	private: System::Windows::Forms::Label^ fullname;
	private: System::Windows::Forms::TextBox^ fullnameInput;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ pin;
	private: System::Windows::Forms::TextBox^ pinInput;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ deposit;

	private: System::Windows::Forms::TextBox^ depositoInput;

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
			this->openrekMainPanel = (gcnew System::Windows::Forms::Panel());
			this->openrekInputPanel = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->deposit = (gcnew System::Windows::Forms::Label());
			this->depositoInput = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pin = (gcnew System::Windows::Forms::Label());
			this->pinInput = (gcnew System::Windows::Forms::TextBox());
			this->btnOpenRek = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->address = (gcnew System::Windows::Forms::Label());
			this->addressInput = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->gender = (gcnew System::Windows::Forms::Label());
			this->femaleRadButton = (gcnew System::Windows::Forms::RadioButton());
			this->maleRadButton = (gcnew System::Windows::Forms::RadioButton());
			this->phonenumber = (gcnew System::Windows::Forms::Label());
			this->phoneNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::Label());
			this->emailInput = (gcnew System::Windows::Forms::TextBox());
			this->nik = (gcnew System::Windows::Forms::Label());
			this->nikInput = (gcnew System::Windows::Forms::TextBox());
			this->fullname = (gcnew System::Windows::Forms::Label());
			this->fullnameInput = (gcnew System::Windows::Forms::TextBox());
			this->openrekHeadingLabel = (gcnew System::Windows::Forms::Label());
			this->openrekMainPanel->SuspendLayout();
			this->openrekInputPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// openrekMainPanel
			// 
			this->openrekMainPanel->Controls->Add(this->openrekInputPanel);
			this->openrekMainPanel->Controls->Add(this->openrekHeadingLabel);
			this->openrekMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->openrekMainPanel->ForeColor = System::Drawing::Color::White;
			this->openrekMainPanel->Location = System::Drawing::Point(310, 0);
			this->openrekMainPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->openrekMainPanel->Name = L"openrekMainPanel";
			this->openrekMainPanel->Size = System::Drawing::Size(1090, 900);
			this->openrekMainPanel->TabIndex = 0;
			// 
			// openrekInputPanel
			// 
			this->openrekInputPanel->Controls->Add(this->panel7);
			this->openrekInputPanel->Controls->Add(this->deposit);
			this->openrekInputPanel->Controls->Add(this->depositoInput);
			this->openrekInputPanel->Controls->Add(this->panel1);
			this->openrekInputPanel->Controls->Add(this->pin);
			this->openrekInputPanel->Controls->Add(this->pinInput);
			this->openrekInputPanel->Controls->Add(this->btnOpenRek);
			this->openrekInputPanel->Controls->Add(this->panel5);
			this->openrekInputPanel->Controls->Add(this->address);
			this->openrekInputPanel->Controls->Add(this->addressInput);
			this->openrekInputPanel->Controls->Add(this->panel4);
			this->openrekInputPanel->Controls->Add(this->panel3);
			this->openrekInputPanel->Controls->Add(this->panel2);
			this->openrekInputPanel->Controls->Add(this->panel6);
			this->openrekInputPanel->Controls->Add(this->gender);
			this->openrekInputPanel->Controls->Add(this->femaleRadButton);
			this->openrekInputPanel->Controls->Add(this->maleRadButton);
			this->openrekInputPanel->Controls->Add(this->phonenumber);
			this->openrekInputPanel->Controls->Add(this->phoneNumberInput);
			this->openrekInputPanel->Controls->Add(this->email);
			this->openrekInputPanel->Controls->Add(this->emailInput);
			this->openrekInputPanel->Controls->Add(this->nik);
			this->openrekInputPanel->Controls->Add(this->nikInput);
			this->openrekInputPanel->Controls->Add(this->fullname);
			this->openrekInputPanel->Controls->Add(this->fullnameInput);
			this->openrekInputPanel->Location = System::Drawing::Point(71, 175);
			this->openrekInputPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->openrekInputPanel->Name = L"openrekInputPanel";
			this->openrekInputPanel->Size = System::Drawing::Size(949, 674);
			this->openrekInputPanel->TabIndex = 1;
			this->openrekInputPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &OpenRek::openrekInputPanel_Paint);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(521, 116);
			this->panel7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(300, 5);
			this->panel7->TabIndex = 44;
			// 
			// deposit
			// 
			this->deposit->AutoSize = true;
			this->deposit->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->deposit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->deposit->Location = System::Drawing::Point(517, 54);
			this->deposit->Name = L"deposit";
			this->deposit->Size = System::Drawing::Size(118, 20);
			this->deposit->TabIndex = 43;
			this->deposit->Text = L"Deposit Awal";
			// 
			// depositoInput
			// 
			this->depositoInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->depositoInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->depositoInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->depositoInput->ForeColor = System::Drawing::Color::White;
			this->depositoInput->Location = System::Drawing::Point(521, 85);
			this->depositoInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->depositoInput->MaxLength = 50;
			this->depositoInput->Name = L"depositoInput";
			this->depositoInput->Size = System::Drawing::Size(300, 20);
			this->depositoInput->TabIndex = 42;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(521, 194);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 5);
			this->panel1->TabIndex = 41;
			// 
			// pin
			// 
			this->pin->AutoSize = true;
			this->pin->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->pin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->pin->Location = System::Drawing::Point(517, 132);
			this->pin->Name = L"pin";
			this->pin->Size = System::Drawing::Size(162, 20);
			this->pin->TabIndex = 40;
			this->pin->Text = L"Buat PIN Rekening";
			// 
			// pinInput
			// 
			this->pinInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->pinInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->pinInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pinInput->ForeColor = System::Drawing::Color::White;
			this->pinInput->Location = System::Drawing::Point(521, 162);
			this->pinInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pinInput->MaxLength = 15;
			this->pinInput->Name = L"pinInput";
			this->pinInput->Size = System::Drawing::Size(200, 20);
			this->pinInput->TabIndex = 39;
			// 
			// btnOpenRek
			// 
			this->btnOpenRek->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnOpenRek->FlatAppearance->BorderSize = 0;
			this->btnOpenRek->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOpenRek->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->btnOpenRek->Location = System::Drawing::Point(27, 560);
			this->btnOpenRek->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnOpenRek->Name = L"btnOpenRek";
			this->btnOpenRek->Size = System::Drawing::Size(220, 60);
			this->btnOpenRek->TabIndex = 38;
			this->btnOpenRek->Text = L"Buka Rekening";
			this->btnOpenRek->UseVisualStyleBackColor = false;
			this->btnOpenRek->Click += gcnew System::EventHandler(this, &OpenRek::btnOpenRek_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->Location = System::Drawing::Point(27, 498);
			this->panel5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(451, 5);
			this->panel5->TabIndex = 37;
			// 
			// address
			// 
			this->address->AutoSize = true;
			this->address->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->address->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->address->Location = System::Drawing::Point(23, 436);
			this->address->Name = L"address";
			this->address->Size = System::Drawing::Size(67, 20);
			this->address->TabIndex = 36;
			this->address->Text = L"Alamat";
			// 
			// addressInput
			// 
			this->addressInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->addressInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->addressInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addressInput->ForeColor = System::Drawing::Color::White;
			this->addressInput->Location = System::Drawing::Point(27, 466);
			this->addressInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addressInput->MaxLength = 100;
			this->addressInput->Name = L"addressInput";
			this->addressInput->Size = System::Drawing::Size(451, 20);
			this->addressInput->TabIndex = 35;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(27, 350);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(251, 5);
			this->panel4->TabIndex = 34;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(27, 272);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(300, 5);
			this->panel3->TabIndex = 33;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(27, 194);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(451, 5);
			this->panel2->TabIndex = 32;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(27, 116);
			this->panel6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(451, 5);
			this->panel6->TabIndex = 31;
			// 
			// gender
			// 
			this->gender->AutoSize = true;
			this->gender->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->gender->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->gender->Location = System::Drawing::Point(23, 366);
			this->gender->Name = L"gender";
			this->gender->Size = System::Drawing::Size(125, 20);
			this->gender->TabIndex = 30;
			this->gender->Text = L"Jenis Kelamin";
			// 
			// femaleRadButton
			// 
			this->femaleRadButton->AutoSize = true;
			this->femaleRadButton->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->femaleRadButton->Location = System::Drawing::Point(143, 398);
			this->femaleRadButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->femaleRadButton->Name = L"femaleRadButton";
			this->femaleRadButton->Size = System::Drawing::Size(103, 19);
			this->femaleRadButton->TabIndex = 29;
			this->femaleRadButton->TabStop = true;
			this->femaleRadButton->Text = L"Perempuan";
			this->femaleRadButton->UseVisualStyleBackColor = true;
			// 
			// maleRadButton
			// 
			this->maleRadButton->AutoSize = true;
			this->maleRadButton->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maleRadButton->Location = System::Drawing::Point(27, 398);
			this->maleRadButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->maleRadButton->Name = L"maleRadButton";
			this->maleRadButton->Size = System::Drawing::Size(82, 19);
			this->maleRadButton->TabIndex = 28;
			this->maleRadButton->TabStop = true;
			this->maleRadButton->Text = L"Laki-laki";
			this->maleRadButton->UseVisualStyleBackColor = true;
			// 
			// phonenumber
			// 
			this->phonenumber->AutoSize = true;
			this->phonenumber->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->phonenumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->phonenumber->Location = System::Drawing::Point(23, 288);
			this->phonenumber->Name = L"phonenumber";
			this->phonenumber->Size = System::Drawing::Size(135, 20);
			this->phonenumber->TabIndex = 27;
			this->phonenumber->Text = L"Nomor Telepon";
			// 
			// phoneNumberInput
			// 
			this->phoneNumberInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->phoneNumberInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->phoneNumberInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->phoneNumberInput->ForeColor = System::Drawing::Color::White;
			this->phoneNumberInput->Location = System::Drawing::Point(27, 319);
			this->phoneNumberInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->phoneNumberInput->MaxLength = 15;
			this->phoneNumberInput->Name = L"phoneNumberInput";
			this->phoneNumberInput->Size = System::Drawing::Size(251, 20);
			this->phoneNumberInput->TabIndex = 26;
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->email->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->email->Location = System::Drawing::Point(23, 210);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(55, 20);
			this->email->TabIndex = 25;
			this->email->Text = L"Email";
			// 
			// emailInput
			// 
			this->emailInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->emailInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->emailInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->emailInput->ForeColor = System::Drawing::Color::White;
			this->emailInput->Location = System::Drawing::Point(27, 241);
			this->emailInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->emailInput->MaxLength = 100;
			this->emailInput->Name = L"emailInput";
			this->emailInput->Size = System::Drawing::Size(300, 20);
			this->emailInput->TabIndex = 24;
			// 
			// nik
			// 
			this->nik->AutoSize = true;
			this->nik->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->nik->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->nik->Location = System::Drawing::Point(23, 132);
			this->nik->Name = L"nik";
			this->nik->Size = System::Drawing::Size(40, 20);
			this->nik->TabIndex = 23;
			this->nik->Text = L"NIK";
			// 
			// nikInput
			// 
			this->nikInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->nikInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nikInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nikInput->ForeColor = System::Drawing::Color::White;
			this->nikInput->Location = System::Drawing::Point(27, 162);
			this->nikInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->nikInput->MaxLength = 16;
			this->nikInput->Name = L"nikInput";
			this->nikInput->Size = System::Drawing::Size(451, 20);
			this->nikInput->TabIndex = 22;
			// 
			// fullname
			// 
			this->fullname->AutoSize = true;
			this->fullname->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->fullname->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->fullname->Location = System::Drawing::Point(23, 54);
			this->fullname->Name = L"fullname";
			this->fullname->Size = System::Drawing::Size(133, 20);
			this->fullname->TabIndex = 21;
			this->fullname->Text = L"Nama Lengkap";
			// 
			// fullnameInput
			// 
			this->fullnameInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->fullnameInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->fullnameInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fullnameInput->ForeColor = System::Drawing::Color::White;
			this->fullnameInput->Location = System::Drawing::Point(27, 85);
			this->fullnameInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->fullnameInput->MaxLength = 50;
			this->fullnameInput->Name = L"fullnameInput";
			this->fullnameInput->Size = System::Drawing::Size(451, 20);
			this->fullnameInput->TabIndex = 20;
			this->fullnameInput->TextChanged += gcnew System::EventHandler(this, &OpenRek::fullnameInput_TextChanged);
			// 
			// openrekHeadingLabel
			// 
			this->openrekHeadingLabel->AutoSize = true;
			this->openrekHeadingLabel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->openrekHeadingLabel->Location = System::Drawing::Point(59, 61);
			this->openrekHeadingLabel->Name = L"openrekHeadingLabel";
			this->openrekHeadingLabel->Size = System::Drawing::Size(807, 70);
			this->openrekHeadingLabel->TabIndex = 0;
			this->openrekHeadingLabel->Text = L"Buka Rekening GoBanking";
			// 
			// OpenRek
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->openrekMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"OpenRek";
			this->Text = L"OpenRek";
			this->openrekMainPanel->ResumeLayout(false);
			this->openrekMainPanel->PerformLayout();
			this->openrekInputPanel->ResumeLayout(false);
			this->openrekInputPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void openrekInputPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: 
		System::Void fullnameInput_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnOpenRek_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
