#include <stdio.h>

int main() {
    int opcion;
    float temperatura, resultado;

    printf("=== Conversor de Temperatura IoT ===\n");
    printf("1. Celsius a Fahrenheit\n");
    printf("2. Fahrenheit a Celsius\n");
    printf("3. Celsius a Kelvin\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    printf("Ingrese la temperatura: ");
    scanf("%f", &temperatura);

    switch(opcion) {
        case 1:
            resultado = (temperatura * 9 / 5) + 32;
            printf("Resultado: %.2f °F\n", resultado);
            break;

        case 2:
            resultado = (temperatura - 32) * 5 / 9;
            printf("Resultado: %.2f °C\n", resultado);
            break;

        case 3:
            resultado = temperatura + 273.15;
            printf("Resultado: %.2f K\n", resultado);
            break;

        default:
            printf("Opcion no valida.\n");
    }

    return 0;
}