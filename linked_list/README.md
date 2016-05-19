# Lista encadeada

### Informações

- Aluno: João Victor Bezerra Barboza.
- E-mail: victorbarboza@outlook.com.

### Resumo

Uma lista encadeada é uma sequência encadeada de elementos (nós) em que cada nó possui a informação armazenada e um ponteiro para o próximo elemento. O primeiro elemento da lista recebe o ponteiro pHead e o último nó sempre terá como nulo o ponteiro para o próximo elemento.

Nesse projeto, foi feita uma lista encadeada dividida em três arquivos:

- **include/les_v1.h**, que possui os protótipos da lista;
- **src/les_v1.cpp**, em que a lista foi implementada;
- e **src/drive_les_v1.cpp**, que foi utilizado para fazer testes na lista.

### Versão

1.0.0

### Bugs e limitações

Não foram encontrados bugs ou limitações. Porém, isso não garante o pleno funcionamento da lista. Outros bugs e limitações ainda poderão ser encontrados e consertados posteriormente.

### Instalação

Para instalação, deve-se fazer os seguintes passos:

**Compilação**

```sh
$ g++ -Wall -std=c++11 src/drive_les_v1.cpp src/les_v1.cpp -o bin/drive_les_v1 -I include/
```

**Execução**

```sh
$ ./bin/drive_les_v1
```
