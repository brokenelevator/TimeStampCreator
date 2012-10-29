// tsm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>


HANDLE target;
FILETIME time_stamp;
SYSTEMTIME users, users_UTC;

int _tmain(int argc, _TCHAR* argv[])
{
if(argc != 11)
        {
        printf("\nUsage: tsm [target] [creation] [access] [write] [year] [month] [day] [hour] [min] [sec]\n\ntarget - file to save timestamp[s] to\ncreation, access, write - timestamp options:\n      c - replace file timestamp\n      x - leave unchanged\nday, month, year - timestamp date(YYYY M D)\nhour, min, sec - timestamp time(24h clock)\n");
        return 0;
        }
users.wYear=_wtoi(argv[5]);
users.wMonth=_wtoi(argv[6]);
users.wDay=_wtoi(argv[7]);
users.wHour=_wtoi(argv[8]);
users.wMinute=_wtoi(argv[9]);
users.wSecond=_wtoi(argv[10]);
TzSpecificLocalTimeToSystemTime(NULL, &users, &users_UTC);
SystemTimeToFileTime(&users_UTC, &time_stamp);
target = CreateFile(argv[1], FILE_WRITE_ATTRIBUTES, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
if(target == INVALID_HANDLE_VALUE)
        {
        printf("Could not open file to write.");
        return -1;
        }
int tmp = 0;
if(wcscmp(argv[2], L"c") == 0)
        {
        tmp = SetFileTime(target, &time_stamp, (LPFILETIME) NULL, (LPFILETIME) NULL);
        if(tmp == 0)
                {
                printf("Changing timestamps failed");
                CloseHandle(target);
                return -1;
                }
        }
if(wcscmp(argv[3], L"c") == 0)
        {
        tmp = SetFileTime(target, (LPFILETIME) NULL, &time_stamp, (LPFILETIME) NULL);
        if(tmp == 0)
                {
                printf("Changing timestamps failed");
                CloseHandle(target);
                return -1;
                }
        }
if(wcscmp(argv[4], L"c") == 0)
        {
        tmp = SetFileTime(target, (LPFILETIME) NULL, (LPFILETIME) NULL, &time_stamp);
        if(tmp == 0)
                {
                printf("Changing timestamps failed");
                CloseHandle(target);
                return -1;
                }
        }
CloseHandle(target);
return 0;
}

