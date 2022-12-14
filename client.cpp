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
int cont; /*Vari??veis*/
int result;
char nome[1000];

printf("\n Diga o seu nome para continuar o jogo\n\n"); /*Nome*/
if (scanf("%999s", nome)) {
printf("\n%s estava entrando pelos port??es do reino, quando\nse deparou "
"com um goblin, que disse-lhe o seguinte:\n\nGoblin - Vejo que um "
"forasteiro est?? invadindo minha",
nome);
sleep(4);
printf("\nmorada, EU N??O DEIXAREI BARATO, resolva essa quest??o\nou irei "
"lhe matar IMPIEDOSAMENTE: x = 2x, x = x e\nx = x/2... qual ?? "
"ent??o o valor de x? ");
scanf("%d", &result); /*Primeira Quest??o*/
if (result == 0) {
printf("\n*parab??ns, voc?? acertou a quest??o e matou o goblin*");
printf("\n\n%s continuou ent??o sua jornada pelo reino, e "
"logo\npercebeu que ela era maior do que imaginava, "
"ent??o,\nquando menos esperava, outro monstro decidiu "
"prestar\nvisita ao protagonista, dessa vez um gato:\n\nGato - "
"Carne nova? Voc?? n??o me parece familiar, eu",
nome);
sleep(9);
printf("\ninvado mentes sabia?? (%s come??a a sentir sua\nmente "
"conturbada) se n??o conseguir resolver minha\ncharada, eu irei "
"confundir sua mente, e levarei-no\na mais absoluta loucura: H?? "
"um pato entre dois patos,\num pato atr??s de um pato e um pato "
"na frente de\noutro pato. De quantos patos estamos falando? ",
nome);
scanf("%d", &result); /*Segunda Quest??o*/
if (result == 3) {
printf("\n*parab??ns, voc?? resolveu a charada e passou pelo gato*");
printf("\n\nO nosso protagonista, %s, j?? estava vendo os port??es\nda "
"fortaleza real de longe, todavia, quando se\naproximava dela "
"trope??ou numa pedra e caiu num\nburaco... levantando, um "
"morcego disse-lhe:\n\nMorcego - Bem, vejo que mais um caiu "
"na minha armadilha,",
nome);
sleep(9);
printf("\neu at?? posso voar contigo pra fora desse buraco, mas "
"pra\nisso o cavalheiro ter?? que responder uma quest??o "
"minha:\nSabendo-se que a = 3 e b = 6, o resultado da "
"express??o\nb(a-b) + (b+a)(b-a) -a(b-a) + (b-a)?? ??? ");
scanf("%d", &result); /*Terceira Quest??o*/
if (result == 9) {
printf("\n*parab??ns, voc?? acertou a quest??o e o morcego "
"voou\ncontigo para fora do buraco*");
printf("\n\nFinalmente, entrando pelos port??es reais, um "
"dos\ncavaleiros reais logo parou %s, era o Davi, "
"jovem\nnovo, de cabelos loiros e lisos, encantava "
"pela\nsua beleza e destreza com os n??meros, Davi "
"logo\ndisse o seguinte:\n\nDavi- Eu tenho acompanhado sua "
"vinda, vejo os obst??culos",
nome);
sleep(12);
printf("\nque passou, as quest??es que resolveu, e admiro "
"voc??,\npor toda sua coragem, mas creio que n??o passar?? por "
"mim...\nresolva a minha quest??o, ou sucumbir?? em minhas "
"m??os:\nEntrei num t??xi onde antes haviam 8 passageiros. "
"Pouco\ntempo depois, 3 pessoas desceram e duas "
"entraram.\nQuantas pessoas h?? no t??xi? ");
scanf("%d", &result); /*Quarta Quest??o*/
if (result == 9) {
printf("\n*parab??ns, voc?? acertou a quest??o e Davi, de forma "
"bem\ncavalheira, deixou que voc?? prosseguisse em sua "
"jornada*");
printf("\n\n%s estava j?? muito cansado de todas batalhas "
"que\nenfrentou at?? aqui, por??m ele n??o iria parar "
"agora,\nent??o continuou trilhando seu caminho, at?? "
"chegar\nnas portas do aposento real, tendo agora que "
"enfrentar\nSalom??o, o chefe da guarda pessoal do "
"rei.\n\nSalom??o - Ora ora, o pequeno estrangeiro se "
"mostrou um",
nome);
sleep(12);
printf("\nguerreiro nato, me concederia a honra de lutar "
"contigo?\nBrincadeira, iremos batalhar voc?? querendo ou "
"n??o...\nmas uma briga matem??tica, l??gico, ent??o me "
"responda:\nQual ?? o sucessor do dobro do antecessor do "
"sucessor\ndo triplo de 2? ");
scanf("%d", &result); /*Quinta Quest??o*/
if (result == 13) {
printf(
"\n*par??bens, voc?? acertou a quest??o e finalmente\nchegou "
"no escabroso, cabuloso, temeroso... Rei ???*");
printf("\n\nA grande hora chegou, o maior dos matem??ticos "
"est??\ncom a sua amada, e voc?? far?? de tudo para "
"tir??-la\nde seu dom??nio.\n\nRei ??? - %s, voc?? n??o sabe "
"o quanto eu esperei por",
nome);
sleep(8);
printf("\nesse momento... suas ??ltimas palavras?\n\n%s - Voc?? "
"ser?? o primeiro a perder a fala entre\nn??s, agora DIGA "
"A SUA QUEST??O.\n\nRei ??? - Durante uma viagem choveu 5 "
"vezes.A chuva\nca??a pela manh?? ou ?? tarde, nunca o dia "
"todo. Houve\n6 manh??s e 3 tardes sem chuvas. Quantos "
"dias durou\na viagem? ",
nome);
scanf("%d", &result); /*??ltima Quest??o*/
if (result == 7) {
printf("\n*par??bens, voc?? derrotou o rei e reconquistou sua "
"amada*");
printf("\n\n%s - Finalmente eu libertei voc??, Amora, minha "
"amada!\n\nAmora - Eu tava aqui por op????o pr??pria :b",
nome);
printf("\n\n%s - ?? o qu??? Por op????o pr??pria??\n\nAmora - ??, "
"bob??o, nenhum momento pedi pra voc?? me "
"salvar...\n\n\nMoral da Est??ria - N??o se meta onde "
"voc?? n??o foi chamado.\n\n "
" Fim.",
nome);
printf("\n\n\nCr??ditos:\nRenan Carvalho\nFelipe "
"Moura\nGabriel Arantes");
break;
} else { /*Casos onde o usu??rio erra a quest??o*/
printf("\n *voc?? errou a quest??o e foi pro belel??u*\n\n");
printf("\n\n\nCr??ditos:\nRenan Carvalho\nFelipe "
"Moura\nGabriel Arantes");
break;
}
} else {
printf("\n *voc?? errou a quest??o e foi pro belel??u*\n\n");
printf("\n\n\nCr??ditos:\nRenan Carvalho\nFelipe Moura\nGabriel "
"Arantes");
break;
}
} else {
printf("\n *voc?? errou a quest??o e foi pro belel??u*\n\n");
printf("\n\n\nCr??ditos:\nRenan Carvalho\nFelipe Moura\nGabriel "
"Arantes");
break;
}
} else {
printf("\n *voc?? errou a quest??o e foi pro belel??u*\n\n");
printf("\n\n\nCr??ditos:\nRenan Carvalho\nFelipe Moura\nGabriel "
"Arantes");
break;
}
} else {
printf("\n *voc?? errou a quest??o e foi pro belel??u*\n\n");
printf(
"\n\n\nCr??ditos:\nRenan Carvalho\nFelipe Moura\nGabriel Arantes");
break;
}
} else {
printf("\n *voc?? errou a quest??o e foi pro belel??u*\n\n");
printf(
"\n\n\nCr??ditos:\nRenan Carvalho\nFelipe Moura\nGabriel Arantes");
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
