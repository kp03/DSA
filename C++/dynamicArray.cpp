#include<iostream>

const int INIT_CAPACITY = 2;
const int GROWTH_FACTOR = 2;

template<class T>

class Vector
{
  private:
    T *pArr;      // Create a pointer to T type dynamic array
    int capacity; // Capacity is the real size of the dynamic array 
    int _size;
    
  public:
    //Constructor
    Vector(){
      this->capacity = INIT_CAPACITY; // Initialize a dynamic array of size 2
      this->pArr = new T[capacity];   // Declare a dynamic array of type T with the init capacity
      this->size = 0;                 // Set default size to 0 since there are no element yet
    }

    //Constructor with size passed in by user
    Vector(int size){
      this->capacity = size;          // Initialize a dynamic array of size N from user input
      this->pArr = new T[capacity];   // Declare a dynamic array of type T with the user size passed in
      _size = size;
    }

    //Destructor
    ~Vector(){
      delete [] pArr;
    }

    //Return the size of the Array
    int size(){
      return _size;
    }

    //Return true if Array size is 0
    bool isEmpty(){
      return size() == 0;
    }
    
    T getElement(int index){
      return pArr[index];
    }

    void setElement(int index, T element){
      pArr[index] = element;
    }

    void add(T element){
      if(_size+1 >= capacity){
        if (capacity == 0) capacity = 1;
        else capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < _size; i++){
          newArr[i] = pArr[i];
        }
        pArr = newArr;
      }
      pArr[_size++] = element;
    }
    
    T deleteAt(int index){
      T data = pArr[index];
      T* newArr = new T[_size-1];
      for (int i = 0, j = 0; i < _size; i++, j++){
        if(i == index) j--;
        else newArr[j] = pArr[i];
      }
      pArr = newArr;
      capacity = --_size;
      return data;
    }

    bool deleteElement(T element){
      for (int i = 0; i < _size; i++){
        if(pArr[i] == element){
          deleteAt(i);
          return true;
        }
      }
      return false;
    }
    void out(int index){
      std::cout << pArr[index] << " ";
    } 
};


int main()
{
  Vector<char> charac(0);
  charac.add('k'); 
  charac.add('h');
  charac.add('a');
  charac.add('n');
  charac.add('g');
  
  for (int i = 0; i < charac.size(); i++){
    charac.out(i); 
  }
  std::cout << std::endl;
  charac.deleteElement('h');
  for (int i = 0; i < charac.size(); i++){
    charac.out(i);
  }
  std::cout << std::endl;
  char temp = charac.getElement(1);
  std::cout << "Get elements: " << temp;



  return 0;
}
