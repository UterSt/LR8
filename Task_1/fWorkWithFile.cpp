#include <iostream>
#include <string>
#include <fstream>
#include "func.h"

void SaveToFile(officers* array, int size, std::string& filename)
{
    std::ofstream outFile(filename, std::ios::binary);
    outFile.write((char*)(array), sizeof(officers) * size);
    outFile.close();
}

int LoadFromFile(officers*& array, std::string& filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) return 0;
    inFile.seekg(0, std::ios::end);
    int size = inFile.tellg() / sizeof(officers);
    inFile.seekg(0, std::ios::beg);
    array = new officers[size];
    inFile.read((char*)(array), sizeof(officers) * size);
    inFile.close();
    return size;
}

void RedactFile(std::string& filename, int id)
{
    std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);
    officers temp;
    while (file.read((char*)(&temp), sizeof(officers)))
    {
        if (temp.id == id)
        {
            std::cout << "Измените ФИО: ";
            std::cin.ignore();
            std::cin.getline(temp.FIO, 100);
            std::cout << "Измените количество отработанных часов: ";
            std::cin >> temp.number.i;
            std::cout << "Измените тариф: ";
            std::cin >> temp.tarif;
            temp.zp = temp.number.i * temp.tarif;
            file.seekp(-static_cast<long>(sizeof(officers)), std::ios::cur);
            file.write((char*)(&temp), sizeof(officers));
            break;
        }
    }
    file.close();
}