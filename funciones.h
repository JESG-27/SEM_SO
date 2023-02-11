bool existente(int id, list<int> &ids)
{
    for (auto it = ids.begin(); it != ids.end(); it++)
    {
        int id_actual = *it;
        if (id_actual == id)
        {
            return true;
        }
        else if (it == ids.end())
        {
            return false;
        }
    }
}

bool operacionValida (float operando_1, string operador, float operando_2)
{
    if (operador == "+" || operador == "-" || operador == "*" || operador == "/" || operador == "%")
    {
        if (operador == "/" || operador == "%")
        {
            if (operando_2 == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

Proceso capturarProceso (Lote &lote, list<int> &ids, int num_lote)
{
    srand(time(NULL));
    int id;
    string operacion;
    float operando_1;
    float operando_2;
    int tiempo;
    bool id_existe, operacion_valida;

    // ID
    do
    {
        id = rand()%50;
        cout << "ID: " << id << endl;
        id_existe = existente(id, ids);

        if (id_existe == true)
        {
            cout << "ID no valido" << endl;
        }
        else
        {
            ids.push_front(id);
        }

    } while (id_existe == true);

    // Operación
    do
    {
        cout << "Operacion" << endl;
        operando_1 = rand()%500;
        cout << "   Operando 1: "<< operando_1 << endl;

        cout << "   Operador: ";
        getline(cin, operacion);

        operando_2 = rand()%500;
        cout << "   Operando 2: " << operando_2 << endl;

        operacion_valida = operacionValida(operando_1, operacion, operando_2);

        if (operacion_valida == false)
        {
            cout << "Operacion no valida" << endl;
        }

    } while (operacion_valida == false);
    
    // Tiempo
    do
    {
        tiempo = rand()%(16);
        cout << "Tiempo: " << tiempo << endl;
        if (tiempo <= 0)
        {
            cout << "Tiempo no valido" << endl;
        }
    } while (tiempo <= 0);

    system("pause");
    Proceso p = Proceso (id, operando_1, operacion, operando_2, tiempo, num_lote);
    return p;
}

void ejecutar_proceso(Proceso &p)
{
    float operando_1, operando_2;
    string operador;

    operando_1 = p.getOperando_1();
    operando_2 = p.getOperando_2();
    operador = p.getOperacion();

    if (operador == "+")
    {
        p.setResultado(operando_1+operando_2);
    }
    else if (operador == "-")
    {
        p.setResultado(operando_1-operando_2);
    }
    else if (operador == "*")
    {
        p.setResultado(operando_1*operando_2);
    }
    else if (operador == "/")
    {
        p.setResultado(operando_1/operando_2);
    }
    else if (operador == "%")
    {
        int num_1 = (int)operando_1;
        int num_2 = (int)operando_2;
        int resultado = num_1%num_2;
        p.setResultado((float)resultado);
    }   
}