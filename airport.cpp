#include <iostream> 
#include "airport.h" 
#include <Windows.h>
using namespace std;



flight new_flight;
failflight new_failflight;
airport::airport(unsigned int max_n, unsigned int max_ff)
{
	system("color f0");
	max_num_flights = max_n; 
	max_num_failflights = max_ff;
	flights = new flight[max_num_flights];
	failflights = new failflight[max_num_failflights];

	num_flights = 0;
	num_failflights = 0;

	cout << " Hello, it is Airport database! " << endl << " To work press any button" << endl 
		 << " Class airport is ready." << "\n Created flights - " << max_num_flights << "..." 
		 << endl << " Created failflights - " << max_num_failflights << "..." ;
	
	getchar();
	system("cls");	
}

airport::~airport()
{
	max_num_flights = 0;
	max_num_failflights = 0;
	delete[] flights;
	delete[] failflights;
	num_flights = 0;
	num_failflights = 0;
	cout << "\n Class 'Airport' was destroyed.\n Memory is clean.";  
} 

void airport::operator+=(flight &aflight)
{
	if (num_flights < max_num_flights)     // можем добавить еще один полёт? 
	{
		flight new_flight;
		flights[num_flights] = aflight;      // заносим полёт в массив  
		num_flights++;                   // увеличиваем счетчик полётов 
	}
	else
		cout << "Overflight" << endl;
}

void airport::operator+=(failflight &afailflight)
{
	if (num_failflights < max_num_failflights)     // можем добавить еще один полёт? 
	{
		failflight new_failflight;
		failflights[num_failflights] = afailflight;      // заносим полёт в массив  
		num_failflights++;                   // увеличиваем счетчик полётов 
	}
	else
		cout << "Overfailflight" << endl;
}


void airport::read_from_file(string filename)
{
	ifstream fin;
	fin.open(filename);  
		if (!fin.is_open())
		{
			cout << "\n\nFile wasn`t found!" << endl;  	 	
			system("pause");  	 
			exit(1);
		}

		int N;
		fin >> N;
		fin.get();
		flight new_flight;
		for (int i = 0; i < N; i++)
		{		
			
			fin >> new_flight;
			this -> operator+=(new_flight); 
		}
	fin.close();

	cout << "\n Data was loaded" << endl <<" from: " << filename << ", flights : " << num_flights;	
	getchar();
}

void airport::failread_from_file(string filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "\n\nFile wasn`t found!" << endl;
		system("pause");
		exit(1);
	}

	int N;
	fin >> N;
	fin.get();
	failflight new_failflight;
	for (int i = 0; i < N; i++)
	{
		
		fin >> new_failflight;
		this -> operator+=(new_failflight);
	}
	fin.close();

	cout << "\n Data was loaded" << endl << " from: " << filename << ", failflights : " << num_failflights;
	getchar();
}

istream& operator >> (istream& kin, airport& airport) //keyboard in
{
	airport.read_from_keyboard();
	airport.failread_from_keyboard();
	return kin;
}

ifstream& operator >> (ifstream& fin, airport& airport) //file in
{
	airport.read_from_file("flights.txt");
	airport.failread_from_file("FailFlights.txt");
	return fin;
}

void airport::read_from_keyboard()
{
	
	int N;
	system("cls");
	cout << " Write amount flights : ";
	cin >> N;
	cout <<  endl;
	
	for (int i = 0; i < N; i++)
	{
		cout <<" Flight #"<< i+1 << endl;
		flight new_flight;
		cin >> new_flight;
		this -> operator+=(new_flight);
	}

	getchar();
	
}

void airport::failread_from_keyboard()
{

	int N;
	system("cls");
	cout << " Write amount failflights : ";
	cin >> N;
	cout << endl;
	
	for (int i = 0; i < N; i++)
	{
		cout << " FailFlight #" << i + 1 << endl;
		failflight new_failflight;
		cin >> new_failflight;
		this -> operator+=(new_failflight);
	}

	getchar();

}

ofstream& operator << (ofstream& fout, airport& airport) //file out
{
	ofstream fout2;
	fout2.open("output.txt");
	fout2 << " " << airport.num_flights << endl;
	for (int i = 0; i < airport.num_flights; i++)
	{
		fout2 << " Flight #" << i + 1 << endl;
		fout2 << airport.flights[i];
	}
	fout2.close();
	ofstream fout3;
	fout3.open("outputfail.txt");
	fout3 << " " << airport.num_failflights << endl;
	for (int i = 0; i < airport.num_failflights; i++)
	{
		fout3 << " FailFlight #" << i + 1 << endl;
		fout3 << airport.failflights[i];
	}
	fout3.close();

	cout << endl << " " << airport.num_flights << " flights wrote in file " << "output.txt" << endl;
	cout << endl << " " << airport.num_failflights << " failflights wrote in file " << "outputfail.txt" << endl;

	return fout;
}

ostream& operator << (ostream& ccout, airport& airport) //monitor out
{
	system("cls");

	cout << " Reading from file.." << endl << endl;
	for (int i = 0; i < airport.num_flights; i++)
	{
		cout << " Flight #" << i + 1 << endl;
		cout << airport.flights[i] << endl;
		
	}
	cout << endl << endl;
	for (int i = 0; i < airport.num_failflights; i++)
	{
		cout << " FailFlight #" << i + 1 << endl;
		cout << airport.failflights[i];
	}
	return ccout;
}

void airport::speed()
{
	cout << "\n\n Maximum mid speed = " << new_flight.mss() << " km/hour "
		 << " have " << new_flight.maxaircraft()  << endl;
}
 
void airport::MSK()
{
	cout << "\n\n Duration all flights from Moscow = " << new_flight.sum() << " km " << endl;
}



