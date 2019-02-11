#ifndef AIRPORT_H 
#define AIRPORT_H 

#include <string> 
#include <fstream> 
#include "flights.h" 
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;

class airport                    
{
	private: 
		int max_num_flights;            // максимальное кол-во полётов 
		int max_num_failflights;
		int num_flights;                // текущее число полётов 
		int num_failflights;
		flight *flights;                  // массив объектов класса flight
		failflight *failflights;
	public:    
		airport(unsigned int max_n, unsigned int max_ff);         // конструктор класса
		~airport();                          //деструктор 
		void operator += (flight &aflight); //добавления элемента
		void operator += (failflight &afailflight);
		void read_from_file(string filename);   // ввести данные из файла 
		void failread_from_file(string filename);
		void read_from_keyboard();   // ввести данные c клавиатуры 
		void failread_from_keyboard();

		friend istream& operator >> (istream& kin, airport& airport); //keyboard in
		friend ostream& operator << (ostream& ccout, airport& airport); //monitor out
		friend ifstream& operator >> (ifstream& fin, airport& airport); //file in
		friend ofstream& operator << (ofstream& fout, airport& airport); //file out
		


		void speed(); // вывести наибольшую среднюю скорость полёта
		void MSK(); // вывести протяженность рейсов из Москвы		
		void checker();
		
};




#endif 
