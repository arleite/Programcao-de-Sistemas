#include <stdio.h>
#include <string.h>

int main()
{
    int a=1, opcao, contador, idFuncionario;
    char nomeF[50], estatutoF[50];
    float salarioF;
    char* dirnameFuncionarios = "Funcionarios";
    char* dirnameFile = "Files";
    char caminhoF[] = "Files/Funcionarios/";
    char contadorString[100], iString[100], result;
    char linha[100];

    FILE *fileF;
    FILE *fileContadorFuncionario;

   //funções
    void contadorInteiro(){
        fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "r");
        fscanf(fileContadorFuncionario, "%d", &contador);}

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
                    mkdir("Files/Funcionarios", dirnameFile, 0777);

                    printf("Nome: ");
                    scanf("%s", &nomeF);
                    printf("Estatuto: ");
                    scanf("%s", &estatutoF);
                    printf("Salario: ");
                    scanf("%f", &salarioF);

                    if(!fileContadorFuncionario)
                    {
                       fileContadorFuncionario = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"w");
                       fprintf(fileContadorFuncionario, "%d", contador);
                       fclose(fileContadorFuncionario);
                    }

                    contadorInteiro(); //função para ir buscar o valor inteiro do ficheiro contador

                    sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString

                    strcat(caminhoF, contadorString); //junta strings
                    strcat(caminhoF, ".txt");

                    fileF = fopen(caminhoF, "w");
                    fprintf(fileF, "%s\n%s\n%.2f\n", nomeF, estatutoF, salarioF);
                    fclose(fileF);

                    contador += 1;

                    strcpy(caminhoF, "Files/Funcionarios/"); //limpar variavel, copia o segundo parametro

                    fileContadorFuncionario = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "w");
                    fprintf(fileContadorFuncionario, "%d", contador);
                    fclose(fileContadorFuncionario);

                    break;

                case 2:
                    printf("Introduza o Id do funcionário: ");
                    scanf("%d", &idFuncionario);

                    sprintf(iString, "%d", idFuncionario);
                    strcat(caminhoF, iString);
                    strcat(caminhoF, ".txt");

                    fileF = caminhoF;

                    if(fileF != NULL)
                    {
                       remove(caminhoF);
                       printf("Funcionario eliminado com sucesso!");
                    }
                    else
                    {
                        printf("O funcionario nao existe!");
                    }

                    break;

                case 3:

                    contadorInteiro();

                    for(int i = 0; contador > i;i++)
                    {

                        sprintf(iString, "%d", i);
                        strcat(iString, ".txt");
                        strcat(caminhoF, iString);

                        fileF = fopen(caminhoF, "r");

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

                        strcpy(caminhoF, "Files/Funcionarios/");
                    }

                    break;

                default:
                    break;
                }

            break;

            case 2:
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar stock\n");
                printf("2 - Remover stock\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);
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
