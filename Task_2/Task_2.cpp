#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "func.h"

int main()
{
    std::string filename = "abituri.txt";
    int size = 0;
    students* array = nullptr;
    LoadFromFile(array, size, filename);
    if (size == 0)
    {
        std::cout << "Введите количество абитуриентов для записи: ";
        std::cin >> size;
        array = new students[size];
        for (int i = 0; i < size; ++i)
        {
            InputStudent(array[i]);
        }
    }
    int stope = 1;
    while (stope != 0)
    {
        std::cout << "Выберите функцию: " << std::endl;
        std::cout << "0 - закончить" << std::endl;
        std::cout << "1 - просмотреть таблицу" << std::endl;
        std::cout << "2 - дополнить" << std::endl;
        std::cout << "3 - удалить/изменить" << std::endl;
        std::cout << "4 - Подсчитать абитуриентов из Гомеля" << std::endl;
        std::cin >> stope;
        if (stope == 1)
        {
            Prosmotr(array, size);
        }
        else if (stope == 2)
        {
            int dop = 0;
            std::cout << "Сколько добавить?: ";
            std::cin >> dop;
            array = ResizeArray(array, size, size + dop);
            for (int i = size; i < size + dop; ++i)
            {
                InputStudent(array[i]);
            }
            size += dop;
        }
        else if (stope == 3)
        {
            int num;
            std::string FIO;
            std::cout << "1 - удалить" << std::endl;
            std::cout << "2 - изменить" << std::endl;
            std::cin >> num;
            if (num == 1)
            {
                std::cout << "Кого убрать?: ";
                std::cin.ignore();
                std::getline(std::cin, FIO);
                Del(array, size, FIO);
            }
            else if (num == 2)
            {
                std::cout << "Кого изменить?: ";
                std::cin.ignore();
                std::getline(std::cin, FIO);
                redact(array, size, FIO);
            }
        }
        else if (stope == 4)
        {
            Number(array, size);
        }
    }
    SaveToFile(array, size, filename);
    delete[] array;
    return 0;
}