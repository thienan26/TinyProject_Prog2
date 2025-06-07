#include "LinearRegression.h"
#include <iostream>
using namespace std;

int main() {
    LinearRegression regression;
    string filename = "machine.txt";
    readData(regression, filename);
    cout << "Starting training...." << endl;
    regression.splitData();          // 80/20 train-test split
    regression.train(5000, 1e-3, 5);  // epochs, learning rate, batch size
    cout << "Training complete." << endl;
    cout << "Inference on test set:" << endl;
    const vector<pair<double,double>>& predictions = regression.infer();
    for (size_t i = 0; i < predictions.size(); ++i) {
        cout << "Pred and GT for sample " << i + 1 << ": " << predictions[i].first << " " << predictions[i].second << endl;
    }

    cout << "Weights: ";
    const vector<double>& weights = regression.getWeights();
    for (const auto& w : weights) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}