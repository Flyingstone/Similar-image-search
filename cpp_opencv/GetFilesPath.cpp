#include "GetFilesPath.h"

/*
* ���ܣ��жϵ�ǰ�ļ��Ƿ���ָ�����ļ�����
* ���룺fileName string �ļ���
* ���룺fileType string �ļ�����
* �����true/false bool  
*/
bool IsSpecifiedFile(std::string fileName, std::string fileType)
{
	// ���������ļ����ĳ���С�ڵ����ļ����͵ĳ��ȣ����� false
	if (fileName.size() <= fileType.size())
		return false;
	// ���������ļ�����Ϊ�գ����� true
	if (fileType.empty())
		return true;

	std::string getFileType = fileName.erase(0, fileName.size() - fileType.size()); // ȡ�ļ����ĺ�λ

	return getFileType == fileType ? true : false;
}

/*
* io.h ͷ�ļ�˵��
* _finddata_t(io.h) �������洢�ļ�������Ϣ�Ľṹ��
*	���У�unsigned attrib���ļ����ԵĴ洢λ�á����洢һ�� unsigned ��Ԫ�����ڱ�ʾ�ļ�������
*		_A_SUBDIR ��ʾ���ļ���
*	char name[_MAX_FNAME]���ļ����ļ���������� _MAX_FNAME ��ʾ�����ļ�������󳤶ȡ�
* _findfirst(io.h) ������ָ�����ļ�����ƥ��ĵ�һ��ʵ�������ɹ��򷵻ص�һ��ʵ���ľ�������򷵻�-1L
* _findnext(io.h) �������ṩ���ļ�����ƥ�����һ��ʵ�������ɹ��򷵻�0�����򷵻أ�1
*/

/*
* ���ܣ���ȡָ��Ŀ¼�£�������Ŀ¼���������ļ����������Ӧ���ļ�·��
* ���룺filePath string ָ����Ŀ¼
* ���룺fileType string �ļ�����
* �����files vector<string> ���������ļ�·�����ļ���
*/
void GetFiles(std::string filePath, std::string fileType, std::vector<std::string>& files)
{
	struct _finddata_t fileinfo; // 
	std::string currentPath; // ��ǰ·��
	long   hFile = 0;//�ļ����

	if ((hFile = _findfirst(currentPath.assign(filePath).append("/*").c_str(), &fileinfo)) !=  -1)
	{
		while (_findnext(hFile, &fileinfo)  == 0)
		{
			if (fileinfo.attrib &  _A_SUBDIR) // _A_SUBDIR ��ʾ���ļ��У��������ļ���
			{
				if (strcmp(fileinfo.name, ".") != 0  &&  strcmp(fileinfo.name, "..") != 0)
				{
					GetFiles(currentPath.assign(filePath).append("/").append(fileinfo.name), fileType, files);
				}
			}
			else // �����ǰ�ļ������ļ��У��򱣴浱ǰ�ļ�
			{
				if (IsSpecifiedFile(fileinfo.name, fileType))
				{
					files.push_back(currentPath.assign(filePath).append("/").append(fileinfo.name));
				}
			}
		}
		_findclose(hFile);
	}
}