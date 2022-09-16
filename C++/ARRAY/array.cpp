#include <iostream>
#include <array>

// Creating a template with type T and size S
template<typename T, size_t S>
class Array{
  
  public:
    constexpr int size() const { return S; }
  private:
    T m_Data[S]; //Create a template declaration

};


int main(){
  Array<int, 5> data;

  return 0;
}
