
    #ifndef List_c
        #define List_c

        #include"List.h"
        //-------------------------------------------------------------------------------//
    /* Struct para o resto dos elementos da lista*/
    typedef struct Next_{
        struct Next_ *next;
        void **data;
    }Next;
    /*Struct que guarda o primeiro e o ultimo da lista*/
    typedef struct List_{
        int nelms;
        Next *first;
        Next *last;
    }List;
//-------------------------------------------------------------------------------//
   /*Aloca um na memoria um ponteiro do tipo lista e  pre seta os valores iniciais de uma lista, 0 elementos, o primeiro e ultimo como NULL*/
    List *List_Create(){
       List *l = (List*)malloc(sizeof(List));

       if(l != NULL){
            l->nelms = 0;
            l->first = NULL;
            l->last = NULL;
            return l;

       }

    }
//-------------------------------------------------------------------------------//
   /*Checa se nao existem elementos na lista para que possa ser destruido*/
    int List_Dex(List *l, int*n ){
        if(l != NULL){
            if(l->nelms == 0 && l->first == NULL && l->last == NULL){
                free(l);
                *n = 1;
                printf("Sucess \n");
                return TRUE;
            }else{
                printf("Already have elms");
            }
        }
        printf("error dex");
        return FALSE;
    }
//---------------------------------------------------------------------------------//
    /*Para adicionar um elemento na lista, primeiro aloca-se um ponteiro do tipo Next e nele aloca-se um ponteiro do tipo aluno e preenche os dados*/
    int add_List(List *l, int *aloca2){
        if(l != NULL){
            Next *n = (Next*)malloc(sizeof(Next));
            if(n != NULL){

                if(n->data != NULL){
                    n->data = Aluno_Create();
                    n->next = NULL;
                    if(l->first == NULL){ /*Se a lista estiver vazia, ele vira o primeiro e o ultimo elemento da lista*/
                        l->first = n;
                        l->last = l->first;
                        l->nelms++;
                        *aloca2 = 2; /*atualiza o ponteiro para que o sistema reconheca que ja existe uma lista alocada*/
                        return TRUE;
                    }else{
                        /*o ultimo é armazenado em um auxiliar e o novo elemento da lista é armazenado em last e o next do auxiliar é o last*/
                        Next *aux ;

                        aux = l->last;
                        aux->next = n;
                        l->last = n;
                        l->nelms++;
                        *aloca2 = 2;
                        return TRUE;


                    }
                }else{
                    printf("Error malloc2");
                }
            }else{
                printf("Error malloc 1");
            }

        }
        printf("List doesnt exists");
        return FALSE;
    }
//---------------------------------------------------------------------//


    int remove_List(List *l, char *nome,int idade){
        if(l!= NULL){
            /*utiliza-se duas varaiveis, aux para os  valores recentes e aux para o anterior*
            /*o loop para quando se acha um elemento da lista igual ao nome e idade fornecidos ou se chegar ao ultimo da lista*/
            /*caso ache, a variavel temp fica igual a 1*/

            Next *aux = l->first;
            Next *aux2;
            int temp = 0;

                while(comp(aux->data,nome,idade, &temp)!= TRUE && aux->next != NULL){
                    aux2 = aux;
                    aux = aux->next;
                }

                if(temp == 1){
                    /*se aux nao for o primeiro, o valor anterior do elemento achado (aux2) recebe como next o elemento posterior ao valor achado (aux->next) aux2->next = aux->next*/
                    if(aux != l->first){

                        aux2->next = aux->next;
                        /*se aux2 == NULL quer dizer que o elemento escolhido é o ultimo e o aux2 se tor o ultimo (l->last = aux2)*/
                        if(aux2->next == NULL){
                            l->last = aux2;
                        }
                        free(aux->data);
                        free(aux);
                        l->nelms--;
                        return TRUE;
                    }else{
                        /*se o elemento escolhido for o primeiro, o proximo elemento se torna o primeiro e o ultimo (*/
                        aux2 = aux->next;
                        l->last = aux2;
                        free(aux->data);
                        free(aux);
                        l->first =aux2;
                        l->nelms--;
                        return TRUE;
                    }
                }else{
                    printf(" not found");
                }


        }
            return FALSE;
    }


//-----------------------------------------------------------//

    void List_show_spec(List *l, char *nome, int idade){
        if(l != NULL){
            Next *aux = l->first;
            int cont = 1;
            int temp = 0;
            if(aux != NULL){

                while(comp(aux->data,nome,idade, &temp) != TRUE && aux ->next != NULL){
                    aux = aux->next;
                    cont++;
                }
                    if(temp == 1){
                    show_Aluno(aux->data, cont);
                    }else{
                    printf(" not found \n");
                    }
            }else{
                printf("Void List \n");
            }


        }
    }
    void List_show_all(List *l){
        if(l != NULL){
            Next *aux = l->first;
            int cont = 1;
            if(aux != NULL){

                while(aux->next != NULL){

                    show_Aluno(aux->data,cont);
                    aux = aux->next;
                    cont++;
                }
                show_Aluno(aux->data,cont);
            }else{
                printf("Void List \n");
                printf("Elms = %d \n", l->nelms);
            }

        }
    }

    #endif // List_c


