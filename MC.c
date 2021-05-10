#include <stdio.h>
#include <string.h>


int main()
{
    int a=1, opc1=0, opc2=0, opc3=0, opc4=0, opc5=0, opc6=0, opc7=0, check;
    char* dirnameFuncionarios = "Funcionarios";
    char* dirnameFile = "Files";
    char* texto[50];
    char* contador[10]= {'10'};
    FILE *ContadorFuncionarios = NULL;


    while (a==1){

        check = mkdir(dirnameFile, 0777);

        if (!check)
            printf("Directory created\n");
        else {
            printf("Unable to create directory\n");
        }

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
                    if (!check)
                    {
                        printf("Directory created\n");
                    }
                    else
                    {
                        printf("Unable to create directory\n");
                    }
                    ContadorFuncionarios = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"a");
                    fprintf("%s", contador);
                    fclose(ContadorFuncionarios);
                    break;

                case 0:

                    break;

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
