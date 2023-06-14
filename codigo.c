#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definição da estrutura de um nó da árvore
struct TreeNode {
    char ingredient[50];
    struct TreeNode* sibling;   // próximo irmão
    struct TreeNode* child;     // primeiro filho
};

// Função para criar um novo nó na árvore
struct TreeNode* createNode(char ingredient[]) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->ingredient, ingredient);
    newNode->sibling = NULL;
    newNode->child = NULL;
    return newNode;
}

// Função para adicionar um irmão a um nó
void addSibling(struct TreeNode* siblingNode, char ingredient[]) {
    while (siblingNode->sibling != NULL) {
        siblingNode = siblingNode->sibling;
    }
    siblingNode->sibling = createNode(ingredient);
}

// Função para adicionar um filho a um nó
void addChild(struct TreeNode* parentNode, char ingredient[]) {
    if (parentNode->child == NULL) {
        parentNode->child = createNode(ingredient);
    } else {
        addSibling(parentNode->child, ingredient);
    }
}

// Função auxiliar para exibir os ingredientes do sanduíche usando uma travessia em pré-ordem da árvore
void display(struct TreeNode* node, int level) {
    if (node == NULL) {
        return;
    }
    
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    
    printf("- %s\n", node->ingredient);
    
    display(node->child, level + 1);
    display(node->sibling, level);
}

// Função para exibir os ingredientes do sanduíche usando uma indentação para representar a árvore
void displayIngredients(struct TreeNode* node) {
    display(node, 0);
}

int main() {
    
    
	int opcao = 0;   
	int total = 0;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PAO  
    struct TreeNode* sandwich = createNode("Pão");
   
   do {
	    int scan = 0;
	        printf("\nSelecione seu pão:\n");
            printf("1. Pao de Ervas finas...R$3,00\n");
            printf("2. Pao Brioche..........R$1,00\n");
            printf("3. Pao Integral.........R$2,00\n");
            printf("4. Pao de 3 queijos.....R$3,00\n");
            printf("5. Pao sem glutem.......R$2,00\n");
            printf("\nDigite a opcao desejada: ");
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
            scan = scanf ("%d",&opcao);
            if (scan < 1 || scan > 5){
                opcao = 6;
                scan = 6;
            }
            int gc;
            do {
                gc = getchar();
                if (gc == EOF) exit(EXIT_FAILURE);
            } while (gc != '\n');
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        switch (opcao) {
            
            case 1://Pão de Ervas finas
                addChild(sandwich, "Pao de Ervas finas");
                total = total + 3;
                opcao = 7;
                break;  
            //-----------------------------------------------------
            
            case 2://Pão Brioche
                addChild(sandwich, "Pao Brioche");
                total = total + 1;
                opcao = 7;
                break;
            //-----------------------------------------------------
            
            case 3://Pão Integral
                addChild(sandwich, "Pao Integral");
                total = total + 2;
                opcao = 7;
                break;
            //-----------------------------------------------------
            
            case 4://Pão de 3 queijos
                addChild(sandwich, "Pao de 3 queijos");
                total = total + 3;
                opcao = 7;
                break;
            //-----------------------------------------------------
            
            case 5://Pão Amanteigado
                addChild(sandwich, "Pao sem glutem");
                total = total + 2;
                opcao = 7;
                break;
             
            //-----------------------------------------------------       
            case 6://Opção inválida
                printf("\n\nOpcao invalida. Favor inserir um numero de 1 a 5.\n");
            break;
            //-----------------------------------------------------
            default:
                printf("\n\nOpcao invalida. Favor inserir um numero de 1 a 5.\n");
                break;
        
        }   
	} while (opcao != 7);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CARNES
	struct TreeNode* meats = createNode("Carnes");
	int qtd;
    do {
	    int scan = 0;
	        printf("\nSelecione sua carne:\n");
            printf("1. Smash Burger.........R$4,00\n");
            printf("2. Picanha Burger.......R$7,00\n");
            printf("3. Costela Burger.......R$6,00\n");
            printf("4. Peito de Frango......R$5,00\n");
            printf("5. Lombo Suino..........R$5,00\n");
            printf("6. Vegano...............R$6,00\n");
            printf("\nDigite a opcao desejada: ");
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
            scan = scanf ("%d",&opcao);
            if (scan < 1 || scan > 5){
                opcao = 7;
                scan = 7;
            }
            int gc;
            do {
                gc = getchar();
                if (gc == EOF) exit(EXIT_FAILURE);
            } while (gc != '\n');
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        switch (opcao) {
            
            case 1://Smash Burger
               printf("\nQuantas unidades de carne voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd);
                    if (scan < 1 || scan > 3)
                        qtd = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd < 1 || qtd > 3) {
                        printf("Valor inválido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd < 1 || qtd > 3);
                if(qtd == 1){
                   addChild(meats, "Smash Burger"); 
                   total = total + 4;
                }
                if(qtd == 2){
                   addChild(meats, "Smash Burger"); 
                   addChild(meats, "Smash Burger");
                   total = total + 8;
                }
                if(qtd == 3){
                   addChild(meats, "Smash Burger"); 
                   addChild(meats, "Smash Burger"); 
                   addChild(meats, "Smash Burger"); 
                   total = total + 12;
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 2://Picanha Burger
                printf("\nQuantas unidades de carne voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd);
                    if (scan < 1 || scan > 3)
                        qtd = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd < 1 || qtd > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd < 1 || qtd > 3);
                if(qtd == 1){
                   addChild(meats, "Picanha Burger");
                   total = total + 7;
                }
                if(qtd == 2){
                   addChild(meats, "Picanha Burger"); 
                   addChild(meats, "Picanha Burger"); 
                   total = total + 14;
                }
                if(qtd == 3){
                   addChild(meats, "Picanha Burger"); 
                   addChild(meats, "Picanha Burger"); 
                   addChild(meats, "Picanha Burger");
                   total = total + 21;
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 3://Costela Burger
                printf("\nQuantas unidades de carne voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd);
                    if (scan < 1 || scan > 3)
                        qtd = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd < 1 || qtd > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd < 1 || qtd > 3);
                if(qtd == 1){
                   addChild(meats, "Costela Burger"); 
                   total = total + 6;
                }
                if(qtd == 2){
                   addChild(meats, "Costela Burger"); 
                   addChild(meats, "Costela Burger");
                   total = total + 12;
                }
                if(qtd == 3){
                   addChild(meats, "Costela Burger"); 
                   addChild(meats, "Costela Burger"); 
                   addChild(meats, "Costela Burger");
                   total = total + 18;
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 4://Peito de Frango
               printf("\nQuantas unidades de carne voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd);
                    if (scan < 1 || scan > 3)
                        qtd = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd < 1 || qtd > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd < 1 || qtd > 3);
                if(qtd == 1){
                   addChild(meats, "Peito de Frango");
                   total = total + 5;
                }
                if(qtd == 2){
                   addChild(meats, "Peito de Frango"); 
                   addChild(meats, "Peito de Frango");
                   total = total + 10;
                }
                if(qtd == 3){
                   addChild(meats, "Peito de Frango"); 
                   addChild(meats, "Peito de Frango"); 
                   addChild(meats, "Peito de Frango");
                   total = total + 15;
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 5://Lombo Suíno
                printf("\nQuantas unidades de carne voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd);
                    if (scan < 1 || scan > 3)
                        qtd = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd < 1 || qtd > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd < 1 || qtd > 3);
                if(qtd == 1){
                   addChild(meats, "Lombo Suino"); 
                   total = total + 5;
                }
                if(qtd == 2){
                   addChild(meats, "Lombo Suino"); 
                   addChild(meats, "Lombo Suíno"); 
                   total = total + 10;
                }
                if(qtd == 3){
                   addChild(meats, "Lombo Suino"); 
                   addChild(meats, "Lombo Suino"); 
                   addChild(meats, "Lombo Suino"); 
                   total = total + 15;
                }
                opcao = 4;
                break;  
             
            //-----------------------------------------------------       
            case  6://Vegano
                printf("\nQuantas unidades de carne voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd);
                    if (scan < 1 || scan > 3)
                        qtd = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd < 1 || qtd > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd < 1 || qtd > 3);
                if(qtd == 1){
                   addChild(meats, "Vegano");
                   total = total + 6;
                }
                if(qtd == 2){
                   addChild(meats, "Vegano"); 
                   addChild(meats, "Vegano"); 
                   total = total + 12;
                }
                if(qtd == 3){
                   addChild(meats, "Vegano"); 
                   addChild(meats, "Vegano"); 
                   addChild(meats, "Vegano"); 
                   total = total + 18;
                }
                opcao = 4;
                break; 
            break;
            //-----------------------------------------------------
            default:
                printf("\n\nOpcao invalida. Tente novamente.\n");
                break;
        
        }   
	} while (opcao != 4);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~QUEIJOS
	struct TreeNode* cheese = createNode("Queijos");
	int qtd2;
    do {
	    int scan = 0;
	        printf("\nSelecione seu queijo:\n");
            printf("1. Queijo Prato.........R$2,00\n");
            printf("2. Quijo Suíço..........R$2,00\n");
            printf("3. Queijo Mozzarella....R$2,00\n");
            printf("4. Queijo Sem Lactose...R$2,00\n");
            printf("\nDigite a opcao desejada: ");
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
            scan = scanf ("%d",&opcao);
            if (scan < 1 || scan > 4){
                opcao = 7;
                scan = 7;
            }
            int gc;
            do {
                gc = getchar();
                if (gc == EOF) exit(EXIT_FAILURE);
            } while (gc != '\n');
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        switch (opcao) {
            
            case 1://Queijo Prato
               printf("\nQuantas unidades de queijo voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd2);
                    if (scan < 1 || scan > 3)
                        qtd2 = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd2 < 1 || qtd2 > 3) {
                        printf("Valor inválido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd2 < 1 || qtd2 > 3);
                if(qtd2 == 1){
                   addChild(cheese, "Queijo Prato"); 
                }
                if(qtd2 == 2){
                   addChild(cheese, "Queijo Prato"); 
                   addChild(cheese, "Queijo Prato"); 
                }
                if(qtd2 == 3){
                   addChild(cheese, "Queijo Prato"); 
                   addChild(cheese, "Queijo Prato"); 
                   addChild(cheese, "Queijo Prato"); 
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 2://Quijo Suíço
                printf("\nQuantas unidades de queijo voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd2);
                    if (scan < 1 || scan > 3)
                        qtd2 = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd2 < 1 || qtd2 > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd2 < 1 || qtd2 > 3);
                if(qtd2 == 1){
                   addChild(cheese, "Quijo Suiço"); 
                }
                if(qtd2 == 2){
                   addChild(cheese, "Quijo Suiço");
                   addChild(cheese, "Quijo Suíço"); 
                }
                if(qtd2 == 3){
                   addChild(cheese, "Quijo Suiço");  
                   addChild(cheese, "Quijo Suiço");  
                   addChild(cheese, "Quijo Suiço"); 
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 3://Queijo Mozarella
                printf("\nQuantas unidades de queijo voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd2);
                    if (scan < 1 || scan > 3)
                        qtd2 = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd2 < 1 || qtd2 > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd2 < 1 || qtd2 > 3);
                if(qtd2 == 1){
                   addChild(cheese, "Queijo Mozzarella");  
                }
                if(qtd2 == 2){
                   addChild(cheese, "Queijo Mozzarella");  
                   addChild(cheese, "Queijo Mozzarella");  
                }
                if(qtd2 == 3){
                   addChild(cheese, "Queijo Mozzarella");  
                   addChild(cheese, "Queijo Mozzarella");  
                   addChild(cheese, "Queijo Mozzarella"); 
                }
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 4://Queijo Sem Lactose
                printf("\nQuantas unidades de queijo voce deseja?: ");
                do{
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
                    scan = scanf ("%d",&qtd2);
                    if (scan < 1 || scan > 3)
                        qtd2 = 4;
                    int gc;
                    do {
                     gc = getchar();
                        if (gc == EOF) exit(EXIT_FAILURE);
                    } while (gc != '\n');
                    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                    if(qtd2 < 1 || qtd2 > 3) {
                        printf("Valor invalido. Favor inserir um numero de 1 a 3: ");
                    }
                } while(qtd2 < 1 || qtd2 > 3);
                if(qtd2 == 1){
                   addChild(cheese, "Queijo Sem Lactose"); 
                }
                if(qtd2 == 2){
                   addChild(cheese, "Queijo Sem Lactose");  
                   addChild(cheese, "Queijo Sem Lactose"); 
                }
                if(qtd2 == 3){
                   addChild(cheese, "Queijo Sem Lactose"); 
                   addChild(cheese, "Queijo Sem Lactose"); 
                   addChild(cheese, "Queijo Sem Lactose"); 
                }
                opcao = 4;
                break;  
        }   
	} while (opcao != 4);
	if(qtd2 == 1){
	    total = total + 2;
	}
	if(qtd2 == 2){
	    total = total + 4;
	}
	if(qtd2 == 3){
	    total = total + 6;
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~EXTRAS
	struct TreeNode* extra = createNode("Extras");
    do {
	    int scan = 0;
	        printf("\nSelecione seu pacote de extras:\n");
            printf("1. Italiano.............R$6,00\n");
            printf("           -Tomate, Ketchup, Alface, Manjericao e Oregano.\n\n");
            printf("2. Mexicano.............R$7,00\n");
            printf("           -Queijo Nacho, Pimenta Jalapeno e Guacamole.\n\n");
            printf("3. Americano............R$8,00\n");
            printf("           -Onion rings, Molho Barbecue, Bacon e Alface.\n\n");
            printf("4. Frances..............R$6,00\n");
            printf("           -Ovo, Pure de Batata e Maionese da Casa\n\n");
            printf("5. Brasileiro...........R$8,00\n");
            printf("           -Ovo, Bacon, Batata palha, Tomate, Alface, Ketchup e Maionese da Casa\n\n");
            printf("6. Vegano...............R$6,00\n");
            printf("           -Tomate, Alface e Maionese da Casa\n\n");
            printf("\nDigite a opcao desejada: ");
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ função para impedir que usuario digite letra e trave o programa
            scan = scanf ("%d",&opcao);
            if (scan < 1 || scan > 5){
                opcao = 7;
                scan = 7;
            }
            int gc;
            do {
                gc = getchar();
                if (gc == EOF) exit(EXIT_FAILURE);
            } while (gc != '\n');
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        switch (opcao) {
            
            case 1://Italiano
                addChild(extra, "Tomate");
                addChild(extra, "Ketchup");
                addChild(extra, "Alface");
                addChild(extra, "Manjericao");
                addChild(extra, "Oregano");
                total = total + 6;
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 2://Mexicano
                addChild(extra, "Queijo Nacho");
                addChild(extra, "Pimenta Jalapeno");
                addChild(extra, "Guacamole");
                total = total + 7;
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 3://Americano
                addChild(extra, "Onion rings");
                addChild(extra, "Molho Barbecue");
                addChild(extra, "Bacon");
                addChild(extra, "Alface");
                total = total + 8;
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 4://Frances
                addChild(extra, "Ovo");
                addChild(extra, "Pure de Batata");
                addChild(extra, "Maionese da Casa");
                total = total + 6;
                opcao = 4;
                break;  
            //-----------------------------------------------------
            
            case 5://Brasileiro
                addChild(extra, "Ovo");
                addChild(extra, "Bacon");
                addChild(extra, "Batata palha");
                addChild(extra, "Tomate");
                addChild(extra, "Alface");
                addChild(extra, "Ketchup");
                addChild(extra, "Maionese da Casa");
                total = total + 8;
                opcao = 4;
            break;  
            //-----------------------------------------------------       
            case  6://Vegano
                addChild(extra, "Tomate");
                addChild(extra, "Alface");
                addChild(extra, "Maionese da Casa");
                total = total + 6;
                opcao = 4;
                break; 
            break;
            //-----------------------------------------------------
            default:
                printf("\n\nOpcao invalida. Tente novamente.\n");
                break;
        
        }   
	} while (opcao != 4);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n O sanduiche que você montou ficou assim:\n\n");
    // Exibir os ingredientes do sanduíche
    displayIngredients(sandwich);
    displayIngredients(meats);
    displayIngredients(cheese);
    displayIngredients(extra);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("TOTAL A PAGAR: R$:%d,00",total);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    
    return 0;
}
