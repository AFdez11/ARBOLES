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
    registro *izq2;
    registro *der2;
};

registro *aux, *aux2, *raiz;
registro *raizF, *auxF, *auxF2; /*hace referencia a los auxliares utilizados para posicionar la fecha*/ ;

int posicionarCodigo(){

    if (aux->codigo < aux2->codigo) {

        if (aux2->izq != NULL){
            aux2 = aux2->izq;
            posicionarCodigo();
        } else {
            aux2->izq = aux;
            aux = NULL;
        }
        
    } else if (aux->codigo > aux2->codigo){
        
            if(aux2->der != NULL){
            aux2 = aux2->der;
            posicionarCodigo();
        }   
        else {

            aux2->der = aux;
            aux = NULL;
        }
        
    }
    return 0;
}

int PosicionarFecha(){

    //año menor
    if (auxF->year < auxF2->year) {

        if (auxF2->der2 != NULL)
        {
            auxF2 = auxF2->der2;
            PosicionarFecha();

        } else {

            auxF2->der2 = auxF;
            auxF = NULL;
            free(auxF);
        }
        
        //mismo año, menor mes
    } else if ((auxF->year == auxF2->year) && (auxF->mes < auxF2->mes)){

        if (auxF2->der2!= NULL)
        {
            auxF2 = auxF2->der2;
            PosicionarFecha();

        } else {

            auxF2->der2 = auxF;
            auxF = NULL;
            free(auxF);
        }
        
        //mismo añor, mismo mes, día menor
    } else if((auxF->year == auxF2->year) && (auxF->mes == auxF2->mes) && (auxF->dia < auxF2->dia)){

        if (auxF2->der2 != NULL)
        {
            auxF2 = auxF2->der2;
            PosicionarFecha();

        } else {

            auxF2->der2 = auxF;
            auxF = NULL;
            free(auxF);
        }

        //año mayor
    } else if (auxF->year > auxF2->year){

        if (auxF2->izq2 != NULL)
        {
            auxF2 = auxF2->izq2;
            PosicionarFecha();

        } else {

            auxF2->izq2 = auxF;
            auxF = NULL;
            free(auxF);
        }

        //mismo año, mes mayor

    }   else if ((auxF->year == auxF2->year) && (auxF->mes > auxF2->mes)){

        if (auxF2->izq2 != NULL)
        {
            auxF2 = auxF2->izq2;
            PosicionarFecha();

        } else {

            auxF2->izq2 = auxF;
            auxF = NULL;
            free(auxF);
        }
        
        //mismo añor, mismo mes, día mayor
    } else if((auxF->year == auxF2->year) && (auxF->mes == auxF2->mes) && (auxF->dia > auxF2->dia)){

        if (auxF2->izq2 != NULL)
        {
            auxF2 = auxF2->izq2;
            PosicionarFecha();

        } else {

            auxF2->izq2 = auxF;
            auxF = NULL;
            free(auxF);
        }

        //mismo año, mismo mes, mismo día
    } else if ((auxF->year == auxF2->year) && (auxF->mes == auxF2->mes) && (auxF->dia == auxF2->dia)) {

        if (auxF2->izq2 != NULL)
        {
            auxF2 = auxF2->izq2;
            PosicionarFecha();

        } else {

            auxF2->izq2 = auxF;
            auxF = NULL;
            free(auxF);
        }

    }

    return 0;

}

int datos (){

    aux = new registro();
    auxF = new registro();

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


    aux->izq = aux->der=NULL;
    auxF->izq2 = auxF->der2 = NULL;
    auxF = aux;


    return 0;
}


int registrarCodigo(){

        datos();

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

                if (raiz == NULL){ 
                
                    raiz = aux;
                    aux = NULL;
                    free(aux);

                }else {
                    aux2 = raiz;
                    posicionarCodigo();
                }

            }

        } else  {

            cout<<endl;
            cout<<"Valor invalido."<<endl;
        }
        
        return 0;

}

int registrarFecha(){

        if (raizF == NULL){ 
        
            raizF = auxF;
            auxF = NULL;
            free(auxF);

        }else {
            auxF2 = raizF;
            PosicionarFecha();

        }

    return 0;
}


//Funciones Recorridos (Pre, Post, In)

int preorden(registro *recursive){

    cout<<endl;

    cout<<"Estudiante: "<<recursive->apellido<<" "<<recursive->nombre<<endl<<"Codigo: "<< recursive->codigo <<endl;

        if(recursive->izq != NULL){            
            preorden(recursive->izq);
        }

        if(recursive->der != NULL){
            preorden(recursive->der);
        }

    
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

    if (recursive->izq != NULL){
        indorden(recursive->izq);
    }

    cout<<endl;
    cout<<"Estudiante: "<<recursive->apellido<<" "<<recursive->nombre<<endl<<"Codigo: "<< recursive->codigo <<endl;

    if (recursive->der != NULL){
        indorden(recursive->der);
    }

    return 0;
}

int recoIn(){

    aux = raiz;

    if (aux != NULL){
        indorden(aux);
    }

    return 0;
}

int postorden(registro *recursive){

    if(recursive->izq != NULL){
        postorden(recursive->izq);
    }

    if(recursive->der != NULL){
        postorden(recursive->der);
    }

    cout<<endl;
    cout<<"Estudiante: "<<recursive->apellido<<" "<<recursive->nombre<<endl<<"Codigo: "<< recursive->codigo <<endl;
  
    return 0;

}

int recoPost(){
    aux = raiz;
    if (aux != NULL)
    {
        postorden(aux);
    }
    return 0;
}

//Eliminar y buscar

int buscar(){

  return 0;
}

int eliminar(){

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
        cout<<"           INSTITUTO COMERCIAL BOLIViANO 'OLAS DEL MAR'      "<<endl;
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

                registrarCodigo();
                registrarFecha();
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
                        cout<<"Muchas gracias por confiar en nosotros!"<<endl;
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