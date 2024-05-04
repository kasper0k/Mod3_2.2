/*Задача 2. Счётчик
В этом задании вам нужно будет создать класс-счётчик
Создайте класс Counter. Класс должен выполнять функцию счётчика, для этого он должен предоставлять:
    возможность увеличить своё значение на 1
    возможность уменьшить своё значение на 1
    возможность посмотреть своё текущее значение
    возможность создания экземпляра класса с начальным значением по умолчанию (1)
    возможность создания экземпляра класса с инициализирующим начальным значением */

#include <iostream>
#include <string>

class counter
{
    private:
        int total_num=1;
    public:
       // counter() : total_num(1) {};
        void start_command(int num) { total_num = num; }
        void add() { total_num = total_num + 1; };
        void subtract() { total_num = total_num - 1; };
        void total() { std::cout << "Результат: " << total_num << std::endl; };
        bool close() { return false; };
};

int main()
{
    setlocale(LC_ALL, "Russian");

    bool cheak_close = true, cheak_start = true;
    int num;
    std::string qust_start, command;
    counter count_num;
    
    do
    {
        std::cout << "Вы хотите указать начальное значение? Введите 'yes' или 'no': ";
        std::cin >> qust_start;
            if (qust_start == "да")
            {
                std::cout << "Введите начальное (целое) значение: ";
                std::cin >> num;
                count_num.start_command(num);
                cheak_start = true;
            }
            else if (qust_start == "нет")
            {
                std::cout << "Счетчик начнет со значения: 1\n";
                cheak_start = true;
            }
            else
            {
                std::cout << "Команда не распознана. Вы хотите указать начальное значение? Введите да или нет: ";
                cheak_start = false;
            }        
    } while (cheak_start == false);

    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        if (command == "+") { count_num.add(); };
        if (command == "-") { count_num.subtract(); };
        if (command == "=") { count_num.total(); };
        if (command == "x") { cheak_close=count_num.close(); };
    } while (cheak_close==true);
    
    std::cout << "До свидания!\n";
    return 0;
}
