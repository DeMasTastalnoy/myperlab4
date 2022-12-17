#include <iostream>
#include <locale>

using namespace std;

void remove(char* exp, int* startindex, int* count)
{
    for (int i = *startindex; i < *count + *startindex; i++)
    {
        exp[i] = ' ';
    }
    /*
    for (int i = *startindex; i < *count + 1; i++)
    {
        exp[i] = exp[j];
        exp[j] = ' ';
        j++;
    }
    */
    for (int i = *startindex; i < sizeof(exp); i++)
        for (int j = *startindex; j < sizeof(exp); j++)
        {
            if (exp[j] == ' ')
                swap(exp[j], exp[j + 1]);

        }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int startindex;
    int count;
    unsigned short int size;
    cout << "Введите длину выражения" << endl;
    cin >> size;
    char* exp = new char[size + 10];
    cout << "Введите строку" << endl;
    cin >> exp;
    cout << "Введите номер начального символа и количество символов" << endl;
    cin >> startindex >> count;
    while (startindex > size || count > (size - startindex))
    {
        startindex = 0;
        count = 0;
        cout << "Повторите ввод" << endl;
        cin >> startindex >> count;
    }
    remove(exp, &startindex, &count);
    cout << endl;
    cout << exp;
    delete[] exp;
    return 0;
}