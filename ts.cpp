/*
 * cal.cpp
 *
 *  Created on: 27 May 2024
 *      Author: jole
 *
 *      Driver program for testing calendar class
 *
 *
 *
 */

// Needed for getopt
#include <iostream>
#include <getopt.h>
//******************

//#include <iomanip>
//#include <locale.h>
//#include <time.h>
//#include <sys/time.h>


#include "timestamp.h"



// driver code
int main(int argc, char *argv[])
{

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




	//
	//	getopt() switch statement
	//
	//	TODO Implement a proper help-screen for the user
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'h':	{
							//PrintUsage();
							exit(1);
						}
			default:	{
							std::cout << "Switch default - Je ne sais quoi" << std::endl;
							break;
						}
		} // switch(c)
	} // while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1)


	return 0;
}	//	int main(int argc, char *argv[])








