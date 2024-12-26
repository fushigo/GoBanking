#pragma once

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CustomerData
	/// </summary>
	public ref class CustomerData : public System::Windows::Forms::Form
	{
	public:
		CustomerData(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CustomerData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ customerDataMainPanel;
	protected:

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::TextBox^ textBox1;









	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ identityNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ customerName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gender;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ email;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ phoneNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ createdAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ updatedAt;
	private: System::Windows::Forms::Button^ btn_reset;






































































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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CustomerData::typeid));
			this->customerDataMainPanel = (gcnew System::Windows::Forms::Panel());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->identityNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->customerName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phoneNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->createdAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->updatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->customerDataMainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// customerDataMainPanel
			// 
			this->customerDataMainPanel->Controls->Add(this->dataGridView);
			this->customerDataMainPanel->Controls->Add(this->panel1);
			this->customerDataMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->customerDataMainPanel->Location = System::Drawing::Point(252, 0);
			this->customerDataMainPanel->Margin = System::Windows::Forms::Padding(2);
			this->customerDataMainPanel->Name = L"customerDataMainPanel";
			this->customerDataMainPanel->Size = System::Drawing::Size(788, 640);
			this->customerDataMainPanel->TabIndex = 0;
			this->customerDataMainPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CustomerData::customerDataMainPanel_Paint);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToOrderColumns = true;
			this->dataGridView->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->identityNumber,
					this->customerName, this->gender, this->email, this->phoneNumber, this->createdAt, this->updatedAt
			});
			this->dataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridView->Location = System::Drawing::Point(2, 204);
			this->dataGridView->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidth = 51;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dataGridView->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridView->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView->RowTemplate->Height = 24;
			this->dataGridView->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->Size = System::Drawing::Size(740, 492);
			this->dataGridView->TabIndex = 3;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerData::dataGridView_CellContentClick);
			// 
			// identityNumber
			// 
			this->identityNumber->HeaderText = L"Nomor Identitas";
			this->identityNumber->Name = L"identityNumber";
			// 
			// customerName
			// 
			this->customerName->HeaderText = L"Nama Nasabah";
			this->customerName->MinimumWidth = 6;
			this->customerName->Name = L"customerName";
			this->customerName->Width = 125;
			// 
			// gender
			// 
			this->gender->HeaderText = L"Jenis Kelamin";
			this->gender->Name = L"gender";
			// 
			// email
			// 
			this->email->HeaderText = L"Email";
			this->email->Name = L"email";
			// 
			// phoneNumber
			// 
			this->phoneNumber->HeaderText = L"Nomor Telephone";
			this->phoneNumber->Name = L"phoneNumber";
			// 
			// createdAt
			// 
			this->createdAt->HeaderText = L"Tgl. Dibuat";
			this->createdAt->MinimumWidth = 6;
			this->createdAt->Name = L"createdAt";
			this->createdAt->Width = 125;
			// 
			// updatedAt
			// 
			this->updatedAt->HeaderText = L"Tgl. Diubah";
			this->updatedAt->MinimumWidth = 6;
			this->updatedAt->Name = L"updatedAt";
			this->updatedAt->Width = 125;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btn_reset);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->dateTimePicker);
			this->panel1->Controls->Add(this->btnSearch);
			this->panel1->Location = System::Drawing::Point(0, 86);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(742, 77);
			this->panel1->TabIndex = 4;
			// 
			// btn_reset
			// 
			this->btn_reset->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reset->Location = System::Drawing::Point(0, 38);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(115, 36);
			this->btn_reset->TabIndex = 3;
			this->btn_reset->Text = L"Reset Filter";
			this->btn_reset->UseVisualStyleBackColor = true;
			this->btn_reset->Click += gcnew System::EventHandler(this, &CustomerData::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(488, 10);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->MaxLength = 255;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(226, 23);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &CustomerData::textBox1_TextChanged);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dateTimePicker->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dateTimePicker->CalendarTitleForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dateTimePicker->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker->Location = System::Drawing::Point(0, 10);
			this->dateTimePicker->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker->MaxDate = System::DateTime(2045, 12, 31, 0, 0, 0, 0);
			this->dateTimePicker->MinDate = System::DateTime(2024, 12, 21, 0, 0, 0, 0);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(245, 23);
			this->dateTimePicker->TabIndex = 0;
			this->dateTimePicker->Value = System::DateTime(2024, 12, 21, 0, 0, 0, 0);
			this->dateTimePicker->ValueChanged += gcnew System::EventHandler(this, &CustomerData::dateTimePicker_ValueChanged);
			// 
			// btnSearch
			// 
			this->btnSearch->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->btnSearch->FlatAppearance->BorderSize = 0;
			this->btnSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSearch.Image")));
			this->btnSearch->Location = System::Drawing::Point(712, 10);
			this->btnSearch->Margin = System::Windows::Forms::Padding(2);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(30, 22);
			this->btnSearch->TabIndex = 2;
			this->btnSearch->UseVisualStyleBackColor = false;
			this->btnSearch->Click += gcnew System::EventHandler(this, &CustomerData::btnSearch_Click);
			// 
			// CustomerData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1040, 640);
			this->Controls->Add(this->customerDataMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"CustomerData";
			this->Text = L"CustomerData";
			this->Load += gcnew System::EventHandler(this, &CustomerData::CustomerData_Load);
			this->customerDataMainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void customerDataMainPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}

private: 
	System::Void CustomerData_Load(System::Object^ sender, System::EventArgs^ e);
	System::Void dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
};
}
