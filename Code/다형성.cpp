#include <iostream>

using namespace std;

class Animal {

	public : 
	void animalMove() {
		cout<<("������ �����Դϴ�")<<endl;
	}
};

class Human : public Animal 
{
	public:
	void animalMove() {
		cout<<("����� �ι߷� �Ƚ��ϴ�")<<endl;
	}
};
class Tiger : public Animal {

	public:
	void animalMove() {
		cout<<("ȣ���̰� �׹߷� �ݴϴ�")<<endl;
	}
};
class Eagle :Animal {

	public:
	void animalMove() {
		cout << ("�������� �ϴ��� ���ϴ�")<<endl;
	}
};

//2�� AnimalMove class ����
class AnimalMove {

	
	//3��
	public:
	void moveAnimal(Animal* animal) {

		animal->animalMove();
	};
};
/*int main() {
	//2��
	Animal* hAnimal = new Human();
	Animal* tAnimal = new Tiger();
	Animal* eAnimal = new Human();
	//4��
	AnimalMove* test = new AnimalMove();
	test->moveAnimal(hAnimal);//����� �ι߷� �Ƚ��ϴ�
	test->moveAnimal(tAnimal);//ȣ���̰� �׹߷� �ݴϴ�
	test->moveAnimal(eAnimal);//����� �ι߷� �Ƚ��ϴ�

}
*/