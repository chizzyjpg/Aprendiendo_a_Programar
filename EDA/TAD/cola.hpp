#ifndef _COLA_H
#define _COLA_H

typedef int T;

struct RepresentacionCola;
typedef RepresentacionCola *Cola;

Cola crearCola();
/* Devuelve la cola vacia. */

void encolar(T t, Cola &c);
/* Agrega el elemento t al final de c. */

bool esVaciaCola(Cola c);
/* Devuelve 'true' si c es vacia, 'false' en otro caso. */

T frente(Cola c);
/* Devuelve el primer elemento de c.
Precondicion: ! esVaciaCola(c). */

void desencolar(Cola &c);
/* Remueve el primer elemento de c.
Precondicion: ! esVaciaCola(c). */

void destruirCola(Cola &c);
/* Libera toda la
(Cola &c);
memoria ocupada por c. */

#endif /* _COLA_H */