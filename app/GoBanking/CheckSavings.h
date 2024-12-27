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

	private:
		Timer^ fadeInTimer;
		Timer^ fadeOutTimer;
		double opacityIncrement;
		double opacityValue;
		System::Windows::Forms::Panel^ detailPanel;
	private: System::Windows::Forms::DataGridView^ dataGridViewDetail;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ activityType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ totalBalanceDetail;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ detailCreatedAt;
	private: System::Windows::Forms::Label^ label1;
		   System::Windows::Forms::Button^ btnCloseDetailPanel;


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
	private: System::Windows::Forms::DataGridView^ dataGridViewAccount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ accountNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ savingsType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ balanceTotal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ createdAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ updatedAt;
	private: System::Windows::Forms::DataGridViewButtonColumn^ details;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->checkSavingsMainPanel = (gcnew System::Windows::Forms::Panel());
			this->detailPanel = (gcnew System::Windows::Forms::Panel());
			this->btnCloseDetailPanel = (gcnew System::Windows::Forms::Button());
			this->dataGridViewAccount = (gcnew System::Windows::Forms::DataGridView());
			this->accountNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->savingsType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->balanceTotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->createdAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->updatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->details = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->btnCheckSavings = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->checkSav = (gcnew System::Windows::Forms::Label());
			this->dataGridViewDetail = (gcnew System::Windows::Forms::DataGridView());
			this->activityType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->totalBalanceDetail = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->detailCreatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkSavingsMainPanel->SuspendLayout();
			this->detailPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAccount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetail))->BeginInit();
			this->SuspendLayout();
			// 
			// checkSavingsMainPanel
			// 
			this->checkSavingsMainPanel->Controls->Add(this->detailPanel);
			this->checkSavingsMainPanel->Controls->Add(this->dataGridViewAccount);
			this->checkSavingsMainPanel->Controls->Add(this->btnCheckSavings);
			this->checkSavingsMainPanel->Controls->Add(this->panel7);
			this->checkSavingsMainPanel->Controls->Add(this->customerAccNum);
			this->checkSavingsMainPanel->Controls->Add(this->customerAccInput);
			this->checkSavingsMainPanel->Controls->Add(this->checkSav);
			this->checkSavingsMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->checkSavingsMainPanel->ForeColor = System::Drawing::Color::White;
			this->checkSavingsMainPanel->Location = System::Drawing::Point(310, 0);
			this->checkSavingsMainPanel->Name = L"checkSavingsMainPanel";
			this->checkSavingsMainPanel->Size = System::Drawing::Size(1090, 900);
			this->checkSavingsMainPanel->TabIndex = 0;
			// 
			// detailPanel
			// 
			this->detailPanel->Controls->Add(this->label1);
			this->detailPanel->Controls->Add(this->dataGridViewDetail);
			this->detailPanel->Controls->Add(this->btnCloseDetailPanel);
			this->detailPanel->Location = System::Drawing::Point(220, 299);
			this->detailPanel->Name = L"detailPanel";
			this->detailPanel->Size = System::Drawing::Size(650, 550);
			this->detailPanel->TabIndex = 1;
			// 
			// btnCloseDetailPanel
			// 
			this->btnCloseDetailPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnCloseDetailPanel->FlatAppearance->BorderSize = 0;
			this->btnCloseDetailPanel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCloseDetailPanel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnCloseDetailPanel->Location = System::Drawing::Point(3, 497);
			this->btnCloseDetailPanel->Name = L"btnCloseDetailPanel";
			this->btnCloseDetailPanel->Size = System::Drawing::Size(100, 50);
			this->btnCloseDetailPanel->TabIndex = 40;
			this->btnCloseDetailPanel->Text = L"Close";
			this->btnCloseDetailPanel->UseVisualStyleBackColor = false;
			this->btnCloseDetailPanel->Click += gcnew System::EventHandler(this, &CheckSavings::btnCloseDetailPanel_Click);
			// 
			// dataGridViewAccount
			// 
			this->dataGridViewAccount->AllowUserToOrderColumns = true;
			this->dataGridViewAccount->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewAccount->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle32->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle32->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle32->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle32->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle32->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle32->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle32->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewAccount->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle32;
			this->dataGridViewAccount->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAccount->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->accountNumber,
					this->savingsType, this->balanceTotal, this->createdAt, this->updatedAt, this->details
			});
			this->dataGridViewAccount->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridViewAccount->Location = System::Drawing::Point(52, 266);
			this->dataGridViewAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridViewAccount->Name = L"dataGridViewAccount";
			this->dataGridViewAccount->RowHeadersVisible = false;
			this->dataGridViewAccount->RowHeadersWidth = 51;
			dataGridViewCellStyle39->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle39->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle39->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle39->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle39->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle39->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle39->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewAccount->RowsDefaultCellStyle = dataGridViewCellStyle39;
			this->dataGridViewAccount->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewAccount->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dataGridViewAccount->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridViewAccount->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewAccount->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridViewAccount->RowTemplate->Height = 24;
			this->dataGridViewAccount->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewAccount->Size = System::Drawing::Size(987, 606);
			this->dataGridViewAccount->TabIndex = 40;
			this->dataGridViewAccount->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CheckSavings::dataGridViewAccount_CellContentClick);
			this->dataGridViewAccount->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &CheckSavings::dataGridViewAccount_CellFormatting);
			// 
			// accountNumber
			// 
			dataGridViewCellStyle33->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle33->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->accountNumber->DefaultCellStyle = dataGridViewCellStyle33;
			this->accountNumber->HeaderText = L"Nomor Rekening";
			this->accountNumber->MinimumWidth = 6;
			this->accountNumber->Name = L"accountNumber";
			this->accountNumber->Width = 125;
			// 
			// savingsType
			// 
			dataGridViewCellStyle34->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->savingsType->DefaultCellStyle = dataGridViewCellStyle34;
			this->savingsType->HeaderText = L"Jenis Tabungan";
			this->savingsType->MinimumWidth = 6;
			this->savingsType->Name = L"savingsType";
			this->savingsType->Width = 125;
			// 
			// balanceTotal
			// 
			dataGridViewCellStyle35->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->balanceTotal->DefaultCellStyle = dataGridViewCellStyle35;
			this->balanceTotal->HeaderText = L"Total Saldo";
			this->balanceTotal->MinimumWidth = 6;
			this->balanceTotal->Name = L"balanceTotal";
			this->balanceTotal->Width = 125;
			// 
			// createdAt
			// 
			dataGridViewCellStyle36->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->createdAt->DefaultCellStyle = dataGridViewCellStyle36;
			this->createdAt->HeaderText = L"Tgl. Dibuat";
			this->createdAt->MinimumWidth = 6;
			this->createdAt->Name = L"createdAt";
			this->createdAt->Width = 125;
			// 
			// updatedAt
			// 
			dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->updatedAt->DefaultCellStyle = dataGridViewCellStyle37;
			this->updatedAt->HeaderText = L"Tgl. Diubah";
			this->updatedAt->MinimumWidth = 6;
			this->updatedAt->Name = L"updatedAt";
			this->updatedAt->Width = 125;
			// 
			// details
			// 
			dataGridViewCellStyle38->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle38->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)));
			dataGridViewCellStyle38->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle38->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle38->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle38->SelectionForeColor = System::Drawing::Color::White;
			this->details->DefaultCellStyle = dataGridViewCellStyle38;
			this->details->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->details->HeaderText = L"Detail";
			this->details->MinimumWidth = 6;
			this->details->Name = L"details";
			this->details->Text = L"Detail";
			this->details->UseColumnTextForButtonValue = true;
			this->details->Width = 125;
			// 
			// btnCheckSavings
			// 
			this->btnCheckSavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnCheckSavings->FlatAppearance->BorderSize = 0;
			this->btnCheckSavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCheckSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnCheckSavings->Location = System::Drawing::Point(519, 195);
			this->btnCheckSavings->Name = L"btnCheckSavings";
			this->btnCheckSavings->Size = System::Drawing::Size(100, 50);
			this->btnCheckSavings->TabIndex = 39;
			this->btnCheckSavings->Text = L"Cek";
			this->btnCheckSavings->UseVisualStyleBackColor = false;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(52, 240);
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
			this->customerAccNum->Location = System::Drawing::Point(48, 178);
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
			this->customerAccInput->Location = System::Drawing::Point(52, 209);
			this->customerAccInput->MaxLength = 50;
			this->customerAccInput->Name = L"customerAccInput";
			this->customerAccInput->Size = System::Drawing::Size(450, 20);
			this->customerAccInput->TabIndex = 32;
			// 
			// checkSav
			// 
			this->checkSav->AutoSize = true;
			this->checkSav->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->checkSav->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkSav->Location = System::Drawing::Point(40, 63);
			this->checkSav->Name = L"checkSav";
			this->checkSav->Size = System::Drawing::Size(850, 70);
			this->checkSav->TabIndex = 6;
			this->checkSav->Text = L"Data dan Riwayat Tabungan";
			// 
			// dataGridViewDetail
			// 
			this->dataGridViewDetail->AllowUserToOrderColumns = true;
			this->dataGridViewDetail->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewDetail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle27->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle27->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle27->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle27->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewDetail->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle27;
			this->dataGridViewDetail->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDetail->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->activityType,
					this->totalBalanceDetail, this->detailCreatedAt
			});
			this->dataGridViewDetail->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridViewDetail->Location = System::Drawing::Point(25, 138);
			this->dataGridViewDetail->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridViewDetail->Name = L"dataGridViewDetail";
			this->dataGridViewDetail->RowHeadersVisible = false;
			this->dataGridViewDetail->RowHeadersWidth = 51;
			dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle31->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle31->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle31->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle31->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle31->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewDetail->RowsDefaultCellStyle = dataGridViewCellStyle31;
			this->dataGridViewDetail->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewDetail->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dataGridViewDetail->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridViewDetail->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewDetail->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridViewDetail->RowTemplate->Height = 24;
			this->dataGridViewDetail->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewDetail->Size = System::Drawing::Size(600, 300);
			this->dataGridViewDetail->TabIndex = 41;
			// 
			// activityType
			// 
			dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->activityType->DefaultCellStyle = dataGridViewCellStyle28;
			this->activityType->HeaderText = L"Jenis Aktivitas";
			this->activityType->MinimumWidth = 6;
			this->activityType->Name = L"activityType";
			this->activityType->Width = 125;
			// 
			// totalBalanceDetail
			// 
			dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->totalBalanceDetail->DefaultCellStyle = dataGridViewCellStyle29;
			this->totalBalanceDetail->HeaderText = L"Jumlah Dana";
			this->totalBalanceDetail->MinimumWidth = 6;
			this->totalBalanceDetail->Name = L"totalBalanceDetail";
			this->totalBalanceDetail->Width = 125;
			// 
			// detailCreatedAt
			// 
			dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->detailCreatedAt->DefaultCellStyle = dataGridViewCellStyle30;
			this->detailCreatedAt->HeaderText = L"Tgl. Dibuat";
			this->detailCreatedAt->MinimumWidth = 6;
			this->detailCreatedAt->Name = L"detailCreatedAt";
			this->detailCreatedAt->Width = 125;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(19, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 32);
			this->label1->TabIndex = 41;
			this->label1->Text = L"Detail Data";
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
			this->Load += gcnew System::EventHandler(this, &CheckSavings::CheckSavings_Load);
			this->checkSavingsMainPanel->ResumeLayout(false);
			this->checkSavingsMainPanel->PerformLayout();
			this->detailPanel->ResumeLayout(false);
			this->detailPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAccount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetail))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// ==================================== Detail Panel ===================================================
		private: System::Void CheckSavings_Load(System::Object^ sender, System::EventArgs^ e) {
			detailPanel->Visible = false;
			detailPanel->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);

			opacityValue = 0.0;
			opacityIncrement = 0.03; // Slower transition for more visible effect

			fadeInTimer = gcnew Timer();
			fadeInTimer->Interval = 10; // Faster timer interval for smoother animation

			fadeOutTimer = gcnew Timer();
			fadeOutTimer->Interval = 10;

			fadeInTimer->Tick += gcnew EventHandler(this, &CheckSavings::FadeIn);
			fadeOutTimer->Tick += gcnew EventHandler(this, &CheckSavings::FadeOut);

			dataGridViewAccount->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &CheckSavings::dataGridViewAccount_CellFormatting);

		}
		private: 

			System::Void dataGridViewAccount_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e) {
				if (e->ColumnIndex == dataGridViewAccount->Columns["details"]->Index) {
					DataGridViewButtonCell^ buttonCell = safe_cast<DataGridViewButtonCell^>(dataGridViewAccount->Rows[e->RowIndex]->Cells[e->ColumnIndex]);

					// Check if the account number cell has value
					if (dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
						!String::IsNullOrEmpty(dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value->ToString())) {
						buttonCell->FlatStyle = FlatStyle::Flat;
						buttonCell->Style->BackColor = System::Drawing::Color::FromArgb(43, 39, 56);
						buttonCell->Style->ForeColor = System::Drawing::Color::White;
						buttonCell->Style->SelectionBackColor = System::Drawing::Color::FromArgb(43, 39, 56);
						buttonCell->Style->SelectionForeColor = System::Drawing::Color::White;
					}
				}
			}

			System::Void dataGridViewAccount_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
				if (e->ColumnIndex == dataGridViewAccount->Columns["details"]->Index) {
					// Check if the row has data before processing the click
					if (dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
						!String::IsNullOrEmpty(dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value->ToString())) {
						detailPanel->Visible = true;
						opacityValue = 0.0;
						fadeInTimer->Start();
					}
				}
			}

			System::Void FadeIn(System::Object^ sender, System::EventArgs^ e) {
				if (opacityValue < 1.0) {
					opacityValue += opacityIncrement;
					int alpha = Math::Min(255, Math::Max(0, static_cast<int>(opacityValue * 255)));
					detailPanel->BackColor = System::Drawing::Color::FromArgb(alpha, 43, 39, 56);
					detailPanel->Refresh();
				}
				else {
					opacityValue = 1.0;
					fadeInTimer->Stop();
				}
			}

			System::Void FadeOut(System::Object^ sender, System::EventArgs^ e) {
				if (opacityValue > 0.0) {
					opacityValue -= opacityIncrement;
					int alpha = Math::Min(255, Math::Max(0, static_cast<int>(opacityValue * 255)));
					detailPanel->BackColor = System::Drawing::Color::FromArgb(alpha, 43, 39, 56);
					detailPanel->Refresh();
				}
				else {
					opacityValue = 0.0;
					fadeOutTimer->Stop();
					detailPanel->Visible = false;
				}
			}

			System::Void btnCloseDetailPanel_Click(System::Object^ sender, System::EventArgs^ e) {
				detailPanel->Visible = false; // Immediately hide the panel
				// Prevent multiple clicks during animation
			}
			// ==================================== Detail Panel End ===================================================
};
}
