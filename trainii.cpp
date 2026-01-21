#include "trainii.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Load data
    std::vector<int> datafile;
    std::ifstream file("./a.txt");
    int n;
    while (file >> n) {
        datafile.push_back(n);
    }
    file.close();
    couvctr(datafile, "datafile");

    // Input size
    int sz;
    std::cout << "Enter size of array: ";
    std::cin >> sz;
    assert(sz > 0 && "Vector size must be greater than zero.");

    // Choose input source
    int choi;
    std::cout << "(Read from terminal or file)? (0: terminal, 1: file): ";
    std::cin >> choi;
    assert((choi == 0 || choi == 1) && "Choice must be 0 or 1");

    std::vector<double> input(sz);
    if (choi == 0) {
        std::cout << "Enter array { ";
        for (int i = 0; i < sz; ++i) {
            std::cin >> input[i];
            assert((input[i] == 0 || input[i] == 1) && "Input data must be 0 or 1");
        }
        std::cout << "}";
    } else {
        for (int i = 0; i < sz; ++i) {
            input[i] = datafile[i];
        }
        datafile.erase(datafile.begin(), datafile.begin() + sz);
    }

    // Initialize weights
    std::vector<double> wei(sz);
    for (int t = 0; t < sz; ++t) {
        wei[t] = rannum(-2.0, 2.0);
    }

    // Training
    std::ofstream out("hello.csv");
    out << "Weigh,actual_loss,lossfunction\n";

    for (int epoch = 0; epoch < iter; ++epoch) {
        for (size_t i = 0; i < datafile.size(); ++i) {
            double target = datafile[i];

            // Forward pass
            double z = 0.0;
            for (int j = 0; j < sz; ++j) {
                z += input[j] * wei[j];
            }
            double pred = actfu(z);
            double error = target - pred;
            double loss = error * error;

            // Backward pass (gradient)
            double delta = error * pred * (1 - pred);  // dL/dz
            for (int j = 0; j < sz; ++j) {
                double gradient = delta * input[j];
                wei[j] += lr * gradient;  // Update weight
                out << wei[j] << "," << loss << "," << gradient << "\n";
            }
        }
        out << "\n";  // Epoch separator
    }
    out.close();

    std::cout << "Training complete.\n";
    couvctr(wei, "Final Weights");
    return 0;
}
