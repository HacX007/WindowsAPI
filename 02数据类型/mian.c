#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

int WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, LPSTR lpCmdLine, int nCmdshow)
{
	MessageBox(NULL, TEXT("Hello C"), TEXT("����"), MB_OK);

	//�����ַ���
	LPSTR szString = "Windows data type, string.";

	//��������
	CHAR lpString[120] = { 0 }; //Ҫ����szSring�ĳ���

	//����DWORD���͵�����

	DWORD dwMax = 0xFFFFFFFF;
	DWORD dwOne = 0x1;

	//����INT���͵�����
	INT iMax = 0xFFFFFFFF;
	INT iOne = 0x1;

	//��ʾ�ַ���
	MessageBoxA(NULL, szString, "LPSTR", MB_OK);

	//�����ڴ棬���ַ������Ƶ������У�����NULL��������
	CopyMemory(lpString, szString, lstrlen(szString) + 1);

	//��ʾ���Ƶ��ַ���
	MessageBoxA(NULL, lpString, "CHAR[]", MB_OK);

	//�Ƚ�DWORD����ʾ���
	if (dwMax > dwOne)
	{
		MessageBoxA(NULL, "DWORD���͵����� 0xFFFFFFFF > 0x1", "DWORD", MB_OK);
	}

	//�Ƚ�INT����ʾ���
	if (iMax < iOne)
	{
		MessageBoxA(NULL, "INT���͵����� 0xFFFFFFFF < 0x1", "INT", MB_OK);
	}
	system("pause");
	return 0;
}