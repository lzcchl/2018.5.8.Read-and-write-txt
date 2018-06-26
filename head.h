#pragma once  //保证头文件只被编译一次
#include <string>
#include <fstream>

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
	void scanFirstStepTxt(fstream &newTxtFile1, int r[]);
	void bit71_To_bit64(char row[], char char_r[]);
	void inverseChar(char char_r[], char rows[]);
};