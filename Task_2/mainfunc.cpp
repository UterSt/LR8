#include <iostream>
#include <algorithm>
#include "func.h"

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