#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() =0;  //순수 가상 함수 (=0 이용)
    virtual ~Animal() {};
};

class Dog : public Animal {
public://Animal의 자식클래스인 Dog에서 makeSound()함수 재정의 => override 함수 사용
    void makeSound() override { cout << "Woof!" << endl; }
};

class Cat : public Animal {
public://Animal의 자식클래스인 Cat에서 makeSound()함수 재정의 => override 함수 사용
    void makeSound() override { cout << "Meow!" << endl; }
};

class Cow : public Animal {
public://Animal의 자식클래스인 Cow에서 makeSound()함수 재정의 => override 함수 사용
    void makeSound() override { cout << "Moo!" << endl; }
};

//도전 기능//////////////////////////////////
class Zoo {
private:
    Animal* animals[10];
    int count=0;

public:
    //동물원에 동물 추가
    void addAnimal(Animal* animal) {
        if (count < 10) { animals[count++] = animal; }
        else { cout << "배열 크기 초과" << endl; }
    }

    //makeSound 함수 실행
    void performActions() {
        for (int i = 0; i < count; i++) {
            animals[i]->makeSound(); //소리 출력
        }
    }

    //Zoo 소멸자
    ~Zoo() {
        for (int i = 0; i < count; i++) {
            delete animals[i];
        }
    }
};
//랜덤으로 동물 객체 반환.
Animal* createRandomAnimal() {
    int random = rand() % 3;
    if (random == 0) { return new Dog; }
    else if (random == 1) { return new Cat; }
    else { return new Cow; }
}


int main() {
    Zoo z; //Zoo 객체 생성
    
    srand(time(0));//시간을 이용해서 랜덤값 초기화
    
    for (int i = 0; i < 10; i++) {//랜덤으로 동물 객체 지정, 10개 제한
        z.addAnimal(createRandomAnimal());
    }

    z.performActions();//makeSound 함수 실행, 동물 울음소리 출력
    
    return 0;
}
