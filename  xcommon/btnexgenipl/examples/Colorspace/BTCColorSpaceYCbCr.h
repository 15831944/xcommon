/////////////////////////////////////////////////////////////////////////////
//
// NexgenIPL - Next Generation Image Processing Library
// Copyright (c) 1999-2003 Binary Technologies
// All Rights Reserved.
//
// This code may be used in compiled form in any way you desire. This
// file may be redistributed unmodified by any means PROVIDING it is 
// not sold for profit without the authors written consent, and 
// providing that this notice and the authors name is included. If 
// the source code in this file is used in any commercial application 
// then a simple email would be nice.
//
// THIS SOFTWARE IS PROVIDED BY BINARY TECHNOLOGIES ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BINARY TECHNOLOGIES OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
// USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// Binary Technologies
// http://www.binary-technologies.com
// info@binary-technologies.com
//
/////////////////////////////////////////////////////////////////////////////

#ifndef BTCCOLORSPACEYCBCR_INCLUDED
#define BTCCOLORSPACEYCBCR_INCLUDED

#pragma once

#include "BTCColor.h"

#ifndef BTColorSpace_YCbCr
#define BTColorSpace_YCbCr BTColorSpace_External + 1
#endif

class BTCColorSpaceYCbCr : public BTIColorSpace
{
public:
	enum { BTColorSpace_YCbCr_MaxNumComponents = 3 };

	BTCColorSpaceYCbCr() {};
	virtual ~BTCColorSpaceYCbCr() {};

	virtual int GetNumComponents();
	virtual BTColorSpace GetType();

	virtual bool FromCIEXYZ(double xyz[3], double *col);
	virtual bool FromRGB(double rgb[3], double *col);
	virtual bool ToCIEXYZ(double col[], double *xyz);
	virtual bool ToRGB(double col[], double *rgb);
};

#endif // BTCCOLORSPACEYCBCR_INCLUDED
