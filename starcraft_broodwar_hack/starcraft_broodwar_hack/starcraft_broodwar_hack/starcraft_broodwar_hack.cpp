// starcraft_broodwar_hack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    int newMineral = 2000;
    int readMineral = 0;

    //Retrieves a handle to the top-level window whose class name 
    //and window name match the specified strings. This function does not search child windows.
    //This function does not perform a case-sensitive search.

    HWND hwnd = FindWindowA(NULL, "Brood War");
    cout << hwnd << endl;

    if (hwnd == NULL)
    {
        cout << "Cannot find window." << endl;

        Sleep(30000);
        exit(-1);
    }
    else
    {
        DWORD procID;
        GetWindowThreadProcessId(hwnd, &procID);
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

            if (procID == NULL)
            {
                cout << "Cannot find procssID." << endl;
                Sleep(30000);
                exit(-1);
            }
            else
            {
                cout << "process exists." << endl;
                cout << procID << endl;
                //WriteProcessMemory(handle, (LPVOID)0x0057F0F0, &newMineral, sizeof(newMineral), 0);
                ReadProcessMemory(handle, (PBYTE*)0x57F0F0, &readMineral, sizeof(int), 0);
                //cout << readMineral << endl;
            }
    }

    return 0;
}


