int suma (int x, int y)
{
int result;

result = x + y;

return result;
}

int resta (int x, int y)
{
int result;

result = x - y;

return result;
}

float division (int x, int y)
{
float result;

result = (float)x / y;

return result;
}

int multiplicacion (int x, int y)
{
int result;

result = x * y;

return result;
}

int factorial (int x)
{
    int result;
    int acumuladorFactorial=1;
        // inicializo el acumulador de la multiplicación en 1 porque 1 es el número neutro en la multiplicación
    int i;

    if(x>=0){
        for(i=x;i>1;i--){
            acumuladorFactorial=acumuladorFactorial*i;
        }
        result=acumuladorFactorial;
    } else {
        result=-1;
        // el factorial de un negativo no existe y el factorial de un positivo nunca da negativo
        // por lo tanto puedo usar cualquier numero negativo para indicar error
    }

    return result;
}
