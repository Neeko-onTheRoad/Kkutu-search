# Kkutu-search
심심해서 만든 끄투? 검색 앤진 입니다.  
물론 데이터는 수작업닙니다.

<br>

## 사용법
1. 다음 파일을 다운 받습니다  
[KKuTu search.zip](https://github.com/Neeko-onTheRoad/Kkutu-search/files/12259552/KKuTu.search.zip)
2. 다운 받을때 "일반적이지 않을 파일"등으로 다운로드가 안되면 "계속 다운로드"를 누른다
4. 압축을 풀고 file.config에 KKuTuSet파일 이름을 입력 합니다 (기본 : chemistry.KKuTuSet)
5. file.config에 적은 이름과 같은 KKuTuSet 파일을 만듭니다 (형식 : 단어 구별은 줄바꿈 파일 마지막에 &EOF)
6. KKuTu search.exe를 실행합니다
7. Windows의 PC보호가 뜨면 "추가 정보"를 누르고 "실행"누르기  
(디지털 인증서가 비싸서 못해놔써용)


<br>

## 텍트스가 깨져요!
다음과 같이 터미널에서 글자가 깨져서 보일 시,  
  
![image](https://github.com/Neeko-onTheRoad/Kkutu-search/assets/61304515/9537f24e-de21-44b9-a82c-f9b8ce3e8202)  
  
cmd에 다음 명령어를 적은 후 실행 해 주세요  
`reg add HKEY_CURRENT_USER\Console -v VirtualTerminalLevel -t REG_DWORD -d 1 -f`

<br>

## 변경
v0.1  : 없어
v0.11 : 글자 길이순 정렬로 변경
