#include <iostream>
#include "func.h"

int main()
{
    std::string filename = "officers.bin";
    officers* array = nullptr;
    int size = LoadFromFile(array, filename);

    if (size == 0)
    {
        std::cout << "Введите количество сотрудников: ";
        std::cin >> size;
        array = new officers[size];
        for (int i = 0; i < size; ++i)
        {
            InputOfficers(array[i]);
        }
        SaveToFile(array, size, filename);
    }

    int stope = 1;
    while (stope != 0)
    {
        std::cout << "Выберите функцию: " << std::endl;
        std::cout << "0 - закончить" << std::endl;
        std::cout << "1 - просмотреть таблицу" << std::endl;
        std::cout << "2 - дополнить" << std::endl;
        std::cout << "3 - поиск" << std::endl;
        std::cout << "4 - удалить/изменить" << std::endl;
        std::cout << "5 - упорядочить" << std::endl;
        std::cin >> stope;

        if (stope == 1)
        {
            Prosmotr(array, size);
        }
        else if (stope == 2)
        {
            int dop;
            std::cout << "На сколько дополнить?: ";
            std::cin >> dop;
            array = ResizeArray(array, size, size + dop);
            size += dop;
            for (int i = size - dop; i < size; ++i)
            {
                InputOfficers(array[i]);
            }
            SaveToFile(array, size, filename);
        }
        else if (stope == 3)
        {
            int id;
            std::cout << "Какой id найти?: ";
            std::cin >> id;
            find(array, size, id);
        }
        else if (stope == 4)
        {
            int num, id;
            std::cout << "1 - удалить" << std::endl;
            std::cout << "2 - изменить" << std::endl;
            std::cin >> num;
            if (num == 1)
            {
                std::cout << "Какой id убрать?: ";
                std::cin >> id;
                Del(array, size, id);
                SaveToFile(array, size, filename);
            }
            else if (num == 2)
            {
                std::cout << "Какой id изменить?: ";
                std::cin >> id;
                RedactFile(filename, id);
            }
        }
        else if (stope == 5)
        {
            sort(array, size);
            SaveToFile(array, size, filename);
        }
    }

    delete[] array;
    return 0;
}