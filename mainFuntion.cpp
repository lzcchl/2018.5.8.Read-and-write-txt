#include <iostream>
#include <string>
#include <direct.h>
#include "head.h"

using namespace std;

int main()
{
	//�Ȼ�ȡ��ǰ��·��buff
	char buff[500];
	_getcwd(buff, 500);
	string dir = buff;

	//��������ע����񣬿���ת�����̺Ϳ�ִ��exe�ļ���Ŀ¼
	//dir.erase(dir.end() - 20, dir.end());
	//cout << dir << endl;

	cout << "�������ɣ���Ⱥ�..." << endl;
	readWriteTxt A;
	A.traverse_folder(dir);
	cout << "�ɹ���" << endl;
	return 0;
}