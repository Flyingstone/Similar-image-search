#include "BuildDatabaseOfImageFinger.h"

/*
* ���ܣ�����ָ�ƿ�
* ���룺files vector<string> ͼ�����ļ�·�����ļ���
* �����hashDatabase unordered_multimap<uint64_t, string> ���ù�ϣ������ָ�ƿ�
*/
void BuildDatabaseOfImageFinger(std::vector<std::string> files, hashMap& hashDatabase)
{
	if (files.empty())
		return;

	for (int i = 0; i < files.size(); i++)
	{
		std::string filePath = files[i];
		cv::Mat image = cv::imread(filePath); // ����ͼ��
		//uint64_t hash = ImageHash(image); // ����ͼ��hashָ��
		uint64_t hash = ImagePHash(image); // ����ͼ��dhashָ��
		//uint64_t hash = ImageDHash(image); // ����ͼ��dhashָ��
		hashDatabase.insert(std::make_pair(hash, filePath)); // ָ����ӵ����ݿ�
	}
}