#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    std::vector<double> data = {20.1, 20.3, 20.2, 25.0, 20.4, 20.3, 20.2};

    // Medie
    double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();

    // Deviatie standard
    double sum_sq = 0.0;
    for(double val : data) {
        sum_sq += (val - mean) * (val - mean);
    }
    double std_dev = std::sqrt(sum_sq / data.size());

    // Detectare anomalii (> 2 sigma)
    std::cout << "Valori anormale: ";
    for(double val : data) {
        if(std::fabs(val - mean) > 2 * std_dev) {
            std::cout << val << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
