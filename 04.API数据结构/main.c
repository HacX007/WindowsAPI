#include <Windows.h>
#include <stdio.h>


DWORD ShowFileTime(PFILETIME lptime)
{
	FILETIME ftlocal;
	SYSTEMTIME st;
	FileTimeToLocalFileTime(lptime, &ftlocal);

	FileTimeToSystemTime(&ftlocal, &st);

	printf("%d年%#02d月%#02d日,%#02d:%#02d:%#02d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	return 0;
}

int main() 
{
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	if(!GetFileAttributesEx("main.c", GetFileExInfoStandard, &wfad)) 
	{
		printf("获取文件属性失败: %d\n", GetLastError());
		return 1;
	}
	printf("文件属性:\t\n");
	printf("创建时间:\t");
	ShowFileTime(&wfad.ftCreationTime);
	printf("修改时间:\t");
	ShowFileTime(&wfad.ftLastWriteTime);
	printf("访问时间:\t");
	ShowFileTime(&wfad.ftLastAccessTime);
	system("pause");
	return 0;
};