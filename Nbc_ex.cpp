#include <iostream>
using namespace std;


int sum(int num[], int size) { //합을 구하는 기능 코드
	int add = 0;
	for (int i = 0;i < size;i++) {
		add += num[i]; //add = add + num[i];
	}
	return add;
}

int numavg(int sum,int size) {
	int avg = sum / size;
	return avg;
}

int main() {

	int number[5]; 

	cin >> number[0];
	cin >> number[1];
	cin >> number[2];
	cin >> number[3];
	cin >> number[4];

	int x = sum(number, 5);

	cout << numavg(x,5);
}
