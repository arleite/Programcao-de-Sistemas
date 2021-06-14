#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int main()
{
    int a=1,b=1,c=1,opc1,opc2,opc3,opc4;
    int letras = 0, aux, contador, id, opcao;
    char caminho[100], contadorString [100], iString[100], result, linha[100];

    FILE * fileF3;
    FILE *fileF2;
    FILE *fileF;
    FILE *fileContadorFuncionario;
    FILE *fileContadorStock;
    FILE *fileContadorCliente;
    FILE *fileContadorPequenoAlmoco;
    FILE *fileContadorAlmoco;
    FILE *fileContadorLanche;
    FILE *fileContadorJantar;
    FILE *fileContadorSobremesa;
    FILE *fileContadorBebida;


    //funcoes
    void contadorInteiroFuncionarios(){
        fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "r");
        fscanf(fileContadorFuncionario, "%d", &contador);
    }
    void contadorInteiroProduto(){
        fileContadorStock = fopen ("Files/Produtos/ContadorProdutos.txt", "r");
        fscanf(fileContadorStock, "%d", &contador);
    }
    void contadorInteiroPequenoAlmoco() {
        fileContadorPequenoAlmoco = fopen ("Files/Ementas/PequenoAlmoco/ContadorPequenoAlmoco.txt", "r");
        fscanf(fileContadorPequenoAlmoco, "%d", &contador);
    }
    void contadorInteiroAlmoco(){
        fileContadorAlmoco = fopen ("Files/Ementas/Almoco/ContadorAlmoco.txt", "r");
        fscanf(fileContadorAlmoco, "%d", &contador);
    }
    void contadorInteiroLanche(){
        fileContadorLanche = fopen ("Files/Ementas/Lanche/ContadorLanche.txt", "r");
        fscanf(fileContadorLanche, "%d", &contador);
    }
    void contadorInteiroJantar(){
        fileContadorJantar = fopen ("Files/Ementas/Jantar/ContadorJantar.txt", "r");
        fscanf(fileContadorJantar, "%d", &contador);
    }
    void contadorInteiroSobremesa(){
        fileContadorSobremesa = fopen ("Files/Ementas/Sobremesa/ContadorSobremesa.txt", "r");
        fscanf(fileContadorSobremesa, "%d", &contador);
    }
    void contadorInteiroBebida(){
        fileContadorBebida = fopen ("Files/Ementas/Bebida/ContadorBebida.txt", "r");
        fscanf(fileContadorBebida, "%d", &contador);
    }
    void contadorInteiroClientes(){
        fileContadorCliente = fopen ("Files/Clientes/ContadorClientes.txt", "r");
        fscanf(fileContadorCliente, "%d", &contador);
    }

    while (a==1)
    {
        mkdir("Files", 0777);
        printf(YELLOW"\n--------------Menu----------------\n"RESET);
        printf(CYAN"\n1 - Gestao da Empresa\n"RESET);
        printf(CYAN"2 - Cliente\n"RESET);
        printf(RED"\n0 - Sair\n"RESET);
        printf(GREEN"Selecione uma opcao: "RESET);
        scanf("%d", &opc1);

        system("cls");

        b=1;
        while (b==1)
        {
            switch (opc1)
            {
            case 1:
                printf(YELLOW"\n--------------Gestao da Empresa----------------\n"RESET);
                printf(CYAN"\n1 - Gerir funcionarios\n"RESET);
                printf(CYAN"2 - Gerir stock\n"RESET);
                printf(CYAN"3 - Gerir ementa\n"RESET);
                printf(CYAN"4 - Gerir clientes\n"RESET);
                printf(CYAN"5 - Dinheiro total\n"RESET);
                printf(RED"\n0 - Voltar\n"RESET);
                printf(GREEN"\nSelecione uma opcao: "RESET);
                scanf("%d", &opc2);
                system("cls");
                    if(opc2==1)
                    {
                        c=1;
                        while(c==1)
                        {
                            mkdir("Files/Funcionarios", 0777);
                            printf(YELLOW"\n--------------Funcionario----------------\n"RESET);
                            printf(CYAN"\n1 - Adicionar funcionario\n"RESET);
                            printf(CYAN"2 - Remover funcionario\n"RESET);
                            printf(CYAN"3 - Listar funcionarios\n"RESET);
                            printf(RED"\n9 - Voltar ao menu anterior\n"RESET);
                            printf(RED"0 - Voltar ao menu inicial\n"RESET);
                            printf(GREEN"\nSelecione uma opcao: "RESET);
                            scanf("%d", &opc3);

                            char nomeF[50], estatutoF[50], salarioF[50];
                            system("cls");

                                if(opc3==1)     //Adicionar funcionario
                                {
                                    printf(YELLOW"--------------Adicionar funcionario--------------\n\n"RESET);
                                    printf(GREEN"Nome: "RESET);
                                    fflush(stdin);
                                    fgets(nomeF, 50, stdin);
                                    nomeF[strcspn(nomeF, "\n")] = 0;

                                    b = 1;
                                    while (b == 1) //verificar que s� introduziu letras
                                    {
                                        for (int i = 0; nomeF[i] != '\0'; i++)
                                        {
                                            int k = (int)(nomeF[i]);
                                            if (isalpha(nomeF[i]) || (k==32))
                                                letras++;
                                        }
                                        if (strlen(nomeF) != letras)
                                        {
                                            letras = 0;
                                            printf(RED"Introduza apenas letras!\n"RESET);
                                            printf(GREEN"Nome: "RESET);
                                            fflush(stdin);
                                            fgets(nomeF, 50, stdin);
                                            nomeF[strcspn(nomeF, "\n")] = 0;
                                        }
                                        else
                                        {
                                            letras = 0;
                                            b = 0;
                                        }
                                    }

                                    printf(GREEN"Estatuto: "RESET);
                                    fflush(stdin);
                                    fgets(estatutoF, 50, stdin);
                                    estatutoF[strcspn(estatutoF, "\n")] = 0;

                                    b = 1;
                                    while (b == 1) //verificar que s� introduziu letras
                                    {
                                        for (int i = 0; estatutoF[i] != '\0'; i++)
                                        {
                                            int k = (int)(estatutoF[i]);
                                            if (isalpha(estatutoF[i]) || (k==32))
                                                letras++;
                                        }
                                        if (strlen(estatutoF) != letras)
                                        {
                                            letras = 0;
                                            printf(RED"Introduza apenas letras!\n"RESET);
                                            printf(GREEN"Estatuto: "RESET);
                                            fflush(stdin);
                                            fgets(estatutoF, 50, stdin);
                                            estatutoF[strcspn(estatutoF, "\n")] = 0;
                                        }
                                        else
                                        {
                                            letras = 0;
                                            b = 0;
                                        }
                                    }

                                    printf(GREEN"Salario: "RESET);
                                    fflush(stdin);
                                    fgets(salarioF, 50, stdin);
                                    salarioF[strcspn(salarioF, "\n")] = 0;

                                    b=1;
                                    while (b == 1) //verificar que s� introduziu letras
                                    {
                                        letras=0;
                                        for (int i=0; salarioF[i] != '\0'; i++)
                                        {
                                            int k = (int)(salarioF[i]);
                                            if(isdigit(salarioF[i]) || (k==46))
                                                letras++;
                                        }

                                        if (strlen(salarioF) != letras)
                                        {
                                            printf(RED"Introduza um numero valido!\n"RESET);
                                            printf(GREEN"Salario: "RESET);
                                            fflush(stdin);
                                            fgets(salarioF, 50, stdin);
                                            salarioF[strcspn(salarioF, "\n")] = 0;
                                        }
                                        else
                                        {
                                            letras=0;
                                            b = 0;
                                        }
                                    }

                                    if (fileContadorFuncionario = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"r"))
                                    {
                                        fclose(fileContadorFuncionario);
                                    }else {
                                        contador = 1;
                                        fileContadorFuncionario = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"w");
                                        fprintf(fileContadorFuncionario, "%d", contador);
                                        fclose(fileContadorFuncionario);
                                    }


                                    contadorInteiroFuncionarios(); //fun��o para ir buscar o valor inteiro do ficheiro contador

                                    sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                                    strcpy(caminho, "Files/Funcionarios/"); //limpar variavel, copia o segundo parametro
                                    strcat(caminho, contadorString); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF = fopen(caminho, "w");
                                    fprintf(fileF, "%s\n%s\n%s\n", nomeF, estatutoF, salarioF);
                                    fclose(fileF);

                                    printf(GREEN"\n-----------------------------------\n"RESET);
                                    printf(GREEN"O ID do funcionario %s e %d!"RESET, nomeF, contador);
                                    printf(GREEN"\n-----------------------------------\n"RESET);

                                    contador += 1;

                                    fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "w");
                                    fprintf(fileContadorFuncionario, "%d", contador);
                                    fclose(fileContadorFuncionario);

                                    printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                    getch();

                                    system("cls");
                                }

                                if(opc3==2)     //Remover funcionario
                                {
                                    printf(YELLOW"--------------Eliminar funcionario--------------\n\n"RESET);
                                    printf(RED"Introduza o Id do funcionario a eliminar: "RESET);
                                    scanf("%d", &id);

                                    strcpy(caminho, "Files/Funcionarios/");
                                    sprintf(iString, "%d", id);
                                    strcat(caminho, iString);
                                    strcat(caminho, ".txt");

                                    fileF = fopen(caminho, "r");


                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Nome: %s", linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Estatuto: %s"RESET, linha);
                                            }
                                            if(k==2)
                                            {
                                                printf(GREEN"Salario: %s"RESET, linha);
                                            }
                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n"RESET);
                                        printf(GREEN"\nTem a certeza que pretende eliminar esse funcionario?\n"RESET);

                                        printf(GREEN"1 - Sim\n"RESET);
                                        printf(RED"2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            remove(caminho);
                                            printf(GREEN"\n-----------------------------------\n"RESET);
                                            printf(GREEN"Funcionario eliminado com sucesso!"RESET);
                                            printf(GREEN"\n-----------------------------------\n"RESET);
                                        }
                                        if(aux == 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Produto nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }
                                    }
                                     else{
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Esse funcionario nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }

                                    printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                    getch();

                                    system("cls");
                                }

                                if(opc3==3)     //Listar funcionario
                                {
                                    printf(YELLOW"--------------Lista funcionario--------------\n\n"RESET);

                                    contadorInteiroFuncionarios();

                                    for(int i = 1; contador > i;i++)
                                    {
                                        strcpy(caminho, "Files/Funcionarios/");
                                        sprintf(iString, "%d", i);
                                        strcat(iString, ".txt");
                                        strcat(caminho, iString);

                                        fileF = fopen(caminho, "r");

                                        if(fileF)
                                        {
                                            int k = 0;
                                            while (!feof(fileF))
                                                {
                                                    result = fgets(linha, 100, fileF);

                                                    if(k==0)
                                                    {
                                                        printf(GREEN"--------------------\n"RESET);
                                                        printf(CYAN"Id: %d\n"RESET, i);
                                                        printf(CYAN"Nome: %s"RESET, linha);
                                                    }
                                                    if(k==1)
                                                    {
                                                        printf(CYAN"Estatuto: %s"RESET, linha);
                                                    }
                                                    if(k==2)
                                                    {
                                                        printf(CYAN"Salario: %s"RESET, linha);
                                                    }

                                                k++;
                                            }
                                        fclose(fileF);
                                        }

                                    }
                                    printf(GREEN"--------------------\n"RESET);

                                    printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                    getch();

                                    system("cls");

                                }
                                if(opc3==9)     //Voltar ao menu anterior (Menu Funcionario)
                                {
                                    system("cls");
                                    c=0;
                                }
                                if(opc3==0)     //Voltar ao menu inicial (Menu Funcionario)
                                {
                                    system("cls");
                                    c=0;
                                    b=0;
                                }

                        }
                    }
                    if(opc2==2)
                    {
                        c=1;
                        while(c==1)
                        {
                            mkdir("Files/Produtos", 0777);
                            printf(YELLOW"\n--------------Gestao de Stock----------------\n"RESET);
                            printf(CYAN"\n1 - Adicionar produto\n"RESET);
                            printf(CYAN"2 - Editar stock\n"RESET);
                            printf(CYAN"3 - Listar produto\n"RESET);
                            printf(CYAN"4 - Eliminar produto\n"RESET);
                            printf(RED"\n9 - Voltar ao menu anterior\n"RESET);
                            printf(RED"0 - Voltar ao menu inicial\n"RESET);
                            printf(GREEN"\nSelecione uma opcao: "RESET);
                            scanf("%d", &opc3);
                            system("cls");

                            char ingredienteS[50], auxIngrediente[50], quantidadeS[50];

                            if(opc3==1)     //Adicionar produto
                            {
                                printf(YELLOW"--------------Adicionar produto--------------\n\n"RESET);
                                printf(GREEN"Ingrediente: "RESET);
                                fflush(stdin);
                                fgets(ingredienteS, 50, stdin);
                                ingredienteS[strcspn(ingredienteS, "\n")] = 0;

                                b = 1;
                                while (b == 1) //verificar que s� introduziu letras
                                {
                                    for (int i = 0; ingredienteS[i] != '\0'; i++)
                                    {
                                        int k = (int)(ingredienteS[i]);
                                        if (isalpha(ingredienteS[i]) || (k==32))
                                            letras++;
                                    }
                                    if (strlen(ingredienteS) != letras)
                                    {
                                        letras = 0;
                                        printf(RED"Introduza apenas letras!\n"RESET);
                                        printf(GREEN"Ingrediente: "RESET);
                                        fflush(stdin);
                                        fgets(ingredienteS, 50, stdin);
                                        ingredienteS[strcspn(ingredienteS, "\n")] = 0;
                                    }
                                    else
                                    {
                                        letras = 0;
                                        b = 0;
                                    }
                                }

                                printf(GREEN"Quantidade: "RESET);
                                fflush(stdin);
                                fgets(quantidadeS, 50, stdin);
                                quantidadeS[strcspn(quantidadeS, "\n")] = 0;

                                b=1;
                                while (b == 1) //verificar que s� introduziu letras
                                {
                                    letras=0;
                                    for (int i=0; quantidadeS[i] != '\0'; i++)
                                    {
                                        int k = (int)(quantidadeS[i]);
                                        if(isdigit(quantidadeS[i]) || (k==46))
                                            letras++;
                                    }

                                    if (strlen(quantidadeS) != letras)
                                    {
                                        printf(RED"Introduza um numero!\n"RESET);
                                        printf(GREEN"Quantidade: "RESET);
                                        fflush(stdin);
                                        fgets(quantidadeS, 50, stdin);
                                        quantidadeS[strcspn(quantidadeS, "\n")] = 0;
                                    }
                                    else
                                    {
                                        letras=0;
                                        b = 0;
                                    }
                                }

                                if (fileContadorStock = fopen("Files/Produtos/ContadorProdutos.txt" ,"r"))
                                {
                                    fclose(fileContadorStock);
                                }else {
                                    contador = 1;
                                    fileContadorStock = fopen("Files/Produtos/ContadorProdutos.txt" ,"w");
                                    fprintf(fileContadorStock, "%d", contador);
                                    fclose(fileContadorStock);
                                }

                                contadorInteiroProduto();

                                sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString

                                strcpy(caminho, "Files/Produtos/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, contadorString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "w");
                                fprintf(fileF, "%s\n%s\n", ingredienteS, quantidadeS);
                                fclose(fileF);

                                printf(GREEN"\n-----------------------------------\n"RESET);
                                printf(GREEN"O ID do ingrediente %s e %d!"RESET, ingredienteS, contador);
                                printf(GREEN"\n-----------------------------------\n"RESET);

                                contador += 1;

                                fileContadorStock = fopen ("Files/Produtos/ContadorProdutos.txt", "w");
                                fprintf(fileContadorStock, "%d", contador);
                                fclose(fileContadorStock);

                                printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");

                            }
                            if(opc3==2)     //Editar produto
                            {
                                printf(YELLOW"--------------Stock--------------\n\n"RESET);
                                printf(GREEN"1 - Adicionar stock\n"RESET);
                                printf(RED"2 - Remover stock\n"RESET);
                                printf(GREEN"\nSelecione uma opcao: "RESET);
                                scanf("%d", &opcao);

                                float auxnum = 0;

                                if(opcao == 1)
                                {
                                    printf(GREEN"\nIntroduza o ID do produto a editar: "RESET);
                                    fflush(stdin);
                                    fgets(iString, 50, stdin);
                                    iString[strcspn(iString, "\n")] = 0;

                                    b=1;
                                    while (b == 1) //verificar que s� introduziu letras
                                    {
                                        letras=0;
                                        for (int i=0; iString[i] != '\0'; i++)
                                        {
                                            int k = (int)(iString[i]);
                                            if(isdigit(iString[i]) || (k==46))
                                                letras++;
                                        }

                                        if (strlen(iString) != letras)
                                        {
                                            printf(RED"Introduza um numero!\n"RESET);
                                            printf(GREEN"Introduza o ID do produto a editar: "RESET);
                                            fflush(stdin);
                                            fgets(iString, 50, stdin);
                                            iString[strcspn(iString, "\n")] = 0;
                                        }
                                        else
                                        {
                                            letras=0;
                                            b = 0;
                                        }
                                    }

                                    strcpy(caminho, "Files/Produtos/"); //limpar variavel, copia o segundo parametro
                                    strcat(caminho, iString); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n------------------------------\n"RESET);
                                                printf(GREEN"O nome do produto e %s"RESET, linha);
                                                strcpy(auxIngrediente, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"A quantidade atual e de %s"RESET, linha);
                                                auxnum = atof(linha);
                                                printf(GREEN"\n------------------------------\n"RESET);
                                            }
                                            k++;
                                        }
                                        fclose(fileF);

                                        float quatidadeA, quantidadeTotal;

                                        printf(GREEN"\nIntroduza o stock a acrescentar:"RESET);
                                        scanf("%f", &quatidadeA);

                                        quantidadeTotal = auxnum + quatidadeA;
                                        fileF = fopen(caminho, "w");

                                        fprintf(fileF, "%s%.2f", auxIngrediente, quantidadeTotal);

                                        fclose(fileF);
                                        printf(GREEN"\n------------------------------\n"RESET);
                                        printf(GREEN"Stock acrescentado com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------\n"RESET);
                                    }
                                    else
                                     {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Esse produto nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }
                                }
                                if(opcao == 2)
                                {
                                    printf(RED"\nIntroduza o ID do produto a editar: "RESET);
                                    fflush(stdin);
                                    fgets(iString, 50, stdin);
                                    iString[strcspn(iString, "\n")] = 0;

                                    b=1;
                                    while (b == 1) //verificar que s� introduziu letras
                                    {
                                        letras=0;
                                        for (int i=0; iString[i] != '\0'; i++)
                                        {
                                            int k = (int)(iString[i]);
                                            if(isdigit(iString[i]) || (k==46))
                                                letras++;
                                        }

                                        if (strlen(iString) != letras)
                                        {
                                            printf(RED"Introduza um numero!\n"RESET);
                                            printf(RED"Introduza o ID do produto a editar: "RESET);
                                            fflush(stdin);
                                            fgets(iString, 50, stdin);
                                            iString[strcspn(iString, "\n")] = 0;
                                        }
                                        else
                                        {
                                            letras=0;
                                            b = 0;
                                        }
                                    }

                                    strcpy(caminho, "Files/Produtos/"); //limpar variavel, copia o segundo parametro
                                    strcat(caminho, iString); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n------------------------------\n"RESET);
                                                printf(GREEN"O nome do produto e %s"RESET, linha);
                                                strcpy(auxIngrediente, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"A quantidade atual e de %s"RESET, linha);
                                                auxnum = atof(linha);
                                                printf(GREEN"\n------------------------------\n"RESET);
                                            }
                                            k++;
                                        }
                                        fclose(fileF);

                                        float quatidadeA, quantidadeTotal;

                                        printf(RED"\nIntroduza o stock a remover:"RESET);
                                        scanf("%f", &quatidadeA);

                                        quantidadeTotal = auxnum - quatidadeA;

                                        fileF = fopen(caminho, "w");

                                        fprintf(fileF, "%s%.2f\n", auxIngrediente, quantidadeTotal);

                                        fclose(fileF);
                                        printf(GREEN"\n------------------------------\n"RESET);
                                        printf(GREEN"Stock removido com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------\n"RESET);
                                    } else {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Esse produto nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }
                                }

                                printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                            }
                            if(opc3==3)     //Listar produto
                            {
                                printf(YELLOW"--------------Lista produto--------------\n"RESET);
                                contadorInteiroProduto();

                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Produtos/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                            {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Id: %d\n"RESET, i);
                                                printf(GREEN"Engrediente: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(GREEN"Quantidade: %s"RESET, linha);
                                            }
                                        k++;
                                        }
                                    fclose(fileF);
                                    }
                                }
                                printf(GREEN"\n--------------------\n"RESET);

                                printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");

                            }
                            if(opc3==4)     //Eliminar produto
                            {
                                printf(YELLOW"--------------Eliminar produto--------------\n"RESET);
                                printf(GREEN"\nIntroduza o id do produto a eliminar: "RESET);
                                fflush(stdin);
                                fgets(iString, 50, stdin);
                                iString[strcspn(iString, "\n")] = 0;

                                b=1;
                                while (b == 1) //verificar que s� introduziu letras
                                {
                                    letras=0;
                                    for (int i=0; iString[i] != '\0'; i++)
                                    {
                                        int k = (int)(iString[i]);
                                        if(isdigit(iString[i]) || (k==46))
                                            letras++;
                                    }

                                    if (strlen(iString) != letras)
                                    {
                                        printf(RED"Introduza um numero!\n"RESET);
                                        printf(RED"Introduza o ID do produto a eliminar: "RESET);
                                        fflush(stdin);
                                        fgets(iString, 50, stdin);
                                        iString[strcspn(iString, "\n")] = 0;
                                    }
                                    else
                                    {
                                        letras=0;
                                        b = 0;
                                    }
                                }

                                strcpy(caminho, "Files/Produtos/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    int k = 0;
                                    while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);
                                        if(k==0)
                                        {
                                            printf(GREEN"\n--------------------\n"RESET);
                                            printf(GREEN"Ingrediente: %s"RESET, linha);
                                        }

                                        if(k==1)
                                        {
                                            printf(GREEN"Stock: %s\n"RESET, linha);
                                        }
                                        k++;
                                    }

                                    fclose(fileF);

                                    int aux;

                                    printf(GREEN"--------------------\n"RESET);
                                    printf(GREEN"\nTem a certeza que pretende eliminar esse produto?\n"RESET);

                                    printf(GREEN"1 - Sim\n"RESET);
                                    printf(RED"2 - Nao\n\n"RESET);

                                    printf(GREEN"Selecione uma opcao: "RESET);

                                    scanf("%d", &aux);

                                    if(aux == 1)
                                    {
                                        remove(caminho);
                                        printf(GREEN"\n------------------------------\n"RESET);
                                        printf(GREEN"Produto eliminado com sucesso!"RESET);
                                        printf(GREEN"\n------------------------------\n"RESET);
                                    }
                                    if(aux == 2)
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Produto nao eliminado!"RESET);
                                        printf(RED"\n------------------------------\n"RESET);
                                    }
                                } else {
                                    printf(RED"\n------------------------------\n"RESET);
                                    printf(RED"Esse produto nao existe!"RESET);
                                    printf(RED"\n-----------------------------\n"RESET);
                                }
                                printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                            }
                            if(opc3==9)     //Voltar ao menu anterior (Menu Stock)
                            {
                                c=0;
                            }
                            if(opc3==0)     //Voltar ao menu inicial (Menu Stock)
                            {
                                c=0;
                                b=0;
                            }
                        }
                    }
                    if(opc2==3)
                    {
                        mkdir("Files/Ementas", 0777);
                        printf(YELLOW"\n--------------Ementa----------------\n"RESET);
                        printf(CYAN"\n1 - Adicionar ementa\n"RESET);
                        printf(CYAN"2 - Remover ementa\n"RESET);
                        printf(CYAN"3 - Listar ementa\n"RESET);
                        printf(RED"\n9 - Voltar ao menu anterior\n"RESET);
                        printf(RED"0 - Voltar ao menu inicial\n"RESET);
                        printf(GREEN"\nSelecione uma opcao: "RESET);
                        scanf("%d", &opcao);

                        system("cls");

                        char ementa[50], precoEmenta[50];
                        int stock, id;
                        float precoEmentaF;

                        if (opcao == 1)
                        {
                            printf(YELLOW"--------------Adicionar Ementa--------------\n"RESET);
                            printf(GREEN"\nEmenta: "RESET);
                            fflush(stdin);
                            fgets(ementa, 50, stdin);
                            ementa[strcspn(ementa, "\n")] = 0;

                            b = 1;
                            while (b == 1) //verificar que s� introduziu letras
                            {
                                for (int i = 0; ementa[i] != '\0'; i++)
                                {
                                    int k = (int)(ementa[i]);
                                    if (isalpha(ementa[i]) || (k==32))
                                        letras++;
                                }
                                if (strlen(ementa) != letras)
                                {
                                    letras = 0;
                                    printf(RED"Introduza apenas letras!\n"RESET);
                                    printf(GREEN"Ementa: "RESET);
                                    fflush(stdin);
                                    fgets(ementa, 50, stdin);
                                    ementa[strcspn(ementa, "\n")] = 0;
                                }
                                else
                                {
                                    letras = 0;
                                    b = 0;
                                }
                            }

                            printf(GREEN"Preco: "RESET);
                            fflush(stdin);
                            fgets(precoEmenta, 50, stdin);
                            precoEmenta[strcspn(precoEmenta, "\n")] = 0;

                            b=1;
                            while (b == 1) //verificar que s� introduziu letras
                            {
                                letras=0;
                                for (int i=0; precoEmenta[i] != '\0'; i++)
                                {
                                    int k = (int)(precoEmenta[i]);
                                    if(isdigit(precoEmenta[i]) || (k==46))
                                        letras++;
                                }

                                if (strlen(precoEmenta) != letras)
                                {
                                    printf(RED"Introduza um numero!\n"RESET);
                                    printf(GREEN"Preco: "RESET);
                                    fflush(stdin);
                                    fgets(precoEmenta, 50, stdin);
                                    precoEmenta[strcspn(precoEmenta, "\n")] = 0;
                                }
                                else
                                {
                                    letras=0;
                                    b = 0;
                                }
                            }

                            printf(GREEN"\nLista de Refeicoes"RESET);
                            printf(CYAN"\n------------------------"RESET);
                            printf(CYAN"\n1 - Pequeno-Almoco\n"RESET);
                            printf(CYAN"2 - Almoco\n"RESET);
                            printf(CYAN"3 - Lanche\n"RESET);
                            printf(CYAN"4 - Jantar\n"RESET);
                            printf(CYAN"5 - Sobremesa\n"RESET);
                            printf(CYAN"6 - Bebida\n"RESET);
                            printf(CYAN"------------------------\n"RESET);

                            int aux2;
                            int aux3;
                            printf(GREEN"\nIntroduza a lista a que corresponde a ementa: "RESET);
                            scanf("%d", &aux2);

                            system("cls");

                            if(aux2 == 1)
                            {
                                mkdir("Files/Ementas/PequenoAlmoco", 0777);

                                if (fileContadorPequenoAlmoco = fopen("Files/Ementas/PequenoAlmoco/ContadorPequenoAlmoco.txt" ,"r"))
                                {
                                    fclose(fileContadorPequenoAlmoco);
                                }
                                else
                                {
                                    contador = 1;
                                    fileContadorPequenoAlmoco = fopen("Files/Ementas/PequenoAlmoco/ContadorPequenoAlmoco.txt" ,"w");
                                    fprintf(fileContadorPequenoAlmoco, "%d", contador);
                                    fclose(fileContadorPequenoAlmoco);
                                }

                                printf(GREEN"Lista de produtos: \n"RESET);

                                contadorInteiroProduto();
                                int k = 0;
                                for(int i = 1; contador > i;i++)
                                {
                                    k=0;
                                    strcpy(caminho, "Files/Produtos/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        while (!feof(fileF))
                                        {
                                                result = fgets(linha, 100, fileF);

                                                //if(result)
                                                //{
                                                    if(k==0)
                                                    {
                                                        printf(CYAN"\n--------------------\n"RESET);
                                                        printf(CYAN"Id: %d\n"RESET, i);
                                                        printf(CYAN"Engrediente: %s"RESET, linha);
                                                    }
                                                    if(k==1)
                                                    {
                                                        printf(CYAN"Quantidade: %s"RESET, linha);
                                                    }
                                                //}
                                            k++;
                                        }
                                    fclose(fileF);
                                    }
                                }
                                printf(GREEN"\n--------------------\n"RESET);

                                if(k==0)
                                {
                                    printf(GREEN"\nAdicione produtos ao sistema para criar uma ementa! (Gerir Stock)\n\n"RESET);
                                    printf(GREEN"Pressione qualquer tecla para avancar"RESET);
                                    getch();
                                    system("cls");\
                                    break;
                                }

                                printf(GREEN"Introduza o ID do produto que constitui a ementa: "RESET);
                                scanf("%d", &id);

                                printf(GREEN"Quantidade necessaria: "RESET);
                                scanf("%d", &stock);


                                contadorInteiroPequenoAlmoco();
                                sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, contadorString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "w");
                                fprintf(fileF, "%s\n%s\n%d\n%d\n", ementa, precoEmenta, id, stock);
                                fclose(fileF);

                                contador += 1;

                                fileContadorPequenoAlmoco = fopen ("Files/Ementas/PequenoAlmoco/ContadorPequenoAlmoco.txt", "w");
                                fprintf(fileContadorPequenoAlmoco, "%d", contador);
                                fclose(fileContadorPequenoAlmoco);

                                b=1;
                                while (b == 1)
                                {
                                    printf(GREEN"\nEsta ementa possui mais produtos?\n"RESET);
                                    printf(GREEN"1 - Sim\n"RESET);
                                    printf(RED"2 - Nao\n"RESET);
                                    printf(GREEN"\nSelecione uma opcao:"RESET);
                                    scanf("%d", &aux3);

                                    if(aux3 == 1)
                                    {
                                        printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                                        scanf("%d", &id);

                                        printf(GREEN"Quantidade necessaria: "RESET);
                                        scanf("%d", &stock);


                                        fileF = fopen(caminho, "a");
                                        fprintf(fileF, "%d\n%d\n", id, stock);
                                        fclose(fileF);

                                    }
                                    if (aux3 == 2)
                                    {
                                        if (fileF = fopen(caminho ,"r"))
                                        {
                                            printf(GREEN"\n-----------------------------------\n"RESET);
                                            printf(GREEN"Ementa criada com sucesso!"RESET);
                                            printf(GREEN"\n-----------------------------------\n"RESET);
                                            fclose(fileF);
                                            printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                            getch();
                                            system("cls");
                                            break;
                                        } else {
                                            printf(RED"\n-----------------------------------\n"RESET);
                                            printf(RED"Ementa não foi criada!"RESET);
                                            printf(RED"\n-----------------------------------\n"RESET);
                                            printf(GREEN"\nPressione qualquer tecla para avancar");
                                            getch();
                                            system("cls");
                                            break;
                                        }
                                    }
                                }
                            }

                        if(aux2 == 2)
                        {
                            mkdir("Files/Ementas/Almoco", 0777);

                            if (fileContadorAlmoco = fopen("Files/Ementas/Almoco/ContadorAlmoco.txt" ,"r"))
                            {
                                fclose(fileContadorAlmoco);
                            }
                            else {
                                contador = 1;
                                fileContadorAlmoco = fopen("Files/Ementas/Almoco/ContadorAlmoco.txt" ,"w");
                                fprintf(fileContadorAlmoco, "%d", contador);
                                fclose(fileContadorAlmoco);
                            }

                            printf(GREEN"Lista de produtos: \n"RESET);

                            contadorInteiroProduto();

                            int k = 0;
                            for(int i = 1; contador > i;i++)
                            {
                                k=0;
                                strcpy(caminho, "Files/Produtos/");
                                sprintf(iString, "%d", i);
                                strcat(iString, ".txt");
                                strcat(caminho, iString);

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                            //if(result)
                                            //{
                                                if(k==0)
                                                {
                                                    printf(GREEN"\n--------------------\n"RESET);
                                                    printf(CYAN"Id: %d\n"RESET, i);
                                                    printf(CYAN"Engrediente: %s"RESET, linha);
                                                }
                                                if(k==1)
                                                {
                                                    printf(CYAN"Quantidade: %s"RESET, linha);

                                                }
                                            //}
                                        k++;
                                    }
                                fclose(fileF);
                                }
                            }
                            printf(GREEN"\n--------------------\n"RESET);

                                if(k==0)
                                {
                                    printf(GREEN"\nAdicione produtos ao sistema para criar uma ementa! (Gerir Stock)\n\n"RESET);
                                    printf(GREEN"Pressione qualquer tecla para avancar"RESET);
                                    getch();
                                    system("cls");
                                    break;
                                }

                            printf(GREEN"\nIntroduza o ID do produto que constituem esta ementa: "RESET);
                            scanf("%d", &id);

                            int stock;
                            printf(GREEN"Quantidade necessaria: "RESET);
                            scanf("%d", &stock);

                            contadorInteiroAlmoco();
                            sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                            strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                            strcat(caminho, contadorString); //junta strings
                            strcat(caminho, ".txt");

                            fileF = fopen(caminho, "w");
                            fprintf(fileF, "%s\n%.2f\n%d\n%d\n", ementa, precoEmenta, id, stock);
                            fclose(fileF);

                            contador += 1;

                            fileContadorPequenoAlmoco = fopen ("Files/Ementas/Almoco/ContadorAlmoco.txt", "w");
                            fprintf(fileContadorPequenoAlmoco, "%d", contador);
                            fclose(fileContadorPequenoAlmoco);

                            b = 1;
                            while (b == 1)
                            {
                                printf(GREEN"\nEsta ementa possui mais produtos?\n"RESET);
                                printf(GREEN"1 - Sim\n"RESET);
                                printf(RED"2 - Nao\n"RESET);
                                printf(GREEN"\Selecione uma opcao:"RESET);
                                scanf("%d", &aux3);

                                if(aux3 == 1)
                                {
                                    printf(GREEN"\nIntroduza o ID do produto que constituem esta ementa: "RESET);
                                    scanf("%d", &id);

                                    int stock;
                                    printf(GREEN"Quantidade necessaria: "RESET);
                                    scanf("%d", &stock);

                                    fileF = fopen(caminho, "a");
                                    fprintf(fileF, "%d\n%d\n", id, stock);
                                    fclose(fileF);

                                }
                                if (aux3 == 2)
                                {
                                    if (fileF = fopen(caminho ,"r"))
                                    {
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"Ementa criada com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        fclose(fileF);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;

                                    } else {
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(RED"Ementa não foi criada!"RESET);
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    }
                                }
                            }

                        }

                        if(aux2 == 3)
                        {
                            mkdir("Files/Ementas/Lanche", 0777);

                            if (fileContadorLanche = fopen("Files/Ementas/Lanche/ContadorLanche.txt" ,"r"))
                            {
                                fclose(fileContadorLanche);

                            }else {
                                contador = 1;
                                fileContadorLanche = fopen("Files/Ementas/Lanche/ContadorLanche.txt" ,"w");
                                fprintf(fileContadorLanche, "%d", contador);
                                fclose(fileContadorLanche);
                            }


                            printf(GREEN"Lista de produto: \n"RESET);
                            contadorInteiroProduto();

                            int k = 0;
                            for(int i = 1; contador > i;i++)
                            {
                                strcpy(caminho, "Files/Produtos/");
                                sprintf(iString, "%d", i);
                                strcat(iString, ".txt");
                                strcat(caminho, iString);

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    k = 0;
                                    while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                            //if(result)
                                            //{
                                                if(k==0)
                                                {
                                                    printf(GREEN"\n--------------------\n"RESET);
                                                    printf(CYAN"Id: %d\n"RESET, i);
                                                    printf(CYAN"Engrediente: %s"RESET, linha);
                                                }
                                                if(k==1)
                                                {
                                                    printf(CYAN"Quantidade: %s"RESET, linha);
                                                }
                                            //}
                                        k++;
                                    }
                                fclose(fileF);
                                }
                            }
                            printf(GREEN"\n--------------------\n"RESET);
                            if(k==0)
                            {
                                printf(GREEN"\nAdicione produtos ao sistema para criar uma ementa! (Gerir Stock)\n\n"RESET);
                                printf(GREEN"Pressione qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                                break;
                            }

                            printf(GREEN"\nIntroduza o ID do produto que constituem esta ementa: "RESET);
                            scanf("%d", &id);

                            int stock;
                            printf(GREEN"Quantidade necessaria: "RESET);
                            scanf("%d", &stock);

                            contadorInteiroLanche();
                            sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                            strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                            strcat(caminho, contadorString); //junta strings
                            strcat(caminho, ".txt");

                            fileF = fopen(caminho, "w");
                            fprintf(fileF, "%s\n%.2f\n%d\n%d\n", ementa, precoEmenta, id, stock);
                            fclose(fileF);

                            contador += 1;

                            fileContadorLanche = fopen ("Files/Ementas/Lanche/ContadorLanche.txt", "w");
                            fprintf(fileContadorLanche, "%d", contador);
                            fclose(fileContadorLanche);

                            b=1;
                            while (b == 1)
                            {
                                printf(GREEN"\nEsta ementa possui mais produtos?\n"RESET);
                                printf(GREEN"1 - Sim\n"RESET);
                                printf(RED"2 - Nao\n"RESET);
                                printf(GREEN"\Selecione uma opcao:"RESET);
                                scanf("%d", &aux3);

                                if(aux3 == 1)
                                {
                                    printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                                    scanf("%d", &id);

                                    int stock;
                                    printf("Quantidade necessaria: ");
                                    scanf("%d", &stock);

                                    fileF = fopen(caminho, "a");
                                    fprintf(fileF, "%d\n%d\n", id, stock);
                                    fclose(fileF);

                                }
                                if (aux3 == 2)
                                {
                                    if (fileF = fopen(caminho ,"r"))
                                    {
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"Ementa criada com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        fclose(fileF);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    } else {
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(RED"Ementa não foi criada!"RESET);
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    }
                                }
                            }

                        }
                        if(aux2 == 4)
                        {
                            mkdir("Files/Ementas/Jantar", 0777);

                            if (fileContadorJantar = fopen("Files/Ementas/Jantar/ContadorJantar.txt" ,"r"))
                            {
                                fclose(fileContadorJantar);

                            }else {
                                contador = 1;
                                fileContadorJantar = fopen("Files/Ementas/Jantar/ContadorJantar.txt" ,"w");
                                fprintf(fileContadorJantar, "%d", contador);
                                fclose(fileContadorJantar);
                            }


                            printf(GREEN"Lista de produtos\n"RESET);

                            contadorInteiroProduto();

                            int k = 0;
                            for(int i = 1; contador > i;i++)
                            {
                                strcpy(caminho, "Files/Produtos/");
                                sprintf(iString, "%d", i);
                                strcat(iString, ".txt");
                                strcat(caminho, iString);

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    k = 0;
                                    while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                            //if(result)
                                            //{
                                                if(k==0)
                                                {
                                                    printf(GREEN"\n--------------------\n"RESET);
                                                    printf(CYAN"Id: %d\n"RESET, i);
                                                    printf(CYAN"Engrediente: %s"RESET, linha);
                                                }
                                                if(k==1)
                                                {
                                                    printf(CYAN"Quantidade: %s"RESET, linha);
                                                }
                                            //}
                                        k++;
                                    }
                                fclose(fileF);
                                }
                            }
                            printf(GREEN"\n--------------------\n"RESET);
                            if(k==0)
                            {
                                printf(GREEN"\nAdicione produtos ao sistema para criar uma ementa! (Gerir Stock)\n\n"RESET);
                                printf(GREEN"Pressione qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                                break;
                            }

                            printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                            scanf("%d", &id);

                            int stock;
                            printf(GREEN"Quantidade necessaria: "RESET);
                            scanf("%d", &stock);

                            contadorInteiroJantar();
                            sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                            strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                            strcat(caminho, contadorString); //junta strings
                            strcat(caminho, ".txt");

                            fileF = fopen(caminho, "w");
                            fprintf(fileF, "%s\n%.2f\n%d\n%d\n", ementa, precoEmenta, id, stock);
                            fclose(fileF);

                            contador += 1;

                            fileContadorJantar = fopen ("Files/Ementas/Jantar/ContadorJantar.txt", "w");
                            fprintf(fileContadorJantar, "%d", contador);
                            fclose(fileContadorJantar);

                            b=1;
                            while (b == 1)
                            {
                                printf(GREEN"\nEsta ementa possui mais produtos?\n"RESET);
                                printf(GREEN"1 - Sim\n"RESET);
                                printf(RED"2 - Nao\n"RESET);
                                printf(GREEN"\Selecione uma opcao:"RESET);
                                scanf("%d", &aux3);

                                if(aux3 == 1)
                                {
                                    printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                                    scanf("%d", &id);

                                    int stock;
                                    printf(GREEN"Quantidade necessaria: "RESET);
                                    scanf("%d", &stock);

                                    fileF = fopen(caminho, "a");
                                    fprintf(fileF, "%d\n%d\n", id, stock);
                                    fclose(fileF);

                                }
                                if (aux3 == 2)
                                {
                                    if (fileF = fopen(caminho ,"r"))
                                    {
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"Ementa criada com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    } else {
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(RED"Ementa não foi criada!"RESET);
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                        }
                        if(aux2 == 5)
                        {
                           mkdir("Files/Ementas/Sobremesa", 0777);

                           if (fileContadorSobremesa = fopen("Files/Ementas/Sobremesa/ContadorSobremesa.txt" ,"r"))
                            {
                                fclose(fileContadorSobremesa);

                            }else {
                                contador = 1;
                                fileContadorSobremesa = fopen("Files/Ementas/Sobremesa/ContadorSobremesa.txt" ,"w");
                                fprintf(fileContadorSobremesa, "%d", contador);
                                fclose(fileContadorSobremesa);
                            }


                            printf(GREEN"Lista de produto: \n"RESET);

                            contadorInteiroProduto();

                            int k = 0;
                            for(int i = 1; contador > i;i++)
                            {
                                strcpy(caminho, "Files/Produtos/");
                                sprintf(iString, "%d", i);
                                strcat(iString, ".txt");
                                strcat(caminho, iString);

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    k = 0;
                                    while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                            //if(result)
                                            //{
                                                if(k==0)
                                                {
                                                    printf(GREEN"\n--------------------\n"RESET);
                                                    printf(CYAN"Id: %d\n"RESET, i);
                                                    printf(CYAN"Engrediente: %s"RESET, linha);
                                                }
                                                if(k==1)
                                                {
                                                    printf(CYAN"Quantidade: %s"RESET, linha);
                                                }
                                            //}
                                        k++;
                                    }
                                fclose(fileF);
                                }
                            }
                            printf(GREEN"\n--------------------\n"RESET);
                            if(k==0)
                            {
                                printf(GREEN"\nAdicione produtos ao sistema para criar uma ementa! (Gerir Stock)\n\n"RESET);
                                printf(GREEN"Pressione qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                                break;
                            }

                            printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                            scanf("%d", &id);

                            int stock;
                            printf(GREEN"Quantidade necessaria: "RESET);
                            scanf("%d", &stock);

                            contadorInteiroSobremesa();
                            sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                            strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                            strcat(caminho, contadorString); //junta strings
                            strcat(caminho, ".txt");

                            fileF = fopen(caminho, "w");
                            fprintf(fileF, "%s\n%.2f\n%d\n%d\n", ementa, precoEmenta, id, stock);
                            fclose(fileF);

                            contador += 1;

                            fileContadorSobremesa = fopen ("Files/Ementas/Sobremesa/ContadorSobremesa.txt", "w");
                            fprintf(fileContadorSobremesa, "%d", contador);
                            fclose(fileContadorSobremesa);

                            b=1;
                            while (b == 1)
                            {
                                printf(GREEN"\nEsta ementa possui mais produtos?\n"RESET);
                                printf(GREEN"1 - Sim\n"RESET);
                                printf(RED"2 - Nao\n"RESET);
                                printf(GREEN"\nSelecione uma opcao:"RESET);
                                scanf("%d", &aux3);

                                if(aux3 == 1)
                                {
                                    printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                                    scanf("%d", &id);

                                    int stock;
                                    printf(GREEN"Quantidade necessaria: "RESET);
                                    scanf("%d", &stock);

                                    fileF = fopen(caminho, "a");
                                    fprintf(fileF, "%d\n%d\n", id, stock);
                                    fclose(fileF);

                                }
                                if (aux3 == 2)
                                {
                                    if (fileF = fopen(caminho ,"r"))
                                    {
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"Ementa criada com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        fclose(fileF);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    } else {
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(RED"Ementa não foi criada!"RESET);
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                        }
                        if(aux2 == 6)
                        {
                           mkdir("Files/Ementas/Bebida", 0777);

                            if (fileContadorBebida = fopen("Files/Ementas/Bebida/ContadorBebida.txt" ,"r"))
                            {
                                fclose(fileContadorBebida);


                            }else {
                                contador = 1;
                                fileContadorBebida = fopen("Files/Ementas/Bebida/ContadorBebida.txt" ,"w");
                                fprintf(fileContadorBebida, "%d", contador);
                                fclose(fileContadorBebida);
                            }


                            printf(GREEN"Lista de produto: \n"RESET);

                            contadorInteiroProduto();

                            int k = 0;
                            for(int i = 1; contador > i;i++)
                            {
                                strcpy(caminho, "Files/Produtos/");
                                sprintf(iString, "%d", i);
                                strcat(iString, ".txt");
                                strcat(caminho, iString);

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    k = 0;
                                    while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                            //if(result)
                                            //{
                                                if(k==0)
                                                {
                                                    printf(GREEN"\n--------------------\n"RESET);
                                                    printf(CYAN"Id: %d\n"RESET, i);
                                                    printf(CYAN"Engrediente: %s"RESET, linha);
                                                }
                                                if(k==1)
                                                {
                                                    printf(CYAN"Quantidade: %s"RESET, linha);
                                                }
                                            //}
                                        k++;
                                    }
                                fclose(fileF);
                                }
                            }
                            printf(GREEN"\n--------------------\n"RESET);
                            if(k==0)
                            {
                                printf(GREEN"\nAdicione produtos ao sistema para criar uma ementa! (Gerir Stock)\n\n"RESET);
                                printf(GREEN"Pressione qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                                break;
                            }

                            printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                            scanf("%d", &id);

                            int stock;
                            printf(GREEN"Quantidade necessaria: "RESET);
                            scanf("%d", &stock);

                            contadorInteiroBebida();
                            sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                            strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                            strcat(caminho, contadorString); //junta strings
                            strcat(caminho, ".txt");

                            fileF = fopen(caminho, "w");
                            fprintf(fileF, "%s\n%.2f\n%d\n%d\n", ementa, precoEmenta, id, stock);
                            fclose(fileF);

                            contador += 1;

                            fileContadorBebida = fopen ("Files/Ementas/Bebida/ContadorBebida.txt", "w");
                            fprintf(fileContadorBebida, "%d", contador);
                            fclose(fileContadorBebida);

                            b=1;
                            while (b == 1)
                            {
                                printf(GREEN"\nEsta ementa possui mais produtos?\n"RESET);
                                printf(GREEN"1 - Sim\n"RESET);
                                printf(RED"2 - Nao\n"RESET);
                                printf(GREEN"\Selecione uma opcao:"RESET);
                                scanf("%d", &aux3);

                                if(aux3 == 1)
                                {
                                    printf(GREEN"\nIntroduza o ID do produto que constitui a ementa: "RESET);
                                    scanf("%d", &id);

                                    int stock;
                                    printf(GREEN"Quantidade necessaria: "RESET);
                                    scanf("%d", &stock);

                                    fileF = fopen(caminho, "a");
                                    fprintf(fileF, "%d\n%d\n", id, stock);
                                    fclose(fileF);

                                }
                                if (aux3 == 2)
                                {
                                    if (fileF = fopen(caminho ,"r"))
                                    {
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"Ementa criada com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        fclose(fileF);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    } else {
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(RED"Ementa não foi criada!"RESET);
                                        printf(RED"\n-----------------------------------\n"RESET);
                                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                        getch();
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                        }
                        }
                        if(opcao==2) // Eliminar Ementas
                        {

                            printf(YELLOW"--------------Eliminar Ementas--------------\n"RESET);
                            printf(GREEN"\nLista de Refeicoes"RESET);
                            printf(CYAN"\n------------------------"RESET);
                            printf(CYAN"\n1 - Pequeno-Almoco\n"RESET);
                            printf(CYAN"2 - Almoco\n"RESET);
                            printf(CYAN"3 - Lanche\n"RESET);
                            printf(CYAN"4 - Jantar\n"RESET);
                            printf(CYAN"5 - Sobremesa\n"RESET);
                            printf(CYAN"6 - Bebida\n"RESET);
                            printf(CYAN"------------------------\n"RESET);
                            printf(GREEN"\nIntroduza qual a lista de refeicoes a que corresponde!\n"RESET);
                            printf(GREEN"Selecione uma opcao: ");
                            scanf("%d", &opc4);

                            system("cls");

                            if(opc4 == 1) // Pequeno Almoco
                            {
                                printf(YELLOW"--------------Eliminar Ementa--------------\n"RESET);
                                printf(RED"\nIntroduza o ID da ementa a eliminar: "RESET);
                                scanf("%d", &id);

                                sprintf(iString, "%d", id); //passar um numero inteiro para char
                                strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Ementa: %s"RESET, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        //if(result)
                                                        //{
                                                            if(k==0)
                                                            {
                                                                 printf(GREEN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(GREEN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n\n"RESET);
                                        printf("Tem a certeza que pretende eliminar essa ementa?\n\n"RESET);

                                        printf(GREEN"1 - Sim"RESET);
                                        printf(RED"\n2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            sprintf(iString, "%d", id); //passar um numero inteiro para char
                                            strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                            strcat(caminho, iString); //junta strings
                                            strcat(caminho, ".txt");
                                            remove(caminho);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                            printf(GREEN"Ementa eliminado com sucesso!"RESET);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                        }
                                        else if(aux = 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Ementa nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }

                                    }
                                    else
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Essa ementa nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }

                                        printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                        getch();
                                        system("cls");
                                }

                            if(opc4 == 2)
                            {
                                printf(YELLOW"--------------Eliminar Ementa--------------\n"RESET);
                                printf(RED"\nIntroduza o ID da ementa a eliminar: "RESET);
                                scanf("%d", &id);

                                sprintf(iString, "%d", id); //passar um numero inteiro para char
                                strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Ementa: %s"RESET, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        //if(result)
                                                        //{
                                                            if(k==0)
                                                            {
                                                                 printf(GREEN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(GREEN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n"RESET);
                                        printf(GREEN"Tem a certeza que pretende eliminar essa ementa?\n"RESET);

                                        printf(GREEN"1 - Sim"RESET);
                                        printf(RED"\n2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            sprintf(iString, "%d", id); //passar um numero inteiro para char
                                            strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                                            strcat(caminho, iString); //junta strings
                                            strcat(caminho, ".txt");
                                            remove(caminho);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                            printf(GREEN"Ementa eliminado com sucesso!"RESET);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                        }
                                        else if(aux = 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Ementa nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }
                                    }
                                    else
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Essa ementa nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }

                                        printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                        getch();

                                        system("cls");
                            }
                            if(opc4 == 3)
                            {
                                printf(YELLOW"--------------Eliminar Ementa--------------\n"RESET);
                                printf(RED"\nIntroduza o ID da ementa a eliminar: "RESET);
                                scanf("%d", &id);

                                sprintf(iString, "%d", id); //passar um numero inteiro para char
                                strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Ementa: %s"RESET, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        //if(result)
                                                        //{
                                                            if(k==0)
                                                            {
                                                                 printf(GREEN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(GREEN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n"RESET);
                                        printf(GREEN"Tem a certeza que pretende eliminar essa ementa?\n"RESET);

                                        printf(GREEN"1 - Sim"RESET);
                                        printf(RED"\n2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            sprintf(iString, "%d", id); //passar um numero inteiro para char
                                            strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                                            strcat(caminho, iString); //junta strings
                                            strcat(caminho, ".txt");
                                            remove(caminho);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                            printf(GREEN"Ementa eliminado com sucesso!"RESET);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                        }
                                        else if(aux = 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Ementa nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }
                                    }
                                    else
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Essa ementa nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);

                                    }

                                        printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                        getch();

                                        system("cls");
                            }
                            if(opc4 == 4)
                            {
                                printf(YELLOW"--------------Eliminar Ementa--------------\n"RESET);
                                printf(RED"\nIntroduza o ID da ementa a eliminar: "RESET);
                                scanf("%d", &id);

                                sprintf(iString, "%d", id); //passar um numero inteiro para char
                                strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Ementa: %s"RESET, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        //if(result)
                                                        //{
                                                            if(k==0)
                                                            {
                                                                 printf(GREEN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(GREEN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n"RESET);
                                        printf(GREEN"Tem a certeza que pretende eliminar essa ementa?\n"RESET);

                                        printf(GREEN"1 - Sim"RESET);
                                        printf(RED"\n2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            sprintf(iString, "%d", id); //passar um numero inteiro para char
                                            strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                                            strcat(caminho, iString); //junta strings
                                            strcat(caminho, ".txt");
                                            remove(caminho);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                            printf(GREEN"Ementa eliminado com sucesso!"RESET);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                        }
                                        else if(aux = 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Ementa nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }
                                    }
                                    else
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Essa ementa nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }

                                        printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                        getch();

                                        system("cls");
                            }
                            if(opc4 == 5)
                            {
                                printf(YELLOW"--------------Eliminar Ementa--------------\n"RESET);
                                printf(RED"\nIntroduza o ID da ementa a eliminar: "RESET);
                                scanf("%d", &id);

                                sprintf(iString, "%d", id); //passar um numero inteiro para char
                                strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Ementa: %s"RESET, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        //if(result)
                                                        //{
                                                            if(k==0)
                                                            {
                                                                 printf(GREEN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(GREEN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n"RESET);
                                        printf(GREEN"Tem a certeza que pretende eliminar essa ementa?\n"RESET);

                                        printf(GREEN"1 - Sim"RESET);
                                        printf(RED"\n2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            sprintf(iString, "%d", id); //passar um numero inteiro para char
                                            strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                                            strcat(caminho, iString); //junta strings
                                            strcat(caminho, ".txt");
                                            remove(caminho);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                            printf(GREEN"Ementa eliminado com sucesso!"RESET);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                        }
                                        else if(aux = 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Ementa nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }
                                    }
                                    else
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Essa ementa nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }

                                        printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                        getch();

                                        system("cls");
                            }
                            if(opc4 == 6)
                            {
                                printf(YELLOW"--------------Eliminar Ementa--------------\n"RESET);
                                printf(RED"\nIntroduza o ID da ementa a eliminar: "RESET);
                                scanf("%d", &id);

                                sprintf(iString, "%d", id); //passar um numero inteiro para char
                                strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, iString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);
                                            if(k==0)
                                            {
                                                printf(GREEN"\n--------------------\n"RESET);
                                                printf(GREEN"Ementa: %s"RESET, linha);
                                            }

                                            if(k==1)
                                            {
                                                printf(GREEN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        //if(result)
                                                        //{
                                                            if(k==0)
                                                            {
                                                                 printf(GREEN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        //}
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(GREEN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                        }

                                        fclose(fileF);

                                        int aux;

                                        printf(GREEN"--------------------\n"RESET);
                                        printf(GREEN"Tem a certeza que pretende eliminar essa ementa?\n"RESET);

                                        printf(GREEN"1 - Sim"RESET);
                                        printf(RED"\n2 - Nao\n"RESET);
                                        printf(GREEN"\nSelecione uma opcao: "RESET);
                                        scanf("%d", &aux);

                                        if(aux == 1)
                                        {
                                            sprintf(iString, "%d", id); //passar um numero inteiro para char
                                            strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                                            strcat(caminho, iString); //junta strings
                                            strcat(caminho, ".txt");
                                            remove(caminho);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                            printf(GREEN"Ementa eliminado com sucesso!"RESET);
                                            printf(GREEN"\n------------------------------\n"RESET);
                                        }
                                        else if(aux = 2)
                                        {
                                            printf(RED"\n------------------------------\n"RESET);
                                            printf(RED"Ementa nao eliminado!"RESET);
                                            printf(RED"\n------------------------------\n"RESET);
                                        }
                                    }
                                    else
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Essa ementa nao existe!"RESET);
                                        printf(RED"\n-----------------------------\n"RESET);
                                    }

                                        printf(GREEN"\nPressiona qualquer tecla para avancar\n"RESET);
                                        getch();

                                        system("cls");
                            }
                        }
                        if(opcao==3)    //Listar Ementas
                        {
                            printf(YELLOW"--------------Listar Ementas--------------\n"RESET);
                            printf(GREEN"\nLista de Refeicoes"RESET);
                            printf(CYAN"\n------------------------"RESET);
                            printf(CYAN"\n1 - Pequeno-Almoco\n"RESET);
                            printf(CYAN"2 - Almoco\n"RESET);
                            printf(CYAN"3 - Lanche\n"RESET);
                            printf(CYAN"4 - Jantar\n"RESET);
                            printf(CYAN"5 - Sobremesa\n"RESET);
                            printf(CYAN"6 - Bebida\n"RESET);
                            printf(CYAN"------------------------\n"RESET);
                            printf(GREEN"\nIntroduza qual a lista de refeicoes a que corresponde!\n"RESET);

                            int aux4;

                            printf(GREEN"\Selecione uma opcao: "RESET);
                            scanf("%d", &aux4);
                            system("cls");
                            printf(GREEN"Lista de ementas: \n\n"RESET);


                            if(aux4 == 1)
                            {
                                contadorInteiroPequenoAlmoco();

                                int nFicheiros =0;
                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Ementas/PequenoAlmoco/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        nFicheiros += 1;
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                            if(result)
                                            {

                                            if(k==0)
                                            {
                                                printf(GREEN"------------------------\n"RESET);
                                                printf(CYAN"Id: %d\n"RESET, i);
                                                printf(CYAN"Nome: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(CYAN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        if(result)
                                                        {
                                                            if(k==0)
                                                            {
                                                                 printf(CYAN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(CYAN"Quantidade necessaria: %s"RESET, linha);
                                            }


                                            k++;
                                            }
                                        }
                                        fclose(fileF);
                                    }

                                    if (contador-1 == i)
                                    {
                                        if(nFicheiros == 0)
                                        {
                                            printf(RED"\n----------------------------------------\n"RESET);
                                            printf(RED"Nao existem ementas no pequeno almoco!"RESET);
                                            printf(RED"\n----------------------------------------\n"RESET);
                                        } else {
                                            printf(GREEN"------------------------\n"RESET);
                                        }
                                    }
                                }

                                printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                                system("cls");
                            }
                            if(aux4 == 2)
                            {
                                contadorInteiroAlmoco();

                                int nFicheiros =0;
                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Ementas/Almoco/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        nFicheiros += 1;
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                             if(result)
                                            {

                                            if(k==0)
                                            {
                                                printf(GREEN"------------------------\n"RESET);
                                                printf(CYAN"Id: %d\n"RESET, i);
                                                printf(CYAN"Nome: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(CYAN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        if(result)
                                                        {
                                                            if(k==0)
                                                            {
                                                                 printf(CYAN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(CYAN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                            }
                                        }
                                        fclose(fileF);
                                    }

                                    if (contador-1 == i)
                                    {
                                        if(nFicheiros == 0)
                                        {
                                            printf(RED"\n----------------------------------------\n"RESET);
                                            printf(RED"Nao existem ementas almoco!"RESET);
                                            printf(RED"\n----------------------------------------\n"RESET);
                                        } else {
                                            printf(GREEN"------------------------\n"RESET);
                                        }
                                    }
                                }

                                printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                                system("cls");
                            }
                            if(aux4 == 3)
                            {
                                contadorInteiroLanche();

                                int nFicheiros =0;
                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Ementas/Lanche/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        nFicheiros += 1;
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                             if(result)
                                            {

                                            if(k==0)
                                            {
                                                printf(GREEN"------------------------\n"RESET);
                                                printf(CYAN"Id: %d\n"RESET, i);
                                                printf(CYAN"Nome: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(CYAN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        if(result)
                                                        {
                                                            if(k==0)
                                                            {
                                                                 printf(CYAN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(CYAN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                            }
                                        }
                                        fclose(fileF);
                                    }

                                    if (contador-1 == i)
                                    {
                                        if(nFicheiros == 0)
                                        {
                                            printf(RED"\n----------------------------------------\n"RESET);
                                            printf(RED"Nao existem ementas no lanche!"RESET);
                                            printf(RED"\n----------------------------------------\n"RESET);
                                        } else {
                                            printf(GREEN"------------------------\n"RESET);
                                        }
                                    }
                                }

                                printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                                system("cls");
                            }
                            if(aux4 == 4)
                            {
                                contadorInteiroJantar();

                                int nFicheiros =0;
                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Ementas/Jantar/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        nFicheiros += 1;
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                             if(result)
                                            {

                                            if(k==0)
                                            {
                                                printf(GREEN"------------------------\n"RESET);
                                                printf(CYAN"Id: %d\n"RESET, i);
                                                printf(CYAN"Nome: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(CYAN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        if(result)
                                                        {
                                                            if(k==0)
                                                            {
                                                                 printf(CYAN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(CYAN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                            }
                                        }
                                        fclose(fileF);
                                    }

                                    if (contador-1 == i)
                                    {
                                        if(nFicheiros == 0)
                                        {
                                            printf(RED"\n----------------------------------------\n"RESET);
                                            printf(RED"Nao existem ementas no Jantar!"RESET);
                                            printf(RED"\n----------------------------------------\n"RESET);
                                        } else {
                                            printf(GREEN"------------------------\n"RESET);
                                        }
                                    }
                                }

                                printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                                system("cls");
                            }
                            if(aux4 == 5)
                            {
                                contadorInteiroSobremesa();

                                int nFicheiros =0;
                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Ementas/Sobremesa/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        nFicheiros += 1;
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                             if(result)
                                            {

                                            if(k==0)
                                            {
                                                printf(GREEN"------------------------\n"RESET);
                                                printf(CYAN"Id: %d\n"RESET, i);
                                                printf(CYAN"Nome: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(CYAN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        if(result)
                                                        {
                                                            if(k==0)
                                                            {
                                                                 printf(CYAN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(CYAN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                            }
                                        }
                                        fclose(fileF);
                                    }

                                    if (contador-1 == i)
                                    {
                                        if(nFicheiros == 0)
                                        {
                                            printf(RED"\n----------------------------------------\n"RESET);
                                            printf(RED"Nao existem ementas na sobremesa!"RESET);
                                            printf(RED"\n----------------------------------------\n"RESET);
                                        } else {
                                            printf(GREEN"------------------------\n"RESET);
                                        }
                                    }
                                }

                                printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                                system("cls");
                            }
                            if(aux4 == 6)
                            {
                                contadorInteiroBebida();

                                int nFicheiros =0;
                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Ementas/Bebida/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        nFicheiros += 1;
                                        int k = 0;
                                        while (!feof(fileF))
                                        {
                                            result = fgets(linha, 100, fileF);

                                             if(result)
                                            {

                                            if(k==0)
                                            {
                                                printf(GREEN"------------------------\n"RESET);
                                                printf(CYAN"Id: %d\n"RESET, i);
                                                printf(CYAN"Nome: %s"RESET, linha);
                                            }
                                            if(k==1)
                                            {
                                                printf(CYAN"Preco: %s"RESET, linha);
                                            }
                                            if(k>1 && k%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha[strcspn(linha, "\n")] = 0;
                                                strcat(caminho, linha);
                                                strcat(caminho, ".txt");

                                                fileF2 = fopen(caminho, "r");

                                                if(fileF2)
                                                {
                                                    int k = 0;
                                                    while (!feof(fileF2))
                                                    {
                                                        result = fgets(linha, 100, fileF2);

                                                        if(result)
                                                        {
                                                            if(k==0)
                                                            {
                                                                 printf(CYAN"Produto associado: %s"RESET, linha);
                                                                 fclose(fileF2);
                                                                 break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if(k>2 && k%2==1)
                                            {
                                                printf(CYAN"Quantidade necessaria: %s"RESET, linha);
                                            }

                                            k++;
                                            }
                                        }
                                        fclose(fileF);
                                    }

                                    if (contador-1 == i)
                                    {
                                        if(nFicheiros == 0)
                                        {
                                            printf(RED"\n----------------------------------------\n"RESET);
                                            printf(RED"Nao existem ementas na bebida!"RESET);
                                            printf(RED"\n----------------------------------------\n"RESET);
                                        } else {
                                            printf(GREEN"------------------------\n"RESET);
                                        }
                                    }
                                }

                                printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                                system("cls");
                            }

                        }
                        if(opcao==9)    //Volar ao menu anterior
                        {
                            c=0;
                        }
                        if(opcao==0)    //Voltar ao menu inicial
                        {
                            c=0;
                            b=0;
                        }
                    }
                    if(opc2==4)
                    {
                        c=1;
                        while(c==1)
                        {
                            mkdir("Files/Clientes", 0777);
                            printf(YELLOW"\n--------------Cliente----------------\n"RESET);
                            printf(CYAN"\n1 - Adicionar cliente\n"RESET);
                            printf(CYAN"2 - Listar clientes\n"RESET);
                            printf(CYAN"3 - Eliminar clientes\n"RESET);
                            printf(RED"\n9 - Voltar ao menu anterior\n"RESET);
                            printf(RED"0 - Voltar ao menu inicial\n"RESET);
                            printf(GREEN"\nSelecione uma opcao: "RESET);
                            scanf("%d", &opc3);
                            system("cls");

                            char nomeC[100], numeroTC[100], nifC[100];

                            if(opc3==1)     //Adicionar cliente
                            {
                                printf(YELLOW"--------------Adicionar cliente--------------\n"RESET);
                                printf(GREEN"Nome: "RESET);
                                fflush(stdin);
                                fgets(nomeC, 50, stdin);
                                nomeC[strcspn(nomeC, "\n")] = 0;

                                b = 1;
                                while (b == 1) //verificar que s� introduziu letras
                                {
                                    for (int i = 0; nomeC[i] != '\0'; i++)
                                    {
                                        int k = (int)(nomeC[i]);
                                        if (isalpha(nomeC[i]) || (k==32))
                                            letras++;
                                    }
                                    if (strlen(nomeC) != letras)
                                    {
                                        letras = 0;
                                        printf(RED"Introduza apenas letras!\n"RESET);
                                        printf(GREEN"Nome: "RESET);
                                        fflush(stdin);
                                        fgets(nomeC, 50, stdin);
                                        nomeC[strcspn(nomeC, "\n")] = 0;
                                    }
                                    else
                                    {
                                        letras = 0;
                                        b = 0;
                                    }
                                }

                                printf(GREEN"Numero de telemovel: "RESET);
                                fflush(stdin);
                                fgets(numeroTC, 50, stdin);
                                numeroTC[strcspn(numeroTC, "\n")] = 0;

                                b=1;
                                while (b == 1) //verificar que s� introduziu letras
                                {
                                    letras=0;
                                    aux = atoi(numeroTC);
                                    for (int i=0; numeroTC[i] != '\0'; i++)
                                    {
                                        int k = (int)(numeroTC[i]);
                                        if(isdigit(numeroTC[i]) || (k==46))
                                            letras++;
                                    }

                                    if (strlen(numeroTC) != letras || aux/100000000 < 9)
                                    {
                                        printf(RED"Introduza um numero valido!\n"RESET);
                                        printf(GREEN"Numero de telemovel: "RESET);
                                        fflush(stdin);
                                        fgets(numeroTC, 50, stdin);
                                        numeroTC[strcspn(numeroTC, "\n")] = 0;
                                    }
                                    else
                                    {
                                        letras=0;
                                        b = 0;
                                    }
                                }
                                printf(GREEN"NIF: "RESET);
                                fflush(stdin);
                                fgets(nifC, 50, stdin);
                                nifC[strcspn(nifC, "\n")] = 0;

                                b=1;
                                while (b == 1) //verificar que s� introduziu letras
                                {
                                    letras=0;
                                    aux = atoi(nifC);
                                    for (int i=0; nifC[i] != '\0'; i++)
                                    {
                                        int k = (int)(nifC[i]);
                                        if(isdigit(nifC[i]) || (k==46))
                                            letras++;
                                    }

                                    if (strlen(nifC) != letras || aux/100000000 < 1)
                                    {
                                        printf(RED"\nIntroduza um NIF com 9 digitos!\n"RESET);
                                        printf(GREEN"NIF: "RESET);
                                        fflush(stdin);
                                        fgets(nifC, 50, stdin);
                                        nifC[strcspn(nifC, "\n")] = 0;
                                    }
                                    else
                                    {
                                        letras=0;
                                        b = 0;
                                    }
                                }

                                if(fileContadorCliente = fopen("Files/Clientes/ContadorClientes.txt", "r"))
                                {
                                    fclose(fileContadorCliente);
                                }
                                else{
                                   contador = 1;
                                   fileContadorCliente = fopen("Files/Clientes/ContadorClientes.txt" ,"w");
                                   fprintf(fileContadorCliente, "%d", contador);
                                   fclose(fileContadorCliente);
                                }

                                contadorInteiroClientes(); //fun��o para ir buscar o valor inteiro do ficheiro contador


                                sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Clientes/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, contadorString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "w");
                                fprintf(fileF, "%s\n%s\n%s\n", nomeC, numeroTC, nifC);
                                fclose(fileF);

                                printf(GREEN"\n---------------------------------"RESET);
                                printf(GREEN"\nO ID do cliente %s e %d!"RESET, nomeC, contador);
                                printf(GREEN"\n---------------------------------"RESET);
                                printf(GREEN"\n\nPressione qualquer tecla para avancar!");
                                getch();

                                contador += 1;

                                fileContadorCliente = fopen ("Files/Clientes/ContadorClientes.txt", "w");
                                fprintf(fileContadorCliente, "%d", contador);
                                fclose(fileContadorCliente);

                                system("cls");

                            }
                            if(opc3==2)     //Listar cliente
                            {
                                printf(YELLOW"--------------Lista cliente--------------\n"RESET);
                                contadorInteiroClientes();

                                printf(GREEN"\n----------------------------------------\n"RESET);

                                for(int i = 1; contador > i;i++)
                                {
                                    strcpy(caminho, "Files/Clientes/");
                                    sprintf(iString, "%d", i);
                                    strcat(iString, ".txt");
                                    strcat(caminho, iString);

                                    fileF = fopen(caminho, "r");

                                    if(fileF)
                                    {
                                        int k = 0;
                                        while (!feof(fileF))
                                            {
                                                result = fgets(linha, 100, fileF);

                                                if(result)
                                                {
                                                    if(k==0)
                                                    {
                                                        printf(CYAN"Id: %d\n"RESET, i);
                                                        printf(CYAN"Nome: %s"RESET, linha);
                                                    }
                                                    if(k==1)
                                                    {
                                                        printf(CYAN"Numero de telemovel: %s"RESET, linha);
                                                    }
                                                    if(k==2)
                                                    {
                                                        printf(CYAN"NIF: %s"RESET, linha);
                                                    }
                                                }
                                            k++;
                                        }
                                        printf(GREEN"----------------------------------------\n"RESET);
                                        fclose(fileF);
                                    }
                                }
                                printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                                getch();
                                system("cls");
                            }
                            if(opc3==3)     //Eliminar cliente
                            {
                                printf(YELLOW"--------------Eliminar cliente--------------\n\n"RESET);
                                printf(RED"Introduza o Id do cliente a eliminar: "RESET);
                                scanf("%d", &id);

                                strcpy(caminho, "Files/Clientes/");
                                sprintf(iString, "%d", id);
                                strcat(caminho, iString);
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");

                                if(fileF)
                                {
                                    int k = 0;
                                    while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);
                                        if(k==0)
                                        {
                                            printf(GREEN"\n--------------------\n"RESET);
                                            printf(GREEN"Nome: %s", linha);
                                        }

                                        if(k==1)
                                        {
                                            printf(GREEN"Telemovel: %s"RESET, linha);
                                        }
                                        if(k==2)
                                        {
                                            printf(GREEN"NIF: %s"RESET, linha);
                                        }
                                        k++;
                                    }

                                    fclose(fileF);

                                    int aux;

                                    printf(GREEN"--------------------\n"RESET);
                                    printf(GREEN"\nTem a certeza que pretende eliminar esse cliente?\n"RESET);

                                    printf(GREEN"1 - Sim\n"RESET);
                                    printf(RED"2 - Nao\n"RESET);
                                    printf(GREEN"\nSelecione uma opcao: "RESET);
                                    scanf("%d", &aux);

                                    if(aux == 1)
                                    {
                                        remove(caminho);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                        printf(GREEN"Cliente eliminado com sucesso!"RESET);
                                        printf(GREEN"\n-----------------------------------\n"RESET);
                                    }
                                    if(aux == 2)
                                    {
                                        printf(RED"\n------------------------------\n"RESET);
                                        printf(RED"Cliente nao eliminado!"RESET);
                                        printf(RED"\n------------------------------\n"RESET);
                                    }
                                }
                                 else{
                                    printf(RED"\n------------------------------\n"RESET);
                                    printf(RED"Esse cliente nao existe!"RESET);
                                    printf(RED"\n-----------------------------\n"RESET);
                                }

                                printf(GREEN"\nPressiona qualquer tecla para avancar"RESET);
                                getch();

                                system("cls");

                            }

                            if(opc3==9)     //Volar ao menu anterior (Menu Ementa)
                            {
                                c=0;
                            }
                            if(opc3==0)     //Voltar ao menu inicial (Menu Ementa)
                            {
                                c=0;
                                b=0;
                            }
                        }
                    }
                    if(opc2==5)
                    {
                        printf(YELLOW"------------------Rendimento Total------------------\n"RESET);
                        char saldo[50];
                        if(fileF = fopen("Files/Saldo/SaldoTotal.txt", "r"))
                        {
                            fscanf(fileF, "%s",saldo);
                            printf(GREEN"\n========================================================="RESET);
                            printf(GREEN"\nO rendimento total da empresa foi de %s euros.\n"RESET, saldo);
                            printf(GREEN"=========================================================\n"RESET);
                            fclose(fileF);
                        }
                        else
                        {
                            printf(RED"\n========================================================="RESET);
                            printf(RED"\nAinda nao foi efetuada nenhuma venda!"RESET);
                            printf(RED"=========================================================\n"RESET);
                        }

                        printf(GREEN"\nPressione qualquer tecla para avancar"RESET);
                        getch();
                        system("cls");
                    }
                    if(opc2==0)
                    {
                        b=0;
                    }
                break;
            case 2:

                b=1;
                while(b==1)
                {
                    printf(YELLOW"\n--------------Cliente----------------\n"RESET);
                    printf(CYAN"\n1 - Pequeno-Almoco\n"RESET);
                    printf(CYAN"2 - Almoco\n"RESET);
                    printf(CYAN"3 - Lanche\n"RESET);
                    printf(CYAN"4 - Jantar\n"RESET);
                    printf(CYAN"5 - Sobremesa\n"RESET);
                    printf(CYAN"6 - Bebida\n"RESET);
                    printf(CYAN"7 - Pagar\n"RESET);
                    printf(CYAN"8 - Listar Pedido\n"RESET);
                    printf(RED"9 - Anular Pedido\n"RESET);
                    printf(RED"\n0 - Voltar\n\n"RESET);
                    printf(GREEN"Selecione uma opcao: "RESET);
                    scanf("%d", &opc2);

                    system("cls");

                    int n=0;

                    if(opc2==1)     //Adicionar PequenoAlmoco
                    {
                        printf(YELLOW"--------------Pequeno Almoco--------------\n\n"RESET);
                        contadorInteiroPequenoAlmoco();

                        for(int i = 1; contador > i;i++)
                        {
                            strcpy(caminho, "Files/Ementas/PequenoAlmoco/");
                            sprintf(iString, "%d", i);
                            strcat(iString, ".txt");
                            strcat(caminho, iString);

                            fileF = fopen(caminho, "r");
                            if(fileF)
                            {
                                int k = 0;
                                while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);

                                        linha[strcspn(linha, "\n")] = 0; // remover o \n da string linha

                                        //if(result)
                                        //{
                                            if(k==0)
                                            {
                                                printf(CYAN"%d - %s................"RESET, i, linha);
                                            }
                                            if(k == 1)
                                            {
                                                printf(CYAN"%s\n"RESET, linha);
                                            }
                                        //}
                                        k++;
                                    }
                                fclose(fileF);
                                n++;
                            }
                        }

                        if(n>0)
                        {
                            printf(RED"\n0 - Voltar\n"RESET);
                            id = 1;
                            while(id!=0)
                            {
                                printf(GREEN"\nIntroduza a ementa a comprar: "RESET);
                                scanf("%d", &id);

                                char idString[50];

                                sprintf(idString, "%d",id); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, idString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");
                                fclose(fileF);

                               if(fileF)
                               {
                                    mkdir("Files/Pedidos", 0777);

                                    fileF = fopen("Files/Pedidos/PequenoAlmoco.txt", "a"); // para diferenciar os id's das ementas

                                    fprintf(fileF, "%d\n", id);

                                    fclose(fileF);
                               }
                               else if(id == 0){}
                               else
                               {
                                   printf(RED"\n-----------------------------"RESET);
                                   printf(RED"\nIntroduza uma ementa valida!\n"RESET);
                                   printf(RED"-----------------------------\n"RESET);
                               }
                            }

                        }
                        else
                        {
                            printf(RED"----------------------------------------------------------"RESET);
                            printf(RED"\nNao existe nenhuma ementa para o Pequeno Almoco!\n"RESET);
                            printf(RED"----------------------------------------------------------\n"RESET);
                            printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        system("cls");

                    }

                    if(opc2==2)     //Adicionar Almoco
                    {
                        printf(YELLOW"--------------Almoco--------------\n\n"RESET);
                        contadorInteiroAlmoco();

                        for(int i = 1; contador > i;i++)
                        {
                            strcpy(caminho, "Files/Ementas/Almoco/");
                            sprintf(iString, "%d", i);
                            strcat(iString, ".txt");
                            strcat(caminho, iString);

                            fileF = fopen(caminho, "r");

                            if(fileF)
                            {
                                int k = 0;
                                while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);

                                        linha[strcspn(linha, "\n")] = 0; // remover o \n da string linha

                                        //if(result)
                                        //{
                                            if(k==0)
                                            {
                                                printf(CYAN"%d - %s................"RESET, i, linha);
                                            }
                                            if(k == 1)
                                            {
                                                printf(CYAN"%s\n"RESET, linha);
                                            }
                                        //}
                                        k++;
                                    }
                                fclose(fileF);
                                n++;
                            }
                        }
                        if(n>0)
                        {
                            id = 1;
                            printf(RED"\n0 - Voltar\n"RESET);
                            while(id!=0)
                            {
                                printf(GREEN"\nIntroduza a ementa a comprar: "RESET);
                                scanf("%d", &id);

                                char idString[50];

                                sprintf(idString, "%d",id); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, idString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");
                                fclose(fileF);

                               if(fileF)
                               {
                                    mkdir("Files/Pedidos", 0777);

                                    fileF = fopen("Files/Pedidos/Almoco.txt", "a"); // para diferenciar os id's das ementas

                                    fprintf(fileF, "%d\n", id);

                                    fclose(fileF);
                               }
                               else if(id == 0){}
                               else
                               {
                                   printf(RED"\n-----------------------------"RESET);
                                   printf(RED"\nIntroduza uma ementa valida!\n"RESET);
                                   printf(RED"-----------------------------\n"RESET);
                               }
                            }
                        }
                         else
                        {
                            printf(RED"----------------------------------------------------------"RESET);
                            printf(RED"\nNao existe nenhuma ementa para o Almoco!\n"RESET);
                            printf(RED"----------------------------------------------------------\n"RESET);
                            printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        system("cls");
                    }
                    if(opc2==3)     //Adicionar Lanche
                    {
                        printf(YELLOW"--------------Lanche--------------\n\n"RESET);
                        contadorInteiroLanche();

                        for(int i = 1; contador > i;i++)
                        {
                            strcpy(caminho, "Files/Ementas/Lanche/");
                            sprintf(iString, "%d", i);
                            strcat(iString, ".txt");
                            strcat(caminho, iString);

                            fileF = fopen(caminho, "r");

                            if(fileF)
                            {
                                int k = 0;
                                while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);

                                        linha[strcspn(linha, "\n")] = 0; // remover o \n da string linha

                                        //if(result)
                                        //{
                                            if(k==0)
                                            {
                                                printf(CYAN"%d - %s................"RESET, i, linha);
                                            }
                                            if(k == 1)
                                            {
                                                printf(CYAN"%s\n"RESET, linha);
                                            }
                                        //}
                                        k++;
                                    }
                                fclose(fileF);
                                n++;
                            }
                        }
                        if(n>0)
                        {
                            id = 1;
                            printf(RED"\n0 - Voltar\n"RESET);
                            while(id!=0)
                            {
                                printf(GREEN"Introduza a ementa a comprar: "RESET);
                                scanf("%d", &id);

                                char idString[50];

                                sprintf(idString, "%d",id); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, idString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");
                                fclose(fileF);

                               if(fileF)
                               {
                                    mkdir("Files/Pedidos", 0777);

                                    fileF = fopen("Files/Pedidos/Lanche.txt", "a"); // para diferenciar os id's das ementas

                                    fprintf(fileF, "%d\n", id);

                                    fclose(fileF);
                               }
                               else if(id == 0){}
                               else
                               {
                                    printf(RED"\n-----------------------------"RESET);
                                    printf(RED"\nIntroduza uma ementa valida!\n"RESET);
                                    printf(RED"-----------------------------\n"RESET);
                               }
                            }
                        }
                        else
                        {
                            printf(RED"----------------------------------------------------------"RESET);
                            printf(RED"\nNao existe nenhuma ementa para o Lanche!\n"RESET);
                            printf(RED"----------------------------------------------------------\n"RESET);
                            printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        system("cls");
                    }
                    if(opc2==4)     //Adicionar Jantar
                    {
                        printf(YELLOW"--------------Jantar--------------\n\n"RESET);
                        contadorInteiroJantar();

                        for(int i = 1; contador > i;i++)
                        {
                            strcpy(caminho, "Files/Ementas/Jantar/");
                            sprintf(iString, "%d", i);
                            strcat(iString, ".txt");
                            strcat(caminho, iString);

                            fileF = fopen(caminho, "r");

                            if(fileF)
                            {
                                int k = 0;
                                while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);

                                        linha[strcspn(linha, "\n")] = 0; // remover o \n da string linha

                                        //if(result)
                                        //{
                                            if(k==0)
                                            {
                                                printf(CYAN"%d - %s................"RESET, i, linha);
                                            }
                                            if(k == 1)
                                            {
                                                printf(CYAN"%s\n"RESET, linha);
                                            }
                                        //}
                                        k++;
                                    }
                                fclose(fileF);
                                n++;
                            }
                        }
                        if(n>0)
                        {

                            id = 1;
                            printf(RED"\n0 - Voltar\n"RESET);
                            while(id!=0)
                            {

                                printf(GREEN"Introduza a ementa a comprar: "RESET);
                                scanf("%d", &id);

                                char idString[50];

                                sprintf(idString, "%d",id); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, idString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");
                                fclose(fileF);

                               if(fileF)
                               {
                                    mkdir("Files/Pedidos", 0777);

                                    fileF = fopen("Files/Pedidos/Jantar.txt", "a"); // para diferenciar os id's das ementas

                                    fprintf(fileF, "%d\n", id);

                                    fclose(fileF);
                               }
                               else if(id == 0){}
                               else
                               {
                                    printf(RED"\n-----------------------------"RESET);
                                    printf(RED"\nIntroduza uma ementa valida!\n"RESET);
                                    printf(RED"-----------------------------\n"RESET);
                               }
                            }
                        }
                        else
                        {
                            printf(RED"----------------------------------------------------------"RESET);
                            printf(RED"\nNao existe nenhuma ementa para o Jantar!\n"RESET);
                            printf(RED"----------------------------------------------------------\n"RESET);
                            printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        system("cls");
                    }
                    if(opc2==5)     //Adicionar Sobremesa
                    {
                        printf(YELLOW"--------------Sobremesa--------------\n\n"RESET);
                        contadorInteiroSobremesa();

                        for(int i = 1; contador > i;i++)
                        {
                            strcpy(caminho, "Files/Ementas/Sobremesa/");
                            sprintf(iString, "%d", i);
                            strcat(iString, ".txt");
                            strcat(caminho, iString);

                            fileF = fopen(caminho, "r");

                            if(fileF)
                            {
                                int k = 0;
                                while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);

                                        linha[strcspn(linha, "\n")] = 0; // remover o \n da string linha

                                        //if(result)
                                        //{
                                            if(k==0)
                                            {
                                                printf(CYAN"%d - %s................"RESET, i, linha);
                                            }
                                            if(k == 1)
                                            {
                                                printf(CYAN"%s\n"RESET, linha);
                                            }
                                        //}
                                        k++;
                                    }
                                fclose(fileF);
                                n++;
                            }
                        }
                        if(n>0)
                        {
                            id = 1;
                            printf(RED"\n0 - Voltar\n"RESET);
                            while(id!=0)
                            {
                                printf(GREEN"Introduza a ementa a comprar: "RESET);
                                scanf("%d", &id);

                                char idString[50];

                                sprintf(idString, "%d",id); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, idString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");
                                fclose(fileF);

                               if(fileF)
                               {
                                    mkdir("Files/Pedidos", 0777);

                                    fileF = fopen("Files/Pedidos/Sobremesa.txt", "a"); // para diferenciar os id's das ementas

                                    fprintf(fileF, "%d\n", id);

                                    fclose(fileF);
                               }
                               else if(id == 0){}
                               else
                               {
                                    printf(RED"\n-----------------------------"RESET);
                                    printf(RED"\nIntroduza uma ementa valida!\n"RESET);
                                    printf(RED"-----------------------------\n"RESET);
                               }
                            }
                        }
                        else
                        {
                            printf(RED"----------------------------------------------------------"RESET);
                            printf(RED"\nNao existe nenhuma ementa para o Sobremesa!\n"RESET);
                            printf(RED"----------------------------------------------------------\n"RESET);
                            printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        system("cls");
                    }
                    if(opc2==6)     //Adicionar Bebida
                    {
                        printf(YELLOW"--------------Bebida--------------\n\n"RESET);
                        contadorInteiroBebida();

                        for(int i = 1; contador > i;i++)
                        {
                            strcpy(caminho, "Files/Ementas/Bebida/");
                            sprintf(iString, "%d", i);
                            strcat(iString, ".txt");
                            strcat(caminho, iString);

                            fileF = fopen(caminho, "r");

                            if(fileF)
                            {
                                int k = 0;
                                while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);

                                        linha[strcspn(linha, "\n")] = 0; // remover o \n da string linha

                                        //if(result)
                                        //{
                                            if(k==0)
                                            {
                                                printf(CYAN"%d - %s................"RESET, i, linha); //erro, mudar
                                            }
                                            if(k == 1)
                                            {
                                                printf(CYAN"%s\n"RESET, linha);
                                            }
                                        //}
                                        k++;
                                    }
                                fclose(fileF);
                                n++;
                            }
                        }
                        if(n>0)
                        {
                            id = 1;
                            printf(RED"\n0 - Voltar\n"RESET);
                            while(id!=0)
                            {
                                printf(GREEN"Introduza a ementa a comprar: "RESET);
                                scanf("%d", &id);

                                char idString[50];

                                sprintf(idString, "%d",id); //passar o valor do contador para string, ou seja, contadorString
                                strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                                strcat(caminho, idString); //junta strings
                                strcat(caminho, ".txt");

                                fileF = fopen(caminho, "r");
                                fclose(fileF);

                               if(fileF)
                               {
                                    mkdir("Files/Pedidos", 0777);

                                    fileF = fopen("Files/Pedidos/Bebida.txt", "a"); // para diferenciar os id's das ementas

                                    fprintf(fileF, "%d\n", id);

                                    fclose(fileF);
                               }
                               else if(id == 0){}
                               else
                               {
                                    printf(RED"\n-----------------------------"RESET);
                                    printf(RED"\nIntroduza uma ementa valida!\n"RESET);
                                    printf(RED"-----------------------------\n"RESET);
                               }
                            }
                        }
                        else
                        {
                            printf(RED"----------------------------------------------------------"RESET);
                            printf(RED"\nNao existe nenhuma ementa para as Bebidas!\n"RESET);
                            printf(RED"----------------------------------------------------------\n"RESET);
                            printf(GREEN"\nSelecione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        system("cls");

                    }
                    if(opc2==7)     //Pagar
                    {
                        printf(YELLOW"================ P A G A M E N T O ================\n\n"RESET);
                        int aux = 0;
                        printf(GREEN"Deseja fatura?"RESET);
                        printf(GREEN"\n1 - Sim\n"RESET);
                        printf(RED"2 - Nao\n"RESET);
                        printf(RED"\n0 - Voltar\n\n"RESET);

                        printf(GREEN"Selecione uma opcao: "RESET);
                        scanf("%d", &aux);
                        char auxIngrediente2[100];
                        float custoTotal = 0;
                        int  n = 0;

                        system("cls");

                        if(aux==1)
                        {
                            printf(YELLOW"================ F A T U R A   S I M P L I F I C A D A ================\n\n"RESET);
                            strcpy(caminho, "Files/Pedidos/PequenoAlmoco.txt");
                            fileF = fopen(caminho, "r");
                            int j = 1;
                            char linha2[100], linha3[100];

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                    printf(CYAN"%d - %s................"RESET,j, linha2);
                                                    j+=1;
                                                }

                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s\n"RESET, linha2);

                                                    sleep(1);
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Almoco.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                    printf(CYAN"%d - %s................"RESET,j, linha2);
                                                    j+=1;
                                                }

                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s\n"RESET, linha2);
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                    sleep(1);

                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Lanche.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                    printf(CYAN"%d - %s................"RESET,j, linha2);
                                                    j+=1;
                                                }

                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s\n"RESET, linha2);
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                    sleep(1);
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Jantar.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                    printf(CYAN"%d - %s................"RESET,j, linha2);
                                                    j+=1;
                                                }

                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s\n"RESET, linha2);
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                    sleep(1);
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Sobremesa.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                    printf(CYAN"%d - %s................"RESET,j, linha2);
                                                    j+=1;
                                                }

                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s\n"RESET, linha2);
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                    sleep(1);
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Bebida.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                    printf(CYAN"%d - %s................"RESET,j, linha2);
                                                    j+=1;
                                                }

                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s\n"RESET, linha2);
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                    sleep(1);
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);
                            if(n==0)
                            {
                                printf(RED"\n==================================="RESET);
                                printf(RED"\nIntroduza uma ementa ao seu pedido!"RESET);
                                printf(RED"\n==================================="RESET);
                                printf(GREEN"\n\nSelecione qualquer tecla para continuar"RESET);
                                getch();
                            }
                            else if(n>0)
                            {
                                mkdir("Files/Saldo/", 0777);
                                strcpy(caminho, "Files/Saldo/SaldoTotal.txt");
                                char auxcustoTotalS[50];
                                float auxcustoTotal;

                                if(fileF = fopen(caminho, "r"))
                                {
                                    fscanf(fileF, "%s", auxcustoTotalS);
                                    auxcustoTotal = atof(auxcustoTotalS);

                                    auxcustoTotal += custoTotal; // CERTO

                                    fclose(fileF);

                                    fileF = fopen(caminho, "w");
                                    fprintf(fileF, "%.2f", auxcustoTotal);
                                    fclose(fileF);
                                }
                                else
                                {
                                      fileF = fopen(caminho ,"w");
                                      fprintf(fileF, "%.2f", custoTotal);
                                      fclose(fileF);
                                }

                                printf(GREEN"\nValor Total a Pagar(com IVA): %.2f"RESET, custoTotal);
                                custoTotal = custoTotal/1.23;
                                printf(GREEN"\nValor Total (sem IVA): %.2f"RESET, custoTotal);

                                printf(GREEN"\n\nObrigado pela sua visita, volte sempre!"RESET);

                                printf(GREEN"\n\nSelecione qualquer tecla para pagar!"RESET);
                                getch();
                            }
                            system("cls");
                        }
                        if(aux==2)
                        {
                            printf(YELLOW"================ Pagamento ================\n"RESET);

                            strcpy(caminho, "Files/Pedidos/PequenoAlmoco.txt");
                            fileF = fopen(caminho, "r");
                            char linha2[100], linha3[100];

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                }

                                                else if(z==1)
                                                {
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Almoco.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                }

                                                else if(z==1)
                                                {
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Lanche.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                                n++;
                                while (!feof(fileF))
                                {
                                    result = fgets(linha, 100, fileF);
                                    strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(result)
                                    {
                                        if(fileF2)
                                        {
                                            int z = 0;
                                            while(!feof(fileF2))
                                            {
                                                result = fgets(linha2, 100, fileF2);

                                                linha2[strcspn(linha2, "\n")] = 0;

                                                char nomeProduto[100];
                                                float quantidadeProduto;
                                                float quantidadeEmenta;

                                                if(z==0)
                                                {
                                                }

                                                else if(z==1)
                                                {
                                                    float custoUnitario = atof(linha2);
                                                    custoTotal += custoUnitario;
                                                }
                                                else if(z>1 && z%2==0)
                                                {
                                                    strcpy(caminho, "Files/Produtos/");
                                                    linha2[strcspn(linha2, "\n")] = 0;
                                                    strcat(caminho, linha2);
                                                    strcat(caminho, ".txt");

                                                    fileF3 = fopen(caminho, "r");

                                                    if(fileF3)
                                                    {
                                                        int y = 0;
                                                        while (!feof(fileF3))
                                                        {

                                                            result = fgets(linha3, 100, fileF3);

                                                            if (y == 0)
                                                            {
                                                                strcpy(nomeProduto, linha3);
                                                            }
                                                            if (y == 1)
                                                            {
                                                                quantidadeProduto = atof(linha3);
                                                            }
                                                            y++;
                                                        }
                                                    }
                                                    fclose(fileF3);
                                                }
                                                else if(z>2 && z%2==1)
                                                {
                                                    quantidadeEmenta = atof(linha2);

                                                    quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                    fileF3 = fopen(caminho, "w");
                                                    fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                    fclose(fileF3);
                                                }
                                                z++;
                                            }
                                            fclose(fileF2);
                                        }
                                    }
                                }
                            }
                            fclose(fileF);

                            strcpy(caminho, "Files/Pedidos/Jantar.txt");
                            fileF = fopen(caminho, "r");

                            if (fileF)
                            {
                            n++;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                                linha[strcspn(linha, "\n")] = 0;
                                strcat(caminho, linha); //junta strings
                                strcat(caminho, ".txt");

                                fileF2 = fopen(caminho, "r");

                                if(result)
                                {
                                    if(fileF2)
                                    {
                                        int z = 0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);

                                            linha2[strcspn(linha2, "\n")] = 0;

                                            char nomeProduto[100];
                                            float quantidadeProduto;
                                            float quantidadeEmenta;

                                            if(z==0)
                                            {
                                            }

                                            else if(z==1)
                                            {
                                                float custoUnitario = atof(linha2);
                                                custoTotal += custoUnitario;
                                            }
                                            else if(z>1 && z%2==0)
                                            {
                                                strcpy(caminho, "Files/Produtos/");
                                                linha2[strcspn(linha2, "\n")] = 0;
                                                strcat(caminho, linha2);
                                                strcat(caminho, ".txt");

                                                fileF3 = fopen(caminho, "r");

                                                if(fileF3)
                                                {
                                                    int y = 0;
                                                    while (!feof(fileF3))
                                                    {

                                                        result = fgets(linha3, 100, fileF3);

                                                        if (y == 0)
                                                        {
                                                            strcpy(nomeProduto, linha3);
                                                        }
                                                        if (y == 1)
                                                        {
                                                            quantidadeProduto = atof(linha3);
                                                        }
                                                        y++;
                                                    }
                                                }
                                                fclose(fileF3);
                                            }
                                            else if(z>2 && z%2==1)
                                            {
                                                quantidadeEmenta = atof(linha2);

                                                quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                fileF3 = fopen(caminho, "w");
                                                fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                fclose(fileF3);
                                            }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                            }
                        }
                                fclose(fileF);

                                strcpy(caminho, "Files/Pedidos/Sobremesa.txt");
                                fileF = fopen(caminho, "r");

                                if (fileF)
                                {
                                    n++;
                                    while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);
                                        strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                                        linha[strcspn(linha, "\n")] = 0;
                                        strcat(caminho, linha); //junta strings
                                        strcat(caminho, ".txt");

                                        fileF2 = fopen(caminho, "r");

                                        if(result)
                                        {
                                            if(fileF2)
                                            {
                                                int z = 0;
                                                while(!feof(fileF2))
                                                {
                                                    result = fgets(linha2, 100, fileF2);

                                                    linha2[strcspn(linha2, "\n")] = 0;

                                                    char nomeProduto[100];
                                                    float quantidadeProduto;
                                                    float quantidadeEmenta;

                                                    if(z==0)
                                                    {
                                                    }

                                                    else if(z==1)
                                                    {
                                                        float custoUnitario = atof(linha2);
                                                        custoTotal += custoUnitario;
                                                    }
                                                    else if(z>1 && z%2==0)
                                                    {
                                                        strcpy(caminho, "Files/Produtos/");
                                                        linha2[strcspn(linha2, "\n")] = 0;
                                                        strcat(caminho, linha2);
                                                        strcat(caminho, ".txt");

                                                        fileF3 = fopen(caminho, "r");

                                                        if(fileF3)
                                                        {
                                                            int y = 0;
                                                            while (!feof(fileF3))
                                                            {

                                                                result = fgets(linha3, 100, fileF3);

                                                                if (y == 0)
                                                                {
                                                                    strcpy(nomeProduto, linha3);
                                                                }
                                                                if (y == 1)
                                                                {
                                                                    quantidadeProduto = atof(linha3);
                                                                }
                                                                y++;
                                                            }
                                                        }
                                                        fclose(fileF3);
                                                    }
                                                    else if(z>2 && z%2==1)
                                                    {
                                                        quantidadeEmenta = atof(linha2);

                                                        quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                        fileF3 = fopen(caminho, "w");
                                                        fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                        fclose(fileF3);
                                                    }
                                                    z++;
                                                }
                                                fclose(fileF2);
                                            }
                                        }
                                    }
                                }
                                fclose(fileF);

                                strcpy(caminho, "Files/Pedidos/Bebida.txt");
                                fileF = fopen(caminho, "r");

                                if (fileF)
                                {
                                    n++;
                                    while (!feof(fileF))
                                    {
                                        result = fgets(linha, 100, fileF);
                                        strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                                        linha[strcspn(linha, "\n")] = 0;
                                        strcat(caminho, linha); //junta strings
                                        strcat(caminho, ".txt");

                                        fileF2 = fopen(caminho, "r");

                                        if(result)
                                        {
                                            if(fileF2)
                                            {
                                                int z = 0;
                                                while(!feof(fileF2))
                                                {
                                                    result = fgets(linha2, 100, fileF2);

                                                    linha2[strcspn(linha2, "\n")] = 0;

                                                    char nomeProduto[100];
                                                    float quantidadeProduto;
                                                    float quantidadeEmenta;

                                                    if(z==0)
                                                    {
                                                    }

                                                    else if(z==1)
                                                    {
                                                        float custoUnitario = atof(linha2);
                                                        custoTotal += custoUnitario;
                                                    }
                                                    else if(z>1 && z%2==0)
                                                    {
                                                        strcpy(caminho, "Files/Produtos/");
                                                        linha2[strcspn(linha2, "\n")] = 0;
                                                        strcat(caminho, linha2);
                                                        strcat(caminho, ".txt");

                                                        fileF3 = fopen(caminho, "r");

                                                        if(fileF3)
                                                        {
                                                            int y = 0;
                                                            while (!feof(fileF3))
                                                            {

                                                                result = fgets(linha3, 100, fileF3);

                                                                if (y == 0)
                                                                {
                                                                    strcpy(nomeProduto, linha3);
                                                                }
                                                                if (y == 1)
                                                                {
                                                                    quantidadeProduto = atof(linha3);
                                                                }
                                                                y++;
                                                            }
                                                        }
                                                        fclose(fileF3);
                                                    }
                                                    else if(z>2 && z%2==1)
                                                    {
                                                        quantidadeEmenta = atof(linha2);

                                                        quantidadeProduto = quantidadeProduto - quantidadeEmenta;

                                                        fileF3 = fopen(caminho, "w");
                                                        fprintf(fileF3, "%s%.2f", nomeProduto, quantidadeProduto);

                                                        fclose(fileF3);
                                                    }
                                                    z++;
                                                }
                                                fclose(fileF2);
                                            }
                                        }
                                    }
                                }
                                fclose(fileF);
                                if(n==0)
                                {
                                    printf(RED"\n==================================="RESET);
                                    printf(RED"\nIntroduza uma ementa ao seu pedido!"RESET);
                                    printf(RED"\n==================================="RESET);
                                    printf(GREEN"\n\nSelecione qualquer tecla para continuar"RESET);
                                    getch();
                                }
                                else if(n>0)
                                {
                                    mkdir("Files/Saldo/", 0777);
                                    strcpy(caminho, "Files/Saldo/SaldoTotal.txt");
                                    char auxcustoTotalS[50];
                                    float auxcustoTotal;

                                    if(fileF = fopen(caminho, "r"))
                                    {
                                        fscanf(fileF, "%s", auxcustoTotalS);
                                        auxcustoTotal = atof(auxcustoTotalS);

                                        auxcustoTotal += custoTotal; // CERTO

                                        fclose(fileF);

                                        fileF = fopen(caminho, "w");
                                        fprintf(fileF, "%.2f", auxcustoTotal);
                                        fclose(fileF);
                                    }
                                    else
                                    {
                                          fileF = fopen(caminho ,"w");
                                          fprintf(fileF, "%.2f", custoTotal);
                                          fclose(fileF);
                                    }

                                    printf(GREEN"\nO total a pagar e de %.2f!"RESET, custoTotal);

                                    printf(GREEN"\n\nObrigado pela sua visita, volte sempre!"RESET);

                                    printf(GREEN"\n\nSelecione qualquer tecla para pagar!"RESET);
                                    getch();
                                }
                                system("cls");
                        }
                        remove("Files/Pedidos/PequenoAlmoco.txt");
                        remove("Files/Pedidos/Almoco.txt");
                        remove("Files/Pedidos/Lanche.txt");
                        remove("Files/Pedidos/Jantar.txt");
                        remove("Files/Pedidos/Sobremesa.txt");
                        remove("Files/Pedidos/Bebidas.txt");

                    }
                    if(opc2==8)     //Listar Pedido
                    {
                        char linha2[100];
                        printf(YELLOW"================ P E D I D O ================\n"RESET);

                        strcpy(caminho, "Files/Pedidos/PequenoAlmoco.txt");
                        fileF = fopen(caminho, "r");
                        int j = 1;

                        if (fileF)
                        {
                            printf(CYAN"\nP E Q U E N O  -  A L M O C O :\n"RESET);
                            int k = 0;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                if(result)
                                {
                                    strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(fileF2)
                                    {
                                        int z=0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);
                                            linha2[strcspn(linha2, "\n")] = 0;

                                                if(z==0)
                                                {

                                                    printf(CYAN"\n%d - %s........."RESET,j, linha2);
                                                    j+=1;
                                                }
                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s"RESET,linha2);
                                                }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                                k++;
                            }
                        }
                        fclose(fileF);

                        strcpy(caminho, "Files/Pedidos/Almoco.txt");
                        fileF = fopen(caminho, "r");

                        if (fileF)
                        {
                            printf(CYAN"\n\nA L M O C O :\n"RESET);
                            int k = 0;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                if(result)
                                {
                                    strcpy(caminho, "Files/Ementas/Almoco/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(fileF2)
                                    {
                                        int z=0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);
                                            linha2[strcspn(linha2, "\n")] = 0;

                                                if(z==0)
                                                {

                                                    printf(CYAN"\n%d - %s........."RESET,j, linha2);
                                                    j+=1;
                                                }
                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s"RESET,linha2);
                                                }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                                k++;
                            }
                        }

                        fclose(fileF);

                        strcpy(caminho, "Files/Pedidos/Lanche.txt");
                        fileF = fopen(caminho, "r");

                        if (fileF)
                        {
                            printf(CYAN"\n\nL A N C H E :\n"RESET);
                            int k = 0;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                if(result)
                                {
                                    strcpy(caminho, "Files/Ementas/Lanche/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(fileF2)
                                    {
                                        int z=0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);
                                            linha2[strcspn(linha2, "\n")] = 0;

                                                if(z==0)
                                                {

                                                    printf(CYAN"\n%d - %s........."RESET,j, linha2);
                                                    j+=1;
                                                }
                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s"RESET,linha2);
                                                }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                                k++;
                            }
                        }
                        fclose(fileF);

                        strcpy(caminho, "Files/Pedidos/Jantar.txt");
                        fileF = fopen(caminho, "r");

                        if (fileF)
                        {
                            printf(CYAN"\n\nJ A N T A R :\n"RESET);
                            int k = 0;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                if(result)
                                {
                                    strcpy(caminho, "Files/Ementas/Jantar/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(fileF2)
                                    {
                                        int z=0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);
                                            linha2[strcspn(linha2, "\n")] = 0;

                                                if(z==0)
                                                {

                                                    printf(CYAN"\n%d - %s........."RESET,j, linha2);
                                                    j+=1;
                                                }
                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s"RESET,linha2);
                                                }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                                k++;
                            }
                        }

                        fclose(fileF);


                        strcpy(caminho, "Files/Pedidos/Sobremesa.txt");
                        fileF = fopen(caminho, "r");

                        if (fileF)
                        {
                            printf(CYAN"\n\nS O B R E M E S A :\n"RESET);
                            int k = 0;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                if(result)
                                {
                                    strcpy(caminho, "Files/Ementas/Sobremesa/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(fileF2)
                                    {
                                        int z=0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);
                                            linha2[strcspn(linha2, "\n")] = 0;

                                                if(z==0)
                                                {

                                                    printf(CYAN"\n%d - %s........."RESET,j, linha2);
                                                    j+=1;
                                                }
                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s"RESET,linha2);
                                                }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                                k++;
                            }
                        }
                        fclose(fileF);

                        strcpy(caminho, "Files/Pedidos/Bebida.txt");
                        fileF = fopen(caminho, "r");

                        if (fileF)
                        {
                            printf(CYAN"\n\nB E B I D A :\n"RESET);
                            int k = 0;
                            while (!feof(fileF))
                            {
                                result = fgets(linha, 100, fileF);
                                if(result)
                                {
                                    strcpy(caminho, "Files/Ementas/Bebida/"); //limpar variavel, copia o segundo parametro
                                    linha[strcspn(linha, "\n")] = 0;
                                    strcat(caminho, linha); //junta strings
                                    strcat(caminho, ".txt");

                                    fileF2 = fopen(caminho, "r");

                                    if(fileF2)
                                    {
                                        int z=0;
                                        while(!feof(fileF2))
                                        {
                                            result = fgets(linha2, 100, fileF2);
                                            linha2[strcspn(linha2, "\n")] = 0;

                                                if(z==0)
                                                {

                                                    printf(CYAN"\n%d - %s........."RESET,j, linha2);
                                                    j+=1;
                                                }
                                                else if(z==1)
                                                {
                                                    printf(CYAN"%s"RESET,linha2);
                                                }
                                            z++;
                                        }
                                        fclose(fileF2);
                                    }
                                }
                                k++;
                            }
                        }
                        fclose(fileF);

                        printf(GREEN"\n\nPresione qualquer tecla para continuar"RESET);
                        getch();
                        system("cls");

                        }
                        if(opc2==9)     //Listar Pedido
                        {
                            printf(YELLOW"================A N U L A R================ \n"RESET);

                            remove("Files/Pedidos/PequenoAlmoco.txt");
                            remove("Files/Pedidos/Almoco.txt");
                            remove("Files/Pedidos/Lanche.txt");
                            remove("Files/Pedidos/Jantar.txt");
                            remove("Files/Pedidos/Sobremesa.txt");
                            remove("Files/Pedidos/Bebidas.txt");

                            printf(GREEN"\n------------------------------\n"RESET);
                            printf(GREEN"Pedido anulado com secesso"RESET);
                            printf(GREEN"\n------------------------------\n"RESET);

                            printf(GREEN"\nPresione qualquer tecla para continuar"RESET);
                            getch();
                            system("cls");
                        }
                        if(opc2==0)
                        {
                            b=0;
                        }

                break;
            case 0:
                b=0;
                a=0;
                break;
                }
            }
        }
    }
}
