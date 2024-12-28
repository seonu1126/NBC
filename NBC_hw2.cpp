#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() =0;  //���� ���� �Լ�
    virtual ~Animal() {};
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public:
    void makeSound() override { cout << "Meow!" << endl; }
};

class Cow : public Animal {
public:
    void makeSound() override { cout << "Moo!" << endl; }
};

//���� ���//////////////////////////////////
class Zoo {
private:
    Animal* animals[10];
    int count=0;

public:
    //�������� ���� �߰�
    void addAnimal(Animal* animal) {
        if (count < 10) { animals[count++] = animal; }
        else { cout << "�迭 ũ�� �ʰ�" << endl; }
    }

    //makeSound �Լ� ����
    void performActions() {
        for (int i = 0; i < count; i++) {
            animals[i]->makeSound(); //�Ҹ� ���
        }
    }

    //Zoo �Ҹ���
    ~Zoo() {
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
};

Animal* createRandomAnimal() {
    int random = rand() % 3;
    if (random == 0) { return new Dog; }
    else if (random == 1) { return new Cat; }
    else { return new Cow; }
}


int main() {
    Zoo z;
    
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        z.addAnimal(createRandomAnimal());
    }

    z.performActions();
    
    return 0;
}