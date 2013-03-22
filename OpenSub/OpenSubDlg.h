#pragma once
#include "afxwin.h"
#include "inputfileinfo.h"
#include "OSApi.h"
#include "afxcmn.h"

class CLink : public CStatic
{
public:
    CLink();
private:
    BOOL m_PointerOnWnd;
    CFont m_font;
    CBrush m_bck_brush;
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    // Implementation
protected:
    DECLARE_MESSAGE_MAP()

};
// COpenSubDlg dialog
class COpenSubDlg : public CDialog
  {

public:
                     COpenSubDlg(CWnd *pParent=NULL);

   enum { IDD=IDD_OPENSUB_DIALOG };

protected:
   virtual void      DoDataExchange(CDataExchange* pDX);

protected:
   HICON             m_hIcon;

   virtual BOOL      OnInitDialog();
   afx_msg void      OnPaint();
   afx_msg HCURSOR   OnQueryDragIcon();
   DECLARE_MESSAGE_MAP()
private:
   LRESULT           OnSearchFinished(WPARAM wParam, LPARAM lParam);
   LRESULT           OnCopyData(WPARAM wParam, LPARAM lParam);
   static UINT       ThreadSearchSub(LPVOID pvParam);
   static UINT       ThreadDownload(LPVOID pvParam);
   static void       PrintMessage(HWND handle,LPCWSTR msg);
   void              InitializeList();
   void              SetTitle();
   static CString    Read7ZipPath();
private:
   OSApi::SubtitleInfoList m_result_list;
   volatile long     m_search_finished;
   bool              DownloadFinished() { return InterlockedExchangeAdd(&m_search_finished,0)>0; }
   void              DownloadFinished(int flag) { InterlockedExchange(&m_search_finished,flag); }
   void              UpdateList();
public:
   afx_msg void      OnLbnSelchangeList2();
   afx_msg void      OnSysCommand(UINT nID,LPARAM lParam);
private:
   CListCtrl         m_list1;
public:
   afx_msg void      OnBnClickedButton1();
   CComboBox         m_cmb_lang;
   afx_msg void      OnCbnSelchangeCombo1();
   CComboBox         m_cmb_match;
   CButton           m_btn_download;
   CButton           m_btn_explore;
   afx_msg void      OnBnClickedButton2();
  };
//+------------------------------------------------------------------+
