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
	/// Summary for DataKaryawan
	/// </summary>
	public ref class DataKaryawan : public System::Windows::Forms::Form
	{
	public:
		DataKaryawan(void)
		{
			InitializeComponent();
			currentPopup = gcnew PopupForm();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DataKaryawan()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ dataKaryawanMainPanel;
	private: System::Windows::Forms::DataGridView^ dataGridViewKaryawan;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ staffNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ staffName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ staffUsername;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ staffRole;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ createdAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ updatedAt;
	private: System::Windows::Forms::DataGridViewButtonColumn^ edit;
	private: System::Windows::Forms::DataGridViewButtonColumn^ deletecol;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btn_reset;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Button^ btnCreate;
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DataKaryawan::typeid));
			this->dataKaryawanMainPanel = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewKaryawan = (gcnew System::Windows::Forms::DataGridView());
			this->staffNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->staffName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->staffUsername = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->staffRole = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->createdAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->updatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->deletecol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnCreate = (gcnew System::Windows::Forms::Button());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->dataKaryawanMainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKaryawan))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataKaryawanMainPanel
			// 
			this->dataKaryawanMainPanel->AutoScroll = true;
			this->dataKaryawanMainPanel->Controls->Add(this->dataGridViewKaryawan);
			this->dataKaryawanMainPanel->Controls->Add(this->panel1);
			this->dataKaryawanMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->dataKaryawanMainPanel->Location = System::Drawing::Point(222, 0);
			this->dataKaryawanMainPanel->Margin = System::Windows::Forms::Padding(2);
			this->dataKaryawanMainPanel->Name = L"dataKaryawanMainPanel";
			this->dataKaryawanMainPanel->Size = System::Drawing::Size(818, 640);
			this->dataKaryawanMainPanel->TabIndex = 0;
			// 
			// dataGridViewKaryawan
			// 
			this->dataGridViewKaryawan->AllowUserToOrderColumns = true;
			this->dataGridViewKaryawan->AllowUserToResizeRows = false;
			this->dataGridViewKaryawan->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewKaryawan->BorderStyle = System::Windows::Forms::BorderStyle::None;
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
			this->dataGridViewKaryawan->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewKaryawan->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKaryawan->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->staffNumber,
					this->staffName, this->staffUsername, this->staffRole, this->createdAt, this->updatedAt, this->edit, this->deletecol
			});
			this->dataGridViewKaryawan->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridViewKaryawan->Location = System::Drawing::Point(39, 179);
			this->dataGridViewKaryawan->Margin = System::Windows::Forms::Padding(2);
			this->dataGridViewKaryawan->Name = L"dataGridViewKaryawan";
			this->dataGridViewKaryawan->ReadOnly = true;
			this->dataGridViewKaryawan->RowHeadersVisible = false;
			this->dataGridViewKaryawan->RowHeadersWidth = 51;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewKaryawan->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridViewKaryawan->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewKaryawan->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dataGridViewKaryawan->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridViewKaryawan->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewKaryawan->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridViewKaryawan->RowTemplate->Height = 50;
			this->dataGridViewKaryawan->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewKaryawan->Size = System::Drawing::Size(740, 492);
			this->dataGridViewKaryawan->TabIndex = 5;
			this->dataGridViewKaryawan->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataKaryawan::dataGridViewKaryawan_CellContentClick_1);
			// 
			// staffNumber
			// 
			this->staffNumber->HeaderText = L"No. Karyawan";
			this->staffNumber->MinimumWidth = 6;
			this->staffNumber->Name = L"staffNumber";
			this->staffNumber->ReadOnly = true;
			this->staffNumber->Width = 125;
			// 
			// staffName
			// 
			this->staffName->HeaderText = L"Nama Karyawan";
			this->staffName->MinimumWidth = 6;
			this->staffName->Name = L"staffName";
			this->staffName->ReadOnly = true;
			this->staffName->Width = 125;
			// 
			// staffUsername
			// 
			this->staffUsername->HeaderText = L"Username";
			this->staffUsername->MinimumWidth = 6;
			this->staffUsername->Name = L"staffUsername";
			this->staffUsername->ReadOnly = true;
			this->staffUsername->Width = 125;
			// 
			// staffRole
			// 
			this->staffRole->HeaderText = L"Role";
			this->staffRole->MinimumWidth = 6;
			this->staffRole->Name = L"staffRole";
			this->staffRole->ReadOnly = true;
			this->staffRole->Width = 125;
			// 
			// createdAt
			// 
			this->createdAt->HeaderText = L"Tgl. Dibuat";
			this->createdAt->MinimumWidth = 6;
			this->createdAt->Name = L"createdAt";
			this->createdAt->ReadOnly = true;
			this->createdAt->Width = 125;
			// 
			// updatedAt
			// 
			this->updatedAt->HeaderText = L"Tgl. Diubah";
			this->updatedAt->MinimumWidth = 6;
			this->updatedAt->Name = L"updatedAt";
			this->updatedAt->ReadOnly = true;
			this->updatedAt->Width = 125;
			// 
			// edit
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			this->edit->DefaultCellStyle = dataGridViewCellStyle2;
			this->edit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->edit->HeaderText = L"Edit";
			this->edit->MinimumWidth = 6;
			this->edit->Name = L"edit";
			this->edit->ReadOnly = true;
			this->edit->Text = L"Edit";
			this->edit->UseColumnTextForButtonValue = true;
			this->edit->Width = 125;
			// 
			// deletecol
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			this->deletecol->DefaultCellStyle = dataGridViewCellStyle3;
			this->deletecol->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deletecol->HeaderText = L"Delete";
			this->deletecol->MinimumWidth = 6;
			this->deletecol->Name = L"deletecol";
			this->deletecol->ReadOnly = true;
			this->deletecol->Text = L"Delete";
			this->deletecol->UseColumnTextForButtonValue = true;
			this->deletecol->Width = 125;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnCreate);
			this->panel1->Controls->Add(this->btn_reset);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->dateTimePicker);
			this->panel1->Controls->Add(this->btnSearch);
			this->panel1->Location = System::Drawing::Point(38, 61);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(742, 77);
			this->panel1->TabIndex = 6;
			// 
			// btnCreate
			// 
			this->btnCreate->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreate->Location = System::Drawing::Point(626, 38);
			this->btnCreate->Name = L"btnCreate";
			this->btnCreate->Size = System::Drawing::Size(115, 36);
			this->btnCreate->TabIndex = 4;
			this->btnCreate->Text = L"Tambah Data";
			this->btnCreate->UseVisualStyleBackColor = true;
			this->btnCreate->Click += gcnew System::EventHandler(this, &DataKaryawan::btnCreate_Click);
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
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &DataKaryawan::textBox1_TextChanged);
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
			this->btnSearch->Click += gcnew System::EventHandler(this, &DataKaryawan::btnSearch_Click);
			// 
			// DataKaryawan
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1040, 640);
			this->Controls->Add(this->dataKaryawanMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"DataKaryawan";
			this->Text = L"DataKaryawan";
			this->Load += gcnew System::EventHandler(this, &DataKaryawan::DataKaryawan_load);
			this->dataKaryawanMainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKaryawan))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		PopupForm^ currentPopup;
		System::Void ShowPopupCreate();
		System::Void ShowConfirmationPopup();
		System::Void ShowPopupEdit();

		System::Void OnConfirmCreate(System::Object^ sender, System::EventArgs^ e);
		System::Void OnConfirmDelete(System::Object^ sender, System::EventArgs^ e);
		System::Void OnConfirmEdit(System::Object^ sender, System::EventArgs^ e);

		System::Void ProcessCreate();
		System::Void ProcessDelete();
		System::Void ProcessEdit();
		System::Void ShowResultPopup(bool isSuccess, String^ message);

		System::Void OnResultConfirmed(System::Object^ sender, System::EventArgs^ e);
		System::Void OnRetryDelete(System::Object^ sender, System::EventArgs^ e);
		System::Void OnClose(System::Object^ sender, System::EventArgs^ e);
		System::Void CloseCurrentPopup(); 
		System::Void btnCreate_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void DataKaryawan_load(System::Object^ sender, System::EventArgs^ e);
		System::Void dataGridViewKaryawan_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
