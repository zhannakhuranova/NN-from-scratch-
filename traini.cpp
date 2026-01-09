
#include "traini.h"


int main()
{
	srand ((unsigned) time( NULL) );

	int n;

	std::string filename  = ("$HOME$/a.txt");
	std::vector <int> datafile;
	std :: ifstream in (filename);

	while (in >> n) {
		datafile.push_back(n);
	}

	in.close();
	couvctr(datafile);

	int sz;
	std::cout << "enter size of array " ;
	std::cin >> sz; // size here corresponding to data type is be only 3, but you could change a.txt file for your data size

	int choi;
	std::cout << "( Read data from terminal or from file ) ? (0 : 1)" << std::endl;
	std::cin >> choi;

	int valu;
	std::cout << "enter array { " ;
	std::vector <double> inpu;
	std::cout << "}  " ;

	if ( choi == 0 )
	{
		for ( int i = 0; i < sz; i++)
		{	std::cin >> valu;
			inpu.push_back(valu);
		}
	}

	if (choi == 1)
	{
		for (int f = 0; f < sz; f++) {
			inpu.push_back(datafile[f]);
		}
	}

	//couvctr(datafile);
	datafile.erase( datafile.begin(), datafile.begin() + sz);
	couvctr(datafile); // cout marix of the data

	std::vector <double> wei;

	for (int t = 0; t < sz; t++) {
		wei.push_back(rannum(-4.0, 4.0));
	}

	double neuro=0.0;
	for ( int i = 0; i < sz; i++) {
		neuro += inpu[i] * wei[i];
	}

	double pred_da; // predicted data
	int ki = 0;

	for (int i = 0; i < datafile.size(); i++) {

		if (inpu[i] == datafile.at(i)) {
			ki++;

			if (ki == sz) {
				pred_da = datafile[i + 1];
					
			}
		}
	}

	std::cout << " Predicted data is... " << pred_da << std::endl;

	std::vector <double> losfu;
	std::vector <double> neurov; // vector of neurons

	neurov.push_back(neuro);

	std::ofstream out;
	out.open("hello.dat");
	out << "Weigh" << "				" << "lossfuction" << std::endl;

	double neu;
	
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

}
