#ifndef Aluno_h

    #define Aluno_h
    #include<stdlib.h>
    #include<stdio.h>

    #define TRUE 1
    #define FALSE !TRUE
    typedef struct _aluno_ Aluno;

    #ifdef Aluno_c
        void *Aluno_create();
        void show_Aluno(void*elm, int n);
        int comp(Aluno *c, char *nome, int idade, int *temp);

    #endif // Aluno_c
#endif // Aluno_h

