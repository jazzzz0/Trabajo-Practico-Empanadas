#include <stdio.h>
void cargarCantidades (int [5][12], int [3][12]);
char buscarIdenti (int);
int obtenerHornoMaxProduccion (int [3][12]);
int obtenerMesMaxProduccion (int [5][12], int []);
void obtenerMesMaxEmpanada (int [5][12]);
float obtenerPromProduccion (int [3][12]);
int mayorProdAgosto (int [3][12]);
int gustoMayorJunio (int [5][12]);
void obtenerTop3Anual (int [5][12]);
int main()
{
    int gustoMes [5][12] = {0};
    int hornoMes [3][12] = {0};
    int meses [12]= {1,2,3,4,5,6,7,8,9,10,11,12};
    cargarCantidades(gustoMes,hornoMes);
    int hornoMax = obtenerHornoMaxProduccion (hornoMes);
    char identi1 = buscarIdenti(hornoMax);
    printf("1. El horno con mayor cantidad cocinada anual es HORNO_COCINA_%d_%c", hornoMax, identi1);
    int mesMax = obtenerMesMaxProduccion (gustoMes, meses);
    printf("\n2. El mes de maxima produccion es el mes %d", mesMax);
    printf("\n3. Mes de máxima producción por tipo de empanada:");
    obtenerMesMaxEmpanada(gustoMes);
    float proMensual = obtenerPromProduccion(gustoMes);
    printf("\n4. El promedio mensual de produccion es %f", proMensual);
    int hornoAgosto = mayorProdAgosto (hornoMes);
    char identi2 = buscarIdenti(hornoAgosto);
    printf("\n5. El horno con mayor producción en agosto es HORNO_COCINA_%d_%c", hornoAgosto, identi2);
    int gustoJunio = gustoMayorJunio (gustoMes);
    printf("\n6. El gusto de empanada mas producido en junio es el gusto %d", gustoJunio);
    printf("\n7. El top 3 de empanadas mayormente producidas en el año:");
    int i,j,gustoMasProducido [5] = {0};
    for (i = 0; i < 5; i++){
        for (j = 0; j < 12; j++){
            if (gustoMes[i][j] > gustoMasProducido[i])
                gustoMasProducido [i] = gustoMes [i][j];
        }
    }
    obtenerTop3Anual(gustoMes);
    return 0;
}

void cargarCantidades (int gustoMes[5][12], int hornoMes [3][12]){
    while(1){
        int mes,gusto,horno,cant;
        printf("Ingrese mes del año (1 a 12). Ingresar número fuera del rango para detener la carga:");
        scanf("%d", &mes);
        
        if(mes < 1 || mes > 12){
            break;
        }
        printf("Gusto de empanada (0 a 4):");
        scanf("%d", &gusto);
        printf("Horno donde se realizó la cocción (1 a 3):");
        scanf("%d", &horno);
        printf("Cantidad:");
        scanf("%d", &cant);
        
        gustoMes[gusto][mes-1]+= cant;
        hornoMes[horno-1][mes-1]+=cant;
    }
}

char buscarIdenti(int horno){
    char identi = 'X';
    if(horno !=1)
        if (horno == 2)
            identi = 'Y';
        else
            identi = 'Z';
    return identi;
}

int obtenerHornoMaxProduccion (int x [3][12]){
    int i,j,y [3]= {1,2,3};
    int vector [3] = {0};
    for (i = 0; i < 3; i++){
        for (j = 0; j < 12; j++){
            vector [i] += x[i][j];
        }
    }
    int max = y [0];
    int cantMax = vector [0];
    for (i = 0; i < 3; i++){
        if (vector [i] > cantMax){
            cantMax = vector [i];
            max = y [i];
        }
    }
    return max;
}

int obtenerMesMaxProduccion (int x [5][12], int y [12]){
    int i,j;
    int vector [12] = {0};
    for (i = 0; i < 12; i++){
        for (j = 0; j < 5; j++){
            vector [i] += x [j][i];
        }
    }
    int max = y [0];
    int cantMax = vector [0];
    for (i = 1; i < 12; i++){
        if (vector [i] > cantMax){
            cantMax = vector [i];
            max = y [i];
        }
    }
    return max;
}

void obtenerMesMaxEmpanada(int x[5][12]) {
    int i,j;
    for (int i = 0; i < 5; i++) {
        int maxCantidad = 0;
        int maxMesTipo = 0;
        for (int j = 0; j < 12; j++) {
            if (x[i][j] > maxCantidad) {
                maxCantidad = x[i][j];
                maxMesTipo = j;
            }
        }
        printf("\n   Tipo: %d, Mes: %d, Cantidad: %d", i , maxMesTipo + 1, maxCantidad);
    }
}

float obtenerPromProduccion(int x [5][12]){
    int total = 0,i,j;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 12; j++){
            total += x[i][j];
        }
    }
    return (float)total/12;
}

int mayorProdAgosto(int x [3][12]){
    int maxAgosto = 0,i;
    for (i = 0; i < 3; i++){
        if (x[i][7] > x[maxAgosto][7])
            maxAgosto = i;
    }
    maxAgosto+=1;
    return maxAgosto;
}

int gustoMayorJunio(int x [5][12]){
    int maxJunio = 0,i;
    for (i = 1; i < 5; i++){
        if (x[i][5] > x [maxJunio][5])
            maxJunio = i;
    }
    return maxJunio;
}

void obtenerTop3Anual (int matriz [5][12]){
    int totalPorGusto [5] = {0};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++){
            totalPorGusto[i]+= matriz[i][j];
        }
    }
    for (int k = 0; k < 3; k++){
        int maxGusto = -1;
        int maxCantidad = -1;
        for(int i = 0; i < 5; i++){
            if (totalPorGusto[i] > maxCantidad){
                maxCantidad = totalPorGusto [i];
                maxGusto = i;
            }
        }
        printf("\n   Tipo: %d, Cantidad: %d", maxGusto, maxCantidad);
        totalPorGusto [maxGusto] = -1;
    }
}