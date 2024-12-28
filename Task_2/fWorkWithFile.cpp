#include <fstream>
#include <iostream>
#include "func.h"

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
        std::cout << "Ошибка открытия файла." << std::endl;
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