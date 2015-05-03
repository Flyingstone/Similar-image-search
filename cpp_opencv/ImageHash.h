#ifndef IMAGEHASH_H
#define IMAGEHASH_H

#ifndef uint64_t
typedef unsigned long long int uint64_t; // �궨��
#endif // uint64_t

#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

/*
* ���ܣ����� hash ������ͼ��ָ��
* ���룺image cv::Mat ����ͼ��
* �����hash uint64_t ����õ���ָ��
*/
uint64_t ImageHash(cv::Mat);

/*
* ���ܣ����� phash ������ͼ��ָ��
* ���룺image cv::Mat ����ͼ��
* �����hash uint64_t ����õ���ָ��
*/
uint64_t ImagePHash(cv::Mat);

/*
* ���ܣ����� dhash ������ͼ��ָ��
* ���룺image cv::Mat ����ͼ��
* �����hash uint64_t ����õ���ָ��
*/
uint64_t ImageDHash(cv::Mat);

#endif // IMAGEHASH_H