/*
 * main.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *      Driver program for testing my astronomy structures
 *
 *
 *
 */

#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

#include "calendar.h"
//#include "PrintUsage.h"
//#include "ParseOptarg.h"



// driver code
int main(int argc, char *argv[])
{

	bool	verbose = false, timeSupplied = false, dateSupplied = false;
	int		year, month, day, hour, minute, second, timezone, dst;
	double	lat, lon;



	//
	//	getopt variables
	//
	int		c, optionIndex;


	//	TODO Add proper switches as the projects goes along
	char	*shortOptions = (char*)"d:t:vh";
	struct option	longOptions[] = {
					{"date",	required_argument,	NULL,	'd'},
					{"time",	required_argument,	NULL,	't'},
					{"tz",		required_argument,	NULL,	3},
					{"lat",		required_argument,	NULL,	4},
					{"lon",		required_argument,	NULL,	5},
					{"dst",		required_argument,	NULL,	6},
					{"verbose",	no_argument,		NULL,	'v'},
					{"help",	no_argument,		NULL,	'h'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	//	Initialise command line variables to some default values, should the user fail to provide...
	//	This is for development purpose only, not to enter production code.
	//year		= 2024;
	//month		= 1;
	//day			= 21;
	//hour		= 12;
	//minute		= 0;
	//second		= 0;
	timezone	= 1;
	lat			= 78.92927;	//	Ny-Ålesund
	lon			= 11.86778;	//	Ny-Ålesund
	//lat			= 64.6806667;	//	Oppi Leite
	//lon			= 11.2914444;	//	Oppi Leite
	dst			= 0;



	//
	//	getopt() switch statement
	//
	//	TODO Implement a proper help-screen for the user
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'd':	{
							year = atoi(optarg);
							//cout << "optarg: " << optarg << endl;
							//cout << "Year: " << year << endl;
							ParseOptarg(&optarg);
							month = atoi(optarg);
							//cout << "Month: " << month << endl;
							ParseOptarg(&optarg);
							day = atoi(optarg);
							dateSupplied = true;

							break;
						}
			case 't':	{
							hour = atoi(optarg);
							ParseOptarg(&optarg);
							minute = atoi(optarg);
							ParseOptarg(&optarg);
							second = atoi(optarg);
							// end of parsing optarg
							timeSupplied = true;

							break;
						}
			case 'v':	{
							verbose = true;
							break;
						}
			case 'h':	{
							PrintUsage();
							exit(1);
						}
			default:	{
							cout << "Switch default - we shouldn't be here :-)\n" << endl;
							break;
						}
		} // switch(c)
	} // while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1)

	if(!dateSupplied){

		cout << "Date not supplied, using system date..." << endl;

		time_t current = time(NULL);
		struct tm* current_s = localtime(&current);

		day		= current_s->tm_mday;
		month	= ++current_s->tm_mon;
		year	= 1900 + current_s->tm_year;

	} // if(!dateSupplied)

	if(!timeSupplied){

			cout << "Time not supplied, using system time..." << endl;

			time_t current = time(NULL);
			struct tm* current_s = localtime(&current);

			hour	= current_s->tm_hour;
			minute	= current_s->tm_min;
			second	= current_s->tm_sec;

	} // if(!timeSupplied)



	if(verbose){
		cout << "Day: " << day << ", month: " << month << ", year: " << year << endl;

		// Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
		// Used in conjunction with setw() and setprecision()
		// << setw(2) << setfill('0') <<
		cout.setf(ios::fixed);

		cout << "Time: " << setw(2) << setfill ('0') << hour
			 << ":" << setw(2) << setfill ('0') << minute
			 << ":" << setw(2) << setfill ('0') << second << endl;
	}

	//JulianDay(int _year, short _month, short _day, short _hour, short _minute, short _second, short _tz, bool _verbose)
	JulianDay *jd = new JulianDay(year, month, day, hour, minute, second, timezone, verbose);

	return 0;
}	//	int main(int argc, char *argv[])








