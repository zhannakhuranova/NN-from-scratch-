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

typedef std::vector<double> v;
inline double lr = 0.3;
inline int iter = 50;   

double actfu(double n) {
	return (1 / ( 1 + exp(-n))); }    // sigmoid activation function

float rannum(float Min, float Max) {
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;}

template <typename T>
void couvctr( std::vector<T> &v, const char* name) {
	assert(!v.empty() && "Vector size size must be greater than zero.");
	std::cout<<name<<" { ";
		for(const auto &i : v){
			std::cout<<i<<' ';}
	std:: cout <<"}"<<std :: endl;}

template <typename T>
void couvctrow( std::vector<T> &v, const char* name) {
	assert(!v.empty() && "Vector size size must be greater than zero.");
	std::cout<< name<<" { ";
		for(const auto &i : v){
			std::cout<<i<<' '<<std::endl;}
	std:: cout << "}"<<std :: endl;}

#endif

