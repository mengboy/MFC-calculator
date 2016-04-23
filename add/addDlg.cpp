
// addDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "add.h"
#include "addDlg.h"
#include "afxdialogex.h"
#include "function.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CaddDlg 对话框



CaddDlg::CaddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_DIALOG, pParent)
	, m_input(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CaddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//编辑框
	DDX_Text(pDX, IDC_EDIT1, m_input); 
}

BEGIN_MESSAGE_MAP(CaddDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONSeven, &CaddDlg::OnBnClickedButtonseven)
	ON_BN_CLICKED(IDC_BUTTONOne, &CaddDlg::OnBnClickedButtonone)
	ON_BN_CLICKED(IDC_BUTTONTwo, &CaddDlg::OnBnClickedButtontwo)
	ON_BN_CLICKED(IDC_BUTTONThree, &CaddDlg::OnBnClickedButtonthree)
	ON_BN_CLICKED(IDC_BUTTONFour, &CaddDlg::OnBnClickedButtonfour)
	ON_BN_CLICKED(IDC_BUTTONFive, &CaddDlg::OnBnClickedButtonfive)
	ON_BN_CLICKED(IDC_BUTTONSix, &CaddDlg::OnBnClickedButtonsix)
	ON_BN_CLICKED(IDC_BUTTONEight, &CaddDlg::OnBnClickedButtoneight)
	ON_BN_CLICKED(IDC_BUTTONNine, &CaddDlg::OnBnClickedButtonnine)
	ON_BN_CLICKED(IDC_BUTTON_Back, &CaddDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTONAdd, &CaddDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTONSub, &CaddDlg::OnBnClickedButtonsub)
	ON_BN_CLICKED(IDC_BUTTONMul, &CaddDlg::OnBnClickedButtonmul)
	ON_BN_CLICKED(IDC_BUTTONDiv, &CaddDlg::OnBnClickedButtondiv)
	ON_BN_CLICKED(IDC_BUTTON_Left_Bra, &CaddDlg::OnBnClickedButtonLeftBra)
	ON_BN_CLICKED(IDC_BUTTON_Right_Bra, &CaddDlg::OnBnClickedButtonRightBra)
	ON_BN_CLICKED(IDC_BUTTON_sin, &CaddDlg::OnBnClickedButtonsin)
	ON_BN_CLICKED(IDC_BUTTON_cos, &CaddDlg::OnBnClickedButtoncos)
	ON_BN_CLICKED(IDC_BUTTON34, &CaddDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON25, &CaddDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON15, &CaddDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON_3_exp, &CaddDlg::OnBnClickedButton3exp)
	ON_BN_CLICKED(IDC_BUTTON_X_exp, &CaddDlg::OnBnClickedButtonXexp)
	ON_BN_CLICKED(IDC_BUTTON_log, &CaddDlg::OnBnClickedButtonlog)
	ON_BN_CLICKED(IDC_BUTTONResult, &CaddDlg::OnBnClickedButtonresult)
	ON_BN_CLICKED(IDC_BUTTON_INT, &CaddDlg::OnBnClickedButtonInt)
	ON_BN_CLICKED(IDC_BUTTON_Mod, &CaddDlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_Fac, &CaddDlg::OnBnClickedButtonFac)
	ON_BN_CLICKED(IDC_BUTTONZero, &CaddDlg::OnBnClickedButtonzero)
	ON_BN_CLICKED(IDC_BUTTON_C, &CaddDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CaddDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_RADIO1, &CaddDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CaddDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK2, &CaddDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON_Point, &CaddDlg::OnBnClickedButtonPoint)
END_MESSAGE_MAP()


// CaddDlg 消息处理程序

BOOL CaddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CaddDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CaddDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CaddDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CaddDlg::OnBnClickedButtonone()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("1");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtontwo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("2");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonthree()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("3");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonfour()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("4");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonfive()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("5");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonsix()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("6");
	m_input = m_input + one;
	UpdateData(FALSE);
}

void CaddDlg::OnBnClickedButtonseven()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("7");
	m_input = m_input + one;
	UpdateData(FALSE);
}

void CaddDlg::OnBnClickedButtoneight()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("8");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonnine()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("9");
	m_input = m_input + one;
	UpdateData(FALSE);
}




void CaddDlg::OnBnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_input.Delete(m_input.GetLength() - 1, 1);
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonadd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("+");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonsub()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("-");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonmul()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("*");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtondiv()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("/");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonLeftBra()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("(");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonRightBra()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one(")");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonsin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!Inv)
	{
		CString sin("sin(");
		m_input = m_input + sin;
	}
	else
	{
		CString a_sin("asin(");
		m_input = m_input + a_sin;
		Asin = 1;
	}
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtoncos()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!Inv)
	{
		CString cos("cos(");
		m_input = m_input + cos;
	}
	else
	{
		CString a_cos("acos(");
		m_input = m_input + a_cos;
		Acos = 1;
	}
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButton34()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!Inv)
	{
		CString tan("tan(");
		m_input = m_input + tan;
	}
	else 
	{
		CString a_tan("atan(");
		m_input = m_input + a_tan;
		Atan = 1;
	}
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("3.1415926");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("^(2)");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButton3exp()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("^(3)");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonXexp()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString one("^(");
	m_input = m_input + one;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonlog()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString log("log(");
	m_input = m_input + log;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonresult()
{
	// TODO: 在此添加控件通知处理程序代码
		if (!Inv)
		{
			CString cstrTemp;
			double result;
			cstrTemp = getString(m_input);
			string getStr;
			getStr = CStr2str(cstrTemp);
			result = countAnswer(getStr);
			stringstream sResult;
			sResult << result;
			m_input = sResult.str().c_str();
		}
		else
		{
			//计算反三角函数
			double nTemp;
			if (Asin)
			{
				nTemp = getNum(m_input);
				nTemp = asin(nTemp);
				stringstream sResult;
				sResult << nTemp;
				m_input = sResult.str().c_str();
			}
			else if (Acos)
			{
				nTemp = getNum(m_input);
				nTemp = acos(nTemp);
				stringstream sResult;
				sResult << nTemp;
				m_input = sResult.str().c_str();
			}
			else if (Atan)
			{
				nTemp = getNum(m_input);
				nTemp = atan(nTemp);
				stringstream sResult;
				sResult << nTemp;
				m_input = sResult.str().c_str();
			}
		}
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonInt()
{
	// TODO: 在此添加控件通知处理程序代码
	//取整数部分
	CString IstrTemp;
	UpdateData(TRUE);
	for (int i = 0; i < m_input.GetLength(); i++)
	{
		if (m_input[i] == '.')
		{
			break;
		}
		else
		{
			IstrTemp += m_input[i];
		}
	}
	m_input = IstrTemp;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonMod()
{
	// TODO: 在此添加控件通知处理程序代码
	//取模运算
	UpdateData(TRUE);
	CString mod("%");
	m_input = m_input + mod;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonFac()
{
	// TODO: 在此添加控件通知处理程序代码
	//阶乘
	UpdateData(TRUE);
	CString fac("!");
	m_input = m_input + fac;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonzero()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString zero("0");
	m_input = m_input + zero;
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonC()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_input.Empty();
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedButtonCe()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_input.Empty();
	UpdateData(FALSE);
}

//转换角度
void CaddDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	string str;
	UpdateData(TRUE);
	str = CStr2str(m_input);
	double angle;
	angle = atof(str.c_str()) / 3.1415926 * 180;
	stringstream sResult;
	sResult << angle;
	m_input = sResult.str().c_str();
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	//角度转换弧度
	string str;
	UpdateData(TRUE);
	str = CStr2str(m_input);
	double angle;
	angle = atof(str.c_str()) / 180 * 3.1415926;
	stringstream sResult;
	sResult << angle;
	m_input = sResult.str().c_str();
	UpdateData(FALSE);
}


void CaddDlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK2))
	{
		Inv = 1;
	}
	else
	{
		Inv = 0;
	}
}


void CaddDlg::OnBnClickedButtonPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString point(".");
	m_input = m_input + point;
	UpdateData(FALSE);
}
