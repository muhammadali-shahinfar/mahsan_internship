#include <iostream>

template <typename T> class mvector {
public:
	mvector() {
		pointer_to_first = new T[1];
		vec_size = 0;
		capacity = 1;
	};

	mvector(int count, T t) {
		pointer_to_first = new T[count];
		T* pointer = pointer_to_first;
		vec_size = count;
		capacity = count;

		change_pointed_values(pointer, t, count);

	}

	~mvector(){
		delete pointer_to_first;
	}

	void operator=(mvector tmp) {
		while (this->size() != 0) this->pop_back();

		for (int i = 0; i < tmp.size(); i++) {
			this->push_back(tmp[i]);
		}
	};
	void push_back(T t) {
		if (vec_size == capacity) {
			resize(capacity * 2);
		}

		*(pointer_to_first + vec_size) = t;
		vec_size++;
	};

	T pop_back() {
		try{
			vec_size--;
			if(vec_size < 0) throw  std::string("pop_from_empty_vector");
			T result = *(pointer_to_first + vec_size);
			if (vec_size < capacity / 2 && capacity / 2 != 0) {
				resize(capacity / 2);
			}
			return result;
		}
		catch(std::string &e){
			std::cerr << "can`t pop from empty vector" << std::endl;
			return NULL;
		}
	};

	void resize(int count) {
		T* new_pointer_to_first = new T[count];
		T* ptr = pointer_to_first;
		T* new_ptr = new_pointer_to_first;

		copy_values(ptr,new_ptr,count);


		delete pointer_to_first;
		pointer_to_first = new_pointer_to_first;
		capacity = (count>1 ? count : 1);
		vec_size = count;
	};
	T operator[](int index) {
		return *(pointer_to_first + index);
	};
	int size() {
		return vec_size;
	};

private:

	void change_pointed_values(T* pointer,T t, int size){
		for (int i = 0; i < size; i++) {
			*(pointer) = t;
			pointer++;
		}
	}

	void copy_values(T* sourse,T* dest, int count){

		for (int i = 0; i < count; i++) {
			if (i > vec_size) {
				*dest = T();
			}
			else
			{
				*(dest) = *(sourse);
				sourse++;
			}
			dest++;
		}
	}
	
	T* pointer_to_first;
	int vec_size;
	int capacity;

};

/*
int main(){
	mvector<int> v1;
	v1.assign(10,1);
	std::cout << v1.pop_back();
}*/