//---------------------------------------------------------------

//written by Mehce Faruk Unisen in 18th of December 2021
//coded in fedora linux terminal
//"vi" terminal text editor was used.
//gcc compiler used for the compilation process
//It's your own risk to run this program
//this program was written for learning binary search tree

//---------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct n{
	int data;
	struct n* left;
	struct n* right;
};

typedef struct n bst;


bst* add_child(bst* root, int prm_dt);
bst* trp_n_node(bst* root, int prm_dt);
bst* find_child(bst* root, int prm_dt);

int main(){

	printf("More detail information can be found in us_man.txt file\n");

	return 0;
}

bst* add_child(bst* root, int prm_dt){
	bst* tmp_root = root;

	root = trp_n_node(root, prm_dt);

	if(root->data >= prm_dt){
		root->left = (bst*)malloc(sizeof(bst));
		root->left->left = NULL;
		root->left->right = NULL;
		root->left->data = prm_dt;	
	}
	else{
		root->right = (bst*)malloc(sizeof(bst));
		root->right->left = NULL;
		root->right->right = NULL;
		root->right->data = prm_dt;
	}
	return tmp_root;
}

bst* trp_n_node(bst* root, int prm_dt){
	
	while(root->left || root->right){
		if((root->data >= prm_dt && !root->left) || (root->data < prm_dt && !root->right)){

			return root;
		}
		else if(root->data > prm_dt){
			root = root->left;
		}
		else if(root->data < prm_dt){
			root = root->right;
		}
	}

	return root;

}

bst* find_child(bst* root, int prm_dt){
	bool flag;
	bst* tmp_root = root;
	while(root->data != prm_dt || !root){
		flag = false;
		if(root->data < prm_dt && root->right != NULL){
			printf("right ");
			root = root->right;
			flag = true;
		}
		else if(root->data > prm_dt && root->left != NULL){
			printf("left ");
			root = root->left;
			flag = true;
		}
		if(!flag){
			break;
		}
		
	}
	if(root->data == prm_dt){
		return root;
	}
	else{
		return tmp_root;
	}
}
