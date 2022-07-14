#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define string_max 150
#define array_size 20
#define Type float

typedef char String[string_max];
typedef struct{
	String pc_id;
	String motherboard;
	String processor;
	String gpu;
	String ram;
	Type price;
}PC;

//BST and LL
typedef struct node{
	PC build;
	struct node *link;
	
	struct node *right;
	struct node *left;
}NodeList, *BST, *LL;

//Heap and AL
typedef struct{
	PC *heap_b;					//Dynamic Array
	int last_pc;
}AL, Heap;

/* Function will initialize everything */
void init_LL_AL(LL *L, AL *A){
	
}

/* Function will populate the LL and return it to the function */
LL populate_to_ll(){
	PC pc_info[10] = {{"A1008", "Gigabyte Z690 Aorus Pro", "Intel Core i5-12400", "Radeon RX 6950 XT", "G.Skill Trident Z5 RGB DDR5-6000 (2 x 16GB)", 72842.24},
					{"A1002", "ASRock Z690 Taichi", "AMD Ryzen 5 5600", "GeForce RTX 3090 Ti", "Samsung DDR5-4800 (2 x 16GB)", 179252.26},
					{"A1009", "MSI MAG B660M Mortar WIFI DDR4", "Intel Core i9-12900K", "Radeon RX 6900 XT", "TeamGroup T-Force Xtreem ARGB DDR4-3600 (2 x 8GB)", 172645.77},
					{"A1003", "MSI MAG B660 Tomahawk WIFI DDR4", "AMD Ryzen 9 5950X", "GeForce RTX 3090", "Patriot Viper Steel DDR4-4400 (2 x 8GB)", 99247.88},
					{"A1006", "Asus TUF Gaming Z590-Plus WIFI", "AMD Ryzen 7 5800X3D", "GeForce RTX 3080 12GB", "Patriot Viper RGB DDR4-3600 (2 x 8GB)", 88276.43},
					{"A1001", "Gigabyte Z590 Aorus Tachyon", "Intel Core i7-12700K", "Radeon RX 6800 XT", "Patriot Viper 4 DDR4-3400 (2 x 8GB)", 112398.99},
					{"A1005", "Asus ROG Crosshair VIII Dark Hero", "Intel Core i5-12600K", "GeForce RTX 3080 Ti", "Corsair Vengeance RGB Pro DDR4-3200 (4 x 8GB)", 128823.21},
					{"A1007", "MSI MPG X570 Gaming Pro Carbon WiFi", "Intel Core i3-12100", "GeForce RTX 3080", "Patriot Viper Steel DDR4-3200 (2 x 16GB)", 92410.11},
					{"A1004", "Gigabyte X570S Aorus Master", "AMD Ryzen 5 5600G", "Radeon RX 6800", "Patriot Viper Steel DDR4-3600 (2 x 32GB)", 89992.64},
					{"A1011", "Asus ROG Strix B550-E Gaming","AMD Ryzen 7 5800X3D", "GeForce RTX 3070 Ti", "G.Skill Trident Z Neo DDR4-3600 (2 x 16GB)", 99999.15}};
	LL head;
	int i;
	for(i = 0; i < 10; i++){
		//Insert pc_info to the head (LL)
	}
	return head;
}

/* Function will convert ll into AL and delete contents from LL */
void convert_ll_to_al(LL *L, AL *A){
	
}

/* Function will sort AL using BST Implementation and return BST */
// NOTE: Make a temp tree for sorting then Make a retTree for the actual tree (WORST CASE)
BST sort_bst(AL *A){
	
}

/* Function will return the index of the value if element is found, otherwise return -1 */
int binary_search(AL A, String ID){
	
}

/* Function will traverse the BST and add all the prices from its contents */
Type add_price(BST T){
	
}

/* Function will convert BST to Heap (Maxheap) and remove all contents from BST */
Heap convert_to_heap(BST *T){
	
}

//NOTE: UPON DISPLAYING, CHECK WHETHER IF THE FIELDS ARE EMPTY OR NOT

/* Display all contents (for Heap and AL)*/
void display_contents(PC game[], int size){
	printf("%-1s%15s%30s\n", "PC ID", "MOTHERBOARD", "PRICE");
	printf("======================================================\n");
	int i;
	for(i = 0; i < size; i++){
		printf("%-5s |", game[i].pc_id);
		printf("%-35s |", game[i].motherboard);
		printf("$%-35.2Lf\n", game[i].price);
	}
	system("pause"); system("cls");
}

/* Display all contents (for BST)*/
void inorder_bst(BST T){
	if(T != NULL){
		inorder_bst(T->left);
		printf("%-5s |", T->build.pc_id);
		printf("%-35s |", T->build.motherboard);
		printf("$%-35.2Lf\n", T->build.price);
		inorder_bst(T->right);
	}
}

/* Display all contents (for list)*/
void display_list(LL list){
	printf("[LINKED LIST]\n\n");
	printf("%-1s%15s%30s\n", "PC ID", "MOTHERBOARD", "PRICE");
	printf("======================================================\n");
	while(list != NULL){
		printf("%-5s |", list->build.pc_id);
		printf("%-35s |", list->build.motherboard);
		printf("$%-35.2Lf\n", list->build.price);
		list = list->link;
	}
	system("pause"); system("cls");
}

int main(){
	
	return 0;
}
