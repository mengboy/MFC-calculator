
// addDlg.h : ͷ�ļ�
//

#pragma once


// CaddDlg �Ի���
class CaddDlg : public CDialogEx
{
// ����
public:
	CaddDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonseven();
	afx_msg void OnBnClickedButtonone();
	// m_input;
	afx_msg void OnBnClickedButtontwo();
	afx_msg void OnBnClickedButtonthree();
	afx_msg void OnBnClickedButtonfour();
	afx_msg void OnBnClickedButtonfive();
	afx_msg void OnBnClickedButtonsix();
	afx_msg void OnBnClickedButtoneight();
	afx_msg void OnBnClickedButtonnine();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButtonsub();
	afx_msg void OnBnClickedButtonmul();
	afx_msg void OnBnClickedButtondiv();
	CString m_input;
	afx_msg void OnBnClickedButtonLeftBra();
	afx_msg void OnBnClickedButtonRightBra();
	afx_msg void OnBnClickedButtonsin();
	afx_msg void OnBnClickedButtoncos();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton3exp();
	afx_msg void OnBnClickedButtonXexp();
	afx_msg void OnBnClickedButtonlog();
	afx_msg void OnBnClickedButtonresult();
	afx_msg void OnBnClickedButtonInt();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonFac();
	afx_msg void OnBnClickedButtonzero();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonCe();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedButtonPoint();
};
