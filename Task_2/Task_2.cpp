#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

struct students
{
    std::string FIO;
    std::string city;
    union number
    {
        double bal;
    } number;
};

void InputStudent(students& array)
{
    std::cout << "Введите ФИО абитуриента: ";
    std::cin.ignore();
    std::getline(std::cin, array.FIO);
    std::cout << "Введите адрес (Город): ";
    std::getline(std::cin, array.city);
    std::cout << "Введите балл: ";
    std::cin >> array.number.bal;
}

void Prosmotr(students* array, int size)
{
    std::cout << "Список: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i].FIO << " | " << array[i].city << " | " << array[i].number.bal << std::endl;
    }
}

students* ResizeArray(students* array, int size, int newsize)
{
    students* NewArray = new students[newsize];
    for (int i = 0; i < size; ++i)
    {
        NewArray[i] = array[i];
    }
    delete[] array;
    return NewArray;
}

void Del(students*& array, int& size, std::string FIO)
{
    int index = -1;
    for (int i = 0; i < size; ++i)
    {
        if (array[i].FIO == FIO)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < size - 1; ++i)
        {
            array[i] = array[i + 1];
        }
        size--;
        array = ResizeArray(array, size, size);
    }
    else
    {
        std::cout << FIO << " не найден.";
    }
}

void redact(students*& array, int size, std::string FIO)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i].FIO == FIO)
        {
            std::cout << "Измените ФИО: ";
            std::getline(std::cin, array[i].FIO);
            std::cout << "Измените город: ";
            std::getline(std::cin, array[i].city);
            std::cout << "Измените балл: ";
            std::cin >> array[i].number.bal;
            break;
        }
    }
}

void Number(students* array, int size)
{
    int count = 0;
    std::string* studentsG = new std::string[size];

    for (int i = 0; i < size; ++i)
    {
        std::cout << "Проверяем студента: " << array[i].FIO << ", город: " << array[i].city << ", балл: " << array[i].number.bal << std::endl; // Отладочная информация
        if (array[i].city == "Гомель") 
        {
            if (array[i].number.bal >= 4.5)
            {
                studentsG[count] = array[i].FIO;
                count++;
            }
        }
    }
    
    std::sort(studentsG, studentsG + count);
    std::cout << "Количество абитуриентов из Гомеля с средним баллом не ниже 4.5: " << count << std::endl;

    for (int i = 0; i < count; ++i)
    {
        std::cout << studentsG[i] << std::endl;
    }

    delete[] studentsG;
}

void SaveToFile(students* array, int size, std::string& filename)
{
    std::ofstream file(filename);
    for (int i = 0; i < size; ++i)
    {
        file << array[i].FIO << "|" << array[i].city << "|" << array[i].number.bal << std::endl;
    }
    file.close();
}

void LoadFromFile(students*& array, int& size, std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return;
    }
    size = 0;
    std::string line;
    while (std::getline(file, line))
    {
        size++;
    }
    file.clear();
    file.seekg(0);
    array = new students[size];
    for (int i = 0; i < size; ++i)
    {
        std::getline(file, line);
        int pos1 = line.find('|');
        int pos2 = line.find('|', pos1 + 1);
        array[i].FIO = line.substr(0, pos1);
        array[i].city = line.substr(pos1 + 1, pos2 - pos1 - 1);
        array[i].number.bal = std::stod(line.substr(pos2 + 1));
    }
    file.close();
}

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