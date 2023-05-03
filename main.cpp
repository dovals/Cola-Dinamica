#include <iostream>

template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(nullptr){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->data;
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

class Alumno{
private:
    std::string Nombre;
    std::string Nombre_Carrera;
    std::string Materias_Aprob;
    std::string Promedio;
public:
    Alumno(){};


    friend std::ostream & operator<<(std::ostream &O, Alumno &x){
            O<<"\n Nombre: "<<x.Nombre<<" Nombre Carrera: " <<x.Nombre_Carrera<<" Numero de Materias Aprobadas: "<<x.Materias_Aprob<<" Promedio: "<<x.Promedio<<std::endl;
            return O;
    }
    friend std::istream & operator>>(std::istream &O, Alumno &x){
            std::cout<<"\n Nombre: ";
            O>>x.Nombre;
            std::cout<<"\n Nombre de la Carrera: ";
            O>>x.Nombre_Carrera;
            std::cout<<"\n Total de Materias Aprobadas: ";
            O>>x.Materias_Aprob;
            std::cout<<"\n Promedio Final: ";
            O>>x.Promedio;
            return O;
    }
};


int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int op;
    while(true)
    {
        std::cout<<" 1.-Agregar informacion de alumno \n 2.-generar constancia"<<std::endl;
        std::cin>>op;
        switch(op)
        {
            case 1:
                std::cout<<"\n Ingresa los datos del alumno No.- "<<std::endl;
                std::cin>>x;
                MiCola.Enqueue(x);
            break;

            case 2:
                if(MiCola.vacia())
                {
                    std::cout<<"\n no hay solicitudes pendientes"<<std::endl;
                }
                else
                {
                    x=MiCola.Front();
                    std::cout<<x<<std::endl;
                    MiCola.Dequeue();
                }
            break;
        }
    }
    return 0;
}
