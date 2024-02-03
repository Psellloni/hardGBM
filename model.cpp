#include<iostream>
#include<vector>

double mse(std::vector<int> a, std::vector<int> b) {

	double result = 0;

	for (int i = 0; i < a.size(); i ++) {
		result += ((a[i] - b[i]) * (a[i] - b[i]));
	}
	
	result /= a.size();

	return result;
}

int main() 
{
	std::vector<int> v1 = {1, 2, 3};
	std::vector<int> v2 = {1, 2, 3};

	double res = mse(v1, v2);

	std::cout << res;
	
	
	return 0;
}