// Functors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "VideoClip.h"

using namespace std;

template<typename T>
void print(const vector<T> &container) {
    for (auto &item : container) {
        cout << item << endl;
        cout << endl;
    }
}

void printMenu() {
    cout << "����� ���������� � ����!\n"
        << "�������� ���� �� ��������� ��������:\n"
        << "1 - ������������� �� ��������\n"
        << "2 - ������������� �� ������\n"
        << "3 - ������������� �� ���� ����������\n"
        << "4 - ������������� �� ���������� ����������\n"
        << "5 - ���������\n"
        << "6 - �����" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<VideoClip> videos{ {"Stream", "Blogger", 2020, 11, 15, 237},
    {"Overview", "Specialist", 2021, 01, 15, 131 },
    { "Challenge", "Man", 2019, 8, 24, 674 },
    { "Video game walkthrough", "Gamer", 2017, 12, 6, 751 },
    { "Unpacking", "Expert", 2020, 3, 21, 15 },
    { "Interview", "Journalist", 2020, 5, 10, 500 }
    };   

	bool stop = false;

	while (!stop) {
		system("cls");

		printMenu();

		cout << "������� ����� ����: ";
		int inputMenuItem;
		cin >> inputMenuItem;
		cin.ignore();

		system("cls");

		switch (inputMenuItem)
		{
		case 1: sort(videos.begin(), videos.end(), LessName());
			print(videos);
			break;
		case 2: sort(videos.begin(), videos.end(), LessAuthor());
			print(videos);
			break;
		case 3: sort(videos.begin(), videos.end(), LessDate());
			print(videos);
			break;
		case 4: sort(videos.begin(), videos.end(), LessViews());
			print(videos);
			break;
		case 5: print(videos);
			break;
		case 6: cout << "�� ��������!" << endl;
			stop = true;
			break;
		default:
			cout << "��� ������ ������ ����" << endl;
			break;
		}
		system("pause");
	}


}


