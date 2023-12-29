#include <Windows.h>
#include <stdio.h>

#define BUF_SIZE 256

int main()
{
	HANDLE hFileRead;
	DWORD nIn;
	CHAR buffer[BUF_SIZE];

	hFileRead = CreateFileA("halibote.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFileRead == INVALID_HANDLE_VALUE) {
		printf("Can not open file. Error: %x\n", GetLastError());
		system("pause");
		return -1;
	}
	while (ReadFile(hFileRead, buffer, BUF_SIZE, &nIn, NULL) > 0) {
		printf("%s\n", buffer);
		system("pause");
	}
	CloseHandle(hFileRead);
	printf("Hello World!\n");
	system("pause");
	return 0;
}