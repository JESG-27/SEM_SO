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

Proceso capturarProceso (Lote &lote, list<int> &ids)
{
    int id;
    string programador, operacion;
    float operando_1;
    float operando_2;
    int tiempo;
    bool id_existe, operacion_valida;

    // ID
    do
    {
        cout << "ID: ";
        cin >> id; cin.ignore();
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

    // Programador
    cout << "Programador: ";
    getline(cin, programador);

    // Operación
    do
    {
        cout << "Operacion" << endl;
        cout << "   Operando 1: ";
        cin >> operando_1; cin.ignore();

        cout << "   Operador: ";
        getline(cin, operacion);

        cout << "   Operando 2: ";
        cin >> operando_2; cin.ignore();

        operacion_valida = operacionValida(operando_1, operacion, operando_2);

        if (operacion_valida == false)
        {
            cout << "Operacion no valida" << endl;
        }

    } while (operacion_valida == false);
    
    // Tiempo
    do
    {
        cout << "Tiempo: ";
        cin >> tiempo; cin.ignore();
        if (tiempo <= 0)
        {
            cout << "Tiempo no valido" << endl;
        }
    } while (tiempo <= 0);

    Proceso p = Proceso (id, programador, operando_1, operacion, operando_2, tiempo);
    return p;
}