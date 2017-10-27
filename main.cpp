#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

template <typename T>
class dynArray {
private:
	T* arr;
	unsigned maxNumOfCities;
	int currentCity;
	
	void resizeArray() {
		maxNumOfCities *= 2;
		
		T* tmpArray = new T[maxNumOfCities];
		for (int i = 0; i < currentCity; i++)
		{
			tmpArray[i] = arr[i];
		}

		deleteArr();
		//arr = new T[maxNumOfCities];
		arr = tmpArray;
	}

	void deleteArr() {
		delete arr;
		arr = nullptr;
	}
public:
	dynArray(unsigned _maxNumOfCities, unsigned _currentCity) {
		arr = new T[_maxNumOfCities];
		_currentCity = 0;
	}

	void addCity(const T& newCity) {
		if (currentCity == maxNumOfCities) {
			resizeArray();
		}

		arr[currentCity] = newCity;
		currentCity++;
	}
	/*dynArray& operator=(const T& other) {
		maxNumOfCities = other.getNumOfCities();
		currentCity = other.getCurrCity();
		//TODO
	}*/

	/*unsigned getNumOfCities() { return maxNumOfCities; }
	int getCurrCity() { return currentCity; }*/

};


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

	City& operator=(const City& other) {
		if (this != &other) {
			removeCity();
		}

		this->setName(other.getName());
		this->population = other.getPopulation();
	}

	void setName(char* newName) {
		if (name != nullptr) {
			removeCity();
		}

		int length = strlen(newName) + 1;
		name = new char[length];
		strcpy(name, newName);
	}

	char* getName() const { return name; }
	int getPopulation() const { return population; }

	~City() {
		removeCity();
	}
};



void readFromBin(char* fileName, dynArray<City> cities) {
	ifstream myFile(fileName, ios::in);

	if (myFile) {
		while (!myFile.eof()) {

			string city;
			myFile >> city;
			int population;
			myFile.read((char*)&population, sizeof(population));

			City newCity(city, population);

			cities.addCity(newCity);

			//delete city;
		}
	}

	myFile.close();
}




int main(int argc, char* argv[]) {

	//clock_t start;
	//double duration;
	//start = clock();

	//int n = 100000;

	//for (int index = 0; index < n; index++)
	//{
	//	for (int index1 = 0; index1 < n; index1++)
	//	{
	//		//26,... sec (n^2 - slojnost na algorituma)
	//	}
	//}

	//for (int index = 0; index < n; index++)
	//{
	//	for (int index1 = 0; index1 < n; index1 *= 2)
	//	{
	//		//0,003 sec (n*log(n) - slojnost na algorituma)
	//	}
	//}

	////sbora na slojnosta e ~26

	//for (int index = 0; index < n; index *= 2)
	//{
	//	for (int index1 = 0; index1 < n; index1 *= 2)
	//	{
	//		//0,000000... - slojnost na algoritma
	//	}
	//}

	return 0;
}