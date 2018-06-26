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
	fstream file, outfile, firstfile, newTxtFile1, newTxtFile2;
	file.open(txtName, ios::in);
	firstfile.open(txtName, ios::in);

	string txtPath = dirpath + "\\1.txt";
	string newTxtName1 = dirpath + "\\new_1_ROM_L2.txt";
	string newTxtName2 = dirpath + "\\new_2_ROM_L2.txt";
	string newTxtPath = dirpath + "\\该文件格式错误.txt";
	outfile.open(txtPath, ios::out);
	newTxtFile1.open(newTxtName1, ios::out);
	newTxtFile2.open(newTxtName2, ios::out);

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

	//int k0 = 0;
	int newTxt[8][1122];
	char row1[1123], row2[1123], row3[1123], row4[1123], row5[1123], row6[1123], row7[1123], row8[1123], row9[1123], row10[1123];
	int r1[1122], r2[1122], r3[1122], r4[1122], r5[1122], r6[1122], r7[1122], r8[1122], r9[1122], r10[1122];
	while (file.getline(row1, 1123)) 
	{
		file.getline(row2, 1123);
		file.getline(row3, 1123);
		file.getline(row4, 1123);
		file.getline(row5, 1123);
		file.getline(row6, 1123);
		file.getline(row7, 1123);
		file.getline(row8, 1123);
		file.getline(row9, 1123);
		file.getline(row10, 1123);

		//cout << row1 << endl;

		for (int i = 0; i < 1122; ++i)
		{
			if (row1[i] == '1') {r1[i] = 1;}
			else{r1[i] = 0;}

			if (row2[i] == '1') { r2[i] = 1; }
			else { r2[i] = 0; }

			if (row3[i] == '1') { r3[i] = 1; }
			else { r3[i] = 0; }

			if (row4[i] == '1') { r4[i] = 1; }
			else { r4[i] = 0; }

			if (row5[i] == '1') { r5[i] = 1; }
			else { r5[i] = 0; }

			if (row6[i] == '1') { r6[i] = 1; }
			else { r6[i] = 0; }

			if (row7[i] == '1') { r7[i] = 1; }
			else { r7[i] = 0; }

			if (row8[i] == '1') { r8[i] = 1; }
			else { r8[i] = 0; }

			if (row9[i] == '1') { r9[i] = 1; }
			else { r9[i] = 0; }

			if (row10[i] == '1') { r10[i] = 1; }
			else { r10[i] = 0; }

			//cout << r1[i];
		}

		scanFirstStepTxt(newTxtFile1, r1);
		scanFirstStepTxt(newTxtFile1, r2);
		scanFirstStepTxt(newTxtFile1, r3);
		scanFirstStepTxt(newTxtFile1, r4);
		scanFirstStepTxt(newTxtFile1, r5);
		scanFirstStepTxt(newTxtFile1, r6);
		scanFirstStepTxt(newTxtFile1, r7);
		scanFirstStepTxt(newTxtFile1, r8);
		scanFirstStepTxt(newTxtFile1, r9);
		scanFirstStepTxt(newTxtFile1, r10);

		for (int i = 0; i < 1122; ++i)
		{
			//newTxt[k0 * 8 + 0][i] = r2[i] & r3[i] & r4[i];
			//newTxt[k0 * 8 + 1][i] = r1[i] & r3[i] & r4[i];
			//newTxt[k0 * 8 + 2][i] = r1[i] & r2[i] & r4[i];
			//newTxt[k0 * 8 + 3][i] = r1[i] & r2[i] & r3[i];

			//newTxt[k0 * 8 + 4][i] = r8[i] & r9[i] & r10[i];
			//newTxt[k0 * 8 + 5][i] = r7[i] & r9[i] & r10[i];
			//newTxt[k0 * 8 + 6][i] = r7[i] & r8[i] & r10[i];
			//newTxt[k0 * 8 + 7][i] = r7[i] & r8[i] & r9[i];
			newTxt[0][i] = r2[i] & r3[i] & r4[i];
			newTxt[1][i] = r1[i] & r3[i] & r4[i];
			newTxt[2][i] = r1[i] & r2[i] & r4[i];
			newTxt[3][i] = r1[i] & r2[i] & r3[i];

			newTxt[4][i] = r8[i] & r9[i] & r10[i];
			newTxt[5][i] = r7[i] & r9[i] & r10[i];
			newTxt[6][i] = r7[i] & r8[i] & r10[i];
			newTxt[7][i] = r7[i] & r8[i] & r9[i];
		}
		//k0 += 1;

		scanFirstStepTxt(newTxtFile2, newTxt[0]);
		scanFirstStepTxt(newTxtFile2, newTxt[1]);
		scanFirstStepTxt(newTxtFile2, newTxt[2]);
		scanFirstStepTxt(newTxtFile2, newTxt[3]);
		scanFirstStepTxt(newTxtFile2, newTxt[4]);
		scanFirstStepTxt(newTxtFile2, newTxt[5]);
		scanFirstStepTxt(newTxtFile2, newTxt[6]);
		scanFirstStepTxt(newTxtFile2, newTxt[7]);

		int t[17][16];

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				for (int k = 0; k < 16; ++k)
				{
					t[j][k] = newTxt[i][66 * j + k + 1] | newTxt[i][66 * j + k + 17] | newTxt[i][66 * j + k + 33] | newTxt[i][66 * j + k + 49];
					//cout << t[j][k];
				}
				//cout << endl;
			}

			for (int m = 0; m < 16; ++m)
			{
				int count = 0;
				for (int n = 0; n < 16; ++n)
				{
					if (t[n][m] == 1)
					{
						count += 1;
					}
					outfile << t[n][m];
				}

				if (count % 2 == 0)
				{
					outfile << " 偶：";
				}
				else
				{
					outfile << " 奇：";
				}
				outfile << t[16][m];

				outfile << endl;
			}
		}

	}

	//for (int j = 0; j < 1122; ++j)
	//{
	//	cout << newTxt[255][j];
	//}









	//char s[1200];
	//while (file.getline(s, 1200)) {
	//	//cout << s << endl;
	//	if (k > 9)
	//	{
	//		k -= 10;
	//	}

	//	if (k == 4 || k == 5)
	//	{
	//		k += 1;
	//		continue;
	//	}
	//	k += 1;

	//	int z = 5;
	//	char a[17][64];
	//	for (int i = 0; i < 32; ++i, ++z)
	//	{
	//		a[0][i] = s[z];
	//	}
	//	if (s[z] != '1' || s[z + 2] != '1')
	//	{
	//		b1 = 1;
	//		outfile << "该文件格式错误" << endl;
	//		outfile.close();//需要关闭文件才能修改文件名
	//		//rename(txtPath.c_str(), newTxtPath.c_str());
	//		break;
	//	}
	//	z += 3;
	//	for (int i = 32; i < 64; ++i, ++z)
	//	{
	//		a[0][i] = s[z];
	//	}
	//	if (s[z] != '0' || s[z + 1] != '0')
	//	{
	//		b11 = 1;
	//		outfile << "该文件格式错误" << endl;
	//		outfile.close();//需要关闭文件才能修改文件名
	//		//rename(txtPath.c_str(), newTxtPath.c_str());
	//		break;
	//	}
	//	z += 2;
	//	for (int i = 0; i < 64; ++i, ++z)
	//	{
	//		a[1][i] = s[z];
	//	}
	//	if (s[z] != '0' || s[z + 1] != '0')
	//	{
	//		b2 = 1;
	//		outfile << "该文件格式错误" << endl;
	//		outfile.close();
	//		//rename(txtPath.c_str(), newTxtPath.c_str());
	//		break;
	//	}
	//	z += 6;
	//	for (int i = 0; i < 32; ++i, ++z)
	//	{
	//		a[2][i] = s[z];
	//	}
	//	if (s[z] != '1' || s[z + 2] != '1')
	//	{
	//		b3 = 1;
	//		outfile << "该文件格式错误" << endl;
	//		outfile.close();
	//		//rename(txtPath.c_str(), newTxtPath.c_str());
	//		break;
	//	}
	//	z += 3;
	//	for (int i = 32; i < 64; ++i, ++z)
	//	{
	//		a[2][i] = s[z];
	//	}
	//	if (s[z] != '0' || s[z + 1] != '0')
	//	{
	//		b12 = 1;
	//		outfile << "该文件格式错误" << endl;
	//		outfile.close();//需要关闭文件才能修改文件名
	//		//rename(txtPath.c_str(), newTxtPath.c_str());
	//		break;
	//	}
	//	z += 2;
	//	for (int i = 3; i < 17; ++i)
	//	{
	//		for (int j = 0; j < 64; ++j, ++z)
	//		{
	//			a[i][j] = s[z];
	//		}
	//		if (s[z] != '0')
	//		{
	//			b4 = 1;
	//			outfile << "该文件格式错误" << endl;
	//			outfile.close();
	//			//rename(txtPath.c_str(), newTxtPath.c_str());
	//			break;
	//		}
	//		z += 2;
	//	}
	//	for (int i = 0; i < 64; ++i) {
	//		int count = 0;
	//		for (int j = 0; j < 16; ++j)
	//		{
	//			if (a[j][i] == '1')
	//			{
	//				count += 1;
	//			}
	//			outfile << a[j][i];
	//		}
	//		if (count % 2 == 0)
	//		{
	//			outfile << "偶：";
	//		}
	//		else
	//		{
	//			outfile << "奇：";
	//		}
	//		outfile << a[16][i] << endl;
	//	}
	//}
	firstfile.close();
	file.close();
	newTxtFile1.close();
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



	int newTxt[8][1122];
	char row1[1123], row2[1123], row3[1123], row4[1123], row5[1123], row6[1123], row7[1123], row8[1123], row9[1123], row10[1123];
	int r1[1122], r2[1122], r3[1122], r4[1122], r5[1122], r6[1122], r7[1122], r8[1122], r9[1122], r10[1122];
	while (file.getline(row1, 1123))
	{
		file.getline(row2, 1123);
		file.getline(row3, 1123);
		file.getline(row4, 1123);
		file.getline(row5, 1123);
		file.getline(row6, 1123);
		file.getline(row7, 1123);
		file.getline(row8, 1123);
		file.getline(row9, 1123);
		file.getline(row10, 1123);

		char *rows1 = _strrev(row1);
		char *rows2 = _strrev(row2);
		char *rows3 = _strrev(row3);
		char *rows4 = _strrev(row4);
		char *rows7 = _strrev(row7);
		char *rows8 = _strrev(row8);
		char *rows9 = _strrev(row9);
		char *rows10 = _strrev(row10);


		for (int i = 0; i < 1122; ++i)
		{
			if (rows1[i] == '1') { r1[i] = 1; }
			else { r1[i] = 0; }

			if (rows2[i] == '1') { r2[i] = 1; }
			else { r2[i] = 0; }

			if (rows3[i] == '1') { r3[i] = 1; }
			else { r3[i] = 0; }

			if (rows4[i] == '1') { r4[i] = 1; }
			else { r4[i] = 0; }

			if (rows7[i] == '1') { r7[i] = 1; }
			else { r7[i] = 0; }

			if (rows8[i] == '1') { r8[i] = 1; }
			else { r8[i] = 0; }

			if (rows9[i] == '1') { r9[i] = 1; }
			else { r9[i] = 0; }

			if (rows10[i] == '1') { r10[i] = 1; }
			else { r10[i] = 0; }

			//cout << r1[i];
		}

		for (int i = 0; i < 1122; ++i)
		{
			newTxt[0][i] = r2[i] & r3[i] & r4[i];
			newTxt[1][i] = r1[i] & r3[i] & r4[i];
			newTxt[2][i] = r1[i] & r2[i] & r4[i];
			newTxt[3][i] = r1[i] & r2[i] & r3[i];

			newTxt[4][i] = r8[i] & r9[i] & r10[i];
			newTxt[5][i] = r7[i] & r9[i] & r10[i];
			newTxt[6][i] = r7[i] & r8[i] & r10[i];
			newTxt[7][i] = r7[i] & r8[i] & r9[i];
		}
		//k0 += 1;

		int t[17][16];

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				for (int k = 0; k < 16; ++k)
				{
					t[j][k] = newTxt[i][66 * j + k + 1] | newTxt[i][66 * j + k + 17] | newTxt[i][66 * j + k + 33] | newTxt[i][66 * j + k + 49];
					//cout << t[j][k];
				}
				//cout << endl;
			}

			for (int m = 0; m < 16; ++m)
			{
				int count = 0;
				for (int n = 0; n < 16; ++n)
				{
					if (t[n][m] == 1)
					{
						count += 1;
					}
					outfile << t[n][m];
				}

				if (count % 2 == 0)
				{
					outfile << " 偶：";
				}
				else
				{
					outfile << " 奇：";
				}
				outfile << t[16][m];

				outfile << endl;
			}
		}

	}





	//int k = 0;
	//char s[1200];
	//while (file.getline(s, 1200)) {
	//	if (k > 9)
	//	{
	//		k -= 10;
	//	}

	//	if (k == 4 || k == 5)
	//	{
	//		k += 1;
	//		continue;
	//	}
	//	k += 1;
	//	//字符串逆序
	//	//char *s1 = _strrev(s);
	//	//cout << s1 << endl;

	//	int z = 5;
	//	char a[17][64];
	//	for (int i = 0; i < 32; ++i, ++z)
	//	{
	//		a[0][i] = s[z];
	//	}
	//	z += 3;
	//	for (int i = 32; i < 64; ++i, ++z)
	//	{
	//		a[0][i] = s[z];
	//	}
	//	z += 2;
	//	for (int i = 0; i < 64; ++i, ++z)
	//	{
	//		a[1][i] = s[z];
	//	}
	//	z += 6;
	//	for (int i = 0; i < 32; ++i, ++z)
	//	{
	//		a[2][i] = s[z];
	//	}
	//	z += 3;
	//	for (int i = 32; i < 64; ++i, ++z)
	//	{
	//		a[2][i] = s[z];
	//	}
	//	z += 2;
	//	for (int i = 3; i < 17; ++i)
	//	{
	//		for (int j = 0; j < 64; ++j, ++z)
	//		{
	//			a[i][j] = s[z];
	//		}
	//		z += 2;
	//	}
	//	for (int i = 63; i >= 0; --i) {
	//		int count = 0;
	//		for (int j = 16; j > 0; --j)
	//		{
	//			if (a[j][i] == '1')
	//			{
	//				count += 1;
	//			}
	//			outfile << a[j][i];
	//		}
	//		if (count % 2 == 0)
	//		{
	//			outfile << "偶：";
	//		}
	//		else
	//		{
	//			outfile << "奇：";
	//		}
	//		outfile << a[0][i] << endl;
	//	}
	//}
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
			int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
			for (int j1 = 0; j1 < 16; ++j1)
			{
				if (a[j1][i] == '1')
				{
					count1 += 1;
				}
				outfile << a[j1][i];
			}
			if (count1 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[16][i] << endl;
			for (int j2 = 0; j2 < 16; ++j2)
			{
				if (a[j2][i + 16] == '1')
				{
					count2 += 1;
				}
				outfile << a[j2][i + 16];
			}
			if (count2 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[16][i + 16] << endl;
			for (int j3 = 0; j3 < 16; ++j3)
			{
				if (a[j3][i + 32] == '1')
				{
					count3 += 1;
				}
				outfile << a[j3][i + 32];
			}
			if (count3 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[16][i + 32] << endl;
			for (int j4 = 0; j4 < 16; ++j4)
			{
				if (a[j4][i + 48] == '1')
				{
					count4 += 1;
				}
				outfile << a[j4][i + 48];
			}
			if (count4 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[16][i + 48] << endl;
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
			int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
			for (int j1 = 16; j1 > 0; --j1)
			{
				if (a[j1][63 - i] == '1')
				{
					count1 += 1;
				}
				outfile << a[j1][63 - i];
			}
			if (count1 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[0][63 - i] << endl;
			for (int j2 = 16; j2 > 0; --j2)
			{
				if (a[j2][47 - i] == '1')
				{
					count2 += 1;
				}
				outfile << a[j2][47 - i];
			}
			if (count2 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[0][47 - i] << endl;
			for (int j3 = 16; j3 > 0; --j3)
			{
				if (a[j3][31 - i] == '1')
				{
					count3 += 1;
				}
				outfile << a[j3][31 - i];
			}
			if (count3 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[0][31 - i] << endl;
			for (int j4 = 16; j4 > 0; --j4)
			{
				if (a[j4][15 - i] == '1')
				{
					count4 += 1;
				}
				outfile << a[j4][15 - i];
			}
			if (count4 % 2 == 0)
			{
				outfile << "偶：";
			}
			else
			{
				outfile << "奇：";
			}
			outfile << a[0][15 - i] << endl;
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
	//if (b == 0)
	//{
	//	generate_txt2(txtName, dirpath);
	//	//generate_txt3(txtName, dirpath);
	//	//generate_txt4(txtName, dirpath);
	//}
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



void readWriteTxt::scanFirstStepTxt(fstream &newTxtFile, int r[])
{
	for (int j = 0; j < 17; ++j)
	{
		for (int k = 0; k < 17; ++k)
		{
			newTxtFile << r[66 * j + k];
		}
		newTxtFile << " ";
		for (int k = 0; k < 16; ++k)
		{
			newTxtFile << r[66 * j + k + 17];
		}
		newTxtFile << " ";
		for (int k = 0; k < 16; ++k)
		{
			newTxtFile << r[66 * j + k + 33];
		}
		newTxtFile << " ";
		for (int k = 0; k < 17; ++k)
		{
			newTxtFile << r[66 * j + k + 49];
		}
		newTxtFile << " ";
	}
	newTxtFile << endl;
}