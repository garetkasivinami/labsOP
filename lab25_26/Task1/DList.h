#pragma once
template <typename T>
class DList
{
public:
	DList();
	~DList();
	void Add(T obj);
	void Add(T _arr[], int count);
	void Remove(T *obj);
	void Remove(T obj);
	void RemoveAt(int index);
	T* GetOriginalArr();
	T operator [](int index);
private:
	T *arr;
	int lenght;
	int realSize;
	void CheckSize();
};
template <typename T>
DList<T>::DList() {
	lenght = 0;
	realSize = 0;
	arr = (T*)malloc(0);
}
template <typename T>
DList<T>::~DList() {
	free(arr);
}

template<typename T>
void DList<T>::Add(T obj)
{
	CheckSize();
	arr[lenght] = obj;
	lenght++;
}

template<typename T>
void DList<T>::Add(T _arr[], int count)
{
	for (int i = 0; i < count; i++) {
		Add(_arr[i]);
	}
}

template<typename T>
void DList<T>::Remove(T* obj)
{
	int index = (obj - arr) / sizeof(T);
	RemoveAt(index);
}

template<typename T>
void DList<T>::Remove(T obj)
{
	if (lenght == 0) {
		return;
	}
	for (int i = 0; i < lenght; i++) {
		if (arr[i] == obj) {
			RemoveAt(i);
			i--;
		}
	}
}

template<typename T>
void DList<T>::RemoveAt(int index)
{
	if (index < 0 || index >= lenght) {
		return;
	}
	lenght--;
	arr[index] = arr[lenght];
}

template<typename T>
inline T* DList<T>::GetOriginalArr()
{
	return arr;
}

template<typename T>
T DList<T>::operator[](int index)
{
	if (index < 0 || index >= lenght) {
		throw;
	}
	return arr[index];
}
template<typename T>
void DList<T>::CheckSize()
{
	if (lenght >= realSize) {
		arr = (T*)realloc(arr, sizeof(T) * (lenght + 4)); // на 3 елементи додатково резервація
		realSize = lenght + 4;
	}
}
