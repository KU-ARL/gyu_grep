 # GYU_GREP
 
 ## How to Use 
 ```bash
 ./gyu_grep [-option] <"pattern"> <file or directory>
 ```

 ## Options (Available Now)
```bash
-n : show line num
-i : neglect about capital
```

 ## Options (To be Update)
```bash
-r : 디렉토리 내 모든 파일 검색
-v : 일치하지 않는 line 검색 (반전 검색)
-c : 발견 line 개수만 출력
-l : 발견한 파일 이름만 출력
-w : 단어 단위로 검색
```

## 프로그램 구조

### Layer1. File Collector

### Layer2. Line Processor

### Layer3. File Processor