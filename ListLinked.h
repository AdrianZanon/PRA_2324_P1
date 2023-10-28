#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:
	
	ListLinked(){
		first = nullptr;
		n = 0;
	}

	~ListLinked(){
		Node<T>* aux  = first;
		while(first != nullptr){
			first = first->next;
			delete aux;
			aux = first;
		}
	}


	T operator[](int pos){
		if (pos >= 0 && pos < n){ 
			Node<T>* aux = first;
                        for(int i = 0 ; i != pos ; i++){
                        	aux = aux->next;
                        }
                        return aux->data;
		}
		else { 
			throw std::out_of_range("La posición no es válida.\n");
	       	}
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &objeto){
		Node<T>* aux =objeto.first;

		while(aux != nullptr){
			out << aux->data <<" "<< std::endl;
			aux = aux->next;
		};

		return out;
	}

        void insert(int pos, T e){ 
		if(pos < 0 || pos > n){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else {
			Node<T>* aux = first;
                        Node<T>* aux2 = nullptr;

			for(int i = 0 ; i != pos ; i++){ 
				aux2 = aux;
				aux = aux-> next;
			}

			Node<T>* nuevo_node = new Node(e , aux );

			if(pos == 0){
				nuevo_node->next = first;
				first = nuevo_node;
			}
			else{
				aux2->next = nuevo_node;
				nuevo_node->next = aux;
			}

			n++;	
		}
	}
	
	void append(T e){
		insert(n, e);
	}

	void prepend(T e){
		insert(0, e);
	}
	
	T remove(int pos){
		if(pos < 0 || pos >=  n){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			Node<T>* aux = first;
                        Node<T>* aux2 = nullptr;

                        for(int i = 0 ; i != pos ; i++){
	                        aux2 = aux;
                                aux = aux-> next;
                        }
			
			T elemento = aux->data;
			n--;

			if(pos == 0){
				first = aux->next;
				return elemento;
			}
			else{
				aux2->next = aux->next;
				delete aux;
				return elemento;
                	}	
		}
	}
	
	T get(int pos){
		if(pos < 0 || pos >= n){
			throw std::out_of_range("La posición no es válida.\n");
		}
		else{
			Node<T>* aux = first;
			for(int i = 0 ; i != pos ; i++){
				aux = aux->next;
			}
			return aux->data;
		}
	}
	
	int search(T e){
		Node<T>*  aux = first;
                for(int i = 0 ; i < n ; i++){
                        if(aux->data == e){
				return i;
			}
			aux = aux->next;
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

