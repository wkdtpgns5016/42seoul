# **libft**

## **libft 소개**
> 앞으로 과제에서 사용하게 될 함수들을 만들어 라이브러리로 만드는 과제

## **libft 아카이브 파일 생성**

~~~
make all    # 일반적인 libft 라이브러리
make bonus  # list 함수가 포함된 라이브러리
~~~

## **libft 라이브러리 구성 함수**
- ft_atoi : 문자열을 숫자로 변환 하는 함수
- ft_bzero : 메모리 주소에 0으로 초기화 하는 함수
- ft_calloc : 사이즈 만큼 메모리 할당하는 함수
- ft_isalnum : 알파벳이거나 숫자인지 검사하는 함수
- ft_isalpha : 알파벳인지 검사하는 함수
- ft_isascii : 아스키 코드 범위를 검사하는 함수
- ft_isdigit : 숫자인지 검사하는 함수
- ft_isprint : 아스키 코드 문자가 printable한지 검사하는 함수
- ft_itoa : 숫자를 문자열로 변환 하는 함수
- ft_memchr : 메모리 주소에서 특정 문자 찾는 함수
- ft_memcmp : 메모리 주소 비교 함수
- ft_memcpy : 메모리 복사 함수
- ft_memmove : 메모리 복사 함수 (오버랩 방지)
- ft_memset : 메모리 주소 초기화 함수
- ft_putchar_fd : 문자 출력 함수
- ft_putendl_fd : 문자열 출력 함수 (줄바꿈)
- ft_putnbr_fd : 숫자 출력 함수
- ft_putstr_fd : 문자열 출력 함수
- ft_split : 문자열을 특정 문자로 쪼개는 함수
- ft_strchr : 문자열에서 특정 문자 찾는 함수
- ft_strdup : 문자열 복사 함수
- ft_striteri : 문자열 반복 적용 함수
- ft_strjoin : 문자열 합치는 함수
- ft_strlcat : 문자열을 뒤에 붙이는 함수
- ft_strlcpy : 문자열 복사 함수
- ft_strlen : 문자열 길이 반환 함수
- ft_strmapi : 문자열 반복 적용 함수
- ft_strncmp : 문자열 비교 함수
- ft_strnstr : 문자열 찾는 함수
- ft_strrchr : 뒤에서 부터 문자 찾는 함수
- ft_strtrim : trim 간격으로 이동 함수
- ft_substr : 문자열 자르는 함수
- ft_tolower : 소문자 변환 함수
- ft_toupper : 대문자 변환 함수
- ft_lstadd_back : 노드 맨끝에 삽입하는 함수
- ft_lstadd_front : 노드 맨처음에 삽입하는 함수
- ft_lstclear : 리스트 초기화 함수
- ft_lstdelone : 노드 삭제 함수
- ft_lstiter : 리스트 반복 함수
- ft_lstlast : 노드 맨끝을 반환하는 함수
- ft_lstmap : 리스트 반복 함수
- ft_lstnew : 리스트 생성 함수
- ft_lstsize : 리스트 사이즈 반환하는 함수