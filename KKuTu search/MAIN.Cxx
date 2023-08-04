#include <vector>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <iostream>
#include <Windows.h>
using namespace std;

int main(void) {
	SetConsoleTitle(TEXT("KKuTu search"));

	wcout.imbue(locale("kor"));
	wcin.imbue (locale("kor"));

	wifstream fileTemp(L"file.config");
	wstring   fileName;
	fileTemp >> fileName;

	if (!fileTemp) {
		wcout << L"file.config������ �����ϴ�!" << endl;
		wcout << L"file.config������ �ٽ� �����Ͽ� �ȿ� KKuTuSet������ �����ּ���" << endl << endl;

		system("pause");
		exit(EXIT_FAILURE);
	}

	wifstream       file(fileName);
	wstring         strBuffer;
	vector<wstring> latters;
	wstring         userInput;
	bool            isExist;

	if (!file) {
		wcout << L"���� \"" << fileName <<  L"\"(��)�� ã�� �� �����ϴ�!" << endl;
		wcout << L"\"file.config\" ���Ͽ� �ִ� ���� ���� ��Ȯ ���� Ȯ���� �ּ���!" << endl << endl;

		system("pause");
		exit(EXIT_FAILURE);
	}

	file.imbue(locale(".UTF-8"));
	while (strBuffer != L"&EOF") {
		file >> strBuffer;
		latters.push_back(strBuffer);
	}
	latters.pop_back();
	file.close();

	while (true) {
		wcout << L"\x1b[38;5;3m��¼�� ���� �˻� ���� v0.1" << endl;
		wcout << L"\x1b[38;5;255mù ���� �Է� \x1b[38;5;244m> \x1b[38;5;111m";
		userInput = wstring();
		wcin >> userInput;

		wcout << endl;
		isExist = false;

		wcout << L"\x1b[38;5;46m'" << userInput[0] << L"'\x1b[38;5;255m �� �����ϴ� �ܾ� : " << endl;
		wcout << L"\x1b[38;5;111m";


		for (int i = 0; i < latters.size(); i++) {
			if (latters[i][0] == userInput[0]) {
				wcout << "  - " << latters[i] << endl;
				isExist = true;
			}
		}

		if (!isExist) wcout << L"�����ϴ�!" << endl;

		char inputTemp;
		wcout << endl << L"\x1b[38;5;244m EnterŰ�� ���� �ʱ�ȭ\x1b[38;5;0m";
		while (true) {
			inputTemp = _getch();
			if (inputTemp == 13) break;
		}
		
		#if _WIN32
			system("cls");
		#else
			system("clear");
		#endif
	}
}