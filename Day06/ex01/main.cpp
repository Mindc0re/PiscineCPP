#include <iostream>
#include <ctime>
#include <cctype>

struct          Data
{
    std::string s1;
    int         n;
    std::string s2;
};

std::string  randomStr(void)
{
    char    strC[9];
    char    randC = 0;

    for (int i = 0 ; i < 8 ; i++)
    {
        randC = 0;
        while (std::isalnum(randC) == false)
            randC = rand() % 127 + 1;
        strC[i] = randC;
    }
    strC[8] = '\0';
    return std::string(strC);
}

void *           serialize(void)
{
    char *toSer = new char[20];
    std::string s1;
    std::string s2;

    s1 = randomStr();
    s2 = randomStr();

    int n = rand();

    std::cout << "STRING 1 : " << s1 << std::endl;
    std::cout << "STRING 2 : " << s2 << std::endl;
    std::cout << "INT : " << n << std::endl;

    for (int i = 0 ; i < 8 ; i++)
        toSer[i] = s1[i];
    reinterpret_cast<int *>(toSer)[2] = n;
    for (int i = 12 ; i < 20 ; i++)
        toSer[i] = s2[i - 12];

    return reinterpret_cast<void *>(toSer);
}

Data *        deserialize(void *raw)
{
    char *deser = reinterpret_cast<char *>(raw);
    
    Data *data = new Data;

    for (int i = 0 ; i < 8 ; i++)
        data->s1 += deser[i];
    data->n = reinterpret_cast<int *>(deser)[2];
    for (int i = 12 ; i < 20 ; i++)
        data->s2 += deser[i];

    return data;
}

int             main(void)
{
    srand(time(NULL));

    void *test = serialize();

    deserialize(test);
    Data *test2 = deserialize(test);

    std::cout << "DESER : String 1 = " << test2->s1 << std::endl;
    std::cout << "DESER : rand n = " << test2->n << std::endl;
    std::cout << "DESER : String 2 = " << test2->s2 << std::endl;

    return 0;
}
