//심플 벡터 만들기

#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize; //현재 원소 갯수
    int currentCapacity; // 최대 길이
    void resize(int newCapacity) {//프라이빗 함수
        T* newdata = new T[newCapacity]; //최대길이+5의 길이인 새로운 배열 생성

        for (int i = 0; i < currentSize; i++) {//기존배열 복사해오기
            newdata[i] = data[i];
        }

        delete[] data;//기존 배열 삭제
        data = newdata;//배열 업데이트
        currentCapacity = newCapacity;//사이즈 업데이트
    }
public:
    SimpleVector() {
        data = new int[10];
    }
    SimpleVector(int capacity) {
        data = new int[currentCapacity];
    }

    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (currentSize >= currentCapacity) {
            resize(currentCapacity+5);
        }
        data[currentSize] = value;
        currentSize++;
    }

    void pop_back() {
        if (currentSize <= 0) {
            cout << "제거 할 원소 없음" << endl;
        }
        else
            currentSize--;
    }

    int size() {
        return currentSize;
    }

    int capacity() {
        return currentCapacity;
    }
    void sortData() {
        sort(data, data + currentSize);
    }

    const T& operator[](int index) const {
        return data[index];
    }
};


int main() {
    // SimpleVector<int>의 기본 생성자 사용
    SimpleVector<int> vec;
   
    // 요소 추가 (push_back)
    while(1){
        
        cout << "요소를 추가하세요 0을 누르면 중단합니다" << endl;
        int num = 0;
        cin >> num;
        
        vec.push_back(num);

        if (num == 0) {
            break;
        }
    }
    // 현재 크기와 용량 출력
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    // 데이터 정렬
    cout << "vec: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.sortData();

    cout << "orting: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // 마지막 요소 제거
    vec.pop_back();
    cout << "pop_back: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;




    

    return 0;
}
