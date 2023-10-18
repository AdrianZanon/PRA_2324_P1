#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE;
	void resize(int new_size){
		/*Aún por hacer*/
	}

    public:
        // miembros públicos, incluidos los heredados de List<T>
	
	

	ListArray(){
		new T lista[MINSIZE];
		MINSIZE = 2;
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
    	
	void append(T e){
		lista(n) = e;
	}

	void prepend(T e){
		lista(n - (n + 1)) = e;
	}
	
	T remove(int pos){
		/*WIP*/
	}
	
	T get(int pos){
		if(pos < 0 || pos > (max - 1)){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			/*WIP*/
		}
	}
	
	int search(T e){
		/*WIP*/
	}

	bool empty(){
		/*WIP*/
	}

	int size(){
		cout<< "En la lista hay " << n-1 << " elementos." << endl;
	}
};














