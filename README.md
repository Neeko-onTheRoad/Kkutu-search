# Kkutu-search
심심해서 만든 끄투? 검색 앤진 입니다.  
물론 데이터는 수작업닙니다.

<br>

## 사용법
1. 초록색 <>Code버튼 -> Download ZIP 을 눌러 다운로드 합니다
1. 다운로드 받은 파일의 압축을 풉니다
2. 파일 안에 있는 "KKuTu search"를 실행합니다

## 단어목록 수정
1. x64 -> Debug 폴더에 에 들어갑니다
2. file.config에 KKuTuSet파일 이름을 입력 합니다 (기본 : MAIN.KKuTuSet)
3. file.config에 적은 이름과 같은 KKuTuSet 파일을 만듭니다 (형식 : 단어 구별은 줄바꿈 파일 마지막에 &EOF 그 아래는 모두 주석)

<br>

## 텍스트가 깨져요!
다음과 같이 터미널에서 글자가 깨져서 보일 시,  
  
![image](https://github.com/Neeko-onTheRoad/Kkutu-search/assets/61304515/9537f24e-de21-44b9-a82c-f9b8ce3e8202)  
  
cmd에 다음 명령어를 적은 후 실행 해 주세요  
`reg add HKEY_CURRENT_USER\Console -v VirtualTerminalLevel -t REG_DWORD -d 1 -f`

<br>

## 변경

`v0.1  : 없어`  
`v0.11 : 글자 길이순 정렬로 변경`
