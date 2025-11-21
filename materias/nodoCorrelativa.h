typedef struct NodoCorrelativa {
    int idMateria;
    struct NodoCorrelativa* sig; // siguiente nodo
} NodoCorrelativa;

// Crea un nodo nuevo
NodoCorrelativa* nodo_crear(int idMateria);