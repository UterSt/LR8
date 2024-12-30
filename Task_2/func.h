#include <string>
#include "struct.h"

void InputStudent(students& array);
void Prosmotr(students* array, int size);
students* ResizeArray(students* array, int size, int newsize);
void Del(students*& array, int& size, std::string FIO);
void redact(students*& array, int size, std::string FIO);
void Number(students* array, int size);
void SaveToFile(students* array, int size, std::string& filename);
void LoadFromFile(students*& array, int& size, std::string& filename);