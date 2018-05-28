#include <iostream>
#include <string>
#include <direct.h>
#include "head.h"

using namespace std;

int main()
{
	//先获取当前的路径buff
	char buff[500];
	_getcwd(buff, 500);
	string dir = buff;

	//下面这行注释与否，可以转换工程和可执行exe文件的目录
	dir.erase(dir.end() - 20, dir.end());
	//cout << dir << endl;

	cout << "正在生成，请等候..." << endl;
	readWriteTxt A;
	A.traverse_folder(dir);
	cout << "成功！" << endl;
	return 0;
}