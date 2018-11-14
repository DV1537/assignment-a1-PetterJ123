#include <iostream>
#include <fstream>
#include <string>
/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[]){
	std::ifstream readFile;

	readFile.open("./tests/input.in");	// Opens file in read-mode

	if(!readFile){						// Checks if program can't read file
		std::cout << "Can't open text-file\n";
		exit(EXIT_FAILURE);
	}

	int count;
	int i=0;
	int readInt;
	while(readFile >> readInt){		// Counts the number of integers
		count++;
		i++;
	}

	int* arr = new int[count];

	double sum;
	double average;

	readFile.clear();
	readFile.seekg(0, std::ios::beg);
	for (int i=0; i<count; i++) {
		readFile >> arr[i];
		sum = sum + arr[i];
	}
	average = sum / count;
	std::cout << "Sum is: " << sum << "\n";
	std::cout << "Average is: " << average << "\n";

	for(int i=0; i<count; i++){
		if(average < arr[i]){
			std::cout << arr[i] << " is greater than " << average << "\n";
		}
	}

	delete [] arr;

	return 0;
}
