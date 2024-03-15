#ifndef DEQUE;
#define DEQUE ;

// estructura del cabezal el cual guarda el inicio y final de pila
struct dummy;
typedef dummy *Dummy;

// crea cabezal de pila
Dummy crearLista();

// agrega al inicio de la pila
void agregarInicio(Dummy &, int);

// agrega al final de la pila
void agregarFinal(Dummy &, int);

// elimina el elemento al inicio de la pila
void eliminarInicio(Dummy &);

// elimina el elemento al final de la pila
void eliminarUltimo(Dummy &);

// devuelve elemento al inicio de la pila
int inicio(Dummy &);

// devuelve elemento al final de la pila
int final(Dummy &);

// verifica si la pila esta vacia;
bool esVacia(Dummy &);

#endif // deque