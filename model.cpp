#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

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
	std::vector<std::vector<double>> read_txt (std::string path) {
		std::vector<double> d1 = {};
		std::vector<double> d2 = {};
		
		std::ifstream myfile;
    		myfile.open("data1.txt");
	
		float a, b;
		while (myfile >> a >> b) {
    			d1.push_back(a);
			d2.push_back(b);
		}

		std::vector<std::vector<double>> result = {};
		
		result.push_back(d1);
		result.push_back(d2);

		return result;

	}
};


int main() 
{
	std::ifstream myfile;
    	myfile.open("data1.txt");
	std::string line;

	while(std::getline(myfile, line)) {
		std::cout << line << std::endl;
	}
	
	return 0;
}