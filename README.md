# C++로 작성된 간단한 JavaScript 인터프리터

## 프로젝트 개요

이 프로젝트는 C++로 구현된 JavaScript의 하위 집합에 대한 간단한 인터프리터입니다. 이 인터프리터는 기본적인 산술 연산, 변수 선언, 객체 리터럴 및 `console.log` 기능을 지원합니다.

## 기능

- `const`를 사용한 변수 선언
- 기본 산술 연산 (`+`, `-`, `*`, `/`)
- 정적 키-값 쌍을 가진 객체 리터럴
- `console.log`를 통한 기본 로깅

## 시작하기

### 사전 준비

- C++ 컴파일러 (예: g++, clang++)
- C++11 이상과 호환되는 표준 라이브러리가 시스템에 설정되어 있어야 합니다.

### 설치

1. 저장소를 클론합니다:

   ```bash
   git clone https://github.com/Triple-Trouble-Devs/simple-js-interpreter.git
   cd simple-js-interpreter
   ```

2. 소스 코드를 컴파일합니다:
   ```bash
   g++ -o js_interpreter main.cpp -std=c++11
   ```

## 사용법

JavaScript 코드를 입력으로 받아 인터프리터를 실행합니다:

```bash
./js_interpreter
```

다음과 같은 JavaScript 코드를 입력하세요:

```javascript
const a = 10;
const b = { a, c: 20 };
console.log(a + b.c);
```

예상 출력:

```
30
```

## 코드 구조

- **Lexer**: 입력 문자열을 식별자, 숫자, 연산자 등 의미 있는 단위(토큰)로 분리합니다.
- **Parser**: 이러한 토큰을 해석하여 코드의 구문 구조를 형성하고, 선언과 표현식을 이해합니다.
- **Evaluator**: 구문 구조를 평가하여 코드를 실행하고 `console.log`를 사용하여 결과를 출력합니다.
