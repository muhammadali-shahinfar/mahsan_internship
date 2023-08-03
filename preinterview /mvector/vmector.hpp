#include <iostream>
#include <string.h>
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

	mvector(const mvector& t){ //copy constructure
		pointer_to_first = new T[t.vec_size];
		vec_size = t.size();
		capacity = t.size();
		memcpy(pointer_to_first,t.pointer_to_first,sizeof(T)*t.vec_size);
	}

	mvector(mvector&& t){ // move constructure
		pointer_to_first = t.pointer_to_first;
		vec_size = t.vec_size;
		capacity = t.capacity;
		t.pointer_to_first = nullptr;
		t.vec_size = 0;
		t.capacity = 0;
	}

	mvector& operator=(mvector&& t){
		if(this != &t){
			delete[] pointer_to_first;
			pointer_to_first = t.pointer_to_first;
			vec_size = t.vec_size;
			capacity = t.capacity;
			t.pointer_to_first = nullptr;
			t.vec_size = 0;
			t.capacity = 0;
		}
		return *this;
	}

	~mvector(){
		delete[] pointer_to_first;
	}

	mvector& operator=(const mvector& t) {  // copy assignment
		if(this != &t){
			allocate_memory(t.size());
			memcpy(pointer_to_first,t.pointer_to_first,sizeof(T)*t.vec_size);
			vec_size = t.size();
		}
		return *this;
	};



	void move(mvector& mv){
		while(this->size() != 0) this->pop_back();
		while(mv.size() != 0) this->push_back(mv.pop_back());
	}

	void push_back(T t) {
		if (vec_size == capacity) {
			allocate_memory(capacity * 2);
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
				allocate_memory(capacity / 2);
			}
			return result;
		}
		catch(std::string &e){
			std::cerr << "can`t pop from empty vector" << std::endl;
			return NULL;
		}
	};

	void resize(int count) {

		allocate_memory(count);
		extend(count);		
		vec_size = count;
	};

	T operator[](int index) const {
		try{
			if(index > vec_size) throw std::string("access_denied");
			return *(pointer_to_first + index);
		}
		catch(std::string &e){
			std::cerr << "access denied, request unallocated memory" << std::endl;
			return NULL;
		}
	};

	int size() const {
		return vec_size;
	};

private:

	void allocate_memory(int count){
		if(capacity >= count){
			vec_size = count;
			return;
		}
		T* new_pointer_to_first = new T[count];
		T* ptr = pointer_to_first;
		T* new_ptr = new_pointer_to_first;
		copy_values(ptr,new_ptr,count);
		delete[] pointer_to_first;
		pointer_to_first = new_pointer_to_first;
		capacity = count;
	}

	void change_pointed_values(T* pointer,T t, int size){
		for (int i = 0; i < size; i++) {
			*(pointer) = t;
			pointer++;
		}
	}
	void copy_values(T* source, T* dest, int count) {
	    if (count <= vec_size) {
	        memcpy(dest, source, count * sizeof(T));
	    } else {
	        memcpy(dest, source, vec_size * sizeof(T));
	        for (int i = vec_size; i < count; i++) {
	            *(dest + i) = T();
	        }
	    }
	}

	
	void extend(int count){
		T* sourceptr = pointer_to_first;
		T* dest = pointer_to_first + vec_size;

		for(int i=vec_size; i<count; i++){
			*(dest) = *(sourceptr);
			dest++;
			sourceptr = pointer_to_first + (((sourceptr-pointer_to_first) + 1) % vec_size);
			
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
