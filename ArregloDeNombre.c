#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 100

void MostrarPersonas(char *nom[] , int cant);
int buscarNombrePorClave(char *nom[], int cant , char *frase);
void BuscarNombrePorId(char *nom[], int can , int numEntero);

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
    printf("\nPara buscar nombre por id ingrese el numero 1:\n");
    printf("Para buscar nombre por clave ingrese el numero 2:");
    scanf("%d", &numfuncion);
    if (numfuncion == 1)
    {   int id;

        printf("\ningrese un numero entero positivo:");
        scanf("%d", &id);
        BuscarNombrePorId(nombres, cantNombres , id);
    }else
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

void BuscarNombrePorId(char *nom[], int can , int numEntero){
    if (numEntero < can && numEntero >= 0)
    {
        for (int i = 0; i < can; i++)
        {
            if (i == numEntero)
            {
                printf("\nel nombre buscado por ID es :%s", nom[numEntero]);
            }
        
        }
    }else
    {
        printf("\nno se encontro nombre con el id ingresado");
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