#include <stdio.h>
#include <stdlib.h>
#define LIMPIARPANTALLA system("clear");
#define MOSTRAREMPRESA printf("\nAAA Conections");
#define SALTARLINEA printf("\n"); 

//Estructuras

typedef enum {
    menuClientes = 1,
    menuInsumos,
    menuVentas,
} Menus;

typedef enum {
    opcionCrearClientes = 1,
    opcionMostrarClientes,
    opcionActualizarClientes,
    opcionEliminarClientes,
} Clientes;

typedef struct {
    int dia;
    int mes;
    int ano;
} Fecha;



typedef struct {
    int idCliente;
    char nombreCompleto[50];
    char direccionCliente[50];
    char telefonoCliente[15];
    int estrato;
} Cliente;



typedef struct {
    int idEquipo;
    char tipoInsumo;
    float valor;
    Fecha fecha;
} Insumos;



typedef struct {
    int idVenta;
    Fecha fechaVenta;
    Cliente cliente;
    Insumos insumos;
    float valorTotal;
} Venta;

// Funciones Cliente

Cliente crearCliente(){
    Cliente miCliente;
    printf("--------- Crear Cliente ---------\n");
    printf("\nDocumento de Identidad: ");
    scanf("%d", &miCliente.idCliente);
    char c__buffer[20];
    fgets(c__buffer, 20, stdin);
    printf("\nNombre Completo: ");
    fgets(miCliente.nombreCompleto, 50, stdin);
    printf("\nDireccion de Residencia: ");
    fgets(miCliente.direccionCliente, 50, stdin);
    printf("\nTelefono de Contacto: ");
    fgets(miCliente.telefonoCliente, 15, stdin);
    printf("\nEstrato: ");
    scanf("%d", &miCliente.estrato);
    printf("\nCliente creado exitosamente. \n\n");
    return miCliente;
}

void mostrarClientes(Cliente miCliente, int cont){
        printf("--------- Cliente #%d ---------", cont);
        printf("\nID: %d", miCliente.idCliente);
        printf("\n\nNombre: %s", miCliente.nombreCompleto);
        printf("\nDireccion: %s", miCliente.direccionCliente);
        printf("\nTelefono: %s", miCliente.telefonoCliente);
        printf("\nEstrato: %d\n\n", miCliente.estrato);

}



Cliente actualizarCliente(Cliente miCliente){
    int opcion = 1;
    while(opcion != 0){
        printf("\n--------- Actualizar Clientes ---------\n");
        printf("\n1. Nombre. ");
        printf("\n2. Direccion. ");
        printf("\n3. Telefono. ");
        printf("\n4. Estrato. ");
        printf("\n\n0. Atras");
        printf("\n\n----------------------------------------");
        printf("\nIngrese la opcion: ");
        scanf("%d", &opcion);
        char c__buffer2[20];
        fgets(c__buffer2, 20, stdin);
        switch(opcion){
            case 0:
                return miCliente;
                LIMPIARPANTALLA;
                break;
            case 1:
                printf("\nActualice su Nombre: ");
                fgets(miCliente.nombreCompleto, 50, stdin);
                LIMPIARPANTALLA;
                printf("\nNombre Actualizado.\n");
                break;
            case 2:
                printf("\nActualice su Direccion: ");
                fgets(miCliente.direccionCliente, 50, stdin);
                LIMPIARPANTALLA;
                printf("\nDireccion Actualizada.\n");
                break;
            case 3:
                printf("\nActualice su Telefono: ");
                fgets(miCliente.telefonoCliente, 15, stdin);
                LIMPIARPANTALLA;
                printf("\nTelefono Actualizado.\n");
                break;
            case 4:
                printf("\nActualice su Estrato: ");
                scanf("%d", &miCliente.estrato);
                LIMPIARPANTALLA;
                printf("\nEstrato Actualizado.\n");
                break;
        }
    }
    LIMPIARPANTALLA;
    return miCliente;
}

void eliminarClientes(int *contClientes, Cliente vectorClientes[], int posicion){
    for(int i = posicion; i<(*contClientes)-1; i++){
        vectorClientes[i] = vectorClientes[i+1];
    }
    printf("\nCliente eliminado correctamente. \n\n");
    (*contClientes)--;
}

void menuGestionarClientes(){
    printf("--------- Gestion Clientes ---------\n");
    printf("\n1. Crear Cliente. ");
    printf("\n2. Mostrar Cliente. ");
    printf("\n3. Actualizar Cliente. ");
    printf("\n4. Eliminar Cliente. ");
    printf("\n\n0. Atras");
    printf("\n\n----------------------------------------");
    printf("\nIngrese la opcion: ");
}

// Funcion Menu Principal

void menuPrincipal(){
    printf("--------- Bienvenido a AAA Connection ---------\n");
    printf("\n1. Gestionar Cliente. ");
    printf("\n2. Gestionar Insumos. ");
    printf("\n3. Gestionar Ventas. ");
    printf("\n\n0. Salir");
    printf("\n\n----------------------------------------------");
    printf("\nIngrese la opcion: ");
}

//Gestion de Todos los menus en el main!!

    //Funciones submenu (Para resolver las tareas una por una con funciones, no blo ques de codigo gigantes)

void submenuCrearClientes(Cliente vectorClientes[], int *contClientes){
    Cliente miCliente;
    miCliente = crearCliente();
    vectorClientes[*contClientes] = miCliente;
    (*contClientes)++;
}



void submenuMostrarClientes(int contClientes, Cliente vectorClientes[]){
    LIMPIARPANTALLA;
    if(contClientes==0){
        printf("\nNingun cliente ha sido registrado.\n\n");
        }
    for(int i = 0; i < contClientes; i++){
        mostrarClientes(vectorClientes[i], i+1);
    }
}

int submenuActualizarClientes(int *contClientes, Cliente vectorClientes[]){
    Cliente miCliente;
    if((*contClientes)==0){
        printf("\nNingun cliente ha sido registrado.\n\n");
        return 0;
    }
    int id;
    printf("Ingrese el ID del cliente: ");
    scanf("%d", &id);
    int clienteEncontrado = -1; //Si se encuentra el cliente la variable es igual a 1, si es -1 no se encontro
    int i;
    for(i=0; i<(*contClientes); i++){
        if(vectorClientes[i].idCliente == id){ //Si el ID del cliente se encuentra en el vector Clientes entonces ClienteEcontrado = 1
            clienteEncontrado = 1; //El cliente se encontro
            miCliente = vectorClientes[i]; //Se encontro el vector del Cliente a actualizar
            Cliente clienteActualizado = actualizarCliente(miCliente); //La funcion devuelve el Cliente actualizado
            vectorClientes[i] = clienteActualizado; // El cliente fue actualizado
            LIMPIARPANTALLA;
            break;
        }
    }
    if(clienteEncontrado == -1){ //Si entra a este if es porque el cliente no fue encontrado
        printf("\nCliente no encontrado.\n");
    }
}

int submenuEliminarClientes(int *contClientes, Cliente vectorClientes[]){
    if((*contClientes)==0){
        printf("\nNingun cliente ha sido registrado.\n\n");
        return 0;
    }
    int id;
    printf("Ingrese el ID del cliente: ");
    scanf("%d", &id);
    int clienteEncontrado = -1;
    int i;
    int posicion;
    for(i=0; i<(*contClientes); i++){
        if(vectorClientes[i].idCliente == id){
            clienteEncontrado = 1;
            posicion = i;
            eliminarClientes(contClientes, vectorClientes, posicion);
            break;
        }
    }
    if(clienteEncontrado == -1){
        printf("\nCliente no encontrado.\n");
    }
}

void gestionarMenus(int opcion, Cliente vectorClientes[], int *contClientes){
    Cliente miCliente;
    switch(opcion){
            case menuClientes:
                int opcionGestionarClientes = 1;
                while(opcionGestionarClientes!=0){
                    menuGestionarClientes();
                    scanf("%d", &opcionGestionarClientes);
                    LIMPIARPANTALLA;
                    switch(opcionGestionarClientes){
                        case opcionCrearClientes:
                            submenuCrearClientes(vectorClientes, contClientes);
                            break;
                        case opcionMostrarClientes:
                            submenuMostrarClientes(*contClientes, vectorClientes);
                            break;
                        case opcionActualizarClientes:
                            submenuActualizarClientes(contClientes, vectorClientes);
                            break;
                        case opcionEliminarClientes:
                            submenuEliminarClientes(contClientes, vectorClientes);
                    }
                }
            break;
            case menuInsumos:
                
            break;
            case menuVentas:

            break;
        }
}

void main(){
    int tamanoClientes = 100;
    int contClientes = 0;
    Cliente vectorClientes[tamanoClientes];
    int opcion = 1;
    while(opcion!=0){
        menuPrincipal();
        scanf("%d", &opcion);
        LIMPIARPANTALLA;
        gestionarMenus(opcion, vectorClientes, &contClientes);
    }
}
