//Given three images, perform edge detection on the three images using Sobel and Laplacian of a Gaussion (LoG) operators.
//image name is  image1.jpg image2.jpg image3.jpg
#define _CRT_SECURE_NO_WARNINGS //必須在include前
#include <stdio.h>
#include <stdlib.h>               
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
static int x = 0;
static int y = 200;

//LOG
void laplacian_of_gaussian(Mat Log)
{
	Mat meta;
	meta = Log.clone();
	for (int i = 2; i < Log.rows - 2; i++)
	{
		for (int j = 2; j < Log.cols - 2; j++)
		{
			int sum = 0;
			sum = meta.at<uchar>(i, j) * 16;
			sum = sum - meta.at<uchar>(i, j - 2) - meta.at<uchar>(i - 1, j - 1) - meta.at<uchar>(i + 1, j - 1)
				- meta.at<uchar>(i - 2, j) - meta.at<uchar>(i + 2, j) - meta.at<uchar>(i - 1, j + 1) - meta.at<uchar>(i + 1, j + 1) - meta.at<uchar>(i, j + 2);
			sum = sum - meta.at<uchar>(i, j - 1) * 2 - meta.at<uchar>(i, j + 1) * 2 - meta.at<uchar>(i - 1, j) * 2 - meta.at<uchar>(i + 1, j) * 2;
			sum = abs(sum);
			if (sum > 255)
				sum = 255;
			else
				sum = sum;
			Log.at<uchar>(i, j) = sum;
		}
	}
}

int showImage(char * name, Mat image)
{
	int addr = 0;
	namedWindow(name);
	moveWindow(name, x + addr, y - 130);
	imshow(name, image);
	waitKey(1);
	x = x + 570;
	return 0;
}

int edge_detection(char * name)
{
	char str_source[7] = "source";
	char LoG[4] = "LoG";
	Mat source, Mat_LoG;
	source = imread(name, 0);
	Mat_LoG = source.clone();
	laplacian_of_gaussian(Mat_LoG);
	showImage(str_source, source);
	showImage(LoG, Mat_LoG);
	return 0;
}

int main()
{
	char image1[11] = "image1.jpg";
	char image2[11] = "image2.jpg";
	char image3[11] = "image3.jpg";
	edge_detection(image1);//image1
	printf("按Enter 到下一張\n");
	int num1 = getchar();
	destroyAllWindows();
	system("cls");
	x = 0;
	edge_detection(image2);//image2
	printf("按Enter 到下一張\n");
	int num2 = getchar();
	destroyAllWindows();
	system("cls");
	x = 0;
	edge_detection(image3);//image3
	printf("按Enter 結束\n");
	int num3 = getchar();
	destroyAllWindows();
	return 0;
}