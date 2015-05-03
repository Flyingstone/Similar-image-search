#include "SearchImage.h"

/*
* ���ܣ�����ָ�ƿ�
* ���룺image cv::Mat ������ͼ��
* �����hashDatabase unordered_multimap<uint64_t, string> ������ָ�ƿ�
* �����searchResult vector<string> ���ҵ���ָ��·��
*/
void SearchImage(cv::Mat image, hashMap hashDatabase, std::vector<std::string>& searchResult)
{
	//uint64_t hash = ImageHash(image); // ���������ͼ���ָ��
	uint64_t hash = ImagePHash(image); // ���������ͼ���ָ��
	//uint64_t hash = ImageDHash(image); // ���������ͼ���ָ��

	auto range = hashDatabase.equal_range(hash);
	for (hashMap::iterator it = range.first; it!=range.second; ++it)
	{
		searchResult.push_back(it->second);
	}
}