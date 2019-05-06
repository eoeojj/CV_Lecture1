# 1.시작하기

## 1.1버전관리

파일을 저장하는 순서에 따라 기록했다가 나중에 어느 지정순서의 버전을 다시 꺼내 올 수 있는 시스템이다.

Git은 파일의 공유 다른사람이 전 버전으로 만든 파일을 지금 내가 최신 버전이라도 깃허브에 저장되어 있으면 전 버전으로 실행이 가능하다. 어느컴퓨터에서나 실행이 가능.

### 로컬버전관리

내 컴퓨터에 디렉토리(폴더)를 만들어 파일을 복사하는방식이다. 저장하는 순서에따라 시간을 써놓기도 한다. 서버가 따로 없이 아주 간단한 데이터베이스로 파일변경 정보를 관리한다. 

단점 : 컴퓨터가 다운되면 폴더에 있는 파일이 다 날라 갈 수 있다. 또한 작업하던 폴더를 실수로 삭제했을 때가 생길 수고 있다. 

### 중앙집중식 버전관리(CVCS)

다른 사람과 함께 작업해야 할 때를 위한 시스템이다. 파일을 관리하는 서버가 따로 있고 클라이언트(중앙관리자)가 중앙 서버에서 파일을 받아서 사용(checkout)한다. 예를 들어 사람들에게 중앙 서버에 파일을 배정해줘서 사람들이 가져가면 된다. 사람들이 중간중간 저장하면 중앙서버에서 사람들이 어느정도 일을 했는지 확인이 가능하다. 즉 관리자는 관리가 쉬워진다.

단점 : 중앙서버가 다운되면 그동안 아무도 파일을 중앙서버에서 가져오지 못하고 파일을 저장 할 수도 없다. 중앙서버의 하드디스크가 문제가 생기면 사람이 ''중앙서버에서 파일을 가져왔을 때''의 파일(스냅샷)은 유지가 가능하나 나머지 저장된 파일은 복구할 수 없다.

### 분산버전관리시스템(DVCS)

Git이 쓰는 시스템이다. 단순히 파일의 마지막 스냅샷을 체크아웃하지 않고 저장소 전체를 복제한다. 서버에 문제가 생겨도 저장소를 다운받았던 사람이 한 명이라도 있으면 그 사람의 저장소를 복제(clone)하면 복구가 가능하다.리모트 저장소(백업장소)를 만들어 놓을 수 있다.

단점 : 모든 저장소가 저장되어서 데이터를 많이 잡아먹는다.

## 1.2 Git의 목표

빠른 속도 

단순한구조

비선형적인 개발(수천 개의 동시다발적인 브랜치) : 여러목표, 다양한 사람들이 같은 시간에

완벽한 분산

속도나 데이터 크기가 대형프로젝트를 진행하기 유용하다

## 1.3 Git 기초

### 차이가 아닌 스냅샷

Git이 아닌 다른 시스템은 각 파일의 변화를 시간순으로 관리하면서 파일들의 ''집합''으로 관리하지만 Git은 파일 자체의 스냅샷을 저장해서 크기가 작다. 이는 파일 자체의 히스토리(시간순의 변화)를 서버에 저장하는 것이다. 또한 파일을 새로 저장하지 않고 링크를 저장하여 스냅샷 스트림(파일 저장 순간을 기록)처럼 취급한다. 그래서 버전을 새로 찾을 필요가 없다.

### 거의 모든 명령을 로컬에서 실행

중앙서버에 접속을 안해도 된다. Git은 히스토리를 조회할 때 서버가 필요 없다. 그래서 네트워크에 접속하고 있지 않아도 커밋(업로드가 준비됨)할 수 있다. 즉 디렉토리 데이터베이스에 네트워크 없이 접근가능하다는 것이다.

### Git의 무결성

체크섬 : 파일에 접근해서 파일을 수정할 때 그 파일의 관리자에게 동의를 구하는 것. 40자 길이의 16진수

Git은 체크섬이 없으면 파일을 변경할 수 없다. Git은 파일을 이름이 아닌 해시로 저장하기 때문에 같은 이름의 파일을 만들어도 덮어쓰기가 되지 않는다. 

### Git은 데이터를 추가할 뿐

Git은 커밋하기 전에 단계로 되돌릴 수 없다. 그리고 커밋을 했을 때에 삭제가 불가능 하다. 

### 세 가지 상태

Git에는 세 가지 상태가 있다. commited, Modified, staged. 

committed : 데이터가 로컬디바이스에 저장됨 - 수정불가

modified : 수정파일을 아직 데이터베이스에 커밋하기 전 - 수정가능

staged : 수정파일을 곧 커밋할 것이라 표시 - 수정가능

이 세가지 상태는 세가지 단계와 관련이 있다. Git디렉터리 , 워킹 디렉터리, Staging area

Git 디렉터리 : 다른 컴퓨터에 있는 저장소를 로컬 디렉토리로 클론할 때 만들어진다. 이 곳에 있는 파일은 committed 상태이다

워킹 디렉터리 : 현재 가져온 파일을 수정하는 단계에서 있는 장소이다. 

staging area : 커밋할 스냅샷을 만든다. 커밋할 준비를 하는 것 이다. 이 곳에서 커밋을 하면 Git디렉터리에 영구적으로 저장 할 수 있다.

## 1.4 CLI

Git을 사용하는 방법으로 Command Line Interface 터미널창을 이용하는 것이다.

## 1.5 Git 최초설정

### 사용자정보설정

$ git config --global user.name "eoeojj" : github의 이름

$ git config --global user.email ehroql921@naver.com : github에 가입한 이메일

다른 이름이나 이메일로 변경하고 싶을 때에는 --global을 빼고 명령어를 쓰면 된다.

### 편집기설정

$ git config --global core.editor emacs

텍스트 편집기를 설정한다. 기본은 Vi나 Vim을 사용하지만 emacs같은 다른 편집기를 사용할 수도 있다. 

### 설정 확인

 $ git config --list 

현재 설정한 것들을 보여준다.

## 1.6 도움말 보기

$ git help<verb>

$ git <verb> --help

$ man git -<verb>

<verb>는 자신이 궁금한 것을 쓰는 곳이다. 예를들어 config의 도움말을 보고싳으면 config를 <verb>위치에 쓴다.

# 2 Git의 기초

## 2.1 Git의 저장소 만들기

기존 프로젝트나 디렉터리로 만드는 방법이 있고 다른 저장소에서 클론해 오는 방법이 있다.

$ git init  : 기존의 프로젝트로 Git 저장소 만들기

$ git clone <주소> :  
