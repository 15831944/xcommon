//*******************************************************************************
// COPYRIGHT NOTES
// ---------------
// This is a part of the BCGPro Library
// Copyright (C) 1998-2006 BCGSoft Ltd.
// All rights reserved.
//
// This source code can be used, distributed or modified
// only under terms and conditions 
// of the accompanying license agreement.
//*******************************************************************************
//
// BCGPRibbonLabel.h: interface for the CBCGPRibbonLabel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BCGPRIBBONLABEL_H__E0F28D16_0073_4E84_A17B_5FAB11B2164A__INCLUDED_)
#define AFX_BCGPRIBBONLABEL_H__E0F28D16_0073_4E84_A17B_5FAB11B2164A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BCGPRibbonButton.h"

#ifndef BCGP_EXCLUDE_RIBBON

class BCGCBPRODLLEXPORT CBCGPRibbonLabel : public CBCGPRibbonButton
{
	DECLARE_DYNCREATE(CBCGPRibbonLabel)

// Construction:
public:
	CBCGPRibbonLabel (LPCTSTR lpszText);
	virtual ~CBCGPRibbonLabel();

protected:
	CBCGPRibbonLabel();

// Overrides
protected:
	virtual void OnDraw (CDC* pDC);
	virtual void OnAfterChangeRect (CDC* pDC);
	virtual void OnLButtonUp (CPoint /*point*/) {}

	virtual BOOL IsTabStop () const
	{
		return FALSE;
	}

	virtual BOOL CanBeAddedToQAT () const
	{
		return FALSE;
	}
};

#endif

#endif // !defined(AFX_BCGPRIBBONLABEL_H__E0F28D16_0073_4E84_A17B_5FAB11B2164A__INCLUDED_)
