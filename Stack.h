#include <string>
#include <iostream>
using namespace std;

class Stack {
  public: 
    
    Stack(){
      top = 0;
    }
    
    bool empty(){
      return top == 0;
    }
    
    bool full(){
      return top == MaxStack;
    }
    
    void push(string x){
      if(full()){
        cout << "Pilha Cheia";
      }
      else{
        entry[top] = x;
        top++;  
      }
    }
    
    string pop(void){
      if(empty()){
        cout << "Pilha Vazia";
        return NULL;
      }
      else{
        string pop = entry[top - 1];
        top--;
        return pop;
      }
    }

    void clear(){
      top = 0;
    }

    string getTop(){
      return entry[top-1];
    }

    int size(){
      return top;
    }
        
  private: 
    static const int MaxStack = 128;
    int top;
    string entry[MaxStack];
    
};
