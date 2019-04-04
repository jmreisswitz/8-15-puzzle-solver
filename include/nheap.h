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
	void heapfyUp(int i);
	void heapfyDown(int i);
	int parent(int i);
	void swap(int i, int j){
		T aux = elements[i];
		elements[i] = elements[j];
		elements[j] = aux;
	};

public:
	Nheap(int n);
	void insert(T element);
	T getmin();
	T pop_min();
	//void deleteNode(T element);
	void update(T oldElement, T newElement);
	bool isEmpty(){
		return elements.empty();
	};
	void printElements(){
		for(int i = 0; i < elements.size(); i++)
			cout << "(" << elements[i].getValue() << ", " <<  elements[i].getKey() << "), ";
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
void Nheap<T>::heapfyUp(int i){
	if (i != 0)
	{
		if(elements[parent(i)].getKey() > elements[i].getKey())
		{
			swap(i, parent(i));			
			heapfyUp(parent(i));
		}
	}
}

template <class T>
void Nheap<T>::insert(T element){
	elements.push_back(element);
	heapfyUp(elements.size()-1);
}

template <class T>
T Nheap<T>::getmin(){
	return elements.front();
}

template <class T>
T Nheap<T>::pop_min(){
	T aux = elements.front();
	swap(0, elements.size() - 1);	
	elements.pop_back();
	if(!elements.empty())
		heapfyDown(0);
	//cout << "RETURNED: (" << aux.getValue() << ", " << aux.getKey() << ")\n";
	return aux;
}
/*
template <class T>
void Nheap<T>::deleteNode(int i){
	swap(elements.front(), elements.back());
	elements.pop_back();
	heapfyDown(elements.size()-1);
}
*/

template<class T>
void Nheap<T>::update(T oldElement, T newElement){
	for(int i = 0; i < elements.size(); i++)
	{
		if(oldElement.getKey() == elements[i].getKey())
		{
			elements[i] = newElement;
			if(newElement.getKey() > newElement.getKey()){
				heapfyDown(i);				
			}
			else{
				heapfyUp(i);
			}
		}
	}
}


template <class T>
void Nheap<T>::heapfyDown(int i){
	if(elements.size() - 1 > n*i + 1){ // verifica se tem filhos
		int kmin = 0;//elements[n*i-1].getKey
		int k=0;
		//cout << "\npai = (" << elements[i].getValue() << ", " <<  elements[i].getKey() << ")\n";
		//cout << "filhos: ";
			//cout << "(" << elements[k + (n*i)+1].getValue() << ", " <<  elements[k + (n*i)+1].getKey() << "), ";
		for(k = 1; k < n && elements.size() > k + (n*i)+1; k++)
		{
			//cout << "(" << elements[k + (n*i)+1].getValue() << ", " <<  elements[k + (n*i)+1].getKey() << "), ";
			if ( elements[k + (n*i)+1].getKey() < elements[kmin + (n*i)+1].getKey()){ // elements.size() - 1 < k + (n*i)+1
				kmin = k;//min = elements[k + n*i - 1].getKey();
			}
		}
		if(elements[i].getKey() > elements[kmin + (n*i)+1].getKey())
		{	
			//cout << "oi 1";
			swap(i, kmin + (n*i)+1);
			heapfyDown(kmin + (n*i)+1);
		}
	}
}




#endif /* NHEAP_H */