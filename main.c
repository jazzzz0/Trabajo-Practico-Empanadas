#include <stdio.h>
int sumaFila (int [5][12], int[], int, int);
int sumaColumna (int [5][12], int[], int, int);
int obtenerHornoMaxProduccion (int [3][12], int []);
int obtenerMesMaxProduccion (int [5][12], int []);
void obtenerMesMaxEmpanada (int [5][12]);
float obtenerPromProduccion (int [3][12]);
int mayorProdAgosto (int [3][12]);
int gustoMayorJunio (int [5][12]);
int main()
{
    int gustoMes [5][12] = {1,5,3,4,9,6,7,8,9,10,11,12,2,14,15,16,1,10,19,20,1,2,3,4,5,6,7,8,9,10,11,3,13,8,15,16,17,18,19,20,1,2,3,4,5,6,7,8,9,1,15,12,13,14,15,16,7,18,19,4};
    int hornoMes [3][12] = {1,2,3,4,5,6,7,8,9,10,9,4,1,2,3,4,5,6,7,9,9,10,5,12,1,2,3,4,5,6,7,8,9,10,10,2};
    int horno [3]= {1,2,3};
    int meses [12]= {1,2,3,4,5,6,7,8,9,10,11,12};
    int gusto [5]= {0,1,2,3,4};
    int i,j;
    int hornoMax = obtenerHornoMaxProduccion (hornoMes, horno);
    printf("\n1. El horno con mayor cantidad cocinada anual es HORNO_COCINA_%d", hornoMax);
    int mesMax = obtenerMesMaxProduccion (gustoMes, meses);
    printf("\n2. El mes de maxima produccion es el mes %d", mesMax);
    printf("\n3. Mes de máxima producción por tipo de empanada:");
    obtenerMesMaxEmpanada(gustoMes);
    float proMensual = obtenerPromProduccion(gustoMes);
    printf("\n4. El promedio mensual de produccion es %f", proMensual);
    int hornoAgosto = mayorProdAgosto (hornoMes);
    printf("\n5. El horno con mayor producción en agosto es HORNO_COCINA_%d", hornoAgosto);
    int gustoJunio = gustoMayorJunio (gustoMes);
    printf("\n6. El gusto de empanada mas producido en junio es el gusto %d", gustoJunio);
    return 0;
}

int sumaFila(int matriz [5][12], int maxVec [], int numFila, int numCol){
    int i,j;
    int vector [5] = {0};
    for(i = 0; i < numFila; i++){
        for (j = 0; j < numCol; j++){
            vector [i] =+ matriz[i][j];
        }   
    }
    int max = maxVec[0];
    int cantMax = vector [0];
    for (i = 1; i <numFila; i++){
        if (vector [i] > cantMax){
            cantMax = vector [i];
            max = maxVec [i];
        }
    }
    return max;
}

int sumaColumna(int matriz [5][12], int maxVec [], int numFila, int numCol){
    int i,j;
    int vector [12] = {0};
    for (i = 0; i < numCol; i++){
        for (j = 0; j < numFila; j++){
            vector [i] += matriz [j][i];
        }
    }
    int max = maxVec[0];
    int cantMax = vector [0];
    for (i = 1; i < numCol; i++){
        if (vector [i] > cantMax){
            cantMax = vector [i];
            max = maxVec [i];
        }
    }
    return max;
}

int obtenerHornoMaxProduccion (int x [3][12], int y []){
    int numFila = 3;
    int numCol = 12;
    int max = sumaFila (x,y,numFila,numCol);
    return max;
}

int obtenerMesMaxProduccion (int x [5][12], int y [12]){
    int numFila = 5;
    int numCol = 12;
    int max = sumaColumna (x,y,numFila,numCol);
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
    return maxAgosto;
}

int gustoMayorJunio(int x [5][12]){
    int maxJunio = 0,i;
    for (i = 0; i < 5; i++){
        if (x[i][5] > x [maxJunio][5])//no funciona todavia el de gustos, refinar.
            maxJunio = i;
    }
    return maxJunio;
}

