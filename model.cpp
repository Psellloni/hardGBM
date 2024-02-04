#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>

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

		std::cout << size;

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
};


int main() 
{
	Solars sl;
	Metrics mt;

	std::string path = "source/data1.csv";

	std::vector<std::vector<double>> result = sl.read_csv(path);

	return 0;
}