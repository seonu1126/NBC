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

void Asc(int num[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}

void Desc(int num[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (num[j] < num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}

void printnum(int num[], int size) {
	for (int i = 0; i < size-1; i++) {
		cout << "[" << num[i] << "]" << " ,";
	}
	cout << "[" << num[size-1] << "]" << endl;
}

int main() {

	int number[5]; 
	int choice = 0;
	cout << "다섯개의 수를 입력받아 총합과 평균을 구합니다." << endl;

	for (int i = 0; i < 5; i++) {
		cout << i+1 << "번째 수를 입력하세요." << endl;
		cin >> number[i];
	}

	int x = sum(number, 5);
	cout << "배열의 평균은 : " << numavg(x, 5) << endl ;

	
	while (1) {
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
		cout << "정렬 방식을 선택하세요. " << endl
		<< "1. 오름차순 "<< endl <<"2. 내림차순 "<< endl <<"3. 종료 "<< endl;
		cin >> choice;

		if (choice == 1) {
			Asc(number, 5);
			cout << "오름차순 정렬 완료" << endl;
			printnum(number, 5);
		}
		else if (choice == 2) {
			Desc(number, 5);
			cout << "내림차순 정렬 완료" << endl;
			printnum(number, 5);
		}
		else {
			cout << "종료합니다" << endl;
			break;
		}
	}


}
