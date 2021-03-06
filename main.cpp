#include "typeconv.hpp"
#include <string>
#include <sstream>
#include <stdint.h>
#include <iostream>

class person
{
	public:
		person(std::string n, int a)
		{
			name = n;
			age = a;
		}
		std::string name;
		int age;

};

any p_uint64_t(any& a)
{
	std::cout << "p_uint64_t" << std::endl;
	uint64_t number = any::as<uint64_t>(a);
	std::stringstream ss;
	ss << number;
	return any(ss.str());
}

any p_int(any& a)
{
	std::cout << "p_int" << std::endl;
	int number = any::as<int>(a);
	std::stringstream ss;
	ss << number;
	return any(ss.str());
}

any p_unsigned_int(any& a)
{
	std::cout << "p_unsigned_int" << std::endl;
	unsigned int number = any::as<unsigned int>(a);
	std::stringstream ss;
	ss << number;
	return any(ss.str());
}

any p_person(any& a)
{
	std::cout << "p_person" << std::endl;
	person p = any::as<person>(a);
	std::stringstream ss;
	ss << p.name << " " << p.age;
	return any(ss.str());
}

int main(void)
{
	type_converter c;

	c.add_conv(typeid(uint64_t), p_uint64_t);
	uint64_t ui64t = 42;
	std::cout << any::as<std::string>(c.convert(ui64t)) << std::endl;

	c.add_conv(typeid(int), p_int);
	int i = 7;
	std::cout << any::as<std::string>(c.convert(i)) << std::endl;

	c.add_conv(typeid(unsigned int), p_unsigned_int);
	unsigned int ui = 17;
	std::cout << any::as<std::string>(c.convert(ui)) << std::endl;

	c.add_conv(typeid(person), p_person);
	person p("Pedro Navaja", 83);
	std::cout << any::as<std::string>(c.convert(p)) << std::endl;
}
