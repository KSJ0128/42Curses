# ft_printf

## int	ft_printf(const char *str, ...)
### 고정 인자


### 가변 인자란?
일반적인 인자의 경우, 함수 선언시 인자의 타입, 이름, 개수를 명시해줘야 한다.
가변 인자의 경우, ... 을 통해 불러들일 인자의 타입, 이름, 개수를 명시하지 않아도 인자를 받아올 수 있다.

#include <stdarg.h>
va_list, va_start, va_copy, va_arg, va_end를 활용해서 !

```C
// 가변 인자 예시 코드

int vout(int max, ...)
{
   va_list arg_ptr;
   va_list args_copy;
   int args;
   char *day;
   va_start(arg_ptr, max);
   va_copy(args_copy, arg_ptr);
   args = 0;
   while(args < max)
   {
      day = va_arg(arg_ptr, char *);
      printf("Day: %s\n", day);
      args++;
   }
   va_end(arg_ptr);

   args = 0;
   while(args < max)
   {
      day = va_arg(args_copy, char *);
      printf("Day: %s\n", day);
      args++;
   }
   va_end(args_copy);
}
```

- ### va_list

- ### va_start

- ### va_copy

- ### va_arg

- ### va_end


가변 인자
1. 최소 한 개 이상의 가변 인자가 필요하다.
2. va_start와 va_end의 짝을 맞춰주는 것이 좋다.
