#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class City {
	char* name;
	int population;

	void removeCity() {
		delete name;
		name = nullptr;
	}

public:

	City(char* _name = NULL, int _population = 0) {
		setName(_name);
		population = _population;

	}

	void setName(char* newName) {
		if (name != nullptr) {
			removeCity();
		}

		int length = strlen(newName) + 1;
		name = new char[length];
		strcpy(name, newName);
	}

	const char* getName() const { return name; }
	int getPopulation() const { return population; }

	~City() {
		removeCity();
	}
};

void writeToBin(City* city, int numOfCities, char* fileName) {
	ofstream myFile(fileName, ios::out | ios::binary);

	if (fileName) {
		for (int i = 0; i < numOfCities; i++)
		{
			int tmp = city[i].getPopulation();

			int cityNameLen = strlen(city[i].getName()) + 1;
			myFile.write((char*)&cityNameLen, sizeof(cityNameLen));
			myFile.write((char*)city[i].getName(), cityNameLen);
			myFile.write((char*)&tmp, sizeof(city[i].getPopulation()));
		}
	}
	else cout << "Error!\n";

	myFile.close();
}

void readFromBin(char* fileName) {
	ifstream myFile(fileName, ios::in | ios::binary);

	if (myFile) {
		while (!myFile.eof()) {
			int length;
			myFile.read((char*)&length, sizeof(length));

			char* city = new char[length + 1];
			myFile.read(city, length);
			int population;
			myFile.read((char*)&population, sizeof(population));

			cout << "City name:" << city << '\n' << "It's population: " << population << endl;

			delete city;
		}
	}

	myFile.close();
}

int main() {

	ifstream binFile("cities.dat", ios::in | ios::binary);

	City city1("Sofia", 5000);
	City city2("Plovdiv", 2000);
	int len = 2;
	City cities[] = { city1, city2 };

	writeToBin(cities, len, "cities.dat");

	return 0;
}