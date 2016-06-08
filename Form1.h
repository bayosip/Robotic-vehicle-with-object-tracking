#pragma once
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "ImageProcessing.h"
#include "SerialComm.h"

int i;
int H_MIN = 0;
int H_MAX = 256 ;
int S_MIN = 0;
int S_MAX = 256;
int V_MIN = 0;
int V_MAX = 256;
int xPos = 0;
int objSensitivity = 10;
bool trackObjects = false;

	//image matrix storage
	cv::Mat cameraFeed;
	//matrix storage for HSV image
	cv::Mat HSV;
	//matrix storage for binary threshold image
	cv::Mat threshold;
	cv::VideoCapture capture;

namespace testui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	//using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  portComboBox;
	protected: 
	private: System::Windows::Forms::ComboBox^  brComboBox;
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::Button^  openButton;


	private: System::Windows::Forms::ProgressBar^  indicatorBar;
	private: System::Windows::Forms::Button^  SearchButton;
	private: System::Windows::Forms::RichTextBox^  outputTextBox;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  revButton;
	private: System::Windows::Forms::Button^  rgtButton;



	private: System::Windows::Forms::Button^  fwdButton;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TrackBar^  smaxTrackBar;

	private: System::Windows::Forms::TrackBar^  vminTrackBar;
	private: System::Windows::Forms::TrackBar^  vmaxTrackBar;


	private: System::Windows::Forms::TrackBar^  sminTrackBar;
	private: System::Windows::Forms::TrackBar^  hmaxTrackBar;
	private: System::Windows::Forms::TrackBar^  hminTrackBar;





	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  vmaxCounter;

	private: System::Windows::Forms::NumericUpDown^  smaxCounter;


	private: System::Windows::Forms::NumericUpDown^  hmaxCounter;


	private: System::Windows::Forms::NumericUpDown^  vminCounter;


	private: System::Windows::Forms::NumericUpDown^  sminCounter;

	private: System::Windows::Forms::NumericUpDown^  hminCounter;
	private: System::Windows::Forms::Button^  startButton;

	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox4;




	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::NumericUpDown^  sensitivityCounter;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TrackBar^  sensitivityTrackBar;
	private: System::Windows::Forms::Button^  readButton;

	private:
		ImageProcessing camfun;
private: System::Windows::Forms::Button^  trackButton;
		 SerialComm serial;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->portComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->brComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->indicatorBar = (gcnew System::Windows::Forms::ProgressBar());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->outputTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->readButton = (gcnew System::Windows::Forms::Button());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->revButton = (gcnew System::Windows::Forms::Button());
			this->rgtButton = (gcnew System::Windows::Forms::Button());
			this->fwdButton = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->trackButton = (gcnew System::Windows::Forms::Button());
			this->sensitivityCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->sensitivityTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->vmaxCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->smaxCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->hmaxCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->vminCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->sminCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->hminCounter = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->smaxTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->vminTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->vmaxTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->sminTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->hmaxTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->hminTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sensitivityCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sensitivityTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vmaxCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smaxCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hmaxCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vminCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sminCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hminCounter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smaxTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vminTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vmaxTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sminTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hmaxTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hminTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// portComboBox
			// 
			this->portComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->portComboBox->FormattingEnabled = true;
			this->portComboBox->Location = System::Drawing::Point(147, 34);
			this->portComboBox->Margin = System::Windows::Forms::Padding(2);
			this->portComboBox->Name = L"portComboBox";
			this->portComboBox->Size = System::Drawing::Size(108, 25);
			this->portComboBox->TabIndex = 0;
			// 
			// brComboBox
			// 
			this->brComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->brComboBox->FormattingEnabled = true;
			this->brComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"9600", L"115200"});
			this->brComboBox->Location = System::Drawing::Point(147, 84);
			this->brComboBox->Margin = System::Windows::Forms::Padding(2);
			this->brComboBox->Name = L"brComboBox";
			this->brComboBox->Size = System::Drawing::Size(108, 25);
			this->brComboBox->TabIndex = 1;
			// 
			// closeButton
			// 
			this->closeButton->Enabled = false;
			this->closeButton->Location = System::Drawing::Point(258, 115);
			this->closeButton->Margin = System::Windows::Forms::Padding(2);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(86, 32);
			this->closeButton->TabIndex = 2;
			this->closeButton->Text = L"close";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &Form1::closeButton_Click);
			// 
			// openButton
			// 
			this->openButton->Location = System::Drawing::Point(74, 115);
			this->openButton->Margin = System::Windows::Forms::Padding(2);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(86, 32);
			this->openButton->TabIndex = 3;
			this->openButton->Text = L"open";
			this->openButton->UseVisualStyleBackColor = true;
			this->openButton->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// indicatorBar
			// 
			this->indicatorBar->Location = System::Drawing::Point(4, 365);
			this->indicatorBar->Margin = System::Windows::Forms::Padding(2);
			this->indicatorBar->Name = L"indicatorBar";
			this->indicatorBar->Size = System::Drawing::Size(75, 19);
			this->indicatorBar->TabIndex = 4;
			// 
			// SearchButton
			// 
			this->SearchButton->Location = System::Drawing::Point(258, 24);
			this->SearchButton->Margin = System::Windows::Forms::Padding(2);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(86, 32);
			this->SearchButton->TabIndex = 5;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &Form1::SearchButton_Click);
			// 
			// outputTextBox
			// 
			this->outputTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->outputTextBox->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->outputTextBox->Enabled = false;
			this->outputTextBox->Location = System::Drawing::Point(4, 388);
			this->outputTextBox->Margin = System::Windows::Forms::Padding(2);
			this->outputTextBox->Name = L"outputTextBox";
			this->outputTextBox->Size = System::Drawing::Size(341, 279);
			this->outputTextBox->TabIndex = 6;
			this->outputTextBox->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->groupBox1->Controls->Add(this->readButton);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->revButton);
			this->groupBox1->Controls->Add(this->rgtButton);
			this->groupBox1->Controls->Add(this->fwdButton);
			this->groupBox1->Controls->Add(this->SearchButton);
			this->groupBox1->Controls->Add(this->indicatorBar);
			this->groupBox1->Controls->Add(this->outputTextBox);
			this->groupBox1->Controls->Add(this->portComboBox);
			this->groupBox1->Controls->Add(this->brComboBox);
			this->groupBox1->Controls->Add(this->closeButton);
			this->groupBox1->Controls->Add(this->openButton);
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(897, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(349, 678);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Remote Control Box";
			// 
			// readButton
			// 
			this->readButton->Enabled = false;
			this->readButton->Location = System::Drawing::Point(170, 115);
			this->readButton->Name = L"readButton";
			this->readButton->Size = System::Drawing::Size(75, 32);
			this->readButton->TabIndex = 19;
			this->readButton->Text = L"Read";
			this->readButton->UseVisualStyleBackColor = true;
			this->readButton->Click += gcnew System::EventHandler(this, &Form1::readButton_Click_1);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(19, 233);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(57, 21);
			this->radioButton3->TabIndex = 17;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Fast";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(19, 205);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(77, 21);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Normal";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(19, 178);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(59, 21);
			this->radioButton1->TabIndex = 15;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Slow";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 87);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 17);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Select Baud Rate:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(50, 39);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 17);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Select Port:";
			// 
			// button7
			// 
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->button7->Location = System::Drawing::Point(74, 274);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(86, 53);
			this->button7->TabIndex = 11;
			this->button7->Text = L"Left";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// revButton
			// 
			this->revButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Red;
			this->revButton->Location = System::Drawing::Point(159, 331);
			this->revButton->Margin = System::Windows::Forms::Padding(2);
			this->revButton->Name = L"revButton";
			this->revButton->Size = System::Drawing::Size(86, 53);
			this->revButton->TabIndex = 10;
			this->revButton->Text = L"Reverse";
			this->revButton->UseVisualStyleBackColor = true;
			this->revButton->Click += gcnew System::EventHandler(this, &Form1::revButton_Click);
			// 
			// rgtButton
			// 
			this->rgtButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->rgtButton->Location = System::Drawing::Point(244, 274);
			this->rgtButton->Margin = System::Windows::Forms::Padding(2);
			this->rgtButton->Name = L"rgtButton";
			this->rgtButton->Size = System::Drawing::Size(86, 53);
			this->rgtButton->TabIndex = 9;
			this->rgtButton->Text = L"Right";
			this->rgtButton->UseVisualStyleBackColor = true;
			this->rgtButton->Click += gcnew System::EventHandler(this, &Form1::rgtButton_Click);
			// 
			// fwdButton
			// 
			this->fwdButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->fwdButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Lime;
			this->fwdButton->Location = System::Drawing::Point(159, 217);
			this->fwdButton->Margin = System::Windows::Forms::Padding(2);
			this->fwdButton->Name = L"fwdButton";
			this->fwdButton->Size = System::Drawing::Size(86, 53);
			this->fwdButton->TabIndex = 8;
			this->fwdButton->Text = L"Forward";
			this->fwdButton->UseVisualStyleBackColor = true;
			this->fwdButton->Click += gcnew System::EventHandler(this, &Form1::fwdButton_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Location = System::Drawing::Point(12, 154);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(131, 111);
			this->groupBox4->TabIndex = 18;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Choose Speed";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Controls->Add(this->pictureBox1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(9, 10);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(450, 718);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Video Stream Box";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(322, 365);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Filter Stream";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 349);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Tracking Stream";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::Desktop;
			this->pictureBox2->Location = System::Drawing::Point(23, 387);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(400, 320);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Desktop;
			this->pictureBox1->Location = System::Drawing::Point(23, 23);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 320);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// cancelButton
			// 
			this->cancelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(1021, 695);
			this->cancelButton->Margin = System::Windows::Forms::Padding(2);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(130, 39);
			this->cancelButton->TabIndex = 9;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &Form1::cancelButton_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->groupBox3->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->groupBox3->Controls->Add(this->trackButton);
			this->groupBox3->Controls->Add(this->sensitivityCounter);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->sensitivityTrackBar);
			this->groupBox3->Controls->Add(this->startButton);
			this->groupBox3->Controls->Add(this->vmaxCounter);
			this->groupBox3->Controls->Add(this->smaxCounter);
			this->groupBox3->Controls->Add(this->hmaxCounter);
			this->groupBox3->Controls->Add(this->vminCounter);
			this->groupBox3->Controls->Add(this->sminCounter);
			this->groupBox3->Controls->Add(this->hminCounter);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->smaxTrackBar);
			this->groupBox3->Controls->Add(this->vminTrackBar);
			this->groupBox3->Controls->Add(this->vmaxTrackBar);
			this->groupBox3->Controls->Add(this->sminTrackBar);
			this->groupBox3->Controls->Add(this->hmaxTrackBar);
			this->groupBox3->Controls->Add(this->hminTrackBar);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(484, 12);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(373, 676);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Filter Controls Box";
			// 
			// trackButton
			// 
			this->trackButton->Location = System::Drawing::Point(19, 604);
			this->trackButton->Name = L"trackButton";
			this->trackButton->Size = System::Drawing::Size(75, 48);
			this->trackButton->TabIndex = 23;
			this->trackButton->Text = L"Track";
			this->trackButton->UseVisualStyleBackColor = true;
			this->trackButton->Click += gcnew System::EventHandler(this, &Form1::trackButton_Click);
			// 
			// sensitivityCounter
			// 
			this->sensitivityCounter->Enabled = false;
			this->sensitivityCounter->Location = System::Drawing::Point(313, 319);
			this->sensitivityCounter->Name = L"sensitivityCounter";
			this->sensitivityCounter->Size = System::Drawing::Size(46, 23);
			this->sensitivityCounter->TabIndex = 22;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(5, 319);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(134, 17);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Object Sensitivity";
			// 
			// sensitivityTrackBar
			// 
			this->sensitivityTrackBar->Enabled = false;
			this->sensitivityTrackBar->Location = System::Drawing::Point(142, 319);
			this->sensitivityTrackBar->Maximum = 100;
			this->sensitivityTrackBar->Minimum = 10;
			this->sensitivityTrackBar->Name = L"sensitivityTrackBar";
			this->sensitivityTrackBar->Size = System::Drawing::Size(164, 45);
			this->sensitivityTrackBar->SmallChange = 5;
			this->sensitivityTrackBar->TabIndex = 20;
			this->sensitivityTrackBar->Value = 10;
			this->sensitivityTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::sensitivityTrackBar_Scroll);
			// 
			// startButton
			// 
			this->startButton->Enabled = false;
			this->startButton->Location = System::Drawing::Point(19, 22);
			this->startButton->Margin = System::Windows::Forms::Padding(2);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(86, 49);
			this->startButton->TabIndex = 19;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// vmaxCounter
			// 
			this->vmaxCounter->Enabled = false;
			this->vmaxCounter->Location = System::Drawing::Point(291, 381);
			this->vmaxCounter->Margin = System::Windows::Forms::Padding(2);
			this->vmaxCounter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->vmaxCounter->Name = L"vmaxCounter";
			this->vmaxCounter->Size = System::Drawing::Size(42, 23);
			this->vmaxCounter->TabIndex = 18;
			// 
			// smaxCounter
			// 
			this->smaxCounter->Enabled = false;
			this->smaxCounter->Location = System::Drawing::Point(218, 381);
			this->smaxCounter->Margin = System::Windows::Forms::Padding(2);
			this->smaxCounter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->smaxCounter->Name = L"smaxCounter";
			this->smaxCounter->Size = System::Drawing::Size(42, 23);
			this->smaxCounter->TabIndex = 17;
			// 
			// hmaxCounter
			// 
			this->hmaxCounter->Enabled = false;
			this->hmaxCounter->Location = System::Drawing::Point(142, 381);
			this->hmaxCounter->Margin = System::Windows::Forms::Padding(2);
			this->hmaxCounter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->hmaxCounter->Name = L"hmaxCounter";
			this->hmaxCounter->Size = System::Drawing::Size(42, 23);
			this->hmaxCounter->TabIndex = 16;
			// 
			// vminCounter
			// 
			this->vminCounter->Enabled = false;
			this->vminCounter->Location = System::Drawing::Point(291, 21);
			this->vminCounter->Margin = System::Windows::Forms::Padding(2);
			this->vminCounter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->vminCounter->Name = L"vminCounter";
			this->vminCounter->Size = System::Drawing::Size(42, 23);
			this->vminCounter->TabIndex = 15;
			// 
			// sminCounter
			// 
			this->sminCounter->Enabled = false;
			this->sminCounter->Location = System::Drawing::Point(218, 23);
			this->sminCounter->Margin = System::Windows::Forms::Padding(2);
			this->sminCounter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->sminCounter->Name = L"sminCounter";
			this->sminCounter->Size = System::Drawing::Size(42, 23);
			this->sminCounter->TabIndex = 14;
			// 
			// hminCounter
			// 
			this->hminCounter->Enabled = false;
			this->hminCounter->Location = System::Drawing::Point(142, 23);
			this->hminCounter->Margin = System::Windows::Forms::Padding(2);
			this->hminCounter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {256, 0, 0, 0});
			this->hminCounter->Name = L"hminCounter";
			this->hminCounter->Size = System::Drawing::Size(42, 23);
			this->hminCounter->TabIndex = 13;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(278, 620);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(55, 17);
			this->label10->TabIndex = 12;
			this->label10->Text = L"V MAX";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(207, 620);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 17);
			this->label9->TabIndex = 11;
			this->label9->Text = L"S MAX";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(129, 620);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 17);
			this->label8->TabIndex = 10;
			this->label8->Text = L"H MAX";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(278, 259);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 17);
			this->label7->TabIndex = 9;
			this->label7->Text = L"V MIN";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(207, 259);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 17);
			this->label6->TabIndex = 8;
			this->label6->Text = L"S MIN";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(129, 259);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"H MIN";
			// 
			// smaxTrackBar
			// 
			this->smaxTrackBar->BackColor = System::Drawing::Color::DarkGreen;
			this->smaxTrackBar->Enabled = false;
			this->smaxTrackBar->Location = System::Drawing::Point(218, 414);
			this->smaxTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->smaxTrackBar->Maximum = 256;
			this->smaxTrackBar->Name = L"smaxTrackBar";
			this->smaxTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->smaxTrackBar->Size = System::Drawing::Size(45, 203);
			this->smaxTrackBar->TabIndex = 6;
			this->smaxTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::smaxTrackBar_Scroll);
			// 
			// vminTrackBar
			// 
			this->vminTrackBar->BackColor = System::Drawing::Color::LightBlue;
			this->vminTrackBar->Enabled = false;
			this->vminTrackBar->Location = System::Drawing::Point(291, 54);
			this->vminTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->vminTrackBar->Maximum = 256;
			this->vminTrackBar->Name = L"vminTrackBar";
			this->vminTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->vminTrackBar->Size = System::Drawing::Size(45, 203);
			this->vminTrackBar->TabIndex = 5;
			this->vminTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::vminTrackBar_Scroll);
			// 
			// vmaxTrackBar
			// 
			this->vmaxTrackBar->BackColor = System::Drawing::Color::DarkBlue;
			this->vmaxTrackBar->Enabled = false;
			this->vmaxTrackBar->Location = System::Drawing::Point(291, 414);
			this->vmaxTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->vmaxTrackBar->Maximum = 256;
			this->vmaxTrackBar->Name = L"vmaxTrackBar";
			this->vmaxTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->vmaxTrackBar->Size = System::Drawing::Size(45, 203);
			this->vmaxTrackBar->TabIndex = 4;
			this->vmaxTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::vmaxTrackBar_Scroll);
			// 
			// sminTrackBar
			// 
			this->sminTrackBar->BackColor = System::Drawing::Color::LightGreen;
			this->sminTrackBar->Enabled = false;
			this->sminTrackBar->Location = System::Drawing::Point(218, 54);
			this->sminTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->sminTrackBar->Maximum = 256;
			this->sminTrackBar->Name = L"sminTrackBar";
			this->sminTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->sminTrackBar->Size = System::Drawing::Size(45, 203);
			this->sminTrackBar->TabIndex = 3;
			this->sminTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::sminTrackBar_Scroll);
			// 
			// hmaxTrackBar
			// 
			this->hmaxTrackBar->BackColor = System::Drawing::Color::DarkRed;
			this->hmaxTrackBar->Enabled = false;
			this->hmaxTrackBar->Location = System::Drawing::Point(142, 414);
			this->hmaxTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->hmaxTrackBar->Maximum = 256;
			this->hmaxTrackBar->Name = L"hmaxTrackBar";
			this->hmaxTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->hmaxTrackBar->Size = System::Drawing::Size(45, 203);
			this->hmaxTrackBar->TabIndex = 2;
			this->hmaxTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::hmaxTrackBar_Scroll);
			// 
			// hminTrackBar
			// 
			this->hminTrackBar->BackColor = System::Drawing::Color::LightPink;
			this->hminTrackBar->Enabled = false;
			this->hminTrackBar->Location = System::Drawing::Point(142, 54);
			this->hminTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->hminTrackBar->Maximum = 256;
			this->hminTrackBar->Name = L"hminTrackBar";
			this->hminTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->hminTrackBar->Size = System::Drawing::Size(45, 203);
			this->hminTrackBar->TabIndex = 1;
			this->hminTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::himTrackBar_Scroll);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1255, 739);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sensitivityCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sensitivityTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vmaxCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smaxCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hmaxCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vminCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sminCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hminCounter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smaxTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vminTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->vmaxTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sminTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hmaxTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hminTrackBar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


private: void sendCamInfoToRobo(int x){
		 
			// add sender name
				 String^ name = this->serialPort1->PortName;
			 //Grab command to send to buffer7
			 System::String^ command = x.ToString();

			 //Write to Serial port
			 if(this->serialPort1->IsOpen){
				 
				this->serialPort1->WriteLine(command);
				Sleep(1000);
			 }
				else{
					MessageBox::Show("Port not Opened!!!");
				}
		 }


	private: System::Void SearchButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->portComboBox->Items->AddRange(serial.findPorts());
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				this->outputTextBox->Text=String::Empty;
				if(this->portComboBox->Text==String::Empty || this->brComboBox->Text==String::Empty)
					this->outputTextBox->Text="Please Select Port Settings";
				else {
					String^ pName = this->portComboBox->Text;
						String^ bRate = this->brComboBox->Text;
					if (serial.openPort(serialPort1,pName,bRate)){
				
						this->indicatorBar->Value=100;
						this->openButton->Enabled = false;
						this->closeButton->Enabled = true;
						this->readButton -> Enabled =true;
						this -> startButton -> Enabled = true;
					}else{}
				 }
				

		 }
private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 //close serialPort
				 //this->serialPort1->Close();
			 if (serial.closePort(serialPort1)){
				 // update progress bar
				 this->indicatorBar->Value=0;
				 // Enable the init button
				 this->openButton->Enabled = true;
				 this->closeButton->Enabled = false;
				 startButton->Text = "Start";
				this->startButton->Enabled = false;
				this->hmaxTrackBar->Enabled = false;
				this->smaxTrackBar->Enabled = false;
				this->vmaxTrackBar->Enabled = false;
				this->hminTrackBar->Enabled = false;
				this->sminTrackBar->Enabled = false;
				this->vminTrackBar->Enabled = false;
				timer1->Stop();
			 }
				
		 }
private: System::Void himTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 H_MIN = hminTrackBar->Value;
			 this->hminCounter->Value=hminTrackBar->Value;
		 }
private: System::Void sminTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			  S_MIN = sminTrackBar->Value;
			  this->sminCounter->Value=sminTrackBar->Value;
		 }
private: System::Void vminTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 V_MIN = vminTrackBar->Value;
			 this->vminCounter->Value=vminTrackBar->Value;
		 }

		 
private: System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Stop();
			 this->Close();
		 }
private: System::Void hmaxTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 H_MAX = hmaxTrackBar->Value;
			 this->hmaxCounter->Value=hmaxTrackBar->Value;
		 }
private: System::Void smaxTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 S_MAX = smaxTrackBar->Value;
			 this->smaxCounter->Value=smaxTrackBar->Value;
		 }
private: System::Void vmaxTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 V_MAX = vmaxTrackBar->Value;
			 this->vmaxCounter->Value=vmaxTrackBar->Value;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			try{
		//store image to matrix
		capture.read(cameraFeed);
		bool useMorphObjs = true;
		//x and y values for the location of the object
	int x=0, y=0;
	
			if(!cameraFeed.isContinuous()){
				MessageBox::Show("Frame is NULL ");
				this->outputTextBox->Text= String::Empty;//Clear the output screen
				timer1->Stop();
			}
		//convert frame from BGR to HSV colorspace
		cv::cvtColor(cameraFeed,HSV,cv::COLOR_BGR2HSV);

		//filter HSV image between set values and store filtered image to threshold matrix
		cv::inRange(HSV,cv::Scalar(H_MIN,S_MIN,V_MIN),cv::Scalar(H_MAX,S_MAX,V_MAX),threshold);

		//perform morphological operations on thresholded image to eliminate noise
		//and emphasize the filtered object(s)
		if(useMorphObjs)
		camfun.morphObjs(threshold, objSensitivity);

		//pass in thresholded frame to object tracking function in ImageProcessing class
		//this function will return the x and y coordinates of the
		//filtered object
		if(trackObjects)
			xPos = camfun.trackFilteredObject(x,y,threshold,cameraFeed,this->pictureBox1->Width,this->pictureBox1->Height, serialPort1);


			System::Drawing::Graphics^ graphics1 = pictureBox1->CreateGraphics();
			System::IntPtr ptr1(cameraFeed.ptr());
			System::Drawing::Bitmap^ b1  = gcnew System::Drawing::Bitmap(cameraFeed.cols,
			cameraFeed.rows,cameraFeed.step,System::Drawing::Imaging::PixelFormat::Format24bppRgb,ptr1);
			System::Drawing::RectangleF rect1(0,0, this->pictureBox1->Width,this->pictureBox1->Height);
			graphics1->DrawImage(b1,rect1);
			

			System::Drawing::Graphics^ graphics2 = this->pictureBox2->CreateGraphics();
			System::IntPtr ptr2(threshold.ptr());
			System::Drawing::Bitmap^ b2  = gcnew System::Drawing::Bitmap(threshold.cols,
			threshold.rows,threshold.step,System::Drawing::Imaging::PixelFormat::Format8bppIndexed,ptr2);
			System::Drawing::RectangleF rect2(0,0, pictureBox2->Width,pictureBox2->Height);
			graphics2->DrawImage(b2,rect2); 
			
			cv::waitKey(15);
			}catch(...){}
		 }
private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(startButton->Text == "Start")
		{	
		capture.open("http://10.0.1.33:8888/?action=stream.mjpeg");
		if(!capture.isOpened()){// if capture not accessible
			MessageBox::Show("ERROR! Could Not Access Webcam!");
		}
	else{
	capture.set(CV_CAP_PROP_FRAME_WIDTH,this->pictureBox1->Width);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,this->pictureBox1->Height);
				startButton->Text = "Stop";
				timer1->Start();
				this->hmaxTrackBar->Enabled = true;
				this->hmaxTrackBar->Value= H_MAX;
				this->hmaxCounter->Value=hmaxTrackBar->Value;

				this->smaxTrackBar->Enabled = true;
				this->smaxTrackBar->Value= S_MAX;
				this->smaxCounter->Value=smaxTrackBar->Value;

				this->vmaxTrackBar->Enabled = true;
				this->vmaxTrackBar->Value= V_MAX;
				this->vmaxCounter->Value=vmaxTrackBar->Value;
				this->hminTrackBar->Enabled = true;
				this->sminTrackBar->Enabled = true;
				this->vminTrackBar->Enabled = true;
				this->sensitivityTrackBar->Enabled =true;


		}
		}
		else if(startButton->Text == "Stop")
		{
			capture.release();
			startButton->Text = "Start";
			timer1->Stop();
		}
		 }
private: System::Void fwdButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
				
			 //Grab command to send to buffer7
			 System::String^ command = "F";
			  //Write to Serial port
			 serial.sendDataToPort(serialPort1, command);
			 camfun.calculateRotaion(xPos, serialPort1);

			 //Write to Serial port
			  //String^ name = this->serialPort1->PortName;
			 /*if(this->serialPort1->IsOpen){
			

				this->serialPort1->WriteLine(command);
				Sleep(700);
				 
			 }
				else{
					MessageBox::Show("Port not Opened!!!");
				}*/
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 // add sender name
				 
			 //Grab command to send to buffer7
			 System::String^ command = "L";
			  //Write to Serial port
			 serial.sendDataToPort(serialPort1, command);
			 camfun.calculateRotaion(xPos, serialPort1);
			 //String^ name = this->serialPort1->PortName;
			 //Write to Serial port
			 /*if(this->serialPort1->IsOpen){
				 
				this->serialPort1->WriteLine(command);
				Sleep(700);
			 }
				else{
					MessageBox::Show("Port not Opened!!!");
				}*/
		 }
private: System::Void rgtButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 // add sender name
				
			 //Grab command to send to buffer7
			 System::String^ command = "R";
			 serial.sendDataToPort(serialPort1, command);
			 camfun.calculateRotaion(xPos, serialPort1);
			/* //Write to Serial port 
			 String^ name = this->serialPort1->PortName;
			 if(this->serialPort1->IsOpen){
				 
				this->serialPort1->WriteLine(command);
				Sleep(700);
			 }
				else{
					MessageBox::Show("Port not Opened!!!");
				}*/
		 }
private: System::Void revButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 // add sender name
				 
			 //Grab command to send to buffer7
			 System::String^ command = "B";
			 serial.sendDataToPort(serialPort1, command);
			 camfun.calculateRotaion(xPos, serialPort1);
		 }
		  
private: System::Void sensitivityTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 objSensitivity = sensitivityTrackBar->Value;
			 this->sensitivityCounter->Value = sensitivityTrackBar->Value;
		 }
private: System::Void readButton_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 //this->outputTextBox->Text=serial.readFromPort(serialPort1);
		 }
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			  System::String^ command = "S";
			  serial.sendDataToPort(serialPort1, command);
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ command = "N";
			  serial.sendDataToPort(serialPort1, command);
		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ command = "Q";
			  serial.sendDataToPort(serialPort1, command);
		 }
private: System::Void trackButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (trackButton->Text=="Track"){
				 trackObjects = true;
				trackButton->Text= "Stop";
			 }
			 else if (trackButton->Text=="Stop"){
				 trackObjects = false;
				trackButton->Text= "Track";
			 }
		 }
};
}

