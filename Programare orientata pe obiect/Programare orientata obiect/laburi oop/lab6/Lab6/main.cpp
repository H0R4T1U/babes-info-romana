#include "slist.h"
#include "complex.h"
#include "product.h"

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	SList<Complex> clist;
	Complex x;
	Complex s;
	s=0;
	
	cin>>x;
	while ( x != Complex(0,0)){
		clist.add(x);
		cin >> x;
	}
	
	SList<Complex>::iterator it;
	for(it = clist.begin();it!=clist.end();++it){
		cout<<*it<<" ";
		s = s + *it;
	}
	cout<<endl;
	cout<<"Sum:"<<s<<endl;
	
	SList<Product> plist;
	Product p;
	while(cin.peek()!='\n')
		cin.get();
	cin.get();
	cin>>p;
	while (strcmp(p.getName(),"")){
		plist.add(p);
		while(cin.peek()!='\n')
			cin.get();
		cin.get();
		cin >> p;
	}
	
	SList<Product>::iterator pit;
	
	for(pit = plist.begin();pit!= plist.end();++pit)
		cout<<*pit<<" ";
	cout<<endl;
	
	return 0;
}
