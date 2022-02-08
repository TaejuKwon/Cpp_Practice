#include <iostream>

class Date {
    int year_;
    int month_;     // 1 ~ 12
    int day_;       // 1 ~ 31

    public:
        void set_date(int year, int month, int date) {
            year_ = year;
            month_ = month;
            day_ = date;
        }
        void add_day(int inc) {
            day_ += inc;

            switch (month_) {
                case 1:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
                case 2:
                    if (year_ % 4 == 0 || year_ % 100 == 0 || year_ % 400 == 0) {
                        if (day_ > 29) {
                            add_month(1);
                            day_ -= 29;
                        }
                        else {}
                    }
                    else {
                        if (day_ > 28) {
                            add_month(1);
                            day_ -= 28;
                        }
                        else {}
                    }
                case 3:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
                case 4:
                    if (day_ > 30) {
                        add_month(1);
                        day_ -= 30;

                    }
                    else {}
                case 5:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
                case 6:
                    if (day_ > 30) {
                        add_month(1);
                        day_ -= 30;

                    }
                    else {}
                case 7:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
                case 8:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
                case 9:
                    if (day_ > 30) {
                        add_month(1);
                        day_ -= 30;

                    }
                    else {}
                case 10:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
                case 11:
                    if (day_ > 30) {
                        add_month(1);
                        day_ -= 30;

                    }
                    else {}
                case 12:
                    if (day_ > 31) {
                        add_month(1);
                        day_ -= 31;

                    }
                    else {}
            }

        }
        void add_month(int inc) {
            month_ += inc;
            while (month_ >= 13) {
                add_year(1);
                month_ -= 12;
            }
                

        }
        void add_year(int inc) {
            year_ += inc;

        }

        void show_date() {
            std::cout << year_ << "년" << month_ << "월" << day_ << "일" << std::endl;

        }
    
};

int main() {
    Date date;
    int day, month, year;

    date.set_date(2002, 10, 9);

    std::cout << "Initial Date" << std::endl;
    date.show_date();
    std::cout << std::endl;

    std::cout << "Press year to add" << std::endl;
    std::cin >> year;
    date.add_year(year);
    std::cout << std::endl;

    std::cout << "Press month to add" << std::endl;
    std::cin >> month;
    date.add_month(month);
    std::cout << std::endl;

    std::cout << "Press day to add" << std::endl;
    std::cin >> day;
    date.add_day(day);
    std::cout << std::endl;

    std::cout << "Current Date" << std::endl;
    date.show_date();
    std::cout << std::endl;

    return 0;

}