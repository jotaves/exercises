# List ADT
Esse projeto é baseado em uma ADT (List Abstract Data Type, em inglês), a qual foi implementada de três maneiras, um "Dynamic Array" (std::vector), "Singly Linked List" (std::foward_list) e "Double Linked List" (std::list).

## Como rodar

Abra o terminal e acesse a pasta do projeto, em seguida compile usando

`g++ -Wall -std=c++11 src/drive.cpp -o bin/drive -I include/`

Após isso, basta executar usando

`./bin/drive`

Para checar se há vazamento de memória, utilizando o Valgrind, digite

`valgrind --leak-check=full --show-leak-kinds=all ./bin/drive`

## Métodos não implementados
 - Iteradores e alguns métodos da classe Forward List.
 - Todos os métodos da classe List.

## Autores
 - João Victor Bezerra Barboza
 - Carlos Vinicius Fernandes Rodrigues

## Agradecimentos
 - Elton Viana (what is *this?)