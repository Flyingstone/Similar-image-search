#include "ImageHash.h"

/*
* ���ܣ����� hash ������ͼ��ָ��
* ���룺image cv::Mat ����ͼ��
* �����hash uint64_t ����õ���ָ��
*/
uint64_t ImageHash(cv::Mat image)
{
	uint64_t hash = 0; // ���ڱ���hashֵ
	cv::Mat imageGray; // ת����ĻҶ�ͼ��
	cv::Mat imageFinger; // ���ź��8x8��ָ��ͼ��
	int fingerSize = 8; // ָ��ͼ��Ĵ�С

	if (3 == image.channels()) // rgb -> gray
	{
		cv::cvtColor(image, imageGray, CV_RGB2GRAY);
	}
	else
	{
		imageGray = image.clone();
	}

	cv::resize(imageGray, imageFinger, cv::Size(fingerSize, fingerSize)); // ͼ������
	imageFinger.convertTo(imageFinger, CV_32F); // ת��Ϊ������
	cv::Scalar imageMean = cv::mean(imageFinger); // ���ֵ

	/* ����ͼ���ϣָ�ƣ�С�ڵ��ھ�ֵΪ0������Ϊ1 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			if (data[j] > imageMean[0])
			{
				hash = (hash << 1) + 1;
			}
			else
			{
				hash = hash << 1;
			}
		}
	}

	return hash;
}

/*
* ���ܣ����� phash ������ͼ��ָ��
* ���룺image cv::Mat ����ͼ��
* �����hash uint64_t ����õ���ָ��
*/
uint64_t ImagePHash(cv::Mat image)
{
	uint64_t hash = 0; // ���ڱ���hashֵ
	cv::Mat imageGray; // ת����ĻҶ�ͼ��
	cv::Mat imageFinger; // ���ź��8x8��ָ��ͼ��
	int fingerSize = 8; // ָ��ͼ��Ĵ�С
	int dctSize = 32; // dct�任�ĳߴ��С

	if (3 == image.channels()) // rgb -> gray
	{
		cv::cvtColor(image, imageGray, CV_RGB2GRAY);
	}
	else
	{
		imageGray = image.clone();
	}

	cv::resize(imageGray, imageFinger, cv::Size(dctSize, dctSize)); // ͼ������
	imageFinger.convertTo(imageFinger, CV_32F); // ת��Ϊ������
	cv::dct(imageFinger, imageFinger); // �����ź��ͼ�����dct�任
	imageFinger = imageFinger(cv::Rect(0, 0, fingerSize, fingerSize)); // ȡ��Ƶ����

	/* ��dct�任���ϵ��ȡ���� */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			data[j] = logf(abs(data[j]));
		}
	}

	cv::Scalar imageMean = cv::mean(imageFinger); // ���ֵ

	/* ����ͼ���ϣָ�ƣ�С�ڵ��ھ�ֵΪ0������Ϊ1 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			if (data[j] > imageMean[0])
			{
				hash = (hash << 1) + 1;
			}
			else
			{
				hash = hash << 1;
			}
		}
	}

	return hash;
}

/*
* ���ܣ����� dhash ������ͼ��ָ��
* ���룺image cv::Mat ����ͼ��
* �����hash uint64_t ����õ���ָ��
*/
uint64_t ImageDHash(cv::Mat image)
{
	uint64_t hash = 0; // ���ڱ���hashֵ
	cv::Mat imageGray; // ת����ĻҶ�ͼ��
	cv::Mat imageFinger; // ���ź��8x8��ָ��ͼ��
	int fingerSize = 8; // ָ��ͼ��Ĵ�С

	if (3 == image.channels()) // rgb -> gray
	{
		cv::cvtColor(image, imageGray, CV_RGB2GRAY);
	}
	else
	{
		imageGray = image.clone();
	}

	cv::resize(imageGray, imageFinger, cv::Size(fingerSize+1, fingerSize)); // ͼ������

	/* ����ͼ���ϣָ�ƣ�����ǰ���еĵ㣬���ĳ����������Ҳ�ĵ㣬��Ϊ1������Ϊ0 */
	for (int i = 0; i < fingerSize; i++)
	{
		float* data = imageFinger.ptr<float>(i);
		for (int j = 0; j < fingerSize; j++)
		{
			if (data[j] > data[j+1])
			{
				hash = (hash << 1) + 1;
			}
			else
			{
				hash = hash << 1;
			}
		}
	}

	return hash;
}