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
	// add covariation and dispersion
	double corr (std::vector<double> a, std::vector<double> b) {
		double mean_a = 0;
		double mean_b = 0;

		for (int i = 0; i < a.size(); i++) {
			mean_a += a[i];
			mean_b += b[i];
		}

		mean_a /= a.size();
		mean_b /= b.size();

		double a_val = 0;
		double b_val = 0;

		for (int i = 0; i < a.size(); i++) {
			a_val += (a[i] - mean_a);
			b_val += (b[i] - mean_b);
		}

		double result = (a_val * b_val) / std::sqrt(a_val * a_val * b_val * b_val);

		return result;
	}
};


int main() 
{
	Solars sl;
	Metrics mt;

	std::string path = "source/data1.csv";

	std::vector<std::vector<double>> result = sl.read_csv(path);

	std::cout << sl.corr(result[1], result[2]);

	return 0;
}