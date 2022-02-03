#include <stdio.h>

int hayPalabrotas(char m[256]);
char* filtraPalabrotas(char m[256]);

int main(){
    char mensaje[256]=" Papá, quiero caca y pipi, he dicho caca ";
    printf(" \n Hay %d tacos \n",hayPalabrotas(mensaje));
}

int hayPalabrotas(char m[256]){
    char tacos[2][25]={
        "caca",
        "pipi"
    };
    int nTacos=0;

    int i=0;
    while(i<256&&m[i]!='\0'){
        //Buscando en el array de palabrotas la primera letra
        for(int j=0;j<2;j++){
            if(m[i]==tacos[j][0] && (i==0 || m[i-1]==' ')){
                int tmp=i; //guardo la posición actual de la cadena por si hay que rebobinar
                int k=0;
                for(k=1;k<25&&tacos[j][k]!='\0';k++){
                    if(m[++i]!=tacos[j][k]){
                        k=25;  //si no coincide en alguna letra rompo el bucle
                    }
                }
                if(tacos[j][k]=='\0' && (m[i+1]==' ' || m[i+1]==',' || 
                                        m[i+1]=='.' || m[i+1]=='\0')){
                    //si me he salido del bucle llegando al final de un
                    //taco y la siguiente letra del mensaje es espacio o final
                    // es un taco
                    nTacos++;
                }else{
                    //si no es que todo ha fallado, rebobino para seguir por donde iba
                    i=tmp;
                }
            }
        }
        i++;
    
    
    }
    return nTacos;

}

char* filtraPalabrotas(char m[256]){
    char tacos[2][25]={
        "caca",
        "pipi"
    };
    return NULL;
}