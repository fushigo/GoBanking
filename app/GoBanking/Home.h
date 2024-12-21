#pragma once
#include "OpenRek.h"
#include "Transfer.h"
#include "Withdraw.h"
#include "AddSavingsFunds.h"
#include "CheckSavings.h"
#include <nlohmann/json.hpp>
#include <msclr/marshal_cppstd.h>

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using json = nlohmann::json;
	using namespace std;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(json karyawanData)
		{
			InitializeComponent();
			string namaKaryawan = karyawanData["namaKaryawan"];

			System::String^ displayName = gcnew System::String(namaKaryawan.c_str());

			welcome->Text = "Hi! " + displayName + "\nSelamat Datang";
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Void loadform(System::Windows::Forms::Form^ Form) {
		if (this->mainpanel->Controls->Count > 0) {
			this->mainpanel->Controls->RemoveAt(0);
		}

		Form->TopLevel = false;
		Form->Dock = System::Windows::Forms::DockStyle::Fill;
		this->mainpanel->Controls->Add(Form);
		this->mainpanel->Tag = Form;
		Form->Show();
	}


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnOpenrek;
	private: System::Windows::Forms::Button^ btnLogout;


	private: System::Windows::Forms::Button^ btnTransfer;
	private: System::Windows::Forms::Button^ btnWithdraw;
	private: System::Windows::Forms::Button^ btnCeksavings;
	private: System::Windows::Forms::Button^ btnAddsavings;



	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btnCloseWindow;
	private: System::Windows::Forms::Button^ btnMinimizeWindow;
	private: System::Windows::Forms::Panel^ mainpanel;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ textWelcomeScreen;
	private: System::Windows::Forms::Label^ welcome;
	private: System::Windows::Forms::Panel^ panel4;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnCeksavings = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->btnOpenrek = (gcnew System::Windows::Forms::Button());
			this->btnAddsavings = (gcnew System::Windows::Forms::Button());
			this->btnWithdraw = (gcnew System::Windows::Forms::Button());
			this->btnTransfer = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnMinimizeWindow = (gcnew System::Windows::Forms::Button());
			this->btnCloseWindow = (gcnew System::Windows::Forms::Button());
			this->mainpanel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textWelcomeScreen = (gcnew System::Windows::Forms::Label());
			this->welcome = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->mainpanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->panel1->Controls->Add(this->btnCeksavings);
			this->panel1->Controls->Add(this->btnLogout);
			this->panel1->Controls->Add(this->btnOpenrek);
			this->panel1->Controls->Add(this->btnAddsavings);
			this->panel1->Controls->Add(this->btnWithdraw);
			this->panel1->Controls->Add(this->btnTransfer);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(232, 640);
			this->panel1->TabIndex = 0;
			// 
			// btnCeksavings
			// 
			this->btnCeksavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->btnCeksavings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCeksavings->FlatAppearance->BorderSize = 0;
			this->btnCeksavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCeksavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCeksavings->ForeColor = System::Drawing::Color::White;
			this->btnCeksavings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCeksavings.Image")));
			this->btnCeksavings->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCeksavings->Location = System::Drawing::Point(-1, 434);
			this->btnCeksavings->Margin = System::Windows::Forms::Padding(2);
			this->btnCeksavings->Name = L"btnCeksavings";
			this->btnCeksavings->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->btnCeksavings->Size = System::Drawing::Size(232, 45);
			this->btnCeksavings->TabIndex = 6;
			this->btnCeksavings->Text = L"Tabungan";
			this->btnCeksavings->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnCeksavings->UseVisualStyleBackColor = false;
			this->btnCeksavings->Click += gcnew System::EventHandler(this, &Home::btnCeksavings_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogout->FlatAppearance->BorderSize = 0;
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLogout.Image")));
			this->btnLogout->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnLogout->Location = System::Drawing::Point(-1, 635);
			this->btnLogout->Margin = System::Windows::Forms::Padding(2);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Padding = System::Windows::Forms::Padding(22, 0, 8, 0);
			this->btnLogout->Size = System::Drawing::Size(232, 45);
			this->btnLogout->TabIndex = 2;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->UseVisualStyleBackColor = false;
			this->btnLogout->Click += gcnew System::EventHandler(this, &Home::btnLogout_Click);
			// 
			// btnOpenrek
			// 
			this->btnOpenrek->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->btnOpenrek->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnOpenrek->FlatAppearance->BorderSize = 0;
			this->btnOpenrek->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOpenrek->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOpenrek->ForeColor = System::Drawing::Color::White;
			this->btnOpenrek->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnOpenrek.Image")));
			this->btnOpenrek->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnOpenrek->Location = System::Drawing::Point(-1, 200);
			this->btnOpenrek->Margin = System::Windows::Forms::Padding(2);
			this->btnOpenrek->Name = L"btnOpenrek";
			this->btnOpenrek->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->btnOpenrek->Size = System::Drawing::Size(232, 45);
			this->btnOpenrek->TabIndex = 1;
			this->btnOpenrek->Text = L"Buka Rekening";
			this->btnOpenrek->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnOpenrek->UseVisualStyleBackColor = false;
			this->btnOpenrek->Click += gcnew System::EventHandler(this, &Home::btnOpenrek_Click);
			// 
			// btnAddsavings
			// 
			this->btnAddsavings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->btnAddsavings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAddsavings->FlatAppearance->BorderSize = 0;
			this->btnAddsavings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddsavings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddsavings->ForeColor = System::Drawing::Color::White;
			this->btnAddsavings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddsavings.Image")));
			this->btnAddsavings->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddsavings->Location = System::Drawing::Point(-1, 375);
			this->btnAddsavings->Margin = System::Windows::Forms::Padding(2);
			this->btnAddsavings->Name = L"btnAddsavings";
			this->btnAddsavings->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->btnAddsavings->Size = System::Drawing::Size(232, 45);
			this->btnAddsavings->TabIndex = 5;
			this->btnAddsavings->Text = L"Tambah Tabungan";
			this->btnAddsavings->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnAddsavings->UseVisualStyleBackColor = false;
			this->btnAddsavings->Click += gcnew System::EventHandler(this, &Home::btnAddsavings_Click);
			// 
			// btnWithdraw
			// 
			this->btnWithdraw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->btnWithdraw->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnWithdraw->FlatAppearance->BorderSize = 0;
			this->btnWithdraw->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnWithdraw->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWithdraw->ForeColor = System::Drawing::Color::White;
			this->btnWithdraw->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnWithdraw.Image")));
			this->btnWithdraw->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnWithdraw->Location = System::Drawing::Point(-1, 317);
			this->btnWithdraw->Margin = System::Windows::Forms::Padding(2);
			this->btnWithdraw->Name = L"btnWithdraw";
			this->btnWithdraw->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->btnWithdraw->Size = System::Drawing::Size(232, 45);
			this->btnWithdraw->TabIndex = 3;
			this->btnWithdraw->Text = L"Tarik Tunai";
			this->btnWithdraw->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnWithdraw->UseVisualStyleBackColor = false;
			this->btnWithdraw->Click += gcnew System::EventHandler(this, &Home::btnWithdraw_Click);
			// 
			// btnTransfer
			// 
			this->btnTransfer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->btnTransfer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnTransfer->FlatAppearance->BorderSize = 0;
			this->btnTransfer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTransfer->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTransfer->ForeColor = System::Drawing::Color::White;
			this->btnTransfer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTransfer.Image")));
			this->btnTransfer->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnTransfer->Location = System::Drawing::Point(-1, 258);
			this->btnTransfer->Margin = System::Windows::Forms::Padding(2);
			this->btnTransfer->Name = L"btnTransfer";
			this->btnTransfer->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->btnTransfer->Size = System::Drawing::Size(232, 45);
			this->btnTransfer->TabIndex = 4;
			this->btnTransfer->Text = L"Transfer";
			this->btnTransfer->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnTransfer->UseVisualStyleBackColor = false;
			this->btnTransfer->Click += gcnew System::EventHandler(this, &Home::btnTransfer_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->btnMinimizeWindow);
			this->panel3->Controls->Add(this->btnCloseWindow);
			this->panel3->Location = System::Drawing::Point(232, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(818, 32);
			this->panel3->TabIndex = 4;
			// 
			// btnMinimizeWindow
			// 
			this->btnMinimizeWindow->FlatAppearance->BorderSize = 0;
			this->btnMinimizeWindow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMinimizeWindow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMinimizeWindow.Image")));
			this->btnMinimizeWindow->Location = System::Drawing::Point(742, 2);
			this->btnMinimizeWindow->Margin = System::Windows::Forms::Padding(2);
			this->btnMinimizeWindow->Name = L"btnMinimizeWindow";
			this->btnMinimizeWindow->Padding = System::Windows::Forms::Padding(8);
			this->btnMinimizeWindow->Size = System::Drawing::Size(30, 32);
			this->btnMinimizeWindow->TabIndex = 6;
			this->btnMinimizeWindow->UseVisualStyleBackColor = true;
			this->btnMinimizeWindow->Click += gcnew System::EventHandler(this, &Home::btnMinimizeWindow_Click);
			// 
			// btnCloseWindow
			// 
			this->btnCloseWindow->FlatAppearance->BorderSize = 0;
			this->btnCloseWindow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCloseWindow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCloseWindow.Image")));
			this->btnCloseWindow->Location = System::Drawing::Point(776, 2);
			this->btnCloseWindow->Margin = System::Windows::Forms::Padding(2);
			this->btnCloseWindow->Name = L"btnCloseWindow";
			this->btnCloseWindow->Padding = System::Windows::Forms::Padding(8);
			this->btnCloseWindow->Size = System::Drawing::Size(30, 32);
			this->btnCloseWindow->TabIndex = 5;
			this->btnCloseWindow->UseVisualStyleBackColor = true;
			this->btnCloseWindow->Click += gcnew System::EventHandler(this, &Home::btnCloseWindow_Click);
			// 
			// mainpanel
			// 
			this->mainpanel->Controls->Add(this->panel2);
			this->mainpanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainpanel->Location = System::Drawing::Point(0, 0);
			this->mainpanel->Margin = System::Windows::Forms::Padding(2);
			this->mainpanel->Name = L"mainpanel";
			this->mainpanel->Size = System::Drawing::Size(1040, 640);
			this->mainpanel->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->Controls->Add(this->textWelcomeScreen);
			this->panel2->Controls->Add(this->welcome);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Location = System::Drawing::Point(375, 36);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(525, 569);
			this->panel2->TabIndex = 0;
			// 
			// textWelcomeScreen
			// 
			this->textWelcomeScreen->AutoSize = true;
			this->textWelcomeScreen->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->textWelcomeScreen->ForeColor = System::Drawing::Color::White;
			this->textWelcomeScreen->Location = System::Drawing::Point(11, 488);
			this->textWelcomeScreen->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->textWelcomeScreen->Name = L"textWelcomeScreen";
			this->textWelcomeScreen->Size = System::Drawing::Size(374, 69);
			this->textWelcomeScreen->TabIndex = 9;
			this->textWelcomeScreen->Text = L"Untuk melakukan aktivitas, anda bisa \r\nmenggunakan panel navigasi pada \r\nbagian s"
				L"amping halaman";
			// 
			// welcome
			// 
			this->welcome->AutoSize = true;
			this->welcome->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->welcome->ForeColor = System::Drawing::Color::White;
			this->welcome->Location = System::Drawing::Point(10, 11);
			this->welcome->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->welcome->Name = L"welcome";
			this->welcome->Size = System::Drawing::Size(223, 64);
			this->welcome->TabIndex = 8;
			this->welcome->Text = L"Hi!\r\nSelamat Datang";
			this->welcome->Click += gcnew System::EventHandler(this, &Home::welcome_Click);
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel4->Location = System::Drawing::Point(15, 98);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(498, 366);
			this->panel4->TabIndex = 7;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Home::panel4_Paint);
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1040, 640);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->mainpanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->mainpanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnCloseWindow_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btnMinimizeWindow_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	private: System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnOpenrek_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenRek^ openrek = gcnew OpenRek();
		loadform(openrek);
	}
	private: System::Void btnTransfer_Click(System::Object^ sender, System::EventArgs^ e) {
		Transfer^ transfer = gcnew Transfer();
		loadform(transfer);
	}
	private: System::Void btnWithdraw_Click(System::Object^ sender, System::EventArgs^ e) {
		Withdraw^ withdraw = gcnew Withdraw();
		loadform(withdraw);
	}
	private: System::Void btnAddsavings_Click(System::Object^ sender, System::EventArgs^ e) {
		AddSavingsFunds^ addsavings = gcnew AddSavingsFunds();
		loadform(addsavings);
	}
	private: System::Void btnCeksavings_Click(System::Object^ sender, System::EventArgs^ e) {
		CheckSavings^ checksavings = gcnew CheckSavings();
		loadform(checksavings);
	}
private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void welcome_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
