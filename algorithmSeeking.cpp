#include <iostream>

using namespace std;

int main() {

	//int arr[] = { 2,3,5,8,11,13,21 };
	//
	//int beg = 0;
	//int end = 6;
	//int mid = 0;

	//int elToSeek = 21;
	//bool hasTheNum = false;

	//while (!hasTheNum) {
	//	mid = (end + beg) / 2;

	//	if (elToSeek > arr[mid]) {
	//		beg = mid + 1;
	//	}
	//	else if(elToSeek < arr[mid]) {
	//		end = mid - 1;
	//	}
	//	else {
	//		hasTheNum = true;
	//	}
	//}

	//cout << hasTheNum << " " << arr[mid] << endl;


	int arr1[4] = { 2,5,5,10 };
	int arr2[4] = { 6,9,11,13 };

	int arr3[8] = { 0 };
	int j, k;
	j = k = 0;

	for (int i = 0; i < 8; i++)
	{
		if (arr2[j] < arr1[k]) {
			arr3[i] = arr2[j++];
		}
		else {
			arr3[i] = arr1[k++];
		}

		if (j == 4 || k == 4) {
			break;
		}
	}

	if (j == 4) {
		for (int i = k; i < 8; i++)
		{
			arr3[i + j] = arr1[i];
		}
	}
	else {
		for (int i = j; i < 8; i++)
		{
			arr3[i + k] = arr1[i];
		}
	}

	system("pause");
	return 0;
}