/*
 * 
 */

#include "a8_class.h"
#include <iostream>

using namespace std;

void Dummy::show_map()
{
	cout << "\tName\t\t:\tAddress\n\n";
	
	cout << "\ti_1_pub\t\t:\t" << &i_1_pub << endl;
	cout << "\tc_2_pub\t\t:\t" << reinterpret_cast<void *>(&c_2_pub) << endl;
	cout << "\ti_3_pri\t\t:\t" << &i_3_pri << endl;
	cout << "\tc_4_pri\t\t:\t" << reinterpret_cast<void *>(&c_4_pri) << endl;
	cout << "\tf_5_pro\t\t:\t" << &f_5_pro << endl;
	cout << "\td_6_pro\t\t:\t" << &d_6_pro << endl;
	cout << "\ti_7_pri\t\t:\t" << &i_7_pri << endl;
	cout << "\tc_8_pub\t\t:\t" << reinterpret_cast<void *>(&c_8_pub) << endl;
	cout << "\ti_9_pub\t\t:\t" << &i_9_pub << endl;
	cout << "\td_10_pro\t:\t" << &d_10_pro << endl;
	cout << "\tf_11_pro\t:\t" << &f_11_pro << endl;
	cout << "\tf_12_pri\t:\t" << &f_12_pri << "\n\n";
}
