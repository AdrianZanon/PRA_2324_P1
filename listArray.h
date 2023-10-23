#include <ostream>
#include "list.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE;
	void resize(int new_size){
		if (new_size == max){
			return;
		}

		int* listanueva = new T[new_size];

		for (int i = 0; i < size; i++) {
            		listanueva[i] = lista[i];
        	}
		delete[] lista;
		arr = new_arr;
		max = new_max;
	}

    public:	

	ListArray(){
		this->MINSIZE = MINSIZE = 2;
		this->max = max;
		this->n = n;
		new T lista[MINSIZE];		
	}
	
	~ListArray(){
		delete[] lista;
	}

	T operator[](int pos){
		if (pos >= 0 && i < (max - 1)) { 
			return e[pos]; 
		}
		else { 
			throw std::out_of_range("La posición no es válida.\n");
	       	}
	}
	
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &lista){
		out << lista[];
		return out;
	}



	void List::insert(int pos, T e){ 
		if(pos < 0 || pos > (max - 1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else {
			lista[pos] = e;	
		}
	}
    	
	void List::append(T e){
		lista(n) = e;
	}

	void List::prepend(T e){
		lista(n - (n + 1)) = e;
	}
	
	T List::remove(int pos){
		if(pos < 0 || pos > (max -1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			T elemento = lista[pos];
			delete lista[pos];
			for(int i = pos; i < (max -1); i++){
				lista[pos] = lista[pos+i];
			}
		return elemento;	
		}
	}
	
	T List::get(int pos){
		if(pos < 0 || pos > (max - 1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			return lista[pos];
		}
	}
	
	int List::search(T e){
		for(int i = 0; i < (max -1); i++ ){
			if(e == i){
				return i;	
			}
		}
		return -1;
	}

	bool List::empty(){
		if(lista[0] == nullptr){
			return 1;
		}
		else{ 
			return 0;
		}
	}

	int List::size(){
		return n;
	}
};














