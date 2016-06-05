#include "StdAfx.h"
#include "DynamicList.h"
#include <iostream>
#include <assert.h>


DynamicList::DynamicList(void)
{
	this->lenght = 0;
	this->capacity = 4;
	this->elements = new DomainClass*[4];
}

void DynamicList::resize() {

	this->capacity = 2 * (this->capacity);
	DomainClass** temporary = new DomainClass*[this->capacity];
	for (int i = 0; i <= this->lenght; i++)
		temporary[i] = this->elements[i];
	delete[] this->elements;
	this->elements = temporary;
}

void DynamicList::deletePosition(int p){

	// Stergem elementul
	delete elements[p];

	// Mutam restul elementelor la stanga
	for (int i = p; i < this->lenght - 1; i++)
		this->elements[i] = this->elements[i + 1];
	this->elements[this->lenght - 1] = NULL;
	this->lenght -= 1;
}

void DynamicList::testDelete() {
	DynamicList ll;
	assert(ll.getLenght()==0);
	DomainClass element;
	element.DomainClass::DomainClass(100,4,32,"water");
	ll.append(element);
	assert(ll.getLenght()==1);
	/*
	try{
	assert(ll.getLenght()==45);
	}
	catch (std::exception& e) { assert(true)}
	*/

}

void DynamicList::updatePosition(int p, const DomainClass& cheltuiala){
	
	delete elements[p];
	this->elements[p] = new DomainClass(cheltuiala);
}

void DynamicList::testUpdate(){

	DynamicList ll;
	assert(ll.getLenght()==0);
	DomainClass element;
	element.DomainClass::DomainClass(100,4,32,"water");
	ll.append(element);
	assert(ll.getLenght()==1);
	DomainClass el;
	el.DomainClass::DomainClass(100,12,302,"illuminat");
	ll.updatePosition(0,el);
	//std::cout<<ll[0].GetType();
	assert(ll[0].GetNumber() == 12);
	assert(ll[0].GetAmount() == 302);
	
}

int DynamicList::getCapacity(){
	return this->capacity;
}

int DynamicList::getLenght(){
	return this->lenght;
}

void DynamicList::append(const DomainClass& element){
	if (this->lenght == this->capacity)
		resize();
	this->elements[this->lenght++] = new DomainClass(element);
}
void DynamicList::testAppend(){
	DynamicList ll;
	assert(ll.getLenght()==0);
	DomainClass element,a,b,c;
	element.DomainClass::DomainClass(100,4,32,"water");
	a.DomainClass::DomainClass(16,15,100,"gas");
	b.DomainClass::DomainClass(10,35,175,"illuminat");

	ll.append(element);
	assert(ll.getLenght()==1);
	assert(ll[0].GetNumber() == 4);

	ll.append(a);
	assert(ll.getLenght()==2);
	assert(ll[1].GetNumber() == 15);

	ll.append(b);
	assert(ll.getLenght()==3);
	assert(ll[2].GetNumber() == 35);

}
DomainClass& DynamicList::operator[](int k){
	return *(this->elements[k]);
}

void DynamicList::display() const 
{ 
    for(int i = 1; i < lenght; i++) 
        //std::cout<<elements[i].GetId()<<" "<<elements[i].GetNumber()<<" "<<elements[i].GetAmount() <<" "<<elements[i].GetType(); 
		std::cout<<'\n'; 
} 

DynamicList::~DynamicList(void)
{
	for (int i = 0; i < this->lenght ; i++)
		delete this->elements[i];

	delete[] this->elements;
}