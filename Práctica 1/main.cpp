#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//La paridad de un número n mediante restas.
bool numPar(int n){
    if(n==0){
        return true;
    }else if(n==1){
        return false;
    }else{
        return numPar(n-2);
    }
};


//La paridad de un número utilizando recursión indirecta
// . La función esPar llama a la función esImpar y viceversa.
bool es_Par(int n);
bool es_Impar(int n){
    if(n==0){
        return false;
    }else{
        return es_Par(n-1);
    }
}
bool es_Par(int n){
    if(n==0){
        return true;
    }else{
        return es_Impar(n-1);
    }
};


//El producto de dos números positivos n y m realizando sumas.
int producto (int n , int m){
    if(m==0){
        return 0;
    }else{
        return n+producto(n,m-1);
    }
}



//La potencia de dos números calculada con productos
int potencia1(int x,int m){
    if(m==0){
        return 1;
    }else{
        return x*potencia1(x,m-1);
    }
}



//La función potencia2 definida con dos relaciones de recurrencia,
//  una para valores pares y otra para impares
int potencia2(int x,int n){
    if(n==0){
        return 1;
    }else {
        int p=potencia2(x,n/2);

        if(n%2==0){
            return p*p;
            // return (potencia2(x,n/2)*potencia2(x,n/2));
        }else{
            return x*p*p;
            //return x * potencia2(x,n/2)*potencia2(x,n/2);
        }
    }
}


//La función factorial de un número n mayor o igual que cero.
int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}


//La sucesión de Fibonacci.
int fibonacci(int x){
    if(x==0){
        return 0;
    }else if(x==1){
        return 1;
    }else{
        return fibonacci(x-2)+fibonacci(x-1);
    }
}



//El cociente y el resto de la división de dos números enteros.
int cociente(int dividendo, int divisor){
    if(dividendo<divisor){
        return 0;
    }else{
        return 1+cociente(dividendo-divisor,divisor);
    }
}
int resto(int dividendo,int divisor){
    if(dividendo<divisor){
        return dividendo;
    }else{
        return resto(dividendo-divisor,divisor);
    }
}



//La función múltiplo determina si un número entero es divisible por otro
bool multiplo(int dividendo , int divisor){
    if(dividendo==divisor){
        return true;
    }else if(dividendo<divisor){
        return false;
    }else{return multiplo(dividendo-divisor,divisor);
    }
}



//La sumatoria de todos los números desde 1 hasta n,
//  la sumatoria de los números pares
// y de los números impares desde 1 hasta n.
int sumatoria1(int n){
    if(n==1){
        return 1;
    }else{
        return n+sumatoria1(n-1);
    }
}
int sumatoriaPar1(int n){
    if(n==0){
        return 0;
    }else if(n%2==0){
        return n+sumatoriaPar1(n-2);
    }else{
        return sumatoriaPar1(n-1);
    }
};
int sumatoriaImpar1(int n){
    if(n==1){
        return 1;
    }else if(n%2==0){
        return sumatoriaImpar1(n-1);
    }else{
        return n+sumatoriaImpar1(n-2);
    }
}




//El máximo común divisor calculado con el método de Euclides.
int MCD(int a , int b ){
    if(b==0){
        return a;
    }
    return MCD(b,a%b);
}




//La evaluación de una función de grado n en un punto
double eval(int coeficientes[], int n, int valor){
    if(n==1){
        return coeficientes[n-1];
    }else{
        return (coeficientes[n-1]*pow(valor,n-1))+eval(coeficientes,n-1,valor);
    }
}


//Funciones recursivas aplicadas a un array de números enteros.
int minimo(int v[], int n){

    if(n==0){
        return v[0];
    }else{
        int p=minimo(v,n-1);
        if(v[n-1]>p){
            return p;
        }else{
            return v[n-1];
        }
    }
}
int maximo(int v[], int n){

    if(n==0){
        return v[0];
    }else{
        int p=maximo(v,n-1);
        if(v[n-1]<p){
            return p;
        }else{
            return v[n-1];
        }
    }
}
int sumatoria2(int v[], int n){
    if(n==1){
        return v[n-1];
    }else{
        return v[n-1]+sumatoria2(v,n-1);
    }
}
int sumatoriaPar2(int v[], int n){
    if(n==1){
        return v[n-1];
    }else if((n-1)%2==0){
        return v[n-1]+sumatoriaPar2(v,n-2);
    }else{
        return  sumatoriaPar2(v,n-1);
    }
}
int sumatoriaImpar2(int v[], int n){
    if(n==2){
        return v[n-1];
    }else if((n-1)%2==0){
        return sumatoriaImpar2(v,n-1);
    }else{
        return v[n-1]+sumatoriaImpar2(v,n-2);
    }
}
double promedio(int v[], int n, double total){
    if(n==1){
        total=total+v[n-1];
        return total/5;
    }else{
        total=total+v[n-1];
        return promedio(v,n-1,total);
    }
}
bool existe(int v[], int n, int valor){
    if(n==1){
        if(v[n-1]==valor){
            return true;
        }else{
            return false;
        }
    }else if(v[n-1]==valor){
        return true;
    }else{
        return existe(v,n-1,valor);
    }
}
void invierte(int v[], int p, int n){
    if(p<n){
        int w=v[p-1];
        int e=v[n-1];
        v[n-1]=w;
        v[p-1]=e;
        invierte(v,p+1,n-1);
    }else{
        for(int i=0;i<5;i++){
            cout<<v[i]<<" ";
        }
    }

}
//hanoi
void hanoi(int n, int origen, int auxiliar, int destino){
    if(n==1){
        cout<<"\t mueve el bloque "<<n<<" desde "<<origen<<" hasta "<<destino<<"\n";
    }else{
        hanoi(n-1,origen,destino,auxiliar);
        cout<<"\t mueve el bloque "<<n<<" desde "<<origen<<" hasta "<<destino<<"\n";
        hanoi(n-1,auxiliar,origen,destino);
    }
}
////--------------------------------------------ITERATIVO--------------------------------------------------------
bool numPar2(int n){
    while (n!=1 && n!=0){
        n=n-2;
    }
    if(n==1){
        return false;
    }else{
        return true;
    }
}

//El cociente y el resto de la división de dos números enteros.
int cociente2(int dividendo, int divisor){
    int contador=0;
    while(dividendo>=divisor){
        contador++;
        dividendo=dividendo-divisor;
    }
    return contador;
}
int resto2(int dividendo, int divisor){
    if(dividendo<divisor){
        return dividendo;
    }else{
        while(dividendo>=divisor){
            dividendo=dividendo-divisor;
        }
    }
    return dividendo;
}
//La función múltiplo determina si un número entero es divisible por otro.
bool multiplo2(int dividendo, int divisor){
    if(dividendo==divisor){
        return true;
    }else{
        int c=0;
        while(dividendo>=divisor){
            if (dividendo==divisor){
                c=1;
            }
            dividendo=dividendo-divisor;
        }
        if(c==1){return true;}else{return false;
        }
    }
}


//La sucesión de Fibonacci.
int fibonacci2(int n){
    std::vector <int> vec{0,1};

    for(int poss=1;poss<=n;poss++){
        int operacion=vec[poss]+vec[poss-1];
        vec.push_back(operacion);
    }
    return vec[n];
}
//La representación binaria de un número entero decimal sin signo.
void imprimeBinario(unsigned short n){
    std::vector <int> binario;
    while(n!=0){
        binario.push_back(n%2);
        n=n/2;
    }
    for(int i=binario.size()-1;i>=0;i--){
        cout<<binario[i]<<"-";
    }
}
//El producto de dos números positivos n y m realizando sumas.
int producto2(int n, int m){
    int s=0;
    for(auto i=0;i<n;i++){
        s=s+m;
    }
    return s;}


int potencia3(int x, int n){
    int s=1;
    for(auto i=0;i<n;i++){
        s=s*x;
    }
    return s;}
//La evaluación de una función de grado n en un punto x.
double eval2(int coeficientes[], int n, int x){
    double r=0.0;
    for(int i=0;i<n;i++){
        r=r+coeficientes[i]*pow(x,i);
    }
    return r;}

//Las funciones esIdentidad, esSimetrica.......
//int matriz2_[3][3]{ {1,2,3},{2,1,4},{3,4,1}}; //la matriz que le voy a pasar

bool esIdentidad(int m[][], int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                continue;
            }else if(m[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}
bool esSimetrica(int m[][], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[j][i]!=m[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool transpuesta(int m[][], int t[][], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(t[j][i]!=m[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool esIgual(int m1[][], int m2[][], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(m1[i][j]!=m2[i][j]){
                return false;
            }
        }
    }
    return true;
}

//La función esPerfecto
bool esPerfecto(int n){
    int s=1;//por que el q es divisor siempre;
    for(auto i=2;i<n;i++){
        if(n%i==0){
            s=s+i;
        }
    }
    if(n==s){
        return true;
    }else{
        return false;
    }
}
int main()
{
    //La paridad de un número n mediante restas.
    if(numPar(8)==true){
        cout<<"\n8 ES PAR";
    }else if(numPar(8)==false){
        cout<<"\n8 ES IMPAR";
    }


    //La paridad de un número utilizando recursión indirecta.
    //La función esPar llama a la función esImpar y viceversa.

    if(es_Par(8)==true){
        cout<<"\n\n8 ES PAR";
    }else if(es_Par(8)==false){
        cout<<"\n\n8 ES IMPAR";
    }


    //El producto de dos números positivos n y m realizando sumas.
    cout<<"\n\nPRODUCTO DE 5X3 POR SUMAS: "<<producto(5,3);


    //La potencia de dos números calculada con productos
    std::cout<<"\n\nPOTENCIA DE 2 ELEVADO A 4 POR PRODUCTOS: "<<potencia1(2,4);


    //La función potencia2 definida con dos relaciones de recurrencia
    // , una para valores pares y otra para impares
    std::cout<<"\n\n2 ELEVADO A 4: "<<potencia2(2,4);


    //La función factorial de un número n mayor o igual que cero.
    cout<<"\n\nFACTORIAL DE 3: "<<factorial(3);


    //La sucesión de Fibonacci.
    cout<<"\n\nFIBONACCI (4): "<<fibonacci(4);


    //El cociente y el resto de la división de dos números enteros.
    cout<<"\n\nCOCIENTE ENTRE 15 Y 3: "<<cociente(15,3)<<" RESTO: "<<resto(15,3);


    //La función múltiplo determina si un número entero es divisible por otro.
    if(multiplo(15,5)==true){
        cout<<"\n\n15 ES MULTIPLO de 5";
    }else if(multiplo(15,5)==false){
        cout<<"\n\n15 No ES MULTIPLO DE 5";
    };


    //La sumatoria de todos los números desde 1 hasta n
    // la sumatoria de los números pares
    // y de los números impares desde 1 hasta n.
    cout<<"\n\nSUMATORIA(5-1): "<<sumatoria1(5)<<
          "\nSUMATORIA PAR(7-1): "<<sumatoriaPar1(7)
       <<" \nSUMATORIA IMPAR(5-1): "<<sumatoriaImpar1(5);


    //El máximo común divisor calculado con el método de Euclides.
    cout<<"\n\nMCD ENTRE 20,5: "<<MCD(5,20);
    //La evaluación de una función de grado n en un punto
    int Matriz[5]{10,4,-3,-5,2};
    cout<<"\n\n  f(x)=2x^(4)-5x^(3)-3x^(2)+4x+10\tf(2): "<<eval(Matriz,5,2);
    //Funciones recursivas aplicadas a un array de números enteros.
    cout<<"\n\nEL MINIMO DE LA MATRIZ {10 4 -3 -5 2} ES: "<<minimo(Matriz,5);
    cout<<"\n\nEL MAXIMO DE LA MATRIZ {10 4 -3 -5 2} ES: "<<maximo(Matriz,5);
    cout<<"\n\nEL SUMATORIA DE LA MATRIZ {10 4 -3 -5 2} ES: "<<sumatoria2(Matriz,5);
    cout<<"\n\nEL SUMATORIA_PAR DE LA MATRIZ {10 4 -3 -5 2} ES: "<<sumatoriaPar2(Matriz,5);
    cout<<"\n\nEL SUMATORIA_IMPAR DE LA MATRIZ {10 4 -3 -5 2} ES: "<<sumatoriaImpar2(Matriz,5);
    cout<<"\n\nEL PROMEDIO {10 4 -3 -5 2} ES: "<<promedio(Matriz,5,0);
    if(existe(Matriz,5,-3)==true){
        cout<<"\n\nEL NUMERO -3 EXISTE EN LA MATRIZ {10 4 -3 -5 2}";
    }else{
        cout<<"\n\nEL NUMERO -3 NO EXISTE EN LA MATRIZ {10 4 -3 -5 2}";
    }
    cout<<"\n\nLA INVERSA DE LA MATRIZ {10 4 -3 -5 2} ES: ";invierte(Matriz,1,5);
    std::cout<<"\n\nHanoi: ";hanoi(3,1,2,3);
    //------------------------------------ITERATIVO------------------------------------------
    //La paridad de un número n mediante restas.
    cout<<"\n\n\t\t-----ITERATIVOS------";
    if(numPar2(12)==true){
        cout<<"\n\n 12 ES PAR (Iterativo)";
    }else{
        cout<<"\n\n 12 NO ES PAR (Iterativo) ";
    }


    //El cociente y el resto de la división de dos números enteros.
    cout<<"\n\nEL COCIENTE DE 12/2(Iterativo)= "<<cociente2(12,2);
    cout<<"\nEL RESTO DE 13/2(Iterativo)= "<<resto2(13,2);
    if(multiplo2(15,5)==true){
        cout<<"\n\n15 ES MULTIPLO de 5";
    }else{cout<<"\n\n15 NO ES MULTIPLO DE 5";
    };
    //fibonaccie
    cout<<"\n\nFibonacci en 4= "<<fibonacci2(4);
    //La representación binaria de un número entero decimal sin signo.
    cout<<"\n\nBINARIO DE 8= "; imprimeBinario(8);
    //El producto de dos números positivos n y m realizando sumas.
    cout<<"\n\nEl PRODUCTO DE 4X4= "<<producto2(4,4);
    //La potencia de x elevado a n con productos.
    cout<<"\n\nEl RESULTADO DE 2^(4)= "<<potencia3(2,5);
    cout<<"\n\n(Iterativo) f(x)=2x^(4)-5x^(3)-3x^(2)+4x+10\tf(2): "<<eval2(Matriz,5,2);


    if(esPerfecto(7)==true){
        cout<<"\n\n 7 ES PERFECTO";
    }else{cout<<"\n\n7 NO ES PERFECTO\n";
    }


}
