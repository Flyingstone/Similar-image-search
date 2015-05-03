#ifndef BUILDDATABASEOFIMAGEFINGER_H
#define BUILDDATABASEOFIMAGEFINGER_H

#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <unordered_map>
#include "ImageHash.h"

#ifndef uint64_t
typedef unsigned long long int uint64_t; // �궨��
#endif // uint64_t

#ifndef hashMap
typedef std::unordered_multimap<uint64_t, std::string> hashMap;
#endif // hashMap

/*
* ���ܣ�����ָ�ƿ�
* ���룺files vector<string> ͼ�����ļ�·�����ļ���
* �����hashDatabase unordered_multimap<uint64_t, string> ���ù�ϣ������ָ�ƿ�
*/
void BuildDatabaseOfImageFinger(std::vector<std::string>, hashMap&);

#endif //BUILDDATABASEOFIMAGEFINGER_H