// João Roberto de Moraes Neto nº14801159 | Ian Marcos Gomes e Freitas nº14759041

#include <string>
#include <iostream>
using namespace std;

class Stack {
  public: 

    // Construtor da pilha, colocando top como 0, deixando-a "vazia"
    Stack(){
      top = 0;
    }

    // Método empty, retornando um bool dependendo de top ser 0, ou seja, a pilha estar "vazia"
    bool empty(){
      return top == 0;
    }

    // Método full, retornando um boll dependendo de top ser igual a MaxStack, ou seja, a pilha está cheia
    bool full(){
      return top == MaxStack;
    }

    // Método push, se a pilhar estiver cheia, printa uma mensagem, senão coloca o valor do parâmetro na pilha, e soma 1 ao indicador de posição
    void push(string x){
      if(full()){
        cout << "Pilha Cheia";
      }
      else{
        entry[top] = x;
        top++;  
      }
    }
    
    // Método pop, se a pilha estiver vazia, printa uma mensagem e retorna vazio, senão retorna o último valor da pilha, e subtrao 1 do indicador de posição
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

    // Método clear, atribui 0 ao indicador de posição, esvaziando a pilha
    void clear(){
      top = 0;
    }

    // Método getTop, se a pilha estiver vazia, printa uma mensage e retorna vazio, senão retorna o última valor da pilha
    string getTop(){
      if(empty()){
        cout << "Pilha Vazia";
        return NULL;
      }
      else{
        return entry[top-1];
      } 
    }

    // Método size, retorna o tamanho da pilha, ou seja, o valor do indicador de posição
    int size(){
      return top;
    }
        
  private: 
    // declaração das variáveis privadas da classe
    static const int MaxStack = 128;
    int top;
    string entry[MaxStack];
    
};
