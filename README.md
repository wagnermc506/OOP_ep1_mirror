# EP1 - OO 2019.1 (UnB - Gama)

Nome: Wagner Martins da Cunha
Mat.: 180029177

Bem vindo ao EP1 do Curso de Orientação a objetos. Este é um jogo de Batalha naval.

## Instruções

-Para executar o programa, vá ao terminal, e dentro da pasta ep1, digite:
```
$ make
```
e depois, para iniciar o jogo:
```
$ make run 
```

-Preferencialmente, deixar o terminal em tela maximizada quando iniciar o jogo.
-O jogo pedirá inicialmente os nomes dos 2 players, depois será pedido as linha e coluna da jogada. 
-A grade do campo tem um tamanho de 13x13.
-Para mudar as posições dos navios, vá ao arquivo doc/posicoes.txt

-O jogo conta com 3 tipos de embarcações:
-> Canoa: Ocupa uma única casa no mapa(tabuleiro);
-> Submarino: Ocupa duas casas e cada parte deve ser atingida duas vezes;
-> Porta_Aviões: Ocupa quatro casas, e é possível que ele intercepte os tiros, desta forma achando a embarcação, porém não destruindo-a;
 
Para um jogador ganhar, ele deve destruir todas as embarcações do adversário.
