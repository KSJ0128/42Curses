# **Get Next Line**

##### Reading a line on a fd is way too tedious

fd에서 한 줄을 읽는다는 것은 너무나도 지루한 일입니다.

##### _Summary: The aim of this project is to make you code a function that returns a line, read from a file descriptor._

_요약: 이 프로젝트의 목적은 파일 디스크립터로부터 읽혀진, 개행으로 끝나는 한 줄을 반환하는 함수를 코드화 하는 것입니다._

<br>

# Contents

| Chapter | Contents                                         | page |
| :-----: | :----------------------------------------------- | :--: |
|    1    | [**Goals**](#Chapter-1)                          |  2   |
|    2    | [**Common Instrunctions**](#Chapter-2)           |  3   |
|    3    | [**Mandatory part - Get_next_line**](#Chapter-3) |  4   |
|    4    | [**Bonus part**](#Chapter-4)                     |  6   |

<br>

# **Chapter 1**

## Goals

<br>

##### _This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: static variables._

이 프로젝트는 당신의 콜렉션(아마 라이브러리)에 아주 편리한 함수를 추가하게 할 뿐만 아니라, C 프로그래밍에 있어서 아주 흥미롭고 새로운 개념인 '정적 변수'를 배울 수 있도록 도울 것입니다.

<br>

# **Chapter 2**

## Common Instructions

<br>

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside._

  프로젝트는 Norm 규칙에 맞춰 작성되어야 합니다. 보너스 파일/함수가 존재할 경우, 그 또한 norm 검사에 포함되며 norm error가 있을 시 0점을 받게 됩니다.

- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._

  정의되지 않은 동작을 제외하고, 여러분이 작성하신 프로그램이 예기치 않게 중단되어서는 안 됩니다. (예를 들어, segmentation fault, bus error, double free 등) 만약 여러분의 프로그램이 예기치 않게 종료된다면, 제대로 작동하지 않은 것으로 간주되어 평가에서 0점을 받게 됩니다.

- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._

  필요한 경우 heap에 할당된 모든 메모리 공간은 적절하게 해제되어야 합니다. 메모리 누수는 용납될 수 없습니다.

- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink._

  과제에서 필요한 경우, **-Wall -Wextra -Werror** 플래그를 지정하여 컴파일을 수행하는 **Makefile**을 제출해야 합니다. Makefile은 relink 되어서는 안 됩니다.

- ##### _Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re._

  **Makefile**은 최소한 **$(NAME), all, clean, fclean, re** 규칙을 포함해야 합니다.

- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h}. Mandatory and bonus part evaluation is done separately._

  프로젝트에 보너스를 제출하려면, Makefile에 **보너스 규칙**을 포함해야 합니다. 이 보너스 규칙은 프로젝트의 메인 파트에서 금지되었던 모든 다양한 헤더, 라이브러리, 또는 함수들을 추가하여야 합니다. 보너스 과제는 반드시 \_**bonus**.{c/h}라는 별도의 파일에 있어야 합니다. 반드시 수행하여야 하는 메인 파트의 평가와 보너스 파트의 평가는 별도로 이뤄집니다.

- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._

  만일 프로젝트에서 여러분의 libft 사용을 허용한다면, 소스들과 관련 Makefile을 함께 루트 폴더 안에 있는 libft 폴더에 복사해야 합니다. 프로젝트의 Makefile은 우선 libft의 Makefile을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.

- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._

  **이 과제물을 제출할 필요가 없고, 채점 받을 필요가 없을지라도,** 저희는 여러분들이 프로젝트를 위한 테스트 프로그램을 만들 것을 권장합니다. 이것은 여러분의 과제물과 동료들의 과제물을 쉽게 테스트할 수 있게 도울 것입니다. 또한, 평가를 진행할 때 이러한 테스트 프로그램들이 특히 유용하다는 사실을 알게 될 것입니다. 평가 시에는 여러분의 테스트 프로그램과 평가 받는 동료의 테스트 프로그램들을 당연히 자유롭게 사용할 수 있습니다.

- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._
  할당된 git 저장소에 과제물을 제출하세요. 오직 git 저장소에 있는 과제물만 등급이 매겨질 것입니다. Deepthought가 평가하는 과제의 경우엔, 동료평가 이후에 Deepthought가 수행됩니다. 만약 Deepthought 평가 중에 오류가 발생한다면, 그 즉시 평가는 중지될 것입니다.

<br>

# Chapter 3

## Mandatory part - Get_next_line

<br>

| **함수 이름**                | get_next_line                                                                     |
| ---------------------------- | --------------------------------------------------------------------------------- |
| **프로토타입**               | char \*get_next_line(int fd);                                                     |
| **제출할 파일**              | get_next_line.c, get_next_line_utils.c, get_next_line.h                           |
| **매개변수**                 | 읽어들일 파일의 디스크립터 (서술자)                                               |
| **반환값**                   | 읽혀진 라인 : 한 줄이 제대로 읽힘 <br> NULL : 읽을 라인이 더이상 없거나 에러 발생 |
| **사용가능한 <br>외부 함수** | `read, malloc, free`                                                              |
| **설명**                     | 파일 디스크립터로부터 한 줄을 읽고, <br>반환하는 함수를 작성하시오.               |

<br>

- ##### _Repeated calls (e.g., using a loop) to your `get_next_line()` function should let you read the text file pointed to by the file descriptor, **one line at a time**._

  `get_next_line()`을 (반복문 등을 통해) 여러 번 호출할  때마다, 함수는 **한 번에 한 줄씩** 파일 디스크립터가 가리키는 텍스트 파일을 읽을 수 있어야 합니다.

- ##### _Your function should return the line that has just been read. If there is nothing else to read or if an error has occurred it should return NULL._

  여러분의 함수는 방금 읽어들인 문자열 한 줄을 반환하여야 합니다. 더이상 읽어올 것이 없거나 에러가 발생하면 NULL을 반환하여야 합니다.

- ##### _Make sure that your function works as expected both when reading from a file and when reading from the standard input._

  파일에서 읽을 때, 표준입력으로부터 읽어들일 때 모두 함수가 예상대로 동작하는지 확인하십시오.

- ##### _**Please note** that the returned line should include the terminating `\n` character, expect if the end of file was reached and does not end with a `\n` character._

  **중요**: 파일에 끝까지 도달하였고 `\n`이 존재하지 않을때를 제외하고, 반환하는 문자열에는 `\n`이 포함되어야 합니다.

- ##### _Your header file `get_next_line.h` must at least contain the prototype of the `get_next_line()` function._

  헤더 파일인, `get_next_line.h`에는 적어도 `get_next_line()`의 프로토타입이 존재하여야 합니다.

- ##### _Add all the helper functions you need in the `get_next_line_utils.c` file._

  `get_next_line_utils.c` 파일에 필요한 모든 헬퍼 함수들을 추가하세요.

> ℹ️ <br>
>
> ##### _A good start would be to know what a [static variable](https://en.wikipedia.org/wiki/Static_variable) is._
>
> [정적 변수](https://en.wikipedia.org/wiki/Static_variable)가 무엇인지 익혀 두면 좋은 시작이 될 겁니다 . <br> 

- ##### _Because you will have to read files in `get_next_line()`, add this option to your compiler call: `-D BUFFER_SIZE=n`<br/>It will define the buffer size for `read()`.<br/>The buffer size value will be modified by your peer-evalutors and the Moulinette in order to test your code._

  `get_next_line()` 내에서 파일을 읽어들여야 하므로, 컴파일러 호출에 `-D BUFFER_SIZE=n` 옵션을 추가하세요.<br/>이것은 `read()`의 buffer size를 지정합니다.<br/>평가자와 Moulinette는 코드를 채점할 때 buffer size를 변경할 것입니다.
  
 > ⚠️ <br>
 > 
 > ##### _We must be able to compile this project with and without the `-D BUFFER_SIZE` flag in addition to the usual flags. You can choose the default value of your choice._
 > 
 > `-D BUFFER_SIZE`플래그가 없어도 프로젝트가 컴파일이 되어야 합니다. 기본값은 마음대로 정하셔도 됩니다.

- ##### _You will compile your code as follows (a buffer size of 42 is used as an example): `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`_

  컴파일은 이런 식으로 진행합니다 (buffer size=42는 예시입니다): `cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`

- ##### _We consider that `get_next_line()` has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas `read()` didn't reach the end of file._

  마지막 호출 이후 `read()`가 파일의 끝에 도달하지 못해 파일 디스크립터가 가리키는 파일이 변경되었으면, `get_next_line()`이 정의되지 않은 동작을 가진다고 간주합니다.
  
- ##### _We consider that `get_next_line()` has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to._

  `get_next_line()`은 바이너리 파일을 읽을 때 정의되지 않은 동작을 가진다고 생각하셔야 합니다. 그러나 여러분이 원한다면 이러한 동작을 논리적으로 구현하셔도 됩니다.

> :bulb:<br>
>
> ##### _Does your function still work if the BUFFER_SIZE value is 9999? And if the BUFFER_SIZE value is 1? And 10000000? Do you know why?_
>
> BUFFER_SIZE 값이 9999인 경우에도 함수는 여전히 작동하나요? BUFFER_SIZE 값이 1이라면? 10000000이라면? 왜 그런지 아시나요?

> ℹ️ <br>
>
> ##### _Try to read as little as possible each time `get_next_lne()` is called. If you encounter a new line, you have to return the current line.<br/>Don't read the whole file and then process each line._
> 
> `get_next_line()`이 호출될 때마다 가능한 적게 읽어들이도록 해야 합니다. 만약 새로운 줄을 만나면, 현재 줄을 반환해야 합니다.<br/>전체 파일을 읽어들인 다음에 한줄씩 처리하지 마세요.

### **Forbidden**
- ##### _You are not allowed to use your `libft` in this project._
  `libft`는 위 프로젝트에서 사용이 금지되어 있습니다. 
- ##### _`lseek()` is forbidden._
  `lseek()`는 금지되어 있습니다.
- ##### _Global variables are forbidden._
  전역 변수는 금지되어 있습니다.

<br>

# Chapter 4

## Bonus part

<br>

##### _The project is straightforward and doesn't allow complex bounses. However, we trust your creativity. If you completed the mandatory part, give a try to this bonus part._

이 프로젝트는 간단명료하기 때문에 복잡한 보너스를 수행하기 어렵습니다. 하지만 우리는 여러분의 상상력을 믿습니다. 만약 여러분이 필수 과제를 끝냈다면, 보너스 과제를 도전해 보세요.

  _Here are the bonus part requirements:_
  
  다음은 보너스 파트의 요구사항입니다:
  
- ##### _Develop `get_next_line()` using only one static variable._
  정적 변수를 하나만 사용하여 `get_next_line()`을 개발하세요.
- ##### _Your `get_next_line()` can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.<br/>It means that you should be able to call `get_next_line()` to read from fd 3, then fd 4, then 5, then once agin 3, once again 4, and so forth._
  당신의 `get_next_line()`이 여러 개의 파일 descriptor를 한번에 관리할수 있어야 합니다. 예를 들어, 파일 디스크립터 3, 4, 5에 접근 가능한 경우, descriptor나 다른 줄에서의 fd의 reading thread를 잃지 않은 채로 각 호출당 다른 fd를 읽을수 있어야 합니다.<br/>이는 `get_next_line()`을 호출하여 fd 3, fd 4, 다음에 5 그 다음에 다시 3, 4, 등등을 읽을 수 있어야 합니다.
##### _Append the `_bonus.[c\h]` suffix to the bonus part files.<br/>It means that, in addition to the mandatory part files, you will turn in the 3 following files:_

보너스 파일 뒤에 `_bonus.[c\h]`를 추가하세요.<br/>이는 필수 파일 외에 다음 3개의 파일을 제출한다는 것을 의미합니다:

- ##### `get_next_line_bonus.c`
- ##### `get_next_line_bonus.h`
- ##### `get_next_line_utils_bonus.c`

 > ⚠️ <br>
 > 
 > ##### _The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all._
 > 
 > 보너스는 필수로 구현해야 하는 파트가 **완벽할 때**만 평가될 것입니다. '완벽함' 이란, 모든 필수 파트가 전부 구현되어 있어야 하며 오작동하는 부분이 없어야 함을 의미합니다. 필수로 구현해야 하는 파트에서 **만점**을 받지 못한다면, 보너스 항목은 채점되지 않습니다.
 > 
