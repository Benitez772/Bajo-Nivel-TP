//NodoCorrelativa representa a una materia correlativa dentro de materia.
//Utiliza el id para identificarse.
typedef struct NodoCorrelativa {
    int idMateria;
    struct NodoCorrelativa* next; // siguiente nodo
} NodoCorrelativa;

// Crea un nodo nuevo
NodoCorrelativa* nodo_init(int idMateria);