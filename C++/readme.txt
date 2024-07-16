PS(C++) 템플릿 자동화 사용법

References : https://notej.tistory.com/entry/OSX-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%ED%85%9C%ED%94%8C%EB%A6%BF-%EC%BD%94%EB%93%9C-%EC%9E%90%EB%8F%99%ED%99%94

1. ~ 디렉토리에서 ls -a로 .zshrc 존재여부 확인, 없으면 (sudo) vi .zshrc로 생성

2. .zshrc에 스크립트 추가

ctmake() { cat 절대경로/C++template.cpp > "$1.cpp" }

3. 터미널에서 source ~/.zshrc 입력하여 적용

4. ctmake filename(ex. BOJ_1234)으로 자동생성 정상작동 확인