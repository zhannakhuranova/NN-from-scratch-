
#include "traini.h"


int main()
{


	srand ((unsigned) time( NULL) );

	int n;

	std::string filename  = ("/home/pidhii/t/a.txt");
	std::vector <int> datafil;
	std :: ifstream in (filename);

	while (in >> n) {
		datafil.push_back(n); }

	in.close();
	couvctr(datafil);

	int choi;
	std::cout << "( here or fro f... ) ? (0 : 1)" << std::endl;
	std::cin >> choi;

	int sz;
	std::cout << "enter size of array " ;
	std::cin >> sz;

	int valu;
	std::cout << "enter array { " ;
	std::vector <double> inpu;
	std::cout<< "}  " ; 

	if ( choi == 0 ) {
		  for ( int i=0; i<sz; i++) 
		  {    std::cin>> valu;
			inpu.push_back(valu); }}
				

	if (choi == 1) {
		for (int f=0; f<sz; f++) 
		  {
			inpu.push_back(datafil[f]); } }

	
	//couvctr(datafil);
	datafil.erase( datafil.begin(), datafil.begin() + sz);
	couvctr(datafil);


	std::vector <double> wei;

	for (int t=0;t<sz;t++) {  
		wei.push_back(rannum(-4.0, 4.0)); }


	double neuro;
	for ( int i=0; i<sz; i++) {
		  neuro += inpu[i] * wei[i]; }


	double pred_da;
	int ki= 0;

	for (int i=0;i<datafil.size(); i++) {

			if (inpu[i] == datafil.at(i)) {
				ki++;

				if (ki == sz) {
					pred_da = datafil[i + 1]; 
	} }}
				


	std::cout << " Pred data is... " << pred_da<< std::endl;

	std::vector <double> losfu;
	std::vector <double> neurov;
	
	
	neurov.push_back(neuro);

	std::ofstream out;
	out.open("hello.dat");
	out << "Wei" << "				" << "lossfu" << std::endl;


	double neu;


	for (int i=0; i<sz*ite; i++) 
	{

			for ( int j=0; j<sz; j++) {

					actfu(neurov.at(i));
					losfu.push_back( 2*lr*(pred_da - actfu(neurov.at(i)))*(actfu(neurov.at(i)))*(1 - actfu(neurov.at(i))));
					wei.at(j) += losfu.at(i);
					neuro = + wei.at(j) + inpu.at(j);
					out << wei.at(j) << "			" << losfu.at(i) << std::endl;
					//couvctr(wei);  
						}


		
	neurov.push_back(neuro);
	neuro = 0;
		
	out << std :: endl;  

       }

}
