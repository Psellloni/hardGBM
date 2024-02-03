#include<iostream>
#include<vector>

class Metrics {
public:
	double mse(std::vector<int> a, std::vector<int> b) {

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

	double mae(std::vector<int> a, std::vector<int> b) {

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

int main() 
{
	std::vector<int> v1 = {1, 1, 1, 1, 1};
	std::vector<int> v2 = {1, 2, 1, 1, 1};

	Metrics metric;

	double res = metric.mae(v1, v2);

	std::cout << res;
	
	
	return 0;
}