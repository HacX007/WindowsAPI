#include <Windows.h>
#include <stdio.h>


DWORD ShowFileTime(PFILETIME lptime)
{
	FILETIME ftlocal;
	SYSTEMTIME st;
	FileTimeToLocalFileTime(lptime, &ftlocal);

	FileTimeToSystemTime(&ftlocal, &st);

	printf("%d��%#02d��%#02d��,%#02d:%#02d:%#02d\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	return 0;
}

int main() 
{
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	if(!GetFileAttributesEx("main.c", GetFileExInfoStandard, &wfad)) 
	{
		printf("��ȡ�ļ�����ʧ��: %d\n", GetLastError());
		return 1;
	}
	printf("�ļ�����:\t\n");
	printf("����ʱ��:\t");
	ShowFileTime(&wfad.ftCreationTime);
	printf("�޸�ʱ��:\t");
	ShowFileTime(&wfad.ftLastWriteTime);
	printf("����ʱ��:\t");
	ShowFileTime(&wfad.ftLastAccessTime);
	system("pause");
	return 0;
};