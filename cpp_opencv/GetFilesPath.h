#ifndef GETFILESPATH_h
#define GETFILESPATH_h

#include <io.h>
#include <iostream>
#include <vector>

/*
* ���ܣ���ȡָ��Ŀ¼�£�������Ŀ¼���������ļ����������Ӧ���ļ�·��
* ���룺filePath string ָ����Ŀ¼
* ���룺fileType string �ļ�����
* �����files vector<string> ���������ļ�·�����ļ���
*/
void GetFiles(std::string, std::string, std::vector<std::string>&);

#endif // GETFILESPATH_h