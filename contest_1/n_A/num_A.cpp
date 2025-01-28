#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "date.h"

void sort_dates(std::vector<Date> &dates, std::string_view order) {
    std::sort(dates.begin(), dates.end(), [order](const Date &date_1, const Date &date_2) {
        for (int i = 0; i < 3; i++) {
            switch (order[i]) {
                case 'y':
                    if (date_1.year != date_2.year) {
                        return date_1.year < date_2.year;
                    }
                    break;
                case 'm':
                    if (date_1.month != date_2.month) {
                        return date_1.month < date_2.month;
                    }
                    break;
                case 'd':
                    if (date_1.day != date_2.day) {
                        return date_1.day < date_2.day;
                    }
                    break;
            }
        }
        return false;
    });
}

// int main() {
//     std::vector<Date> vec = {
//         {2006, 4, 20},
//         {2006, 5, 1},
//         {2002, 9, 3},
//         {2004, 1, 31},
//         {2006, 4, 20}
//     };

//     sort_dates(vec, "myd");

//     for (Date &date : vec) {
//         std::cout << static_cast<int>(date.year) << " " << static_cast<int>(date.month) << " " << static_cast<int>(date.day) << std::endl;
//     }

//     return 0;

// }
