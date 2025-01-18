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
	/// Summary for DataRekening
	/// </summary>
	public ref class DataRekening : public System::Windows::Forms::Form
	{
	public:
		DataRekening(void)
		{
			InitializeComponent();
			currentPopup = gcnew PopupForm();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DataRekening()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ dataRekeningMainPanel;
	private: System::Windows::Forms::DataGridView^ dataGridViewRekening;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numberAccount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ savingType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ totalBalance;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ bonus;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ accPin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ createdAt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ updatedAt;
	private: System::Windows::Forms::DataGridViewButtonColumn^ edit;
	private: System::Windows::Forms::DataGridViewButtonColumn^ deletecol;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btn_reset;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::Button^ btnSearch;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DataRekening::typeid));
			this->dataRekeningMainPanel = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewRekening = (gcnew System::Windows::Forms::DataGridView());
			this->numberAccount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->savingType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->totalBalance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bonus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->accPin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->createdAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->updatedAt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->edit = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->deletecol = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_reset = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->dataRekeningMainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRekening))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataRekeningMainPanel
			// 
			this->dataRekeningMainPanel->AutoScroll = true;
			this->dataRekeningMainPanel->Controls->Add(this->dataGridViewRekening);
			this->dataRekeningMainPanel->Controls->Add(this->panel1);
			this->dataRekeningMainPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->dataRekeningMainPanel->Location = System::Drawing::Point(309, 0);
			this->dataRekeningMainPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataRekeningMainPanel->Name = L"dataRekeningMainPanel";
			this->dataRekeningMainPanel->Size = System::Drawing::Size(1091, 900);
			this->dataRekeningMainPanel->TabIndex = 0;
			// 
			// dataGridViewRekening
			// 
			this->dataGridViewRekening->AllowUserToOrderColumns = true;
			this->dataGridViewRekening->AllowUserToResizeRows = false;
			this->dataGridViewRekening->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewRekening->BorderStyle = System::Windows::Forms::BorderStyle::None;
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
			this->dataGridViewRekening->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewRekening->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewRekening->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->numberAccount,
					this->savingType, this->totalBalance, this->bonus, this->accPin, this->createdAt, this->updatedAt, this->edit, this->deletecol
			});
			this->dataGridViewRekening->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->dataGridViewRekening->Location = System::Drawing::Point(52, 220);
			this->dataGridViewRekening->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridViewRekening->Name = L"dataGridViewRekening";
			this->dataGridViewRekening->ReadOnly = true;
			this->dataGridViewRekening->RowHeadersVisible = false;
			this->dataGridViewRekening->RowHeadersWidth = 51;
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
			this->dataGridViewRekening->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridViewRekening->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewRekening->RowTemplate->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dataGridViewRekening->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridViewRekening->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridViewRekening->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridViewRekening->RowTemplate->Height = 50;
			this->dataGridViewRekening->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewRekening->Size = System::Drawing::Size(987, 606);
			this->dataGridViewRekening->TabIndex = 5;
			// 
			// numberAccount
			// 
			this->numberAccount->HeaderText = L"Nomor Rekening";
			this->numberAccount->MinimumWidth = 6;
			this->numberAccount->Name = L"numberAccount";
			this->numberAccount->ReadOnly = true;
			this->numberAccount->Width = 125;
			// 
			// savingType
			// 
			this->savingType->HeaderText = L"Jenis Tabungan";
			this->savingType->MinimumWidth = 6;
			this->savingType->Name = L"savingType";
			this->savingType->ReadOnly = true;
			this->savingType->Width = 125;
			// 
			// totalBalance
			// 
			this->totalBalance->HeaderText = L"Total Dana";
			this->totalBalance->MinimumWidth = 6;
			this->totalBalance->Name = L"totalBalance";
			this->totalBalance->ReadOnly = true;
			this->totalBalance->Width = 125;
			// 
			// bonus
			// 
			this->bonus->HeaderText = L"Bonus Bunga";
			this->bonus->MinimumWidth = 6;
			this->bonus->Name = L"bonus";
			this->bonus->ReadOnly = true;
			this->bonus->Width = 125;
			// 
			// accPin
			// 
			this->accPin->HeaderText = L"PIN";
			this->accPin->MinimumWidth = 6;
			this->accPin->Name = L"accPin";
			this->accPin->ReadOnly = true;
			this->accPin->Width = 125;
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
			this->panel1->Location = System::Drawing::Point(51, 75);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(989, 95);
			this->panel1->TabIndex = 6;
			// 
			// btn_reset
			// 
			this->btn_reset->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reset->Location = System::Drawing::Point(0, 47);
			this->btn_reset->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_reset->Name = L"btn_reset";
			this->btn_reset->Size = System::Drawing::Size(153, 44);
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
			this->textBox1->Location = System::Drawing::Point(651, 12);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->MaxLength = 255;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(301, 27);
			this->textBox1->TabIndex = 1;
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
			// 
			// DataRekening
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->dataRekeningMainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"DataRekening";
			this->Text = L"DataRekening";
			this->Load += gcnew System::EventHandler(this, &DataRekening::DataRekening_Load);
			this->dataRekeningMainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRekening))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		PopupForm^ currentPopup;

		System::Void dataGridViewRekening_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
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
		System::Void DataRekening_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void dateTimePicker_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
