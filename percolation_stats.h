#ifndef Percolation_h
#define Percolation_h

class Percolation {
private:
	int size;
	int **array;
	int top, bottom;
	float probability;
	float count;
	float randrun;
public:
    Percolation(){
	    top = 2;
	    bottom = 11;
    }
	int stats();		//Checks for percolation 1000 times. 
	int matrixdetails();
	int percolates();
	int matrixgen();
	int getprobability();
	int open();
	int cluster();
	int viewMatrix();
};

#endif
