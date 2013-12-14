/*
 *
 */

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	const time_t curr_time = time(0);
	struct tm * time_info;

	time_info = localtime ( &curr_time );
	cout << "Time and date currently: " << asctime(time_info) << endl;

	return 0;
}
