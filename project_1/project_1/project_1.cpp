#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <tuple>
using namespace std;

string username;
string password;
string plik;

tuple<bool, string> log()
{

	string username_1;
	string password_1;

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	system("CLS");

	plik = username + ".txt";
	ifstream file(plik);
	getline(file, username_1);
	getline(file, password_1);
	
	if (password == password_1 && username == username_1) return {true, plik};
	else return { false, "" };
}

void sign() {

	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ofstream file(username+".txt");
	file << username << endl;
	file << password << endl;
	file.close();
}

int main()
{	
	pair<bool, string> q;
	string s;
	bool login;
	int a = 0;
	while (a != 3) {
	again:
		cout << "Press 1 to log in" << endl;
		cout << "Press 2 to sign up" << endl;
		cout << "Press 3 to quit" << endl;
		cout << endl;

		cin >> a;

		system("CLS");

		switch (a) {
		case 1:
			tie(login, s) = log();
			q.first = login;
			q.second = s;
			if (q.first == true)
			{
				cout << "Logged in" << endl;
				cout << "Press 1 to delete" << endl;
				cout << "Press 2 to quit to the selection center" << endl;
				cout << "Press 3 to quit to the desktop" << endl;

				int c;
				cin >> c;

				system("CLS");

				switch (c)
				{
				case 1:
					remove(q.second.c_str());
					goto again;
				case 2:
					goto again;
				}
		case 0:
			return 0;
			}
			else {
				cout << "Failed attempt, shutting down the serwer";
				return 0;
			}
		case 2:
			sign();
			system("CLS");
			break;
		case 3:
			cout << "Goodbye!";
			return 0;
		}

	}
	return 0;
}