#pragma once
#include "Graph.h"

namespace GUITesting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	string inline ConvertString(System::String^ s);

	/// <summary>
	/// Summary for SixDegrees
	/// </summary>
	public ref class SixDegrees : public System::Windows::Forms::Form
	{
	public:
		Graph* g = new Graph;
		SixDegrees(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		SixDegrees(Graph* g) {
			InitializeComponent();
			this->g = g;
		}
		void UpdateStats() {
			lbl_nodeNum->Text = g->getVertices().ToString() + lbl_nodeNum->Text;
			// lbl_numPages->Text = g->getMapSize().ToString() + lbl_numPages->Text;
			lbl_graphLinks->Text = g->getNumLinks().ToString() + lbl_graphLinks->Text;
		}
		
	private: System::Windows::Forms::Label^ lbl_findEdges;
	private: System::Windows::Forms::TextBox^ txt_loadEdges;
	private: System::Windows::Forms::Button^ btn_findEdges;
	private: System::Windows::Forms::Label^ lbl_header;
	private: System::Windows::Forms::Label^ lbl_nodeNum;

	private: System::Windows::Forms::Label^ lbl_graphLinks;
	private: System::Windows::Forms::Label^ lbl_noPath;
	private: System::Windows::Forms::Label^ lbl_path;
	private: System::Windows::Forms::Label^ lbl_pagesBtwn;
	private: System::Windows::Forms::Label^ lbl_linksBtwn;
	private: System::Windows::Forms::ListBox^ lb_path;

	private: System::Windows::Forms::RadioButton^ rbtn_bellman;
	private: System::Windows::Forms::RadioButton^ rbtn_dijkstra;
	private: System::Windows::Forms::Button^ btn_randomPage;
	private: System::Windows::Forms::Label^ lbl_timeTaken;

	private: System::Windows::Forms::Label^ lbl_noEdges;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SixDegrees()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_article1;
	protected:

	private: System::Windows::Forms::Label^ lbl_article2;
	private: System::Windows::Forms::TextBox^ txt_article1;
	private: System::Windows::Forms::TextBox^ txt_article2;



	private: System::Windows::Forms::ListBox^ lb_vertices;

	private: System::Windows::Forms::Button^ btn_go;
	private: System::Windows::Forms::CheckBox^ box_numLinks;
	private: System::Windows::Forms::Label^ lbl_numLinks;


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
			this->lbl_article1 = (gcnew System::Windows::Forms::Label());
			this->lbl_article2 = (gcnew System::Windows::Forms::Label());
			this->txt_article1 = (gcnew System::Windows::Forms::TextBox());
			this->txt_article2 = (gcnew System::Windows::Forms::TextBox());
			this->lb_vertices = (gcnew System::Windows::Forms::ListBox());
			this->btn_go = (gcnew System::Windows::Forms::Button());
			this->box_numLinks = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_numLinks = (gcnew System::Windows::Forms::Label());
			this->lbl_findEdges = (gcnew System::Windows::Forms::Label());
			this->txt_loadEdges = (gcnew System::Windows::Forms::TextBox());
			this->btn_findEdges = (gcnew System::Windows::Forms::Button());
			this->lbl_noEdges = (gcnew System::Windows::Forms::Label());
			this->lbl_header = (gcnew System::Windows::Forms::Label());
			this->lbl_nodeNum = (gcnew System::Windows::Forms::Label());
			this->lbl_graphLinks = (gcnew System::Windows::Forms::Label());
			this->lbl_noPath = (gcnew System::Windows::Forms::Label());
			this->lbl_path = (gcnew System::Windows::Forms::Label());
			this->lbl_pagesBtwn = (gcnew System::Windows::Forms::Label());
			this->lbl_linksBtwn = (gcnew System::Windows::Forms::Label());
			this->lb_path = (gcnew System::Windows::Forms::ListBox());
			this->rbtn_bellman = (gcnew System::Windows::Forms::RadioButton());
			this->rbtn_dijkstra = (gcnew System::Windows::Forms::RadioButton());
			this->btn_randomPage = (gcnew System::Windows::Forms::Button());
			this->lbl_timeTaken = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_article1
			// 
			this->lbl_article1->AutoSize = true;
			this->lbl_article1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_article1->Location = System::Drawing::Point(12, 230);
			this->lbl_article1->Name = L"lbl_article1";
			this->lbl_article1->Size = System::Drawing::Size(117, 29);
			this->lbl_article1->TabIndex = 0;
			this->lbl_article1->Text = L"Article 1:";
			// 
			// lbl_article2
			// 
			this->lbl_article2->AutoSize = true;
			this->lbl_article2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_article2->Location = System::Drawing::Point(12, 277);
			this->lbl_article2->Name = L"lbl_article2";
			this->lbl_article2->Size = System::Drawing::Size(117, 29);
			this->lbl_article2->TabIndex = 1;
			this->lbl_article2->Text = L"Article 2:";
			// 
			// txt_article1
			// 
			this->txt_article1->Location = System::Drawing::Point(135, 239);
			this->txt_article1->Name = L"txt_article1";
			this->txt_article1->Size = System::Drawing::Size(185, 20);
			this->txt_article1->TabIndex = 2;
			// 
			// txt_article2
			// 
			this->txt_article2->Location = System::Drawing::Point(135, 286);
			this->txt_article2->Name = L"txt_article2";
			this->txt_article2->Size = System::Drawing::Size(185, 20);
			this->txt_article2->TabIndex = 3;
			// 
			// lb_vertices
			// 
			this->lb_vertices->FormattingEnabled = true;
			this->lb_vertices->Location = System::Drawing::Point(470, 85);
			this->lb_vertices->Name = L"lb_vertices";
			this->lb_vertices->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->lb_vertices->Size = System::Drawing::Size(339, 121);
			this->lb_vertices->TabIndex = 4;
			// 
			// btn_go
			// 
			this->btn_go->BackColor = System::Drawing::Color::OliveDrab;
			this->btn_go->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_go->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btn_go->Location = System::Drawing::Point(135, 407);
			this->btn_go->Name = L"btn_go";
			this->btn_go->Size = System::Drawing::Size(205, 47);
			this->btn_go->TabIndex = 5;
			this->btn_go->Text = L"Find Shortest Path";
			this->btn_go->UseVisualStyleBackColor = false;
			this->btn_go->Click += gcnew System::EventHandler(this, &SixDegrees::btn_go_Click);
			// 
			// box_numLinks
			// 
			this->box_numLinks->AutoSize = true;
			this->box_numLinks->Location = System::Drawing::Point(236, 336);
			this->box_numLinks->Name = L"box_numLinks";
			this->box_numLinks->Size = System::Drawing::Size(15, 14);
			this->box_numLinks->TabIndex = 6;
			this->box_numLinks->UseMnemonic = false;
			this->box_numLinks->UseVisualStyleBackColor = true;
			this->box_numLinks->CheckedChanged += gcnew System::EventHandler(this, &SixDegrees::box_numLinks_CheckedChanged);
			// 
			// lbl_numLinks
			// 
			this->lbl_numLinks->AutoSize = true;
			this->lbl_numLinks->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_numLinks->Location = System::Drawing::Point(15, 328);
			this->lbl_numLinks->Name = L"lbl_numLinks";
			this->lbl_numLinks->Size = System::Drawing::Size(215, 24);
			this->lbl_numLinks->TabIndex = 7;
			this->lbl_numLinks->Text = L"Shortest Path by Links\?";
			// 
			// lbl_findEdges
			// 
			this->lbl_findEdges->AutoSize = true;
			this->lbl_findEdges->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_findEdges->Location = System::Drawing::Point(455, 23);
			this->lbl_findEdges->Name = L"lbl_findEdges";
			this->lbl_findEdges->Size = System::Drawing::Size(380, 24);
			this->lbl_findEdges->TabIndex = 8;
			this->lbl_findEdges->Text = L"Enter the name of an article to see its links:";
			// 
			// txt_loadEdges
			// 
			this->txt_loadEdges->Location = System::Drawing::Point(480, 54);
			this->txt_loadEdges->Name = L"txt_loadEdges";
			this->txt_loadEdges->Size = System::Drawing::Size(226, 20);
			this->txt_loadEdges->TabIndex = 9;
			// 
			// btn_findEdges
			// 
			this->btn_findEdges->BackColor = System::Drawing::Color::OliveDrab;
			this->btn_findEdges->Location = System::Drawing::Point(721, 52);
			this->btn_findEdges->Name = L"btn_findEdges";
			this->btn_findEdges->Size = System::Drawing::Size(75, 23);
			this->btn_findEdges->TabIndex = 10;
			this->btn_findEdges->Text = L"Load";
			this->btn_findEdges->UseVisualStyleBackColor = false;
			this->btn_findEdges->Click += gcnew System::EventHandler(this, &SixDegrees::btn_findEdges_Click);
			// 
			// lbl_noEdges
			// 
			this->lbl_noEdges->AutoSize = true;
			this->lbl_noEdges->ForeColor = System::Drawing::Color::Firebrick;
			this->lbl_noEdges->Location = System::Drawing::Point(802, 57);
			this->lbl_noEdges->Name = L"lbl_noEdges";
			this->lbl_noEdges->Size = System::Drawing::Size(86, 13);
			this->lbl_noEdges->TabIndex = 11;
			this->lbl_noEdges->Text = L"No edges found!";
			this->lbl_noEdges->Visible = false;
			// 
			// lbl_header
			// 
			this->lbl_header->AutoSize = true;
			this->lbl_header->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_header->Location = System::Drawing::Point(13, 23);
			this->lbl_header->Name = L"lbl_header";
			this->lbl_header->Size = System::Drawing::Size(276, 34);
			this->lbl_header->TabIndex = 12;
			this->lbl_header->Text = L"Graph created with:";
			// 
			// lbl_nodeNum
			// 
			this->lbl_nodeNum->AutoSize = true;
			this->lbl_nodeNum->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nodeNum->Location = System::Drawing::Point(31, 70);
			this->lbl_nodeNum->Name = L"lbl_nodeNum";
			this->lbl_nodeNum->Size = System::Drawing::Size(61, 24);
			this->lbl_nodeNum->TabIndex = 13;
			this->lbl_nodeNum->Text = L" nodes";
			// 
			// lbl_graphLinks
			// 
			this->lbl_graphLinks->AutoSize = true;
			this->lbl_graphLinks->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_graphLinks->Location = System::Drawing::Point(31, 106);
			this->lbl_graphLinks->Name = L"lbl_graphLinks";
			this->lbl_graphLinks->Size = System::Drawing::Size(59, 24);
			this->lbl_graphLinks->TabIndex = 15;
			this->lbl_graphLinks->Text = L" links";
			// 
			// lbl_noPath
			// 
			this->lbl_noPath->AutoSize = true;
			this->lbl_noPath->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_noPath->ForeColor = System::Drawing::Color::Firebrick;
			this->lbl_noPath->Location = System::Drawing::Point(163, 373);
			this->lbl_noPath->Name = L"lbl_noPath";
			this->lbl_noPath->Size = System::Drawing::Size(126, 21);
			this->lbl_noPath->TabIndex = 16;
			this->lbl_noPath->Text = L"No path found!";
			this->lbl_noPath->Visible = false;
			// 
			// lbl_path
			// 
			this->lbl_path->AutoSize = true;
			this->lbl_path->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_path->Location = System::Drawing::Point(461, 230);
			this->lbl_path->Name = L"lbl_path";
			this->lbl_path->Size = System::Drawing::Size(348, 31);
			this->lbl_path->TabIndex = 17;
			this->lbl_path->Text = L"Shortest path between pages:";
			this->lbl_path->Visible = false;
			// 
			// lbl_pagesBtwn
			// 
			this->lbl_pagesBtwn->AutoSize = true;
			this->lbl_pagesBtwn->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_pagesBtwn->Location = System::Drawing::Point(476, 277);
			this->lbl_pagesBtwn->Name = L"lbl_pagesBtwn";
			this->lbl_pagesBtwn->Size = System::Drawing::Size(60, 24);
			this->lbl_pagesBtwn->TabIndex = 18;
			this->lbl_pagesBtwn->Text = L" pages";
			this->lbl_pagesBtwn->Visible = false;
			// 
			// lbl_linksBtwn
			// 
			this->lbl_linksBtwn->AutoSize = true;
			this->lbl_linksBtwn->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_linksBtwn->Location = System::Drawing::Point(476, 315);
			this->lbl_linksBtwn->Name = L"lbl_linksBtwn";
			this->lbl_linksBtwn->Size = System::Drawing::Size(174, 24);
			this->lbl_linksBtwn->TabIndex = 19;
			this->lbl_linksBtwn->Text = L" total links between";
			this->lbl_linksBtwn->Visible = false;
			// 
			// lb_path
			// 
			this->lb_path->FormattingEnabled = true;
			this->lb_path->Location = System::Drawing::Point(470, 355);
			this->lb_path->Name = L"lb_path";
			this->lb_path->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->lb_path->Size = System::Drawing::Size(339, 121);
			this->lb_path->TabIndex = 20;
			this->lb_path->Visible = false;
			// 
			// rbtn_bellman
			// 
			this->rbtn_bellman->AutoSize = true;
			this->rbtn_bellman->Location = System::Drawing::Point(19, 356);
			this->rbtn_bellman->Name = L"rbtn_bellman";
			this->rbtn_bellman->Size = System::Drawing::Size(86, 17);
			this->rbtn_bellman->TabIndex = 22;
			this->rbtn_bellman->TabStop = true;
			this->rbtn_bellman->Text = L"Bellman-Ford";
			this->rbtn_bellman->UseVisualStyleBackColor = true;
			this->rbtn_bellman->Visible = false;
			// 
			// rbtn_dijkstra
			// 
			this->rbtn_dijkstra->AutoSize = true;
			this->rbtn_dijkstra->Location = System::Drawing::Point(19, 376);
			this->rbtn_dijkstra->Name = L"rbtn_dijkstra";
			this->rbtn_dijkstra->Size = System::Drawing::Size(67, 17);
			this->rbtn_dijkstra->TabIndex = 23;
			this->rbtn_dijkstra->TabStop = true;
			this->rbtn_dijkstra->Text = L"Dijkstra\'s";
			this->rbtn_dijkstra->UseVisualStyleBackColor = true;
			this->rbtn_dijkstra->Visible = false;
			// 
			// btn_randomPage
			// 
			this->btn_randomPage->BackColor = System::Drawing::Color::OliveDrab;
			this->btn_randomPage->Location = System::Drawing::Point(374, 122);
			this->btn_randomPage->Name = L"btn_randomPage";
			this->btn_randomPage->Size = System::Drawing::Size(90, 40);
			this->btn_randomPage->TabIndex = 24;
			this->btn_randomPage->Text = L"Load Random Page";
			this->btn_randomPage->UseVisualStyleBackColor = false;
			this->btn_randomPage->Click += gcnew System::EventHandler(this, &SixDegrees::btn_randomPage_Click);
			// 
			// lbl_timeTaken
			// 
			this->lbl_timeTaken->AutoSize = true;
			this->lbl_timeTaken->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_timeTaken->Location = System::Drawing::Point(31, 469);
			this->lbl_timeTaken->Name = L"lbl_timeTaken";
			this->lbl_timeTaken->Size = System::Drawing::Size(122, 24);
			this->lbl_timeTaken->TabIndex = 25;
			this->lbl_timeTaken->Text = L"seconds taken";
			this->lbl_timeTaken->Visible = false;
			// 
			// SixDegrees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PowderBlue;
			this->ClientSize = System::Drawing::Size(1003, 521);
			this->Controls->Add(this->lbl_timeTaken);
			this->Controls->Add(this->btn_randomPage);
			this->Controls->Add(this->rbtn_dijkstra);
			this->Controls->Add(this->rbtn_bellman);
			this->Controls->Add(this->lb_path);
			this->Controls->Add(this->lbl_linksBtwn);
			this->Controls->Add(this->lbl_pagesBtwn);
			this->Controls->Add(this->lbl_path);
			this->Controls->Add(this->lbl_noPath);
			this->Controls->Add(this->lbl_graphLinks);
			this->Controls->Add(this->lbl_nodeNum);
			this->Controls->Add(this->lbl_header);
			this->Controls->Add(this->lbl_noEdges);
			this->Controls->Add(this->btn_findEdges);
			this->Controls->Add(this->txt_loadEdges);
			this->Controls->Add(this->lbl_findEdges);
			this->Controls->Add(this->lbl_numLinks);
			this->Controls->Add(this->box_numLinks);
			this->Controls->Add(this->btn_go);
			this->Controls->Add(this->lb_vertices);
			this->Controls->Add(this->txt_article2);
			this->Controls->Add(this->txt_article1);
			this->Controls->Add(this->lbl_article2);
			this->Controls->Add(this->lbl_article1);
			this->Name = L"SixDegrees";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SixDegrees";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_go_Click(System::Object^ sender, System::EventArgs^ e) {

		string art1 = ConvertString(txt_article1->Text);
		string art2 = ConvertString(txt_article2->Text);
		lb_path->Items->Clear();
		lbl_pagesBtwn->Visible = false;
		lbl_pagesBtwn->Text = L" pages";
		lbl_linksBtwn->Visible = false;
		lbl_linksBtwn->Text = L" total links between";
		lbl_timeTaken->Visible = false;
		lbl_timeTaken->Text = L" seconds taken";
		auto timer = std::chrono::steady_clock::now();
		if (box_numLinks->Checked) {
			// use bellman-ford or dijkstra's here: use vector of pairs to display pages,
			// weights, and total links btwn
			std::vector<std::pair<int, string>> pathVecWeighted;
			if (rbtn_bellman->Checked) {
				pathVecWeighted = g->getBellmanPath(art1, art2);
			}
			else {
				pathVecWeighted = g->getDijkstrasPath(art1, art2);
			}
			if (pathVecWeighted.size() == 0) {
				// no path found
				lbl_noPath->Visible = true;
				return;
			}
			else {
				lbl_noPath->Visible = false;
				// populate results
				lbl_path->Visible = true;
				lbl_pagesBtwn->Visible = true;
				lbl_pagesBtwn->Text = pathVecWeighted.size().ToString() + lbl_pagesBtwn->Text;
				lbl_linksBtwn->Visible = true;
				lbl_linksBtwn->Text = pathVecWeighted[0].first.ToString() + lbl_linksBtwn->Text;
				lbl_timeTaken->Visible = true;
				auto end = std::chrono::steady_clock::now();
				int seconds = std::chrono::duration_cast<std::chrono::seconds>(end - timer).count();
				lbl_timeTaken->Text = seconds.ToString() + lbl_timeTaken->Text;

				lb_path->BeginUpdate();
				for (auto i = 0; i < pathVecWeighted.size(); i++) {
					String^ pgName = gcnew String(pathVecWeighted[i].second.c_str());
					lb_path->Items->Add(pgName);
				}
				lb_path->EndUpdate();
				lb_path->Visible = true;
			}
		}
		else {
			lbl_linksBtwn->Visible = false;
			// use BFS here
			std::vector<string> pathVec;
			pathVec = g->getBFSPath(art1, art2);
			if (pathVec.size() == 0) {
				// no path found
				lbl_noPath->Visible = true;
				return;
			}
			else {
				lbl_noPath->Visible = false;
				// populate results
				lbl_path->Visible = true;
				lbl_pagesBtwn->Visible = true;
				lbl_pagesBtwn->Text = pathVec.size().ToString() + lbl_pagesBtwn->Text;
				lbl_timeTaken->Visible = true;
				auto end = std::chrono::steady_clock::now();
				int seconds = std::chrono::duration_cast<std::chrono::seconds>(end - timer).count();
				lbl_timeTaken->Text = seconds.ToString() + lbl_timeTaken->Text;
				lb_path->BeginUpdate();
				for (auto i = 0; i < pathVec.size(); i++) {
					String^ pgName = gcnew String(pathVec[i].c_str());
					lb_path->Items->Add(pgName);
				}
				lb_path->EndUpdate();
				lb_path->Visible = true;
			}

		}
	}

	private: System::Void btn_findEdges_Click(System::Object^ sender, System::EventArgs^ e) {
		string pageName = ConvertString(txt_loadEdges->Text);
		std::vector<string> edges = g->getEdges(pageName);
		lb_vertices->Items->Clear();
		if (edges.size() == 0) {
			lbl_noEdges->Visible = true;
			return;
		}
		lbl_noEdges->Visible = false;
		lb_vertices->BeginUpdate();
		for (auto i = 0; i < edges.size(); i++) {
			String^ edgeName = gcnew String(edges.at(i).c_str());
			lb_vertices->Items->Add(edgeName);
		}
		lb_vertices->EndUpdate();
	}
	private: System::Void box_numLinks_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (box_numLinks->Checked) {
			rbtn_bellman->Visible = true;
			rbtn_dijkstra->Visible = true;
		}
		else {
			rbtn_bellman->Visible = false;
			rbtn_dijkstra->Visible = false;
		}
	}
		   private: System::Void findEdges_Click() {
			   string pageName = ConvertString(txt_loadEdges->Text);
			   std::vector<string> edges = g->getEdges(pageName);
			   lb_vertices->Items->Clear();
			   if (edges.size() == 0) {
				   lbl_noEdges->Visible = true;
				   return;
			   }
			   lbl_noEdges->Visible = false;
			   lb_vertices->BeginUpdate();
			   for (auto i = 0; i < edges.size(); i++) {
				   String^ edgeName = gcnew String(edges.at(i).c_str());
				   lb_vertices->Items->Add(edgeName);
			   }
			   lb_vertices->EndUpdate();
		   }
	private: System::Void btn_randomPage_Click(System::Object^ sender, System::EventArgs^ e) {
		// get list of loaded pages
		// choose random one, verify non-empty link list
		String^ randNode = gcnew String(g->getRandomNode().c_str());
		txt_loadEdges->Text = randNode;
		findEdges_Click();
	}
};
string ConvertString(System::String^ s) {
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	string newStr = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return newStr;
}
}
