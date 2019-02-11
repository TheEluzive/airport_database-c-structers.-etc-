#ifndef FLIGHTS_H 
#define FLIGHTS_H 

#include <string>
#include <fstream> 
using std::string;
using std::ifstream;
using std::ofstream; 
using std::ostream;
using std::istream;


class flight
{

	protected:
		int number; // номер рейса
		string airline; //название авиакомпании
		string from; //откуда
		string to; //куда
		float distance; //дистанция перелёта
		float duration; //продолжительность перелёта
		string aircraft; // тип самолета
		int pessengers; //кол-во посадочных мест
		float ms;// средняя скорость
	
	public:  
		 flight() : number(0), airline(""), from(""), to(""), distance(0), duration(0), aircraft(""), pessengers(0), ms(0) {};
		 flight(int, string, string, string, float, float, string, int, float);
		 bool operator==(flight another);		
		 friend istream& operator >> (istream& kin,  flight& aflight); //keyboard in
		 friend ifstream& operator >> (ifstream& fin, flight& aflight); //file in/reader
		 friend ostream& operator << (ostream& mout, const flight& aflight); //monitor out
		 friend ofstream& operator << (ofstream& fout, const flight& aflight); //file out
		 float mss(); //скорость
		 string maxaircraft(); //название самого быстрого
		 int sum(); //протяженность авиаперелётов из Москвы		 
};

class failflight : public flight // отложенные рейсы
{
	private:
		float time; //рейс отложен на time часов
	public:
		failflight() : flight(), time(0) {};
		failflight(int, string, string, string, float, float, string, int, float, int);
		friend bool operator==(failflight failflight1, failflight failflight2);
		friend istream& operator >> (istream& kin, failflight& afailflight); //keyboard in
		friend ifstream& operator >> (ifstream& fin, failflight& afailflight); //file in/reader
		friend ostream& operator << (ostream& mout,const failflight& afailflight); //monitor out
		friend ofstream& operator << (ofstream& fout,const failflight& afailflight); //file out

};


#endif 
