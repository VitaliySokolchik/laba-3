#include <cstdlib>
#include <iostream>
#include <locale.h>
#include<ios>  
#include<limits>

using namespace std;

class Massiv
{
private:
    int n;
    double* arr;
public:
    Massiv() {
        n = 3;
        this->arr = new double[n];
        for (int i = 0; i < n; i++)
            this->arr[i] = 0;
    }
    Massiv(int a, double* array) {
        n = a;
        this->arr = new double[this->n];
        for (int i = 0; i < n; i++)
            this->arr[i] = array[i];
    }
    Massiv(const Massiv& other)
    {
        this->n = other.n;
        this->arr = new double[other.n];
        for (int i = 0; i < n; i++)
            this->arr[i] = other.arr[i];
    }
    void setMassive(int n, double* mas)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            this->arr[i] = mas[i];
        }
    }

    friend void show(Massiv& prin);

    friend bool operator> (const Massiv& b1, const  Massiv& b2);

    friend bool operator< (const  Massiv& d1, const  Massiv& d2);

    friend bool operator== (const  Massiv& c1, const  Massiv& c2);

    friend const Massiv& operator--(Massiv& d1);

    ~Massiv() {
        delete[]this->arr;
    }

};


bool operator> (const  Massiv& b1, const  Massiv& b2)
{
    return (b1.n > b2.n);
}

bool operator< (const  Massiv& d1, const  Massiv& d2)
{
    return (d1.n < d2.n);
}

bool operator== (const  Massiv& c1, const  Massiv& c2)
{
    return (c1.n == c2.n);
}
const Massiv& operator--(Massiv& d1) {
    d1.n -= 1;
    return d1;
}
int getValue()
{
    while (true)
    {
        int a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "ERROR! INT ONLY!\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}
void show(Massiv& prin)
{
    for (int i = 0; i < prin.n; i++)
    {
        cout << prin.arr[i] << " ";
    }
    cout << endl;
    cout << "===============================" << endl;
}
int main()
{
    int n;
    double* array;
    setlocale(LC_ALL, "Russian");
    cout << "Массив: ";
    cout << endl << "Колиество элементов = ";
    n = getValue();
    array = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Элемент [" << i << "] : ";
        cin >> array[i];
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Massiv def(n, array);
    Massiv Copy = def;
    show(def);
    cout << "Скопировали :" << endl;
    show(Copy);

    const int size = 4;
    Massiv matr[size];
    int k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (k = 0; k < 4; k++) {
        cout << "Массив: ";
        cout << endl << "Количество элементво = ";
        n = getValue();
        array = new double[n];
        for (int i = 0; i < n; i++) {
            cout << "Элемент [" << i << "] : ";
            cin >> array[i];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        matr[k]=Massiv(n, array);
        show(matr[k]);
    }
    int sw = 0, red_bt = 0, c, b;
    while (red_bt != 5)
    {
        cout << "Выберите номера 2-ух массивов [0-3]" << endl;
        c = b = 0;
        c = getValue();
        b = getValue();

        cout << "Выбор 1. >, 2. <, 3. ==, 4. --, 5. exit" << endl;
        sw = getValue();
        switch (sw)
        {
        case 1:
        {
            if (matr[c] > matr[b])
                cout << "Первый массив больше второго\n";
            else
                cout << "Первый массив меньше второго или равен ему\n";
            break;
        }
        case 2:
        {
            if (matr[c] < matr[b])
                cout << "Первый массив меньше второго\n";
            else
                cout << "Первый массив больше второго или равен ему\n";
            break;
        }
        case 3:
        {
            if (matr[c] == matr[b])
                cout << "Первый массив равен второму\n";
            else
                cout << "Первый массив не равен второму\n";
            break;
        }
        case 4:
        {
            --matr[c];
            show(matr[c]);
            break;
        }
        case 5:
        {
            red_bt = 5;
            break;
        }
        default:
            cout << "Введен неверный case";
            break;
        }

    }
    return 0;
}