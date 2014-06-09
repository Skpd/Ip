#include <iostream>
#include "includes.h"
#include <typeinfo>
#include <ctime>

int main() {
	std::cout << "Test" << std::endl;

	Ip::Cidr* record = new Ip::Cidr(2130706432, 24);

	std::cout << "Record size: " << record->size() << std::endl;

	Ip::Single start = NULL;
	Ip::Single end = NULL;
	std::vector<Ip::Cidr> result;

	Ip::Single::buildFromString("0.0.0.0", start);
	Ip::Single::buildFromString("0.0.0.254", end);

	Ip::Cidr::build(start.getAddress(), end.getAddress(), result);

	printf("Size: %u\n", result.size());

	result.insert(result.end(), Ip::Cidr(end.getAddress() + 1, 32));

	std::vector<Ip::Cidr> optimized = Ip::Cidr::optimize(result);

	printf("Otimized: %u\n", optimized.size());

	//std::cout << "Testing Single IP factory speed:" << std::endl;
	//Ip::Single ip = NULL;
	//std::vector<Ip::Single> vector;

	//clock_t begin = clock();

	//for (size_t i = 1000; i--;) {
	//	//ip = &Ip::Factory::create<Ip::Single>(std::string("127.0.0.2"));
	//	//Ip::Single::buildFromString(std::string("127.0.0.2"), ip);
	//	Ip::Single::buildFromString(std::string("127.0.0.2"), vector);
	//	//std::cout << ip.getAddress() << std::endl;
	//	//inet_addr("255.255.255.255");
	//}

	//clock_t end = clock();
	//double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	//printf("Elasped time is %.6lf seconds.\n", elapsed_secs);

	//printf("%s: %u\n", typeid(vector).name(), vector[0].getAddress());
	

	std::cin.get();

	return 0xDEADBEAF;
}