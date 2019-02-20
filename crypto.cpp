#include<bits/stdc++.h>
using namespace std;

void encrypt(char* file , char* file1 , int key)
{
	fstream cin(file , ios::in);
	string s;
	getline(cin , s);
	for(int j = 0 ; j < s.size() ; j++)
	{
		s[j] = (s[j] + key) % 256;
	}
	cin.close();
	fstream cout(file1 , ios::out);
	cout  << s;
	cout.close();
}

void decrypt(char* file , char* file1 , int key)
{
	fstream cin(file1 , ios::in);
	string s;
	getline(cin , s);
	for(int j = 0 ; j < s.size() ; j++)
	{
		if((s[j] - key) < 0)
		{
			s[j] = s[j] - key + 256;
		}
		else
			s[j] = (s[j] - key) % 256;
	}
	cin.close();
	fstream cout(file , ios::out);
	cout << s;
	cout.close();
}

int main(int argc , char** argv)
{	
	string s = argv[2];
	int key;
	if(s == "-e")
	{
		cout << "enter the key for encryption: " << endl;
		cin >> key;
		encrypt(argv[3] , argv[4] , key);
	}
	if(s == "-d")
	{
		cout << "enter key value: " << endl;
		int key1;
		cin >> key1;
		decrypt(argv[3] , argv[4] , key1);
	}
return 0;
}
