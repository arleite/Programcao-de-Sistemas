#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int a=1, opcao, letras = 0, contador = 1, id, b=1;
    char nomeF[50], estatutoF[50], salarioF[50];
    char* dirnameFuncionarios = "Funcionarios";
    char* dirnameFile = "Files";
    char* dirnameClientes= "Clientes";
    char  caminho[100], contadorString[100], iString[100], result, linha[100], auxIngrediente[50];

    int quantidadeS;
    char ingredienteS[50];

    int aux;
    char nomeC[50], numeroTC[50], nifC[50];

    FILE *fileF;
    FILE *fileContadorFuncionario;
    FILE *fileContadorStock;
    FILE *fileContadorCliente;

   //funções
    void contadorInteiroFuncionarios(){
        fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "r");
        fscanf(fileContadorFuncionario, "%d", &contador);
    }
    void contadorInteiroProduto(){
        fileContadorStock = fopen ("Files/Produtos/ContadorProdutos.txt", "r");
        fscanf(fileContadorStock, "%d", &contador);
    }
    void contadorInteiroClientes(){
        fileContadorCliente = fopen ("Files/Clientes/ContadorClientes.txt", "r");
        fscanf(fileContadorCliente, "%d", &contador);
    }


    while (a==1){
        mkdir(dirnameFile, 0777);

        printf("\n--------------Menu----------------\n");
        printf("\n1 - Gestao da Empresa\n");
        printf("2 - Cliente\n");
        printf("\n0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            printf("\n--------------Gestao da Empresa----------------\n");
            printf("\n1 - Gerir funcionarios\n"); // adicionar remover e listar
            printf("2 - Gerir stock\n"); // adicionar e listar
            printf("3 - Gerir ementa\n"); //adicionar e remover
            printf("4 - Gerir clientes\n");//adicionar e remover
            printf("5 - Dinheiro total\n");
            printf("\n0 - Voltar ao menu inicial\n");
            printf("\nSelecione uma opcao: ");
            scanf("%d", &opcao);

            system("cls");

            switch (opcao)
            {
            case 1:
                mkdir("Files/Funcionarios", 0777);
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar funcionario\n");
                printf("2 - Remover funcionario\n");
                printf("3 - Listar funcionarios\n");
                printf("\n9 - Voltar ao menu anterior\n");
                printf("0 - Voltar ao menu inicial\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                system("cls");

                switch (opcao)
                {
                case 1:
                    printf("Adicionar o funcionario\n");
                    printf("Nome: ");
                    scanf("%s", &nomeF);

                    while (b == 1) //verificar que só introduziu letras
                    {
                        for (int i = 0; nomeF[i] != '\0'; i++)
                        {
                            if (isalpha(nomeF[i]))
                                letras++;
                        }
                        if (strlen(nomeF) != letras)
                        {
                            letras = 0;
                            printf("Introduza apenas letras!\n");
                            printf("Nome: ");
                            scanf("%s", &nomeF);
                        }
                        else
                        {
                            letras = 0;
                            b = 0;
                        }
                    }

                    printf("Estatuto: ");
                    scanf("%s", &estatutoF);
                    b = 1;
                    while (b == 1) //verificar que só introduziu letras
                    {
                        for (int i = 0; estatutoF[i] != '\0'; i++)
                        {
                            if (isalpha(estatutoF[i]))
                                letras++;
                        }
                        if (strlen(estatutoF) != letras)
                        {
                            letras = 0;
                            printf("Introduza apenas letras!\n");
                            printf("Estatuto: ");
                            scanf("%s", &estatutoF);
                        }
                        else
                        {
                            letras = 0;
                            b = 0;
                        }
                    }

                    printf("Salario: ");
                    scanf("%s", &salarioF);

                    b=1;
                    while (b == 1) //verificar que só introduziu letras
                    {
                        letras=0;
                        for (int i=0; salarioF[i] != '\0'; i++)
                        {
                            if(isdigit(salarioF[i]))
                                letras++;
                        }
                        aux = strlen(salarioF);
                        if (strlen(salarioF) != letras && strlen(salarioF) != letras+1)
                        {
                            printf("%d, %d", letras, aux);
                            printf("\nIntroduza um numero valido!\n");
                            printf("Salario: ");
                            scanf("%s", salarioF);
                        }
                        else
                        {
                            b = 0;
                        }
                    }


                    if(!fileContadorFuncionario)
                    {
                       fileContadorFuncionario = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"w");
                       fprintf(fileContadorFuncionario, "%d", contador);
                       fclose(fileContadorFuncionario);
                    }

                    contadorInteiroFuncionarios(); //função para ir buscar o valor inteiro do ficheiro contador

                    sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                    strcpy(caminho, "Files/Funcionarios/"); //limpar variavel, copia o segundo parametro
                    strcat(caminho, contadorString); //junta strings
                    strcat(caminho, ".txt");

                    fileF = fopen(caminho, "w");
                    fprintf(fileF, "%s\n%s\n%s\n", nomeF, estatutoF, salarioF);
                    fclose(fileF);

                    printf("\nO ID do funcionario %s e %d!", nomeF, contador);

                    contador += 1;

                    fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "w");
                    fprintf(fileContadorFuncionario, "%d", contador);
                    fclose(fileContadorFuncionario);

                    break;

                case 2:
                    printf("Remover funcionario\n");
                    printf("Pressione 0 para voltar.\n");
                    printf("Introduza o Id do funcionario: ");
                    scanf("%d", &id);

                    if(id == 0) break;

                    strcpy(caminho, "Files/Funcionarios/");
                    sprintf(iString, "%d", id);
                    strcat(caminho, iString);
                    strcat(caminho, ".txt");

                    fileF = fopen(caminho, "r");
                    fclose(fileF);

                    printf("\n%s", caminho);

                    if(fileF)
                    {
                       remove(caminho);
                       printf("\n-----------------------------------\n");
                       printf("Funcionario eliminado com sucesso!");
                       printf("\n-----------------------------------\n\n");
                    }
                    else
                    {
                        printf("\n-----------------------------------\n");
                        printf("\nEsse funcionario nao existe!");
                        printf("\n-----------------------------\n\n");
                        //printf("\n%s", caminho);
                    }


                    break;

                case 3:
                    contadorInteiroFuncionarios();

                    for(int i = 1; contador > i;i++)
                    {
                        strcpy(caminho, "Files/Funcionarios/");
                        sprintf(iString, "%d", i);
                        strcat(iString, ".txt");
                        strcat(caminho, iString);

                        fileF = fopen(caminho, "r");
                        //printf("\n%s", caminho); Ver caminho
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
                                            printf("\n--------------------\n\n");
                                            printf("Id: %d\n", i);
                                            printf("Nome: %s", linha);
                                        }
                                        if(k==1)
                                        {
                                            printf("Estatuto: %s", linha);
                                        }
                                        if(k==2)
                                        {
                                            printf("Salario: %s", linha);
                                        }
                                    }
                                k++;
                            }
                        fclose(fileF);
                        }
                    }
                    break;
                }
            break;


            case 2:
                printf("\n--------------Gestao de Stock----------------\n");
                printf("\n1 - Adicionar produto\n"); //criar uma pasta ingredientes com um txt do produto, e dentro a quantidade
                printf("2 - Editar stock\n");
                printf("3 - Listar produto\n");
                printf("4 - Eliminar produto\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);
                mkdir("Files/Produtos", 0777);

                switch (opcao)
                {
                case 1:
                    printf("Ingrediente: ");
                    scanf("%s", &ingredienteS);
                    printf("Quantidade: ");
                    scanf("%d", &quantidadeS);


                    if(!fileContadorStock)
                    {
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
                    fprintf(fileF, "%s\n%d\n", ingredienteS, quantidadeS);
                    fclose(fileF);

                    printf("\nO ID do ingrediente %s e %d!", ingredienteS, contador);

                    contador += 1;

                    fileContadorStock = fopen ("Files/Produtos/ContadorProdutos.txt", "w");
                    fprintf(fileContadorStock, "%d", contador);
                    fclose(fileContadorStock);

                    break;

                case 2:
                    printf("1 - Adicionar stock\n");
                    printf("2 - Remover stock\n");
                    scanf("%d", &opcao);

                    if(opcao == 1)
                    {
                        printf("Introduza o ID do produto a editar: \n");
                        scanf("%d", &id);

                        sprintf(iString, "%d", id);
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
                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("O nome do produto e %s", linha);
                                        strcpy(auxIngrediente, linha);
                                    }

                                    if(k==1)
                                    {
                                        printf("A quantidade atual e de %s", linha);
                                        quantidadeS = atoi(linha);
                                    }
                                }
                                k++;
                            }

                        fclose(fileF);
                        }
                        int quatidadeA, quantidadeTotal;

                        printf("\nIntroduza o stock a acrescentar:");
                        scanf("%d", &quatidadeA);

                        quantidadeTotal = quantidadeS + quatidadeA;

                        fileF = fopen(caminho, "w");

                        fprintf(fileF, "%s%d", auxIngrediente, quantidadeTotal);

                        fclose(fileF);
                    }
                    if(opcao == 2)
                    {
                        printf("Introduza o ID do produto a editar: \n");
                        scanf("%d", &id);

                        sprintf(iString, "%d", id);
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
                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("O nome do produto e %s", linha);
                                        strcpy(auxIngrediente, linha);
                                    }

                                    if(k==1)
                                    {
                                        printf("A quantidade atual e de %s", linha);
                                        quantidadeS = atoi(linha);
                                    }
                                }
                                k++;
                            }

                        fclose(fileF);
                        }

                        int quatidadeA, quantidadeTotal;

                        printf("\nIntroduza o stock a remover:");
                        scanf("%d", &quatidadeA);

                        quantidadeTotal = quantidadeS - quatidadeA;

                        fileF = fopen(caminho, "w");

                        fprintf(fileF, "%s%d", auxIngrediente, quantidadeTotal);

                        fclose(fileF);
                    }

                    break;

                case 3:
                    contadorInteiroProduto();

                    for(int i = 1; contador > i;i++)
                    {
                        strcpy(caminho, "Files/Produtos/");
                        sprintf(iString, "%d", i);
                        strcat(iString, ".txt");
                        strcat(caminho, iString);

                        fileF = fopen(caminho, "r");
                        //printf("\n%s", caminho); Ver caminho
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
                                            printf("\n--------------------\n\n");
                                            printf("Id: %d\n", i);
                                            printf("Engrediente: %s", linha);
                                        }
                                        if(k==1)
                                        {
                                            printf("Quantidade: %s", linha);
                                        }
                                    }
                                k++;
                            }
                        fclose(fileF);
                        }
                    }
                    break;

                case 4:
                    printf("Qual o id do produto que pretende eliminar\n");
                    scanf("%d", &id);

                    sprintf(iString, "%d", id); //passar um numero inteiro para char
                    strcpy(caminho, "Files/Produtos/"); //limpar variavel, copia o segundo parametro
                    strcat(caminho, iString); //junta strings
                    strcat(caminho, ".txt");

                    fileF = fopen(caminho, "r");

                    printf("Produto\n");

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
                                    printf("Ingrediente: %s", linha);
                                }

                                if(k==1)
                                {
                                    printf("Stock: %s\n", linha);
                                }
                            }
                            k++;
                        }
                    fclose(fileF);
                    }

                    int aux;

                    printf("Tem a certeza que pretende eliminar este produto\n");
                    printf("Sim - 1\n");
                    printf("Nao - 2\n");
                    scanf("%d", &aux);

                    if(aux == 1)
                    {
                        remove(caminho);
                    }



                }

                break;

            break;

            case 3:
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar ementa\n");
                printf("2 - Remover ementa\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);

            break;

            case 4:
                mkdir("Files/Clientes", 0777);
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar cliente\n");
                printf("2 - Listar clientes\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                if (opcao == 1)
                {
                    printf("Nome: ");
                    scanf("%s", nomeC);
                    printf("\n%s", nomeC);
                    b=1;
                    letras = 0;
                    while (b == 1) //verificar que só introduziu letras
                    {
                        for (int i = 0; nomeC[i] != '\0'; i++)
                        {
                            if (isalpha(nomeC[i]))
                                letras++;
                        }
                        if (strlen(nomeC) != letras)
                        {
                            letras = 0;
                            printf("Introduza apenas letras!\n");
                            printf("Nome: ");
                            scanf("%s", nomeC);
                        }
                        else
                        {
                            b = 0;
                        }
                    }

                    printf("Numero de telemovel: ");
                    scanf("%s", numeroTC);

                    b=1;
                    while (b == 1) //verificar que só introduziu letras
                    {
                        letras=0;
                        aux = atoi(numeroTC);
                        for (int i=0; numeroTC[i] != '\0'; i++)
                        {
                            if(isdigit(numeroTC[i]))
                                letras++;
                        }

                        if (strlen(numeroTC) != letras || aux/100000000 < 9)
                        {
                            printf("\nIntroduza um numero valido!\n");
                            printf("Numero de telemovel: ");
                            scanf("%s", numeroTC);
                        }
                        else
                        {
                            b = 0;
                        }
                    }

                    printf("NIF: ");
                    scanf("%s", nifC);

                    b=1;
                    while (b == 1) //verificar que só introduziu letras
                    {
                        letras=0;
                        aux = atoi(nifC);
                        for (int i=0; nifC[i] != '\0'; i++)
                        {
                            if(isdigit(nifC[i]))
                                letras++;
                        }

                        if (strlen(nifC) != letras || aux/100000000 < 1)
                        {
                            printf("\nIntroduza um numero valido!\n");
                            printf("NIF: ");
                            scanf("%s", nifC);
                        }
                        else
                        {
                            b = 0;
                        }
                    }

                    if(!fileContadorCliente)
                    {
                       contador = 1;
                       fileContadorCliente = fopen("Files/Clientes/ContadorClientes.txt" ,"w");
                       fprintf(fileContadorCliente, "%d", contador);
                       fclose(fileContadorCliente);
                    }

                    contadorInteiroClientes(); //função para ir buscar o valor inteiro do ficheiro contador

                    sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                    strcpy(caminho, "Files/Clientes/"); //limpar variavel, copia o segundo parametro
                    strcat(caminho, contadorString); //junta strings
                    strcat(caminho, ".txt");


                    fileF = fopen(caminho, "w");
                    fprintf(fileF, "%s\n%s\n%s\n", nomeC, numeroTC, nifC);
                    fclose(fileF);

                    printf("\nO ID do cliente %s e %d!", nomeC, contador);

                    contador += 1;

                    fileContadorCliente = fopen ("Files/Clientes/ContadorClientes.txt", "w");
                    fprintf(fileContadorCliente, "%d", contador);
                    fclose(fileContadorCliente);
                }

                if(opcao==2) //////////////////////////////////
                {
                    contadorInteiroClientes();

                    for(int i = 1; contador > i;i++)
                    {
                        strcpy(caminho, "Files/Clientes/");
                        sprintf(iString, "%d", i);
                        strcat(iString, ".txt");
                        strcat(caminho, iString);

                        fileF = fopen(caminho, "r");
                        //printf("\n%s", caminho); Ver caminho
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
                                            printf("\n--------------------\n\n");
                                            printf("Id: %d\n", i);
                                            printf("Nome: %s", linha);
                                        }
                                        if(k==1)
                                        {
                                            printf("Numero de telemovel: %s", linha);
                                        }
                                        if(k==2)
                                        {
                                            printf("NIF: %s", linha);
                                        }
                                    }
                                k++;
                            }
                        fclose(fileF);
                        }
                    }
                }

            break;

            case 5:
                //DINHEIRO TOTAL
            break;

            case 0:

            break;

            default:
                break;
            }
        break;

        case 2:
            printf("\n--------------Cliente----------------\n");
            printf("\n1 - Pequeno-Almoco\n");
            printf("2 - Almoco\n");
            printf("3 - Lanche\n");
            printf("4 - Jantar\n");
            printf("5 - Sobremesa\n");
            printf("6 - Bebida\n");
            printf("7 - Pagar / Anular\n");
            printf("\n0 - Voltar\n");
            scanf("%d", &opcao);

            break;

        case 0:
            a=0;
            break;

        default:
            break;
        }

    }
}
