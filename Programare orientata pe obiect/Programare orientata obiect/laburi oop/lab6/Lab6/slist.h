#ifndef SLIST_H
#define SLIST_H

#define NULL 0

template<class T>
class SList{
	public:
		
		struct elem{
			elem* next;
			T* data;
		};
		
		class iterator{
			public:
				iterator(){
					data = NULL;
					position = NULL;
				}
				iterator(SList* s){
					data = s;
					position = s->data;
				}
				iterator(SList* s,elem* ppos){
					data = s;
					position = ppos;
				}
				void operator=(iterator w){
					data = w.data;
					position = w.position;
				}
				
				void operator++(){
					position = position->next;
				}
				
				bool operator==(iterator w){
					return w.position==position && w.data==data;
				}
				
				bool operator!=(iterator w){
					return w.position!=position || w.data!=data;
				}
				
				T& operator*(){
					return *(position->data);	
				}
			private:
				SList* data;
				elem* position;
		};
		
		
		SList(){
			data = NULL;
		}
		
		iterator begin(){
			return iterator(this);
		}
		
		iterator end(){
			return iterator(this,NULL);
		}
		
		void add(T& e){
			elem* tmp = new elem;
			tmp->data = new T(e);
			tmp->next = data;
			data = tmp;
		}
		
		void add(T* e){
			elem* tmp = new elem;
			tmp->data = e;
			tmp->next = data;
			data = tmp;
		}
		
		void remove(T& e){
			elem* tmp;
			for(tmp=data;tmp->next!=NULL;tmp=tmp->next){
				if(tmp->next->data == e){
					elem* aux = tmp->next;
					tmp->next = tmp->next->next;
					delete aux->data;
					delete aux;
				}
			}
			
			if(tmp == data && tmp->data == e){
				delete tmp->data;
				delete tmp;
			}
		}
		
		iterator find(T& e){
			elem* tmp;
			for(tmp=data;tmp!=NULL;tmp=tmp->next){
				if(tmp->data == e)
					return iterator(this,tmp);
			}
			return end();
		}
	private:
		elem* data;
};

#endif
