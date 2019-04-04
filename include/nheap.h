#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;


template <class T>

class Nheap{
private:
	vector<T> elements;
	int n;
	void heapfy_up(int i);
	void heapfy_down(int i);
	int parent(int i);
	void swap(int i, int j){
		T aux = elements[i];
		elements[i] = elements[j];
		elements[j] = aux;
	};

public:
	Nheap(int n);
	void insert(T element);
	T pop_min();
	T get_min();
	//void deleteNode(T element);
	void update(T oldElement, T newElement);
	bool is_empty(){
		return elements.empty();
	};
	void print_elements(){
		for(int i = 0; i < elements.size(); i++)
			cout << "(" << elements[i].get_value() << ", " <<  elements[i].get_key() << "), ";
		cout << "\n";
	};
};



template <class T>
Nheap<T>::Nheap(int n){
	this->n = n;
}

template <class T>
int Nheap<T>::parent(int i){
	return (i-1)/n;
}

template <class T>
void Nheap<T>::heapfy_up(int i){
	if (i != 0)
	{
		if(elements[parent(i)].get_key() > elements[i].get_key())
		{
			swap(i, parent(i));			
			heapfy_up(parent(i));
		}
	}
}

template <class T>
void Nheap<T>::insert(T element){
	elements.push_back(element);
	heapfy_up(elements.size()-1);
}

template <class T>
T Nheap<T>::get_min(){
	return elements.front();
}

template <class T>
T Nheap<T>::pop_min(){
	T aux = elements.front();
	swap(0, elements.size() - 1);	
	elements.pop_back();
	if(!elements.empty())
		heapfy_down(0);
	//cout << "RETURNED: (" << aux.get_value() << ", " << aux.get_key() << ")\n";
	return aux;
}
/*
template <class T>
void Nheap<T>::deleteNode(int i){
	swap(elements.front(), elements.back());
	elements.pop_back();
	heapfy_down(elements.size()-1);
}
*/

template<class T>
void Nheap<T>::update(T oldElement, T newElement){
	for(int i = 0; i < elements.size(); i++)
	{
		if(oldElement.get_key() == elements[i].get_key())
		{
			elements[i] = newElement;
			if(newElement.get_key() > newElement.get_key()){
				heapfy_down(i);				
			}
			else{
				heapfy_up(i);
			}
		}
	}
}


template <class T>
void Nheap<T>::heapfy_down(int i){
	if(elements.size() - 1 > n*i + 1){ // verifica se tem filhos
		int kmin = 0;//elements[n*i-1].get_key
		int k=0;
		//cout << "\npai = (" << elements[i].get_value() << ", " <<  elements[i].get_key() << ")\n";
		//cout << "filhos: ";
			//cout << "(" << elements[k + (n*i)+1].get_value() << ", " <<  elements[k + (n*i)+1].get_key() << "), ";
		for(k = 1; k < n && elements.size() > k + (n*i)+1; k++)
		{
			//cout << "(" << elements[k + (n*i)+1].get_value() << ", " <<  elements[k + (n*i)+1].get_key() << "), ";
			if ( elements[k + (n*i)+1].get_key() < elements[kmin + (n*i)+1].get_key()){ // elements.size() - 1 < k + (n*i)+1
				kmin = k;//min = elements[k + n*i - 1].get_key();
			}
		}
		if(elements[i].get_key() > elements[kmin + (n*i)+1].get_key())
		{	
			//cout << "oi 1";
			swap(i, kmin + (n*i)+1);
			heapfy_down(kmin + (n*i)+1);
		}
	}
}




#endif /* NHEAP_H */