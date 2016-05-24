# Tabela de Dispersão

No código, foi implementado uma Tabela de Dispersão que usa *template* para realizar e armazenar o cadastro de determinadas contas-correntes.

## Chaves da Tabela de Dispersão

Basicamente, a mudança de cada formato de tabela consiste na chave utilizada. Foram ultilizadas três formas de chaves na tabela, são elas:

### Primeira
Esta chave tem por forma de armazenamento um inteiro que corresponde à um número de conta corrente. É definida no código como:

    using AcctKey = int;

### Segunda
Esta chave tem por forma de armazenamento um par com o nome de um cliente e o número de uma conta. É definida como:

    using AcctKey = std::pair < std::string, int >;

### Terceira
Esta chave tem por forma de armazenamento uma tupla que possui o nome de um cliente, código do banco, número da agência e da conta, do mesmo. É definida como:

    using AcctKey = std::tuple<std::string, int, int, int>;

## Como compilar
Para compilar, deve-se escolher primeiramente a estrutura a ser utilizada: one, two ou three,
que são os três possíveis de acordo com o exemplo a seguir:

`make one`, `make two` ou `make three`.

Se preferir, também pode ser utilizado

`g++ -Wall -std=c++11 src/pgm_ht.cpp -I include/ -o bin/pgm_ht -D TYPE1`, 

`g++ -Wall -std=c++11 src/pgm_ht.cpp -I include/ -o bin/pgm_ht -D TYPE2`

ou 
`g++ -Wall -std=c++11 src/pgm_ht.cpp -I include/ -o bin/pgm_ht -D TYPE3`.

Para executar basta:

`make run`
ou
`./bin/pgm_ht`.

Para verificar a existência de vazamento de memória:

`make mleak` ou `make mlfull`.

Se preferir, também pode ser utilizado

`valgrind --tool=memcheck --leak-check=yes ./bin/pgm_ht`

ou 
`valgrind --leak-check=full --show-leak-kinds=all ./bin/pgm_ht`.

## Autores
- João Victor Bezerra Barboza

- Carlos Vincius Fernandes Rodrigues

### Suporte
- Elton Viana