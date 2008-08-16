// Sample static code illustrates using IntelliSense features with CBCGPEditCtrl class.
// Comments in code include an extended information about using IntelliSense!

//  --------------------------
//  Note to improved noticeable syntax coloring
//  --------------------------

//  To set or remove a breakpoint (bookmark) click
//  on the Build toolbar, Insert/Remove Breakpoint ('F9')
//  --------------------------
//  To set or remove a bookmark at the currnet line
//  click on the Edit toolbar, Toggle Bookmark ('Ctrl'+'F2');
//  To move the cursor between bookmarks click on the
//  Edit toolbar, Next Bookmark and Previous Bookmark
//  --------------------------
//  To remove all breakpoints click on the Build toolbar,
//  Remove All Breakpoints
//  --------------------------
//  To find the text use find combo box on the Standard toolbar
//  or click on the Edit toolbar, Find ('Ctrl'+'F')
//  --------------------------
//  To look definition of a symbol just set mouse focus on it
//  --------------------------

#include "stdafx.h"

#include <windows.h>
#include <stdio.h>
#include <conio.h>

/////////////////////////////////////////////////////////////////////////////
// CMyClass

class CMyClass
{
public:
    CMyClass(int argc, char* argv[])
    {
        m_argv = new char*[m_argc = argc];

        for (int ind = -1; ++ind < argc; m_argv[ind] = strdup(argv[ind]));

        memset(&m_lf,0,sizeof(LOGFONT));
        m_bTrace = FALSE;
    }

    ~CMyClass()
    {
        OnDestroy();

        for (int ind = -1; ++ind < m_argc; free(m_argv[ind]));

        delete[] m_argv;
    }

    int DoMain()
    {
        if (m_bTrace)
        {
            printf("CMyClass::DoMain ()\n");
        }

        return 0;
    }

    const char* GetAppName() const
    {
        return m_argv[0];
    }

    void EnableTrace(BOOL bTrace = TRUE)
    {
        m_bTrace = bTrace;
    }

protected:
    BOOL m_bTrace;
    LOGFONT m_lf;

    virtual void OnDestroy()
    {
//  To change indentation of the text select lines and
//  click on the Edit toolbar, Increase Ident ('Tab')
//  or Decrease Indent ('Shift'+'Tab') to increase or
//  decrease the left indent of the lines
        if (m_bTrace)
        {
            printf("CMyClass::OnDestroy ()\n");
        }
        
//  To find out the class members' names type "this->"
//  to open class members' popup list
        
        getch();
    }

private:
    int m_argc;
    char** m_argv;
};

/////////////////////////////////////////////////////////////////////////////
// int main(int, char*) - the entry point for the console application

int main(int argc, char* argv[])
{
    CMyClass* pMyClass = new CMyClass(argc, argv);
    
//  To find out the struct or class members' names
//  simple strike '.' after typing its name or just
//  press 'Ctrl'+'Alt'+'T' after '->' or '.'
    printf("%s\n", pMyClass->GetAppName());
    
//  To find out the CMyClass members' names type "pMyClass->"
//  to open class members' popup list.
    
    BOOL bRet = pMyClass->DoMain();
    
    delete pMyClass;
    return bRet;
}
   