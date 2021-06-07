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
    FILE *fileContadorPequenoAlmoco;
    FILE *fileContadorAlmoco;
    FILE *fileContadorLanche;
    FILE *fileContadorJantar;
    FILE *fileContadorSobremesa;
    FILE *fileContadorBebida;

   //fun��es
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

                    while (b == 1) //verificar que s� introduziu letras
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
                    while (b == 1) //verificar que s� introduziu letras
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
                    while (b == 1) //verificar que s� introduziu letras
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

                    contadorInteiroFuncionarios(); //fun��o para ir buscar o valor inteiro do ficheiro contador

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

                    break;
                }
            break;

            case 3:
                mkdir("Files/Ementas", 0777);
                printf("\n--------------Menu----------------\n");
                printf("\n1 - Adicionar ementa\n");
                printf("2 - Remover ementa\n");
                printf("\n0 - Voltar\n");
                printf("\nSelecione uma opcao: ");
                scanf("%d", &opcao);

                system("cls");

                char ementa[50];
                float precoEmenta;

                if (opcao == 1)
                {
                    printf("Ementa: ");
                    scanf("%s", ementa);
                    printf("Preco: ");
                    scanf("%f", &precoEmenta);

                    printf("\nLista de Refeicoes");
                    printf("\n------------------------");
                    printf("\n1 - Pequeno-Almoco\n");
                    printf("2 - Almoco\n");
                    printf("3 - Lanche\n");
                    printf("4 - Jantar\n");
                    printf("5 - Sobremesa\n");
                    printf("6 - Bebida\n");
                    printf("------------------------\n");

                    printf("\nIntroduza qual a lista de refeicoes a que corresponde!\n");
                    printf("Opcao: ");
                    scanf("%d", &opcao);

                    system("cls");

                    if(opcao == 1)
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


                        printf("Lista de produtos\n");

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

                                        if(result)
                                        {
                                            if(k==0)
                                            {
                                                printf("--------------------\n");
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

                        printf("--------------------\n\n");
                        printf("Quais os produtos que constituem essa ementa?\n");

                        printf("Adicione por ID: ");
                        scanf("%d", &id);

                        int stock;
                        printf("Quantidade necessaria: ");
                        scanf("%d", &stock);

                        contadorInteiroPequenoAlmoco();
                        sprintf(contadorString, "%d",contador); //passar o valor do contador para string, ou seja, contadorString
                        strcpy(caminho, "Files/Ementas/PequenoAlmoco/"); //limpar variavel, copia o segundo parametro
                        strcat(caminho, contadorString); //junta strings
                        strcat(caminho, ".txt");

                        fileF = fopen(caminho, "w");
                        fprintf(fileF, "%s\n%.2f\n%d\n%d\n", ementa, precoEmenta, id, stock);
                        fclose(fileF);

                        contador += 1;

                        fileContadorPequenoAlmoco = fopen ("Files/Ementas/PequenoAlmoco/ContadorPequenoAlmoco.txt", "w");
                        fprintf(fileContadorPequenoAlmoco, "%d", contador);
                        fclose(fileContadorPequenoAlmoco);

                        b=1;
                        while (b == 1)
                        {
                            printf("\nEsta ementa possui mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Nao\n");
                            printf("\nOpcao:");
                            scanf("%d", &opcao);

                            if(opcao == 1)
                            {
                                printf("\nQuais os produtos que constituem essa ementa?\n");


                                printf("Adicione por ID: ");
                                scanf("%d", &id);

                                int stock;
                                printf("Quantidade necessaria: ");
                                scanf("%d", &stock);

                                fileF = fopen(caminho, "a");
                                fprintf(fileF, "%d\n%d\n", id, stock);
                                fclose(fileF);

                            }
                            if (opcao == 2)
                            {
                                if (fileF = fopen(caminho ,"r"))
                                {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa criada com sucesso!");
                                    printf("\n-----------------------------------\n");
                                    fclose(fileF);
                                    sleep(1);
                                    system("cls");
                                    b=0;
                                } else {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa não foi criada!");
                                    printf("\n-----------------------------------\n");
                                    sleep(1);
                                    system("cls");
                                    b=0;
                                }
                            }
                        }
                    }

                    if(opcao == 2)
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


                        printf("Lista de produtos\n");

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

                                        if(result)
                                        {
                                            if(k==0)
                                            {
                                                printf("--------------------\n");
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

                        printf("--------------------\n\n");
                        printf("Quais os produtos que constituem essa ementa?\n");

                        printf("Adicione por ID: ");
                        scanf("%d", &id);

                        int stock;
                        printf("Quantidade necessaria: ");
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

                        b=1;
                        while (b == 1)
                        {
                            printf("\nEsta ementa possui mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Nao\n");
                            printf("\nOpcao:");
                            scanf("%d", &opcao);

                            if(opcao == 1)
                            {
                                printf("\nQuais os produtos que constituem essa ementa?\n");


                                printf("Adicione por ID: ");
                                scanf("%d", &id);

                                int stock;
                                printf("Quantidade necessaria: ");
                                scanf("%d", &stock);

                                fileF = fopen(caminho, "a");
                                fprintf(fileF, "%d\n%d\n", id, stock);
                                fclose(fileF);

                            }
                            if (opcao == 2)
                            {
                                if (fileF = fopen(caminho ,"r"))
                                {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa criada com sucesso!");
                                    printf("\n-----------------------------------\n");
                                    fclose(fileF);
                                    sleep(1);
                                    system("cls");
                                    b=0;
                                } else {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa não foi criada!");
                                    printf("\n-----------------------------------\n");
                                    sleep(1);
                                    system("cls");
                                    b=0;
                                }
                            }
                        }

                    }

                    if(opcao == 3)
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


                        printf("Lista de produtos\n");

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

                                        if(result)
                                        {
                                            if(k==0)
                                            {
                                                printf("--------------------\n");
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

                        printf("--------------------\n\n");
                        printf("Quais os produtos que constituem essa ementa?\n");

                        printf("Adicione por ID: ");
                        scanf("%d", &id);

                        int stock;
                        printf("Quantidade necessaria: ");
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
                            printf("\nEsta ementa possui mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Nao\n");
                            printf("\nOpcao:");
                            scanf("%d", &opcao);

                            if(opcao == 1)
                            {
                                printf("\nQuais os produtos que constituem essa ementa?\n");


                                printf("Adicione por ID: ");
                                scanf("%d", &id);

                                int stock;
                                printf("Quantidade necessaria: ");
                                scanf("%d", &stock);

                                fileF = fopen(caminho, "a");
                                fprintf(fileF, "%d\n%d\n", id, stock);
                                fclose(fileF);

                            }
                            if (opcao == 2)
                            {
                                if (fileF = fopen(caminho ,"r"))
                                {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa criada com sucesso!");
                                    printf("\n-----------------------------------\n");
                                    fclose(fileF);
                                    sleep(1);
                                    system("cls");
                                    break;
                                } else {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa não foi criada!");
                                    printf("\n-----------------------------------\n");
                                    sleep(1);
                                    system("cls");
                                    break;
                                }
                            }
                        }

                    }
                    if(opcao == 4)
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


                        printf("Lista de produtos\n");

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

                                        if(result)
                                        {
                                            if(k==0)
                                            {
                                                printf("--------------------\n");
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

                        printf("--------------------\n\n");
                        printf("Quais os produtos que constituem essa ementa?\n");

                        printf("Adicione por ID: ");
                        scanf("%d", &id);

                        int stock;
                        printf("Quantidade necessaria: ");
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
                            printf("\nEsta ementa possui mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Nao\n");
                            printf("\nOpcao:");
                            scanf("%d", &opcao);

                            if(opcao == 1)
                            {
                                printf("\nQuais os produtos que constituem essa ementa?\n");


                                printf("Adicione por ID: ");
                                scanf("%d", &id);

                                int stock;
                                printf("Quantidade necessaria: ");
                                scanf("%d", &stock);

                                fileF = fopen(caminho, "a");
                                fprintf(fileF, "%d\n%d\n", id, stock);
                                fclose(fileF);

                            }
                            if (opcao == 2)
                            {
                                if (fileF = fopen(caminho ,"r"))
                                {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa criada com sucesso!");
                                    printf("\n-----------------------------------\n");
                                    fclose(fileF);
                                    sleep(1);
                                    system("cls");
                                    break;
                                } else {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa não foi criada!");
                                    printf("\n-----------------------------------\n");
                                    sleep(1);
                                    system("cls");
                                    break;
                                }
                            }
                        }
                    }
                    if(opcao == 5)
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


                        printf("Lista de produtos\n");

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

                                        if(result)
                                        {
                                            if(k==0)
                                            {
                                                printf("--------------------\n");
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

                        printf("--------------------\n\n");
                        printf("Quais os produtos que constituem essa ementa?\n");

                        printf("Adicione por ID: ");
                        scanf("%d", &id);

                        int stock;
                        printf("Quantidade necessaria: ");
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
                            printf("\nEsta ementa possui mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Nao\n");
                            printf("\nOpcao:");
                            scanf("%d", &opcao);

                            if(opcao == 1)
                            {
                                printf("\nQuais os produtos que constituem essa ementa?\n");


                                printf("Adicione por ID: ");
                                scanf("%d", &id);

                                int stock;
                                printf("Quantidade necessaria: ");
                                scanf("%d", &stock);

                                fileF = fopen(caminho, "a");
                                fprintf(fileF, "%d\n%d\n", id, stock);
                                fclose(fileF);

                            }
                            if (opcao == 2)
                            {
                                if (fileF = fopen(caminho ,"r"))
                                {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa criada com sucesso!");
                                    printf("\n-----------------------------------\n");
                                    fclose(fileF);
                                    sleep(1);
                                    system("cls");
                                    break;
                                } else {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa não foi criada!");
                                    printf("\n-----------------------------------\n");
                                    sleep(1);
                                    system("cls");
                                    break;
                                }
                            }
                        }
                    }
                    if(opcao == 6)
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


                        printf("Lista de produtos\n");

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

                                        if(result)
                                        {
                                            if(k==0)
                                            {
                                                printf("--------------------\n");
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

                        printf("--------------------\n\n");
                        printf("Quais os produtos que constituem essa ementa?\n");

                        printf("Adicione por ID: ");
                        scanf("%d", &id);

                        int stock;
                        printf("Quantidade necessaria: ");
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
                            printf("\nEsta ementa possui mais produtos?\n");
                            printf("1 - Sim\n");
                            printf("2 - Nao\n");
                            printf("\nOpcao:");
                            scanf("%d", &opcao);

                            if(opcao == 1)
                            {
                                printf("\nQuais os produtos que constituem essa ementa?\n");


                                printf("Adicione por ID: ");
                                scanf("%d", &id);

                                int stock;
                                printf("Quantidade necessaria: ");
                                scanf("%d", &stock);

                                fileF = fopen(caminho, "a");
                                fprintf(fileF, "%d\n%d\n", id, stock);
                                fclose(fileF);

                            }
                            if (opcao == 2)
                            {
                                if (fileF = fopen(caminho ,"r"))
                                {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa criada com sucesso!");
                                    printf("\n-----------------------------------\n");
                                    fclose(fileF);
                                    sleep(1);
                                    system("cls");
                                    break;
                                } else {
                                    printf("\n-----------------------------------\n");
                                    printf("Ementa não foi criada!");
                                    printf("\n-----------------------------------\n");
                                    sleep(1);
                                    system("cls");
                                    break;
                                }
                            }
                        }
                    }

                }

                if(opcao == 2)
                {

                }

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
                    b=1;
                    letras = 0;
                    while (b == 1) //verificar que s� introduziu letras
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
                    while (b == 1) //verificar que s� introduziu letras
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
                    while (b == 1) //verificar que s� introduziu letras
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

                    contadorInteiroClientes(); //fun��o para ir buscar o valor inteiro do ficheiro contador

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
            printf("7 - Pagar\n");
            printf("8 - Anular\n");
            printf("\n0 - Voltar\n");
            printf("Selecione uma opcao: ");
            scanf("%d", &opcao);
            printf("\n-------------------------------\n");
             if(opcao == 1)
            {
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

                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("%d - %s................", i, linha); //erro, mudar
                                    }
                                    if(k == 1)
                                    {
                                        printf("%s\n", linha);
                                    }
                                }
                                k++;
                            }

                        fclose(fileF);
                    }
                }
                    id = 1;
                    while(id!=0)
                    {
                        printf("0 - Voltar\n");
                        printf("Introduza a ementa a comprar: ");
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
                           printf("Introduza uma ementa valida!");
                       }

                   }
            }

            if (opcao  == 2) //////////////////////////////////////////////////////
            {
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

                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("%d - %s................", i, linha); //erro, mudar
                                    }
                                    if(k == 1)
                                    {
                                        printf("%s\n", linha);
                                    }
                                }
                                k++;
                            }
                        fclose(fileF);
                    }
                }
                    id = 1;
                    while(id!=0)
                    {
                        printf("0 - Voltar\n");
                        printf("Introduza a ementa a comprar: ");
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
                           printf("Introduza uma ementa valida!");
                       }
                    }
            }

            if (opcao  == 3) //////////////////////////////////////////////////////
            {
            contadorInteiroLanche();

                for(int i = 1; contador > i;i++)
                {
                    strcpy(caminho, "Files/Ementas/Lacnhe/");
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

                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("%d - %s................", i, linha); //erro, mudar
                                    }
                                    if(k == 1)
                                    {
                                        printf("%s\n", linha);
                                    }
                                }
                                k++;
                            }
                        fclose(fileF);
                    }
                }
                    id = 1;
                    while(id!=0)
                    {
                        printf("0 - Voltar\n");
                        printf("Introduza a ementa a comprar: ");
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
                           printf("Introduza uma ementa valida!");
                       }
                    }
            }

            if (opcao  == 4) //////////////////////////////////////////////////////
            {
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

                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("%d - %s................", i, linha); //erro, mudar
                                    }
                                    if(k == 1)
                                    {
                                        printf("%s\n", linha);
                                    }
                                }
                                k++;
                            }
                        fclose(fileF);
                    }
                }
                    id = 1;
                    while(id!=0)
                    {
                        printf("0 - Voltar\n");
                        printf("Introduza a ementa a comprar: ");
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
                           printf("Introduza uma ementa valida!");
                       }
                    }
            }

            if (opcao  == 5) //////////////////////////////////////////////////////
            {
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

                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("%d - %s................", i, linha); //erro, mudar
                                    }
                                    if(k == 1)
                                    {
                                        printf("%s\n", linha);
                                    }
                                }
                                k++;
                            }
                        fclose(fileF);
                    }
                }
                    id = 1;
                    while(id!=0)
                    {
                        printf("0 - Voltar\n");
                        printf("Introduza a ementa a comprar: ");
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
                           printf("Introduza uma ementa valida!");
                       }
                    }
            }

            if (opcao  == 6) //////////////////////////////////////////////////////
            {
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

                                if(result)
                                {
                                    if(k==0)
                                    {
                                        printf("%d - %s................", i, linha); //erro, mudar
                                    }
                                    if(k == 1)
                                    {
                                        printf("%s\n", linha);
                                    }
                                }
                                k++;
                            }
                        fclose(fileF);
                    }
                }
                    id = 1;
                    while(id!=0)
                    {
                        printf("0 - Voltar\n");
                        printf("Introduza a ementa a comprar: ");
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
                           printf("Introduza uma ementa valida!");
                       }
                    }
            }

            if(opcao == 7)
            {
                int aux = 0;
                printf("Deseja fatura?\n");
                printf("1 - Sim\n");
                printf("2 - Nao\n");
                printf("0 - Voltar");

                printf("Selecione uma opcao: ");
                scanf("%d", aux);

                if(aux == 1)
                {
                    printf("F A T U R A   S I M P L I F I C A D A\n");
                    printf("Funcionarios 04/06/21 Andre Leite - Tiago Rangel");
                    printf("Itens");
                    //Listar o pedido


                    printf("Total (com IVA)");
                    printf("Valor do IVA (23%)");
                    printf("Obrigado pela sua visita, volte sempre!");

                    scanf("");
                }
                else if(aux == 2)
                {
                    printf("Valor a pagar � de: ");
                    printf("Obrigado pela sua visita, volte sempre!");
                }
                else
                {
                    printf("Imprima um valor correspondente!");
                }
            }

            break;

        case 0:
            a=0;
            break;

        default:
            break;
        }

    }
}
