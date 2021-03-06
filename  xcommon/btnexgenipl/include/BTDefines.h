/////////////////////////////////////////////////////////////////////////////
//
// NexgenIPL - Next Generation Image Processing Library
// Copyright (c) 1999-2004 Binary Technologies
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

#ifndef BTDEFINES_INCLUDED
#define BTDEFINES_INCLUDED

#pragma once

#if defined(UNICODE) || defined(_UNICODE)
	typedef wchar_t          bt_char;
	typedef wchar_t          bt_uchar;

	#define _BTTEXT(x)       L ## x
#else
	typedef char             bt_char;
	typedef unsigned char    bt_uchar;

	#define _BTTEXT(x)       x
#endif

typedef long                 BTRESULT;
typedef unsigned long        BTCOLORREF;

#define BTRGB(r,g,b)         ((unsigned long)(((unsigned char)(r)|((unsigned short)((unsigned char)(g))<<8))|(((unsigned long)(unsigned char)(b))<<16)))
#define BTRGBA(r,g,b,a)      ((unsigned long)(((unsigned char)(r)|((unsigned short)((unsigned char)(g))<<8))|(((unsigned long)(unsigned char)(b))<<16)|(((unsigned long)(a))<<24)))

#define BTGetRValue(rgba)    ((unsigned char)(rgba))
#define BTGetGValue(rgba)    ((unsigned char)(((unsigned short)(rgba)) >> 8))
#define BTGetBValue(rgba)    ((unsigned char)((rgba)>>16))
#define BTGetAValue(rgba)    ((unsigned char)((rgba)>>24))

#define BTMAKEINTRESOURCE(i) (bt_char *)((unsigned long)((unsigned short)(i)))

enum BTCodecType        { BTCODECTYPE_DECODER = 0,
                          BTCODECTYPE_ENCODER };

enum BTEncodingType     { BTENCODINGTYPE_ASCII = 0,
                          BTENCODINGTYPE_BINARY };

enum BTResolutionMetric { BTMETRIC_NONE       = -1, // Metric unknown
                          BTMETRIC_CENTIMETER =  0, // Resolution is in centimeters (pixels/centimeter)
                          BTMETRIC_METER,           // Resolution is in meters (pixels/meter)
                          BTMETRIC_INCH };          // Resolution is in inches (pixels/inch)
                        

enum BTDCTMethod        { BTDCTMETHOD_ISLOW,   // Slow but accurate integer algorithm.
                          BTDCTMETHOD_IFAST,   // Faster, less accurate integer method.
                          BTDCTMETHOD_FLOAT }; // Floating-point: accurate, fast on fast HW.

enum BTChannel          { BTCHANNEL_RED   = 0x01,
                          BTCHANNEL_GREEN = 0x02,
                          BTCHANNEL_BLUE  = 0x04,
                          BTCHANNEL_ALPHA = 0x08 };

enum BTDirection        { BTDIRECTION_LEFT,
                          BTDIRECTION_RIGHT };

enum BTResizeFilter     { BTRESIZEFILTER_DEFAULT,
                          BTRESIZEFILTER_BOX,
                          BTRESIZEFILTER_BILINEAR,
                          BTRESIZEFILTER_GAUSSIAN,
                          BTRESIZEFILTER_HAMMING,
                          BTRESIZEFILTER_BLACKMAN,
                          BTRESIZEFILTER_TRIANGLE,
                          BTRESIZEFILTER_BELL,
                          BTRESIZEFILTER_BSPLINE,
                          BTRESIZEFILTER_SINC,
                          BTRESIZEFILTER_LANCZOS3,
                          BTRESIZEFILTER_MITCHELL,
                          BTRESIZEFILTER_QUADRATIC,
                          BTRESIZEFILTER_HERMITE,
                          BTRESIZEFILTER_HANNING,
                          BTRESIZEFILTER_CATROM,
                          BTRESIZEFILTER_CUBIC,
                          BTRESIZEFILTER_HANN4 };

enum BTDeInterlaceType  { BTDEINTERLACETYPE_INTERPOLATE,
                          BTDEINTERLACETYPE_DUPLICATE };

enum BTCombineFunction  { BTCOMBINEFUNCTION_NORMAL,
                          BTCOMBINEFUNCTION_ADD,
                          BTCOMBINEFUNCTION_SUBTRACT,
                          BTCOMBINEFUNCTION_MULTIPLY,
                          BTCOMBINEFUNCTION_DIVIDE,
                          BTCOMBINEFUNCTION_DIFFERENCE,
                          BTCOMBINEFUNCTION_LIGHTEST,
                          BTCOMBINEFUNCTION_DARKEST,
                          BTCOMBINEFUNCTION_AVERAGE,
                          BTCOMBINEFUNCTION_OR,
                          BTCOMBINEFUNCTION_AND,
                          BTCOMBINEFUNCTION_SCREEN,
                          BTCOMBINEFUNCTION_OVERLAY };

enum BTNoiseType        { BTNOISETYPE_UNIFORMNOISE = 0,
                          BTNOISETYPE_LAPLACIANNOISE,
                          BTNOISETYPE_POISSONNOISE,
                          BTNOISETYPE_GAUSSIANNOISE,
                          BTNOISETYPE_MULTIPLICATIVEGAUSSIANNOISE,
                          BTNOISETYPE_IMPULSENOISE };

enum BTCompareResult    { BTCOMPARERESULT_IMAGE     = 0x01,   // Images are different.
                          BTCOMPARERESULT_NUMCOLORS = 0x02,   // Number of colours in palette differ.
                          BTCOMPARERESULT_COLOR     = 0x04,   // Image colours differ.
                          BTCOMPARERESULT_SIZE_X    = 0x08,   // Image width differs.
                          BTCOMPARERESULT_SIZE_Y    = 0x10 }; // Image heights differ.

typedef struct tagBTRGBQUAD
{
	unsigned char rgbBlue;
	unsigned char rgbGreen;
	unsigned char rgbRed;
	unsigned char rgbReserved;
} BTRGBQUAD;

typedef struct tagBTResolution
{
	int    nResolutionMetric;
	double HResolution;
	double VResolution;

	tagBTResolution() : nResolutionMetric(BTMETRIC_NONE),
                        HResolution(0.0),
                        VResolution(0.0) {};
} BTResolution;

// ---------------------- BTRESULT value definitions -----------------

#define BTRESULT_TYPEDEF(rc) ((BTRESULT)rc)

#define BT_S_OK           BTRESULT_TYPEDEF(0x00000000L)
#define BT_S_FALSE        BTRESULT_TYPEDEF(0x00000001L)

#define BT_E_NOTIMPL      BTRESULT_TYPEDEF(0x80000001L)
#define BT_E_OUTOFMEMORY  BTRESULT_TYPEDEF(0x80000002L)
#define BT_E_INVALIDARG   BTRESULT_TYPEDEF(0x80000003L)
#define BT_E_NOINTERFACE  BTRESULT_TYPEDEF(0x80000004L)
#define BT_E_POINTER      BTRESULT_TYPEDEF(0x80000005L)
#define BT_E_HANDLE       BTRESULT_TYPEDEF(0x80000006L)
#define BT_E_ABORT        BTRESULT_TYPEDEF(0x80000007L)
#define BT_E_FAIL         BTRESULT_TYPEDEF(0x80000008L)
#define BT_E_ACCESSDENIED BTRESULT_TYPEDEF(0x80000009L)

// ---------------------- List of internal codecs --------------------

// +--------------------+--------------------+---------+---------+
// | Format             | Extension          | Decoder | Encoder |
// +--------------------+--------------------+---------+---------+
// | BMP                | bmp                |    x    |    x    |
// | CUT                | cut                |    x    |    x    |
// | EMF                | emf                |    x    |    -    |
// | EPS                | eps                |    x    |    -    |
// | GIF                | gif                |    x    |    x    |
// | ILBM               | iff,lbm            |    x    |    -    |
// | JP2                | jp2,jpc            |    x    |    x    |
// | JPEG               | jpg,jif,jpeg       |    x    |    x    |
// | MNG                | mng                |    x    |    x    |
// | PCX                | pcx                |    x    |    x    |
// | PNG                | png                |    x    |    x    |
// | PSD                | psd                |    x    |    -    |
// | PSP                | psp                |    x    |    -    |
// | PPM                | ppm                |    x    |    x    |
// | PGM                | pgm                |    x    |    x    |
// | PBM                | pbm                |    x    |    x    |
// | RAS                | ras                |    x    |    x    |
// | TGA                | tga                |    x    |    x    |
// | TIFF               | tif,tiff           |    x    |    x    |
// +--------------------+--------------------+---------+---------+

#endif // BTDEFINES_INCLUDED
