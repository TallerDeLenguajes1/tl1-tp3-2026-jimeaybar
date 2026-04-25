#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 100

void MostrarPersonas(char *nom[] , int cant);
int buscarNombrePorClave(char *nom[], int cant , char *frase);

int main(){
    int cantNombres = 5;
    char buff[TAMA];
    char *nombres[cantNombres];
    
    for (int i = 0; i < cantNombres; i++)
    {
        printf("ingrese el nombre numero %d: ", i + 1);
        gets(buff);
        nombres[i] = (char*)malloc(strlen(buff) + 1);
        strcpy(nombres[i] , buff);
        
        
    }
    
    MostrarPersonas(nombres , cantNombres);
    
    int numfuncion;

    printf("Para buscar nombre por clave ingrese el numero 2:");
    scanf("%d", &numfuncion);
    if (numfuncion == 1)
     {
        char clave[TAMA];
        printf("\ningrese un palabra clave:");
        scanf("%s", &clave);

        char encontrado = buscarNombrePorClave(nombres, cantNombres, clave);
        printf("\nnombre encontrado: %s", nombres[encontrado] );
    }
    

    return 0;
}

void MostrarPersonas(char *nom[] , int cant){

    printf("El nombre de las personas es :\n");
    for (int i = 0; i < cant; i++)
    {
        printf("%s\n",nom[i]);
    }   
}
int buscarNombrePorClave(char *nom[], int cant , char *frase){

    for (int i = 0; i < cant; i++)
    {
       if (strstr(nom[i], frase) != NULL)
       {
            return i;
       }else
       {
        return -1;
       }
       
       
    } 

}