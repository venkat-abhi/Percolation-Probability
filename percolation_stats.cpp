#include"percolation_stats.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
using namespace std;
int Percolation::matrixdetails() {
	cout << "Enter the size of the matrix: ";         //square matrix (enter sqrt(order of matrix))
	cin >> size;
	cin.ignore();
	array = new int*[size];
	for (int i = 0; i<size; i++) {
		array[i] = new int[size];
	}
	return 0;
}

int Percolation::stats() {
	count = 0;
	matrixdetails();
	getprobability();
	clock_t t;
	t = clock();
	for (int i = 0; i < 1000; i++) {
		matrixgen();
		open();
		cluster();
		//viewMatrix();                 //Uncomment this line if you want to see the matrix after each iteration
		percolates();
		bottom = 11;
	}
	//cout << count;
	float percolation_probability = (float)count / 1000;
	cout << "The probability of the system to percolate is: " << percolation_probability;
	t = clock() - t;
	cout << "\nThe execution time is: " << (float)t / CLOCKS_PER_SEC;
	return 0;
}

int Percolation::getprobability() {
	cout << "Enter the probabilitiy of a site being open: ";
	cin >> probability;
	cin.ignore();
	cout << "\n";
	return 0;
}

int Percolation::percolates() {
	if (bottom == top) {
		//cout<<"The system percolates.";
		count += 1;
	}
	/*else{
	cout<<"The system does not percolate.";
	}*/
	return 0;
}

int Percolation::cluster() {
	bool changes = false;
	for (int run = 0; run <= size; run++) {
		for (int i = 0; i<size; i++) {                      //checks top border
			if (array[0][i] == 1) {
				array[0][i] = top;
				changes = true;
			}
		}
		for (int i = 1; i<size - 1; i++) {                      //checks lattice excluding the boundaries
			for (int j = 1; j<size - 1; j++) {
				if (array[i][j] == 1) {
					if (array[i + 1][j] == top) {
						array[i][j] = top;
						changes = true;
					}
					if (array[i - 1][j] == top) {
						array[i][j] = top;
						changes = true;
					}
					if (array[i][j - 1] == top) {
						array[i][j] = top;
						changes = true;
					}
					if (array[i][j + 1] == top) {
						array[i][j] = top;
						changes = true;
					}
				}
			}
		}

		for (int i = 1; i<size - 1; i++) {                  //checks left border
			if (array[i][0] == 1) {
				if (array[i + 1][0] == top) {
					array[i][0] = top;
					changes = true;
				}
				if (array[i - 1][0] == top) {
					array[i][0] = top;
					changes = true;
				}
				if (array[i][1] == top) {
					array[i][0] = top;
					changes = true;
				}
			}
		}

		for (int i = 1; i<size - 1; i++) {                  //checks right border
			if (array[i][size - 1] == 1) {
				if (array[i + 1][size - 1] == top) {
					array[i][size - 1] = top;
					changes = true;
				}
				if (array[i - 1][size - 1] == top) {
					array[i][size - 1] = top;
					changes = true;
				}
				if (array[i][size - 2] == top) {
					array[i][size - 1] = top;
					changes = true;
				}
			}
		}

		for (int i = 0; i<size; i++) {                      //checks elements of bottom border
			if (array[size - 1][i] == 1) {
				if (array[size - 2][i] == top) {
					array[size - 1][i] = top;
					bottom = top;
					return 0;
				}
			}
		}
		if (changes == true) {
			continue;
		}
		else {
			break;
		}
	}
	return 0;
}

int Percolation::open() {
	randrun = count / 100000;
	for (int i = 0; i<size; i++) {
		for (int j = 0; j<size; j++) {
			float random = (float)(((rand() % 10)*0.1) + randrun);
			if (random < probability) {
				array[i][j] = 1;
			}
		}
	}
	return 0;
}

int Percolation::viewMatrix() {
	cout << "\n";
	for (int i = 0; i<size; i++) {
		for (int j = 0; j<size; j++) {
			cout << array[i][j];
		}
		cout << "\n";
	}
	return 0;
}

int Percolation::matrixgen() {
	for (int i = 0; i<size; i++) {
		for (int j = 0; j<size; j++) {
			array[i][j] = 0;
		}
	}
	return 0;
}
