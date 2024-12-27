#pragma once

namespace GoBanking {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class PopupForm : public System::Windows::Forms::Form {
    private:
        Label^ messageLabel;
        Button^ actionButton1;
        Button^ actionButton2;
        ProgressBar^ loadingBar;
        Timer^ fadeInTimer;
        Timer^ fadeOutTimer;
        double opacityIncrement;

    public:
        PopupForm(void) {
            InitializeComponent();

            opacityIncrement = 0.05;

            fadeInTimer = gcnew Timer();
            fadeInTimer->Interval = 16; // ~60fps for smoother animation (1000ms/60)
            fadeInTimer->Tick += gcnew EventHandler(this, &PopupForm::FadeIn);

            fadeOutTimer = gcnew Timer();
            fadeOutTimer->Interval = 16; // ~60fps for smoother animation
            fadeOutTimer->Tick += gcnew EventHandler(this, &PopupForm::FadeOut);
        }

        // Set message text dynamically
        void SetMessage(String^ message) {
            this->messageLabel->Text = message;
        }

        // Set action button text and event
        void SetActionButton1(String^ buttonText, EventHandler^ onClickHandler) {
            actionButton1->Text = buttonText;
            actionButton1->Click += onClickHandler;
        }

        void SetActionButton2(String^ buttonText, EventHandler^ onClickHandler) {
            actionButton2->Text = buttonText;
            actionButton2->Click += onClickHandler;
        }

        void HideActionButtons() {
            this->actionButton1->Visible = false;
            this->actionButton2->Visible = false;
        }

        // Show loading bar
        void ShowLoadingBar(bool visible) {
            this->loadingBar->Visible = visible;
        }

        // Show popup with fade-in effect
        void ShowPopup() {
            this->Opacity = 0.0;
            this->fadeInTimer->Start();
            this->ShowDialog();
        }

        // Close popup with fade-out effect
        void ClosePopup() {
            this->fadeInTimer->Stop();
            this->fadeOutTimer->Start();
        }

    private:
        void FadeIn(System::Object^ sender, System::EventArgs^ e) {
            if (this->Opacity < 1.0) {
                this->Opacity = Math::Min(1.0, this->Opacity + opacityIncrement);
            }
            else {
                fadeInTimer->Stop();
            }
        }

        void FadeOut(System::Object^ sender, System::EventArgs^ e) {
            if (this->Opacity > 0.0) {
                this->Opacity = Math::Max(0.0, this->Opacity - opacityIncrement);
            } else {
                fadeOutTimer->Stop();
                this->Close();
            }
        }

    protected:
        ~PopupForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->components = gcnew System::ComponentModel::Container();
            this->Size = System::Drawing::Size(400, 250);
            this->Text = L"PopupForm";
            this->Padding = System::Windows::Forms::Padding(0);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->BackColor = System::Drawing::Color::FromArgb(110, 84, 181);
            this->Opacity = 0.0;

            // Message Label
            this->messageLabel = gcnew System::Windows::Forms::Label();
            this->messageLabel->AutoSize = false;
            this->messageLabel->Size = System::Drawing::Size(360, 80); // Adjusted width
            this->messageLabel->Location = System::Drawing::Point(
                (this->Width - messageLabel->Width) / 2,  // Center horizontally
                (this->Height - messageLabel->Height) / 2 - 30  // Center vertically with offset
            );
            this->messageLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->messageLabel->Font = gcnew System::Drawing::Font("Arial Rounded MT", 12);
            this->messageLabel->ForeColor = System::Drawing::Color::White;
            this->Controls->Add(this->messageLabel);

            // Action Button1 (OK) - Bottom Right
            this->actionButton1 = gcnew System::Windows::Forms::Button();
            this->actionButton1->Size = System::Drawing::Size(100, 40);
            this->actionButton1->Font = gcnew System::Drawing::Font("Arial Rounded MT", 8);
            this->actionButton1->Text = "OK";
            this->actionButton1->BackColor = System::Drawing::Color::FromArgb(110, 84, 181);
            this->actionButton1->ForeColor = System::Drawing::Color::White;
            this->actionButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->actionButton1->Location = System::Drawing::Point(
                this->Width - actionButton1->Width - 20,  // 20 pixels from right edge
                this->Height - actionButton1->Height - 40  // 20 pixels from bottom edge
            );
            this->actionButton1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                System::Windows::Forms::AnchorStyles::Bottom |
                System::Windows::Forms::AnchorStyles::Right
                );
            this->Controls->Add(this->actionButton1);

            // Action Button2 (Cancel) - Bottom Left
            this->actionButton2 = gcnew System::Windows::Forms::Button();
            this->actionButton2->Size = System::Drawing::Size(100, 40);
            this->actionButton2->Font = gcnew System::Drawing::Font("Arial Rounded MT", 8);
            this->actionButton2->Text = "Cancel";
            this->actionButton2->BackColor = System::Drawing::Color::White;
            this->actionButton2->ForeColor = System::Drawing::Color::FromArgb(82, 70, 148);
            this->actionButton2->FlatAppearance->BorderSize = 0;
            this->actionButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->actionButton2->Location = System::Drawing::Point(
                3,  // 3 pixels from left edge
                this->Height - actionButton2->Height - 40  // 20 pixels from bottom edge
            );
            this->actionButton2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                System::Windows::Forms::AnchorStyles::Bottom |
                System::Windows::Forms::AnchorStyles::Left
                );
            this->Controls->Add(this->actionButton2);

            // Loading Bar
            this->loadingBar = gcnew System::Windows::Forms::ProgressBar();
            this->loadingBar->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
            this->loadingBar->MarqueeAnimationSpeed = 30;
            this->loadingBar->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->loadingBar->Height = 20;
            this->loadingBar->Visible = false;
            this->Controls->Add(this->loadingBar);
        }
#pragma endregion
    };
}
