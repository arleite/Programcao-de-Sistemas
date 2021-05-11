#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int idFuncionario;
    int contador=0;
    char contadorString[100];
    char iString[100];
    float salarioF;
    int a=1, opc1=0, opc2=0, opc3=0, opc4=0, opc5=0, opc6=0, opc7=0, check;
    char caminhoF[] = "Files/Funcionarios/";
    char* dirnameFuncionarios = "Funcionarios";
    char* result;
    char linha[100];
    char* dirnameFile = "Files";
    char* nomeF[50], estatutoF[50];

    FILE *FileF;
    FILE *ContadorFuncionarios;

   //funções
    void contadorInteiro (){
        ContadorFuncionarios = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "r");
        fscanf(ContadorFuncionarios, "%d", &contador);}




    while (a==1){

        check = mkdir(dirnameFile, 0777);

        printf("\n--------------Menu----------------\n");
        printf("1 - Gestao da Empresa\n");
        printf("2 - Cliente\n");
        printf("\n0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opc1);

        //Menu de Gestão da empresa
        switch (opc1)
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
            scanf("%d", &opc2);

            switch (opc2)
            {
            case 1:
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar funcionario\n");
                printf("2 - Remover funcionario\n");
                printf("3 - Listar funcionarios\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opc3);


                switch (opc3)
                {
                case 1:
                    check = mkdir("Files/Funcionarios", dirnameFile, 0777);

                    printf("Nome: ");
                    scanf("%s", &nomeF);
                    printf("Estatuto: ");
                    scanf("%s", &estatutoF);
                    printf("Salario: ");
                    scanf("%f", &salarioF);

                    if(!ContadorFuncionarios)
                    {
                       ContadorFuncionarios = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"w");
                       fprintf(ContadorFuncionarios, "%d", contador);
                       fclose(ContadorFuncionarios);
                    }

                    contadorInteiro(); //função para ir buscar o valor inteiro do ficheiro contador

                    sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString

                    strcat(caminhoF, contadorString); //junta strings
                    strcat(caminhoF, ".txt");

                    FileF = fopen(caminhoF, "w");
                    fprintf(FileF, "%s\n%s\n%.2f\n", nomeF, estatutoF, salarioF);
                    fclose(FileF);

                    contador += 1;

                    strcpy(caminhoF, "Files/Funcionarios/"); //limpar variavel, copia o segundo parametro

                    ContadorFuncionarios = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "w");
                    fprintf(ContadorFuncionarios, "%d", contador);
                    fclose(ContadorFuncionarios);

                    break;

                case 2:
                    printf("Introduza o Id do funcionário: ");
                    scanf("%d", &idFuncionario);

                    sprintf(iString, "%d", idFuncionario);
                    strcat(caminhoF, iString);
                    strcat(caminhoF, ".txt");

                    FileF = caminhoF;

                    if(FileF != NULL)
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

                        FileF = fopen(caminhoF, "r");

                        int k = 0;

                         while (!feof(FileF))
                        {
                            result = fgets(linha, 100, FileF);

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

                        fclose(FileF);

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
                scanf("%d", &opc4);
                break;

            case 3:
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar ementa\n");
                printf("2 - Remover ementa\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opc5);
                break;

            case 4:
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar cliente\n");
                printf("2 - Remover cliente\n");
                printf("3 - Listar clientes\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opc6);
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
            scanf("%d", &opc7);

            break;

        case 0:
            a=0;
            break;

        default:
            break;
        }

    }
}
