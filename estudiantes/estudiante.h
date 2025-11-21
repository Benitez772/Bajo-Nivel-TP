typedef struct {
    int legajo;            // debe tener 6 dígitos
    char nombre[40];
    char apellido[40];
    int edad;
} Estudiante;

// Inicializa; devuelve 1 si funciona y 0 en error 
int estudiante_init(Estudiante* e, int legajo, const char* nombre, const char* apellido, int edad);

// Modifica el estudiante existente con los datos de nuevo. devuelve 0 si el estudiante nuevo es invalido
int estudiante_modificar(Estudiante* e, const Estudiante* nuevo);

/* Valida datos: 1 = válido, 0 = inválido */
int estudiante_es_valido(Estudiante* e);

// Setters: set_legajo devuelve 1 si válido (debe tener 6 digitos)
int estudiante_set_legajo(Estudiante* e, int legajo);

void estudiante_set_nombre(Estudiante* e, const char* nombre);
void estudiante_set_apellido(Estudiante* e, const char* apellido);
void estudiante_set_edad(Estudiante* e, int edad);