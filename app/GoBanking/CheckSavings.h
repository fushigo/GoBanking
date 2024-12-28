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








	private: System::Windows::Forms::TextBox^ checkSavingsSearchBar;
	private: System::Windows::Forms::Button^ btnSearchCheckSavings;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ accountNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ savingsType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ jumlahSaldo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ bunga;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ totalSaldo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ createdAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ updatedAt;
	private: System::Windows::Forms::DataGridViewButtonColumn^ details;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CheckSavings::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->checkSavingsMainPanel = (gcnew System::Windows::Forms::Panel());
			this->checkSavingsSearchBar = (gcnew System::Windows::Forms::TextBox());
			this->btnSearchCheckSavings = (gcnew System::Windows::Forms::Button());
			this->detailPanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewDetail = (gcnew System::Windows::Forms::DataGridView());
			this->activityType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->totalBalanceDetail = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->detailCreatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnCloseDetailPanel = (gcnew System::Windows::Forms::Button());
			this->dataGridViewAccount = (gcnew System::Windows::Forms::DataGridView());
			this->btnCheckSavings = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->customerAccNum = (gcnew System::Windows::Forms::Label());
			this->customerAccInput = (gcnew System::Windows::Forms::TextBox());
			this->checkSav = (gcnew System::Windows::Forms::Label());
			this->accountNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->savingsType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->jumlahSaldo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bunga = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->totalSaldo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->createdAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->updatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->details = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->checkSavingsMainPanel->SuspendLayout();
			this->detailPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetail))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAccount))->BeginInit();
			this->SuspendLayout();
			// 
			// checkSavingsMainPanel
			// 
			this->checkSavingsMainPanel->AutoScroll = true;
			this->checkSavingsMainPanel->Controls->Add(this->checkSavingsSearchBar);
			this->checkSavingsMainPanel->Controls->Add(this->btnSearchCheckSavings);
			this->checkSavingsMainPanel->Controls->Add(this->detailPanel);
			this->checkSavingsMainPanel->Controls->Add(this->dataGridViewAccount);
			this->checkSavingsMainPanel->Controls->Add(this->btnCheckSavings);
			this->checkSavingsMainPanel->Controls->Add(this->panel7);
			this->checkSavingsMainPanel->Controls->Add(this->customerAccNum);
			this->checkSavingsMainPanel->Controls->Add(this->customerAccInput);
			this->checkSavingsMainPanel->Controls->Add(this->checkSav);
			this->checkSavingsMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->checkSavingsMainPanel->ForeColor = System::Drawing::Color::White;
			this->checkSavingsMainPanel->Location = System::Drawing::Point(222, 0);
			this->checkSavingsMainPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkSavingsMainPanel->Name = L"checkSavingsMainPanel";
			this->checkSavingsMainPanel->Size = System::Drawing::Size(818, 640);
			this->checkSavingsMainPanel->TabIndex = 0;
			// 
			// checkSavingsSearchBar
			// 
			this->checkSavingsSearchBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->checkSavingsSearchBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->checkSavingsSearchBar->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->checkSavingsSearchBar->ForeColor = System::Drawing::Color::White;
			this->checkSavingsSearchBar->Location = System::Drawing::Point(526, 176);
			this->checkSavingsSearchBar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->checkSavingsSearchBar->MaxLength = 255;
			this->checkSavingsSearchBar->Name = L"checkSavingsSearchBar";
			this->checkSavingsSearchBar->Size = System::Drawing::Size(226, 23);
			this->checkSavingsSearchBar->TabIndex = 41;
			// 
			// btnSearchCheckSavings
			// 
			this->btnSearchCheckSavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnSearchCheckSavings->FlatAppearance->BorderSize = 0;
			this->btnSearchCheckSavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSearchCheckSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSearchCheckSavings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSearchCheckSavings.Image")));
			this->btnSearchCheckSavings->Location = System::Drawing::Point(749, 176);
			this->btnSearchCheckSavings->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnSearchCheckSavings->Name = L"btnSearchCheckSavings";
			this->btnSearchCheckSavings->Size = System::Drawing::Size(30, 22);
			this->btnSearchCheckSavings->TabIndex = 42;
			this->btnSearchCheckSavings->UseVisualStyleBackColor = false;
			// 
			// detailPanel
			// 
			this->detailPanel->Controls->Add(this->label1);
			this->detailPanel->Controls->Add(this->dataGridViewDetail);
			this->detailPanel->Controls->Add(this->btnCloseDetailPanel);
			this->detailPanel->Location = System::Drawing::Point(165, 243);
			this->detailPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->detailPanel->Name = L"detailPanel";
			this->detailPanel->Size = System::Drawing::Size(488, 447);
			this->detailPanel->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(14, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 26);
			this->label1->TabIndex = 41;
			this->label1->Text = L"Detail Data";
			// 
			// dataGridViewDetail
			// 
			this->dataGridViewDetail->AllowUserToOrderColumns = true;
			this->dataGridViewDetail->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewDetail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle22->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle22->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle22->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle22->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle22->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle22->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle22->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewDetail->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle22;
			this->dataGridViewDetail->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDetail->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->activityType,
					this->totalBalanceDetail, this->detailCreatedAt
			});
			this->dataGridViewDetail->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridViewDetail->Location = System::Drawing::Point(19, 112);
			this->dataGridViewDetail->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridViewDetail->Name = L"dataGridViewDetail";
			this->dataGridViewDetail->RowHeadersVisible = false;
			this->dataGridViewDetail->RowHeadersWidth = 51;
			dataGridViewCellStyle26->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle26->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle26->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle26->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle26->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle26->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle26->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewDetail->RowsDefaultCellStyle = dataGridViewCellStyle26;
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
			this->dataGridViewDetail->Size = System::Drawing::Size(450, 244);
			this->dataGridViewDetail->TabIndex = 41;
			// 
			// activityType
			// 
			dataGridViewCellStyle23->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->activityType->DefaultCellStyle = dataGridViewCellStyle23;
			this->activityType->HeaderText = L"Jenis Aktivitas";
			this->activityType->MinimumWidth = 6;
			this->activityType->Name = L"activityType";
			this->activityType->Width = 125;
			// 
			// totalBalanceDetail
			// 
			dataGridViewCellStyle24->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->totalBalanceDetail->DefaultCellStyle = dataGridViewCellStyle24;
			this->totalBalanceDetail->HeaderText = L"Jumlah Dana";
			this->totalBalanceDetail->MinimumWidth = 6;
			this->totalBalanceDetail->Name = L"totalBalanceDetail";
			this->totalBalanceDetail->Width = 125;
			// 
			// detailCreatedAt
			// 
			dataGridViewCellStyle25->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->detailCreatedAt->DefaultCellStyle = dataGridViewCellStyle25;
			this->detailCreatedAt->HeaderText = L"Tgl. Dibuat";
			this->detailCreatedAt->MinimumWidth = 6;
			this->detailCreatedAt->Name = L"detailCreatedAt";
			this->detailCreatedAt->Width = 125;
			// 
			// btnCloseDetailPanel
			// 
			this->btnCloseDetailPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnCloseDetailPanel->FlatAppearance->BorderSize = 0;
			this->btnCloseDetailPanel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCloseDetailPanel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnCloseDetailPanel->Location = System::Drawing::Point(2, 404);
			this->btnCloseDetailPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCloseDetailPanel->Name = L"btnCloseDetailPanel";
			this->btnCloseDetailPanel->Size = System::Drawing::Size(75, 41);
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
			dataGridViewCellStyle14->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle14->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle14->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle14->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle14->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle14->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewAccount->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle14;
			this->dataGridViewAccount->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAccount->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->accountNumber,
					this->savingsType, this->jumlahSaldo, this->bunga, this->totalSaldo, this->createdAt, this->updatedAt, this->details
			});
			this->dataGridViewAccount->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridViewAccount->Location = System::Drawing::Point(39, 216);
			this->dataGridViewAccount->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridViewAccount->Name = L"dataGridViewAccount";
			this->dataGridViewAccount->RowHeadersVisible = false;
			this->dataGridViewAccount->RowHeadersWidth = 51;
			dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle21->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle21->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle21->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle21->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewAccount->RowsDefaultCellStyle = dataGridViewCellStyle21;
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
			this->dataGridViewAccount->Size = System::Drawing::Size(740, 492);
			this->dataGridViewAccount->TabIndex = 40;
			this->dataGridViewAccount->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CheckSavings::dataGridViewAccount_CellContentClick);
			this->dataGridViewAccount->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &CheckSavings::dataGridViewAccount_CellFormatting);
			// 
			// btnCheckSavings
			// 
			this->btnCheckSavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnCheckSavings->FlatAppearance->BorderSize = 0;
			this->btnCheckSavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCheckSavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnCheckSavings->Location = System::Drawing::Point(389, 158);
			this->btnCheckSavings->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCheckSavings->Name = L"btnCheckSavings";
			this->btnCheckSavings->Size = System::Drawing::Size(75, 41);
			this->btnCheckSavings->TabIndex = 39;
			this->btnCheckSavings->Text = L"Cek";
			this->btnCheckSavings->UseVisualStyleBackColor = false;
			this->btnCheckSavings->Click += gcnew System::EventHandler(this, &CheckSavings::btnCheckSavings_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Location = System::Drawing::Point(39, 195);
			this->panel7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(338, 4);
			this->panel7->TabIndex = 34;
			// 
			// customerAccNum
			// 
			this->customerAccNum->AutoSize = true;
			this->customerAccNum->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->customerAccNum->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->customerAccNum->Location = System::Drawing::Point(36, 145);
			this->customerAccNum->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->customerAccNum->Name = L"customerAccNum";
			this->customerAccNum->Size = System::Drawing::Size(157, 16);
			this->customerAccNum->TabIndex = 33;
			this->customerAccNum->Text = L"No. Identitas Nasabah";
			// 
			// customerAccInput
			// 
			this->customerAccInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->customerAccInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->customerAccInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->customerAccInput->ForeColor = System::Drawing::Color::White;
			this->customerAccInput->Location = System::Drawing::Point(39, 170);
			this->customerAccInput->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->customerAccInput->MaxLength = 50;
			this->customerAccInput->Name = L"customerAccInput";
			this->customerAccInput->Size = System::Drawing::Size(338, 16);
			this->customerAccInput->TabIndex = 32;
			this->customerAccInput->TextChanged += gcnew System::EventHandler(this, &CheckSavings::customerAccInput_TextChanged);
			// 
			// checkSav
			// 
			this->checkSav->AutoSize = true;
			this->checkSav->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->checkSav->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkSav->Location = System::Drawing::Point(30, 51);
			this->checkSav->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->checkSav->Name = L"checkSav";
			this->checkSav->Size = System::Drawing::Size(682, 55);
			this->checkSav->TabIndex = 6;
			this->checkSav->Text = L"Data dan Riwayat Tabungan";
			// 
			// accountNumber
			// 
			dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->accountNumber->DefaultCellStyle = dataGridViewCellStyle15;
			this->accountNumber->HeaderText = L"Nomor Rekening";
			this->accountNumber->MinimumWidth = 6;
			this->accountNumber->Name = L"accountNumber";
			this->accountNumber->ReadOnly = true;
			this->accountNumber->Width = 125;
			// 
			// savingsType
			// 
			dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->savingsType->DefaultCellStyle = dataGridViewCellStyle16;
			this->savingsType->HeaderText = L"Jenis Tabungan";
			this->savingsType->MinimumWidth = 6;
			this->savingsType->Name = L"savingsType";
			this->savingsType->Width = 125;
			// 
			// jumlahSaldo
			// 
			dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->jumlahSaldo->DefaultCellStyle = dataGridViewCellStyle17;
			this->jumlahSaldo->HeaderText = L"Jumlah Saldo";
			this->jumlahSaldo->MinimumWidth = 6;
			this->jumlahSaldo->Name = L"jumlahSaldo";
			this->jumlahSaldo->Width = 125;
			// 
			// bunga
			// 
			this->bunga->HeaderText = L"Bunga Didapat";
			this->bunga->MinimumWidth = 6;
			this->bunga->Name = L"bunga";
			this->bunga->Width = 125;
			// 
			// totalSaldo
			// 
			this->totalSaldo->HeaderText = L"Total Saldo";
			this->totalSaldo->MinimumWidth = 6;
			this->totalSaldo->Name = L"totalSaldo";
			this->totalSaldo->Width = 125;
			// 
			// createdAt
			// 
			dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->createdAt->DefaultCellStyle = dataGridViewCellStyle18;
			this->createdAt->HeaderText = L"Tgl. Dibuat";
			this->createdAt->MinimumWidth = 6;
			this->createdAt->Name = L"createdAt";
			this->createdAt->Width = 125;
			// 
			// updatedAt
			// 
			dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->updatedAt->DefaultCellStyle = dataGridViewCellStyle19;
			this->updatedAt->HeaderText = L"Tgl. Diubah";
			this->updatedAt->MinimumWidth = 6;
			this->updatedAt->Name = L"updatedAt";
			this->updatedAt->Width = 125;
			// 
			// details
			// 
			dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle20->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(56)));
			dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle20->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::White;
			this->details->DefaultCellStyle = dataGridViewCellStyle20;
			this->details->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->details->HeaderText = L"Detail";
			this->details->MinimumWidth = 6;
			this->details->Name = L"details";
			this->details->Text = L"Detail";
			this->details->UseColumnTextForButtonValue = true;
			this->details->Width = 125;
			// 
			// CheckSavings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1040, 640);
			this->Controls->Add(this->checkSavingsMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"CheckSavings";
			this->Text = L"CheckSavings";
			this->Load += gcnew System::EventHandler(this, &CheckSavings::CheckSavings_Load);
			this->checkSavingsMainPanel->ResumeLayout(false);
			this->checkSavingsMainPanel->PerformLayout();
			this->detailPanel->ResumeLayout(false);
			this->detailPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDetail))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAccount))->EndInit();
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

			//System::Void dataGridViewAccount_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			//	if (e->ColumnIndex == dataGridViewAccount->Columns["details"]->Index) {
			//		// Check if the row has data before processing the click
			//		if (dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value != nullptr &&
			//			!String::IsNullOrEmpty(dataGridViewAccount->Rows[e->RowIndex]->Cells[0]->Value->ToString())) {
			//			detailPanel->Visible = true;
			//			opacityValue = 0.0;
			//			fadeInTimer->Start();
			//		}
			//	}
			//}

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
private: 
	System::Void btnCheckSavings_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void customerAccInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void dataGridViewAccount_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
