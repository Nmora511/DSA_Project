// João Roberto de Moraes Neto nº14801159 | Ian Marcos Gomes e Freitas nº14759041

#include <string>
#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
  Stack* previous = new Stack();
  Stack* next = new Stack();
  
  string current = "";
  bool running = true;
  
  while(running){
    // Obtém o comando passado ao programa
    string command;
    cout << ">";
    getline(cin, command);

    // Identifica e executa o comando
    bool skip_print = false;
    if (command.rfind("novo", 0) == 0) {
      // Retira o texto "novo" do começo do comando
      command.erase(0, 4);
      if(command.empty() || command.rfind(" ") != 0){
        cout << "Por favor use \"novo <pagina>\"" << endl;
      } else {
        next->clear();
        if(!current.empty()){
          previous->push(current);
        }

        // Retira o espaço após "novo", e define a página atual como o resultado
        command.erase(0, 1);
        current = command;
      }
    }
    
    else if (command.compare("anterior") == 0) {
      if(!previous->empty()){
        next->push(current);
        current = previous->pop();
      } else {
        cout << "Erro: Não há página anterior" << endl;
      }
    } 
    
    else if (command.compare("posterior") == 0) {
      if(!next->empty()){
        previous->push(current);
        current = next->pop();
      } else {
        cout << "Erro: Não há página posterior" << endl;
      }
    } 
    
    else if (command.compare("sair") == 0) {
      running = false;
      skip_print = true;
    }
    
    else {
      cout << "Comando não identificado: " << command
      << endl  << "Favor use um desses: \"novo <site>\", \"posterior\", \"anterior\" ou \"sair\"" << endl;
    }

    // Apenas mostra se o comando não pular a etapa 
    if(!skip_print){
      string formatted = current.empty() ? "Nenhuma" : current;
      cout << "Página atual: " << formatted << "\n\n";
    }
  }
  
  return 0;
}
