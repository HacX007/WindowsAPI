#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

int WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, LPSTR lpCmdLine, int nCmdshow)
{
	MessageBox(NULL, TEXT("Hello C"), TEXT("标题"), MB_OK);

	//定义字符串
	LPSTR szString = "Windows data type, string.";

	//定义数组
	CHAR lpString[120] = { 0 }; //要大于szSring的长度

	//定义DWORD类型的数据

	DWORD dwMax = 0xFFFFFFFF;
	DWORD dwOne = 0x1;

	//定义INT类型的数据
	INT iMax = 0xFFFFFFFF;
	INT iOne = 0x1;

	//显示字符串
	MessageBoxA(NULL, szString, "LPSTR", MB_OK);

	//复制内存，将字符串复制到数组中（包括NULL结束符）
	CopyMemory(lpString, szString, lstrlen(szString) + 1);

	//显示复制的字符串
	MessageBoxA(NULL, lpString, "CHAR[]", MB_OK);

	//比较DWORD并显示结果
	if (dwMax > dwOne)
	{
		MessageBoxA(NULL, "DWORD类型的数据 0xFFFFFFFF > 0x1", "DWORD", MB_OK);
	}

	//比较INT并显示结果
	if (iMax < iOne)
	{
		MessageBoxA(NULL, "INT类型的数据 0xFFFFFFFF < 0x1", "INT", MB_OK);
	}
	system("pause");
	return 0;
}