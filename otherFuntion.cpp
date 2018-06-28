#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <direct.h>
#include "head.h"

using namespace std;

readWriteTxt::readWriteTxt() {}

void readWriteTxt::generate_txt1For64Bit(string txtName, string dirpath) {
	//fstream是一个类，下面定义一个fstream类的对象file，file的函数open()是为了获得文件指针，最后一定要用close()去delete掉指针
	fstream file, outfile, firstfile, newTxtFile1;// , newTxtFile2;
	file.open(txtName, ios::in);
	firstfile.open(txtName, ios::in);

	string txtPath = dirpath + "\\1.txt";
	string newTxtName1 = dirpath + "\\1new_ROM_L2.txt";
	//string newTxtName2 = dirpath + "\\new_2_ROM_L2.txt";
	string newTxtPath = dirpath + "\\该文件格式错误.txt";
	outfile.open(txtPath, ios::out);
	newTxtFile1.open(newTxtName1, ios::out);
	//newTxtFile2.open(newTxtName2, ios::out);

	//cout << txtName + ".txt" << endl << dirpath + "\\1.txt" << endl;

	//int k = 0;
	//bool b1 = 0, b2 = 0, b3 = 0, b4 = 0, b11 = 0, b12 = 0;
	int firstNum;

	firstNum = firstfile.get();
	if (firstfile.eof())  //一个字符都未读到，表示文件为空
	{
		file.close();
		firstfile.close();
		outfile << "文件为空" << endl;
		outfile.close();//需要关闭文件才能修改文件名
		rename(txtPath.c_str(), newTxtPath.c_str());
		return;
	}

	//int k0 = 0;
	int newTxt[8][1122];
	const int bit1 = 1137;
	const int bit2 = 1122;
	char row1[bit1], row2[bit1], row3[bit1], row4[bit1], row5[bit1], row6[bit1], row7[bit1], row8[bit1], row9[bit1], row10[bit1];

	char char_r1[bit2], char_r2[bit2], char_r3[bit2], char_r4[bit2], char_r5[bit2], char_r6[bit2], char_r7[bit2], char_r8[bit2], char_r9[bit2], char_r10[bit2];
	int r1[bit2], r2[bit2], r3[bit2], r4[bit2], r5[bit2], r6[bit2], r7[bit2], r8[bit2], r9[bit2], r10[bit2];
	while (file.getline(row1, bit1)) 
	{
		file.getline(row2, bit1);
		file.getline(row3, bit1);
		file.getline(row4, bit1);
		file.getline(row5, bit1);
		file.getline(row6, bit1);
		file.getline(row7, bit1);
		file.getline(row8, bit1);
		file.getline(row9, bit1);
		file.getline(row10, bit1);

		//cout << row1 << endl;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////用于71位
		//bit71_To_bit64(row1, char_r1);
		//bit71_To_bit64(row2, char_r2);
		//bit71_To_bit64(row3, char_r3);
		//bit71_To_bit64(row4, char_r4);
		//bit71_To_bit64(row5, char_r5);
		//bit71_To_bit64(row6, char_r6);
		//bit71_To_bit64(row7, char_r7);
		//bit71_To_bit64(row8, char_r8);
		//bit71_To_bit64(row9, char_r9);
		//bit71_To_bit64(row10, char_r10);
		////for (int i = 0; i < 1122; ++i)
		////{
		////	cout << char_r1[i];
		////}

		//charToInt(char_r1, char_r2, char_r3, char_r4, char_r5, char_r6, char_r7, char_r8, char_r9, char_r10, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//用于64位
		charToInt(row1, row2, row3, row4, row5, row6, row7, row8, row9, row10, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//for (int i = 0; i < bit2; ++i)
		//{
		//	if (row1[i] == '1') {r1[i] = 1;}
		//	else{r1[i] = 0;}

		//	if (row2[i] == '1') { r2[i] = 1; }
		//	else { r2[i] = 0; }

		//	if (row3[i] == '1') { r3[i] = 1; }
		//	else { r3[i] = 0; }

		//	if (row4[i] == '1') { r4[i] = 1; }
		//	else { r4[i] = 0; }

		//	if (row5[i] == '1') { r5[i] = 1; }
		//	else { r5[i] = 0; }

		//	if (row6[i] == '1') { r6[i] = 1; }
		//	else { r6[i] = 0; }

		//	if (row7[i] == '1') { r7[i] = 1; }
		//	else { r7[i] = 0; }

		//	if (row8[i] == '1') { r8[i] = 1; }
		//	else { r8[i] = 0; }

		//	if (row9[i] == '1') { r9[i] = 1; }
		//	else { r9[i] = 0; }

		//	if (row10[i] == '1') { r10[i] = 1; }
		//	else { r10[i] = 0; }

		//	//cout << r1[i];
		//}

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


		//四行的“与”算法
		//for (int i = 0; i < bit2; ++i)
		//{
		//	newTxt[0][i] = r2[i] & r3[i] & r4[i];
		//	newTxt[1][i] = r1[i] & r3[i] & r4[i];
		//	newTxt[2][i] = r1[i] & r2[i] & r4[i];
		//	newTxt[3][i] = r1[i] & r2[i] & r3[i];

		//	newTxt[4][i] = r8[i] & r9[i] & r10[i];
		//	newTxt[5][i] = r7[i] & r9[i] & r10[i];
		//	newTxt[6][i] = r7[i] & r8[i] & r10[i];
		//	newTxt[7][i] = r7[i] & r8[i] & r9[i];
		//}

		//scanFirstStepTxt(newTxtFile2, newTxt[0]);
		//scanFirstStepTxt(newTxtFile2, newTxt[1]);
		//scanFirstStepTxt(newTxtFile2, newTxt[2]);
		//scanFirstStepTxt(newTxtFile2, newTxt[3]);
		//scanFirstStepTxt(newTxtFile2, newTxt[4]);
		//scanFirstStepTxt(newTxtFile2, newTxt[5]);
		//scanFirstStepTxt(newTxtFile2, newTxt[6]);
		//scanFirstStepTxt(newTxtFile2, newTxt[7]);


		for (int i = 0; i < bit2; ++i)
		{
			newTxt[0][i] = r1[i];
			newTxt[1][i] = r2[i];
			newTxt[2][i] = r3[i];
			newTxt[3][i] = r4[i];

			newTxt[4][i] = r7[i];
			newTxt[5][i] = r8[i];
			newTxt[6][i] = r9[i];
			newTxt[7][i] = r10[i];
		}

		//scanFirstStepTxt(newTxtFile2, newTxt[0]);
		//scanFirstStepTxt(newTxtFile2, newTxt[1]);
		//scanFirstStepTxt(newTxtFile2, newTxt[2]);
		//scanFirstStepTxt(newTxtFile2, newTxt[3]);
		//scanFirstStepTxt(newTxtFile2, newTxt[4]);
		//scanFirstStepTxt(newTxtFile2, newTxt[5]);
		//scanFirstStepTxt(newTxtFile2, newTxt[6]);
		//scanFirstStepTxt(newTxtFile2, newTxt[7]);

		int t[17][16];

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				for (int k = 0; k < 16; ++k)
				{
					t[j][k] = newTxt[i][66 * j + k + 1] & newTxt[i][66 * j + k + 17] & newTxt[i][66 * j + k + 33] & newTxt[i][66 * j + k + 49];
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
	//newTxtFile2.close();
	//if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b11 == 0 && b12 == 0)
	//{
	//	outfile.close();
	//}
	//else
	//{
	//	b = 1;
	//}
	//return b;
	//cout << "a" << endl;
}


void readWriteTxt::generate_txt1For71Bit(string txtName, string dirpath) {
	//fstream是一个类，下面定义一个fstream类的对象file，file的函数open()是为了获得文件指针，最后一定要用close()去delete掉指针
	fstream file, outfile, firstfile, newTxtFile1;// , newTxtFile2;
	file.open(txtName, ios::in);
	firstfile.open(txtName, ios::in);

	string txtPath = dirpath + "\\1.txt";
	string newTxtName1 = dirpath + "\\1new_ROM_L2.txt";
	//string newTxtName2 = dirpath + "\\new_2_ROM_L2.txt";
	string newTxtPath = dirpath + "\\该文件格式错误.txt";
	outfile.open(txtPath, ios::out);
	newTxtFile1.open(newTxtName1, ios::out);
	//newTxtFile2.open(newTxtName2, ios::out);

	//cout << txtName + ".txt" << endl << dirpath + "\\1.txt" << endl;

	//int k = 0;
	//bool b1 = 0, b2 = 0, b3 = 0, b4 = 0, b11 = 0, b12 = 0;
	int firstNum;

	firstNum = firstfile.get();
	if (firstfile.eof())  //一个字符都未读到，表示文件为空
	{
		file.close();
		firstfile.close();
		outfile << "文件为空" << endl;
		outfile.close();//需要关闭文件才能修改文件名
		rename(txtPath.c_str(), newTxtPath.c_str());
		return;
	}

	//int k0 = 0;
	int newTxt[8][1122];
	const int bit1 = 1137;
	const int bit2 = 1122;
	char row1[bit1], row2[bit1], row3[bit1], row4[bit1], row5[bit1], row6[bit1], row7[bit1], row8[bit1], row9[bit1], row10[bit1];

	char char_r1[bit2], char_r2[bit2], char_r3[bit2], char_r4[bit2], char_r5[bit2], char_r6[bit2], char_r7[bit2], char_r8[bit2], char_r9[bit2], char_r10[bit2];
	int r1[bit2], r2[bit2], r3[bit2], r4[bit2], r5[bit2], r6[bit2], r7[bit2], r8[bit2], r9[bit2], r10[bit2];
	while (file.getline(row1, bit1))
	{
		file.getline(row2, bit1);
		file.getline(row3, bit1);
		file.getline(row4, bit1);
		file.getline(row5, bit1);
		file.getline(row6, bit1);
		file.getline(row7, bit1);
		file.getline(row8, bit1);
		file.getline(row9, bit1);
		file.getline(row10, bit1);

		//cout << row1 << endl;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//用于71位
		bit71_To_bit64(row1, char_r1);
		bit71_To_bit64(row2, char_r2);
		bit71_To_bit64(row3, char_r3);
		bit71_To_bit64(row4, char_r4);
		bit71_To_bit64(row5, char_r5);
		bit71_To_bit64(row6, char_r6);
		bit71_To_bit64(row7, char_r7);
		bit71_To_bit64(row8, char_r8);
		bit71_To_bit64(row9, char_r9);
		bit71_To_bit64(row10, char_r10);
		//for (int i = 0; i < 1122; ++i)
		//{
		//	cout << char_r1[i];
		//}

		charToInt(char_r1, char_r2, char_r3, char_r4, char_r5, char_r6, char_r7, char_r8, char_r9, char_r10, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////用于64位
		//charToInt(row1, row2, row3, row4, row5, row6, row7, row8, row9, row10, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//for (int i = 0; i < bit2; ++i)
		//{
		//	if (row1[i] == '1') {r1[i] = 1;}
		//	else{r1[i] = 0;}

		//	if (row2[i] == '1') { r2[i] = 1; }
		//	else { r2[i] = 0; }

		//	if (row3[i] == '1') { r3[i] = 1; }
		//	else { r3[i] = 0; }

		//	if (row4[i] == '1') { r4[i] = 1; }
		//	else { r4[i] = 0; }

		//	if (row5[i] == '1') { r5[i] = 1; }
		//	else { r5[i] = 0; }

		//	if (row6[i] == '1') { r6[i] = 1; }
		//	else { r6[i] = 0; }

		//	if (row7[i] == '1') { r7[i] = 1; }
		//	else { r7[i] = 0; }

		//	if (row8[i] == '1') { r8[i] = 1; }
		//	else { r8[i] = 0; }

		//	if (row9[i] == '1') { r9[i] = 1; }
		//	else { r9[i] = 0; }

		//	if (row10[i] == '1') { r10[i] = 1; }
		//	else { r10[i] = 0; }

		//	//cout << r1[i];
		//}

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


		//四行的“与”算法
		//for (int i = 0; i < bit2; ++i)
		//{
		//	newTxt[0][i] = r2[i] & r3[i] & r4[i];
		//	newTxt[1][i] = r1[i] & r3[i] & r4[i];
		//	newTxt[2][i] = r1[i] & r2[i] & r4[i];
		//	newTxt[3][i] = r1[i] & r2[i] & r3[i];

		//	newTxt[4][i] = r8[i] & r9[i] & r10[i];
		//	newTxt[5][i] = r7[i] & r9[i] & r10[i];
		//	newTxt[6][i] = r7[i] & r8[i] & r10[i];
		//	newTxt[7][i] = r7[i] & r8[i] & r9[i];
		//}

		//scanFirstStepTxt(newTxtFile2, newTxt[0]);
		//scanFirstStepTxt(newTxtFile2, newTxt[1]);
		//scanFirstStepTxt(newTxtFile2, newTxt[2]);
		//scanFirstStepTxt(newTxtFile2, newTxt[3]);
		//scanFirstStepTxt(newTxtFile2, newTxt[4]);
		//scanFirstStepTxt(newTxtFile2, newTxt[5]);
		//scanFirstStepTxt(newTxtFile2, newTxt[6]);
		//scanFirstStepTxt(newTxtFile2, newTxt[7]);


		for (int i = 0; i < bit2; ++i)
		{
			newTxt[0][i] = r1[i];
			newTxt[1][i] = r2[i];
			newTxt[2][i] = r3[i];
			newTxt[3][i] = r4[i];

			newTxt[4][i] = r7[i];
			newTxt[5][i] = r8[i];
			newTxt[6][i] = r9[i];
			newTxt[7][i] = r10[i];
		}

		//scanFirstStepTxt(newTxtFile2, newTxt[0]);
		//scanFirstStepTxt(newTxtFile2, newTxt[1]);
		//scanFirstStepTxt(newTxtFile2, newTxt[2]);
		//scanFirstStepTxt(newTxtFile2, newTxt[3]);
		//scanFirstStepTxt(newTxtFile2, newTxt[4]);
		//scanFirstStepTxt(newTxtFile2, newTxt[5]);
		//scanFirstStepTxt(newTxtFile2, newTxt[6]);
		//scanFirstStepTxt(newTxtFile2, newTxt[7]);

		int t[17][16];

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				for (int k = 0; k < 16; ++k)
				{
					t[j][k] = newTxt[i][66 * j + k + 1] & newTxt[i][66 * j + k + 17] & newTxt[i][66 * j + k + 33] & newTxt[i][66 * j + k + 49];
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

	firstfile.close();
	file.close();
	newTxtFile1.close();
}


void readWriteTxt::generate_txt2For64Bit(string txtName, string dirpath) {
	fstream file, outfile, newTxtFile1;
	file.open(txtName, ios::in);

	outfile.open(dirpath + "\\2.txt", ios::out);

	string newTxtName2 = dirpath + "\\2new_ROM_L2.txt";
	newTxtFile1.open(newTxtName2, ios::out);


	int newTxt[8][1122];
	const int bit1 = 1137;
	const int bit2 = 1122;
	char row1[bit1], row2[bit1], row3[bit1], row4[bit1], row5[bit1], row6[bit1], row7[bit1], row8[bit1], row9[bit1], row10[bit1];

	char char_r1[bit2], char_r2[bit2], char_r3[bit2], char_r4[bit2], char_r5[bit2], char_r6[bit2], char_r7[bit2], char_r8[bit2], char_r9[bit2], char_r10[bit2];
	int r1[bit2], r2[bit2], r3[bit2], r4[bit2], r5[bit2], r6[bit2], r7[bit2], r8[bit2], r9[bit2], r10[bit2];
	char rows1[bit2], rows2[bit2], rows3[bit2], rows4[bit2], rows5[bit2], rows6[bit2], rows7[bit2], rows8[bit2], rows9[bit2], rows10[bit2];
	while (file.getline(row1, bit1))
	{
		file.getline(row2, bit1);
		file.getline(row3, bit1);
		file.getline(row4, bit1);
		file.getline(row5, bit1);
		file.getline(row6, bit1);
		file.getline(row7, bit1);
		file.getline(row8, bit1);
		file.getline(row9, bit1);
		file.getline(row10, bit1);

		//cout << row1 << endl;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////用于71位
		//bit71_To_bit64(row1, char_r1);
		//bit71_To_bit64(row2, char_r2);
		//bit71_To_bit64(row3, char_r3);
		//bit71_To_bit64(row4, char_r4);
		//bit71_To_bit64(row5, char_r5);
		//bit71_To_bit64(row6, char_r6);
		//bit71_To_bit64(row7, char_r7);
		//bit71_To_bit64(row8, char_r8);
		//bit71_To_bit64(row9, char_r9);
		//bit71_To_bit64(row10, char_r10);

		////for (int i = 0; i < 1122; ++i)
		////{
		////	cout << char_r1[i];
		////}
		////cout << endl;

		//inverseChar(char_r1, rows1);
		//inverseChar(char_r2, rows2);
		//inverseChar(char_r3, rows3);
		//inverseChar(char_r4, rows4);
		//inverseChar(char_r5, rows5);
		//inverseChar(char_r6, rows6);
		//inverseChar(char_r7, rows7);
		//inverseChar(char_r8, rows8);
		//inverseChar(char_r9, rows9);
		//inverseChar(char_r10, rows10);
		////for (int i = 0; i < 1122; ++i)
		////{
		////	cout << rows1[i];
		////}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//用于64位
		inverseChar(row1, rows1);
		inverseChar(row2, rows2);
		inverseChar(row3, rows3);
		inverseChar(row4, rows4);
		inverseChar(row5, rows5);
		inverseChar(row6, rows6);
		inverseChar(row7, rows7);
		inverseChar(row8, rows8);
		inverseChar(row9, rows9);
		inverseChar(row10, rows10);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		for (int i = 0; i < bit2; ++i)
		{
			if (rows1[i] == '1') { r1[i] = 1; }
			else { r1[i] = 0; }

			if (rows2[i] == '1') { r2[i] = 1; }
			else { r2[i] = 0; }

			if (rows3[i] == '1') { r3[i] = 1; }
			else { r3[i] = 0; }

			if (rows4[i] == '1') { r4[i] = 1; }
			else { r4[i] = 0; }

			if (rows5[i] == '1') { r5[i] = 1; }
			else { r5[i] = 0; }

			if (rows6[i] == '1') { r6[i] = 1; }
			else { r6[i] = 0; }

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

		//for (int i = 0; i < bit2; ++i)
		//{
		//	if (row1[i] == '1') {r1[i] = 1;}
		//	else{r1[i] = 0;}

		//	if (row2[i] == '1') { r2[i] = 1; }
		//	else { r2[i] = 0; }

		//	if (row3[i] == '1') { r3[i] = 1; }
		//	else { r3[i] = 0; }

		//	if (row4[i] == '1') { r4[i] = 1; }
		//	else { r4[i] = 0; }

		//	if (row5[i] == '1') { r5[i] = 1; }
		//	else { r5[i] = 0; }

		//	if (row6[i] == '1') { r6[i] = 1; }
		//	else { r6[i] = 0; }

		//	if (row7[i] == '1') { r7[i] = 1; }
		//	else { r7[i] = 0; }

		//	if (row8[i] == '1') { r8[i] = 1; }
		//	else { r8[i] = 0; }

		//	if (row9[i] == '1') { r9[i] = 1; }
		//	else { r9[i] = 0; }

		//	if (row10[i] == '1') { r10[i] = 1; }
		//	else { r10[i] = 0; }

		//	//cout << r1[i];
		//}

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

		for (int i = 0; i < bit2; ++i)
		{
			newTxt[0][i] = r1[i];
			newTxt[1][i] = r2[i];
			newTxt[2][i] = r3[i];
			newTxt[3][i] = r4[i];

			newTxt[4][i] = r7[i];
			newTxt[5][i] = r8[i];
			newTxt[6][i] = r9[i];
			newTxt[7][i] = r10[i];
		}

		//scanFirstStepTxt(newTxtFile2, newTxt[0]);
		//scanFirstStepTxt(newTxtFile2, newTxt[1]);
		//scanFirstStepTxt(newTxtFile2, newTxt[2]);
		//scanFirstStepTxt(newTxtFile2, newTxt[3]);
		//scanFirstStepTxt(newTxtFile2, newTxt[4]);
		//scanFirstStepTxt(newTxtFile2, newTxt[5]);
		//scanFirstStepTxt(newTxtFile2, newTxt[6]);
		//scanFirstStepTxt(newTxtFile2, newTxt[7]);

		int t[17][16];

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				for (int k = 0; k < 16; ++k)
				{
					t[j][k] = newTxt[i][66 * j + k + 1] & newTxt[i][66 * j + k + 17] & newTxt[i][66 * j + k + 33] & newTxt[i][66 * j + k + 49];
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

	//int newTxt[8][1122];
	//char row1[1123], row2[1123], row3[1123], row4[1123], row5[1123], row6[1123], row7[1123], row8[1123], row9[1123], row10[1123];
	//int r1[1122], r2[1122], r3[1122], r4[1122], r5[1122], r6[1122], r7[1122], r8[1122], r9[1122], r10[1122];
	//while (file.getline(row1, 1123))
	//{
	//	file.getline(row2, 1123);
	//	file.getline(row3, 1123);
	//	file.getline(row4, 1123);
	//	file.getline(row5, 1123);
	//	file.getline(row6, 1123);
	//	file.getline(row7, 1123);
	//	file.getline(row8, 1123);
	//	file.getline(row9, 1123);
	//	file.getline(row10, 1123);

		//char *rows1 = _strrev(row1);
		//char *rows2 = _strrev(row2);
		//char *rows3 = _strrev(row3);
		//char *rows4 = _strrev(row4);
		//char *rows7 = _strrev(row7);
		//char *rows8 = _strrev(row8);
		//char *rows9 = _strrev(row9);
		//char *rows10 = _strrev(row10);


	//	for (int i = 0; i < 1122; ++i)
	//	{
	//		if (rows1[i] == '1') { r1[i] = 1; }
	//		else { r1[i] = 0; }

	//		if (rows2[i] == '1') { r2[i] = 1; }
	//		else { r2[i] = 0; }

	//		if (rows3[i] == '1') { r3[i] = 1; }
	//		else { r3[i] = 0; }

	//		if (rows4[i] == '1') { r4[i] = 1; }
	//		else { r4[i] = 0; }

	//		if (rows7[i] == '1') { r7[i] = 1; }
	//		else { r7[i] = 0; }

	//		if (rows8[i] == '1') { r8[i] = 1; }
	//		else { r8[i] = 0; }

	//		if (rows9[i] == '1') { r9[i] = 1; }
	//		else { r9[i] = 0; }

	//		if (rows10[i] == '1') { r10[i] = 1; }
	//		else { r10[i] = 0; }

	//		//cout << r1[i];
	//	}

	//	for (int i = 0; i < 1122; ++i)
	//	{
	//		newTxt[0][i] = r2[i] & r3[i] & r4[i];
	//		newTxt[1][i] = r1[i] & r3[i] & r4[i];
	//		newTxt[2][i] = r1[i] & r2[i] & r4[i];
	//		newTxt[3][i] = r1[i] & r2[i] & r3[i];

	//		newTxt[4][i] = r8[i] & r9[i] & r10[i];
	//		newTxt[5][i] = r7[i] & r9[i] & r10[i];
	//		newTxt[6][i] = r7[i] & r8[i] & r10[i];
	//		newTxt[7][i] = r7[i] & r8[i] & r9[i];
	//	}
	//	//k0 += 1;

	//	int t[17][16];

	//	for (int i = 0; i < 8; ++i)
	//	{
	//		for (int j = 0; j < 17; ++j)
	//		{
	//			for (int k = 0; k < 16; ++k)
	//			{
	//				t[j][k] = newTxt[i][66 * j + k + 1] | newTxt[i][66 * j + k + 17] | newTxt[i][66 * j + k + 33] | newTxt[i][66 * j + k + 49];
	//				//cout << t[j][k];
	//			}
	//			//cout << endl;
	//		}

	//		for (int m = 0; m < 16; ++m)
	//		{
	//			int count = 0;
	//			for (int n = 0; n < 16; ++n)
	//			{
	//				if (t[n][m] == 1)
	//				{
	//					count += 1;
	//				}
	//				outfile << t[n][m];
	//			}

	//			if (count % 2 == 0)
	//			{
	//				outfile << " 偶：";
	//			}
	//			else
	//			{
	//				outfile << " 奇：";
	//			}
	//			outfile << t[16][m];

	//			outfile << endl;
	//		}
	//	}

	//}





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
    newTxtFile1.close();
	file.close();
	outfile.close();
	//cout << "b" << endl;
}


void readWriteTxt::generate_txt2For71Bit(string txtName, string dirpath) {
	fstream file, outfile, newTxtFile1;
	file.open(txtName, ios::in);

	outfile.open(dirpath + "\\2.txt", ios::out);

	string newTxtName2 = dirpath + "\\2new_ROM_L2.txt";
	newTxtFile1.open(newTxtName2, ios::out);


	int newTxt[8][1122];
	const int bit1 = 1137;
	const int bit2 = 1122;
	char row1[bit1], row2[bit1], row3[bit1], row4[bit1], row5[bit1], row6[bit1], row7[bit1], row8[bit1], row9[bit1], row10[bit1];

	char char_r1[bit2], char_r2[bit2], char_r3[bit2], char_r4[bit2], char_r5[bit2], char_r6[bit2], char_r7[bit2], char_r8[bit2], char_r9[bit2], char_r10[bit2];
	int r1[bit2], r2[bit2], r3[bit2], r4[bit2], r5[bit2], r6[bit2], r7[bit2], r8[bit2], r9[bit2], r10[bit2];
	char rows1[bit2], rows2[bit2], rows3[bit2], rows4[bit2], rows5[bit2], rows6[bit2], rows7[bit2], rows8[bit2], rows9[bit2], rows10[bit2];
	while (file.getline(row1, bit1))
	{
		file.getline(row2, bit1);
		file.getline(row3, bit1);
		file.getline(row4, bit1);
		file.getline(row5, bit1);
		file.getline(row6, bit1);
		file.getline(row7, bit1);
		file.getline(row8, bit1);
		file.getline(row9, bit1);
		file.getline(row10, bit1);

		//cout << row1 << endl;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////用于71位
		//bit71_To_bit64(row1, char_r1);
		//bit71_To_bit64(row2, char_r2);
		//bit71_To_bit64(row3, char_r3);
		//bit71_To_bit64(row4, char_r4);
		//bit71_To_bit64(row5, char_r5);
		//bit71_To_bit64(row6, char_r6);
		//bit71_To_bit64(row7, char_r7);
		//bit71_To_bit64(row8, char_r8);
		//bit71_To_bit64(row9, char_r9);
		//bit71_To_bit64(row10, char_r10);

		////for (int i = 0; i < 1122; ++i)
		////{
		////	cout << char_r1[i];
		////}
		////cout << endl;

		//inverseChar(char_r1, rows1);
		//inverseChar(char_r2, rows2);
		//inverseChar(char_r3, rows3);
		//inverseChar(char_r4, rows4);
		//inverseChar(char_r5, rows5);
		//inverseChar(char_r6, rows6);
		//inverseChar(char_r7, rows7);
		//inverseChar(char_r8, rows8);
		//inverseChar(char_r9, rows9);
		//inverseChar(char_r10, rows10);
		////for (int i = 0; i < 1122; ++i)
		////{
		////	cout << rows1[i];
		////}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//用于64位
		inverseChar(row1, rows1);
		inverseChar(row2, rows2);
		inverseChar(row3, rows3);
		inverseChar(row4, rows4);
		inverseChar(row5, rows5);
		inverseChar(row6, rows6);
		inverseChar(row7, rows7);
		inverseChar(row8, rows8);
		inverseChar(row9, rows9);
		inverseChar(row10, rows10);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		for (int i = 0; i < bit2; ++i)
		{
			if (rows1[i] == '1') { r1[i] = 1; }
			else { r1[i] = 0; }

			if (rows2[i] == '1') { r2[i] = 1; }
			else { r2[i] = 0; }

			if (rows3[i] == '1') { r3[i] = 1; }
			else { r3[i] = 0; }

			if (rows4[i] == '1') { r4[i] = 1; }
			else { r4[i] = 0; }

			if (rows5[i] == '1') { r5[i] = 1; }
			else { r5[i] = 0; }

			if (rows6[i] == '1') { r6[i] = 1; }
			else { r6[i] = 0; }

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

		for (int i = 0; i < bit2; ++i)
		{
			newTxt[0][i] = r1[i];
			newTxt[1][i] = r2[i];
			newTxt[2][i] = r3[i];
			newTxt[3][i] = r4[i];

			newTxt[4][i] = r7[i];
			newTxt[5][i] = r8[i];
			newTxt[6][i] = r9[i];
			newTxt[7][i] = r10[i];
		}

		//scanFirstStepTxt(newTxtFile2, newTxt[0]);
		//scanFirstStepTxt(newTxtFile2, newTxt[1]);
		//scanFirstStepTxt(newTxtFile2, newTxt[2]);
		//scanFirstStepTxt(newTxtFile2, newTxt[3]);
		//scanFirstStepTxt(newTxtFile2, newTxt[4]);
		//scanFirstStepTxt(newTxtFile2, newTxt[5]);
		//scanFirstStepTxt(newTxtFile2, newTxt[6]);
		//scanFirstStepTxt(newTxtFile2, newTxt[7]);

		int t[17][16];

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 17; ++j)
			{
				for (int k = 0; k < 16; ++k)
				{
					t[j][k] = newTxt[i][66 * j + k + 1] & newTxt[i][66 * j + k + 17] & newTxt[i][66 * j + k + 33] & newTxt[i][66 * j + k + 49];
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

	newTxtFile1.close();
	file.close();
	outfile.close();
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
//void readWriteTxt::generateTxt(string txtName, string dirpath) {
//	
//	judgeFor71or64(txtName, dirpath);
//	//generate_txt1(txtName, dirpath);
//	//generate_txt2(txtName, dirpath);
//	//	generate_txt3(txtName, dirpath);
//	//	generate_txt4(txtName, dirpath);
//
//}

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
					judgeFor71or64(fileName, dirpath);
				}
			}
		}

		while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile);
	}
}


//写入TXT中观察每16一组的原始数据
void readWriteTxt::scanFirstStepTxt(fstream &newTxtFile, int r[])
{
	for (int j = 0; j < 17; ++j)
	{
		for (int k = 1; k < 17; ++k)
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
		for (int k = 0; k < 16; ++k)
		{
			newTxtFile << r[66 * j + k + 49];
		}
		newTxtFile << " ";
	}
	newTxtFile << endl;
}


//从71位数据转成64位
void readWriteTxt::bit71_To_bit64(char row[], char char_r[])
{
	char_r[0] = row[0];
	for (int i = 1; i < 33; ++i)
	{
		char_r[i] = row[i + 4];
	}
	for (int i = 33; i < 133; ++i)
	{
		char_r[i] = row[i + 7];
	}
	for (int i = 133; i < 165; ++i)
	{
		char_r[i] = row[i + 11];
	}
	for (int i = 165; i < 1122; ++i)
	{
		char_r[i] = row[i + 14];
	}
}


//让字符数组逆序排列
void readWriteTxt::inverseChar(char char_r[], char rows[])
{
	for (int i = 0; i < 1122; ++i)
	{
		rows[i] = char_r[1121 - i];
	}
}


//因为需要&和|，此函数把字符型转换为整型
void readWriteTxt::charToInt(char char_r1[], char char_r2[], char char_r3[], char char_r4[], char char_r5[], char char_r6[], char char_r7[], char char_r8[], char char_r9[], char char_r10[],
	int r1[], int r2[], int r3[], int r4[], int r5[], int r6[], int r7[], int r8[], int r9[], int r10[])
{
	for (int i = 0; i < 1122; ++i)
	{
		if (char_r1[i] == '1') { r1[i] = 1; }
		else { r1[i] = 0; }

		if (char_r2[i] == '1') { r2[i] = 1; }
		else { r2[i] = 0; }

		if (char_r3[i] == '1') { r3[i] = 1; }
		else { r3[i] = 0; }

		if (char_r4[i] == '1') { r4[i] = 1; }
		else { r4[i] = 0; }

		if (char_r5[i] == '1') { r5[i] = 1; }
		else { r5[i] = 0; }

		if (char_r6[i] == '1') { r6[i] = 1; }
		else { r6[i] = 0; }

		if (char_r7[i] == '1') { r7[i] = 1; }
		else { r7[i] = 0; }

		if (char_r8[i] == '1') { r8[i] = 1; }
		else { r8[i] = 0; }

		if (char_r9[i] == '1') { r9[i] = 1; }
		else { r9[i] = 0; }

		if (char_r10[i] == '1') { r10[i] = 1; }
		else { r10[i] = 0; }

		//cout << r1[i];
	}
}


//用来判断文件格式正确或错误，以及是71位还是64位
void readWriteTxt::judgeFor71or64(string txtName, string dirpath)
{
	//用来判断文件是否为空
	fstream firstfile, outfile;
	firstfile.open(txtName, ios::in);

	int firstNum;
	//string txtPath = dirpath + "\\1.txt";
	string newTxtPath1 = dirpath + "\\空文件.txt";
	string newTxtPath2 = dirpath + "\\文件格式错误.txt";

	firstNum = firstfile.get();
	if (firstfile.eof())  //一个字符都未读到，表示文件为空
	{
		outfile.open(newTxtPath1, ios::out);
		outfile << "文件为空" << endl;
		firstfile.close();
		outfile.close();//需要关闭文件才能修改文件名
		//rename(txtPath.c_str(), newTxtPath1.c_str());
		return;
	}



	//用来判断文件格式是否正确
	fstream file;
	file.open(txtName, ios::in);

	int num = 0;
	char vec1[1200];
	while (file.getline(vec1, 1200))
	{
		num += 1;
		if (vec1[0] != '0')
		{
			outfile.open(newTxtPath2, ios::out);
			outfile << "该文件格式错误" << endl;
			file.close();
			outfile.close();//需要关闭文件才能修改文件名
			firstfile.close();
			//rename(txtPath.c_str(), newTxtPath2.c_str());
			return;
		}
	}
	if (num < 100)
	{
		outfile.open(newTxtPath2, ios::out);
		outfile << "该文件格式错误" << endl;
		file.close();
		outfile.close();//需要关闭文件才能修改文件名
		firstfile.close();
		//rename(txtPath.c_str(), newTxtPath2.c_str());
		return;
	}


	//用来判断是71位还是64位
	fstream bitfile;
	bitfile.open(txtName, ios::in);
	char vec2[1200];
	while (file.getline(vec2, 1200))
	{
		if (vec2[1] == '1' && vec2[2] == '1' && vec2[3] == '1' && vec2[4] == '1')
		{
			continue;
		}
		else
		{
			generate_txt1For64Bit(txtName, dirpath);
			generate_txt2For64Bit(txtName, dirpath);
			break;
		}
	}
	generate_txt1For71Bit(txtName, dirpath);
	generate_txt2For71Bit(txtName, dirpath);

	bitfile.close();
	firstfile.close();
	outfile.close();
	file.close();
}