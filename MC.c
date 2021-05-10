#include <stdio.h>
#include <string.h>


int main()
{
    int contador = 0;
    float salarioF;
    int a=1, opc1=0, opc2=0, opc3=0, opc4=0, opc5=0, opc6=0, opc7=0, check;
    char caminhoF[] = "Files/Funcionarios";
    char* dirnameFuncionarios = "Funcionarios";
    char* dirnameFile = "Files";
    char* nomeF[50], estatutoF[50];

    FILE *FileF;
    FILE *ContadorFuncionarios = NULL;


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
                    if (!check) { printf("Directory created\n"); } else { printf("Unable to create directory\n"); }

                    printf("Nome");
                    scanf("%s", &nomeF);
                    printf("Estatuto");
                    scanf("%s", &estatutoF);
                    printf("Salario");
                    scanf("%f", &salarioF);


                    if(!ContadorFuncionarios)
                    {
                       ContadorFuncionarios = fopen("Files/Funcionarios/ContadorFuncionarios.txt" ,"w");
                       fprintf(ContadorFuncionarios, "%d", contador);
                       fclose(ContadorFuncionarios);
                    }




                    ContadorFuncionarios = fopen ("Files/Funcionarios/ContadorFuncionarios.txt", "r");
                    fscanf(ContadorFuncionarios, "%d", &contador);

                    printf("%d", contador); //ler contador do ficheiro

                    printf("%s",caminhoF);


                    //strcpy(caminhoF, contador); /////////////o erro está aqui

                    //sprintf(caminhoF, contador); //////////// tentei fazer com isto mas tambem não está a dar



                    //printf("%s", caminhoF);

                    //FileF = fopen(caminhoF, "w");

                    //fprintf(FileF, "%s\n%s\n%f\n", nomeF, estatutoF, salarioF);

                    //fclose(FileF);




                    fclose(ContadorFuncionarios);






                    //fprintf("%s", contador);

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
