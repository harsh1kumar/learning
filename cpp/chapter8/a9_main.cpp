/*
 *
 */

#include <iostream>

using namespace std;

int main()
{
	double arr[10] = {0};
	double * const dp = arr;

	//dp++; // Error
	//dp--; // Error

	dp[0] = 1;
	cout << "dp[0] = " << dp[0] << endl;


	return 0;
}
