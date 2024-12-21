#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Windows::Forms;
using namespace System::ComponentModel;

public ref class RoundedControlProperties {
public:
	property float Radius;
	property Color BorderColor;
	property float BorderSize;
	property Color BackgroundColor;
	property bool GradientBackground;
	property Color GradientColor1;
	property Color GradientColor2;
	property LinearGradientMode GradientDirection;
};