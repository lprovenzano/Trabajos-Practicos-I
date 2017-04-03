float calculo(int a, float b, float c)
{
    switch(a)
    {
    case 1:
        suma(b, c);
        break;
    case 2:
        resta(b, c);
        break;
    case 3:
        multiplica(b, c);
        break;
    case 4:
        divide(b, c);
        break;
    case 5:
        factorial(b);
        break;
    case 6:
        system("CLS");
        suma(b, c);
        resta(b, c);
        multiplica(b, c);
        divide(b, c);
        factorial(b);
        break;
    default:
        system("CLS");
        return menu();
    }
}

void menu()
{
        printf("\n \n MENU \n ------------------------ \n");
        printf("\n 1 - SUMA (A+B) \n 2 - RESTA (A-B) \n 3 - MULTIPLICACION (A*B) \n 4 - DIVISION (A/B) \n 5 - FACTORIAL (A!) \n 6 - TODAS LAS OPERACIONES \n\n 7 - SALIR");
        return menu;
}

float suma(float a, float b)
{
    float total;
    total = a+b;
    printf("\n ------------------------ \n %f + %f = %f \n \n", a, b, total);
    return total;
}

float resta(float a, float b)
{
    float total;
    total = a-b;
    printf("\n ------------------------ \n %f - %f = %f \n \n", a, b, total);
    return total;
}

float multiplica(float a, float b)
{
    float total;
    total = a*b;
    printf("\n ------------------------ \n %f * %f = %f \n \n", a, b, total);
    return total;
}

float divide(float a, float b)
{
    float total;
    if(b==0)
    {
        printf("\n ------------------------ \n ERROR! Operacion invalida \n \n");
        return 0;
    }
    total = a/b;
    printf("\n ------------------------ \n %f / %f = %f \n \n", a, b, total);
    return total;
}

float factorial(float a)
{
    float acumulador;
    int antecesores;
    acumulador = 0;
    for(antecesores=a;antecesores>0;antecesores--)
    {
        acumulador += antecesores;
    }
    printf("\n ------------------------ \n Factorial de %f: %f \n \n", a,acumulador);
    return acumulador;
}
