//---------------------------------------------

//this code was written by Mehce Faruk Unisen
//written in Jan 16th 4.00 am
//code written via vim terminal text editor
//this code wraps up hashtables in a simple way

//-------------------------------------------


#include <stdio.h>
#include <stdlib.h>

//defining the linked list for hash map
struct n{
    int key;
    int value;
    struct n* next;
};

typedef struct n hm;

hm* create_hm(int depth);
int val_hash(int value);
hm* insert_val(int value, hm* root);
void print_hm(hm* root);

int main(){
     hm* root = create_hm(20);
     

     hm* iter = insert_val(18, root);
     insert_val(118, root);
     insert_val(17, root);
     insert_val(117, root);

     print_hm(root);

     return 0; 

}


//creating hashmap as a linked list
//just to make thing easier to access
hm* create_hm(int depth){
    hm* root = (hm*)malloc(sizeof(hm));
    hm* iter = root;
    for(int i = 0; i < depth; i++){
        iter->key = i;
        iter->value = -1;
        iter->next = (hm*)malloc(sizeof(hm));
        iter = iter->next;    
    }   
    //this line of code makes things quite weird.
    //I found out that the NULL node is actually
    //not the 21st node It's actually the 22nd node
    iter = NULL;

    return root;
}

//simple hashing algorithm tbh LOL
int val_hash(int value){
    return value % 20;
}


hm* insert_val(int value, hm* root){
    hm* iter = root;
    int insertion_key = val_hash(value);
    
    //this line of code wraps up all the conditions that I want
    //it checks wether the key is same as the key we computed
    //if the desired table is full, simply moves to the other 
    //table thanks to iter->value != -1 line
    //and also it checks that if we hit the end, if It hits the
    //end it simply overrides the last map with the desired value 
    while((insertion_key != iter->key || iter->value != -1) && iter->next->next != NULL){
        iter = iter->next;
    }
    
    iter->value = value;
    return iter;
}

//simple stuff you know how it goes
void print_hm(hm* root){
    hm* iter = root;
    while(iter->next != NULL){
        printf("Key = %d, Value = %d\n", iter->key, iter->value);
        iter = iter->next;
    }
    
}
