#include"List.h"
#include"Aluno.h"

int main(){

    List *l;

    int loop = TRUE;
    int aloca1 = 1;
    int aloca2 = 1;
    while(loop == TRUE){
        system("CLS");

        char opt;

        printf("-----------------------------Lista Manage ------------------------------- \n");
        printf(" a) Cria lista \n b) Destroi lista \n c) Inserir dados T \n d) Consultar estrutura T \n e) Remover estrutura T \n f) Listar estruturas \n g) Sair \n");

        if(aloca2 == 2){
            List_show_all(l);
        }

        fflush(stdin);
        scanf("%c", &opt);


        if(opt == 'a'){


                if(aloca1 == 1){
                    l = List_Create();
                    aloca1++;
                    printf("Sucess \n");
                }else{
                    printf(" List already exists \n");
                }




        }

        if(opt == 'b'){

            if(aloca1 == 2){
                int result = List_Dex(l, &aloca1);
                if(result == TRUE){
                    aloca1 = 1;
                    aloca2 = 1;
                }


            }else{

                printf(" Lista nao existe \n");
            }



        }

        if(opt == 'c'){
            if(aloca1 == 2){


                add_List(l, &aloca2);






            }else{
                printf(" Lista inexistente \n");
            }
        }

        if(opt == 'd'){
            if(aloca2 == 2){
                char p[20];
                int idade;
                printf(" Informe o nome = ");
                scanf("%s", &p);
                printf("\n Informe a idade =  ");
                scanf("%d", &idade);
                int cont = 0;
                for(int i = 0 ; p[i] != '\0' ; i++){
                    cont++;
                }
                char nome[cont];

                strcpy(nome,p);

                List_show_spec(l, nome,idade);
            }else{
                printf(" Empty \n");
            }




        }

        if(opt == 'e'){
            if(aloca2 == 2 && aloca1 == 2){
                char p[20];
                int idade;
                printf(" Informe o nome = ");
                scanf("%s", &p);
                printf("\n Informe a idade =  ");
                scanf("%li", &idade);
                int cont = 0;
                for(int i = 0 ; p[i] != '\0' ; i++){
                    cont++;
                }
                char nome[cont];

                strcpy(nome,p);

                remove_List(l,nome,idade);
            }else{
                printf(" Empty\n");
            }

        }

        if(opt == 'f'){
            if(aloca2 == 2){
                List_show_all(l);
            }else{
                printf("Empty(s) \n");
            }


        }

        if(opt == 'g'){
            loop = FALSE;
        }

       getch();
        int clrscr();

    }
    free(l);

    return 0;
}
