#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //переменные для настройки//
    char separator = ' ';
    char endSeparator = '.';
    //переменные для настройки//

    string path = "Input.txt";
    ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        cout << "Ошибка открытия файла!";
        inputFile.close();
        return 0;
    }
    int now = 0;
    int num = 0;
    char* chbuffer = new char[10000];
    inputFile.getline(chbuffer, 10000);
    while (chbuffer[now] != endSeparator)
    {
        if (chbuffer[now] == separator)
        {
            num++;
        }
        now++;
    }
    num++;
    now = 0;
    float* numbers = new float[num];
    num = 0;
    while (chbuffer[now] != endSeparator)
    {
        if (chbuffer[now] != separator)
        {
            switch (chbuffer[now])
            {
                case '0':
                    numbers[num] *= 10;
                    numbers[num] += 0;
                    break;
                case '1':
                    numbers[num] *= 10;
                    numbers[num] += 1;
                    break;
                case '2':
                    numbers[num] *= 10;
                    numbers[num] += 2;
                    break;
                case '3':
                    numbers[num] *= 10;
                    numbers[num] += 3;
                    break;
                case '4':
                    numbers[num] *= 10;
                    numbers[num] += 4;
                    break;
                case '5':
                    numbers[num] *= 10;
                    numbers[num] += 5;
                    break;
                case '6':
                    numbers[num] *= 10;
                    numbers[num] += 6;
                    break;
                case '7':
                    numbers[num] *= 10;
                    numbers[num] += 7;
                    break;
                case '8':
                    numbers[num] *= 10;
                    numbers[num] += 8;
                    break;
                case '9':
                    numbers[num] *= 10;
                    numbers[num] += 9;
                    break;
            }
        }
        if (chbuffer[now] == separator)
        {
            num++;
        }
        now++;
    }
    num++;
    delete[] chbuffer;
    float buble = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                buble = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = buble;
            }
        }
    }

    //вывод результатов
    system("clear");
    cout << "Ваш упорядоченный ряд - ";
    for (int i = 0; i < num; i++)
    {
        cout << numbers[i] << " ";
    }
    float moda = 0; //мода ряда
    float mediana = 0; //медиана
    float average = 0; //среднее арифметическое
    float min = numbers[0]; //минимальное (для вычисления размаха)
    float max = numbers[0]; //максимальное (для вычисления размаха)
    //вычисление медианы
    if ((num % 2) != 0)
    {
        mediana = (int)numbers[num / 2];
    }
    else
    {
        mediana = (numbers[(num / 2) - 1] + numbers[num / 2]) / 2;
    }
    //вычисление среднего арифметического
    float temp = 0;
    for (int i = 0; i < num; i++)
    {
        temp += numbers[i];
    }
    average = (temp / num);
    //вычисление размаха
    for (int i = 0; i < num; ++i)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }
    for (int i = 0; i < num; ++i)
    {
        if (min > numbers[i])
        {
            min = numbers[i];
        }
    }
    cout << endl
         << endl
         << "Колличество элементов - " << num << endl
         << "Мода - " << moda << endl
         << "Медиана - " << mediana << endl
         << "Среднее арифметическое - " << average << endl
         << "Размах - " << max - min << endl;
}