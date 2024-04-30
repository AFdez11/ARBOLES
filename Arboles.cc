#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;


struct registro{
    string nombre;
    string apellido;
    int codigo = 0;

    int dia = 0;
    int mes = 0;
    int year = 0;

    registro *izq;
    registro *der;
};

registro *aux, *aux2, *raiz, *aux3;

int posicionar(){

    if (aux->codigo < aux2->codigo) {

        if (aux2->izq != NULL){
            aux2 = aux2->izq;
            posicionar();
        } else {
            aux2 = aux2->izq;
        }
        
    } 
    else if (aux->codigo > aux2->codigo){
        
            if(aux2->der != NULL){
            aux2 = aux2->der;
            posicionar();
        }   
        else {

            aux2->der = aux;
        }
        
    }
    return 0;
}

int registrar(){
    aux = new registro;
    aux3 = new registro;

        cout << "Nombres del estudiante: ";
        getline(cin >> ws, aux->nombre);

        cout << "Apellidos del estudiante: ";
        getline(cin >> ws, aux->apellido);

        cout << "Codigo del estudiante: ";
        cin >> aux->codigo;

        cout<<endl;


        cout << "Ingrese el dia de nacimiento del estudiante (en orden numerico): " ;
        cin >> aux->dia;
        cout << "Ingrese el mes de nacimiento del estudiante (en orden numerico): ";
        cin >> aux->mes;
        cout << "Ingrese el a"<<char(164) <<"o de nacimiento del estudiante (en orden numerico): ";
        cin >> aux->year;


        if ((aux->dia <= 31 && aux->dia > 0) && (aux->mes <= 12 && aux->mes > 0) && (aux->year <= 2024 && aux->year >= 1900))
        {
            if (aux->mes == 02 && aux->dia > 29)
            {
            
                cout<<"Dia no valido."<<endl;

            } else {
                
                cout<<endl;
                cout<<"********************************"<<endl;
                cout<<"Estudiante registrado con exito."<<endl;
                cout<<"********************************"<<endl;

            }

        } else  {

            cout<<endl;
            cout<<"Valor invalido."<<endl;
        }
        

        aux->izq = NULL;
        aux->der = NULL;

        if (raiz == NULL){ 

            raiz = aux;
            aux = NULL;
            free(aux);

        }else {
            aux2 = raiz;
            posicionar();
        }
        return 0;

}

int preorden(registro *recursive){
    cout<<endl;
    cout<<"Estudiante: "<<aux->apellido<<" "<<aux->nombre<<endl<<"Codigo: "<< recursive->codigo <<endl;

    if(recursive->izq != NULL);
        preorden(recursive->izq);
    if(recursive->der != NULL);
        preorden(recursive->der);

    return 0;

}

int recoPre(){ //RecorrerPre

    aux = raiz;
    if (aux != NULL)
    {
        preorden(aux);
    }

    return 0;
}

int indorden(registro *recursive){

    cout<<endl;

    if(recursive->izq != NULL);
    indorden(recursive->izq);

    cout<<"Estudiante: "<<aux->apellido<<" "<<aux->nombre<<endl<<"Codigo: "<< recursive->codigo <<endl;

    if(recursive->der != NULL);
    indorden(recursive->der);

    return 0;
}

int recoIn(){

    if (aux != NULL)
    {
        indorden(aux);
    }
    
    
    return 0;
}

int recoPost(){

    return 0;
}

int buscar(){

  return 0;
}
    

int main(){

    int opcion = 0, opcion2 = 0;
    cout<<"";
    cout<<"Bienvenido, digite la opcion que desee realizar."<<endl;

    do
    {
        cout<<""<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"       INSTITUTO COMERCIAL BOLIVARIANO 'OLAS DEL MAR'        "<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"1.       AGREGAR DATOS DE ESTUDIANTE."<<endl;
        cout<<"2.       BUSCAR DATOS DE ESTUDIANTE."<<endl;
        cout<<"3.       ELIMINAR DATOS DE ESTUDIANTE."<<endl;
        cout<<"4.       RECORRER LISTADO. "<<endl;
        cout<<"5.       SALIR."<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        
        
        switch (opcion) {
            
            case 1:

                registrar();
                cout<<endl;
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:

                cout<<"1.   PRE - ORDEN."<<endl;
                cout<<"2.   IN - ORDEN."<<endl;
                cout<<"3.   POST - ORDEN."<<endl;
                cout<<"4.   SALIR."<<endl;
                cout<<"Opcion: ";
                cin>>opcion2;

                switch (opcion2) {
                    case 1:
                        recoPre(); break;

                    case 2:
                        recoIn(); break;

                    case 3:
                        recoPost(); break;

                    case 4:
                        cout<<"¡Muchas gracias por confiar en nosotros!"<<endl;
                        break;

                    default:
                        cout << "Opcion no valida." << endl;
                        break;
                }
                break;

            case 5:
                cout << "¡Muchas gracias por confiar en nosotros!" << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
                break;
        }

    } while (opcion != 5);
    
}