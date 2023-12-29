#include <Windows.h>
#include <stdio.h>
#include <TlHelp32.h>

int main() {
	PROCESSENTRY32 pe32 = {0};
	pe32.dwSize = sizeof(pe32);

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE) {
		printf("CreateToolhelp32Snapshot failed.\n");
		return -1;
	}
	BOOL bMore = Process32First(hProcessSnap, &pe32);

	while (bMore) {
		printf("½ø³ÌID: %d (%hs)\n", pe32.th32ProcessID, pe32.szExeFile);
		bMore = Process32Next(hProcessSnap, &pe32);
	}
	CloseHandle(hProcessSnap);
	return 0;
	system("pause");
}