#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[10];
    char telefono[10];
    int edad;
} Contacto;

struct contacto{
    char nombre[10];
    char telefono[10];
    int edad;
};

void rellenaAgenda(Contacto *a);
void imprimeAgenda(Contacto *a);

int main(){
    struct contacto Manu = {"Manu","666454545",45};  //Sin Typedef
    printf("%s , %s (%d) \n",Manu.nombre,Manu.telefono,Manu.edad);

    Contacto Carlos = {"Carlos","789456123",46};
    printf("%s , %s (%d) \n",Carlos.nombre,Carlos.telefono,Carlos.edad);

    Contacto Agenda[3];
    rellenaAgenda(Agenda);
    imprimeAgenda(Agenda);


}
void rellenaAgenda(Contacto *a){
    for(int i=0;i<3;i++){
        fflush(stdin); //limpio buffer, concretamente el \n que ha dejado el leer el entero
        printf("Introduzca el nombre: ");
        gets(a[i].nombre);
        printf("Introduzca el telefono: ");
        gets(a[i].telefono);
        printf("Introduzca la edad: ");
        scanf("%d",&a[i].edad);
        
    }
}
void imprimeAgenda(Contacto *a){
     for(int i=0;i<3;i++){
          printf("%s , %s (%d) \n",a[i].nombre,a[i].telefono,a[i].edad);
     }
}


