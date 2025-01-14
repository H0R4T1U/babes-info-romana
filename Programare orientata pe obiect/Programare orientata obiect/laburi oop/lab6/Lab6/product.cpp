#include "product.h"

#include <cstring>

Product::~Product(){
	delete[] name;
}

Product::Product(){
	name = NULL;
	price = 0;
}

Product::Product(char* pname,int pprice){
	name = new char[strlen(pname)+1];
	strcpy(name,pname);
	price=pprice;
}

Product::Product(const Product& from){
	name = new char[strlen(from.name)+1];
	strcpy(name,from.name);
	price = from.price;
}

void Product::operator=(Product& from){
	delete[] name;
	name = new char[strlen(from.name)+1];
	strcpy(name,from.name);
	price = from.price;
}

bool Product::operator==(Product& from){
	return price==from.price && strcmp(name,from.name)==0;
}

bool Product::operator>(Product& from){
	return price>from.price;
}

bool Product::operator<(Product& from){
	return price<from.price;
}

bool Product::operator>=(Product& from){
	return price>=from.price;
}

bool Product::operator<=(Product& from){
	return price<=from.price;
}

char* Product::getName(){
	return name;
}

std::ostream& operator<<(std::ostream& os, Product& r){
	os<<r.name<<':'<<r.price;
}
std::istream& operator>>(std::istream& os, Product& r){
	char name[1024];
	os.getline(name,1024);
	delete[] r.name;
	r.name = new char[strlen(name)+1];
	strcpy(r.name,name);
	os>>r.price;
}
