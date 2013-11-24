#ifndef A8_CLASS_H
#define A8_CLASS_H

class Dummy
{
public:
	int i_1_pub;
	char c_2_pub;

private:
	int i_3_pri;
	char c_4_pri;

protected:
	float f_5_pro;
	double d_6_pro;

private:
	int i_7_pri;

public:
	char c_8_pub;
	int i_9_pub;

protected:
	double d_10_pro;
	float f_11_pro;

private:
	float f_12_pri;
	

public:
	void show_map();

};

#endif // A8_CLASS_H
