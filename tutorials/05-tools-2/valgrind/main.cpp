#include <memory>
#include <iostream>
#include <vector>

class Person {
public:
	void setFriend(std::shared_ptr<Person> f) {
		friendOfPerson = f;
	}
	std::shared_ptr<Person> friendOfPerson;
};

int main() {

	int a;
	if (a > 1) {
		a = 0;
	}

	std::shared_ptr<int> b = std::make_shared<int>(1);
	std::shared_ptr<int> b2 (b.get());


	std::shared_ptr<int> c = std::make_shared<int>(1);
	std::shared_ptr<int> c2(c.get());
	c.reset();
	*c2 = 2;


	std::vector<int> d(1);
	d[0] = 0;
	d[1] = 1;


	std::shared_ptr<Person> e = std::make_shared<Person>();
	std::shared_ptr<Person> e2 = std::make_shared<Person>();
	e->setFriend(e2);
	e2->setFriend(e);

	return 0;
}
