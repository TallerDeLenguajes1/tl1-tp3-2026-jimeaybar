#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int cant=5, largo=100;
    char *nombres[cant];
    char nomb[largo];
    printf("Ingrese 5 nombres:\n ");

    for (int i = 0; i < cant; i++){
        printf("Nombre %d:\n ", i+1);
        fgets(nomb, largo, stdin);
        nomb[strcspn(nomb, "\n")];

        int longitud= strlen(nomb);
        nombres[i]= (char *)malloc(longitud * sizeof(char));
        
        strcpy(nombres[i],nomb);
    
    }

    MostrarPersonas(nombres, cant);

    for (int i=0; i<cant; i++){
        free(nombres[i]);
    }

    return 0;
}

void MostrarPersonas(char *vector[],int tam){
    printf("Nombres almacenados: \n");
    for(int i=0; i< tam; i++){
        printf("Persona %d: %s\n", i+1 , vector[i]);
    }
}