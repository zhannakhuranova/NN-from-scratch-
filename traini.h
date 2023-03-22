
Skip to content
Pull requests
Issues
Codespaces
Marketplace
Explore
@zhannakhuranova
zhannakhuranova /
neural - network - from - scratch -
Public

Cannot fork because you own this repository and are not a member of any organizations.

Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights

Settings

neural - network - from - scratch - / traini.h
@zhannakhuranova
zhannakhuranova Update traini.h
Latest commit 9378444 Nov 15, 2022
History
1 contributor
42 lines (29 sloc) 845 Bytes

#ifndef TRAINI_H
#define TRAINI_H


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>
#include <time.h>
#include <stddef.h>


double lr = 0.3; // learning rate opt
int ite = 50;

#define gnmvl( val ) print_vector( val, #val )
template <typename F>
void pri_vec (const std::vector<double> v, const char *name) {
	std::cout << name << " : { " ;
	for ( auto i : v) {
		std::cout << v[i] << ' ';
	}
	std ::cout << "}" << std::endl;
};

double actfu(double n) {
	return (1 / ( 1 + exp(-n)));
}    // sigmoid act

float rannum(float Min, float Max) {
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

template <typename T>
void couvctr( std::vector<T> &v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << ' ';
	}
	std:: cout << std :: endl;
};


#endif
