#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPIARPANTALLA system("cls"); //cls 
#define MOSTRAREMPRESA printf("\nAAA Conections");
#define SALTARLINEA printf("\n"); 

//Estructuras

typedef enum {
    menuClientes = 1,
    menuProductos, //Cambio insumo a productos
    menuVentas,
} Menus;

typedef enum {
    opcionCrearClientes = 1,
    opcionMostrarClientes,
    opcionActualizarClientes,
    opcionEliminarClientes,
} Clientes;

typedef enum {
    opcionCrearProductos = 1,
    opcionMostrarProductos,
    opcionActualizarProductos,
    opcionEliminarProductos,
    opcionInformeInventario,
} Productos;

typedef enum {
    opcionCrearVentas = 1,
    opcionMostrarVentas,
    opcionActualizarVentas,
    opcionEliminarVentas,
} Ventas;

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
    int idProducto;
    char tipoProducto;
    char nombreProducto;
    int valorCompra;
    float valorVenta;
    int CantidadProducto;
    Fecha fechaCompra;
} Producto;

typedef struct {
    int idVenta;
    int idCliente;
    int idProducto;
    int cantidadVendida;
    float valorTotal;
    Fecha fechaVenta;
} Venta;

// Funciones Cliente

Cliente crearCliente(){
    Cliente miCliente;
    int pausa;
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
    printf("\n\nCliente creado exitosamente. \n\n");
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    return miCliente;
}

void mostrarClientes(Cliente miCliente, int cont){
        printf("--------- Cliente #%d ---------", cont);
        printf("\nID: %d", miCliente.idCliente);
        printf("\nNombre: %s", miCliente.nombreCompleto);
        printf("Direccion: %s", miCliente.direccionCliente);
        printf("Telefono: %s", miCliente.telefonoCliente);
        printf("Estrato: %d\n\n", miCliente.estrato);
}



Cliente actualizarCliente(Cliente miCliente){
    int opcion = 1;
    while(opcion != 0){
        printf("\n--------- Actualizar Cliente ---------\n");
        printf("\n1. Nombre. ");
        printf("\n2. Direccion. ");
        printf("\n3. Telefono. ");
        printf("\n4. Estrato. ");
        printf("\n\n0. Atras");
        printf("\n\n----------------------------------------");
        printf("\nIngrese la opcion: ");
        scanf("%d", &opcion);
        LIMPIARPANTALLA;
        char c__buffer2[20];
        fgets(c__buffer2, 20, stdin);
        switch(opcion){
            case 0:
                return miCliente;
                break;
            case 1:
                printf("\nActualice su Nombre: ");
                fgets(miCliente.nombreCompleto, 50, stdin);
                printf("\nNombre Actualizado.\n");
                int pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                LIMPIARPANTALLA;
                break;
            case 2:
                printf("\nActualice su Direccion: ");
                fgets(miCliente.direccionCliente, 50, stdin);
                printf("\nDireccion Actualizada.\n");
                int pausa2;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa2);  
                LIMPIARPANTALLA;
                break;
            case 3:
                printf("\nActualice su Telefono: ");
                fgets(miCliente.telefonoCliente, 15, stdin);
                printf("\nTelefono Actualizado.\n");
                int pausa3;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa3); 
                LIMPIARPANTALLA;
                break;
            case 4:
                printf("\nActualice su Estrato: ");
                scanf("%d", &miCliente.estrato);
                printf("\nEstrato Actualizado.\n");
                int pausa4;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa4);  
                LIMPIARPANTALLA;
                break;
        }
    }
    return miCliente;
}

void eliminarClientes(int *contClientes, Cliente vectorClientes[], int posicion){
    for(int i = posicion; i<(*contClientes)-1; i++){
        vectorClientes[i] = vectorClientes[i+1];
    }
    printf("\nCliente eliminado correctamente. \n\n");
    int pausa;
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
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

// Funciones Producto

Producto ingresarProducto(){
    Producto elProducto;
    printf("--------- Ingresar Producto ---------\n");
    printf("\nTipo de producto: ");
    printf("\n1. Equipos. ");
    printf("\n2. Insumos. ");
    printf("\n\n----------------------------------------");
    printf("\nIngrese la opcion: ");
    scanf("%d", &elProducto.tipoProducto);
    printf("\nNombre del Producto: ");
   
    switch(elProducto.tipoProducto){
        case 1:
        printf("\n1. Router. ");
        printf("\n2. Antena. ");
        printf("\n3. Estabilizador. ");
        printf("\n\n Ingrese una opcion. ");
        scanf("%d", &elProducto.nombreProducto);
        break;

        case 2:

        printf("\n1. Cable UTP. ");
        printf("\n2. Conector RJ45 ");
        printf("\n3. Grapas. ");
        printf("\n4. Amarras. ");
        printf("\n\n Ingrese una opcion. ");
        scanf("%d", &elProducto.nombreProducto);
        break;
    }

    switch(elProducto.tipoProducto){
        case 1:
        switch(elProducto.nombreProducto){
            case 1:
            elProducto.idProducto = 1101;
            break;
            case 2:
            elProducto.idProducto = 1201;
            break;
            case 3:
            elProducto.idProducto = 1301;
            break;
        }
        break;

        case 2:
            switch(elProducto.nombreProducto){
                case 1:
                elProducto.idProducto = 2101;
                break;
                case 2:
                elProducto.idProducto = 2201;
                break;
                case 3:
                elProducto.idProducto = 2301;
                break;
                case 4:
                elProducto.idProducto = 2401;
                break;
            }
        break; 
        
    }
    
    switch (elProducto.idProducto){
        case 1101:
        elProducto.valorCompra = 38000;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;

        case 1201:
        elProducto.valorCompra = 145000;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;

        case 1301:
        elProducto.valorCompra = 25000;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;

        case 2101:
        elProducto.valorCompra = 3500;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;

        case 2201:
        elProducto.valorCompra = 1200;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;

        case 2301:
        elProducto.valorCompra = 2900;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;

        case 2401:
        elProducto.valorCompra = 4500;
        elProducto.valorVenta = elProducto.valorCompra *1.3;
        break;
    }

    LIMPIARPANTALLA
    printf("Cantidad del producto: ");
    scanf("%d", &elProducto.CantidadProducto);
    LIMPIARPANTALLA
    printf("Fecha de Compra (DD/MM/AAAA):\n");
    printf("Dia:");
    scanf("%d", &elProducto.fechaCompra.dia);
    printf("Mes:");
    scanf("%d", &elProducto.fechaCompra.mes);
    printf("Ano:");
    scanf("%d", &elProducto.fechaCompra.ano);
    
    printf("\nProducto registrado exitosamente. \n\n");
    return elProducto;
    
}


void mostrarProductos(Producto elProducto, int cont){

    char tipo[20]; 
    char nombre[20];   
       
    if(elProducto.tipoProducto==1){
        
        strcpy(tipo,"Equipo");
                
    }else{
        strcpy(tipo,"Insumo");
    }
                
    switch (elProducto.idProducto){
        case 1101:
        strcpy(nombre,"Router");
        break;

        case 1201:
        strcpy(nombre,"Antena");
        break;

        case 1301:
        strcpy(nombre,"Estabilizador");
        break;

        case 2101:
        strcpy(nombre,"Cable UTP");
        break;

        case 2201:
        strcpy(nombre,"Conector RJ45");
        break;

        case 2301:
        strcpy(nombre,"Grapas");
        break;

        case 2401:
        strcpy(nombre,"Amarras");
        break;
    }
   
    printf("|  %4d  |  %7s |%-13s|  %7d   |  %7.0f  |  %3d   |%2d/%2d/%4d|\n"    , elProducto.idProducto, tipo, nombre,  elProducto.valorCompra, elProducto.valorVenta, elProducto.CantidadProducto, elProducto.fechaCompra.dia,elProducto.fechaCompra.mes,elProducto.fechaCompra.ano);
    printf("+--------+----------+-------------+------------+-----------+--------+----------+\n");
}



Producto actualizarProducto(Producto elProducto){
    int opcion = 1;
    while(opcion != 0){
        printf("\n--------- Actualizar Productos ---------\n");
        printf("\n1. Producto. ");
        printf("\n2. Cantidad. ");
        printf("\n3. Fecha. ");
        printf("\n\n0. Atras");
        printf("\n\n----------------------------------------");
        printf("\nIngrese la opcion: ");
        scanf("%d", &opcion);
        char c__buffer2[20];
        fgets(c__buffer2, 20, stdin);
        switch(opcion){
            case 0:
                return elProducto;
                LIMPIARPANTALLA;
                break;
            case 1:
                printf("\nActualice Tipo de Producto: ");
                printf("\n1. Equipos. ");
                printf("\n2. Insumos. ");
                printf("\n\n----------------------------------------");
                printf("\nIngrese la opcion: ");
                scanf("%d", &elProducto.tipoProducto);
                printf("\nActualice Nombre del Producto: ");
                switch(elProducto.tipoProducto){
                    case 1:
                    printf("\n1. Router. ");
                    printf("\n2. Antena. ");
                    printf("\n3. Estabilizador. ");
                    printf("\n\n Ingrese una opcion. ");
                    scanf("%d", &elProducto.nombreProducto);
                    break;

                    case 2:

                    printf("\n1. Cable UTP. ");
                    printf("\n2. Conector RJ45 ");
                    printf("\n3. Grapas. ");
                    printf("\n4. Amarras. ");
                    printf("\n\n Ingrese una opcion. ");
                    scanf("%d", &elProducto.nombreProducto);
                    break;
                }

                switch(elProducto.tipoProducto){
                    case 1:
                        switch(elProducto.nombreProducto){
                            case 1:
                            elProducto.idProducto = 1101;
                            break;
                            case 2:
                            elProducto.idProducto = 1201;
                            break;
                            case 3:
                            elProducto.idProducto = 1301;
                            break;
                        }
                    break;

                    case 2:
                        switch(elProducto.nombreProducto){
                            case 1:
                            elProducto.idProducto = 2101;
                            break;
                            case 2:
                            elProducto.idProducto = 2201;
                            break;
                            case 3:
                            elProducto.idProducto = 2301;
                            break;
                            case 4:
                            elProducto.idProducto = 2401;
                            break;
                        }
                    break; 
                }

                switch (elProducto.idProducto){
                    case 1101:
                    elProducto.valorCompra = 38000;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;

                    case 1201:
                    elProducto.valorCompra = 145000;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;

                    case 1301:
                    elProducto.valorCompra = 25000;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;

                    case 2101:
                    elProducto.valorCompra = 3500;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;

                    case 2201:
                    elProducto.valorCompra = 1200;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;

                    case 2301:
                    elProducto.valorCompra = 2900;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;

                    case 2401:
                    elProducto.valorCompra = 4500;
                    elProducto.valorVenta = elProducto.valorCompra *1.3;
                    break;
                }

                LIMPIARPANTALLA;
                printf("\nProducto Actualizado.\n");
                int pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                break;

            case 2:
                printf("\nActualice Cantidad: ");
                scanf("%d",&elProducto.CantidadProducto);
                LIMPIARPANTALLA;
                printf("\nCantidad Actualizada.\n");
                pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                break;
            
            case 3:
                printf("\nActualice Fecha de Compra: ");
                //scanf(elProducto.fechaCompra, 15, stdin);
                LIMPIARPANTALLA;
                printf("\nTelefono Actualizado.\n");
                pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                break;
            
        }
    }
    LIMPIARPANTALLA;
    return elProducto;
}

/*void eliminarProductos(int *contProductos, Producto vectorProductos[], int posicion){
    int CantidadVacia = 0;
    for(int i = posicion; i<(*contProductos)-1; i++){
        vectorProductos[i] = vectorProductos[i+1];
    }
    (*contProductos)--;
    for(int i=0; i<(*contProductos); i++){
        if(vectorProductos[i].CantidadProducto == 0){
            CantidadVacia = 1;
            for(int i2 = i; i2<(*contProductos)-1; i2++){
                vectorProductos[i2] = vectorProductos[i2+1];
            }
        }
        if(CantidadVacia == 1){
            (*contProductos)--;
        }
    }
}*/

void eliminarProductos(int *contProductos, Producto vectorProductos[], int posicion) {
    for(int i = posicion; i<(*contProductos)-1; i++) {
		vectorProductos[i] = vectorProductos[i+1];
	}
    (*contProductos)--;
    printf("Producto Eliminado.");
}

// Funciones Venta

Venta crearVenta(int contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[]){
    Venta miVenta = {0};
    int pausa;
    
    printf("--------- Crear Venta ---------\n");
    printf("%d", (*contProductos));
    
    // Mostrar clientes disponibles
    if(contClientes == 0){
        printf("\nNo hay clientes registrados.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    printf("\nIngrese el ID del cliente: ");
    scanf("%d", &miVenta.idCliente);
    
    // Validar que el cliente exista
    int clienteEncontrado = 0;
    for(int i = 0; i < contClientes; i++){
        if(vectorClientes[i].idCliente == miVenta.idCliente){
            clienteEncontrado = 1;
            break;
        }
    }
    
    if(!clienteEncontrado){
        printf("\nCliente no encontrado.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    LIMPIARPANTALLA;
    
    // Mostrar productos disponibles
    if((*contProductos) == 0){
        printf("\nNo hay productos registrados.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    printf("\n--- Productos Disponibles ---\n");
    for(int i = 0; i < (*contProductos); i++){
        char nombre[20];
        switch(vectorProductos[i].idProducto){
            case 1101: strcpy(nombre,"Router"); break;
            case 1201: strcpy(nombre,"Antena"); break;
            case 1301: strcpy(nombre,"Estabilizador"); break;
            case 2101: strcpy(nombre,"Cable UTP"); break;
            case 2201: strcpy(nombre,"Conector RJ45"); break;
            case 2301: strcpy(nombre,"Grapas"); break;
            case 2401: strcpy(nombre,"Amarras"); break;
            default: strcpy(nombre,"Otro"); break;
        }
        printf("%d. %s (ID: %d) - Cantidad: %d\n", i+1, nombre, vectorProductos[i].idProducto, vectorProductos[i].CantidadProducto);
    }
    
    printf("\nSeleccione el ID del producto: ");
    scanf("%d", &miVenta.idProducto);
    
    // Sumar stock total del producto (puede haber múltiples entradas con mismo id)
    int totalStock = 0;
    int primerIndice = -1;
    for(int i = 0; i < (*contProductos); i++){
        if(vectorProductos[i].idProducto == miVenta.idProducto){
            totalStock += vectorProductos[i].CantidadProducto;
            if(primerIndice == -1) primerIndice = i;
        }
    }
    
    if(primerIndice == -1){
        printf("\nProducto no encontrado.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    if(totalStock == 0){
        printf("\nProducto sin stock disponible.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    printf("\nStock disponible (total): %d\n", totalStock);
    printf("\nCantidad a vender: ");
    scanf("%d", &miVenta.cantidadVendida);
    
    if(miVenta.cantidadVendida > totalStock){
        printf("\nStock insuficiente. Disponible: %d\n", totalStock);
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    float precioUnitario = vectorProductos[primerIndice].valorVenta;
    miVenta.valorTotal = miVenta.cantidadVendida * precioUnitario;
    
    int restante = miVenta.cantidadVendida;
    for(int i = 0; i < (*contProductos) && restante > 0; i++){
        if(vectorProductos[i].idProducto == miVenta.idProducto){
            int disponibleEnEntrada = vectorProductos[i].CantidadProducto;
            if(disponibleEnEntrada == 0) continue;
            if(disponibleEnEntrada <= restante){
                restante -= disponibleEnEntrada;
                vectorProductos[i].CantidadProducto = 0;
                if (vectorProductos[i].CantidadProducto == 0) {
                    printf("\nEl producto ya no tiene unidades en stock\n");
                    eliminarProductos(contProductos, vectorProductos, i);
                    printf("%d", (*contProductos));
                }
            } else {
                vectorProductos[i].CantidadProducto -= restante;
                restante = 0;
            }
        }
    }
    // Fecha de venta
    printf("\nFecha de Venta (DD/MM/AAAA):\n");
    printf("Dia: ");
    scanf("%d", &miVenta.fechaVenta.dia);
    printf("Mes: ");
    scanf("%d", &miVenta.fechaVenta.mes);
    printf("Ano: ");
    scanf("%d", &miVenta.fechaVenta.ano);
    
    printf("\n\nVenta registrada exitosamente.\n");
    printf("Valor Total: $%.2f\n\n", miVenta.valorTotal);
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
    
    return miVenta;
}

// Funcion Especial
void informeInventario( int contProductos,Producto vectorProductos[]){
int controuters=0;
int contestabilizador=0;
int contantenas=0;
int contutp=0;
int contrj45=0;
int contgrapas=0;
int contamarras=0;

    if((contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        }
    for(int i = 0; i < contProductos; i++){
        switch(vectorProductos[i].idProducto){
            case 1101:
            controuters=controuters+vectorProductos[i].CantidadProducto;
            break;
            case 1201:
            contantenas=contantenas+vectorProductos[i].CantidadProducto;
            break;
            case 1301:
            contestabilizador=contestabilizador+vectorProductos[i].CantidadProducto;
            break;
            case 2101:
            contutp=contutp+vectorProductos[i].CantidadProducto;
            break;
            case 2201:
            contrj45=contrj45+vectorProductos[i].CantidadProducto;
            break;
            case 2301:
            contgrapas=contgrapas+vectorProductos[i].CantidadProducto;
            break;
            case 2401:
            contamarras=contamarras+vectorProductos[i].CantidadProducto;
            break;
        }
       
    }
    printf ("%d \n",controuters);
    printf ("%d \n",contestabilizador);
    printf ("%d \n",contantenas);
    printf ("%d \n",contutp);
    printf ("%d \n",contrj45);
    printf ("%d \n",contgrapas);
    printf ("%d \n",contamarras);
    
}

//FINAL FUNCION ESPECIAL

void menuGestionarProductos(){
    printf("--------- Gestion Productos ---------\n");
    printf("\n1. Ingresar Productos. ");
    printf("\n2. Mostrar Productos. ");
    printf("\n3. Actualizar Productos. ");
    printf("\n4. Eliminar Productos. ");
    
    printf("\n\n0. Atras");
    printf("\n\n----------------------------------------");
    printf("\nIngrese la opcion: ");
}

void menuGestionarVentas(){
    printf("--------- Gestion Ventas ---------\n");
    printf("\n1. Crear Venta. ");
    printf("\n2. Mostrar Venta. ");
    printf("\n3. Actualizar Venta. ");
    printf("\n4. Eliminar Venta. ");
    printf("\n\n0. Atras");
    printf("\n\n----------------------------------------");
    printf("\nIngrese la opcion: ");
}

// Funcion Menu Principal

void menuPrincipal(){
    printf("--------- Bienvenido a AAA Connection ---------\n");
    printf("\n1. Gestionar Cliente. ");
    printf("\n2. Gestionar Productos. ");
    printf("\n3. Gestionar Ventas. ");
    printf("\n\n0. Salir");
    printf("\n\n----------------------------------------------");
    printf("\nIngrese la opcion: ");
}

//Gestion de Todos los menus en el main!!

    //Funciones submenu (Para resolver las tareas una por una con funciones, no blo ques de codigo gigantes)

void submenuCrearClientes(Cliente vectorClientes[], int *contClientes){
    LIMPIARPANTALLA;
    Cliente miCliente;
    miCliente = crearCliente();
    vectorClientes[*contClientes] = miCliente;
    (*contClientes)++;
    LIMPIARPANTALLA;
}

void submenuMostrarClientes(int contClientes, Cliente vectorClientes[]){
    LIMPIARPANTALLA;
    if(contClientes==0){
        printf("\nNingun cliente ha sido registrado.\n\n");
        }
    for(int i = 0; i < contClientes; i++){
        mostrarClientes(vectorClientes[i], i+1);
    }
    int pausa;
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
}

int submenuActualizarClientes(int *contClientes, Cliente vectorClientes[]){
    LIMPIARPANTALLA;
    Cliente miCliente;
    if((*contClientes)==0){
        printf("\nNingun cliente ha sido registrado.\n\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return 0;
    }
    int id;
    printf("\n--------- Actualizar Cliente ---------\n");
    printf("\nIngrese el ID del cliente: ");
    scanf("%d", &id);
    int clienteEncontrado = -1; //Si se encuentra el cliente la variable es igual a 1, si es -1 no se encontro
    int i;
    for(i=0; i<(*contClientes); i++){
        if(vectorClientes[i].idCliente == id){ //Si el ID del cliente se encuentra en el vector Clientes entonces ClienteEcontrado = 1
            clienteEncontrado = 1; //El cliente se encontro
            int pausa;
            printf("\n\nCliente encontrado.\n");
            printf("\nDigite 0 para actualizar la informacion del cliente...");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            miCliente = vectorClientes[i]; //Se encontro el vector del Cliente a actualizar
            Cliente clienteActualizado = actualizarCliente(miCliente); //La funcion devuelve el Cliente actualizado
            vectorClientes[i] = clienteActualizado; // El cliente fue actualizado
            break;
        }
    }
    if(clienteEncontrado == -1){ //Si entra a este if es porque el cliente no fue encontrado
        printf("\n\nCliente no encontrado.\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
    }
}

int submenuEliminarClientes(int *contClientes, Cliente vectorClientes[]){
    LIMPIARPANTALLA;
    if((*contClientes)==0){
        printf("\nNingun cliente ha sido registrado.\n\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return 0;
    }
    int id;
    printf("\n--------- Eliminar Cliente ---------\n");
    printf("\nIngrese el ID del cliente: ");
    scanf("%d", &id);
    LIMPIARPANTALLA;
    int clienteEncontrado = -1;
    int i;
    int posicion;
    for(i=0; i<(*contClientes); i++){
        if(vectorClientes[i].idCliente == id){
            clienteEncontrado = 1;
            posicion = i;
            int pausa;
            printf("\n--------- Eliminacion de cliente ---------\n");
            printf("\n0. Cancelar. ");
            printf("\n1. Confirmar. ");
            printf("\n\n----------------------------------------");
            printf("\nIngrese la opcion: ");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            switch(pausa){
                case 0:
                    printf("La eliminacion fue cancelada.\n");
                    int pausa2;
                    printf("\n\nDigite 0 para continuar...");
                    scanf("%d", &pausa2);
                    LIMPIARPANTALLA;
                    break;
                case 1:
                    eliminarClientes(contClientes, vectorClientes, posicion);
                    break;
            }
            break;
        }
        LIMPIARPANTALLA;
    }
    if(clienteEncontrado == -1){
        printf("\nCliente no encontrado.\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);  
        LIMPIARPANTALLA;
    }
}

// Submenus Producto

void submenuCrearProductos(Producto vectorProductos[], int *contProductos){
    Producto elProducto;
    elProducto = ingresarProducto();
    vectorProductos[*contProductos] = elProducto;
    (*contProductos)++;
}



void submenuMostrarProductos(int *contProductos, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    printf("+--------+----------+-------------+------------+-----------+--------+----------+\n");
    printf("|   ID   |   Tipo   |   Nombre    |Valor Compra|Valor Venta|Cantidad|    Mes   |\n"); 
    printf("+--------+----------+-------------+------------+-----------+--------+----------+\n");
    if((*contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        }
    for(int i = 0; i < (*contProductos); i++){
        mostrarProductos(vectorProductos[i], i+1);
    }
    int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
}

int submenuActualizarProductos(int *contProductos, Producto vectorProductos[]){
    Producto elProducto;
    if((*contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        return 0;
    }
    int id;
    for(int i = 0; i < (*contProductos); i++){
     
        switch (vectorProductos[i].idProducto){
            case 1101:
            printf("\n%d    Router",vectorProductos[i].idProducto);
            break;

            case 1201:
            printf("\n%d    Antena",vectorProductos[i].idProducto);
            break;

            case 1301:
            printf("\n%d    Estabilizador",vectorProductos[i].idProducto);
            break;

            case 2101:
            printf("\n%d    Cable UTP",vectorProductos[i].idProducto);
            break;

            case 2201:
            printf("\n%d    Conector RJ45",vectorProductos[i].idProducto);
            break;

            case 2301:
            printf("\n%d    Grapas",vectorProductos[i].idProducto);
            break;

            case 2401:
            printf("\n%d    Amarras",vectorProductos[i].idProducto);
            break;
        }
        
    }
    printf("\n\n----------------------------------------");
    printf("\nIngrese el ID del producto: ");
    scanf("%d", &id);
    int productoEncontrado = -1; 
    int i;
    for(i=0; i<(*contProductos); i++){
        if(vectorProductos[i].idProducto == id){ 
            productoEncontrado = 1;
            elProducto = vectorProductos[i];
            Producto productoActualizado = actualizarProducto(elProducto); 
            vectorProductos[i] = productoActualizado; 
            LIMPIARPANTALLA;
            break;
        }
    }
    if(productoEncontrado == -1){ 
        printf("\nProducto no encontrado.\n");
    }
}

int submenuEliminarProductos(int *contProductos, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    if((*contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return 0;
    }
    int id;
    printf("\n--------- Eliminar Producto ---------\n");
    for(int i = 0; i < (*contProductos); i++){
     
        switch (vectorProductos[i].idProducto){
            case 1101:
            printf("\n%d    Router",vectorProductos[i].idProducto);
            break;

            case 1201:
            printf("\n%d    Antena",vectorProductos[i].idProducto);
            break;

            case 1301:
            printf("\n%d    Estabilizador",vectorProductos[i].idProducto);
            break;

            case 2101:
            printf("\n%d    Cable UTP",vectorProductos[i].idProducto);
            break;

            case 2201:
            printf("\n%d    Conector RJ45",vectorProductos[i].idProducto);
            break;

            case 2301:
            printf("\n%d    Grapas",vectorProductos[i].idProducto);
            break;

            case 2401:
            printf("\n%d    Amarras",vectorProductos[i].idProducto);
            break;
        }
        
    }
    printf("\n\n----------------------------------------");
    printf("\nIngrese el ID del Producto: ");
    scanf("%d", &id);
    LIMPIARPANTALLA;
    int productoEncontrado = -1;
    int i;
    int posicion;
    for(i=0; i<(*contProductos); i++){
        if(vectorProductos[i].idProducto == id){
            productoEncontrado = 1;
            posicion = i;
            printf("Producto encontrado.\n");
            int pausa;
            printf("\nDigite 0 para confirmar la eliminacion del producto...");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            eliminarProductos(contProductos, vectorProductos, posicion);
            printf("\nProducto eliminado correctamente. \n\n");
            printf("\nDigite 0 para continuar...");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            break;
        }
        LIMPIARPANTALLA;
    }
    if(productoEncontrado == -1){
        printf("\nProducto no encontrado.\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);  
        LIMPIARPANTALLA;
    }
}

void submenuCrearVenta(Venta vectorVentas[], int *contVentas, int contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    Venta miVenta;
    miVenta = crearVenta(contClientes, vectorClientes, contProductos, vectorProductos);
    vectorVentas[*contVentas] = miVenta;
    (*contVentas)++;
    LIMPIARPANTALLA;
}

void gestionarMenus(int opcion, Cliente vectorClientes[], Producto vectorProductos[], Venta vectorVentas[], int *contClientes,int *contProductos, int *contVentas, int *contVectorproductos){
    Cliente miCliente;
    switch(opcion){
            case menuClientes:
                int opcionGestionarClientes = 1;
                while(opcionGestionarClientes!=0){
                    menuGestionarClientes();
                    scanf("%d", &opcionGestionarClientes);
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
                            break;
                    }
                }
            break;
            case menuProductos:
                int opcionGestionarProductos = 1;
                while(opcionGestionarProductos!=0){
                    menuGestionarProductos();
                    scanf("%d", &opcionGestionarProductos);
                    LIMPIARPANTALLA;
                    switch(opcionGestionarProductos){
                        case opcionCrearProductos:
                            submenuCrearProductos(vectorProductos, contProductos);
                            break;
                        case opcionMostrarProductos:
                            submenuMostrarProductos(contProductos, vectorProductos);
                            break;
                        case opcionActualizarProductos:
                            submenuActualizarProductos(contProductos, vectorProductos);
                            break;
                        case opcionEliminarProductos:
                            submenuEliminarProductos(contProductos, vectorProductos);
                            break;
                        case opcionInformeInventario:
                            informeInventario(*contProductos, vectorProductos);
                            break;
                    }
                }
            break;

            case menuVentas:
                int opcionGestionarVentas = 1;
                while(opcionGestionarVentas!=0){
                    menuGestionarVentas();
                    scanf("%d", &opcionGestionarVentas);
                    LIMPIARPANTALLA;
                    switch(opcionGestionarVentas){
                        case opcionCrearVentas:{
                            submenuCrearVenta(vectorVentas, contVentas, *contClientes, vectorClientes, contProductos, vectorProductos);
                            break;
                        case opcionMostrarVentas:
                            
                            break;
                        case opcionActualizarVentas:
                            
                            break;
                        case opcionEliminarVentas:
                            
                            break;
                    }
                break;
            }
        }
    }
}

void main(){
    int tamanoClientes = 100;
    int tamanoProductos = 100;
    int tamanoVentas = 100;
    int contClientes = 0;
    int contProductos = 0;
    int contVentas = 0;
    int contVectorproductos = 0;
    Cliente vectorClientes[tamanoClientes];
    Producto vectorProductos[tamanoProductos];
    Venta vectorVentas[tamanoVentas];
    int opcion = 1;
    while(opcion!=0){
        LIMPIARPANTALLA;
        menuPrincipal();
        scanf("%d", &opcion);
        LIMPIARPANTALLA;
        gestionarMenus(opcion, vectorClientes, vectorProductos, vectorVentas, &contClientes,&contProductos, &contVentas, &contVectorproductos);
    }
}

// Recuerde Ingresar las funciones para guardar y actualizar archivo
// Recuerde la Funcion de Recursividad
// si le queda tiempo revisar lo de las fechas 
// toca vereificar las pausas en producto (yo me encargo) porque como me quedo a mi en el "mostrar", no me gusto 
