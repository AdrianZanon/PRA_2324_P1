#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* lista;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
		if (new_size == max){
			return;
		}

		int* listanueva = new T[new_size];
		int new_max;

		for (int i = 0; i < new_size; i++) {
            		listanueva[i] = lista[i];
        	}
		delete[] lista;
		lista = listanueva;
		max = new_max;
	}

    public:	

	ListArray(){
		this->max = max;
		this->n = n;
		T* lista = new T[MINSIZE];
		
	}
	
	~ListArray(){
		delete[] lista;
	}

	T operator[](int pos){
		if (pos >= 0 && pos < (max - 1)) { 
			return lista[pos]; 
		}
		else { 
			throw std::out_of_range("La posición no es válida.\n");
	       	}
	}
	
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &objeto){
		for (int i = 0; i < (objeto.max - 1); i++) {
            	out << objeto.lista[i] << " ";
       		}
		return out;
	}



	void insert(int pos, T e){ 
		if(pos < 0 || pos > (max - 1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else {
			lista[pos] = e;	
		}
	}
    	
	void append(T e){
		lista[n] = e;
	}

	void prepend(T e){
		lista[n - (n + 1)] = e;
	}
	
	T remove(int pos){
		if(pos < 0 || pos > (max -1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			T elemento = lista[pos];
			for(int i = pos; i < (max -1); i++){
				lista[pos] = lista[pos+i];
			}
		return elemento;	
		}
	}
	
	T get(int pos){
		if(pos < 0 || pos > (max - 1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			return lista[pos];
		}
	}
	
	int search(T e){
		for(int i = 0; i < (max -1); i++ ){
			if(e == i){
				return i;	
			}
		}
		return -1;
	}

	bool empty(){
		if(n == 0){
			return 1;
		}
		else{ 
			return 0;
		}
	}

	int size(){
		return n;
	}
};
