#include <iostream>

class Marine {
    int hp;                
    int coord_x, coord_y;  
    int damage;            
    bool is_dead;

    public:
        Marine();              
        Marine(int x, int y);  

        int attack();                    
        void be_attacked(int damage_earn);  
        void move(int x, int y);            

        void show_status();  
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}         // 초기화 리스트 : 생성자 호출과 동시에 멤버 변수들을 초기화시켜 줌
                                                                                        // 생성과 동시에 초기화 : 레퍼러스와 상수 -> 얘네를 쓸 땐 초기화 리스트 필수
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() {return damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();
}