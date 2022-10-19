#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <cmath>
#include <string>
#include <list> 

//#include "gnuplot-iostream.h"
//
#include <stddef.h>
/*
#include"TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TRint.h"
*/


#define getNameandValues( val ) print_vector( val, #val )
template <typename F>
void print_vector (const std::vector<double> v, const char *name){

std::cout<< name << " : { " ;

	for ( auto i : v) {
		std::cout<< v[i]<<' '; }
		std ::cout <<"}" << std::endl; 
};


double actfun(double n) {
	return (1 / ( 1 + exp(-n)));}


double activfunc_threshold (double arg) {
	return (arg <= 0) ?  0 : 1;}


float RandomNumber(float Min, float Max) {
	return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;}



template <typename T>
void cout_vector ( std::vector<T> &v) {

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << ' ';}

	std:: cout << std :: endl;};



double LR = 0.3;
int iter = 50;


int main()
{

	srand( (unsigned) time( NULL) );

	int n;

	std::string filename  = ("/home/pidhii/t/a.txt");
	std::vector <int> datafile;
	std :: ifstream in (filename);

	while (in >> n) {
		datafile.push_back(n);
	}

	in.close();
	cout_vector(datafile);


	int choise;
	std::cout << "( array <- array from file) ? (1 : 2)" << std::endl;
	std::cin >> choise;

	int size ;
	std::cout << "Enter size of array " ; // 
	std::cin >> size; // size for a.txt file shoulb be 3
	int value;
	std::cout << "Enter array" ;

	std::vector <double> Inputs;



	if ( choise == 1 ) // take Inputs from terminal
	{
		for ( int i = 0 ; i < size ; i++)
		{
			std :: cin >> value;
			Inputs.push_back(value);
		}
	}


	if (choise == 2) {
		for (int k = 0; k < size; k++) {
			Inputs.push_back(datafile[k]);
		}
	}
	
	
	cout_vector(datafile);
	datafile.erase(datafile.begin(), datafile.begin() + size);
	cout_vector(datafile);

	std::vector <double> Weigh;
	for (int i = 0 ; i < size; i++) { // input_size
		Weigh.push_back (RandomNumber(-4.0,4));	}  // only for 1 0 0  data type, for other need to recalculate


	double neuro;
	for ( int i = 0; i < size; i++) {
		neuro += Inputs[i]*Weigh[i];	}


	double pred_data;
	int k = 0;
	for (int i = 0; i < datafile.size(); i++) {

		if (Inputs[i] == datafile[i]) {
			k++;

			if (k == size) {
				pred_data = datafile[i + 1];	}	}}
				

	std::cout << " Predicted data " << pred_data << std::endl;

	std:: vector <double> lossfunc ;
	std::vector<double> neuro_v;
	neuro_v.push_back(neuro);

	std::ofstream out;
	out.open("hello1.dat");
	out << "Weigh" << "  " << "lossfunc" << std::endl;


	double neuron ;
	int step = 1 / size;

	for (int i = 0; i < size * iter; i++) {

		for ( int j = 0; j < size; j++) {

			actfun(neuro_v[i]);

			lossfunc.push_back(2 * LR * (pred_data - actfun(neuro_v[i])) * (actfun(neuro_v[i])) * (1 - actfun(neuro_v[i])));
			Weigh[j] += lossfunc[i];
			neuron = + Weigh[j] + Inputs[j];
			out << Weigh[j] << " " << lossfunc[i] << std::endl;
			cout_vector(Weigh);
		}


		neuro_v.push_back(neuron);
		neuron = 0;

		out << std :: endl;

	}

	std :: cout << "Weigh.size() - " << Weigh.size() << std::endl;


/*

`	Gnuplot gr;

	gr << "set title 'Graph of Loss func(Weigh)'\n";
	gr << "set xrange [-1:6]\nset yrange [-1:1]\n";

	gr << "plot '-' with lines title'Weighout',"	
	<< "'-' with lines title 'lossfunc_out'\n";

	gr.send(Weigh);
	gr.send(lossfunc);


	std ::cin.get();*/

}
