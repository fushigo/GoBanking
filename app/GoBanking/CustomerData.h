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
	/// Summary for CustomerData
	/// </summary>
	public ref class CustomerData : public System::Windows::Forms::Form
	{
	public:
		CustomerData(void)
		{
			InitializeComponent();
			currentPopup = gcnew PopupForm();
			
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







	private: System::Windows::Forms::Button^ btn_reset;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ identityNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ customerName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gender;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ email;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ phoneNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ createdAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ updatedAt;
	private: System::Windows::Forms::DataGridViewButtonColumn^ edit;
	private: System::Windows::Forms::DataGridViewButtonColumn^ deletecol;



















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
			this->edit = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->deletecol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
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
			this->customerDataMainPanel->AutoScroll = true;
			this->customerDataMainPanel->Controls->Add(this->dataGridView);
			this->customerDataMainPanel->Controls->Add(this->panel1);
			this->customerDataMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->customerDataMainPanel->Location = System::Drawing::Point(309, 0);
			this->customerDataMainPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->customerDataMainPanel->Name = L"customerDataMainPanel";
			this->customerDataMainPanel->Size = System::Drawing::Size(1091, 900);
			this->customerDataMainPanel->TabIndex = 0;
			this->customerDataMainPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CustomerData::customerDataMainPanel_Paint);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToOrderColumns = true;
			this->dataGridView->AllowUserToResizeRows = false;
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
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->identityNumber,
					this->customerName, this->gender, this->email, this->phoneNumber, this->createdAt, this->updatedAt, this->edit, this->deletecol
			});
			this->dataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridView->Location = System::Drawing::Point(52, 251);
			this->dataGridView->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidth = 51;
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
			this->dataGridView->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dataGridView->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridView->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView->RowTemplate->Height = 50;
			this->dataGridView->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->Size = System::Drawing::Size(987, 606);
			this->dataGridView->TabIndex = 3;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomerData::dataGridView_CellContentClick);
			// 
			// identityNumber
			// 
			this->identityNumber->HeaderText = L"Nomor Identitas";
			this->identityNumber->MinimumWidth = 6;
			this->identityNumber->Name = L"identityNumber";
			this->identityNumber->ReadOnly = true;
			this->identityNumber->Width = 125;
			// 
			// customerName
			// 
			this->customerName->HeaderText = L"Nama Nasabah";
			this->customerName->MinimumWidth = 6;
			this->customerName->Name = L"customerName";
			this->customerName->ReadOnly = true;
			this->customerName->Width = 125;
			// 
			// gender
			// 
			this->gender->HeaderText = L"Jenis Kelamin";
			this->gender->MinimumWidth = 6;
			this->gender->Name = L"gender";
			this->gender->ReadOnly = true;
			this->gender->Width = 125;
			// 
			// email
			// 
			this->email->HeaderText = L"Email";
			this->email->MinimumWidth = 6;
			this->email->Name = L"email";
			this->email->ReadOnly = true;
			this->email->Width = 125;
			// 
			// phoneNumber
			// 
			this->phoneNumber->HeaderText = L"Nomor Telephone";
			this->phoneNumber->MinimumWidth = 6;
			this->phoneNumber->Name = L"phoneNumber";
			this->phoneNumber->ReadOnly = true;
			this->phoneNumber->Width = 125;
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
			this->panel1->Controls->Add(this->btn_reset);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->dateTimePicker);
			this->panel1->Controls->Add(this->btnSearch);
			this->panel1->Location = System::Drawing::Point(51, 106);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(989, 95);
			this->panel1->TabIndex = 4;
			// 
			// btn_reset
			// 
			this->btn_reset->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reset->Location = System::Drawing::Point(0, 47);
			this->btn_reset->Margin = System::Windows::Forms::Padding(4);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(153, 44);
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
			this->textBox1->Location = System::Drawing::Point(651, 12);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->MaxLength = 255;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(301, 27);
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
			this->dateTimePicker->Location = System::Drawing::Point(0, 12);
			this->dateTimePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePicker->MaxDate = System::DateTime(2045, 12, 31, 0, 0, 0, 0);
			this->dateTimePicker->MinDate = System::DateTime(2024, 12, 21, 0, 0, 0, 0);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(325, 27);
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
			this->btnSearch->Location = System::Drawing::Point(949, 12);
			this->btnSearch->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(40, 27);
			this->btnSearch->TabIndex = 2;
			this->btnSearch->UseVisualStyleBackColor = false;
			this->btnSearch->Click += gcnew System::EventHandler(this, &CustomerData::btnSearch_Click);
			// 
			// CustomerData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->customerDataMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
private:

	PopupForm^ currentPopup;

	System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	System::Void ShowConfirmationPopup();
	System::Void ShowPopupEdit();
	System::Void OnConfirmDelete(System::Object^ sender, System::EventArgs^ e);
	System::Void OnConfirmEdit(System::Object^ sender, System::EventArgs^ e);

	System::Void ProcessDelete();
	System::Void ShowResultPopup(bool isSuccess, String^ message);
	System::Void ProcessEdit();

	System::Void OnResultConfirmed(System::Object^ sender, System::EventArgs^ e);
	System::Void OnRetryDelete(System::Object^ sender, System::EventArgs^ e);
	System::Void OnClose(System::Object^ sender, System::EventArgs^ e);
	System::Void CloseCurrentPopup();

private: 
	System::Void CustomerData_Load(System::Object^ sender, System::EventArgs^ e);
	System::Void dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
};
}
