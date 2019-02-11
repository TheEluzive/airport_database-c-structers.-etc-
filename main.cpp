#include "airport.h" 
#include <iostream>
#include <iomanip>
using namespace std;

void menu()
{
	cout << "\n\n 1)Reading data from file -     press <1>" << endl;	//для чтения из файла - нажмите 1
	cout << " 2)Reading data from keyboard - press <2>" << endl;		//для чтения с клавиатуры  - нажмите 2
	cout << " 3)Output data on display -     press <3>" << endl;		//для вывода на экран нажмите - 3
	cout << " 4)Quickest aircraft -          press <4>" << endl;		//вывести самый быстрый самолёт - нажмите 4
	cout << " 5)All flights from Moscow -    press <5>" << endl;		//вывести все рейсы из Москвы - нажмите 5 
	cout << " 6)Write data in txt-file -     press <6>" << endl;		//запись в файл - нажмите 6
	cout << " 7)Compare two flights -        press <7>" << endl;		//сравнить два рейса - нажмите 7
	cout << " 8)Close data -                 press <8>" << endl;		//запустить деструктор - нажмите 8
}

airport vlg(25,25);
int m=0;

void airport::checker()
{
	int c1 = 0; int c2 = 0;
	cout << " Write number of comparing flights. " << endl;
	cout << " Number #1: ";  cin >> c1;
	cout << " Number #2: "; cin >> c2;
	if (vlg.flights[c1 - 1] == vlg.flights[c2 - 1])
		cout << " Flight #1 == Flight #2";
	else
		cout << " This is different flights!";
	getchar();

}

int main()
{
	system("color f0");

	if (m == 0)
	{
		menu();
		m = 1;
	}
	
	int choose = 0;
	cout << "\n\n\n\n Input : ";
	cin >> choose;
	ifstream fin;
	fin.open("flights.txt");
	ofstream fout;
	fout.open("output.txt");
	switch (choose)
	{
		
	case 1:
	{        			  
			  fin >> vlg; 
			  getchar();
			  fin.close();
			  main();
			  break;
	}
	
	case 2:
	{
			  cin >> vlg;
			  system("cls");
			  menu();
			  cout << "\n\n DATA WAS CHANGED BY USER... " << endl;
			  main();
			  break;
	}
	
	case 3:
	{
			  cout << vlg; 
			  getchar();
			  menu();
			  main();
	}
	
	case 4:
	{
			  vlg.speed();
			  getchar();
			  main();
			  break;
	}
	
	case 5:
	{
			  vlg.MSK();
			  getchar();
			  main();
			  break;
	}

	case 6:
	{
			  fout << vlg;
			  getchar();
			  main();
			  break;			  
	}

	case 7:
	{
			  vlg.checker();
			  getchar();
			  main();
			  break;
	}

	case 8:
	{
			  vlg.~airport();
			  getchar();
			  break;
			 
	}

	default:
	{
			   cout << "Failed!";
			   getchar();
			   main();
	}
	}
	fin.close();
	fout.close();
	
}
