#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//function declarations
void createProject(ifstream& in_stream, ofstream& out_stream, vector<string> _fileList);

void transfer(ifstream& in_stream, ofstream& out_stream);

int main( )
{
	ifstream fin;
	ofstream fout;
    vector<string> fileList = {"newProject.cpp", "makefile", "Plan.txt", "Readme.md"};

	createProject(fin, fout, fileList);
}

//function definitions
void createProject(ifstream & in_stream, ofstream & out_stream, vector<string> _fileList)
{
	string temp;
	for (int i = 0; i < _fileList.size(); i++)
	{
		//transferring the cpp template
		in_stream.open("C:\\Users\\Nate\\Documents\\Visual Studio 2015\\Projects\\misc\\NewHWProject\\NewHWProject\\templates\\" + _fileList[i]);
		if (in_stream.fail())
		{
			cout << "Error connecting to the in stream of " << _fileList[i] << endl;
			system("pause");
			exit(1);
		}

		out_stream.open("C:\\Users\\Nate\\Documents\\Visual Studio 2015\\Projects\\School\\" + _fileList[i]);
		if (out_stream.fail())
		{
			cout << "Error connecting the out stream of " << _fileList[i] << endl;
			system("pause");
			exit(1);
		}

		transfer(in_stream, out_stream);

		in_stream.close();
		out_stream.close();
	}
}

void transfer(ifstream& in_stream, ofstream& out_stream)
{
	char next;
	in_stream.get(next);
	while(! in_stream.eof())			//eof becuase its text based data
	{
		out_stream.put(next);
		in_stream.get(next);
	}
}





