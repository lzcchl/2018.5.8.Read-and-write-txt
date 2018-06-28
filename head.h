#pragma once  //保证头文件只被编译一次
#include <string>
#include <fstream>

using namespace std;

class readWriteTxt {
public:
	readWriteTxt::readWriteTxt();
	void generate_txt1For64Bit(string txtName, string dirpath);
	void generate_txt1For71Bit(string txtName, string dirpath);
	void generate_txt2For64Bit(string txtName, string dirpath);
	void generate_txt2For71Bit(string txtName, string dirpath);
	void generate_txt3(string txtName, string dirpath);
	void generate_txt4(string txtName, string dirpath);
	//void generateTxt(string txtName, string dirpath);
	void traverse_folder(string dir);
	void scanFirstStepTxt(fstream &newTxtFile1, int r[]);
	void bit71_To_bit64(char row[], char char_r[]);
	void inverseChar(char char_r[], char rows[]);
	void charToInt(char char_r1[], char char_r2[], char char_r3[], char char_r4[], char char_r5[], char char_r6[], char char_r7[], char char_r8[], char char_r9[], char char_r10[],
		int r1[], int r2[], int r3[], int r4[], int r5[], int r6[], int r7[], int r8[], int r9[], int r10[]);
	void judgeFor71or64(string txtName, string dirpath);
};