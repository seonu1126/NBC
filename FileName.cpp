#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize; //���� ���� ����
    int currentCapacity; // �ִ� ����
    void resize(int newCapacity) {//�����̺� �Լ�
        T* newdata = new T[newCapacity]; //�ִ����+5�� ������ ���ο� �迭 ����

        for (int i = 0; i < currentSize; i++) {//�����迭 �����ؿ���
            newdata[i] = data[i];
        }

        delete[] data;//���� �迭 ����
        data = newdata;//�迭 ������Ʈ
        currentCapacity = newCapacity;//������ ������Ʈ
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
            cout << "���� �� ���� ����" << endl;
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
    // SimpleVector<int>�� �⺻ ������ ���
    SimpleVector<int> vec;
   
    // ��� �߰� (push_back)
    while(1){
        
        cout << "��Ҹ� �߰��ϼ��� 0�� ������ �ߴ��մϴ�" << endl;
        int num = 0;
        cin >> num;
        
        vec.push_back(num);

        if (num == 0) {
            break;
        }
    }
    // ���� ũ��� �뷮 ���
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    // ������ ����
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

    // ������ ��� ����
    vec.pop_back();
    cout << "pop_back: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;




    

    return 0;
}