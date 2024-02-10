#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

class Metrics {
public:
	double mse(std::vector<double> a, std::vector<double> b) {

		if (a.size() != b.size()) {
			return -1;
		}

		double result = 0;

		for (int i = 0; i < a.size(); i ++) {
			result += ((a[i] - b[i]) * (a[i] - b[i]));
		}
	
		result /= a.size();

		return result;

		}

	double mae(std::vector<double> a, std::vector<double> b) {

		if (a.size() != b.size()) {
			return -1;
		}

		double result = 0;

		for (int i = 0; i < a.size(); i ++) {
			result += abs(a[i] - b[i]);
		}
	
		result /= a.size();

		return result;

		}
};

class Solars {
public:
	std::vector<std::vector<double>> read_csv (std::string path) {
		std::vector<std::vector<double>> result(3);
	
		std::ifstream myfile;
    		myfile.open(path);

		int size = 0;
		std::string line;

		while(std::getline(myfile, line)) {
			size ++;
		}

		myfile.close();
		myfile.open(path);

		std::getline(myfile, line);
		
		std::vector<double> vec(50000);
		result.push_back(vec);

		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ',') {
				std::vector<double> vec(50000);
				result.push_back(vec);
			}
		}

		while(std::getline(myfile, line)) {
			int sp = 0;
			int c = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == ';') {
					result[c].push_back(std::stod(line.substr(sp, i - sp)));
					sp = i + 1;
					c += 1;
				}
			}
			result[c].push_back(std::stod(line.substr(sp).c_str()));
		}

		return result;

	}

	double mean(std::vector<double> v) {
    		double sum = 0.0;
    		for (auto& i : v) {
        		sum += i;
    		}
    		return sum / v.size();
	}

	double cov (std::vector<double> a, std::vector<double> b) {
		double sum = 0.0;

    		double mean_a = mean(a);
    		double mean_b = mean(b);

		if (a.size() != b.size()) {
        		return 0.0;
    		}

    		for (int i = 0; i < a.size(); i++) {
        		sum += (a[i] - mean_a) * (b[i] - mean_b);
    		}

    		return sum / (a.size() - 1);
	}

	double variance(std::vector<double> a) {
    		double mean_a = mean(a);
    		double sum = 0.0;

    		for (int i = 0; i < a.size(); i++) {
        		sum += (a[i] - mean_a) * (a[i] - mean_a);
    		}

    		return sum / (a.size() - 1);
	}

	double stdDev(std::vector<double> a) {
    		return sqrt(variance(a));
	}

	double corr (std::vector<double> a, std::vector<double> b) {
		double cov_ab = cov(a, b);
    		double stdDev_a = stdDev(a);
    		double stdDev_b = stdDev(b);

		return cov_ab / (stdDev_a * stdDev_b);
	}
};

class DecisionTreeRegressor {
public:
	double mean;
	
	void fit (std::vector<std::vector<double>> x, std::vector<double> y) {
		for (int i = 0; i < y.size(); i++) {
			mean += y[i];
		}

		mean /= y.size();
	}

	std::vector<double> predict (std::vector<std::vector<double>> x) {
		std::vector<double> prediction(x[0].size(), mean);

		return prediction;
	}
};


int main() 
{
	Solars sl;
	Metrics mt;
	DecisionTreeRegressor dtr;

	std::string path = "source/data1.csv";

	std::vector<std::vector<double>> result = sl.read_csv(path);

	/* std::vector<double> y = result[1];

	result.erase(result.begin() + 1);

	double mean = dtr.fit(result, y);

	std::cout << mean;

	std::vector<double> y_pred = dtr.predict(result);

	std::cout << std::round(mt.mae(y_pred, y));*/

	// std::cout << sl.corr(result[0], result[1]);


	return 0;
}