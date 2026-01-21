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
#include <cassert>

double lr = 0.01; // learning rate opt
int iter = 60;

typedef std::vector<double> v;


double actfu(double n) {
	return (1 / ( 1 + exp(-n)));
}    // sigmoid ac

float rannum(float Min, float Max) {
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

//print func line print
template <typename T>
void couvctr( std::vector<T> &v, const char* name) {
	if(!v.empty()) { std::cout<<"EMPTY VECTOR"<<std::endl;}
	std::cout<< name<<" { ";
		for(const auto &i : v){
			std::cout<<i<<' ';}
	std:: cout << "}"<<std :: endl;
}


template <typename T>
void gnmvl(std::vector<T>& vec) {
    couvctr(vec, "vec");
}

template <typename T>
void couvctrow( std::vector<T> &v, const char* name) {
	assert(!v.empty() && "Vector size size must be greater than zero.");
	std::cout<< name<<" { ";
		for(const auto &i : v){
			std::cout<<i<<' '<<std::endl;}
	std:: cout << "}"<<std :: endl;
}
#endif
