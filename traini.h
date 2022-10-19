
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


double lr = 0.3;
int ite = 50;
 
#define gnmvl( val ) print_vector( val, #val )
template <typename F>
void pri_vec (const std::vector<double> v, const char *name){
std::cout<< name << " : { " ;
		for ( auto i : v) {
			std::cout<< v[i]<<' '; }
			std ::cout <<"}" << std::endl; };

double actfu(double n) {
		return (1 / ( 1 + exp(-n)));} // sigmoid 

float rannum(float Min, float Max) {
		return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;}

template <typename T>
void couvctr( std::vector<T> &v) {
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << ' ';}
		std:: cout << std :: endl;};

template <typename T>
void couvctr_( std::vector<T> &v) {
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << ' ';}
		};


#endif


