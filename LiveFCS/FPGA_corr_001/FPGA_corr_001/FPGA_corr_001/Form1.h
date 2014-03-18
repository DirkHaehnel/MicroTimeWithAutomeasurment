#pragma once
#include<windows.h>
#include <vcclr.h>
#include<math.h>

namespace FPGA_corr_001 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
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
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	public: Mitov::PlotLab::Scope^  scope1;	
	private: 

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button3;
	public: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	public: 
	private: 




	private: System::ComponentModel::IContainer^  components;
	protected: 

	public:
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
			Mitov::PlotLab::ScopeChannel^  scopeChannel5 = (gcnew Mitov::PlotLab::ScopeChannel());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			Mitov::PlotLab::ScopePoints^  scopePoints5 = (gcnew Mitov::PlotLab::ScopePoints());
			Vcl::VclPen^  vclPen10 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::ScopeChannel^  scopeChannel6 = (gcnew Mitov::PlotLab::ScopeChannel());
			Mitov::PlotLab::ScopePoints^  scopePoints6 = (gcnew Mitov::PlotLab::ScopePoints());
			Vcl::VclPen^  vclPen11 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::ScopeChannel^  scopeChannel7 = (gcnew Mitov::PlotLab::ScopeChannel());
			Mitov::PlotLab::ScopePoints^  scopePoints7 = (gcnew Mitov::PlotLab::ScopePoints());
			Vcl::VclPen^  vclPen12 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::ScopeChannel^  scopeChannel8 = (gcnew Mitov::PlotLab::ScopeChannel());
			Mitov::PlotLab::ScopePoints^  scopePoints8 = (gcnew Mitov::PlotLab::ScopePoints());
			Vcl::VclPen^  vclPen13 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::ScopeDataView^  scopeDataView2 = (gcnew Mitov::PlotLab::ScopeDataView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground6 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings6 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen14 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DataDisplayHighlighting^  dataDisplayHighlighting2 = (gcnew Mitov::PlotLab::DataDisplayHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting3 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::ChannelItemHighlighting^  channelItemHighlighting4 = (gcnew Mitov::PlotLab::ChannelItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting7 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting8 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting9 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting10 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting11 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			Mitov::PlotLab::ChannelMouseHitPoint^  channelMouseHitPoint2 = (gcnew Mitov::PlotLab::ChannelMouseHitPoint());
			Mitov::SignalLab::OptionalLabel^  optionalLabel2 = (gcnew Mitov::SignalLab::OptionalLabel());
			Mitov::PlotLab::DisplayItemHighlighting^  displayItemHighlighting12 = (gcnew Mitov::PlotLab::DisplayItemHighlighting());
			OpenWire::Proxy::PinList^  pinList3 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeLegendView^  scopeLegendView2 = (gcnew Mitov::PlotLab::ScopeLegendView());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground7 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::LegendViewButtonSettings^  legendViewButtonSettings2 = (gcnew Mitov::PlotLab::LegendViewButtonSettings());
			Mitov::PlotLab::LegendGroup^  legendGroup9 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel9 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup10 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel10 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup11 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel11 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup12 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel12 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup13 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel13 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup14 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel14 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::LegendGroup^  legendGroup15 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel15 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize5 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::LegendGroup^  legendGroup16 = (gcnew Mitov::PlotLab::LegendGroup());
			Mitov::PlotLab::DisplayLabel^  displayLabel16 = (gcnew Mitov::PlotLab::DisplayLabel());
			Mitov::PlotLab::DisplayTitle^  displayTitle2 = (gcnew Mitov::PlotLab::DisplayTitle());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground8 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize6 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayToolBar^  displayToolBar2 = (gcnew Mitov::PlotLab::DisplayToolBar());
			Mitov::PlotLab::DisplayToolBarButtons^  displayToolBarButtons2 = (gcnew Mitov::PlotLab::DisplayToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton21 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton22 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton23 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton24 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton25 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton26 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton27 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton28 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton29 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton30 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton31 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton32 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ToolBarPosition^  toolBarPosition2 = (gcnew Mitov::PlotLab::ToolBarPosition());
			Mitov::PlotLab::DisplayTrails^  displayTrails2 = (gcnew Mitov::PlotLab::DisplayTrails());
			Mitov::PlotLab::ScopeXAxis^  scopeXAxis2 = (gcnew Mitov::PlotLab::ScopeXAxis());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel3 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground9 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings3 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings3 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings3 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings7 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen15 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings8 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen16 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat3 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks3 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart3 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue3 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange7 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue13 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue14 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue5 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::ScopeMaxSample^  scopeMaxSample2 = (gcnew Mitov::PlotLab::ScopeMaxSample());
			Mitov::PlotLab::AxisValue^  axisValue3 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange8 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue15 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue16 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue6 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks3 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar3 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons3 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton33 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton34 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton35 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton36 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::ScopeXAxisUnitScale^  scopeXAxisUnitScale2 = (gcnew Mitov::PlotLab::ScopeXAxisUnitScale());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize7 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom3 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange9 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue17 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue18 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin3 = (gcnew OpenWire::Proxy::StatePin());
			OpenWire::Proxy::PinList^  pinList4 = (gcnew OpenWire::Proxy::PinList());
			Mitov::PlotLab::ScopeYAxis^  scopeYAxis2 = (gcnew Mitov::PlotLab::ScopeYAxis());
			Mitov::PlotLab::ScopeAutoScaling^  scopeAutoScaling2 = (gcnew Mitov::PlotLab::ScopeAutoScaling());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace3 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::ScopeAutoScalingSpace^  scopeAutoScalingSpace4 = (gcnew Mitov::PlotLab::ScopeAutoScalingSpace());
			Mitov::PlotLab::DisplayTitleLabel^  displayTitleLabel4 = (gcnew Mitov::PlotLab::DisplayTitleLabel());
			Mitov::PlotLab::DisplayViewBackground^  displayViewBackground10 = (gcnew Mitov::PlotLab::DisplayViewBackground());
			Mitov::PlotLab::ViewButtonSettings^  viewButtonSettings4 = (gcnew Mitov::PlotLab::ViewButtonSettings());
			Mitov::PlotLab::DisplayAxisCursorSettings^  displayAxisCursorSettings4 = (gcnew Mitov::PlotLab::DisplayAxisCursorSettings());
			Mitov::PlotLab::DisplayGridDirectionalLinesSettings^  displayGridDirectionalLinesSettings4 = (gcnew Mitov::PlotLab::DisplayGridDirectionalLinesSettings());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings9 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen17 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::DisplayGridLineSettings^  displayGridLineSettings10 = (gcnew Mitov::PlotLab::DisplayGridLineSettings());
			Vcl::VclPen^  vclPen18 = (gcnew Vcl::VclPen());
			Mitov::PlotLab::AxisFormat^  axisFormat4 = (gcnew Mitov::PlotLab::AxisFormat());
			Mitov::PlotLab::MajorTicks^  majorTicks4 = (gcnew Mitov::PlotLab::MajorTicks());
			Mitov::PlotLab::TicksStart^  ticksStart4 = (gcnew Mitov::PlotLab::TicksStart());
			Mitov::PlotLab::MaxAxisValue^  maxAxisValue4 = (gcnew Mitov::PlotLab::MaxAxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange10 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue19 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue20 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue7 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::AxisValue^  axisValue4 = (gcnew Mitov::PlotLab::AxisValue());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange11 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue21 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue22 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::BasicAxisValue^  basicAxisValue8 = (gcnew Mitov::PlotLab::BasicAxisValue());
			Mitov::PlotLab::MinorTicks^  minorTicks4 = (gcnew Mitov::PlotLab::MinorTicks());
			Mitov::PlotLab::AxisToolBar^  axisToolBar4 = (gcnew Mitov::PlotLab::AxisToolBar());
			Mitov::PlotLab::AxisToolBarButtons^  axisToolBarButtons4 = (gcnew Mitov::PlotLab::AxisToolBarButtons());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton37 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton38 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton39 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayToolBarButton^  displayToolBarButton40 = (gcnew Mitov::PlotLab::DisplayToolBarButton());
			Mitov::PlotLab::DisplayViewSize^  displayViewSize8 = (gcnew Mitov::PlotLab::DisplayViewSize());
			Mitov::PlotLab::DisplayAxisZoom^  displayAxisZoom4 = (gcnew Mitov::PlotLab::DisplayAxisZoom());
			Mitov::PlotLab::DisplayValueRange^  displayValueRange12 = (gcnew Mitov::PlotLab::DisplayValueRange());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue23 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			Mitov::PlotLab::DisplayOptionalValue^  displayOptionalValue24 = (gcnew Mitov::PlotLab::DisplayOptionalValue());
			OpenWire::Proxy::StatePin^  statePin4 = (gcnew OpenWire::Proxy::StatePin());
			Mitov::PlotLab::DisplayZoom^  displayZoom2 = (gcnew Mitov::PlotLab::DisplayZoom());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->scope1 = (gcnew Mitov::PlotLab::Scope(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scope1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(644, 10);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(142, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(466, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Number of Runs :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(468, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Duration:";
			// 
			// scope1
			// 
			this->scope1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeChannel5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeChannel5->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeChannel5.InternalData")));
			scopeChannel5->MouseCursor = System::Windows::Forms::Cursors::Default;
			scopeChannel5->Name = L"ACF 0";
			scopePoints5->Brush = (gcnew Vcl::VclBrush(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0))), 0));
			vclPen10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen10->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen10.InternalData")));
			scopePoints5->Pen = vclPen10;
			scopePoints5->Size = static_cast<System::UInt32>(3);
			scopeChannel5->Points = scopePoints5;
			scopeChannel5->XAxisIndex = 0;
			scopeChannel5->YAxisIndex = 0;
			scopeChannel6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeChannel6->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeChannel6.InternalData")));
			scopeChannel6->MouseCursor = System::Windows::Forms::Cursors::Default;
			scopeChannel6->Name = L"ACF 1";
			scopePoints6->Brush = (gcnew Vcl::VclBrush(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0))), 0));
			vclPen11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen11->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen11.InternalData")));
			scopePoints6->Pen = vclPen11;
			scopePoints6->Size = static_cast<System::UInt32>(3);
			scopeChannel6->Points = scopePoints6;
			scopeChannel6->Visible = false;
			scopeChannel6->XAxisIndex = 0;
			scopeChannel6->YAxisIndex = 0;
			scopeChannel7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeChannel7->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeChannel7.InternalData")));
			scopeChannel7->MouseCursor = System::Windows::Forms::Cursors::Default;
			scopeChannel7->Name = L"CCF 01";
			scopePoints7->Brush = (gcnew Vcl::VclBrush(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0))), 0));
			vclPen12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen12->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen12.InternalData")));
			scopePoints7->Pen = vclPen12;
			scopePoints7->Size = static_cast<System::UInt32>(3);
			scopeChannel7->Points = scopePoints7;
			scopeChannel7->Visible = false;
			scopeChannel7->XAxisIndex = 0;
			scopeChannel7->YAxisIndex = 0;
			scopeChannel8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeChannel8->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeChannel8.InternalData")));
			scopeChannel8->MouseCursor = System::Windows::Forms::Cursors::Default;
			scopeChannel8->Name = L"CCF 10";
			scopePoints8->Brush = (gcnew Vcl::VclBrush(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0))), 0));
			vclPen13->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen13->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen13.InternalData")));
			scopePoints8->Pen = vclPen13;
			scopePoints8->Size = static_cast<System::UInt32>(3);
			scopeChannel8->Points = scopePoints8;
			scopeChannel8->Visible = false;
			scopeChannel8->XAxisIndex = 0;
			scopeChannel8->YAxisIndex = 0;
			this->scope1->Channels->AddRange(gcnew cli::array< Mitov::PlotLab::ScopeChannel^  >(4) {scopeChannel5, scopeChannel6, scopeChannel7, 
				scopeChannel8});
			displayViewBackground6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeDataView2->Background = displayViewBackground6;
			vclPen14->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen14->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen14.InternalData")));
			displayGridLineSettings6->Pen = vclPen14;
			scopeDataView2->Border = displayGridLineSettings6;
			this->scope1->DataView = scopeDataView2;
			channelItemHighlighting3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->ChannelLinks = channelItemHighlighting3;
			channelItemHighlighting4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->Channels = channelItemHighlighting4;
			displayItemHighlighting7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->CursorLinks = displayItemHighlighting7;
			displayItemHighlighting8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->Cursors = displayItemHighlighting8;
			displayItemHighlighting9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->Ellipses = displayItemHighlighting9;
			displayItemHighlighting10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->Labels = displayItemHighlighting10;
			displayItemHighlighting11->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataDisplayHighlighting2->Markers = displayItemHighlighting11;
			channelMouseHitPoint2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			optionalLabel2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 11, 0));
			optionalLabel2->Text = L"";
			channelMouseHitPoint2->PointLabel = optionalLabel2;
			dataDisplayHighlighting2->MouseHitPoint = channelMouseHitPoint2;
			displayItemHighlighting12->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			dataDisplayHighlighting2->Zones = displayItemHighlighting12;
			this->scope1->Highlighting = dataDisplayHighlighting2;
			pinList3->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList3.ConnectionData")));
			this->scope1->InputPins = pinList3;
			this->scope1->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scope1.InternalData")));
			displayViewBackground7->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView2->Background = displayViewBackground7;
			legendViewButtonSettings2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->Cursor = System::Windows::Forms::Cursors::Default;
			legendViewButtonSettings2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			legendViewButtonSettings2->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeLegendView2->Buttons = legendViewButtonSettings2;
			displayLabel9->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel9->Text = L"";
			legendGroup9->Caption = displayLabel9;
			legendGroup9->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->ChannelLinks = legendGroup9;
			displayLabel10->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel10->Text = L"";
			legendGroup10->Caption = displayLabel10;
			legendGroup10->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Channels = legendGroup10;
			displayLabel11->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel11->Text = L"";
			legendGroup11->Caption = displayLabel11;
			legendGroup11->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->CursorLinks = legendGroup11;
			displayLabel12->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel12->Text = L"";
			legendGroup12->Caption = displayLabel12;
			legendGroup12->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Cursors = legendGroup12;
			displayLabel13->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel13->Text = L"";
			legendGroup13->Caption = displayLabel13;
			legendGroup13->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Ellipses = legendGroup13;
			scopeLegendView2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 11, 0));
			scopeLegendView2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeLegendView2.InternalData")));
			displayLabel14->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel14->Text = L"";
			legendGroup14->Caption = displayLabel14;
			legendGroup14->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Labels = legendGroup14;
			displayLabel15->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel15->Text = L"";
			legendGroup15->Caption = displayLabel15;
			legendGroup15->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->MarkerGroups = legendGroup15;
			displayViewSize5->Size = static_cast<System::UInt32>(100);
			scopeLegendView2->ViewSize = displayViewSize5;
			displayLabel16->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 0));
			displayLabel16->Text = L"";
			legendGroup16->Caption = displayLabel16;
			legendGroup16->Cursor = System::Windows::Forms::Cursors::Default;
			scopeLegendView2->Zones = legendGroup16;
			this->scope1->Legend = scopeLegendView2;
			this->scope1->Location = System::Drawing::Point(14, 68);
			this->scope1->Name = L"scope1";
			this->scope1->RefreshInterval = static_cast<System::UInt32>(100);
			this->scope1->Size = System::Drawing::Size(1483, 414);
			this->scope1->SizeLimit = static_cast<System::UInt32>(0);
			this->scope1->TabIndex = 5;
			this->scope1->Text = L"nnn";
			displayViewBackground8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayTitle2->Background = displayViewBackground8;
			displayTitle2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 21, 1));
			displayTitle2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"displayTitle2.InternalData")));
			displayTitle2->Text = L"Scope";
			displayViewSize6->Size = static_cast<System::UInt32>(100);
			displayTitle2->ViewSize = displayViewSize6;
			this->scope1->Title = displayTitle2;
			displayToolBar2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBarButtons2->Copy = displayToolBarButton21;
			displayToolBarButtons2->Hold = displayToolBarButton22;
			displayToolBarButtons2->Print = displayToolBarButton23;
			displayToolBarButtons2->Save = displayToolBarButton24;
			displayToolBarButtons2->Setup = displayToolBarButton25;
			displayToolBarButtons2->XYZoomOn = displayToolBarButton26;
			displayToolBarButtons2->ZoomIn = displayToolBarButton27;
			displayToolBarButtons2->ZoomMode = displayToolBarButton28;
			displayToolBarButtons2->ZoomNext = displayToolBarButton29;
			displayToolBarButtons2->ZoomOff = displayToolBarButton30;
			displayToolBarButtons2->ZoomOut = displayToolBarButton31;
			displayToolBarButtons2->ZoomPrevious = displayToolBarButton32;
			displayToolBar2->Buttons = displayToolBarButtons2;
			displayToolBar2->Cursor = System::Windows::Forms::Cursors::Default;
			displayToolBar2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayToolBar2->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			toolBarPosition2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"toolBarPosition2.InternalData")));
			displayToolBar2->Position = toolBarPosition2;
			this->scope1->ToolBar = displayToolBar2;
			displayTrails2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			displayTrails2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 11, 0));
			this->scope1->Trails = displayTrails2;
			displayTitleLabel3->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				161, 0, true, 13, 1));
			displayTitleLabel3->Text = L"Lag [us]";
			scopeXAxis2->AxisLabel = displayTitleLabel3;
			displayViewBackground9->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->Background = displayViewBackground9;
			viewButtonSettings3->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings3->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->Button = viewButtonSettings3;
			scopeXAxis2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeXAxis2->CursorSettings = displayAxisCursorSettings3;
			vclPen15->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen15->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen15.InternalData")));
			displayGridLineSettings7->Pen = vclPen15;
			displayGridLineSettings7->Visible = false;
			displayGridDirectionalLinesSettings3->Lines = displayGridLineSettings7;
			vclPen16->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen16->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen16.InternalData")));
			displayGridLineSettings8->Pen = vclPen16;
			displayGridDirectionalLinesSettings3->ZeroLine = displayGridLineSettings8;
			scopeXAxis2->DataView = displayGridDirectionalLinesSettings3;
			scopeXAxis2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 11, 0));
			axisFormat3->FixedPrecision = true;
			axisFormat3->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"axisFormat3.InternalData")));
			axisFormat3->Precision = 1;
			scopeXAxis2->Format = axisFormat3;
			scopeXAxis2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeXAxis2.InternalData")));
			majorTicks3->StartFrom = ticksStart3;
			scopeXAxis2->MajorTicks = majorTicks3;
			maxAxisValue3->DataValue = 1024;
			displayOptionalValue13->Enabled = false;
			displayOptionalValue13->Value = 1000;
			displayValueRange7->High = displayOptionalValue13;
			displayOptionalValue14->Enabled = false;
			displayOptionalValue14->Value = -1000;
			displayValueRange7->Low = displayOptionalValue14;
			maxAxisValue3->Range = displayValueRange7;
			basicAxisValue5->Value = 1024;
			maxAxisValue3->Tick = basicAxisValue5;
			maxAxisValue3->Value = 1000000;
			scopeXAxis2->Max = maxAxisValue3;
			scopeMaxSample2->Value = static_cast<System::UInt32>(1024);
			scopeXAxis2->MaxSample = scopeMaxSample2;
			axisValue3->DataValue = 0;
			displayOptionalValue15->Enabled = false;
			displayOptionalValue15->Value = 1000;
			displayValueRange8->High = displayOptionalValue15;
			displayOptionalValue16->Enabled = false;
			displayOptionalValue16->Value = -1000;
			displayValueRange8->Low = displayOptionalValue16;
			axisValue3->Range = displayValueRange8;
			basicAxisValue6->Value = 0;
			axisValue3->Tick = basicAxisValue6;
			axisValue3->Value = 0;
			scopeXAxis2->Min = axisValue3;
			scopeXAxis2->MinorTicks = minorTicks3;
			axisToolBar3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons3->ZoomIn = displayToolBarButton33;
			axisToolBarButtons3->ZoomOff = displayToolBarButton34;
			axisToolBarButtons3->ZoomOneDir = displayToolBarButton35;
			axisToolBarButtons3->ZoomOut = displayToolBarButton36;
			axisToolBar3->Buttons = axisToolBarButtons3;
			axisToolBar3->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar3->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar3->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->ToolBar = axisToolBar3;
			scopeXAxis2->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeXAxis2->UnitScale = scopeXAxisUnitScale2;
			displayViewSize7->Size = static_cast<System::UInt32>(100);
			scopeXAxis2->ViewSize = displayViewSize7;
			displayOptionalValue17->Enabled = false;
			displayOptionalValue17->Value = 100000000;
			displayValueRange9->High = displayOptionalValue17;
			displayOptionalValue18->Enabled = true;
			displayOptionalValue18->Value = 1E-07;
			displayValueRange9->Low = displayOptionalValue18;
			displayAxisZoom3->Range = displayValueRange9;
			scopeXAxis2->Zooming = displayAxisZoom3;
			statePin3->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"statePin3.ConnectionData")));
			scopeXAxis2->ZoomPin = statePin3;
			this->scope1->XAxis = scopeXAxis2;
			pinList4->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"pinList4.ConnectionData")));
			this->scope1->XInputPins = pinList4;
			scopeAutoScaling2->MaxHistory = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace3->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace3->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling2->SpaceAbove = scopeAutoScalingSpace3;
			scopeAutoScalingSpace4->Space = static_cast<System::UInt32>(20);
			scopeAutoScalingSpace4->Threshold = static_cast<System::UInt32>(10);
			scopeAutoScaling2->SpaceBelow = scopeAutoScalingSpace4;
			scopeYAxis2->AutoScaling = scopeAutoScaling2;
			displayTitleLabel4->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 13, 1));
			displayTitleLabel4->Text = L"G(t)";
			scopeYAxis2->AxisLabel = displayTitleLabel4;
			displayViewBackground10->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->Background = displayViewBackground10;
			viewButtonSettings4->Cursor = System::Windows::Forms::Cursors::Default;
			viewButtonSettings4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseDownColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			viewButtonSettings4->MouseOverColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->Button = viewButtonSettings4;
			scopeYAxis2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			scopeYAxis2->CursorSettings = displayAxisCursorSettings4;
			vclPen17->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			vclPen17->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen17.InternalData")));
			displayGridLineSettings9->Pen = vclPen17;
			displayGridDirectionalLinesSettings4->Lines = displayGridLineSettings9;
			vclPen18->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			vclPen18->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"vclPen18.InternalData")));
			displayGridLineSettings10->Pen = vclPen18;
			displayGridDirectionalLinesSettings4->ZeroLine = displayGridLineSettings10;
			scopeYAxis2->DataView = displayGridDirectionalLinesSettings4;
			scopeYAxis2->Font = (gcnew Vcl::VclFont(System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255))), L"Arial", 
				1, 0, true, 11, 0));
			axisFormat4->Precision = 3;
			scopeYAxis2->Format = axisFormat4;
			scopeYAxis2->InternalData = (cli::safe_cast<Vcl::VclBinaryData^  >(resources->GetObject(L"scopeYAxis2.InternalData")));
			majorTicks4->StartFrom = ticksStart4;
			scopeYAxis2->MajorTicks = majorTicks4;
			maxAxisValue4->DataValue = 1000;
			displayOptionalValue19->Enabled = false;
			displayOptionalValue19->Value = 1000;
			displayValueRange10->High = displayOptionalValue19;
			displayOptionalValue20->Enabled = false;
			displayOptionalValue20->Value = -1000;
			displayValueRange10->Low = displayOptionalValue20;
			maxAxisValue4->Range = displayValueRange10;
			basicAxisValue7->Value = 0;
			maxAxisValue4->Tick = basicAxisValue7;
			maxAxisValue4->Value = 10;
			scopeYAxis2->Max = maxAxisValue4;
			axisValue4->DataValue = 1000;
			displayOptionalValue21->Enabled = false;
			displayOptionalValue21->Value = 1000;
			displayValueRange11->High = displayOptionalValue21;
			displayOptionalValue22->Enabled = false;
			displayOptionalValue22->Value = -1000;
			displayValueRange11->Low = displayOptionalValue22;
			axisValue4->Range = displayValueRange11;
			basicAxisValue8->Value = 0;
			axisValue4->Tick = basicAxisValue8;
			axisValue4->Value = 0;
			scopeYAxis2->Min = axisValue4;
			scopeYAxis2->MinorTicks = minorTicks4;
			axisToolBar4->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->ButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBarButtons4->ZoomIn = displayToolBarButton37;
			axisToolBarButtons4->ZoomOff = displayToolBarButton38;
			axisToolBarButtons4->ZoomOneDir = displayToolBarButton39;
			axisToolBarButtons4->ZoomOut = displayToolBarButton40;
			axisToolBar4->Buttons = axisToolBarButtons4;
			axisToolBar4->Cursor = System::Windows::Forms::Cursors::Default;
			axisToolBar4->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->GlyphColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseDownBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseDownButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseOverBorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			axisToolBar4->MouseOverButtonColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			scopeYAxis2->ToolBar = axisToolBar4;
			scopeYAxis2->TrackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			displayViewSize8->Size = static_cast<System::UInt32>(100);
			scopeYAxis2->ViewSize = displayViewSize8;
			displayOptionalValue23->Enabled = false;
			displayOptionalValue23->Value = 100000000;
			displayValueRange12->High = displayOptionalValue23;
			displayOptionalValue24->Enabled = true;
			displayOptionalValue24->Value = 1E-07;
			displayValueRange12->Low = displayOptionalValue24;
			displayAxisZoom4->Range = displayValueRange12;
			scopeYAxis2->Zooming = displayAxisZoom4;
			statePin4->ConnectionData = (cli::safe_cast<OpenWire::PinConnections^  >(resources->GetObject(L"statePin4.ConnectionData")));
			scopeYAxis2->ZoomPin = statePin4;
			this->scope1->YAxis = scopeYAxis2;
			displayZoom2->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->scope1->Zooming = displayZoom2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(184, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(279, 16);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(55, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"ACF 0";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(279, 35);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(55, 17);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"ACF 1";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(359, 17);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(61, 17);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"CCF 01";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(359, 37);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(61, 17);
			this->checkBox4->TabIndex = 10;
			this->checkBox4->Text = L"CCF 10";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(40) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40"});
			this->comboBox1->Location = System::Drawing::Point(561, 9);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(51, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Tag = L"";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(95, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 38);
			this->button3->TabIndex = 12;
			this->button3->Text = L"STOP";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(798, 7);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 25);
			this->button4->TabIndex = 13;
			this->button4->Text = L"save";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(30) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", 
				L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30"});
			this->comboBox2->Location = System::Drawing::Point(561, 40);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(51, 21);
			this->comboBox2->TabIndex = 14;
			this->comboBox2->Tag = L"";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::WindowText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(14, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(273, 31);
			this->label3->TabIndex = 15;
			this->label3->Text = L"                                     ";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1499, 700);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->scope1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"FPGA multi-tau correlator";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->scope1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 comboBox1->SelectedIndex::set(9);
				 comboBox2->SelectedIndex::set(1);
			 }
 public: int addpoint(double x0,double y0){
			 scope1->Channels[0]->Data->AddXYPoint(1,1);
		 return 0;
		 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {								 
				 timer1->Start();
				 target.RUN_MAX=comboBox1->SelectedIndex::get()+1;
				 target.sum_num=comboBox2->SelectedIndex::get()+1;
				 target.ACF0=checkBox1->Checked;
				 target.ACF1=checkBox2->Checked;
				 target.CCF01=checkBox3->Checked;
				 target.CCF10=checkBox4->Checked;

				 target.FPGA_start();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 scope1->Channels[0]->Visible=checkBox1->Checked;
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 scope1->Channels[1]->Visible=checkBox2->Checked;
		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 scope1->Channels[2]->Visible=checkBox3->Checked;
		 }
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 scope1->Channels[3]->Visible=checkBox4->Checked;
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		    EnterCriticalSection(&CriticalSection0);
			if(target.sprunning==true){target.running=false ;
			timer1->Stop();}
			LeaveCriticalSection(&CriticalSection0);
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {			 
				scope1->Channels[0]->Data->Clear();
				scope1->Channels[1]->Data->Clear();
				scope1->Channels[2]->Data->Clear();
				scope1->Channels[3]->Data->Clear();
			 
				unsigned int i=1,j=1;
				while(i<180){
					if((i+1)%9!=0){ 
						if(target.T[target.RUN][i]>100){							
						scope1->Channels[0]->Data->AddXYPoint(target.get_tau(j),target.get_gxx(target.RUN,i));
						scope1->Channels[1]->Data->AddXYPoint(target.get_tau(j),target.get_gyy(target.RUN,i));
						scope1->Channels[2]->Data->AddXYPoint(target.get_tau(j),target.get_gxy(target.RUN,i));
						scope1->Channels[3]->Data->AddXYPoint(target.get_tau(j),target.get_gyx(target.RUN,i));
						}
						j++;
						}
					i++;
				}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox2->Text::get()->Length::get()>0){
				 pin_ptr<const wchar_t> wch = PtrToStringChars(textBox2->Text::get());
				 size_t convertedChars = 0;
			     size_t  sizeInBytes = ((textBox2->Text::get()->Length + 1) * 2);
				 errno_t err = 0;
				 target.fname_0 = (char *)malloc(sizeInBytes);
				 target.fname_1 = (char *)malloc(sizeInBytes);
				 target.fname_2 = (char *)malloc(sizeInBytes);
				 target.fname_3 = (char *)malloc(sizeInBytes);
				 target.fname_RAW= (char *)malloc(sizeInBytes);
				 err = wcstombs_s(&convertedChars, target.fname_0, sizeInBytes,wch, sizeInBytes);
				 err = wcstombs_s(&convertedChars, target.fname_1, sizeInBytes,wch, sizeInBytes);
				 err = wcstombs_s(&convertedChars, target.fname_2, sizeInBytes,wch, sizeInBytes);
				 err = wcstombs_s(&convertedChars, target.fname_3, sizeInBytes,wch, sizeInBytes);
				 err = wcstombs_s(&convertedChars, target.fname_RAW, sizeInBytes,wch, sizeInBytes);
				 strcat(target.fname_0,"_ACF0.dat");
				 strcat(target.fname_1,"_ACF1.dat");
				 strcat(target.fname_2,"_CCF01.dat");
				 strcat(target.fname_3,"_CCF10.dat");
				 strcat(target.fname_RAW,"_RAW.dat");

				
				 if(target.write_res_tofile()!=0)MessageBox::Show("error creating files");
				}
			 else MessageBox::Show("missing filename");
						
			 
		 }
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
};


}

