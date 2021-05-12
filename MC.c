#include <stdio.h>
#include <string.h>

int main()
{
    int a=1, opcao, contador, idFuncionario;
    char nomeF[50], estatutoF[50];
    float salarioF;
    char* dirnameFuncionarios = "Funcionarios";
    char* dirnameFile = "Files";
    char  caminho[100], contadorString[100], iString[100], result, linha[100];

    int quantidadeS;
    char ingredienteS[50], validadeS[50];

    FILE *fileF;
    FILE *fileContadorFuncionario;
    FILE *fileContadorStock;

   //funções
    void contadorInteiroFuncionarios()
    {
        fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "r");
        fscanf(fileContadorFuncionario, "%d", &contador);
    }

    void contadorInteiroStock()
    {
        fileContadorStock = fopen ("Files/Stock/ContadorFuncionarios.txt", "r");
        fscanf(fileContadorStock, "%d", &contador);
    }

    while (a==1){
        mkdir(dirnameFile, 0777);

        printf("\n--------------Menu----------------\n");
        printf("1 - Gestao da Empresa\n");
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
            printf("\n0 - Voltar\n");
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
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    printf("Nome: ");
                    scanf("%s", &nomeF);
                    printf("Estatuto: ");
                    scanf("%s", &estatutoF);
                    printf("Salario: ");
                    scanf("%f", &salarioF);

                    contador = 1;

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
                    fprintf(fileF, "%s\n%s\n%.2f\n", nomeF, estatutoF, salarioF);
                    fclose(fileF);

                    printf("\nO ID do funcionario %s e %d!", nomeF, contador);

                    contador += 1;

                    fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "w");
                    fprintf(fileContadorFuncionario, "%d", contador);
                    fclose(fileContadorFuncionario);

                    break;

                case 2:
                    printf("\nPressione 0 para voltar.\n");
                    printf("Introduza o Id do funcionario: ");
                    scanf("%d", &idFuncionario);

                    if(idFuncionario == 0) break;

                    strcpy(caminho, "Files/Funcionarios/");
                    sprintf(iString, "%d", idFuncionario);
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

                default:
                    break;
                }

            break;

            case 2:
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar stock\n"); //criar uma pasta ingredientes com um txt do produto, e dentro a quantidade
                printf("2 - Remover stock\n");
                printf("3 - Listar Stock");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    mkdir("Files/Stock", 0777);

                    contador = 1;

                    printf("Ingrediente: ");
                    scanf("%s", &ingredienteS);
                    printf("Quantidade: ");
                    scanf("%d", &quantidadeS);
                    printf("Data de validade(dd/mm/aaaa): ");
                    scanf("%s", &validadeS);

                    if(!fileContadorStock)
                    {
                       fileContadorStock = fopen("Files/Stock/ContadorStock.txt" ,"w");
                       fprintf(fileContadorStock, "%d", contador);
                       fclose(fileContadorStock);
                    }

                    contadorInteiroStock();

                    sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString

                    strcpy(caminho, "Files/Stock/"); //limpar variavel, copia o segundo parametro
                    strcat(caminho, contadorString); //junta strings
                    strcat(caminho, ".txt");

                    fileF = fopen(caminho, "w");
                    fprintf(fileF, "%s\n%d\n%s\n", ingredienteS, quantidadeS, validadeS);
                    fclose(fileF);

                    printf("\nO ID do ingrediente %s e %d!", ingredienteS, contador);

                    contador += 1;

                    fileContadorStock = fopen ("Files/Stock/ContadorStock.txt", "w");
                    fprintf(fileContadorStock, "%d", contador);
                    fclose(fileContadorStock);

                    break;

                case 2:

                    break;


                case 3:


                    break;

                }

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
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar cliente\n");
                printf("2 - Remover cliente\n");
                printf("3 - Listar clientes\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);
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
