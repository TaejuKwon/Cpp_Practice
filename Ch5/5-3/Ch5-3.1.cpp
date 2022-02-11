// C++ 스타일의 캐스팅

/*
암시적(implicit) 캐스팅의 경우 int 와 double 변수와의 덧셈을 수행할 때, int 형 변수가 자동으로 double 변수로 캐스팅 되는 것과 
같은 것을 말하고, 명시적(explicit) 캐스팅의 경우 예를 들어 void * 타입의 주소를 특정 구조체 포인터 타입의 주소로 바꾼다던지 등의 캐스팅
*/

// 명시적 캐스팅
// ptr = (Something *)other_ptr;
// int_variable = (int)float_variable;

/*

static_cast : 우리가 흔히 생각하는, 언어적 차원에서 지원하는 일반적인 타입 변환

const_cast : 객체의 상수성(const) 를 없애는 타입 변환. 쉽게 말해 const int 가 int 로 바뀐다.

dynamic_cast : 파생 클래스 사이에서의 다운 캐스팅 (→ 정확한 의미는 나중에 다시 배울 것입니다)

reinterpret_cast : 위험을 감수하고 하는 캐스팅으로 서로 관련이 없는 포인터들 사이의 캐스팅 등

*/

// static_cast<int>(float_variable);


