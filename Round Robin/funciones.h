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
    srand(time(NULL));
    int id;
    string operacion,estado;
    float operando_1;
    float operando_2;
    int tiempo;
    bool id_existe, operacion_valida;

    // ID
    do
    {
        id = ids.size()+1;
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
        operando_1 = rand()%100;
        cout << "   Operando 1: "<< operando_1 << endl;

        int oper = rand()%5;
        if (oper == 0)
        {
            operacion = "+";
        }
        else if (oper == 1)
        {
            operacion = "-";
        }
        else if (oper == 2)
        {
            operacion = "/";
        }
        else if (oper == 3)
        {
            operacion = "*";
        }
        else if (oper == 4)
        {
            operacion = "%";
        }
        cout << "   Operador: " << operacion << endl;

        operando_2 = rand()%100;
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
        srand(time(NULL));
        tiempo = rand()%16;
        if (tiempo <= 11)
        {
            tiempo = tiempo+5;
        }
        cout << "Tiempo: " << tiempo << endl;
        if (tiempo <= 0)
        {
            cout << "Tiempo no valido" << endl;
        }
    } while (tiempo <= 0);

    Sleep(1000);

    Proceso p = Proceso (id, operando_1, operacion, operando_2, tiempo, "nuevo");
    return p;
}

void ejecutar_proceso(Proceso &p, int cont)
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

    p.setTiempoFinalizacion(cont);
}

void tiempoBloqueo (Lote &bloqueados, Lote &listos, int tiempo, int quantum)
{
    Proceso proceso_actual = bloqueados.front();
    int inicial = proceso_actual.getId();

    do
    {
        if (proceso_actual.getTiempoBlo() != 0)
        {
            proceso_actual.setTiempoBlo(proceso_actual.getTiempoBlo()-1);
        }
        
        bloqueados.agregarProceso(proceso_actual);
        bloqueados.pop_front();
        proceso_actual = bloqueados.front();
    }
    while(inicial != proceso_actual.getId());

    if (proceso_actual.getTiempoBlo() == 0)
    {
        bloqueados.pop_front();
        listos.agregarProcesoListos(proceso_actual, tiempo, quantum);
    }
}

void BCP(Lote &nuevos, Lote &listos, Lote &ejecucion, Lote &bloqueados, list<Proceso> &terminados, int cont)
{
    system("cls");
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Bloque de Control de Procesos" << endl << endl;

    cout << "Nuevos" << endl;
    if (nuevos.size() > 0)
    {
        nuevos.BCP_nuevos();
    }

    cout << endl << "Listos" << endl;
    if (listos.size() > 0)
    {
        listos.BCP_listos_ejecucion_bloqueados(cont);
    }

    cout << endl << "Ejecucion" << endl;
    if (ejecucion.size() > 0)
    {
        ejecucion.BCP_listos_ejecucion_bloqueados(cont);
    }

    cout << endl << "Bloqueados" << endl;
    if (bloqueados.size() > 0)
    {
        bloqueados.BCP_listos_ejecucion_bloqueados(cont);
    }

    cout << endl << "Terminados" << endl;
    for (auto it = terminados.begin(); it != terminados.end(); it++)
    {
        Proceso pro = *it;
        cout << "   ID: " << pro.getId() << endl;
        cout << "       Operacion: " << pro.getOperando_1() << pro.getOperacion() << pro.getOperando_2();
        
        if (pro.getEstado() == "error")
        {
            cout << "   Resultado: error" << endl;
        }

        else
        {
            cout << "   Resultado: " << pro.getResultado() << endl;
        }
        cout << "       Tiempo estimado: " << pro.getTiempo() << endl;
        cout << "       Tiempo llegada: " << pro.getTiempoLLegada() << endl;
        cout << "       Tiempo finalizacion: " << pro.getTiempoFinalizacion() << endl;
        cout << "       Tiempo retorno: " << pro.getTiempoFinalizacion()-pro.getTiempoLLegada() << endl;
        cout << "       Tiempo respuesta: " << pro.getTiempoRespuesta()-pro.getTiempoLLegada() << endl;
        cout << "       Tiempo espera: " << (pro.getTiempoFinalizacion()-pro.getTiempoLLegada())-(pro.getTiempo()-pro.getTiempoRes()) << endl;
        cout << "       Tiempo servicio: " << pro.getTiempo()-pro.getTiempoRes() << endl << endl;
    }
}