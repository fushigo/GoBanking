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

    private:
        System::Windows::Forms::TextBox^ txtIdentitas;
        System::Windows::Forms::TextBox^ txtNama;
        System::Windows::Forms::RadioButton^ rbMale;
        System::Windows::Forms::RadioButton^ rbFemale;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::TextBox^ txtPhone;
        System::Windows::Forms::Label^ lblIdentitas;
        System::Windows::Forms::Label^ lblNama;
        System::Windows::Forms::Label^ lblGender;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::Label^ lblPhone;
        System::Windows::Forms::Panel^ pnlGender;


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

        ref struct FormField {
            String^ label;
            String^ type;  // "text", "radio", "date", "combo"
            cli::array<String^>^ options;  // for radio buttons and combobox
        };

        void CreateFormFields(cli::array<FormField^>^ fields) {
            int yPosition = 20;

            for each (FormField ^ field in fields) {
                Label^ label = gcnew Label();
                label->Text = field->label;
                label->Location = System::Drawing::Point(10, yPosition);
                label->AutoSize = true;
                label->ForeColor = System::Drawing::Color::White;
                label->Font = gcnew System::Drawing::Font("Arial Rounded MT", 10);
                this->Controls->Add(label);

                if (field->type == "text") {
                    TextBox^ textBox = gcnew TextBox();
                    textBox->Name = "txt" + field->label;
                    textBox->Location = System::Drawing::Point(155, yPosition);
                    textBox->Size = System::Drawing::Size(225, 25);
                    textBox->Font = gcnew System::Drawing::Font("Arial Rounded MT", 10);
                    this->Controls->Add(textBox);
                    yPosition += 40;
                }
                else if (field->type == "radio") {
                    Panel^ panel = gcnew Panel();
                    panel->Location = System::Drawing::Point(155, yPosition);
                    panel->Size = System::Drawing::Size(225, 30);

                    int xPos = 0;
                    for each (String ^ option in field->options) {
                        RadioButton^ radio = gcnew RadioButton();
                        radio->Text = option;
                        radio->Location = System::Drawing::Point(xPos, 0);
                        radio->ForeColor = System::Drawing::Color::White;
                        panel->Controls->Add(radio);
                        xPos += 120;
                    }
                    this->Controls->Add(panel);
                    yPosition += 40;
                }
                else if (field->type == "combo") {
                    ComboBox^ combo = gcnew ComboBox();
                    combo->Location = System::Drawing::Point(155, yPosition);
                    combo->Size = System::Drawing::Size(225, 25);
                    combo->Items->AddRange(field->options);
                    this->Controls->Add(combo);
                    yPosition += 40;
                }
            }
        }

        String^ GetFormData() {
            String^ result = "";
            for each (Control ^ control in this->Controls) {
                if (TextBox^ textBox = dynamic_cast<TextBox^>(control)) {
                    Label^ associatedLabel = FindLabel(textBox->Location.Y);
                    if (associatedLabel != nullptr) {
                        result += associatedLabel->Text + ": " + textBox->Text + "\n";
                    }
                }
                else if (Panel^ panel = dynamic_cast<Panel^>(control)) {
                    for each (Control ^ panelControl in panel->Controls) {
                        if (RadioButton^ radio = dynamic_cast<RadioButton^>(panelControl)) {
                            if (radio->Checked) {
                                Label^ associatedLabel = FindLabel(panel->Location.Y);
                                if (associatedLabel != nullptr) {
                                    result += associatedLabel->Text + ": " + radio->Text + "\n";
                                }
                            }
                        }
                    }
                }
            }
            return result;
        }


        // Set message text dynamically
        void SetMessage(String^ message) {
            this->messageLabel->Text = message;
        }

        void SetMessageVisible(bool visible) {
            if (this->messageLabel != nullptr) {
                this->messageLabel->Visible = visible;
                if (!visible) {
                    messageLabel->SendToBack();
                }
                else {
                    messageLabel->BringToFront();
                }
            }
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

        void SetFormSize(int width, int height) {
            this->Size = System::Drawing::Size(width, height);

            if (this->messageLabel != nullptr) {
                this->messageLabel->Location = System::Drawing::Point(
                    (this->Width - messageLabel->Width) / 2,
                    (this->Height - messageLabel->Height) / 2 - 30
                );
            }

            // Automatically adjust button positions when form size changes
            if (this->actionButton1 != nullptr) {
                this->actionButton1->Location = System::Drawing::Point(
                    this->Width - actionButton1->Width - 20,
                    this->Height - actionButton1->Height - 50
                );
            }

            if (this->actionButton2 != nullptr) {
                this->actionButton2->Location = System::Drawing::Point(
                    20,
                    this->Height - actionButton2->Height - 50
                );
            }
        }

        void SetActionButton1Position(int x, int y) {
            if (this->actionButton1 != nullptr) {
                this->actionButton1->Location = System::Drawing::Point(x, y);
            }
        }

        void SetActionButton2Position(int x, int y) {
            if (this->actionButton2 != nullptr) {
                this->actionButton2->Location = System::Drawing::Point(x, y);
            }
        }

    private:

        Label^ FindLabel(int yPosition) {
            for each (Control ^ control in this->Controls) {
                if (Label^ label = dynamic_cast<Label^>(control)) {
                    if (label->Location.Y == yPosition) {
                        return label;
                    }
                }
            }
            return nullptr;
        }

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
                (this->Height - messageLabel->Height) / 2 - 30 // Center vertically with offset
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
                this->Height - actionButton1->Height - 50 // 20 pixels from bottom edge
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
                2,  // 3 pixels from left edge
                this->Height - actionButton2->Height - 50 // 20 pixels from bottom edge
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
