# Hora do Combate!

## Desenvolvedores:

* Fabio Amorelli Vieira Filho - 2020000253

* Felipe Mendonça - 2018006788

* Guilherme Costa Lopes - 2018009912

* Luiz Felipe de Souza - 2018005628

## Funcionamento:

O jogo tem inspiração em RPG de turnos e se baseia em batalhas nas quais você 
pode escolher atacar ou defender.

Existem 5 classes com atributos diferentes pré-definidos:

- Espadachim
- Atirador
- Ladrão
- Padre
- Mago

Para ganhar o jogo, você deve lutar contra cinco inimigos, um de cada classe. Os
inimigos têm seus atributos gerados aleatoriamente.

Ao derrotar um inimigo, você sobe de nível e pode aumentar um de seus 5 atributos
base, que são:

- Força
- Destreza
- Agilidade
- Conhecimento
- Vitalidade

## Instalação:

Para instalar o jogo, basta baixar o arquivo .exe nas [releases](https://github.com/fabioavf/hora-do-combate/releases) e rodá-lo.

## Compilação:

Para compilar o jogo, basta clonar o projeto e executar o comando a seguir na
pasta base.

    g++ -std=c++2a src/main.cpp src/personagens.cpp -o hora-do-combate.exe

Para rodar o jogo, basta executar `hora-do-combate.exe`.