//Given three images, perform edge detection on the three images using Sobel and Laplacian of a Gaussion (LoG) operators.
//image name is  image1.jpg image2.jpg image3.jpg
#define _CRT_SECURE_NO_WARNINGS //必須在include前
#include <stdio.h>
#include <stdlib.h>               
#include <math.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
static int x = 0;
static int y = 200;

//sobel
int Sobel(Mat sobel)
{
	int x, y, sum;
	Mat meta;
	meta = sobel.clone();
	for (int i = 1; i < sobel.rows - 1; i++)
	{
		for (int j = 1; j < sobel.cols - 1; j++)
		{
			x = meta.at<uchar>(i - 1, j + 1) + meta.at<uchar>(i, j + 1) * 2 + meta.at<uchar>(i + 1, j + 1) - meta.at<uchar>(i - 1, j - 1) - meta.at<uchar>(i, j - 1) * 2 - meta.at<uchar>(i + 1, j - 1);
			y = meta.at<uchar>(i + 1, j - 1) + meta.at<uchar>(i + 1, j) * 2 + meta.at<uchar>(i + 1, j + 1) - meta.at<uchar>(i - 1, j - 1) - meta.at<uchar>(i - 1, j) * 2 - meta.at<uchar>(i - 1, j - 1);
			sum = abs(x) + abs(y);
			if (sum > 255)
				sum = 255;
			sobel.at<uchar>(i, j) = sum;
		}
	}
	return 0;
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
	char sobel[6] = "sobel";
	Mat source, Mat_sobel;
	source = imread(name, 0);
	Mat_sobel = source.clone();
	Sobel(Mat_sobel);
	showImage(str_source, source);
	showImage(sobel, Mat_sobel);
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
	edge_detection(image2);
	printf("按Enter 到下一張\n");//image2
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