//created by:
//Cabezas Pinillo Luis (Filantropo anónimo y Fotografo de google maps por desparche)
//Fernandez Fernando (Consejero de parejas y Batman en sus tiempos libres)

#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;


struct registro{
    char nombre[30];
    char apellido[30];
    int codigo;

    int dia;
    int mes;
    int year;

    registro *izq;
    registro *der;
};

registro *aux, *aux2, *raiz;
registro *raizF, *auxF, *auxF2; /*hace referencia a los auxliares utilizados para posicionar la fecha*/
registro *CodigoB, *padre; 

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

        if (auxF2->der!= NULL)
        {
            auxF2 = auxF2->der;
            PosicionarFecha();

        } else {

            auxF2->der = auxF;
            auxF = NULL;
            free(auxF);
        }
        
        //mismo año, menor mes
    } else if ((auxF->year == auxF2->year) && (auxF->mes < auxF2->mes)){

        if (auxF2->der!= NULL)
        {
            auxF2 = auxF2->der;
            PosicionarFecha();

        } else {

            auxF2->der = auxF;
            auxF = NULL;
            free(auxF);
        }
        
        //mismo añor, mismo mes, día menor
    } else if((auxF->year == auxF2->year) && (auxF->mes == auxF2->mes) && (auxF->dia < auxF2->dia)){

        if (auxF2->der != NULL)
        {
            auxF2 = auxF2->der;
            PosicionarFecha();

        } else {

            auxF2->der = auxF;
            auxF = NULL;
            free(auxF);
        }

        //año mayor
    } else if (auxF->year > auxF2->year){

        if (auxF2->izq != NULL)
        {
            auxF2 = auxF2->izq;
            PosicionarFecha();

        } else {

            auxF2->izq = auxF;
            auxF = NULL;
            free(auxF);
        }

        //mismo año, mes mayor

    }   else if ((auxF->year == auxF2->year) && (auxF->mes > auxF2->mes)){

        if (auxF2->izq != NULL)
        {
            auxF2 = auxF2->izq;
            PosicionarFecha();

        } else {

            auxF2->izq = auxF;
            auxF = NULL;
            free(auxF);
        }
        
        //mismo añor, mismo mes, día mayor
    } else if((auxF->year == auxF2->year) && (auxF->mes == auxF2->mes) && (auxF->dia > auxF2->dia)){

        if (auxF2->izq != NULL)
        {
            auxF2 = auxF2->izq;
            PosicionarFecha();

        } else {

            auxF2->izq = auxF;
            auxF = NULL;
            free(auxF);
        }

        //mismo año, mismo mes, mismo día
    } else if ((auxF->year == auxF2->year) && (auxF->mes == auxF2->mes) && (auxF->dia == auxF2->dia)) {

        if (auxF2->izq != NULL)
        {
            auxF2 = auxF2->izq;
            PosicionarFecha();

        } else {

            auxF2->izq = auxF;
            auxF = NULL;
            free(auxF);
        }

    }

    return 0;

}

int datos (){

    aux = ((struct registro *) malloc (sizeof(struct registro)));
    auxF = ((struct registro *) malloc (sizeof(struct registro)));

    cout << "Ingrese el primer nombre del estudiante: ";
    cin>>aux->nombre;

    cout << "Ingrese el primer apellido del estudiante: ";
    cin>>aux->apellido;

    cout << "Ingrese el codigo del estudiante: ";
    cin >> aux->codigo;

    cout<<endl;

    cout << "Ingrese el dia de nacimiento del estudiante (en orden numerico): " ;
    cin >> aux->dia;
    cout << "Ingrese el mes de nacimiento del estudiante (en orden numerico): ";
    cin >> aux->mes;
    cout << "Ingrese el a"<<char(164) <<"o de nacimiento del estudiante (en orden numerico): ";
    cin >> aux->year;


    aux->izq = aux->der=NULL;    
    auxF->izq = auxF->der= NULL;

    auxF->codigo = aux->codigo;
    strcpy(auxF->nombre, aux->nombre);
    strcpy(auxF->apellido, aux->apellido);
    auxF->year = aux->year;
    auxF->mes = aux->mes;
    auxF->dia = aux->dia;

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


//Eliminar y buscar

int buscar(int BuscarC, registro *rama){
    

    if (BuscarC == rama->codigo)
    {
        CodigoB = rama;
    } else {

        if (rama->izq != NULL)
        {
            buscar(BuscarC, rama->izq);
        }
        if (rama->der != NULL)
        {
            buscar(BuscarC, rama->der);
        }
        
        
    }
    

  return 0;
}

int buscarPadre(registro *rama){

    if ((rama->izq != NULL)&&(rama->izq != CodigoB))
    {
        buscarPadre(rama->izq);

    } else if (rama->izq == CodigoB){

        padre = rama;
    }


    if ((rama->der != NULL)&&(rama->der != CodigoB))
    {
        buscarPadre(rama->der);

    } else if (rama->der == CodigoB){
        
        padre = rama;
    }
    

    return 0;
}

int eliminarCaso1(registro *rama){

    if (CodigoB != rama)
    {
        buscarPadre(rama);

        if (padre->izq == CodigoB)
        {
            padre->izq = NULL;

        } else if (padre->der == CodigoB){

            padre->der = NULL;

        }

        free(CodigoB);
        
    }
    
    return 0;
}


int eliminarCaso2(registro *rama){

    if (CodigoB != rama)
    {
        buscarPadre(rama);

        if ((padre->izq == CodigoB) && (padre->izq != NULL))
        {
            padre->izq = CodigoB->izq;
        } else {

            padre->izq = CodigoB->der;

        }
        
    } else if (padre->der == CodigoB){
        
        if (CodigoB->izq != NULL)
        {
            padre->der = CodigoB->izq;

        } else {

            padre->der = CodigoB->der;
        }
        
        free(CodigoB);

    }

  return 0;
}

int eliminar (){

    int buscarC = 0; //lo utilizaremos para almacenar el código del estudiante a eliminar

    cout<<"Ingrese el codigo del estudiante a eliminar: ";
    cin>>buscarC;

    cout<<endl;

    buscar(buscarC, raiz);
    if ((CodigoB->der == NULL) && (CodigoB->izq == NULL))
    {
        eliminarCaso1(raiz);
        cout<<"Estudiante eliminado."<<endl;


    } else if ((CodigoB->der == NULL) && (CodigoB->der != NULL)  &&
              (CodigoB->izq == NULL)   && (CodigoB->izq != NULL)){

        eliminarCaso2(raiz);
        cout<<"Estudiante eliminado."<<endl;    

    } else if (buscarC == raiz->codigo){

        raiz = NULL;
    }
    

    buscar(buscarC, raizF);
    if ((CodigoB->der == NULL) && (CodigoB->izq == NULL))
    {
        eliminarCaso1(raizF);


    } else if ((CodigoB->der == NULL) && (CodigoB->der != NULL)  &&
              (CodigoB->izq == NULL)   && (CodigoB->izq != NULL)){

        eliminarCaso2(raizF); 

    } else if (buscarC == raizF->codigo){

        raizF = NULL;
    }

    

}

int main(){

    int opcion = 0, opcion2 = 0, code = 0;
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

                cout<<"Ingrese el codigo del estudiante a buscar: ";
                cin>>code;
                cout<<endl;

                buscar(code, raiz);
                if (code == CodigoB->codigo)
                {
                    cout<<"Estudiante: "<<CodigoB->apellido<<" "<<CodigoB->nombre<<endl;
                    cout<<"Fecha de nacimiento: "<<CodigoB->dia<<"/"<<CodigoB->mes<<"/"<<CodigoB->year<<endl;
                } else {

                    cout<<"Estudiante no encontrado. "<<endl;
                }
                

                break;

            case 3:
                eliminar();
                cout<<endl;
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
                        cout<<"****************************************"<<endl;
                        cout<<"Preorden (Codigo)."<<endl;
                        cout<<"****************************************"<<endl;
                        preorden(raiz);

                        cout<<endl;

                        cout<<"****************************************"<<endl;
                        cout<<"Preorden (Fecha)."<<endl;
                        cout<<"****************************************"<<endl;
                        preorden(raizF); break;

                    case 2:
                        cout<<"****************************************"<<endl;
                        cout<<"Inorden (Codigo)."<<endl;
                        cout<<"****************************************"<<endl;
                        indorden(raiz);

                        cout<<endl;

                        cout<<"****************************************"<<endl;
                        cout<<"Inorden (Fecha)."<<endl;
                        cout<<"****************************************"<<endl;
                        indorden(raizF); break;

                    case 3:
                        cout<<"*****************************************"<<endl;
                        cout<<"Postorden (Codigo)."<<endl;
                        cout<<"*****************************************"<<endl;
                        postorden(raiz);

                        cout<<endl;

                        cout<<"****************************************"<<endl;
                        cout<<"Postorden (Fecha)."<<endl;
                        cout<<"****************************************"<<endl;
                        postorden(raizF); break;

                    case 4:
                        cout<<"Muchas gracias por confiar en nosotros!"<<endl;
                        cout<<endl;
                        break;

                    default:
                        cout << "Opcion no valida." << endl;
                        cout<<endl;
                        break;
                }
                break;

            case 5:
                cout << "¡Muchas gracias por confiar en nosotros!" << endl;
                cout<<endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
                cout<<endl;
                break;
        }

    } while (opcion != 5);
    
}