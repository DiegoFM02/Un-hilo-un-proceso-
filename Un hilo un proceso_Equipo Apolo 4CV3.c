//EJERCICIO REALIZADO POR EL EQUIPO APOLO DEL 4CV3
//ESTE CÓDIGO REPRESENTA UN EJEMPLO DE UN HILO CON UN PROCESO
//SE REALIZA UN HILO QUE HAGA UNA SUMA DE DOS NÚMEROS
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Estructura para pasar argumentos al hilo
// En C, un hilo solo puede recibir un puntero como argumento, por eso, agrupamos los dos enteros en args
struct args {
    int a;
    int b;
};

// Función que ejecutará el hilo
void* sumar(void* arg) {
    struct args* datos = (struct args*) arg;					//Al puntero arg la pasamos de void* a struct para poder acceder a "a y b"
    int resultado = datos->a + datos->b;					//Se hace la operacion de suma
    printf("La suma de %d y %d es: %d\n", datos->a, datos->b, resultado);	
    return NULL;								//Regresamos NULL para indicar que hemos terminado.
}

int main() {
    pthread_t hilo;								//Declaramos la variable de tipo hilo
    struct args datos;								//Declaramos una variable tipo struct arg para poder darle valores a "a y b"
    datos.a = 5;								//Asignamos valores
    datos.b = 10;

    // Crear el hilo
    pthread_create(&hilo, NULL, sumar, &datos);					//Creamos el hilo, sus parametros son: (dirección del hilo, NULL pues los valores seran los predeterminados, la función de sumar, la direccion de los datos)

    // Esperar a que el hilo termine
    pthread_join(hilo, NULL);							//Funcion que sirve como bloqueador. El programa no avanza hasta que el hilo termina

    printf("El hilo de suma ha terminado\n");					//Imprimimos el mensaje del hilo

    return 0;
}
