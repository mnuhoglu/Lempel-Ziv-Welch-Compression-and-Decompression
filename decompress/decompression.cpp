#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ostream>

using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("compout.txt");// file opened here
	ofstream output;
	output.open("decompout.txt");
	int count = 255;

	string arr[4096];

	for(int a=0;a<256;a++)
		arr[a]=char(a);

	int first,second;
	ifs >> first;
	output << char(first);
	
	while(ifs >> second)
	{
		if(second<=count)
		{
				count++;
				arr[count]=arr[first]+arr[second].at(0);
				output << arr[second];
			
		}
		else
		{
			count++;
			arr[count]=arr[first]+arr[first].at(0);
			output << arr[second];
		}
		first = second;
	}

	return 0;
}