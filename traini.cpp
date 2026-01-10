
#include "traini.h"
#include <cassert>

int main()
{
	srand ((unsigned) time( NULL) ); //for rand

	int n = 0;

	std::string filename  = ("/Users/zhannabananna/Desktop/neuro/a.txt"); // read classification approaches

    std::vector <int> datafile;
		std:: ifstream file (filename);

		while (file >> n) {
			datafile.push_back(n);
		}

  couvctr(datafile,"datafile");  // cout function in header for vector within the name print

	file.close();


// sz - size of input data vector
	int sz = 0;
	std::cout << "enter size of array " ;
	std::cin >> sz; // size here corresponding to data type is be only 3, but you could change a.txt file for your data size
  assert(sz > 0 && "Vector size size must be greater than zero.");

	int choi = 0;
	std::cout << "( Read data from terminal or from file ) ? (0 : 1)" << std::endl; // 0 from terminal
	std::cin >> choi;
  assert(choi ==  0 || choi == 1  && " Choi coresponding to the 1 or 0");
	//insert the data
	int valu = 0;
	std::vector <double> input;
	if ( choi == 0 )//0 from terminal
	{
		std::cout << "enter array { " ;
		for ( int i = 0; i < sz; i++)
			 {	std::cin >> valu;
				// if(valu)
		  	input.push_back(valu);
				assert(valu ==  0 || valu == 1  && "Input data coresponding to the 1 or 0");
				assert(input.size() <= sz  && "Vector size size must sz.");
           if(input.size()==sz){ std::cout << "}" ;};
	    	}

	}

	if (choi == 1) //1 - read from the file
	{
		for (int i = 0; i < sz; i++) {
			input.push_back(datafile[i]);
		}
	}

	//couvctr(datafile);
	datafile.erase(datafile.begin(), datafile.begin() + sz); //
  //couvctr(datafile); // cout marix of the data

	std::vector <double> wei;
 // treat weigh vector with random values in a range -4:4 (because of sigmoid activation function)
	for (int t = 0; t < sz; t++) {
		wei.push_back(rannum(-4.0, 4.0));	}

//treat neuron with inputdata*weigh
	double neuro = 0.0;
	for ( int i = 0; i < sz; i++) {
		neuro += input[i] * wei[i];}
		std::vector <double> neurov;
		neurov.push_back(neuro);

//
// example 0001 -> 000 predicted data corresponds to label 1
	double pred_data; // predicted data
	v pred_data_vec; // predicted data
	int ki = 0; //datafile iterator
	for (int i = 0; i < datafile.size(); i++) {
		if (input[i] == datafile.at(i)) {
			ki++;
			  if (ki == sz && i+1 < datafile.size()) { // if ki as much as a vector size create pred_data
				   pred_data= datafile[i + 1];
					 pred_data_vec.push_back(pred_data);
			}
		}
	}
	std::cout << " Predicted data is... " << pred_data << std::endl;

//create loss function and neurons vector
	std::vector <double> losfu;

//create and write results in a hello.cvs file
	std::ofstream out;
	out.open("hello.csv");
	out << "Weigh"<<"			    	"<<"actual_loss"<<"       "<<"lossfunction"<< std::endl;

  double neu = 0.0;
  double predictions = 0.0;
  double actual_loss = 0.0;
	v actual_loss_vec;
////iter - number of iteration
//epoch sz*iter
	for (int i = 0; i < sz * iter; i++){
		for ( int j = 0; j < sz; j++) {

			actfu(neurov.at(i)); //treat activation function with neuron value
			predictions =	actfu( neurov.at(i) );
			actual_loss = pow( pred_data - predictions,2 );// loss function
			actual_loss_vec.push_back(actual_loss);
			losfu.push_back( 2 * lr * ( pred_data - actfu(neurov.at(i))) * (actfu(neurov.at(i))) * (1 - actfu(neurov.at(i))) );//gradient
			wei.at(j) += losfu.at(i); //weight changes
			neuro +=  wei.at(j) + input.at(j); // neu neuron
			out << wei.at(j) << "," << actual_loss << "," << losfu.at(i) << std::endl;
		}

		neurov.push_back(neuro); //vector of neuron
		neuro = 0; //clean neuro var
		out << std :: endl;

	}
couvctrow( actual_loss_vec, "actual_loss_vec");
out.close();
return 0;
}
