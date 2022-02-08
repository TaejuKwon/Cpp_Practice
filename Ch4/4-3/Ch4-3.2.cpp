#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;

    public:
        Marine();                               // 기본 생성자
        Marine(int x, int y);                   // x, y 좌표에 마린 생성

        int attack();                           // 데미지를 리턴
        void be_attacked(int damage_earn);      // 입는 데미지
        void move(int x, int y);                // 새로운 위치

        void show_status();                     // 현재 상태 표시

};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() {return damage;}

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) {is_dead = true;}
}

void Marine::show_status() {
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);      // C++에 맞는 새로운 동적 할당

    marines[0]->show_status();
    marines[1]->show_status();          // Marine들의 포인터를 가리키는 배열이기에 메소드를 호출할 때, .이 아니라 ->를 사용


    std::cout << std::endl << "마린 1이 마린 2를 공격 !" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}