#pragma once

#include "conio.h"
#include "windows.h"

struct BTree {
	int info;
	struct BTree* left;
	struct BTree* right;
};

struct BTree* stree(BTree* r, int val) {

	if (r == 0) {
		r = new BTree;
		r->info = val;
		r->left = 0;
		r->right = 0;
	}
	else
	{
		if (val <= r->info)
		{
			r->left = stree(r->left, val);
		}

		else
		{
			r->right = stree(r->right, val);
		}
	}
	return r;
}

struct BTree* dtree(BTree* r, int key)
{
	struct BTree* p, * p2;
	if (r == 0)
	{
		return r;
	}
	if (r->info == key)
	{
		if (r->left == r->right)
		{
			delete r;
			return 0;
		}
		else if (r->left == 0)
		{
			p = r->right;
			delete r;
			return p;
		}
		else if (r->right == 0)
		{
			p = r->left;
			delete r;
			return p;
		}
		else
		{
			p2 = r->right;
			p = r->right;
			while (p->left)
			{
				p = p->left;
			}
			p->left = r->left;
			delete r;
			return p2;
		}
	}
	if (r->info < key)
	{
		r->right = dtree(r->right, key);
	}
	else
	{
		r->left = dtree(r->left, key);
	}
	return r;
}

//функция вывода
void output(BTree* r, int* s, bool flag)
{
	static int i = 0;
	if (flag == true)
	{
		flag = false;
		i = 0;
	}
	if (r != 0)
	{
		output(r->left, s, flag);
		output(r->right, s, flag);
		s[i] = r->info;
		i++;
	}
}

//функция удаления
void del(BTree* r)
{
	if (r != 0)
	{
		del(r->left);
		del(r->right);
		delete r;
	}
}

//функция получения минимального поля
int getMinField(BTree* tree)
{
	int field = tree->info;
	if (tree->left != NULL)
	{
		field = getMinField(tree->left);
	}
	return field;
}

//функция подсчета узлов с значениями
int getCountNodesWithValue(int value, BTree* tree, int counter = 0) {
	if (tree != NULL)
	{
		if (tree->info == value)
		{
			counter++;
		}

		if (value <= tree->info)
		{
			counter = getCountNodesWithValue(value, tree->left, counter);
		}
		else
		{
			counter = getCountNodesWithValue(value, tree->right, counter);
		}
	}
	return counter;
}
namespace binaryTree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		int n = 1;
		String^ string;
		struct BTree* r = 0;
		struct BTree* q = 0;
		struct BTree* q2 = 0;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label2;
	public:
		int answer = 0;
	
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonDelete;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ заданиеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;

	protected:

	protected:

	protected:






	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->заданиеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(15, 70);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(205, 328);
			this->dataGridView1->TabIndex = 0;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::SystemColors::Info;
			this->numericUpDown1->Location = System::Drawing::Point(178, 413);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(39, 22);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &mainForm::numericUpDown1_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(877, 93);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(309, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 415);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Количество элементов";
			// 
			// buttonDelete
			// 
			this->buttonDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->buttonDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->ForeColor = System::Drawing::Color::Red;
			this->buttonDelete->Location = System::Drawing::Point(12, 462);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(205, 46);
			this->buttonDelete->TabIndex = 5;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = false;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &mainForm::buttonDelete_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->заданиеToolStripMenuItem,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1198, 28);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// заданиеToolStripMenuItem
			// 
			this->заданиеToolStripMenuItem->Name = L"заданиеToolStripMenuItem";
			this->заданиеToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->заданиеToolStripMenuItem->Text = L"Задание";
			this->заданиеToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::заданиеToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainForm::оПрограммеToolStripMenuItem_Click);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(12, 514);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(206, 22);
			this->numericUpDown2->TabIndex = 7;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &mainForm::numericUpDown2_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(873, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(313, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Уровень с минимальным значением";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1198, 548);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"mainForm";
			this->Text = L"Бинарное дерево";
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
	}

	private: System::Void mainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	//увелчиение кол-ва элементов
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	
		int n;

		n = Convert::ToInt64(numericUpDown1->Value);
		dataGridView1->RowCount = n;
		for (int i = 0; i < n; i++) {
			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i);
		}
	}

	//menustrip
	private: System::Void заданиеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Вариант 11\n\n"
			"1.) Дано число N(>0) и набор из N чисел.Создать бинарное упорядоченное "
			"дерево (в котором левое поддерево содержит вершины, меньшие или равные "
			"корню, а правое содержит вершины, большие корня), содержащее N вершин "
			"со значениями из исходного набора.\n\n"
			"2.) Вывести значения всех вершин дерева в постфиксном порядке (вначале выводится содержимое"
			"левого поддерева в постфиксном порядке, затем – содержимое правого поддерева в постфиксном порядке, затем – значение корня).\n\n" 
			"3.) Вывести значение уровня, на котором находится первая вершина дерева с минимальным значением.\n\n"
			"4.) Удалить из дерева все вершины, имеющие значение, введенное с клавиатуры."
		);
	}

	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Программа 'Бинарные деревья'\n"
			"Вариант 11\n"
			"Дисциплина: Языки программирования\n"
			"Версия 1.0\n"
			"2020 год\n"
			"Разработчик - Юрлов Константин \n"
			"Учебная группа ИНБс-2301");
	}

	//действие при нажатии на кнопку удалить
	private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		/*
		int i = 0;
		int key = 0;
		key = Convert::ToInt64(numericUpDown2->Value);
		n = Convert::ToInt64(numericUpDown1->Value);
		for (i = 0; i < 10; i++)
		{
			r = dtree(r, key);
			if (i < n)
			{
				if (Convert::ToInt64(dataGridView1[0, i]->Value) == key)
				{
					dataGridView1->Rows->RemoveAt(i);
					numericUpDown1->Value--;
				}
			}
		}
		Graphics^ g = CreateGraphics();
		g->Clear(BackColor);
		g->FillRectangle(gcnew SolidBrush(Color::White), 130, 0, 600, 600);
		Draw();
		*/
	}

	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
