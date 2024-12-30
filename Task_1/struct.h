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