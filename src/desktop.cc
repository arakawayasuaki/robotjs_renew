#ifdef IS_WINDOWS
#include <windows.h>
#include <winuser.h>
#endif

#include "desktop.h"

std::string getActiveDesktopI()
{
#ifdef IS_WINDOWS
    char DeskName[100] = {0};
    DWORD WriteByte;
    HDESK hDesk = OpenInputDesktop(0, FALSE, GENERIC_ALL);
    GetUserObjectInformationA(hDesk, UOI_NAME, DeskName, sizeof(DeskName), &WriteByte);
    CloseDesktop(hDesk);
    return DeskName;
#else
    return "";
#endif
}

std::string getCurrentDesktopI()
{
#ifdef IS_WINDOWS
    char Name[100] = {0};
    DWORD WriteByte;
    HDESK hDesk = GetThreadDesktop(GetCurrentThreadId());;
    GetUserObjectInformationA(hDesk, UOI_NAME, Name, sizeof(Name), &WriteByte);
    return Name;
#else
    return "";
#endif
}

void setThreadActiveDesktopI()
{
#ifdef IS_WINDOWS
    char Name[100] = { 0 };
    HDESK hDesk = OpenInputDesktop(0, TRUE, GENERIC_ALL);
    SetThreadDesktop(hDesk);
    CloseDesktop(hDesk);
#endif
}
