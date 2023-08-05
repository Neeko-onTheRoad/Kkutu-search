#include <vector>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <algorithm>
using namespace std;

int main(void) {
	SetConsoleTitle(TEXT("KKuTu search"));

	wcout.imbue(locale("kor"));
	wcin.imbue (locale("kor"));
	wstring         strBuffer;
	wifstream       fileTemp(L"file.config");
	vector<wstring> fileName;

	fileTemp.imbue(locale(".UTF-8"));
	while (strBuffer != L"&EOF") {
		fileTemp >> strBuffer;
		fileName.push_back(strBuffer);
	}
	if (fileName.size() != 0) fileName.pop_back();

	if (!fileTemp) {
		wcout << L"file.config파일이 없습니다!" << endl;
		wcout << L"file.config파일을 다시 생성하여 안에 KKuTuSet파일을 적어주세요" << endl << endl;

		system("pause");
		exit(EXIT_FAILURE);
	}

	wifstream       file;
	vector<wstring> latters;
	wstring         userInput;
	bool            isExist;
	bool            fileNotExist = false;

	for (auto i : fileName) {
		try {
			file.open(i);

			if (!file) throw false;
			else throw true;
		}
		catch (bool j) {
			if (!j) {
				wcout << L"파일 \"" << i << L"\"(을)를 찾을 수 없습니다!" << endl;
				wcout << L"\"file.config\" 파일에 있는 파일 명이 정확 한지 확인해 주세요!" << endl << endl;

				fileNotExist = true;
			}
			else {
				file.imbue(locale(".UTF-8"));
				strBuffer = wstring();
				while (strBuffer != L"&EOF") {
					file >> strBuffer;
					latters.push_back(strBuffer);
				}
				if(latters.size() != 0) latters.pop_back();
				file.close();
			}
		}
	}

	if (fileNotExist) {
		system("pause");
		exit(EXIT_FAILURE);
	}
	sort(latters.begin(), latters.end());
	latters.erase(unique(latters.begin(), latters.end()), latters.end());

	sort(latters.begin(), latters.end(), 
		[](wstring a, wstring b) { return a.size() > b.size(); }
	);

	while (true) {
		wcout << L"\x1b[38;5;3m개쩌는 끄투 검색 엔진 v0.11" << endl;
		wcout << L"\x1b[38;5;255m첫 글자 입력 \x1b[38;5;244m> \x1b[38;5;111m";
		userInput = wstring();
		wcin >> userInput;

		wcout << endl;
		isExist = false;

		wcout << L"\x1b[38;5;46m'" << userInput[0] << L"'\x1b[38;5;255m 로 시작하는 단어 : " << endl;
		wcout << L"\x1b[38;5;111m";


		for (int i = 0; i < latters.size(); i++) {
			if (latters[i][0] == userInput[0]) {
				wcout << "  - " << latters[i] << endl;
				isExist = true;
			}
		}

		if (!isExist) wcout << L"없습니다!" << endl;

		char inputTemp;
		wcout << endl << L"\x1b[38;5;244m Enter키를 눌러 초기화\x1b[38;5;0m";
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