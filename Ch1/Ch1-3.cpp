int number_of_people;
double interest_rate; 

// 좋은 변수명

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


int main() {

    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;

    }

    int sum = 0;

    for (int j = 0; j <= 10; j++) {
        sum += j;

    }
    std::cout << "합은 : " << sum << std::endl;

    // 행운의 숫자

    int lucky_num = 3;
    std::cout << "비밀의 수 맞추어 보세요" << std::endl;

    int user_input;

    while (1) {
        std::cout << "입력 : ";
        std::cin >> user_input; // C와 다른 부분 (scanf X)

        if (lucky_num == user_input) {
            std::cout << "맞추셨습니다" << std::endl;
            break;
        } else {
            std::cout << "다시" << std::endl;
        }

    }
    // switch문
    
    int user_input2;

    cout << "내 정보" << endl;
    cout << "1. 이름" << endl;
    cout << "2. 나이" << endl;
    cout << "3. 성별" << endl;
    cout << "숫자 입력" << endl;
    cin >> user_input2;

    switch (user_input2) {
        case 1:
            cout << "권태주" << endl;
            break;

        case 2:
            cout << "권태주" << endl;
            break;

        case 3:
            cout << "권태주" << endl;
            break;

        default:
            cout << " " << endl;
            break;
    }
    

    return 0;
}