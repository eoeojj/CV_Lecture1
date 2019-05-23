#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
//simple just print image
/*int main(void)
{
	cout << "Hello OpenCV" << CV_VERSION << std::endl;

	Mat img;
	img = imread("gain.jpg");

	if (img.empty()) {
		cerr << "Image load failed!" << std::endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);

	waitKey();
	return 0;
}*/

//print image with clone, copy
/*int main(void)
{
	Mat img1 = imread("gain.jpg");

	Mat img2 = img1;//���� ���� 
	Mat img3;
	img3 = img1;//���� ����

	Mat img4 = img1.clone();//���� ����
	Mat img5;
	img1.copyTo(img5);//���� ����

	img1.setTo(Scalar(0, 255, 255));//yellow
	namedWindow("gain1", 20);//â �ϳ��� ����� ũ�⸦ 20���� �̸��� gain1
	namedWindow("gain2", 20);//â �ϳ��� ����� ũ�⸦ 20���� �̸��� gain2
	imshow("gain1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("gain2", img5);

	waitKey();
	destroyAllWindows();

	return 0;
}*/

//�κ� ���� ����
/*int main(void)
{
	Mat img1 = imread("gain.jpg", IMREAD_ANYCOLOR);

	if (img1.empty()) {
		cerr << "image load failed" << endl;
		return 0;
	}

	Mat img2 = img1(Rect(100, 120, 340, 240));//�κ� ���� ���� ���� ����
	Mat img3 = img1(Rect(100, 120, 340, 240)).clone();//�κ� ���� �����ؼ� ���� ���� 

	img2 = ~img2;//������� -> img1���� ������ �Ͼ
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
	return 0;
}*/

//������ ���� ���, ��� ���� �� ���
/*int main(void)
{
	Mat img1 = imread("gain.jpg");

	cout << "Width : " << img1.cols << endl;
	cout << "Heigth : " << img1.rows << endl;
	cout << "Channels : " << img1.channels() << endl;

	if (img1.type() == CV_8UC1)
		cout << "img5 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img5 is a truecolor image." << endl;

	float data[] = { 2.f,1.414f,3.f,1.732f };
	Mat mat1(2, 2, CV_32FC1,data);//2x2��� �� ������ ���� CV_32FC1->Ÿ��
	cout << "mat1:\n" << mat1 << endl;//2x2��� ���

	return 0;
}*/

//��� ����
/*int main(void)
{
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1 : \n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2 : \n" << mat2 << endl;

	cout << "mat1.t() : \n" << mat1.t() << endl;//mat1�� ��ġ���
	cout << "mat1 + 3 :\n" << mat1 + 3 << endl;//��� ���ҿ� 3�� ���ϱ�
	cout << "mat1 + mat2 : \n" << mat1 + mat2 << endl;//��� ����
	cout << "mat1 * mat2 : \n" << mat1 * mat2 << endl;//��� ����
	return 0;
}*/

//ũ�� Ÿ�� ��ȯ �Լ�
/*int main(void)
{
	Mat img1 = imread("gain.jpg",IMREAD_GRAYSCALE);

	Mat img1f;
	img1.convertTo(img1f, CV_32FC1);//����� Ÿ�� ����

	uchar data1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << "mat1 : \n" << mat1 << endl;
	cout << "mat2 : \n" << mat2 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1);
	mat1.push_back(mat3);
	cout << "mat1 : \n" << mat1 << endl;

	mat1.resize(6, 100);
	cout << "mat1 : \n" << mat1 << endl;

	return 0;
}*/

//ī�޶� �Է� �ޱ�
/*int main(void)
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "failed!!" << endl;
		return 0;
	}
	
	cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	Mat frame, inversed;
	while (1) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27)//ESC Key
			break;
	}

	destroyAllWindows();
	return 0;
}*/