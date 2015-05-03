#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "GetFilesPath.h"
#include "ImageHash.h"
#include "BuildDatabaseOfImageFinger.h"
#include "SearchImage.h"

using namespace std;
using namespace cv;

int main()
{
	string filePath("D:/Document/vidpic/pictures/101_ObjectCategories"); // �ļ�Ŀ¼
	string fileType("jpg"); // �ļ�����
	
	vector<string> files; // �ļ�·��
	GetFiles(filePath, fileType, files); // ��ȡ�ļ�·��

	unordered_multimap<uint64_t, string> hashDatabase; // ͼ��ָ�ƿ�
	BuildDatabaseOfImageFinger(files, hashDatabase); // ����ͼ��ָ�ƿ�

	//int multiResult = 0;
	//for (int i = 0; i < files.size(); i++)
	//{
	//	cout << i << endl;
	//	string filePaths = files[i];
	//	Mat image = imread(filePaths);
	//	vector<string> searchResult; // �������
	//	SearchImage(image, hashDatabase, searchResult); // �����ݿ�������ͼ��
	//	if (searchResult.size() > 1)
	//		multiResult++;
	//}
	//cout << multiResult << endl;

	// ����ѯͼ��
	string filePaths = filePath + "/Leopards/image_0008." + fileType;
	cout << filePaths.c_str() << endl;
	Mat image = imread(filePaths);
	namedWindow("Figure");
	imshow("Figure", image);
	waitKey();

	vector<string> searchResult; // �������
	SearchImage(image, hashDatabase, searchResult); // �����ݿ�������ͼ��
	for (int i = 0; i < searchResult.size(); i++)
	{
		string findImagePath = searchResult[i];
		cout << findImagePath.c_str() << endl;
	}

	return 0;
}