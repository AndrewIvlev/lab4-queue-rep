#pragma once

#include "stdafx.h"
#include "TQueue.h"

namespace lab4queue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		TQueue<int> *pQueue;
		Graphics^ gr;
		float su; //стартовый угол
		float ku; //конечный угол
		int PofExt; // вероятность извелчения в очередь
		int PofAdd; // вероятность добавления в очередь
		int MaxSize; // максимальный размер очереди
		int Size; // текущий размер очереди
		int numadd; //количество добавленных
		int numext; //количество извлеченных
		//Коллизии:
		int colfullque; //сколько раз пытались добавить в полную очередь
		int colempque;  //сколько раз пытались извлечь из пустой
	private: System::Windows::Forms::Button^  stop_button;
	private: System::Windows::Forms::Timer^  timer;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			gr = this->CreateGraphics();
			timer->Interval = 333;
			timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
		//	this->timer->Tick += gcnew System::EventHandler(this, &Form1::start_button_Click);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  start_button;
	private: System::Windows::Forms::Label^  number_of_added;
	private: System::Windows::Forms::Label^  number_of_retrieved;
	private: System::Windows::Forms::Label^  collisions;
	private: System::Windows::Forms::Label^  ext_collision;
	private: System::Windows::Forms::Label^  Add_colision;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->number_of_added = (gcnew System::Windows::Forms::Label());
			this->number_of_retrieved = (gcnew System::Windows::Forms::Label());
			this->collisions = (gcnew System::Windows::Forms::Label());
			this->ext_collision = (gcnew System::Windows::Forms::Label());
			this->Add_colision = (gcnew System::Windows::Forms::Label());
			this->stop_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(92, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(92, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Location = System::Drawing::Point(92, 69);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Location = System::Drawing::Point(92, 95);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"MaxSize";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"StartSize";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"PofExtract";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 99);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"PofAdding";
			// 
			// start_button
			// 
			this->start_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->start_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->start_button->Location = System::Drawing::Point(43, 126);
			this->start_button->Name = L"start_button";
			this->start_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->start_button->Size = System::Drawing::Size(95, 38);
			this->start_button->TabIndex = 8;
			this->start_button->Text = L"START";
			this->start_button->UseVisualStyleBackColor = true;
			this->start_button->Click += gcnew System::EventHandler(this, &Form1::start_button_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// number_of_added
			// 
			this->number_of_added->AutoSize = true;
			this->number_of_added->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->number_of_added->Location = System::Drawing::Point(44, 187);
			this->number_of_added->Name = L"number_of_added";
			this->number_of_added->Size = System::Drawing::Size(94, 16);
			this->number_of_added->TabIndex = 9;
			this->number_of_added->Text = L"Added 0 items";
			// 
			// number_of_retrieved
			// 
			this->number_of_retrieved->AutoSize = true;
			this->number_of_retrieved->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->number_of_retrieved->Location = System::Drawing::Point(44, 217);
			this->number_of_retrieved->Name = L"number_of_retrieved";
			this->number_of_retrieved->Size = System::Drawing::Size(107, 16);
			this->number_of_retrieved->TabIndex = 10;
			this->number_of_retrieved->Text = L"0 items removed";
			// 
			// collisions
			// 
			this->collisions->AutoSize = true;
			this->collisions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->collisions->Location = System::Drawing::Point(5, 242);
			this->collisions->Name = L"collisions";
			this->collisions->Size = System::Drawing::Size(69, 16);
			this->collisions->TabIndex = 11;
			this->collisions->Text = L"Collisions:";
			// 
			// ext_collision
			// 
			this->ext_collision->AutoSize = true;
			this->ext_collision->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->ext_collision->Location = System::Drawing::Point(44, 294);
			this->ext_collision->Name = L"ext_collision";
			this->ext_collision->Size = System::Drawing::Size(266, 16);
			this->ext_collision->TabIndex = 12;
			this->ext_collision->Text = L"0 times tried to extract from the empty queue";
			// 
			// Add_colision
			// 
			this->Add_colision->AutoSize = true;
			this->Add_colision->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Add_colision->Location = System::Drawing::Point(44, 269);
			this->Add_colision->Name = L"Add_colision";
			this->Add_colision->Size = System::Drawing::Size(215, 16);
			this->Add_colision->TabIndex = 13;
			this->Add_colision->Text = L"0 times tried to add to the full queue";
			// 
			// stop_button
			// 
			this->stop_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->stop_button->Enabled = false;
			this->stop_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->stop_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->stop_button->Location = System::Drawing::Point(400, 120);
			this->stop_button->Name = L"stop_button";
			this->stop_button->Size = System::Drawing::Size(74, 50);
			this->stop_button->TabIndex = 14;
			this->stop_button->Text = L"STOP";
			this->stop_button->UseVisualStyleBackColor = true;
			this->stop_button->Click += gcnew System::EventHandler(this, &Form1::stop_button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(624, 322);
			this->Controls->Add(this->stop_button);
			this->Controls->Add(this->Add_colision);
			this->Controls->Add(this->ext_collision);
			this->Controls->Add(this->collisions);
			this->Controls->Add(this->number_of_retrieved);
			this->Controls->Add(this->number_of_added);
			this->Controls->Add(this->start_button);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Round Queue";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_button_Click(System::Object^  sender, System::EventArgs^  e) {
				gr->FillPie(Brushes::LightSteelBlue, 300.f, 50.f, 350.f, 200.f, 0.f, 360.f);
				numadd = numext = colfullque = colempque = 0;
				srand(time(0));
				MaxSize = Convert::ToUInt32(textBox1->Text);
				Size = Convert::ToUInt32(textBox2->Text);
				pQueue = new TQueue<int>(MaxSize);
				for ( int i = 0; i < Size; i++ )
					pQueue->push(rand() % 100 + 1);
				PofExt = Convert::ToUInt32(textBox3->Text);
				PofAdd = Convert::ToUInt32(textBox4->Text);

				
				su = ((float)( 360 * pQueue->First() )) / pQueue->GetMaxSize();
				ku = ((float)( 360 * pQueue->GetSize() )) / pQueue->GetMaxSize();
				gr->FillPie(Brushes::Red, 320.f, 30.f, 230.f, 230.f, su, ku);
				gr->FillPie(Brushes::LightSteelBlue, 350.f, 61.f, 170.f, 170.f, su, ku);

				this->stop_button->Enabled = true;
				this->start_button->Enabled = false;
				timer->Start();
			}
	private: System::Void stop_button_Click(System::Object^  sender, System::EventArgs^  e) {
				timer->Stop();
				ext_collision->Text = L"0 times tried to extract from the empty queue";
				Add_colision->Text = L"0 times tried to add to the full queue";
				number_of_retrieved->Text = L"0 items removed";
				number_of_added->Text = L"Added 0 items";
				this->start_button->Enabled = true;
			}
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
				int rint = rand() % 100 + 1;
				if ( rint < PofAdd ) {
					if ( !pQueue->isfull() ) {
						number_of_added->Text = L"Added " + Convert::ToString(++numadd) + " items";
						pQueue->push(rint);
						ku = ((float)( 360 * pQueue->GetSize() )) / pQueue->GetMaxSize();
						gr->FillPie(Brushes::Red, 320.f, 30.f, 230.f, 230.f, su, ku);
						gr->FillPie(Brushes::LightSteelBlue, 350.f, 61.f, 170.f, 170.f, su, ku);
					} else { Add_colision->Text = Convert::ToString(++colfullque) + L" times tried to add to the full queue"; }
				}
				rint = rand() % 100 + 1;
				if ( rint < PofExt ) {
					if ( !pQueue->isempty() ) {
						number_of_retrieved->Text = Convert::ToString(++numext) + L" items removed";
						pQueue->pop();
						gr->FillPie(Brushes::LightSteelBlue, 320.f, 30.f, 230.f, 230.f, su, ku);
						su = ((float)( 360 * pQueue->First() )) / pQueue->GetMaxSize();
						gr->FillPie(Brushes::Red, 320.f, 30.f, 230.f, 230.f, su, ku);
						gr->FillPie(Brushes::LightSteelBlue, 350.f, 61.f, 170.f, 170.f, su, ku);
					} else { ext_collision->Text = Convert::ToString(++colempque) + L" times tried to extract from the empty queue"; }
				}
			}
};
}