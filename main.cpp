#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

bool writeInFile(char* fileName) {
	ofstream output(fileName, ios::app);

	if (output) {
		char buff[100];
		cin.getline(buff, 100);
		for (int i = 0; i < 5; i++) {
			output << buff << endl;
		}

		return true;
	}
	else {
		return false;
	}

	output.close();
}

bool readFromFile(char* fileName) {
	ifstream input(fileName);

	if (input) {
		
		char buffer[100];

		while (!input.eof()) {
			buffer[0] = '\0';
			input.getline(buffer, 100);
			cout << buffer << endl;
		}

		return true;
	}
	else {
		return false;
	}

	input.close();
}

int main() {
	//fstream stream("asdasd.txt", ios::in); //samo mojem da chetem, vupreki che e fstream i po default ima in | out
	//ifstream stream1("asdasd1.txt", ios::out); //greshka! nqma metod za <<
	//ofstream stream2("asdasd2.tst")
	
	fstream file("practice.txt", ios::in | ios::out | ios::trunc);

	writeInFile("practice.txt");
	readFromFile("practice.txt");

	cout << "Do you want to delete the file:: Yes || No " << endl;
	char answer[5];
	cin.getline(answer, 5);

	if (strcmp(answer, "Yes")) {
		file.trunc;
	}
	else {
		cout << "You kept the file." << endl;
	}


	///*
	//	tellg - dava ukazatelq na tekushtata poziciq
	//*/
	//ifstream input;
	//streampos current = input.tellg(); //dava ni tekushtata poziciq
	//current += 20; // kazva na ukazatelq da otide 20 simvola napred.
	
	//ifstream i1("....txt", ios::ate)
	//i1.seekg(end);

	//input.seekg(current); //tursi okazanata poziciq
	//input.seekg(ios::end); //otiva nakraq na faila
	//streampos end = input.tellg();

	return 0;
}