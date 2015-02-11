#pragma once
#include "afxwin.h"
#include "inputfileinfo.h"
#include "OSApi.h"
#include "afxcmn.h"

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
   static UINT       ThreadTestSub(LPVOID pvParam);
   static void       PrintMessage(HWND handle, LPCWSTR msg);
   void              InitializeList();
   void              SetTitle();
   static CString    Read7ZipPath();
   static BOOL       Launch(LPCWSTR cmd, HANDLE *hProc=NULL);
   void              EnableButtons(BOOL);
   CString           m_lang;
   CString           m_zip_tmp_file_path;
   CString           m_sub_tmp_file_path;
   CString           m_sub_tmp_file_name;
   WCHAR             m_path[MAX_PATH];
   
private:
   OSApi::SubtitleInfoList m_result_list;
   void              UpdateList();
   BOOL              DownloadAndUnzip(OSApi::subtitle_info &item);
   BOOL              GetSubInfo(OSApi::subtitle_info& sub_info);
public:
   afx_msg void      OnLbnSelchangeList2();
   afx_msg void      OnSysCommand(UINT nID,LPARAM lParam);
private:
   CListCtrl         m_results_list_control;
   InputFileInfo     file_info;
public:
   afx_msg void      OnBnClickedDownload();
   afx_msg void      OnLinkClicked();
   afx_msg void      OnLinkClicked2();
   afx_msg void      OnCbnSelchangeCombo1();
   CComboBox         m_cmb_match;
   CButton           m_btn_download;
   CButton           m_btn_explore;
   CButton           m_btn_play;
   CLink             m_link;
   afx_msg void      OnBnClickedExplore();
   afx_msg void      OnBnClickedPlay();
   CButton m_button_lang;
};
//+------------------------------------------------------------------+
