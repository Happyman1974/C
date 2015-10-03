// file.cpp: определяет точку входа для консольного приложения.

//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// объявление прототипа функции 
int faktorial(int);// заголовок функции


int main(int argc, char* argv[])
 {
        int data;
        ifstream fin;
        fin.open("mac.txt"); // открыли файл для чтения
//        assert (!fin.fail( ));  //?
	fin >> data; // считали первое слово из файла	
	// get first number from the file (priming the input statement)
    // You must attempt to read info prior to an eof( ) test.
        
        while (!fin.eof())
        {
	stringstream ss;
	cout << data << endl; // напечатали это слово
	
	ofstream fout; // создаём объект класса ofstream для записи 
	
	ss << "out" << data << ".cfg";
	fout.open ( ss.str().c_str() );
	fout << "account.1.enable = 1\n"
	<< "account.1.label = " << data << endl
	<< "account.1.display_name = " << data << endl
	<< "account.1.auth_name = " << data << endl
	<< "account.1.user_name = " << data << endl
	<< "account.1.password = aeRa8quo\n"
	<< "account.1.reregister_enable = 1\n"
	<< "account.1.sip_server.1.address = 10.1.0.5\n"
	<< "local_time.ntp_server1 = ntp.tbm.ru";
        fout.close(); // закрываем файл
        
        fin >> data;
        }
       
	fin.close(); // закрываем файл
	
        
// system("pause");
 return 0;
 }
 
 // объявление функции нахождения n!
int faktorial(int numb)// заголовок функции
{
    int rezult = 1; // инициализируем переменную rezult значением 1
    for (int i = 1; i <= numb; i++) // цикл вычисления значения n!
        rezult *= i; // накапливаем произведение в переменной rezult
    return rezult; // передаём значение факториала в главную функцию
}

