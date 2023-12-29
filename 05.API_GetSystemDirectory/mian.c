#include <Windows.h>
#include <stdio.h>


int main() 
{
	TCHAR szSystemDir[MAX_PATH];
	GetSystemDirectory(szSystemDir, MAX_PATH);
	printf("%s\n",szSystemDir);

	HANDLE hFile;
	DWORD dwWritten;
	hFile = CreateFile("systemroot.txt",
		GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		printf("创建文件成功!\n");

		if (!WriteFile(hFile, szSystemDir, lstrlen(szSystemDir), &dwWritten, NULL)) {
			return GetLastError();
		}
		printf("写入信息成功!\n");
	}
	CloseHandle(hFile);
	system("pause");
	return 0;
}