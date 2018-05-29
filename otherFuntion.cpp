#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <direct.h>
#include "head.h"

using namespace std;

readWriteTxt::readWriteTxt() {}

bool readWriteTxt::generate_txt1(string txtName, string dirpath, bool b) {
	//fstream是一个类，下面定义一个fstream类的对象file，file的函数open()是为了获得文件指针，最后一定要用close()去delete掉指针
	fstream file, outfile, firstfile;
	file.open(txtName, ios::in);
	firstfile.open(txtName, ios::in);

	string txtPath = dirpath + "\\1.txt";
	string newTxtPath = dirpath + "\\该文件格式错误.txt";
	outfile.open(txtPath, ios::out);

	//cout << txtName + ".txt" << endl << dirpath + "\\1.txt" << endl;

	int k = 0, firstNum;
	bool b1 = 0, b2 = 0, b3 = 0, b4 = 0, b11 = 0, b12 = 0;

	firstNum = firstfile.get();
	if (firstfile.eof())  //一个字符都未读到，表示文件为空
	{
		b = 1;
		file.close();
		firstfile.close();
		outfile << "文件为空" << endl;
		outfile.close();//需要关闭文件才能修改文件名
		rename(txtPath.c_str(), newTxtPath.c_str());
		return b;
	}

	char s[1200];
	while (file.getline(s, 1200)) {
		//cout << s << endl;
		if (k > 9)
		{
			k -= 10;
		}

		if (k == 4 || k == 5)
		{
			k += 1;
			continue;
		}
		k += 1;

		int z = 5;
		char a[17][64];
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		if (s[z] != '1' || s[z + 2] != '1')
		{
			b1 = 1;
			outfile << "该文件格式错误" << endl;
			outfile.close();//需要关闭文件才能修改文件名
			rename(txtPath.c_str(), newTxtPath.c_str());
			break;
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		if (s[z] != '0' || s[z + 1] != '0')
		{
			b11 = 1;
			outfile << "该文件格式错误" << endl;
			outfile.close();//需要关闭文件才能修改文件名
			rename(txtPath.c_str(), newTxtPath.c_str());
			break;
		}
		z += 2;
		for (int i = 0; i < 64; ++i, ++z)
		{
			a[1][i] = s[z];
		}
		if (s[z] != '0' || s[z + 1] != '0')
		{
			b2 = 1;
			outfile << "该文件格式错误" << endl;
			outfile.close();
			rename(txtPath.c_str(), newTxtPath.c_str());
			break;
		}
		z += 6;
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		if (s[z] != '1' || s[z + 2] != '1')
		{
			b3 = 1;
			outfile << "该文件格式错误" << endl;
			outfile.close();
			rename(txtPath.c_str(), newTxtPath.c_str());
			break;
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		if (s[z] != '0' || s[z + 1] != '0')
		{
			b12 = 1;
			outfile << "该文件格式错误" << endl;
			outfile.close();//需要关闭文件才能修改文件名
			rename(txtPath.c_str(), newTxtPath.c_str());
			break;
		}
		z += 2;
		for (int i = 3; i < 17; ++i)
		{
			for (int j = 0; j < 64; ++j, ++z)
			{
				a[i][j] = s[z];
			}
			if (s[z] != '0')
			{
				b4 = 1;
				outfile << "该文件格式错误" << endl;
				outfile.close();
				rename(txtPath.c_str(), newTxtPath.c_str());
				break;
			}
			z += 2;
		}
		for (int i = 0; i < 64; ++i) {
			for (int j = 0; j < 16; ++j)
			{
				outfile << a[j][i];
			}
			outfile << endl;
		}
	}
	firstfile.close();
	file.close();
	if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b11 == 0 && b12 == 0)
	{
		outfile.close();
	}
	else
	{
		b = 1;
	}
	return b;
	//cout << "a" << endl;
}

void readWriteTxt::generate_txt2(string txtName, string dirpath) {
	fstream file, outfile;
	file.open(txtName, ios::in);

	outfile.open(dirpath + "\\2.txt", ios::out);

	int k = 0;
	char s[1200];
	while (file.getline(s, 1200)) {
		if (k > 9)
		{
			k -= 10;
		}

		if (k == 4 || k == 5)
		{
			k += 1;
			continue;
		}
		k += 1;
		//字符串逆序
		//char *s1 = _strrev(s);
		//cout << s1 << endl;

		int z = 5;
		char a[17][64];
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		z += 2;
		for (int i = 0; i < 64; ++i, ++z)
		{
			a[1][i] = s[z];
		}
		z += 6;
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		z += 2;
		for (int i = 3; i < 17; ++i)
		{
			for (int j = 0; j < 64; ++j, ++z)
			{
				a[i][j] = s[z];
			}
			z += 2;
		}
		for (int i = 63; i >= 0; --i) {
			for (int j = 16; j > 0; --j)
			{
				outfile << a[j][i];
			}
			outfile << endl;
		}
	}
	file.close();
	outfile.close();
	//cout << "b" << endl;
}

void readWriteTxt::generate_txt3(string txtName, string dirpath) {
	fstream file, outfile;
	file.open(txtName, ios::in);

	outfile.open(dirpath + "\\3.txt", ios::out);

	int k = 0;
	char s[1200];
	while (file.getline(s, 1200)) {
		if (k > 9)
		{
			k -= 10;
		}

		if (k == 4 || k == 5)
		{
			k += 1;
			continue;
		}
		k += 1;

		int z = 5;
		char a[17][64];
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		z += 2;
		for (int i = 0; i < 64; ++i, ++z)
		{
			a[1][i] = s[z];
		}
		z += 6;
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		z += 2;
		for (int i = 3; i < 17; ++i)
		{
			for (int j = 0; j < 64; ++j, ++z)
			{
				a[i][j] = s[z];
			}
			z += 2;
		}
		for (int i = 0; i < 16; ++i)
		{
			for (int j1 = 0; j1 < 16; ++j1)
			{
				outfile << a[j1][i];
			}
			outfile << endl;
			for (int j2 = 0; j2 < 16; ++j2)
			{
				outfile << a[j2][i + 16];
			}
			outfile << endl;
			for (int j3 = 0; j3 < 16; ++j3)
			{
				outfile << a[j3][i + 32];
			}
			outfile << endl;
			for (int j4 = 0; j4 < 16; ++j4)
			{
				outfile << a[j4][i + 48];
			}
			outfile << endl;
		}
	}
	file.close();
	outfile.close();
	//cout << "c" << endl;
}

void readWriteTxt::generate_txt4(string txtName, string dirpath) {
	fstream file, outfile;
	file.open(txtName, ios::in);

	outfile.open(dirpath + "\\4.txt", ios::out);

	int k = 0;
	char s[1200];
	while (file.getline(s, 1200)) {
		if (k > 9)
		{
			k -= 10;
		}

		if (k == 4 || k == 5)
		{
			k += 1;
			continue;
		}
		k += 1;
		//字符串逆序
		//char *s1 = _strrev(s);
		//cout << s1 << endl;

		int z = 5;
		char a[17][64];
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[0][i] = s[z];
		}
		z += 2;
		for (int i = 0; i < 64; ++i, ++z)
		{
			a[1][i] = s[z];
		}
		z += 6;
		for (int i = 0; i < 32; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		z += 3;
		for (int i = 32; i < 64; ++i, ++z)
		{
			a[2][i] = s[z];
		}
		z += 2;
		for (int i = 3; i < 17; ++i)
		{
			for (int j = 0; j < 64; ++j, ++z)
			{
				a[i][j] = s[z];
			}
			z += 2;
		}
		for (int i = 0; i < 16; ++i)
		{
			for (int j1 = 16; j1 > 0; --j1)
			{
				outfile << a[j1][63 - i];
			}
			outfile << endl;
			for (int j2 = 16; j2 > 0; --j2)
			{
				outfile << a[j2][47 - i];
			}
			outfile << endl;
			for (int j3 = 16; j3 > 0; --j3)
			{
				outfile << a[j3][31 - i];
			}
			outfile << endl;
			for (int j4 = 16; j4 > 0; --j4)
			{
				outfile << a[j4][15 - i];
			}
			outfile << endl;
		}
	}
	file.close();
	outfile.close();
	//cout << "d" << endl;
}

//调用上面4个函数的总函数
void readWriteTxt::generateTxt(string txtName, string dirpath) {
	bool b = 0;
	b = generate_txt1(txtName, dirpath, b);
	if (b == 0)
	{
		generate_txt2(txtName, dirpath);
		generate_txt3(txtName, dirpath);
		generate_txt4(txtName, dirpath);
	}
}

void readWriteTxt::traverse_folder(string dir) {  //这里的filepath应为"...\\data"
									//string filepath = dir + "\\data";
	string filepath = dir;
	int len1 = filepath.length();
	//cout << filepath << endl;

	intptr_t hFile;
	//long hFile;
	_finddata_t fileinfo;
	string p;
	hFile = _findfirst(p.assign(filepath).append("\\*").c_str(), &fileinfo);
	if (hFile != -1) {
		do {
			if ((fileinfo.attrib & _A_SUBDIR)) {}
			else
			{
				string fileName = p.assign(filepath).append("\\").append(fileinfo.name);
				//cout << fileName << endl;
				int len2 = fileName.length();
				string strLast4 = fileName.substr(len2 - 4, len2);
				//cout << strLast4 << endl;

				if (strLast4 != ".txt") {}
				else
				{
					string txtName = fileName.substr(len1);
					//cout << txtName << endl;
					int len3 = txtName.length();
					string txt = txtName.substr(0, len3 - 4);
					//cout << txt << endl;
					string dirpath = filepath + txt;
					//cout << dirpath << endl;

					//创建一个新的文件夹
					_mkdir(dirpath.c_str());

					//生成txt
					generateTxt(fileName, dirpath);
				}
			}
		}

		while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}