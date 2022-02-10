#pragma once

#include <ctype.h>
#include <stdint.h>
#include <iostream>
#include <sstream>

namespace Spectr9600 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Timers;

	
	/* Globals */

	int ModeRx;

	Byte bytes_sent_num = 2, wait_answer = 0;

	unsigned char number = 0, timer = 1;

	unsigned short int x1 = 0;
	unsigned short int x2 = 0;

	Byte *Pack_Tx = new Byte[5]; // Array of sent bytes (1 pack)

	Byte Array[256];

	Byte i1=0, i2=0;

	Byte bytes_get_num, count_bytes;

	Byte *Pack_Rx = new Byte[5]; // Array of received bytes (1 pack)

	Byte CS_Tx; // Control sum of transferred data
	Byte CS_Rx; // Control sum of received data

	float CS_OK = 0;
	float CS_WR = 0;
	float errors = 0;

	Byte my_addr;
	Byte tx_addr;

	unsigned short int num_packs = 0;
	unsigned short int num_ports = 0;

	unsigned short int quality = 0;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent(); // create Form
			//
			//TODO: добавьте код конструктора
			//			
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				serialPort1->Close();
			}
		}

	private: System::Windows::Forms::CheckBox^  checkBox1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox8;
	public: System::Windows::Forms::Timer^  timer1;

	public:

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Enabled = false;
			this->checkBox1->Location = System::Drawing::Point(365, 77);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(58, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Master";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(57, 315);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(74, 27);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Send";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(254, 315);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(73, 27);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 289);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(270, 20);
			this->textBox1->TabIndex = 4;
			// 
			// serialPort1
			// 
			this->serialPort1->DtrEnable = true;
			this->serialPort1->PortName = L"COM11";
			this->serialPort1->ReadBufferSize = 2048;
			this->serialPort1->RtsEnable = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(54, 273);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Transmission data";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(54, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Received data";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(57, 44);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(271, 208);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(20, 36);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(190, 36);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"My addr";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(187, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Tx addr";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(396, 358);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Connection testing";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 177);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"CS OK";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(187, 239);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Errors";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(20, 193);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 15;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(190, 255);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 16;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(20, 255);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 22;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(190, 315);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 27);
			this->button7->TabIndex = 23;
			this->button7->Text = L"Clear all";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(17, 239);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(60, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Packs sent";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->checkBox3);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->comboBox1);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->checkBox2);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->checkBox1);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(447, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(525, 358);
			this->groupBox3->TabIndex = 30;
			this->groupBox3->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.3F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(411, 193);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(20, 17);
			this->label11->TabIndex = 38;
			this->label11->Text = L"%";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(362, 177);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(101, 13);
			this->label10->TabIndex = 37;
			this->label10->Text = L"Transmission quality";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(365, 193);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(41, 20);
			this->textBox8->TabIndex = 36;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Enabled = false;
			this->checkBox3->Location = System::Drawing::Point(365, 119);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(53, 17);
			this->checkBox3->TabIndex = 35;
			this->checkBox3->Text = L"Slave";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(17, 81);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 13);
			this->label9->TabIndex = 34;
			this->label9->Text = L"COM port";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(20, 98);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 33;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(187, 177);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 13);
			this->label8->TabIndex = 32;
			this->label8->Text = L"CS WR";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(190, 193);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 31;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(365, 36);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(66, 17);
			this->checkBox2->TabIndex = 30;
			this->checkBox2->Text = L"Connect";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(984, 391);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Terminal";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	/*================================================================================================================*/

	/* Connect/disconnect */
	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (checkBox2->Checked == true) {

			checkBox1->Enabled = true;
			checkBox3->Enabled = true;

			try {
				my_addr = Convert::ToByte(textBox2->Text); // Get this PC address
				tx_addr = Convert::ToByte(textBox3->Text); // Get other PC address

				if (my_addr == tx_addr) {

					MessageBox::Show("Addresses must be different");
					checkBox2->Checked = false;
				}
			}

			catch (...) {
				MessageBox::Show("Enter device addresses");
				checkBox2->Checked = false;
				return;
			}

			try {
				num_ports = 0;

				array<String^>^ serialPorts = nullptr;
				serialPorts = SerialPort::GetPortNames();
				comboBox1->Items->Clear();
				for each(String^ port in serialPorts)
				{
					comboBox1->Items->Add(port);
					num_ports++;
				}
			}

			catch (...) {
				MessageBox::Show("COM Port is not found");
				checkBox2->Checked = false;
			}
		}

		else if (checkBox2->Checked == false) {

			backgroundWorker1->CancelAsync();
			backgroundWorker2->CancelAsync();
			serialPort1->Close();
			checkBox1->Checked = false;
			checkBox1->Enabled = false;
			checkBox3->Checked = false;
			checkBox3->Enabled = false;
		}
	}

	/* If PC is master */
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (checkBox1->Checked == true) {

			button2->Enabled = true;
			checkBox3->Checked = false;
			checkBox3->Enabled = false;

			try {
				for (int i = 0; i < num_ports; i++) {

					if (comboBox1->SelectedIndex == i) {

						serialPort1->PortName = comboBox1->Text;
						break;
					}
				}
			}

			catch (...) {
				MessageBox::Show("COM Port is not found");
				checkBox2->Checked = false;
				return;
			}
			
			if (serialPort1->IsOpen == false) {

				try { serialPort1->Open(); timer1->Enabled = true; }

				catch (...) { 
					MessageBox::Show("COM Port is not found"); 
					checkBox1->Checked = false;
				}
			}

			try {
				backgroundWorker2->RunWorkerAsync();
			}

			catch (...) {
				return;
			}
		}

		else if (checkBox1->Checked == false) {

			button2->Enabled = false;
			checkBox3->Enabled = true;
			backgroundWorker2->CancelAsync();
			serialPort1->Close();
		}
	}

	/* If PC is slave */
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (checkBox3->Checked == true) {

			checkBox1->Checked = false;
			checkBox1->Enabled = false;

			try {
				for (int i = 0; i < num_ports; i++) {

					if (comboBox1->SelectedIndex == i) {

						serialPort1->PortName = comboBox1->Text;
						break;
					}
				}
			}

			catch (...) {
				MessageBox::Show("COM Port is not found");
				checkBox2->Checked = false;
				return;
			}
			
			if (serialPort1->IsOpen == false) {

				try { serialPort1->Open(); timer1->Enabled = true; }

				catch (...) {
					MessageBox::Show("COM Port is not found"); 
					checkBox3->Checked = false;
				}
			}

			try {
				backgroundWorker1->RunWorkerAsync();
			}

			catch (...) {
				return;
			}
		}

		else if (checkBox3->Checked == false) {

			checkBox1->Enabled = true;
			backgroundWorker1->CancelAsync();
			serialPort1->Close();
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		timer = 1;
		DispValues();
		DispRxData();
	}

	/* DATA TRANSMISSION */
	public: void DataTransmitted() {

		if (checkBox1->Checked == true) {

			if (timer == 1) {

				if (wait_answer) { errors++; wait_answer = 0; }

				Pack_Tx[0] = tx_addr;
				Pack_Tx[1] = bytes_sent_num;
				Pack_Tx[2] = number & 0xFF;
				Pack_Tx[3] = ((number >> 8) & 0xFF);
				CS_Tx = 0;
				
				for (int i = 0; i < 4; i++) {

					CS_Tx += Pack_Tx[i];
				}

				Pack_Tx[4] = CS_Tx;

				/* Send a pack */
				for (int i = 0; i < 5; i++) {

					try {
						serialPort1->BaseStream->WriteByte(Pack_Tx[i]);
					}

					catch (...) {
						return;
					}
				}

				num_packs++;
				number++;
				timer = 0;
				wait_answer = 1;
			}

			else if (((CS_WR + errors) > CS_OK) && ((CS_WR + errors) != 0)) {
				quality = CS_OK / (CS_WR + errors) * 100;
			}

			/* Get data back */
			if (serialPort1->IsOpen == true) {

				if ((serialPort1->BytesToRead > 0) && (wait_answer)) {

					Array[i1] = Pack_Rx[0] = serialPort1->BaseStream->ReadByte();
					i1++;

					switch (ModeRx)
					{
						/* find addr */
						case 0:
							if (Pack_Rx[0] == my_addr) { ModeRx = 1; CS_Rx = Pack_Rx[0]; }
							break;
	
						/* get num of bytes */
						case 1:
							bytes_get_num = Pack_Rx[0];
							CS_Rx += Pack_Rx[0];
							ModeRx = 2;
							count_bytes = 0;
							break;

						/* get bytes */
						case 2:
							if (count_bytes < bytes_get_num) {
								Pack_Rx[count_bytes + 1] = Pack_Rx[0]; CS_Rx += Pack_Rx[0]; count_bytes++;
							}
							else
							/* get CS */
							{
								Pack_Rx[count_bytes + 1] = Pack_Rx[0];
								if (Pack_Rx[count_bytes + 1] == CS_Rx)
								{
									CS_OK++;
									wait_answer = 0;
								}

								else  CS_WR++;
								ModeRx = 0;
							}
							break;

						default:
						ModeRx = 0;
						break;
					}
				}
			}

			// %
			if ((CS_WR + errors) <= CS_OK) {
				quality = (1 - (CS_WR + errors) / CS_OK) * 100;
			}
		}

		else if (checkBox1->Checked == false) {
			
			backgroundWorker2->CancelAsync(); // Stop data transmission
		}

		/* Get data back */
		if (serialPort1->IsOpen == true) {

			if ((serialPort1->BytesToRead > 0) && (wait_answer)) {

				Array[i1] = Pack_Rx[0] = serialPort1->BaseStream->ReadByte();
				i1++;

				switch (ModeRx)
				{
					/* find addr */
				case 0:
					if (Pack_Rx[0] == my_addr) { ModeRx = 1; CS_Rx = Pack_Rx[0]; }
					break;

					/* get num of bytes */
				case 1:
					bytes_get_num = Pack_Rx[0];
					CS_Rx += Pack_Rx[0];
					ModeRx = 2;
					count_bytes = 0;
					break;

					/* get bytes */
				case 2:
					if (count_bytes < bytes_get_num) {
						Pack_Rx[count_bytes + 1] = Pack_Rx[0]; CS_Rx += Pack_Rx[0]; count_bytes++;
					}
					else
						/* get CS */
					{
						Pack_Rx[count_bytes + 1] = Pack_Rx[0];
						if (Pack_Rx[count_bytes + 1] == CS_Rx)
						{
							CS_OK++;
							wait_answer = 0;
						}

						else  CS_WR++;
						ModeRx = 0;
					}
					break;

				default:
					ModeRx = 0;
					break;
				}
			}
		}

		// %
		if ((CS_WR + errors) <= CS_OK) {
			quality = (1 - (CS_WR + errors) / CS_OK) * 100;
		}


	}

	private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		for (;;) {
			DataTransmitted();
		}
	}

	/* DATA RECEIVING */
	public: void DataReceived()	{
		
		try {
			if (checkBox3->Checked == true) {

				if (serialPort1->IsOpen == true) {

					/* If have some data in buffer, read it and send it back */
					if (serialPort1->BytesToRead > 0) {

						Array[i1] = Pack_Rx[0] = serialPort1->BaseStream->ReadByte();
						i1++;

						switch (ModeRx)
						{
						case 0:
							if (Pack_Rx[0] == my_addr) { ModeRx = 1; CS_Rx = Pack_Rx[0]; }
							break;

						case 1:
							bytes_get_num = Pack_Rx[0];
							CS_Rx += Pack_Rx[0];
							ModeRx = 2;
							count_bytes = 0;
							break;

						case 2:
							if (count_bytes < bytes_get_num) { Pack_Rx[count_bytes + 1] = Pack_Rx[0]; CS_Rx += Pack_Rx[0]; count_bytes++; }
							else
							{ 
								Pack_Rx[count_bytes + 1] = Pack_Rx[0];  
								if (Pack_Rx[count_bytes + 1] == CS_Rx)
								{
									CS_OK++;
									x2 = x1;
									x1 = Pack_Rx[1] + (Pack_Rx[2] << 8);

									if ((x1 > 0) && (x2 > 0) && (x1 > x2)) {
										errors += (x1 - x2 - 1); 
									}

									Pack_Rx[0] = tx_addr; 
									Pack_Rx[1] = 2; 
									Pack_Rx[2] = x1;
									Pack_Rx[3] = x1 >> 8;
									CS_Tx = 0;

									for (int i = 0; i < Pack_Rx[1] + 2; i++) {

										CS_Tx += Pack_Rx[i];
									}

									Pack_Rx[4] = CS_Tx;

									System::Threading::Thread::Sleep(100);

									/* Answer */
									for (int i = 0; i < 5; i++) {

										try {
											serialPort1->BaseStream->WriteByte(Pack_Rx[i]);
										}

										catch (...) {
											return;
										}
									}
								}
								else  CS_WR++;
								ModeRx = 0;
							}
							break;

						default:
							ModeRx = 0;
							break;
						}

						// %
						if ((CS_WR + errors) <= CS_OK) {
							quality = (1 - (CS_WR + errors) / CS_OK) * 100;
						}

						else if (((CS_WR + errors) > CS_OK) && ((CS_WR + errors) != 0)) {
							quality = CS_OK / (CS_WR + errors) * 100;
						}
					}
				}
			}

			else if (checkBox3->Checked == false) {

				backgroundWorker1->CancelAsync();
			}
		}

		catch (...) {		
			return;
		}
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	
		for (;;) {

			DataReceived();
		}
	}
	
	/*================================================================================================================*/

	/* Show number of sent/received bytes and errors */
	public: void DispValues() {

		textBox4->Text = Convert::ToString(CS_OK); 
		textBox6->Text = Convert::ToString(num_packs);    
		textBox5->Text = Convert::ToString(errors);  
		textBox7->Text = Convert::ToString(CS_WR);
		textBox8->Text = Convert::ToString(quality);
	}

	public: void DispRxData() {

		Byte value;

		if (serialPort1->IsOpen == true) {

			try {			
				for (int i = 0; i < (i1 - i2); i++) {
					
					value = Array[i2 + i]; //Convert::ToByte(Array[i2 + i]);				
					String^ hex_val = String::Format("{0:X}", value); // convert value to a hexadecimal in string form

					richTextBox1->AppendText(Convert::ToString(hex_val));
					richTextBox1->AppendText("\n");
					richTextBox1->ScrollToCaret();
				}
				i2 = i1;
			}

			catch (...) {}
		}
		else {}
	}

	/* Transmit data */
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		try {
			String ^Tx_data = Convert::ToString(textBox1->Text); // Get data from textbox
			serialPort1->WriteLine(Tx_data);
		}

		catch (...) {
			MessageBox::Show("Error!");
			textBox1->Clear();
			return;
		}
	}

	/* Clear field of trasmission data */
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		textBox1->Clear();
	}

	/* Clear all values */
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	
		textBox4->Clear();
		textBox5->Clear();
		textBox6->Clear();
		textBox7->Clear();
		textBox8->Clear();
		richTextBox1->Clear();
		num_packs = 0;
		errors = 0;
		CS_OK = 0;
		CS_WR = 0;
		x1 = 0;
		x2 = 0;
		quality = 0;
	}

	/*================================================================================================================*/

	//delegate void Rx_deleg(String ^); // Create a delegate to write received data

	/*private: void SetText(String ^Rx_data) {

		Rx_data = serialPort1->ReadExisting(); // Read all available bytes

		if (this->richTextBox1->InvokeRequired) {

			Rx_deleg ^d = gcnew Rx_deleg(this, &MyForm::SetText);
			this->Invoke(d, gcnew array<Object^> {Rx_data});
		}

		else {

			this->richTextBox1->Text = Rx_data;
		}

		this->richTextBox1->Text = Rx_data;
	}*/
};
}
