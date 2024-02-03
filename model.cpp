#include <iostream>
#include <string>
#include <vector>
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
	Metrics mt;
	Solars sl;

	std::vector<std::vector<double>> df = sl.read_txt("data1.txt");

	std::cout << mt.mse(df[0], df[1]);

	return 0;
}