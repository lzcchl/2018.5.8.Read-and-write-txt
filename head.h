#pragma once  //��֤ͷ�ļ�ֻ������һ��
#include <string>

using namespace std;

class readWriteTxt {
public:
	readWriteTxt::readWriteTxt();
	bool generate_txt1(string txtName, string dirpath, bool b);
	void generate_txt2(string txtName, string dirpath);
	void generate_txt3(string txtName, string dirpath);
	void generate_txt4(string txtName, string dirpath);
	void generateTxt(string txtName, string dirpath);
	void traverse_folder(string dir);
};