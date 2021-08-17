#include <stdio.h>
#include <stdlib.h>

FILE *m = fopen("motoristas.txt","a"); // criando arquivo motoristas

FILE *c = fopen("carros.txt","a"); //criando arquivo carros
	
typedef struct Motorista{
	int driver_id; // id do motorista
	int idade; // idade do motorista
	int telefone; // telefone do motorista
	char nome[50]; // nome do motorista
}motorista; // estrutura do motorista

typedef struct Carro{
	int car_id; // id do carro
	char marca[50]; // marca do carro
	char modelo[50]; // modelo do carro
}carro; // estrutura do carro
	
motorista *vet = (motorista*) malloc(sizeof(motorista)); //vetor global de motoristas

void add_driver(){ // função para adicionarr motorista
   // criando vetor para cadastrar motoristas usando ele
  int i = 0, op = 1; 
  while(op != 0){ // criando uma repetição onde sempre que o usuário digite 1, seja possível está adicionando outro motorista
    printf("Digite um id para o motorista: ");
    scanf("%d",&(vet+i)->driver_id);
    
    printf("\nInsira a idade do motorista: ");
    scanf("%d",&(vet+i)->idade);
    
    printf("\nInsira o telefone do motorista: ");
    scanf("%d",&(vet+i)->telefone);
    
    printf("\nInsira o nome do motorista: ");
    scanf("%s",(vet+i)->nome);
    
    printf("\nDeseja adicionar mais um motorista?\n1-Sim\n0-Não\n");
    
    scanf("%d",&op);
    if(op != 0){ 
      i++;
      vet = (motorista*) realloc(vet, (i+1)*sizeof(motorista)); // adicionando mais uma posição ao vetor caso a resposto da usuário seja 1 
    }
    
  }
  
}

carro *vet_car = (carro*) malloc(sizeof(carro)); // vetor global de carros
	int i = 0;
void add_car(){ // função para adicionar carros
	int  op = 1;
	while(op != 0){  
		printf("Digite um id para o carro ");
		scanf("%d",&(vet_car+i)->car_id);
		
		printf("\nInsira a marca do carro: ");
		scanf("%s",(vet_car+i)->marca);
		
		printf("\nInsira o modelo do carro: ");
		scanf("%s",(vet_car+i)->modelo);
		
		printf("\nDeseja adicionar mais um carro?\n1-Sim\n0-Não\n");
		scanf("%d",&op);
		if(op != 0){
			i++;
			vet_car = (carro*) realloc(vet, (i+1)*sizeof(carro)); // asicionando mais uma posição ao vetor caso a resposta do usuário sejaa 1
		}
	
   }

}

void remove_driver(){ // função para remover motorisra
	int id;
	printf("Digite o id do motorista que você deseja remover: ");
	scanf("%d",&id);
	
	for(int j =0; j> i; j++){
	
	if(id == vet->driver_id){
		vet = (motorista*) realloc(vet, (-1)*sizeof(motorista)); // removendo a posição do vetor
	}else printf("Insira um id válido");
  }
	
}

void remove_car(){ // função para remover carro
	int id;
	printf("Digite o id do carro que você deseja remover: ");
	scanf("%d",&id);
	for(int j =0; j> i; j++){
	if(id == (vet_car+i)->car_id){
		vet = (motorista*) realloc(vet, (-1)*sizeof(motorista)); // removendo a posição do vetor
	}else printf("Insira um id válido");
}
}
int main(){
	
	int cadastrar;
	do{
	printf("Escolha uma opção:\n1-Cadastrar motorista\n2-Cadastrar carro\n3-Remover motorista\n4-Remover carro\n5-Sair\n");
	scanf("%d",&cadastrar);
	
	switch(cadastrar){
		case 1:
			add_driver();
			break;
			
		case 2:
			add_car();
			break;
			
		case 3:
			remove_driver();
			break;
			
		case 4:
			remove_car();
	}
 }while(cadastrar <= 4 && cadastrar !=0); // laço 
 
	free(vet); // liberando memória 
	free(vet_car);	// liberando memória
	return 0;
}
