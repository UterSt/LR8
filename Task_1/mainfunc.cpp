#include <iostream>
#include "func.h"

void InputOfficers(officers& array)
{
    std::cout << "Введите ФИО сотрудника: ";
    std::cin.ignore();
    std::cin.getline(array.FIO, 100);
    std::cout << "Введите табельный номер: ";
    std::cin >> array.id;
    std::cout << "Введите количество отработанных часов: ";
    std::cin >> array.number.i;
    std::cout << "Введите почасовой тариф: ";
    std::cin >> array.tarif;
    array.zp = array.number.i * array.tarif;
}

void Prosmotr(officers* array, int size)
{
    std::cout << "Список: " << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i].FIO << " | " << array[i].id << " | "
            << array[i].number.i << " | " << array[i].tarif << " | "
            << array[i].zp << std::endl;
    }
}

officers* ResizeArray(officers* array, int size, int newsize)
{
    officers* NewArray = new officers[newsize];
    for (int i = 0; i < size; ++i)
    {
        NewArray[i] = array[i];
    }
    delete[] array;
    return NewArray;
}

void Del(officers*& array, int& size, int id)
{
    int index = -1;
    for (int i = 0; i < size; ++i)
    {
        if (array[i].id == id)
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
        std::cout << "id не найден.";
    }
}

void find(officers* array, int size, int id)
{
    int index = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i].id == id)
        {
            std::cout << array[i].FIO << " | " << array[i].id << " | " << array[i].number.i << " | " << array[i].tarif << " | " << array[i].zp << std::endl;
            index++;
        }
    }
    if (index == 0)
    {
        std::cout << "id не найден.";
    }
}

void sort(officers*& array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (array[i].zp > array[j].zp)
            {
                std::swap(array[i], array[j]);
            }
        }
    }
}