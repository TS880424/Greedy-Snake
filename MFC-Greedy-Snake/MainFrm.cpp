
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "Snake.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#define GAME_WIN_W (800)
#define GAME_WIN_H (600)
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
#define MY_STYLE (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU |  WS_MINIMIZEBOX | FWS_ADDTOTITLE)
	//创建窗口
	Create(NULL, _T("贪吃蛇"), MY_STYLE, CRect(0, 0, GAME_WIN_W, GAME_WIN_H));
	//设置客户区大小
	{
		CRect rcCli;
		GetClientRect(rcCli);	//获取客户区大小

		RECT rcFrame = { 0,0,m_iWidth + m_iWidth - rcCli.right,m_iHeight + m_iHeight - rcCli.bottom };	//计算边框大小并设置
		MoveWindow(&rcFrame, TRUE);
		//移动窗口至屏幕中央
		CenterWindow();
		ShowWindow(SW_SHOW);
		UpdateData();
	}

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	/*// 创建一个视图以占用框架的工作区
	if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))
	{
		TRACE0("未能创建视图窗口\n");
		return -1;
	}*/
	SetTimer(ETimerldGameLoop, 10, NULL);
	m_game.SetHandle(GetSafeHwnd());

	return 0;
}
//
//BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
//{
//	if( !CFrameWnd::PreCreateWindow(cs) )
//		return FALSE;
//	// TODO: 在此处通过修改
//	//  CREATESTRUCT cs 来修改窗口类或样式
//
//	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
//		 | WS_MINIMIZEBOX | WS_SYSMENU;
//
//	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
//	cs.lpszClass = AfxRegisterWndClass(0);
//	return TRUE;
//}

// CMainFrame 诊断

//#ifdef _DEBUG
//void CMainFrame::AssertValid() const
//{
//	CFrameWnd::AssertValid();
//}
//
//void CMainFrame::Dump(CDumpContext& dc) const
//{
//	CFrameWnd::Dump(dc);
//}
//#endif //_DEBUG
//
//
//// CMainFrame 消息处理程序
//
//void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
//{
//	// 将焦点前移到视图窗口
//	m_wndView.SetFocus();
//}
//
//BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
//{
//	// 让视图第一次尝试该命令
//	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
//		return TRUE;
//
//	// 否则，执行默认处理
//	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
//}



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_game.EnterFrame(GetTickCount());

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_game.onMouseMove(nFlags, point);

	CFrameWnd::OnMouseMove(nFlags, point);
}


void CMainFrame::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_game.OnLButtonUp(nFlags, point);

	CFrameWnd::OnLButtonUp(nFlags, point);
}
