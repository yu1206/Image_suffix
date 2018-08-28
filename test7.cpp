#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 #include <sstream> 
#include <io.h>
#include <Windows.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
 using namespace std;
 int test7(int argc, char *argv[])
 {
	 string nameInput="G:/F/MTCNN/mtcnn-master2/服务器-车辆样板本/yolo-all-pos.txt";
	 string nameOutput="G:/F/MTCNN/mtcnn-master2/服务器-车辆样板本/yolo-all-pos-out.txt";
	 ifstream f_pos;
	 f_pos.open(nameInput,ios::in);
	 if(!f_pos.is_open())
	 {
		 cout << "文件数据打开错误！"<< endl;
		system("pause");
		return false;
	 }

	 fstream f_pos_out;
	 f_pos_out.open(nameOutput,ios::out);
	  if(!f_pos_out.is_open())
	 {
		 cout << "文件数据打开错误！"<< endl;
		system("pause");
		return false;
	 }

	  char line[1024];
	  while(f_pos.getline(line,sizeof(line)))
	  {
             string line_name;
			 int x1,y1,x2,y2;
			 stringstream str_s(line);
			 str_s>>line_name>>x1>>y1>>x2>>y2;
			 line_name=line_name+".jpg";
			 f_pos_out<<line_name<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	  }
	  f_pos.close();
	  f_pos_out.close();
	 return 0;
 }