#include<iostream>
#include<cstdlib>
//#include<ctime>
#include<time.h>
#include"percolation_stats.h"
using namespace std;

int main() {
	srand((int)time(0));
	Percolation test;
	test.stats();
	return 0;
}
