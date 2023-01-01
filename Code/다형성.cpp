#include <iostream>

using namespace std;

class Animal {

	public : 
	void animalMove() {
		cout<<("동물이 움직입니다")<<endl;
	}
};

class Human : public Animal 
{
	public:
	void animalMove() {
		cout<<("사람이 두발로 걷습니다")<<endl;
	}
};
class Tiger : public Animal {

	public:
	void animalMove() {
		cout<<("호랑이가 네발로 뜁니다")<<endl;
	}
};
class Eagle :Animal {

	public:
	void animalMove() {
		cout << ("독수리가 하늘을 납니다")<<endl;
	}
};

//2번 AnimalMove class 생성
class AnimalMove {

	
	//3번
	public:
	void moveAnimal(Animal* animal) {

		animal->animalMove();
	};
};
/*int main() {
	//2번
	Animal* hAnimal = new Human();
	Animal* tAnimal = new Tiger();
	Animal* eAnimal = new Human();
	//4번
	AnimalMove* test = new AnimalMove();
	test->moveAnimal(hAnimal);//사람이 두발로 걷습니다
	test->moveAnimal(tAnimal);//호랑이가 네발로 뜁니다
	test->moveAnimal(eAnimal);//사람이 두발로 걷습니다

}
*/