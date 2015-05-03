#ifndef SEARCHIMAGE_H
#define SEARCHIMAGE_H

#include <iostream>
#include <unordered_map>
#include <opencv2\highgui\highgui.hpp>
#include "ImageHash.h"

#ifndef uint64_t
typedef unsigned long long int uint64_t; // �궨��
#endif // uint64_t

#ifndef hashMap
typedef std::unordered_multimap<uint64_t, std::string> hashMap; // �궨��
#endif // hashMap

/*
* ���ܣ�����ָ�ƿ�
* ���룺image cv::Mat ������ͼ��
* �����hashDatabase unordered_multimap<uint64_t, string> ������ָ�ƿ�
* �����searchResult vector<string> ���ҵ���ָ��·��
*/
void SearchImage(cv::Mat, hashMap, std::vector<std::string>&);

#endif // SEARCHIMAGE_H