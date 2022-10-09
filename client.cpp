/*
 * ============================================================================
 *
 *       Filename:  client.c
 *
 *    Description:  Simple protocol client implementation
 * ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



/* Defines the server port */
#define PORT 27015


/* Sockets buffers length */
#define LEN 4096


/* Server address */
#define SERVER_ADDR "127.0.0.1"



/*
 * Main execution of the client program of our simple protocol
 */
int
main(int argc, char *argv[]) {

    /* Server socket */
    struct sockaddr_in server;
    /* Client file descriptor for the local socket */
    int sockfd;

    int len = sizeof(server);
    int slen;

    /* Receive buffer */
    char buffer_in[LEN];
    /* Send buffer */
    char buffer_out[LEN];


    fprintf(stdout, "Starting Client ...\n");


    /*
     * Creates a socket for the client
     */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error on client socket creation:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Client socket created with fd: %d\n", sockfd);


    /* Defines the connection properties */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    memset(server.sin_zero, 0x0, 8);


    /* Tries to connect to the server */
    if (connect(sockfd, (struct sockaddr*) &server, len) == -1) {
        perror("Can't connect to server");
        return EXIT_FAILURE;
    }


    /* Receives the presentation message from the server */
    if ((slen = recv(sockfd, buffer_in, LEN, 0)) > 0) {
        buffer_in[slen + 1] = '\0';
        fprintf(stdout, "%s\n", buffer_in);
    }


    /*
     * Commuicate with the server until the exit message come
     */
    while (true) {

        /* Zeroing the buffers */
        memset(buffer_in, 0x0, LEN);
        memset(buffer_out, 0x0, LEN);

        fprintf(stdout, " ");
        fgets(buffer_out, LEN, stdin);

        /* Sends the read message to the server through the socket */
        send(sockfd, buffer_out, strlen(buffer_out), 0);

        /* Receives an answer from the server */
        slen = recv(sockfd, buffer_in, LEN, 0);
        printf("%s", buffer_in);

        /* 'bye' message finishes the connection */
        if(strcmp(buffer_in, ".") == 0) {
            break; 
           }
         else {
int cont; /*Variáveis*/
int result;
char nome[1000];

printf("\n Diga o seu nome para continuar o jogo\n\n"); /*Nome*/
if (scanf("%999s", nome)) {
printf("\n%s estava entrando pelos portões do reino, quando\nse deparou "
"com um goblin, que disse-lhe o seguinte:\n\nGoblin - Vejo que um "
"forasteiro está invadindo minha",
nome);
sleep(4);
printf("\nmorada, EU NÃO DEIXAREI BARATO, resolva essa questão\nou irei "
"lhe matar IMPIEDOSAMENTE: x = 2x, x = x e\nx = x/2... qual é "
"então o valor de x? ");
scanf("%d", &result); /*Primeira Questão*/
if (result == 0) {
printf("\n*parabéns, você acertou a questão e matou o goblin*");
printf("\n\n%s continuou então sua jornada pelo reino, e "
"logo\npercebeu que ela era maior do que imaginava, "
"então,\nquando menos esperava, outro monstro decidiu "
"prestar\nvisita ao protagonista, dessa vez um gato:\n\nGato - "
"Carne nova? Você não me parece familiar, eu",
nome);
sleep(9);
printf("\ninvado mentes sabia?? (%s começa a sentir sua\nmente "
"conturbada) se não conseguir resolver minha\ncharada, eu irei "
"confundir sua mente, e levarei-no\na mais absoluta loucura: Há "
"um pato entre dois patos,\num pato atrás de um pato e um pato "
"na frente de\noutro pato. De quantos patos estamos falando? ",
nome);
scanf("%d", &result); /*Segunda Questão*/
if (result == 3) {
printf("\n*parabéns, você resolveu a charada e passou pelo gato*");
printf("\n\nO nosso protagonista, %s, já estava vendo os portões\nda "
"fortaleza real de longe, todavia, quando se\naproximava dela "
"tropeçou numa pedra e caiu num\nburaco... levantando, um "
"morcego disse-lhe:\n\nMorcego - Bem, vejo que mais um caiu "
"na minha armadilha,",
nome);
sleep(9);
printf("\neu até posso voar contigo pra fora desse buraco, mas "
"pra\nisso o cavalheiro terá que responder uma questão "
"minha:\nSabendo-se que a = 3 e b = 6, o resultado da "
"expressão\nb(a-b) + (b+a)(b-a) -a(b-a) + (b-a)² é? ");
scanf("%d", &result); /*Terceira Questão*/
if (result == 9) {
printf("\n*parabéns, você acertou a questão e o morcego "
"voou\ncontigo para fora do buraco*");
printf("\n\nFinalmente, entrando pelos portões reais, um "
"dos\ncavaleiros reais logo parou %s, era o Davi, "
"jovem\nnovo, de cabelos loiros e lisos, encantava "
"pela\nsua beleza e destreza com os números, Davi "
"logo\ndisse o seguinte:\n\nDavi- Eu tenho acompanhado sua "
"vinda, vejo os obstáculos",
nome);
sleep(12);
printf("\nque passou, as questões que resolveu, e admiro "
"você,\npor toda sua coragem, mas creio que não passará por "
"mim...\nresolva a minha questão, ou sucumbirá em minhas "
"mãos:\nEntrei num táxi onde antes haviam 8 passageiros. "
"Pouco\ntempo depois, 3 pessoas desceram e duas "
"entraram.\nQuantas pessoas há no táxi? ");
scanf("%d", &result); /*Quarta Questão*/
if (result == 9) {
printf("\n*parabéns, você acertou a questão e Davi, de forma "
"bem\ncavalheira, deixou que você prosseguisse em sua "
"jornada*");
printf("\n\n%s estava já muito cansado de todas batalhas "
"que\nenfrentou até aqui, porém ele não iria parar "
"agora,\nentão continuou trilhando seu caminho, até "
"chegar\nnas portas do aposento real, tendo agora que "
"enfrentar\nSalomão, o chefe da guarda pessoal do "
"rei.\n\nSalomão - Ora ora, o pequeno estrangeiro se "
"mostrou um",
nome);
sleep(12);
printf("\nguerreiro nato, me concederia a honra de lutar "
"contigo?\nBrincadeira, iremos batalhar você querendo ou "
"não...\nmas uma briga matemática, lógico, então me "
"responda:\nQual é o sucessor do dobro do antecessor do "
"sucessor\ndo triplo de 2? ");
scanf("%d", &result); /*Quinta Questão*/
if (result == 13) {
printf(
"\n*parábens, você acertou a questão e finalmente\nchegou "
"no escabroso, cabuloso, temeroso... Rei □*");
printf("\n\nA grande hora chegou, o maior dos matemáticos "
"está\ncom a sua amada, e você fará de tudo para "
"tirá-la\nde seu domínio.\n\nRei □ - %s, você não sabe "
"o quanto eu esperei por",
nome);
sleep(8);
printf("\nesse momento... suas últimas palavras?\n\n%s - Você "
"será o primeiro a perder a fala entre\nnós, agora DIGA "
"A SUA QUESTÃO.\n\nRei □ - Durante uma viagem choveu 5 "
"vezes.A chuva\ncaía pela manhã ou à tarde, nunca o dia "
"todo. Houve\n6 manhãs e 3 tardes sem chuvas. Quantos "
"dias durou\na viagem? ",
nome);
scanf("%d", &result); /*Última Questão*/
if (result == 7) {
printf("\n*parábens, você derrotou o rei e reconquistou sua "
"amada*");
printf("\n\n%s - Finalmente eu libertei você, Amora, minha "
"amada!\n\nAmora - Eu tava aqui por opção própria :b",
nome);
printf("\n\n%s - É o quê? Por opção própria??\n\nAmora - É, "
"bobão, nenhum momento pedi pra você me "
"salvar...\n\n\nMoral da Estória - Não se meta onde "
"você não foi chamado.\n\n "
" Fim.",
nome);
printf("\n\n\nCréditos:\nRenan Carvalho\nFelipe "
"Moura\nGabriel Arantes");
break;
} else { /*Casos onde o usuário erra a questão*/
printf("\n *você errou a questão e foi pro beleléu*\n\n");
printf("\n\n\nCréditos:\nRenan Carvalho\nFelipe "
"Moura\nGabriel Arantes");
break;
}
} else {
printf("\n *você errou a questão e foi pro beleléu*\n\n");
printf("\n\n\nCréditos:\nRenan Carvalho\nFelipe Moura\nGabriel "
"Arantes");
break;
}
} else {
printf("\n *você errou a questão e foi pro beleléu*\n\n");
printf("\n\n\nCréditos:\nRenan Carvalho\nFelipe Moura\nGabriel "
"Arantes");
break;
}
} else {
printf("\n *você errou a questão e foi pro beleléu*\n\n");
printf("\n\n\nCréditos:\nRenan Carvalho\nFelipe Moura\nGabriel "
"Arantes");
break;
}
} else {
printf("\n *você errou a questão e foi pro beleléu*\n\n");
printf(
"\n\n\nCréditos:\nRenan Carvalho\nFelipe Moura\nGabriel Arantes");
break;
}
} else {
printf("\n *você errou a questão e foi pro beleléu*\n\n");
printf(
"\n\n\nCréditos:\nRenan Carvalho\nFelipe Moura\nGabriel Arantes");
break;
}
} else {
break;
}
        }
   }


    /* Close the connection whith the server */
    close(sockfd);

    fprintf(stdout, "\n\nConnection closed\n\n");

    return EXIT_SUCCESS;
}
