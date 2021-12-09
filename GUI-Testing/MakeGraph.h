#pragma once
#include "Graph.h"
#include "SixDegrees.h"
#include <string>
#include <vector>




namespace GUITesting {

	using std::string;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	

	/// <summary>
	/// Summary for MakeGraph
	/// </summary>
	public ref class MakeGraph : public System::Windows::Forms::Form
	{
	public:
		MakeGraph(void)
		{
			InitializeComponent();
		}

		// graph-related variables
		std::vector<string>* files = new std::vector<string>();
		Graph* g = new Graph;
		int numFiles;
	private: System::Windows::Forms::Label^ lbl_emptyGraph;
	private: System::Windows::Forms::Button^ btn_generalData;
	public:
	private: System::Windows::Forms::Label^ lbl_LoadingGraph;
	public:
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MakeGraph()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_numFiles;
	public:
	public: System::Windows::Forms::TextBox^ txt_numFiles;
	public: System::Windows::Forms::Button^ btn_numFiles;
	private: System::Windows::Forms::Label^ lbl_invalidNum;
	private: System::Windows::Forms::Label^ lbl_fileNames;
	private: System::Windows::Forms::TextBox^ txt_fileNames;
	private: System::Windows::Forms::Button^ btn_fileNames;

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
			this->lbl_numFiles = (gcnew System::Windows::Forms::Label());
			this->txt_numFiles = (gcnew System::Windows::Forms::TextBox());
			this->btn_numFiles = (gcnew System::Windows::Forms::Button());
			this->lbl_invalidNum = (gcnew System::Windows::Forms::Label());
			this->lbl_fileNames = (gcnew System::Windows::Forms::Label());
			this->txt_fileNames = (gcnew System::Windows::Forms::TextBox());
			this->btn_fileNames = (gcnew System::Windows::Forms::Button());
			this->lbl_LoadingGraph = (gcnew System::Windows::Forms::Label());
			this->lbl_emptyGraph = (gcnew System::Windows::Forms::Label());
			this->btn_generalData = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_numFiles
			// 
			this->lbl_numFiles->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_numFiles->Location = System::Drawing::Point(31, 61);
			this->lbl_numFiles->Name = L"lbl_numFiles";
			this->lbl_numFiles->Size = System::Drawing::Size(300, 60);
			this->lbl_numFiles->TabIndex = 0;
			this->lbl_numFiles->Text = L"How many files will be used to make the graph\?";
			this->lbl_numFiles->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// txt_numFiles
			// 
			this->txt_numFiles->Location = System::Drawing::Point(348, 81);
			this->txt_numFiles->Name = L"txt_numFiles";
			this->txt_numFiles->Size = System::Drawing::Size(51, 20);
			this->txt_numFiles->TabIndex = 1;
			// 
			// btn_numFiles
			// 
			this->btn_numFiles->BackColor = System::Drawing::Color::OliveDrab;
			this->btn_numFiles->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_numFiles->Location = System::Drawing::Point(224, 163);
			this->btn_numFiles->Name = L"btn_numFiles";
			this->btn_numFiles->Size = System::Drawing::Size(90, 34);
			this->btn_numFiles->TabIndex = 2;
			this->btn_numFiles->Text = L"OK";
			this->btn_numFiles->UseVisualStyleBackColor = false;
			this->btn_numFiles->Click += gcnew System::EventHandler(this, &MakeGraph::btn_numFiles_Click);
			// 
			// lbl_invalidNum
			// 
			this->lbl_invalidNum->AutoSize = true;
			this->lbl_invalidNum->ForeColor = System::Drawing::Color::Firebrick;
			this->lbl_invalidNum->Location = System::Drawing::Point(111, 138);
			this->lbl_invalidNum->Name = L"lbl_invalidNum";
			this->lbl_invalidNum->Size = System::Drawing::Size(288, 13);
			this->lbl_invalidNum->TabIndex = 3;
			this->lbl_invalidNum->Text = L"It seems you\'ve entered an invalid number, please try again.";
			this->lbl_invalidNum->Visible = false;
			// 
			// lbl_fileNames
			// 
			this->lbl_fileNames->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_fileNames->Location = System::Drawing::Point(31, 174);
			this->lbl_fileNames->Name = L"lbl_fileNames";
			this->lbl_fileNames->Size = System::Drawing::Size(278, 62);
			this->lbl_fileNames->TabIndex = 4;
			this->lbl_fileNames->Text = L"Enter the name of the file you\'d like to use:";
			this->lbl_fileNames->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->lbl_fileNames->Visible = false;
			// 
			// txt_fileNames
			// 
			this->txt_fileNames->Location = System::Drawing::Point(348, 197);
			this->txt_fileNames->Name = L"txt_fileNames";
			this->txt_fileNames->Size = System::Drawing::Size(110, 20);
			this->txt_fileNames->TabIndex = 5;
			this->txt_fileNames->Visible = false;
			// 
			// btn_fileNames
			// 
			this->btn_fileNames->BackColor = System::Drawing::Color::OliveDrab;
			this->btn_fileNames->Location = System::Drawing::Point(224, 255);
			this->btn_fileNames->Name = L"btn_fileNames";
			this->btn_fileNames->Size = System::Drawing::Size(90, 34);
			this->btn_fileNames->TabIndex = 6;
			this->btn_fileNames->Text = L"Add File";
			this->btn_fileNames->UseVisualStyleBackColor = false;
			this->btn_fileNames->Visible = false;
			this->btn_fileNames->Click += gcnew System::EventHandler(this, &MakeGraph::btn_fileNames_Click);
			// 
			// lbl_LoadingGraph
			// 
			this->lbl_LoadingGraph->AutoSize = true;
			this->lbl_LoadingGraph->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_LoadingGraph->ForeColor = System::Drawing::Color::DarkGreen;
			this->lbl_LoadingGraph->Location = System::Drawing::Point(108, 303);
			this->lbl_LoadingGraph->Name = L"lbl_LoadingGraph";
			this->lbl_LoadingGraph->Size = System::Drawing::Size(317, 36);
			this->lbl_LoadingGraph->TabIndex = 7;
			this->lbl_LoadingGraph->Text = L"Constructing Graph...";
			this->lbl_LoadingGraph->Visible = false;
			// 
			// lbl_emptyGraph
			// 
			this->lbl_emptyGraph->AutoSize = true;
			this->lbl_emptyGraph->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_emptyGraph->ForeColor = System::Drawing::Color::Firebrick;
			this->lbl_emptyGraph->Location = System::Drawing::Point(30, 292);
			this->lbl_emptyGraph->Name = L"lbl_emptyGraph";
			this->lbl_emptyGraph->Size = System::Drawing::Size(514, 31);
			this->lbl_emptyGraph->TabIndex = 8;
			this->lbl_emptyGraph->Text = L"Graph would be empty! Enter another file!";
			this->lbl_emptyGraph->Visible = false;
			// 
			// btn_generalData
			// 
			this->btn_generalData->BackColor = System::Drawing::Color::OliveDrab;
			this->btn_generalData->Location = System::Drawing::Point(537, 65);
			this->btn_generalData->Name = L"btn_generalData";
			this->btn_generalData->Size = System::Drawing::Size(131, 56);
			this->btn_generalData->TabIndex = 9;
			this->btn_generalData->Text = L"Use general data!";
			this->btn_generalData->UseVisualStyleBackColor = false;
			this->btn_generalData->Click += gcnew System::EventHandler(this, &MakeGraph::btn_generalData_Click);
			// 
			// MakeGraph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PowderBlue;
			this->ClientSize = System::Drawing::Size(777, 479);
			this->Controls->Add(this->btn_generalData);
			this->Controls->Add(this->lbl_emptyGraph);
			this->Controls->Add(this->lbl_LoadingGraph);
			this->Controls->Add(this->btn_fileNames);
			this->Controls->Add(this->txt_fileNames);
			this->Controls->Add(this->lbl_fileNames);
			this->Controls->Add(this->lbl_invalidNum);
			this->Controls->Add(this->btn_numFiles);
			this->Controls->Add(this->txt_numFiles);
			this->Controls->Add(this->lbl_numFiles);
			this->Name = L"MakeGraph";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MakeGraph";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void btn_numFiles_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fileNumInput = txt_numFiles->Text;
		string fileNum = ConvertString(fileNumInput);
		btn_generalData->Visible = false;

		if (!isValidNumber(fileNum)) {
			lbl_invalidNum->Visible = true;
			return;
		}
		numFiles = stoi(fileNum);
		lbl_invalidNum->Visible = false;
		btn_numFiles->Visible = false;
		txt_numFiles->ReadOnly = true;

		// show next fields
		lbl_fileNames->Visible = true;
		txt_fileNames->Visible = true;
		btn_fileNames->Visible = true;
		return;
	}
	private: System::Void btn_fileNames_Click(System::Object^ sender, System::EventArgs^ e) {
		numFiles--;
		// parse file and return
		String^ nameInput = txt_fileNames->Text;
		string name = ConvertString(nameInput);
		files->push_back(name);
		txt_fileNames->ResetText();
		
		if (numFiles == 0) {
			// construct graph, hide button, and open next form
			// cannot get "Loading" msg to appear before next form
			
			g->inputGraph(*files);
			if (g->getNumVertices() == 0) {
				numFiles++;
				lbl_emptyGraph->Visible = true;
				return;
			}
			btn_fileNames->Visible = false;
			lbl_LoadingGraph->Visible = true;
			lbl_emptyGraph->Visible = false;
			SixDegrees mainForm;
			mainForm.g = g;
			// setting graph stats
			mainForm.UpdateStats();
			mainForm.ShowDialog();
		}
	}
	private: System::Void btn_generalData_Click(System::Object^ sender, System::EventArgs^ e) {
		// get names of files for general data stuff
		// files.push_back(<each file name>)
		 g->inputGraph(*files);
		btn_fileNames->Visible = false;
		lbl_LoadingGraph->Visible = true;
		lbl_emptyGraph->Visible = false;
		SixDegrees mainForm;
		mainForm.g = g;
		// setting graph stats
		mainForm.UpdateStats();
		mainForm.ShowDialog();
	}
};


}

