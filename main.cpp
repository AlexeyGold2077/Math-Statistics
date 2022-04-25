#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    
 //configuration variables
 char separator = ' ';
 char endSeparator = '.';
 //end of configuration variables

 setlocale(LC_ALL, "Russian");
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
 char boof[10000];
 float massBoof[10000];
 for (int i = 0; i < 10000; i++)
 {
  massBoof[i] = 0;
 }
 inputFile.getline(boof, 10000);
 while (boof[now] != endSeparator)
 {
  if (boof[now] != separator)
  {
   switch (boof[now])
   {
   case '0':
    massBoof[num] *= 10;
    massBoof[num] += 0;
    break;
   case '1':
    massBoof[num] *= 10;
    massBoof[num] += 1;
    break;
   case '2':
    massBoof[num] *= 10;
    massBoof[num] += 2;
    break;
   case '3':
    massBoof[num] *= 10;
    massBoof[num] += 3;
    break;
   case '4':
    massBoof[num] *= 10;
    massBoof[num] += 4;
    break;
   case '5':
    massBoof[num] *= 10;
    massBoof[num] += 5;
    break;
   case '6':
    massBoof[num] *= 10;
    massBoof[num] += 6;
    break;
   case '7':
    massBoof[num] *= 10;
    massBoof[num] += 7;
    break;
   case '8':
    massBoof[num] *= 10;
    massBoof[num] += 8;
    break;
   case '9':
    massBoof[num] *= 10;
    massBoof[num] += 9;
    break;
   }
  }
  if (boof[now] == separator)
  {
   num++;
  }
  now++;
 }
 num++;
 float* mass = new float[num];
 for (int i = 0; i < num; i++)
 {
  mass[i] = massBoof[i];
 }
 float buble = 0;
 for (int i = 0; i < num; i++)
 {
  for (int j = 0; j < num - 1; j++)
  {
   if (mass[j] > mass[j + 1])
   {
    buble = mass[j];
    mass[j] = mass[j + 1];
    mass[j + 1] = buble;
   }
  }
 }
system("clear");
 cout << "Ваш упорядоченный ряд - ";
 for (int i = 0; i < num; i++)
 {
  cout << mass[i] << " ";
 }
 float moda = 0;
 float mediana = 0;
 float average = 0;
 float min = mass[0];
 float max = mass[0];
 if ((num % 2) != 0)
 {
  mediana = (int)mass[num / 2];
 }
 else
 {
  mediana = (mass[(num / 2) - 1] + mass[num / 2]) / 2;
 }
 float temp = 0;
 for (int i = 0; i < num; i++)
 {
  temp += mass[i];
 }
 average = (temp / num);
 for (int i = 0; i < num; ++i)
 {
     if (max < mass[i])
     {
         max = mass[i];
     }
 }
 for (int i = 0; i < num; ++i)
 {
     if (min > mass[i])
     {
         min = mass[i];
     }
 }
 cout << endl << endl << "Колличество элементов - " << num << endl << "Мода - " << moda << endl << "Медиана - " << mediana << endl << "Среднее арифметическое - " << average << endl << "Размах - " << max - min << endl;
}