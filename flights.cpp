#include "flights.h"
#include <iostream> 
#include "Windows.h"
using namespace std;

float maxms = 0;
string maxmsaicrft;
float summa = 0;
int sdvig = 0;
int sdvig2 = 0;

flight::flight(int nmbr, string arln, string frm, string toto, float dstnc, float drthn, string arcrft, int pssngrs, float mss)
{
	number = nmbr;
	airline = arln;
	from = frm;
	to = toto;
	distance = dstnc;
	duration = drthn;
	aircraft = arcrft;
	pessengers = pssngrs;
	ms = mss;
}


ifstream& operator >> (ifstream& fin, flight& aflight)
{
	fin >> aflight.number;
	fin >> aflight.airline;
	fin >> aflight.from;
	fin >> aflight.to;
	fin >> aflight.aircraft;
	fin >> aflight.distance;
	fin >> aflight.duration;
	fin >> aflight.pessengers;
	aflight.ms = aflight.distance / aflight.duration;
	if (aflight.ms > maxms)
	{
		maxms = aflight.ms;
		maxmsaicrft = aflight.aircraft;
	}
	if (aflight.from == "Moscow") summa = summa + aflight.distance;
	return fin;
}

int flight::sum()
{
	return summa;
}

float flight::mss()
{
	return maxms;
}

string flight::maxaircraft()
{
	return maxmsaicrft;
}



istream& operator>>(istream& kin, flight& aflight)
{
	
	cout << " Name : ";
	kin >> aflight.airline;
	
	cout << " From : ";
	cin >> aflight.from;

	cout << " To : ";
	cin >> aflight.to;

	cout << " Model/type : ";
	cin >> aflight.aircraft;;

	cout << " Distance(km) : ";
	cin >> aflight.distance;

	cout << " Duration(hour) : ";
	cin >> aflight.duration;

	cout << " Pessengers : ";
	cin >> aflight.pessengers;
	cout << endl;

	aflight.ms = aflight.distance / aflight.duration;
	if (aflight.ms > maxms)
	{
		maxms = aflight.ms;
		maxmsaicrft = aflight.aircraft;
	}
	return kin;
}

bool flight::operator==(flight another)
{
	if (airline != another.airline) return false;
	if (from != another.from) return false;
	if (to != another.to) return false;
	if (distance != another.distance) return false;
	if (duration != another.duration) return false;
	if (aircraft != another.aircraft) return false;
	if (pessengers != another.pessengers) return false;
}

ostream& operator<<(ostream& mout, const flight& aflight) //monitor out
{
	mout << " Airline : " << aflight.airline << endl;
	mout << " From: " << aflight.from << endl;
	mout << " Type aircraft : " << aflight.aircraft << endl;
	mout << " To : " << aflight.to << endl;
	mout << " Distance : " << aflight.distance << endl;	
	mout << " Duration : " << aflight.duration << endl;
	mout << " Pessengers : " << aflight.pessengers << endl;
	return mout;
}

ofstream& operator<<(ofstream& fout, const flight& aflight) //file out
{
	fout << " Airline : " << aflight.airline << endl;
	fout << " From: " << aflight.from << endl;
	fout << " Type aircraft : " << aflight.aircraft << endl;
	fout << " To : " << aflight.to << endl;
	fout << " Distance : " << aflight.distance << endl;	
	fout << " Duration : " << aflight.duration << endl;	
	fout << " Pessengers : " << aflight.pessengers << endl;
	return fout;
}

/// failflight go go go



failflight::failflight(int nmbr, string arln, string frm, string toto, float dstnc, float drthn, string arcrft, int pssngrs, float mss, int tme) :
flight(nmbr, arln, frm,  toto,  dstnc,  drthn,  arcrft, pssngrs,  mss), time(0)
{ 
	cout << " CLASS CONSTRUCTOR ACTIVATED";
	
}

bool operator==(failflight failflight1, failflight failflight2)
{
	bool are_equal_flights = static_cast<flight>(failflight1) == static_cast<flight>(failflight2);
	bool are_equal_time = failflight1.time == failflight2.time;
	if (are_equal_flights && are_equal_time) 
		return true; 
			return false;
}

istream& operator >> (istream& kin, failflight& afailflight) //keyboard in
{
	cout << " Name : ";
	kin >> afailflight.airline;

	cout << " From : ";
	cin >> afailflight.from;

	cout << " To : ";
	cin >> afailflight.to;

	cout << " Model/type : ";
	cin >> afailflight.aircraft;;

	cout << " Distance(km) : ";
	cin >> afailflight.distance;

	cout << " Duration(hour) : ";
	cin >> afailflight.duration;

	cout << " Pessengers : ";
	cin >> afailflight.pessengers;	

	afailflight.ms = afailflight.distance / afailflight.duration;
	if (afailflight.ms > maxms)
	{
		maxms = afailflight.ms;
		maxmsaicrft = afailflight.aircraft;
	}
	cout << " Time : ";
	kin >> afailflight.time;
	return kin;
}

ifstream& operator >> (ifstream& fin, failflight& afailflight)//file in/reader
{
	fin >> afailflight.number;
	fin >> afailflight.airline;
	fin >> afailflight.from;
	fin >> afailflight.to;
	fin >> afailflight.aircraft;
	fin >> afailflight.distance;
	fin >> afailflight.duration;
	fin >> afailflight.pessengers;
	afailflight.ms = afailflight.distance / afailflight.duration;
	if (afailflight.ms > maxms)
	{
		maxms = afailflight.ms;
		maxmsaicrft = afailflight.aircraft;
	}
	if (afailflight.from == "Moscow") summa = summa + afailflight.distance;
	fin >> afailflight.time;
	return fin;
}

ostream& operator << (ostream& mout,const failflight& afailflight) //monitor out
{
	mout << " Airline : " << afailflight.airline << endl;
	mout << " From: " << afailflight.from << endl;
	mout << " Type aircraft : " << afailflight.aircraft << endl;
	mout << " To : " << afailflight.to << endl;
	mout << " Distance : " << afailflight.distance << endl;
	mout << " Duration : " << afailflight.duration << endl;
	mout << " Pessengers : " << afailflight.pessengers << endl;
	mout << " Time : " << afailflight.time << endl << endl;
	return mout;
}

ofstream& operator << (ofstream& fout,const failflight& afailflight) //file out
{
	fout << " Airline : " << afailflight.airline << endl;
	fout << " From: " << afailflight.from << endl;
	fout << " Type aircraft : " << afailflight.aircraft << endl;
	fout << " To : " << afailflight.to << endl;
	fout << " Distance : " << afailflight.distance << endl;
	fout << " Duration : " << afailflight.duration << endl;
	fout << " Pessengers : " << afailflight.pessengers << endl;
	fout << " Time : " << afailflight.time << endl << endl;
	return fout;
}


