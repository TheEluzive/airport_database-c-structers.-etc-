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
		int max_num_flights;            // ������������ ���-�� ������ 
		int max_num_failflights;
		int num_flights;                // ������� ����� ������ 
		int num_failflights;
		flight *flights;                  // ������ �������� ������ flight
		failflight *failflights;
	public:    
		airport(unsigned int max_n, unsigned int max_ff);         // ����������� ������
		~airport();                          //���������� 
		void operator += (flight &aflight); //���������� ��������
		void operator += (failflight &afailflight);
		void read_from_file(string filename);   // ������ ������ �� ����� 
		void failread_from_file(string filename);
		void read_from_keyboard();   // ������ ������ c ���������� 
		void failread_from_keyboard();

		friend istream& operator >> (istream& kin, airport& airport); //keyboard in
		friend ostream& operator << (ostream& ccout, airport& airport); //monitor out
		friend ifstream& operator >> (ifstream& fin, airport& airport); //file in
		friend ofstream& operator << (ofstream& fout, airport& airport); //file out
		


		void speed(); // ������� ���������� ������� �������� �����
		void MSK(); // ������� ������������� ������ �� ������		
		void checker();
		
};




#endif 
