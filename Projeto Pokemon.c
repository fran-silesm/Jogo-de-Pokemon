#include <stdio.h>
#include <string.h>
#include <time.h>

#define VAZIO ' '
#define PAREDE1 '-'
#define PAREDE2 '|'
#define PAREDE3 '+'
#define JOGADOR 'A'
#define AGUA '~'
#define GELO '@'
#define TERRA '-'
#define FOGO '*'
#define ELETRICIDADE 'z'
#define SELVAGEM 'X'

typedef struct pokemons
{
  char nome[50];
  int level;
  int tipo;
} pokemon_t;

void inicializa_Mapa (char campo[21][21])
{
  int i=0,j=0, posS;
  srand(time(NULL));
  //mapa vazio
  for(i=0;i<21;i++)
  {
    for(j=0;j<21;j++)
    {
      campo[i][j] = VAZIO;            
      if ((i==0) || (i==20))
      {
        campo [i][j] = PAREDE1;
      }
      if ((j == 0) || (j == 20))
      {
        campo [i][j] = PAREDE2;
      }
      campo[0][0] = PAREDE3;
      campo[20][0] = PAREDE3;
      campo[0][20] = PAREDE3;
      campo[20][20] = PAREDE3;    
    }
  }
  //sorteia poke selvagem
  pokemon_t selvagem[5];
  for(posS=0; posS<5; posS++)
  {
    i = 1 + (rand() % 19);
    j = 1 + (rand() % 19);
    campo[i][j] = SELVAGEM;
  }  
}

void inicializa_Bioma (char campo[21][21])
{
  int i=0,j=0;
  //sorteia Bioma
  for(i=0;i<21;i++)
  {
    for(j=0;j<21;j++)
    {
      campo[i][j] = (rand() % 5) + 1;        
      if (campo[i][j] == 1)
      {
        campo[i][j]=AGUA;   
      } else if (campo[i][j] == 2)
      {
        campo[i][j]=GELO;   
      } else if (campo[i][j] == 3)
      {
        campo[i][j]=TERRA;   
      }else if (campo[i][j] == 4)
      {
        campo[i][j]=FOGO;   
      }else if (campo[i][j] == 5)
      {
        campo[i][j]=ELETRICIDADE;   
      }
    }
  }
  /*for(i=0;i<20;i++)
  {
    for(j=0;j<20;j++)
    {
      printf("%c ", campo[i][j]);
    }
    printf("\n");
  }*/
}

void desenha_Mapa(char campo[21][21], int col_jogador,int lin_jogador)
{
  int i=0,j=0;  
  for(i=0;i<21;i++)
  {
    for(j=0;j<21;j++)
    {
      if ((j==col_jogador) && (i==lin_jogador))
      {
       printf("A ");
      } else 
      {
        printf("%c ", campo[i][j]);
      }
    }
    printf("\n");
  }
}

int main()
{
  char mapa[20][20], campoM[21][21], campoB[21][21], dig = 0;
  int col_jogador = 10, lin_jogador = 10;
  int i=0, j=0, escS, escP, k, din=1000;
  
  //pokes do usuário
  pokemon_t SEUS[5];
  for(i=0;i<5;i++)
  {
    printf("Digite o nome do seu %dº pokémon:\n", i + 1);
    scanf("%s", SEUS[i].nome);
    printf("Digite o level de seu pokémon de 0 a 100:\n");
    scanf("%d", &SEUS[i].level);
    printf("Qual o tipo do seu pokémon?\n\n1-Água\n2-Gelo\n3-Terra\n4-Fogo\n5-Eletricidade \nDigite o numero do tipo:\n");
    scanf("%d", &SEUS[i].tipo);
    printf("\n");
  }
  printf("Seus pokémons:");
  for(i=0;i<5;i++)
  {
    switch (SEUS[i].tipo)
    {
      case 1:printf("\nNome: %s \nLevel: %d \nTipo: Agua\n\n", SEUS[i].nome, SEUS[i].level);
      SEUS[i].tipo=AGUA;
      break;
      case 2:printf("\nNome: %s \nLevel: %d \nTipo: Gelo\n\n", SEUS[i].nome, SEUS[i].level);
      SEUS[i].tipo=GELO;
      break;
      case 3:printf("\nNome: %s \nLevel: %d \nTipo: Terra\n\n", SEUS[i].nome, SEUS[i].level);
      SEUS[i].tipo=TERRA;
      break;
      case 4:printf("\nNome: %s \nLevel: %d \nTipo: Fogo\n\n", SEUS[i].nome, SEUS[i].level);
      SEUS[i].tipo=FOGO;
      break;
      case 5:printf("\nNome: %s \nLevel: %d \nTipo: Eletricidade\n\n", SEUS[i].nome, SEUS[i].level);
      SEUS[i].tipo=ELETRICIDADE;
      break;
      default:printf("Informação não compatível!\n");
    }
    printf("-----------------------------------------------\n");
  }
  //poke selvagem
  pokemon_t selvagem[5];
  for(i=0;i<5;i++)
  {
    printf("Digite o nome do %dº pokémon selvagem: \n",i+1);
    scanf("%s", selvagem[i].nome);
    printf("O level do pokémon será sorteado durante o jogo. \n");
    printf("Qual o tipo do pokemon? \n\n1- Agua \n2- Gelo \n3- Terra\n4- Fogo\n5- Eletretricidade\n");
    scanf("%d", &selvagem[i].tipo);
    printf("\n");
  }
  printf("Pokémons selvagens: \n");
  for(j=0;j<5;j++)
  {
    switch (selvagem[j].tipo)
    {
      case 1:printf ("\nNome: %s \nTipo: Agua\n\n", selvagem[j].nome);
      selvagem[j].tipo=AGUA;
      break;
      case 2:printf ("\nNome: %s\nTipo: Gelo\n\n", selvagem[j].nome);
      selvagem[j].tipo=GELO;
      break;
      case 3:printf ("\nNome: %s\nTipo: Terra\n\n", selvagem[j].nome);
      selvagem[j].tipo=TERRA;
      break;
      case 4:printf ("\nNome: %s\nTipo: Fogo\n\n", selvagem[j].nome);
      selvagem[j].tipo=FOGO;
      break;
      case 5:printf ("\nNome: %s\nTipo: Eletricidade\n\n", selvagem[j].nome);
      selvagem[j].tipo=ELETRICIDADE;
      break;
      default:printf ("Informação inválida!\n");
    }
    printf("-----------------------------------------------\n");
  }
  
  printf("Bem-vindo ao mundo Pokemon. Vá ao encontro de X para descobrir qual pokemon você vai enfrentar em uma batalha. Você tem %d$ e pode ganhar mais dinheiro se vencer uma luta!\n\n", din);
  inicializa_Bioma(campoB);
  inicializa_Mapa(campoM);
  desenha_Mapa(campoM, col_jogador, lin_jogador);
  printf("Instruções: A - Esquerda D - Direita W - Cima S - Baixo\n");

  do{
    //movimento do jogador
    while(campoM[lin_jogador][col_jogador] != SELVAGEM)
    {
      scanf("%s", &dig);
      if((dig == 'a' || dig == 'A') && (col_jogador > 1))
      {
        col_jogador--;
        desenha_Mapa(campoM, col_jogador,lin_jogador);
        printf("Instruções: A - Esquerda D - Direita W - Cima S - Baixo\n");
      }else if((dig == 'd' || dig == 'D') && (col_jogador < 19))
      {
        col_jogador++;
        desenha_Mapa(campoM, col_jogador,lin_jogador);
        printf("Instruções: A - Esquerda D - Direita W - Cima S - Baixo\n");        
      } else if((dig == 'w' || dig == 'W') && (lin_jogador > 1))
      {      
        lin_jogador--;
        desenha_Mapa(campoM, col_jogador,lin_jogador);
        printf("Instruções: A - Esquerda D - Direita W - Cima S - Baixo\n");
      }else if((dig == 's' || dig == 'S') && (lin_jogador < 19))
      {      
        lin_jogador++;
        desenha_Mapa(campoM, col_jogador,lin_jogador);
        printf("Instruções: A - Esquerda D - Direita W - Cima S - Baixo\n");
      }
    }
    srand(time(NULL));
    escP = rand()%5 + 1;
    selvagem[escP].level = rand()%100 + 1;
    if(campoB[lin_jogador][col_jogador]==AGUA)
    {
      if(selvagem[escP].tipo == AGUA)
      {
        selvagem[escP].level += 20;
        printf("Você encontrou o Pokémon %s em um Campo de Água. Por conta de seu elemento e do ambiente que está, ele ganha 20 pontos extras.\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }else{
        printf("Você encontrou o Pokémon %s em um Campo de Agua\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }      
    }else if (campoB[lin_jogador][col_jogador]==GELO)
    {
     if(selvagem[escP].tipo == GELO)
      {
        selvagem[escP].level += 20;
        printf("Você encontrou o Pokémon %s em um Campo de Gelo. Por conta de seu elemento e do ambiente que está, ele ganha 20 pontos extras.\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }else{
        printf("Você encontrou o Pokémon %s em um Campo de Gelo\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }
    }else if (campoB[lin_jogador][col_jogador]==TERRA)
    {
      if(selvagem[escP].tipo == TERRA)
      {
        selvagem[escP].level += 20;
        printf("Você encontrou o Pokémon %s em um Campo de Terra. Por conta de seu elemento e do ambiente que está, ele ganha 20 pontos extras.\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }else{
        printf("Você encontrou o Pokémon %s em um Campo de Terra\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }
    }else if (campoB[lin_jogador][col_jogador]==FOGO)
    {
      if(selvagem[escP].tipo == FOGO)
      {
        selvagem[escP].level += 20;
        printf("Você encontrou o Pokémon %s em um Campo de Fogo. Por conta de seu elemento e do ambiente que está, ele ganha 20 pontos extras.\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }else{
        printf("Você encontrou o Pokémon %s em um Campo de Fogo\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }
    } else if(campoB[lin_jogador][col_jogador]==ELETRICIDADE)
    {
      if(selvagem[escP].tipo == ELETRICIDADE)
      {
        selvagem[escP].level += 20;
        printf("Você encontrou o Pokémon %s em um Campo de Eletricidade. Por conta de seu elemento e do ambiente que está, ele ganha 20 pontos extras.\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }else{
        printf("Você encontrou o Pokémon %s em um Campo de Eletricidade\n", selvagem[escP].nome);
        printf("Nível do %s: %d\n", selvagem[escP].nome, selvagem[escP].level);
      }
    }
    printf("Relembrando seus Pokemons e avisando que alguns deles pode ganhar 20 pontos extra por estar num campo que favorece seus poderes.\n");
    for(i=0;i<5;i++)
    {
      printf("Digite %d para escolher\nNome: %s \nLevel: %d \n\n", i+1, SEUS[i].nome, SEUS[i].level);
      printf("-----------------------------------------------\n\n");
    }
    printf("Escolha o número do seu pokemon para a batalha:\n");
    scanf("%d", &escS);
    if(campoB[lin_jogador][col_jogador]==AGUA && SEUS[escS].tipo==AGUA){
      SEUS[i].level+=20;
      printf("O %s ganhou 20 pontos por estar num Campo de Agua.\n", SEUS[i].nome);
    }else if(campoB[lin_jogador][col_jogador]==GELO && SEUS[escS].tipo==GELO){
      SEUS[i].level+=20;
      printf("O %s ganhou 20 pontos por estar num Campo de Gelo.\n", SEUS[i].nome);
    }else if(campoB[lin_jogador][col_jogador]==TERRA && SEUS[escS].tipo==TERRA){
      SEUS[i].level+=20;
      printf("O %s ganhou 20 pontos por estar num Campo de Terra.\n", SEUS[i].nome);
    }else if(campoB[lin_jogador][col_jogador]==FOGO && SEUS[escS].tipo==FOGO){
      SEUS[i].level+=20;
      printf("O %s ganhou 20 pontos por estar num Campo de Fogo.\n", SEUS[i].nome);
    }else if(campoB[lin_jogador][col_jogador]==ELETRICIDADE && SEUS[escS].tipo==ELETRICIDADE){
      SEUS[i].level+=20;
      printf("O %s ganhou 20 pontos por estar num Campo de Eletricidade.\n", SEUS[i].nome);
    }
    if(selvagem[escP].level > SEUS[escS].level)
    {
      din -= 50;
      printf("Você foi derrotado e perdeu 50$ :(\nSaldo: %d$\n", din);
      lin_jogador++;
    }else
    {
      din += 75;
      printf("Você venceu e ganhou 75$!!!\nSaldo: %d$\n", din);
      campoM[lin_jogador][col_jogador] = VAZIO;
    }
    desenha_Mapa(campoM, col_jogador,lin_jogador);
    printf("Voce quer continuar jogando? Aperte 1 para continuar e 0 para sair.\n");
    scanf("%d", &k);
  }while(k != 0);
  printf("Saldo final: %d$\n",din);
  printf("GAME OVER");

  return 0;
}