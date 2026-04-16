#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name); // 생성자
	~Person(); // 소멸자
	Person(const Person &person); // 복사 생성자
	void changeName(const char* name);
	void show() {
		cout << id << ", " << name << endl;
	}
};

/* 생성자 */
Person::Person(int id, const char* name) {
	this->id = id;
	//cout << id << endl;
	int len = strlen(name);
	this->name = new char[len + 1]; // 메모리 할당
	
	
	strcpy(this->name, name); // 이름 복사
	//cout << this->name << endl;
}


/* 복사 생성자 */
Person::Person(const Person &person) {
	this->id = person.id;
	//this->name = p.name // 얕은 복사
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체의 이름" << this-> name << endl;
}
Person::~Person() {
	cout << "delete isntance of " << name << endl;
	if (name) delete[] name; 
}


void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name)) 
		return; // 새 이름이 더 길면 변경 불가
	strcpy(this->name, name);
}

int main()
{
	Person father(1, "Kitae"); // 객체 생성
	Person daughter(father); // 객체 복사, 복사 생성자 호출

	cout << "딸 객체 생성 후 ----" << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "딸의 이름을 Grace로 변경한 후 ----" << endl;
	father.show();
	daughter.show();


	return 0;
}
