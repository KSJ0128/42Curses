# Born2beroot : 나만의 서버 구축하기

## 그룹 & 유저
* 그룹 리스트 확인하기

  ```shell
  cat /etc/group
  ```
<br>

* 그룹 생성하기

  ```shell
  groupadd [그룹명]
  ```
<br>

* 그룹 삭제하기
   ```shell
  groupdel [그룹명]
  ```
<br>   

* 유저 생성하기
  ```shell
  adduser [유저명]
  # 유저 생성 후 패스워드를 지정하도록 유도한다.
  ```
<br>  

* 유저 삭제하기
  ```shell
  userdel -rf [유저명]
  # r : 유저의 홈 디렉토리와 내부의 모든 파일, 서브 디렉토리를 삭제
  # f : 강제 삭제. 어떤 이유로 삭제가 불가능한 경우에도 강제로 유저를 삭제
  ```
<br>  

* 유저가 속한 그룹 확인하기
  ```shell
  groups [유저명]
  ```
<br>  

* 유저를 특정 그룹에 추가하기
  ```shell
  usermod -aG [그룹명] [유저명]
  # a : append. 기존 그룹 멤버십에 영향을 주지 않고 새로운 그룹 멤버십을 추가.
  # G : 사용자가 추가될 그룹 목록. 여러 그룹을 추가할 땐 쉼표로 구분한다.
  # root 권한 또는 sudo를 통해 명령어를 실행할 수 있다.
  ```
<br>

**Tip) hostname 변경하기**

```shell
hostnamectl set-hostname [호스트명]
```
<br>

## sudo : superuser do

### sudo란?
sudo는 리눅스 시스템에서 유저가 다른 유저의 권한으로 명령어를 실행할 수 있게 하는 명령어다.

일반적으로는 root 권한을 필요로 할 때 사용한다.<br>

<br>

### 사용해야 하는 이유
- 일반 유저가 root 권한을 부여 받아 명령 수행이 가능하다.
- 지속적으로 root 권한을 부여하는 것에 비해 보안성이 강화된다.
<br>

**Tip) root 계정에 임시 로그인하기**

su -, su -l

<br>

### sudo 설정
/etc/sudoers 설정 파일을 통해 관련 설정을 할 수 있다.

해당 파일은 visudo 명령어를 통해 편집하는 것이 좋다.

- 동시에 여러 유저가 sudoers 파일을 편집하는 것을 방지한다.
- sudoers 파일 내 구문 오류를 실시간으로 체크. 잘못된 명령어로 인해 심각한 문제가 초래되는 것을 방지한다.
- 이전 파일의 백업을 자동으로 생성. 수정 후에도 이전 버전으로 돌아갈 수 있다.

<br>

### sudoers 파일
```shell
passwd_tries
# sudo 인증 시 비밀번호가 입력 시도 횟수 설정

badpass_message
# sudo 권한 사용 중 비밀번호가 틀렸을 때 나오는 오류 메세지 설정

log_input
log_output
# sudo 권한을 이용하여 수행한 명령어의 입출력을 모두 기록

iolog_dir
# 위 log가 기록될 위치 설정

requiretty
# TTY모드에서만 실행될 수 있도록 설정

secure_path
# sudo 사용해 명령어 실행시의 환경 변수인 'PATH' 지정. 시스템에서 실행 가능한 프로그램 찾을 때 사용되는 경로
# sudo 사용시 사용 가능한 명령어의 경로를 제한해 보안 취약점 방지.
# ex) "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
# 명시적으로 /usr/local/sbin, /usr/local/bin, /usr/sbin, /usr/bin, /sbin, /bin으로 제한
```

<br>

**Tip) TTY 모드**

터미널에 로그인한 상태에서만 명령어 실행이 가능하도록 하는 모드.

<br>

## Password
해당 과제에서는 패스워드 사용 기간, 패스워드 복잡도에 대한 패스워드 정책 설정을 요구한다.

<br>

### 패스워드 사용 기간

**/etc/login.defs** 파일을 수정해 패스워드 사용 기간을 설정할 수 있다.
단, 해당 파일을 수정한 이후의 패스워드 정책에만 적용되므로 현재 정책에도 기간을 적용하고 싶다면 후술할 방법을 적용해야 한다.

- **PASS_MAX_DAYS** : 패스워드를 사용할 수 있는 최대 일 수
- **PASS_MIN_DAYS** : 패스워드 갱신이 가능한 최소 일 수
- **PASS_WARN_AGE** : 패스워드 만료를 경고할 잔여일 수

<br>

#### 현재 패스워드 정책
**chage**

기본 패스워드 항목을 지정하는 명령어로 root 권한으로 실행 가능하다.

- chage -l [유저명] : 유저의 현재 패스워드 정책 확인한다.
  <br>

- chage -m [일 수] [유저명] : 비밀번호 변경 간격 최소 일 수를 설정한다.
  <br>

- chage -M [일 수] [유저명] : 암호가 유효한 최대 일 수를 설정한다.
  <br>
  
- chage -W [일 수] [유저명] : 암호 변경이 필요하기 전의 경고 일 수를 설정한다.
  <br>
  
- chage -E [일 수] [유저명] : 유저 계정이 만료되는 날짜를 설정한다. -1을 EXPER_DATE로 전달하면 계정 만료 날짜가 제거

<br>

### 패스워드 복잡도

**/etc/pam.d/common-password** 파일을 수정해 패스워드 복잡도를 설정할 수 있다.

```shell
retry
# 패스워드 입력 시도 가능 횟수

minlen
# 패스워드의 최소 길이

ucredit
# 패스워드에 포함되어야 할 대문자의 개수.

lcredit
# 패스워드에 포함되어야 할 소문자의 개수

dcredit
# 패스워드에 포함되어야 할 숫자의 개수

# credit에서 N의 양수, 음수의 차이
# >= 0 : 조사 필요. 
# < 0 : 패스워드에 최소로 존재해야 하는 개수

difok
# 기존 패스워드와의 일치 개수 or 비율

maxrepeat
# 패스워드 내에 반복 가능한 글자 개수 

reject_username
# 패스워드에 username이 그대로 혹은 거꾸로도 포함되지 않게

enforce_for_root
# root 계정에도 해당 규칙 적용. root 계정은 이전 비밀번호를 기억하지 않기에 difok는 자동적으로 적용되지 않음
```

<br>

**passwd -e [유저명]**

패스워드를 강제로 만료시켜 현재 계정의 다음 로그인시 패스워드를 변경하도록 한다.
- 패스워드가 만료되어 root 계정 변경시에도 기존 패스워드를 물어 difok가 적용된다.
- root 계정이 아닌 계정에서 실행시 최소 변경일자에 걸린다면 반영되지 않는다. sudo 사용시엔 반영됨.

<br>

## SSH(Secure Shell)

### SSH란?
SSH는 네트워크 프로토콜 중 하나로 원격 접속, 컴퓨터 간 데이터 전송을 위해 사용된다.

기본 포트로 22번 포트를 사용한다. 

<br>

*인터넷 프로토콜(IP): **데이터 패킷**이 네트워크를 통해 이동하고 올바른 대상에 도착할 수 있도록 데이터 패킷을 라우팅하고 주소를 지정하기 위한 프로토콜 집합

**프로토콜 : 둘 이상의 장치에서 서로 통신하고 이해할 수 있도록 특정 작업을 수행하고 데이터 형식을 지정하는 표준화된 방법

***네트워크를 통한 데이터 전달시 데이터는 ‘패킷’이라고 하는 더 작은 조각으로 나뉨 

<br>

#### SSH가 보안이 좋은 이유
SSH는 서버 접속시 패스워드 대신 key를 제출하는 방식을 사용한다.

키 생성시 **공개키(Public Key)와 비공개키(Private Key)**가 생성된다.

SSH 접속 시도시 SSH Client가 로컬 머신의 비공개키와 원격 머신의 공개키를 비교해 둘이 일치하는지 확인한다.

- 공개키(Public key): 원격 머신, SSH 서버가 설치된 컴퓨터, 게스트
- 비공개키(Private key): 로컬 머신, 호스트

<br>

통신시 메시지를 전송하기 전 public key를 통해 암호화, private key를 통해 복호화를 진행한다.

SSH는 암호화되었기 때문에 통신이 노출되어도 암호화된 문자로 보인다.

<br>

### SSH 설정
SSH를 사용하기 위해서 **openssh-server 라이브러리**가 필요하다.

<br>

```shell
systemctl status ssh
# ssh 실행 여부, 포트 확인
# active(running) 상태여야 SSH가 실행 중인 상태

systemctl start ssh
# SSH가 실행 중인 상태가 아닌 경우 SSH를 실행한다.

systemctl stop ssh
# SSH 사용 후 프로세스 종료
```

<br>

SSH는 **ssh_config, sshd_config** 두 개의 설정 파일이 존재한다.

- ssh_config : outbound. 나가는 요청에 대한 설정 파일.
- sshd_config : inbound. 들어오는 요청에 대한 설정 파일.

<br>

```shell
vi /etc/ssh/sshd_config
# Port 4242 : 4242 포트에서 SSH 서비스가 작동하게 설정한다.
# PermitRootLogin no : SSH를 통해 root로 로그인 할 수 없게 설정한다.
```

해당 과제는 들어오는 요청에 대한 설정만을 요구하기 때문에 sshd_config 파일만 수정해준다.

**SSHD : SSH Daemon. SSH 연결을 받아주기 위해 대기하는 프로세스.

<br>

```shell
systemctl restart ssh
# 위 sshd_config 파일 수정 후 SSH를 재시작해야 적용된다.

systemctl enable ssh / disable ssh
# 시스템 부팅시 SSH 서비스 활성화 / 비활성화
```

<br>

### 포트 포워딩
host IP, guest IP를 확인한다.
- host : SSH에 접속하려는 컴퓨터. 로컬 머신.
  - ifconfig | grep inet
- guest : SSH 서버를 열어둔 컴퓨터. 가상 머신.
    - hostname -I

<br>

```shell
ssh [사용자 이름]@[host IP] -p [host Port]
```



























  
