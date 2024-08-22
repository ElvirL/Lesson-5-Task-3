/*
Задание 3. Анализ заполненности вагонов в поезде* (дополнительное задание)
Что нужно сделать
В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20 пассажиров — это их оптимальное количество. 
Проанализируйте количество людей в каждом вагоне и сначала сообщите об излишне заполненных вагонах, далее о вагонах с пустыми 
пассажирскими местами. В заключение выведите общее количество пассажиров во всех вагонах.
При старте программы пользователь вводит количество пассажиров в каждом вагоне. Замечания о вагонах должны выводиться в стандартную 
консоль.
При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только опосредованно, через макросы.

Советы и рекомендации
С помощью макроса реализуйте модульный способ вызова функции над элементами массива. Сами функции реализуйте отдельно, в виде 
обычных классических функций (не макросов).
Модульный способ вызова функции печати текста через макрос:
```

define CALL(func) { func("Hello, GeekBrains!"); }
void print(std::string str) {
std::cout << str << std::endl;
}

int main() {
CALL(print);
return 0;
}
*/

#include <iostream>
#include <vector>

#define FOR_CYCLE(func, n) {for (int i=0; i<n; ++i) {func;}}

void read_vec(std::vector<int>& vec){
    int n;
    std::cin >> n;
    vec.push_back(n);
}

void processing_vec(std::vector<int>& vec, std::vector<int>& overcrowded, std::vector<int>& free_place, 
                                int& number_train_carriage, int& count_passanger){
    if (vec[0] > 20){
        overcrowded.push_back(number_train_carriage);
    }
    else if (vec[0] < 20){
        free_place.push_back(number_train_carriage);
    }
    count_passanger+=vec[0];
    ++number_train_carriage;
    vec.erase(vec.begin());
}


void print_vec(std::vector<int>& vec){
    std::cout << vec[0] << " ";
    vec.erase(vec.begin());
}

int main(){
    setlocale(LC_ALL, "Russian");
    std::vector<int> vec;
    std::vector<int> overcrowded;
    std::vector<int> free_place;
    int count_passanger = 0;
    int number_train_carriage = 1;

    std::cout << "Введите количество пассажиров в каждодм вагоне: ";
    FOR_CYCLE(read_vec(vec), 10);

    FOR_CYCLE(processing_vec(vec,overcrowded, free_place,number_train_carriage, count_passanger), 10);

    std::cout << "Излишне заполненные вагоны:" << std::endl;
    int size_vec = static_cast<int>(overcrowded.size());
    FOR_CYCLE(print_vec(overcrowded), size_vec);
    std::cout << std::endl;

    std::cout<< "Вагоны с пустыми местами:" << std:: endl;
    size_vec = static_cast<int>(free_place.size());
    FOR_CYCLE(print_vec(free_place), size_vec);
    std::cout << std::endl;

    std:: cout << "Общее количество пассажиров - " << count_passanger;






}
    
