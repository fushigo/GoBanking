#pragma once
#include "Home.h"

namespace GoBanking {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{

	public:
		Login(void)
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
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ loginForm;
	private: System::Windows::Forms::Label^ loginLabel;

	private: System::Windows::Forms::Label^ loginTitle;
	private: System::Windows::Forms::Label^ loginLabelUsername;
	private: System::Windows::Forms::TextBox^ usernameInput;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ passwordInput;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ underlineLoginForm;

	private: System::Windows::Forms::FlowLayoutPanel^ loginImage;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ loginButton;
	private: System::Windows::Forms::CheckBox^ showPassword;
	private: System::Windows::Forms::Panel^ panelWindow;

	private: System::Windows::Forms::Button^ btnMinimizeWindow;
	private: System::Windows::Forms::Button^ btnCloseWindow;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->loginForm = (gcnew System::Windows::Forms::Panel());
			this->showPassword = (gcnew System::Windows::Forms::CheckBox());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->passwordInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->underlineLoginForm = (gcnew System::Windows::Forms::Panel());
			this->usernameInput = (gcnew System::Windows::Forms::TextBox());
			this->loginLabelUsername = (gcnew System::Windows::Forms::Label());
			this->loginLabel = (gcnew System::Windows::Forms::Label());
			this->loginTitle = (gcnew System::Windows::Forms::Label());
			this->loginImage = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panelWindow = (gcnew System::Windows::Forms::Panel());
			this->btnMinimizeWindow = (gcnew System::Windows::Forms::Button());
			this->btnCloseWindow = (gcnew System::Windows::Forms::Button());
			this->loginForm->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelWindow->SuspendLayout();
			this->SuspendLayout();
			// 
			// loginForm
			// 
			this->loginForm->Controls->Add(this->showPassword);
			this->loginForm->Controls->Add(this->loginButton);
			this->loginForm->Controls->Add(this->panel1);
			this->loginForm->Controls->Add(this->passwordInput);
			this->loginForm->Controls->Add(this->label1);
			this->loginForm->Controls->Add(this->underlineLoginForm);
			this->loginForm->Controls->Add(this->usernameInput);
			this->loginForm->Controls->Add(this->loginLabelUsername);
			this->loginForm->Controls->Add(this->loginLabel);
			this->loginForm->Controls->Add(this->loginTitle);
			this->loginForm->Location = System::Drawing::Point(735, 74);
			this->loginForm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->loginForm->Name = L"loginForm";
			this->loginForm->Size = System::Drawing::Size(600, 750);
			this->loginForm->TabIndex = 1;
			// 
			// showPassword
			// 
			this->showPassword->AutoSize = true;
			this->showPassword->Cursor = System::Windows::Forms::Cursors::Hand;
			this->showPassword->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->showPassword->Location = System::Drawing::Point(80, 512);
			this->showPassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->showPassword->Name = L"showPassword";
			this->showPassword->Size = System::Drawing::Size(145, 21);
			this->showPassword->TabIndex = 9;
			this->showPassword->Text = L"Show password";
			this->showPassword->UseVisualStyleBackColor = true;
			this->showPassword->CheckedChanged += gcnew System::EventHandler(this, &Login::showPassword_CheckedChanged);
			// 
			// loginButton
			// 
			this->loginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->loginButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->loginButton->FlatAppearance->BorderSize = 0;
			this->loginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginButton->ForeColor = System::Drawing::Color::White;
			this->loginButton->Location = System::Drawing::Point(80, 569);
			this->loginButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(188, 54);
			this->loginButton->TabIndex = 8;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = false;
			this->loginButton->Click += gcnew System::EventHandler(this, &Login::loginButton_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->panel1->Location = System::Drawing::Point(80, 476);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(389, 5);
			this->panel1->TabIndex = 7;
			// 
			// passwordInput
			// 
			this->passwordInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->passwordInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passwordInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11));
			this->passwordInput->ForeColor = System::Drawing::Color::White;
			this->passwordInput->Location = System::Drawing::Point(80, 448);
			this->passwordInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->passwordInput->Name = L"passwordInput";
			this->passwordInput->Size = System::Drawing::Size(389, 22);
			this->passwordInput->TabIndex = 6;
			this->passwordInput->UseSystemPasswordChar = true;
			this->passwordInput->TextChanged += gcnew System::EventHandler(this, &Login::passwordInput_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(76, 405);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Password";
			// 
			// underlineLoginForm
			// 
			this->underlineLoginForm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->underlineLoginForm->Location = System::Drawing::Point(80, 366);
			this->underlineLoginForm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->underlineLoginForm->Name = L"underlineLoginForm";
			this->underlineLoginForm->Size = System::Drawing::Size(389, 5);
			this->underlineLoginForm->TabIndex = 4;
			// 
			// usernameInput
			// 
			this->usernameInput->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->usernameInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->usernameInput->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11));
			this->usernameInput->ForeColor = System::Drawing::Color::White;
			this->usernameInput->Location = System::Drawing::Point(80, 338);
			this->usernameInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->usernameInput->Name = L"usernameInput";
			this->usernameInput->Size = System::Drawing::Size(389, 22);
			this->usernameInput->TabIndex = 3;
			this->usernameInput->TextChanged += gcnew System::EventHandler(this, &Login::usernameInput_TextChanged);
			// 
			// loginLabelUsername
			// 
			this->loginLabelUsername->AutoSize = true;
			this->loginLabelUsername->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 11));
			this->loginLabelUsername->ForeColor = System::Drawing::Color::White;
			this->loginLabelUsername->Location = System::Drawing::Point(76, 295);
			this->loginLabelUsername->Name = L"loginLabelUsername";
			this->loginLabelUsername->Size = System::Drawing::Size(103, 22);
			this->loginLabelUsername->TabIndex = 2;
			this->loginLabelUsername->Text = L"Username";
			// 
			// loginLabel
			// 
			this->loginLabel->AutoSize = true;
			this->loginLabel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginLabel->ForeColor = System::Drawing::Color::White;
			this->loginLabel->Location = System::Drawing::Point(76, 196);
			this->loginLabel->Name = L"loginLabel";
			this->loginLabel->Size = System::Drawing::Size(402, 23);
			this->loginLabel->TabIndex = 1;
			this->loginLabel->Text = L"Login with your account to enter the app";
			// 
			// loginTitle
			// 
			this->loginTitle->AutoSize = true;
			this->loginTitle->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 32.8F));
			this->loginTitle->ForeColor = System::Drawing::Color::White;
			this->loginTitle->Location = System::Drawing::Point(69, 123);
			this->loginTitle->Name = L"loginTitle";
			this->loginTitle->Size = System::Drawing::Size(360, 64);
			this->loginTitle->TabIndex = 0;
			this->loginTitle->Text = L"Admin Login";
			// 
			// loginImage
			// 
			this->loginImage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->loginImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loginImage.BackgroundImage")));
			this->loginImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->loginImage->Location = System::Drawing::Point(95, 199);
			this->loginImage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->loginImage->Name = L"loginImage";
			this->loginImage->Size = System::Drawing::Size(500, 500);
			this->loginImage->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(84)),
				static_cast<System::Int32>(static_cast<System::Byte>(181)));
			this->panel2->Controls->Add(this->loginImage);
			this->panel2->Location = System::Drawing::Point(-1, -1);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(691, 900);
			this->panel2->TabIndex = 2;
			this->panel2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::panelWindow_MouseDown);
			this->panel2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::panelWindow_MouseMove);
			this->panel2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::panelWindow_MouseUp);
			// 
			// panelWindow
			// 
			this->panelWindow->Controls->Add(this->btnMinimizeWindow);
			this->panelWindow->Controls->Add(this->btnCloseWindow);
			this->panelWindow->Location = System::Drawing::Point(691, 0);
			this->panelWindow->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelWindow->Name = L"panelWindow";
			this->panelWindow->Size = System::Drawing::Size(709, 39);
			this->panelWindow->TabIndex = 2;
			this->panelWindow->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::panelWindow_MouseDown);
			this->panelWindow->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::panelWindow_MouseMove);
			this->panelWindow->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Login::panelWindow_MouseUp);
			// 
			// btnMinimizeWindow
			// 
			this->btnMinimizeWindow->FlatAppearance->BorderSize = 0;
			this->btnMinimizeWindow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMinimizeWindow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMinimizeWindow.Image")));
			this->btnMinimizeWindow->Location = System::Drawing::Point(624, 0);
			this->btnMinimizeWindow->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMinimizeWindow->Name = L"btnMinimizeWindow";
			this->btnMinimizeWindow->Padding = System::Windows::Forms::Padding(11, 10, 11, 10);
			this->btnMinimizeWindow->Size = System::Drawing::Size(40, 39);
			this->btnMinimizeWindow->TabIndex = 10;
			this->btnMinimizeWindow->UseVisualStyleBackColor = true;
			this->btnMinimizeWindow->Click += gcnew System::EventHandler(this, &Login::btnMinimizeWindow_Click);
			// 
			// btnCloseWindow
			// 
			this->btnCloseWindow->FlatAppearance->BorderSize = 0;
			this->btnCloseWindow->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCloseWindow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCloseWindow.Image")));
			this->btnCloseWindow->Location = System::Drawing::Point(669, 0);
			this->btnCloseWindow->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCloseWindow->Name = L"btnCloseWindow";
			this->btnCloseWindow->Padding = System::Windows::Forms::Padding(11, 10, 11, 10);
			this->btnCloseWindow->Size = System::Drawing::Size(40, 39);
			this->btnCloseWindow->TabIndex = 9;
			this->btnCloseWindow->UseVisualStyleBackColor = true;
			this->btnCloseWindow->Click += gcnew System::EventHandler(this, &Login::btnCloseWindow_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(39)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->ClientSize = System::Drawing::Size(1400, 900);
			this->Controls->Add(this->panelWindow);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->loginForm);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->loginForm->ResumeLayout(false);
			this->loginForm->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panelWindow->ResumeLayout(false);
			this->ResumeLayout(false);

		}


#pragma endregion
	private: System::Void loginImage_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	
	private: System::Void showPassword_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (showPassword->Checked) {
			passwordInput->UseSystemPasswordChar = false;
		}
		else {
			passwordInput->UseSystemPasswordChar = true;
		}
	}
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void btnCloseWindow_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btnMinimizeWindow_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	private:
		System::Void usernameInput_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void passwordInput_TextChanged(System::Object^ sender, System::EventArgs^ e);

	// dragging
		bool dragging;
		Point offset;
	private: System::Void panelWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
	private: System::Void panelWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
		}
	}
	private: System::Void panelWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	};
}
