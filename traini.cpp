
#include "traini.h"


int main()
{
	srand ((unsigned) time( NULL) ); //for rand

	int n=0;
    
	std::string filename  = ("$HOME$/a.txt"); // read classification approaches
	if(filename) // by default you have a file with classification data
	{
    	std::vector <int> datafile;
		std :: ifstream file (filename);
	
		while (file >> n) {
			datafile.push_back(n);
		}
	}
	file.close();
	couvctr(datafile);  //
// sz - size of input data vector 
	int sz = 0;
	std::cout << "enter size of array " ;
	std::cin >> sz; // size here corresponding to data type is be only 3, but you could change a.txt file for your data size

	int choi=0;
	std::cout << "( Read data from terminal or from file ) ? (0 : 1)" << std::endl; // 0 from terminal
	std::cin >> choi;
	//feed the data 
	std::cout << "enter array { " ;
	std::cout << "}  " ;
	int valu;
	std::vector <double> inpu;
	if ( choi == 0 )//0 from terminal
	{
		for ( int i = 0; i < sz; i++)
		{	std::cin >> valu;
			inpu.push_back(valu);
		}
	}

	if (choi == 1) //1 from file
	{
		for (int i = 0; i < sz; i++) {
			inpu.push_back(datafile[i]);
		}
	}

	//couvctr(datafile);
	datafile.erase( datafile.begin(), datafile.begin() + sz); // 
	couvctr(datafile); // cout marix of the data

	std::vector <double> wei;
// tread weigh vector with random values in a range -4:4 because of sigmoid activation function 
	for (int t = 0; t < sz; t++) {
		wei.push_back(rannum(-4.0, 4.0));
	}
//treat neuron with inputdata and weigh
	double neuro=0.0;
	for ( int i = 0; i < sz; i++) {
		neuro += inpu[i] * wei[i];
	}
//read data classification predicted data pred_da
	double pred_da; // predicted data
	int ki = 0;

	for (int i = 0; i < datafile.size(); i++) {
		if (inpu[i] == datafile.at(i)) {
			ki++;
			if (ki == sz && i+1< datafile.size()) {
				pred_da = datafile[i + 1];
			}
		}
	}

	std::cout << " Predicted data is... " << pred_da << std::endl;
//create loss function and neuro vector neurov
	std::vector <double> losfu;
	std::vector <double> neurov; // vector of neurons

	neurov.push_back(neuro);
//creat and write results in a hello.dat file 
	std::ofstream out;
	out.open("hello.dat");
	out << "Weigh" << "				" << "lossfuction" << std::endl;

	double neu;
	//ite is a number of iteration in a .h file
	
	for (int i = 0; i < sz * ite; i++)
	{

		for ( int j = 0; j < sz; j++) {

			actfu(neurov.at(i));
			losfu.push_back( 2 * lr * (pred_da - actfu(neurov.at(i))) * (actfu(neurov.at(i))) * (1 - actfu(neurov.at(i))));
			wei.at(j) += losfu.at(i);
			neuro +=  wei.at(j) + inpu.at(j);
			out << wei.at(j) << "			" << losfu.at(i) << std::endl;
			//couvctr(wei);
		}

		neurov.push_back(neuro);
		neuro = 0;

		out << std :: endl;
	}
out.clode();
return 0;
}
