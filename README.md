# ft_printf

42 프로젝트 ft_printf 구현

## 개요

이 프로젝트는 C 표준 라이브러리의 `printf` 함수를 재구현하는 것입니다. 가변 인자 함수와 포맷 문자열 파싱을 통해 다양한 데이터 타입을 문자열로 변환하고 출력합니다.

## 사용 가능한 함수

- `write`
- `malloc`
- `free`
- `va_start`
- `va_end`
- `va_copy`
- `va_arg`

## 함수 프로토타입

```c
int ft_printf(const char *format, ...);
```

## 구현 계획

### 1. 포맷 문자열 파싱

포맷 문자열은 다음 구조를 따릅니다:
```
%[argument][flags][width][.precision][length_modifier]conversion
```

#### 1.1 Argument (% 또는 %m$)
- `%`: 기본 인자 순서 사용
- `%m$`: m번째 인자 사용 (1부터 시작)
- `%m$` 포맷 사용 시 모든 argument와 width에 대해 `%m$` 또는 `*m$` 포맷 검사 필요

#### 1.2 Flags (#0- +)
- `#`: 8진수/16진수 접두사 출력
- `0`: 0으로 패딩 (왼쪽 정렬 시 무시)
- `-`: 왼쪽 정렬
- ` `: 양수 앞에 공백
- `+`: 양수 앞에 + 기호
- 중복 없이 조합 가능

#### 1.3 Width (* 또는 *m$ 또는 숫자)
- `*`: 다음 인자를 width로 사용
- `*m$`: m번째 인자를 width로 사용
- 숫자: 직접 지정된 width
- 0으로 시작하지 않는 양의 10진수

#### 1.4 Precision (.숫자 또는 .* 또는 .*m$)
- `.숫자`: 직접 지정된 precision
- `.*`: 다음 인자를 precision으로 사용
- `.*m$`: m번째 인자를 precision으로 사용
- width보다 허용 범위가 넓음

#### 1.5 Length Modifier
- `hh`: char
- `h`: short
- `l`: long
- `ll`: long long
- `j`: intmax_t
- `z`: size_t
- `t`: ptrdiff_t

#### 1.6 Conversion
- `c`: 문자
- `s`: 문자열
- `p`: 포인터 (16진수)
- `d`, `i`: 부호 있는 10진수
- `u`: 부호 없는 10진수
- `x`: 소문자 16진수
- `X`: 대문자 16진수
- `%`: % 문자

**제약사항**: length modifier가 존재할 때 `c`, `s`, `p`는 사용 불가

### 2. 파싱 프로세스

1. `%` 문자를 발견하면 파싱 시작
2. 각 구성요소를 순서대로 파싱
3. 하나라도 조건을 만족하지 않으면 다음 `%`까지 전체를 출력
4. 올바른 포맷인 경우 인자를 처리하여 출력

### 3. 가변 인자 처리

#### 3.1 Width/Precision 처리
- `*` 사용 시: 다음 인자를 순서대로 읽음
- `*m$` 사용 시: `va_copy`를 사용하여 m번째 인자에 접근

#### 3.2 Conversion 인자 처리
- `%` 사용 시: 기본 순서로 인자 읽기
- `%m$` 사용 시: `va_copy`를 사용하여 m번째 인자에 접근

### 4. 타입 결정

length modifier와 conversion을 조합하여 출력 인자의 자료형을 결정:
- `c`: int
- `s`: char*
- `p`: void*
- `d`, `i`: int, long, long long (modifier에 따라)
- `u`: unsigned int, unsigned long, unsigned long long
- `x`, `X`: unsigned int, unsigned long, unsigned long long

### 5. 출력 처리

1. flags, width, precision 값을 이용해 출력용 문자열 생성
2. 정수: 정수 변환 함수 사용 (ft_putnbr 수정 필요)
3. 문자열: 그대로 버퍼에 추가
4. 버퍼 크기 부족 시 realloc으로 확장
5. 최종적으로 write로 한 번에 출력

## 필요한 함수들

### 메인 함수
- `ft_printf()`: 메인 함수 (가변 인자 처리, 전체 흐름 제어)

### 파싱 관련 함수
- `parse_format()`: 포맷 문자열 전체 파싱 및 처리
- `parse_argument()`: % 또는 %m$ 파싱
- `parse_flags()`: flags (#0- +) 파싱
- `parse_width()`: width (*, *m$, 숫자) 파싱
- `parse_precision()`: precision (., .숫자, .*, .*m$) 파싱
- `parse_length_modifier()`: length modifier (hh, h, l, ll, j, z, t) 파싱
- `parse_conversion()`: conversion (c, s, p, d, i, u, x, X, %) 파싱

### 가변 인자 처리 함수
- `next_arg()`: 다음 인자 읽기 (va_arg 사용)
- `nth_arg()`: n번째 인자 읽기 (va_copy 사용)
- `get_width_arg()`: width용 인자 읽기 (* 또는 *m$)
- `get_precision_arg()`: precision용 인자 읽기 (.* 또는 .*m$)

### 타입 및 검증 함수
- `get_arg_type()`: 인자의 실제 타입 결정
- `validate_format()`: 포맷 문자열 유효성 검사

### 출력 처리 함수
- `process_conversion()`: conversion별 출력 처리
- `format_string()`: 문자열 포맷팅 (width, precision 적용)
- `format_number()`: 숫자 포맷팅 (flags, width, precision 적용)
- `format_hex()`: 16진수 포맷팅
- `format_pointer()`: 포인터 포맷팅

### 버퍼 관리 함수
- `init_buffer()`: 버퍼 초기화
- `resize_buffer()`: 버퍼 크기 조정
- `add_to_buffer()`: 버퍼에 문자열 추가
- `flush_buffer()`: 버퍼 내용 출력
- `free_buffer()`: 버퍼 메모리 해제

### 유틸리티 함수
- `ft_itoa()`: 정수를 문자열로 변환
- `ft_utoa()`: 부호 없는 정수를 문자열로 변환
- `ft_xtoa()`: 정수를 16진수 문자열로 변환
- `ft_strlen()`: 문자열 길이 계산
- `ft_strcpy()`: 문자열 복사
- `ft_memset()`: 메모리 설정
- `ft_isdigit()`: 숫자 문자 검사
- `ft_atoi()`: 문자열을 정수로 변환

## 오류 처리

### 정의된 오류 상황
1. `%`와 `*`에서 자료형에 맞지 않는 인자가 들어온 경우
2. 필요한 인자 수보다 적은 수의 인자가 들어온 경우
3. `write` 함수 실패
4. `malloc`/`realloc` 함수 실패
5. NULL format 포인터 전달

### 오류 처리 방식
- 1, 2는 Undefined Behavior로 처리
- 프로그램이 자동으로 종료되도록 함
- write 실패 시: -1 반환
- malloc/realloc 실패 시: -1 반환  
- NULL format 포인터: -1 반환

## 구현 시 주의사항

1. **메모리 관리**: malloc/free를 적절히 사용하여 메모리 누수 방지
2. **va_copy 사용**: nth_arg 함수에서 va_list 복사 시 주의
3. **타입 안전성**: length modifier와 conversion 조합 검증
4. **버퍼 관리**: realloc 실패 시 적절한 처리
5. **ft_putnbr 수정**: 정수 변환 함수의 오류 수정 필요

## 테스트 케이스

구현 후 다음 케이스들을 테스트해야 합니다:
- 기본 conversion들 (c, s, p, d, i, u, x, X, %)
- flags 조합
- width와 precision
- length modifier
- argument 지정 (%m$)
- 잘못된 포맷 문자열
- 경계값 테스트 