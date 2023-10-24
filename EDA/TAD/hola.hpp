#ifndef prueba
#define prueba

// Ingreso un dato numerico y se tiene una flecha hacia adelante y otro hacia atras
struct nodo;
typedef nodo *lista;

// Crea una lista con un dato y la devuelve
lista crearLista(int dato);

// Incerta el dato al final de la lista
void incertarLuego(lista li, int dato);

// Incerta el dato al inicio de la lista
void incertarAntes(lista li, int dato);

#endif // prueba