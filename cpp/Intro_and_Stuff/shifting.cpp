#include <iostream>

using namespace std;

void printBinary(const unsigned char val) {
  for(int i = 7; i >= 0; i--)
    if(val & (1 << i))
      std::cout << "1";
    else
      std::cout << "0";
}

int main()
{
	unsigned int a;
	cout<<"1 left shift by 1 = "<< endl;
	printBinary(1<<1);
	cout<<"\n3 left shift by 2 = " <<endl;
	printBinary(3<<2);
	cout<<"\n7 right shift by 1 = "<<endl;
	printBinary(7>>1);
	cout<<endl;
}
