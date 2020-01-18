#include <iostream>
#include "header.h"
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

int main()
{

	ifstream ifs;
	ifs.open("compin.txt");// file opened here
	ofstream output;
	output.open("decompout.txt");
	HashTable<string,int> Myhash;
	int value=256;
	char p=' ';
	char c=' ';
	string strforp,strforpc;
	ifs.get(p);
	strforp = p;

	int count = 256;
	while(!ifs.eof())
	{
			ifs.get(c);
			strforpc = strforp+c;
			if(!Myhash.isKeyExist(strforpc) && !ifs.eof())
			{
				Myhash.add(strforpc,count);
				output <<  Myhash.get(strforp) << " ";
				strforp = c;
				count++;
			}
			else if(!ifs.eof())
				strforp = strforpc;
			
	}
			output <<  Myhash.get(strforp) ;
}