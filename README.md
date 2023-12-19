# Hashtable
Manipulando conjuntos com hashtable e lista ligada.

A escolha da Hashtable para representar conjuntos é justificada pelos seguintes motivos:

1. Eficiência nas Operações Básicas (Inserção, Remoção, Busca): 
- A Hashtable proporciona inserção, remoção e busca em tempo constante (O(1)) na média, devido ao acesso direto aos elementos através da função de hash.

2. Manuseio de Colisões: 
- Usando a técnica de separate chaining a estrutura trata colisões de maneira eficiente, minimizando impactos no desempenho.

3. Criação e Deleção de Tabelas: 
- Essas operações são realizadas em tempo constante, o que contribui para uma implementação eficiente.

4. Desempenho Geral Superior no Caso Médio: 
- Embora o pior caso seja O(n), situações reais geralmente resultam em desempenho superior na média.

5. Complexidade Computacional de Tempo (Big O):
- As operações específicas para conjuntos implementadas na Hashtable: <br/>
-> Pertinência (icmc_hashtbl_pertence): O(1) <br/>
-> Inserção (icmc_hashtbl_inserir): O(1) <br/>
-> Remoção (icmc_hashtbl_remover): O(1) <br/>
-> Tamanho (icmc_hashtbl_size): O(1) <br/>
-> Flatten (icmc_hashtbl_flatten): O(n) no caso médio (percorre todos os elementos para criar o array) <br/>
-> Impressão (icmc_hashtbl_imprimir): O(n log n) devido à ordenação necessária antes da impressão.

- Operações Específicas de Conjuntos: <br/>
-> União (conj_uniao): O(n) no pior caso, pois é necessário percorrer ambos os conjuntos. <br/>
-> Intersecção (conj_interseccao): O(n) no pior caso, pois percorre o menor conjunto. <br/>
-> Impressão (conj_imprimir): O(n log n) devido à necessidade de ordenação antes da impressão. <br/>

Conclusão: <br/>
- A escolha da Hashtable para implementar conjuntos oferece uma solução eficiente para as operações básicas, com desempenho satisfatório em operações específicas de conjuntos. A complexidade computacional varia de O(1) para operações básicas a O(n*log(n)) para a impressão ordenada. Considerando a natureza dos conjuntos e o equilíbrio entre eficiênciae complexidade, a Hashtable é uma escolha sólida para implementar conjuntos numéricos.

_OBS_: as complexidades foram calculadas no caso médio, o pior caso é O(n), quando todos os elementos estão na mesma posição da tabela, uma condição muito improvável.
