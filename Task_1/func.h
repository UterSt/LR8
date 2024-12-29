#include <string>

typedef struct
{
    char FIO[100];
    int id;
    union number
    {
        int i;
    } number;
    int tarif;
    int zp;
} officers;

void InputOfficers(officers& array);
void Prosmotr(officers* array, int size);
officers* ResizeArray(officers* array, int size, int newsize);
void Del(officers*& array, int& size, int id);
void find(officers* array, int size, int id);
void sort(officers*& array, int size);
void SaveToFile(officers* array, int size, std::string& filename);
int LoadFromFile(officers*& array, std::string& filename);
void RedactFile(std::string& filename, int id);