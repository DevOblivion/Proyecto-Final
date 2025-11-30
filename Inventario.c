#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPIARPANTALLA system("cls"); //cls 
#define MOSTRAREMPRESA printf("\nAAA Conections");
#define SALTARLINEA printf("\n"); 
#define GUARDARARCHIVO(cliente, venta, producto) guardarArchivo(cliente, venta, producto);//Macro para guardar archivos

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
    int CantidadVendida;
    Fecha fechaCompra;
} Producto;

typedef struct {
    int idVenta;
    Cliente cliente;
    int idProducto;
    Producto producto;
    int cantidadVendida;
    float valorTotal;
    Fecha fechaVenta;
} Venta;

//FUNCION MACRO GUARDAR ARCHIVO

void guardarArchivo(Cliente *miCliente, Venta *miVenta, Producto *miProducto) {
    FILE *f;
    if (miCliente != NULL) {
        f = fopen("clientes.txt", "a");

        if (f == NULL) {
            printf("\nError: No se pudo abrir el archivo para guardar.");
            return;
        }

        fprintf(f, "%d|%s|%s|%s|%d\n", 
                (*miCliente).idCliente, 
                (*miCliente).nombreCompleto, 
                (*miCliente).direccionCliente, 
                (*miCliente).telefonoCliente, 
                (*miCliente).estrato);
    }

    if (miVenta != NULL) {
        f = fopen("ventas.txt", "a");

        if (f == NULL) {
            printf("\nError: No se pudo abrir el archivo para guardar.");
            return;
        }

        fprintf(f, "%d|%d|%s|%d|%d|%d|%d|%f|%d\n", 
                (*miVenta).idVenta, 
                (*miVenta).cliente.idCliente, 
                (*miVenta).cliente.nombreCompleto,  
                (*miVenta).cantidadVendida,
                (*miVenta).fechaVenta.dia,
                (*miVenta).fechaVenta.mes,
                (*miVenta).fechaVenta.ano,
                (*miVenta).valorTotal,
                (*miVenta).idProducto);
    }

    if (miProducto != NULL) {
        f = fopen("productos.txt", "a");

        if (f == NULL) {
            printf("\nError: No se pudo abrir el archivo para guardar.");
            return;
        }

        fprintf(f, "%d|%d|%f|%d|%d|%d|%d\n", 
                (*miProducto).idProducto, 
                (*miProducto).valorCompra, 
                (*miProducto).valorVenta,  
                (*miProducto).CantidadProducto,
                (*miProducto).fechaCompra.dia,
                (*miProducto).fechaCompra.mes,
                (*miProducto).fechaCompra.ano);
    }

    fclose(f);
}

//FUNCIONES ARCHIVOS - CLIENTES

void cargarClientes(Cliente vectorClientes[], int *contClientes) {
    FILE *f = fopen("clientes.txt", "r");

    if (f == NULL) {
        printf("\n[Sistema] Archivo clientes.txt no encontrado. Creando nuevo...\n");
        return; // No hay archivo, el contador queda en 0
    }

    int i = 0;
    
    // Leer el archivo hasta que se alcance el final (EOF)
    while (!feof(f) && i < 100) {
        Cliente tempCliente;
        
        // El *[^|] lee cualquier cosa hasta encontrar el siguiente separador |
        int itemsLeidos = fscanf(f, "%d|%49[^|]|%49[^|]|%14[^|]|%d\n", 
                                 &tempCliente.idCliente, 
                                 tempCliente.nombreCompleto, 
                                 tempCliente.direccionCliente, 
                                 tempCliente.telefonoCliente, 
                                 &tempCliente.estrato);

        if (itemsLeidos == 5) {
            // Si se leyeron los 5 items correctamente, lo agregamos al vector
            vectorClientes[i] = tempCliente;
            i++;
        }
    }

    *contClientes = i; // Actualizamos el contador con el numero de clientes leidos
    fclose(f);
}

//FINAL ARCHIVOS - CLIENTES

//FUNCIONES ARCHIVOS - PRODUCTOS

void cargarProductos(Producto vectorProductos[], int *contProductos) {
    FILE *f = fopen("productos.txt", "r");

    if (f == NULL) {
        printf("\n[Sistema] Archivo clientes.txt no encontrado. Creando nuevo...\n");
        return; // No hay archivo, el contador queda en 0
    }

    int i = 0;
    
    // Leer el archivo hasta que se alcance el final (EOF)
    while (!feof(f) && i < 100) {
        Producto tempProducto;
        
        // El *[^|] lee cualquier cosa hasta encontrar el siguiente separador |
        int itemsLeidos = fscanf(f, "%d|%d|%f|%d|%d|%d|%d\n", 
                                 &tempProducto.idProducto, 
                                 &tempProducto.valorCompra, 
                                 &tempProducto.valorVenta, 
                                 &tempProducto.CantidadProducto, 
                                 &tempProducto.fechaCompra.dia,
                                 &tempProducto.fechaCompra.mes,
                                 &tempProducto.fechaCompra.ano);

        if (itemsLeidos == 7) {
            // Si se leyeron los 7 items correctamente, lo agregamos al vector
            vectorProductos[i] = tempProducto;
            i++;
        }
    }

    *contProductos = i; // Actualizamos el contador con el numero de productos leidos
    fclose(f);
}

//FINAL ARCHIVOS - PRODUCTOS

//FUNCIONES ARCHIVOS - VENTAS

void cargarVentas(Venta vectorVentas[], int *contVentas) {
    FILE *f = fopen("ventas.txt", "r");

    if (f == NULL) {
        printf("\n[Sistema] Archivo clientes.txt no encontrado. Creando nuevo...\n");
        return; // No hay archivo, el contador queda en 0
    }

    int i = 0;
    
    // Leer el archivo hasta que se alcance el final (EOF)
    while (!feof(f) && i < 100) {
        Venta tempVenta;
        
        // El *[^|] lee cualquier cosa hasta encontrar el siguiente separador |
        int itemsLeidos = fscanf(f, "%d|%d|%49[^|]|%d|%d|%d|%d|%f|%d\n", 
                                 &tempVenta.idVenta, 
                                 &tempVenta.cliente.idCliente, 
                                 tempVenta.cliente.nombreCompleto,  
                                 &tempVenta.cantidadVendida,
                                 &tempVenta.fechaVenta.dia,
                                 &tempVenta.fechaVenta.mes,
                                 &tempVenta.fechaVenta.ano,
                                 &tempVenta.valorTotal,
                                 &tempVenta.idProducto);

        if (itemsLeidos == 9) {
            // Si se leyeron los 9 items correctamente, lo agregamos al vector
            vectorVentas[i] = tempVenta;
            i++;
        }
    }

    *contVentas = i; // Actualizamos el contador con el numero de ventas leidas
    fclose(f);
}

//FINAL ARCHIVOS - VENTAS

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
    
    GUARDARARCHIVO(&miCliente, NULL, NULL);
    printf("\n\nCliente creado exitosamente y GUARDADO en archivo. \n\n");

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
	printf("\n\n0. Atras. ");
    printf("\n\n------------------------------------");
    printf("\nIngrese la opcion: ");
    scanf("%d", &elProducto.tipoProducto);
    LIMPIARPANTALLA;
    printf("\nNombre del Producto: ");
   
    switch(elProducto.tipoProducto){
		 case 0:
        return elProducto;
        LIMPIARPANTALLA
        break;
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
    printf("Cantidad del producto: ");
    scanf("%d", &elProducto.CantidadProducto);
    LIMPIARPANTALLA;
    printf("Fecha de Compra (DD/MM/AAAA):\n");
    printf("Dia:");
    scanf("%d", &elProducto.fechaCompra.dia);
    printf("Mes:");
    scanf("%d", &elProducto.fechaCompra.mes);
    printf("Ano:");
    scanf("%d", &elProducto.fechaCompra.ano);
    
    printf("\nProducto registrado exitosamente. \n\n");
    printf("\nDigite 0 para continuar...");
    int pausa;
    scanf("%d", &pausa);  
    LIMPIARPANTALLA;
    GUARDARARCHIVO(NULL, NULL, &elProducto);
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
				GUARDARARCHIVO(NULL, NULL, &elProducto);
                printf("\nProducto Actualizado.\n");
                int pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                break;

            case 2:
                printf("\nActualice Cantidad: ");
                scanf("%d",&elProducto.CantidadProducto);
                LIMPIARPANTALLA;
				GUARDARARCHIVO(NULL, NULL, &elProducto);
                printf("\nCantidad Actualizada.\n");
                pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                break;
            
            case 3:
				printf("\nActualice Fecha de Compra: ");
                printf("Fecha de Compra (DD/MM/AAAA):\n");
                printf("Dia:");
                scanf("%d", &elProducto.fechaCompra.dia);
                printf("Mes:");
                scanf("%d", &elProducto.fechaCompra.mes);
                printf("Ano:");
                scanf("%d", &elProducto.fechaCompra.ano);
                LIMPIARPANTALLA;
                GUARDARARCHIVO(NULL, NULL, &elProducto);
				printf("\n\nFecha Actualizada y Guardado en archivo exitosamente. \n\n");
                pausa;
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);
                break;
                
            
        }
    }
    LIMPIARPANTALLA;
    return elProducto;
}

void eliminarProductos(int *contProductos, Producto vectorProductos[], int posicion) {
    for(int i = posicion; i<(*contProductos)-1; i++) {
		vectorProductos[i] = vectorProductos[i+1];
	}

	printf("\nProducto eliminado correctamente. \n\n");
    int pausa;
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
    (*contProductos)--;
    printf("Producto Eliminado.");
}

// Funciones Venta

Venta crearVenta(int *generadorID_Venta, int *contVentas, int contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[]){
    Venta miVenta = {0};
    int pausa;
    
    printf("--------- Crear Venta ---------\n");
    
    if(contClientes == 0){
        printf("\nNo hay clientes registrados.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    int id;
    printf("\nIngrese el ID del cliente: ");
    scanf("%d", &id);
    
    int clienteEncontrado = 0;
    for(int i = 0; i < contClientes; i++){
        if(vectorClientes[i].idCliente == id){
            clienteEncontrado = 1;
            miVenta.cliente = vectorClientes[i];
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
    
    if(totalStock <= 0){
        printf("\nProducto sin stock disponible.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
    
    printf("\nStock disponible (total): %d\n", totalStock);
    printf("\nCantidad a vender: ");
    scanf("%d", &miVenta.cantidadVendida);
    
    if(miVenta.cantidadVendida <= 0){
        printf("\nCantidad invalida.\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        return miVenta;
    }
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
        if(vectorProductos[i].idProducto != miVenta.idProducto) continue;
        int disponibleEnEntrada = vectorProductos[i].CantidadProducto;
        if(disponibleEnEntrada <= 0) continue;
        if(disponibleEnEntrada <= restante){
            restante -= disponibleEnEntrada;
            vectorProductos[i].CantidadProducto = 0;
        } else {
            vectorProductos[i].CantidadProducto -= restante;
            restante = 0;
        }
    }
    
    for(int i = 0; i < (*contProductos); i++){
        if(vectorProductos[i].CantidadProducto <= 0){
            eliminarProductos(contProductos, vectorProductos, i);
            i--;
        }
    }
    
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
    
    (*contVentas)++;
    (*generadorID_Venta)++;
    miVenta.idVenta = (*generadorID_Venta);
    GUARDARARCHIVO(NULL, &miVenta, NULL);
    return miVenta;
}

void mostrarVentas(Venta miVenta, int i, Producto vectorProducto[]){
        printf("--------- Venta #%d ---------", i+1);
        printf("\nID Venta: %d", miVenta.idVenta);
        printf("\nID Cliente: %d", miVenta.cliente.idCliente);
        printf("\nNombre: %s", miVenta.cliente.nombreCompleto);
        //printf("Producto: %d", miVenta.idProducto);
        char nombre[20];
        switch(miVenta.idProducto){
            case 1101: strcpy(nombre, "Router"); break;
            case 1201: strcpy(nombre, "Antena"); break;
            case 1301: strcpy(nombre, "Estabilizador"); break;
            case 2101: strcpy(nombre, "Cable UTP"); break;
            case 2201: strcpy(nombre, "Conector RJ45"); break;
            case 2301: strcpy(nombre, "Grapas"); break;
            case 2401: strcpy(nombre, "Amarras"); break;
            default: strcpy(nombre, "Otro"); break;
        }
        printf("Producto: %s", nombre);

        printf("\nCantidad: %d", miVenta.cantidadVendida);
        printf("\nFecha: %d-%d-%d", miVenta.fechaVenta.dia, miVenta.fechaVenta.mes, miVenta.fechaVenta.ano);
        printf("\nValor total: %.2f\n\n", miVenta.valorTotal);
}



//FUNCIONES VENTAS - STOCK

// Funcion de ayuda para obtener el total de productos
int totalStockProducto(int contProductos, Producto vectorProductos[], int idProducto){
    int total = 0;
    for(int i = 0; i < contProductos; i++){
        if(vectorProductos[i].idProducto == idProducto) total += vectorProductos[i].CantidadProducto;
    }
    return total;
}

// Funcion de ayuda para volver a hacer restock, 
void restockProduct(int *contProductos, Producto vectorProductos[], int idProducto, int cantidad){
    for(int i = 0; i < (*contProductos); i++){
        if(vectorProductos[i].idProducto == idProducto){
            vectorProductos[i].CantidadProducto += cantidad;
            return;
        }
    }
    // si no existe, crear un producto (Por si lo que el cliente compro eran las ultimas unidades, 
    //ya no habria un producto con ese ID, por ello lo crea en el vectorProductos)
    Producto p;
    p.idProducto = idProducto;
    p.tipoProducto = 0;
    p.nombreProducto = 0;
    p.CantidadProducto = cantidad;
    p.CantidadVendida = 0;
    p.fechaCompra.dia = p.fechaCompra.mes = p.fechaCompra.ano = 0;
    switch(idProducto){
        case 1101: p.valorCompra = 38000; break;
        case 1201: p.valorCompra = 145000; break;
        case 1301: p.valorCompra = 25000; break;
        case 2101: p.valorCompra = 3500; break;
        case 2201: p.valorCompra = 1200; break;
        case 2301: p.valorCompra = 2900; break;
        case 2401: p.valorCompra = 4500; break;
        default: p.valorCompra = 0; break;
    }
    p.valorVenta = p.valorCompra * 1.3f;
    vectorProductos[*contProductos] = p;
    (*contProductos)++;
}

// Funcion de ayuda para descontar stock de un producto
int deductProductStock(int *contProductos, Producto vectorProductos[], int idProducto, int cantidad){
    int total = totalStockProducto(*contProductos, vectorProductos, idProducto);
    if(cantidad > total) return 0;
    int restante = cantidad;
    for(int i = 0; i < (*contProductos) && restante > 0; i++){
        if(vectorProductos[i].idProducto != idProducto) continue;
        int disponible = vectorProductos[i].CantidadProducto;
        if(disponible <= 0) continue;
        if(disponible <= restante){
            restante -= disponible;
            vectorProductos[i].CantidadProducto = 0;
        } else {
            vectorProductos[i].CantidadProducto -= restante;
            restante = 0;
        }
    }
    // eliminar productos que no tienen cantidad
    for(int i = 0; i < (*contProductos); i++){
        if(vectorProductos[i].CantidadProducto <= 0){
            eliminarProductos(contProductos, vectorProductos, i);
            i--;
        }
    }
    return 1;
}

//FINAL FUNCIONES VENTA - STOCK

int actualizarVenta(Venta vectorVentas[], int *contVentas, int contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    if((*contVentas) == 0){
        printf("\nNinguna venta ha sido registrada.\n\n");
        int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return 0;
    }

    int idBuscar;
    printf("--------- Actualizar Venta ---------\n");
    printf("\nIngrese ID de Venta: ");
    scanf("%d", &idBuscar);

    int idx = -1;
    for(int i = 0; i < (*contVentas); i++){
        if(vectorVentas[i].idVenta == idBuscar){
            idx = i; break;
        }
    }
    if(idx == -1){
        printf("\nVenta no encontrada.\n");
        int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return 0;
    }

    Venta *v = &vectorVentas[idx];
    int opcion = 1;
    while(opcion != 0){
        LIMPIARPANTALLA;
        printf("--------- Editando Venta #%d ---------\n", v->idVenta);
        printf("1. Cambiar producto/cantidad\n");
        printf("2. Cambiar fecha\n");
        printf("0. Atras\n");
        printf("\nIngrese la opcion: ");
        scanf("%d", &opcion);
        LIMPIARPANTALLA;
        switch(opcion){
            case 0:
                break;
            case 1:{
                
                char nombreActual[20];
                switch(v->idProducto){
                    case 1101: strcpy(nombreActual, "Router"); break;
                    case 1201: strcpy(nombreActual, "Antena"); break;
                    case 1301: strcpy(nombreActual, "Estabilizador"); break;
                    case 2101: strcpy(nombreActual, "Cable UTP"); break;
                    case 2201: strcpy(nombreActual, "Conector RJ45"); break;
                    case 2301: strcpy(nombreActual, "Grapas"); break;
                    case 2401: strcpy(nombreActual, "Amarras"); break;
                    default: strcpy(nombreActual, "Otro"); break;
                }
                printf("\n--- Producto Actual ---\n");
                printf("ID: %d - %s (Cantidad: %d) [ACTUAL]\n\n", v->idProducto, nombreActual, v->cantidadVendida);

                // Mostrar productos disponibles con sus IDs
                printf("--- Productos Disponibles para Cambiar ---\n");
                for(int k = 0; k < (*contProductos); k++){
                    char nombre[20];
                    switch(vectorProductos[k].idProducto){
                        case 1101: strcpy(nombre,"Router"); break;
                        case 1201: strcpy(nombre,"Antena"); break;
                        case 1301: strcpy(nombre,"Estabilizador"); break;
                        case 2101: strcpy(nombre,"Cable UTP"); break;
                        case 2201: strcpy(nombre,"Conector RJ45"); break;
                        case 2301: strcpy(nombre,"Grapas"); break;
                        case 2401: strcpy(nombre,"Amarras"); break;
                        default: strcpy(nombre,"Otro"); break;
                    }
                    printf("%d. %s (ID: %d) - Cantidad Disponible: %d\n", k+1, nombre, vectorProductos[k].idProducto, vectorProductos[k].CantidadProducto);
                }
                
                int nuevoIdProducto;
                int nuevaCantidad;
                printf("\nID producto nuevo: ");
                scanf("%d", &nuevoIdProducto);
                printf("\nCantidad nueva: ");
                scanf("%d", &nuevaCantidad);

                if(nuevaCantidad <= 0){
                    printf("\nCantidad invalida.\n");
                    int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                    break;
                }

                int viejoId = v->idProducto;
                int viejaCantidad = v->cantidadVendida;

                int disponibleNuevo = totalStockProducto(*contProductos, vectorProductos, nuevoIdProducto);
                int efectivoDisponible = disponibleNuevo + (nuevoIdProducto == viejoId ? viejaCantidad : 0);

                if(nuevaCantidad > efectivoDisponible){
                    printf("\nStock insuficiente. Disponible (considerando devolución): %d\n", efectivoDisponible);
                    int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                    break;
                }

                if(nuevoIdProducto == viejoId){
                    if(nuevaCantidad > viejaCantidad){
                        int aDescontar = nuevaCantidad - viejaCantidad;
                        if(!deductProductStock(contProductos, vectorProductos, nuevoIdProducto, aDescontar)){
                            printf("\nError al descontar stock.\n");
                            int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                            break;
                        }
                    } else if(nuevaCantidad < viejaCantidad){
                        int aRestock = viejaCantidad - nuevaCantidad;
                        restockProduct(contProductos, vectorProductos, nuevoIdProducto, aRestock);
                    }
                } else {
                    restockProduct(contProductos, vectorProductos, viejoId, viejaCantidad);
                    if(!deductProductStock(contProductos, vectorProductos, nuevoIdProducto, nuevaCantidad)){
                        if(!deductProductStock(contProductos, vectorProductos, viejoId, viejaCantidad)){
                            printf("\nError al restaurar stock original. Revisar inventario.\n");
                        }
                        printf("\nStock insuficiente en el producto nuevo.\n");
                        int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                        break;
                    }
                }

                // actualizar valor total (obtener precio unitario)
                float precioUnitario = 0;
                for(int j = 0; j < (*contProductos); j++){
                    if(vectorProductos[j].idProducto == nuevoIdProducto){
                        precioUnitario = vectorProductos[j].valorVenta;
                        break;
                    }
                }
                if(precioUnitario == 0){
                    switch(nuevoIdProducto){
                        case 1101: precioUnitario = 38000*1.3f; break;
                        case 1201: precioUnitario = 145000*1.3f; break;
                        case 1301: precioUnitario = 25000*1.3f; break;
                        case 2101: precioUnitario = 3500*1.3f; break;
                        case 2201: precioUnitario = 1200*1.3f; break;
                        case 2301: precioUnitario = 2900*1.3f; break;
                        case 2401: precioUnitario = 4500*1.3f; break;
                        default: precioUnitario = 0; break;
                    }
                }

                v->idProducto = nuevoIdProducto;
                v->cantidadVendida = nuevaCantidad;
                v->valorTotal = nuevaCantidad * precioUnitario;

                printf("\nVenta actualizada correctamente.\n");
                int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                break;
            }
            case 2:{
                printf("\nNueva Fecha (DD MM AAAA): ");
                scanf("%d %d %d", &v->fechaVenta.dia, &v->fechaVenta.mes, &v->fechaVenta.ano);
                printf("\nFecha actualizada.\n");
                int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                break;
            }
            default:{
                printf("\nOpcion invalida.\n");
                int pausa; printf("\nDigite 0 para continuar..."); scanf("%d", &pausa);
                break;
            }
        }
    }
    LIMPIARPANTALLA;
    return 1;
}

void eliminarVenta(int *contVentas, Venta vectorVentas[], int posicion){
    for(int i = posicion; i<(*contVentas)-1; i++){
        vectorVentas[i] = vectorVentas[i+1];
    }
    printf("\nVenta eliminado correctamente. \n\n");
    int pausa;
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
    (*contVentas)--;
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

    int valorrouters=0;
    int valorestabilizador=0;
    int valorantenas=0;
    int valorutp=0;
    int valorrj45=0;
    int valorgrapas=0;
    int valoramarras=0;

    float porcentualInsumos=0;
    float porcentualEquipos=0;
    float valorInsumos=0;
    float valorEquipos=0;
    float ValorToal=0;
    
    if((contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        }
    for(int i = 0; i < contProductos; i++){
        switch(vectorProductos[i].idProducto){
            case 1101:
            controuters=controuters+vectorProductos[i].cantidadProducto;
            valorrouters=controuters*vectorProductos[i].valorCompra;
            break;
            case 1201:
            contantenas=contantenas+vectorProductos[i].cantidadProducto;
            valorantenas=contantenas*vectorProductos[i].valorCompra;
            break;
            case 1301:
            contestabilizador=contestabilizador+vectorProductos[i].cantidadProducto;
            valorestabilizador=contestabilizador*vectorProductos[i].valorCompra;
            break;
            case 2101:
            contutp=contutp+vectorProductos[i].cantidadProducto;
            valorutp=contutp*vectorProductos[i].valorCompra;
            break;
            case 2201:
            contrj45=contrj45+vectorProductos[i].cantidadProducto;
            valorrj45=contrj45*vectorProductos[i].valorCompra;
            break;
            case 2301:
            contgrapas=contgrapas+vectorProductos[i].cantidadProducto;
            valorgrapas=contgrapas*vectorProductos[i].valorCompra;
            break;
            case 2401:
            contamarras=contamarras+vectorProductos[i].cantidadProducto;
            valoramarras=contamarras*vectorProductos[i].valorCompra;
            break;
        }
       
    }

    //Porcentual de cada tipo de producto
    
    valorInsumos = valorutp+valorrj45+valorgrapas+valoramarras;
    valorEquipos = valorestabilizador+valorantenas+valorrouters;
    ValorToal = valorInsumos+valorEquipos;
    porcentualInsumos =(valorInsumos/ValorToal)*100;
    porcentualEquipos =(valorEquipos/ValorToal)*100;
   
    // DATOS PARA EL GRÁFICO

    // Encontrar el valor máximo en los datos, necesario para la altura del gráfico

    int datos[] = {valorrouters/100000, valorantenas/100000, valorestabilizador/100000,valorutp/100000, valorrj45/100000, valorgrapas/100000, valoramarras/100000};
    int num_barras = sizeof(datos) / sizeof(datos[0]);
    int max = datos[0];
    for (int i = 1; i < num_barras; i++) {
        if (datos[i] > max) {
            max = datos[i];
        }
    }
       
    printf("+------------------------------------------------------------------------------+\n");
    printf("|                            INFORME DE INVENTARIO                             |\n");
    printf("+-------------------------+-------------------------+--------------------------+\n");
    printf("|       Producto          |          Cantidad       |           Valor          |\n");
    printf("+-------------------------+-------------------------+--------------------------+\n");
    printf("|        Routers          |            %3d          |        %7d           |\n",controuters, valorrouters);
    printf("|     Estabilizador       |            %3d          |        %7d           |\n",contestabilizador, valorestabilizador);
    printf("|        Antenas          |            %3d          |        %7d           |\n",contantenas,valorantenas);
    printf("|       Cable UTP         |            %3d          |        %7d           |\n",contutp,valorutp);
    printf("|     Conector RJ45       |            %3d          |        %7d           |\n",contrj45,valorrj45);
    printf("|        Grapas           |            %3d          |        %7d           |\n",contgrapas,valorgrapas);
    printf("|        Amarras          |            %3d          |        %7d           |\n",contamarras,valoramarras);
    printf("+-------------------------+-------------------------+--------------------------+\n");
    printf("|                         TOTAL                     |       %8.0f           |\n",ValorToal);
    printf("+---------------------------------------------------+--------------------------+\n");
    printf("|                              Insumos Vs Equipos                              |\n");
    printf("+-------------------------+-------------------------+--------------------------+\n");
    printf("|     Total Insumos       |           %7.0f       |           %2.2f%%         |\n",valorInsumos,porcentualInsumos);
    printf("|     Total Equipos       |           %7.0f       |           %2.2f%%         |\n",valorEquipos,porcentualEquipos);
    printf("+-------------------------+-------------------------+--------------------------+\n");
    printf("|                    Grafico de Activos (En en pesos 100K)                     |\n");
    printf("+------------------------------------------------------------------------------+\n");

    // Bucle exterior: Itera desde la altura máxima hacia abajo (de arriba a abajo)
    for (int nivel_actual = max; nivel_actual > 0; nivel_actual--) {
        // Opcional: Imprime el número del nivel/eje Y
        printf("|          %2d | ", nivel_actual);

        // Bucle interior: Itera sobre cada barra en la fila actual
        for (int i = 0; i < num_barras; i++) {
            // Si el valor de la barra es igual o mayor que el nivel actual, imprime un caracter
            if (datos[i] >= nivel_actual) {
                printf(" |XX| ");
            } else {
                // Si no, imprime espacios vacíos para esa posición
                printf("      ");
            }
        }
        printf("                     |\n"); // Salto de línea para pasar al siguiente nivel inferior
    }

    // Opcional: Imprime el eje X y etiquetas en la parte inferior
        printf("|          ---+");
    for (int i = 0; i < num_barras; i++) {
        printf("------");
    }
    printf("                      |\n|             |");
    for (int i = 0; i < num_barras; i++) {
        // Imprime etiquetas simples (A, B, C...) o índices (1, 2, 3...)
        printf(" %3c  ", 'A' + i);
    }
    printf("                      |\n");
    printf("+------------------------------------------------------------------------------+\n");
    printf("|          A = Routers                     E = Conector RJ45                   |\n");
    printf("|          B = Antenas                     F = Grapas                          |\n");
    printf("|          C = Estabilizador               G = Amarras                         |\n");
    printf("|          D = Cable UTP                                                       |\n");
    printf("+------------------------------------------------------------------------------+\n");
    
}

void actualizarPrecios(){

}
//FINAL FUNCION ESPECIAL

//FUNCION RECURSIVA - INGRESO TOTAL

float calcularIngresosRecursiva(Venta vectorVentas[], int contVentas, int indice){
    // Caso base cuando sea el fin del vector
    if(indice >= contVentas){ 
        return 0;
    }
    
    // Sumar la venta actual con las siguientes
    return vectorVentas[indice].valorTotal + calcularIngresosRecursiva(vectorVentas, contVentas, indice + 1);
}

//FIN FUNCION RECURSIVA - INGRESO TOTAL

void menuGestionarProductos(){
    printf("--------- Gestion Productos ---------\n");
    printf("\n1. Ingresar Productos. ");
    printf("\n2. Mostrar Productos. ");
    printf("\n3. Actualizar Productos. ");
    printf("\n4. Eliminar Productos. ");
    printf("\n5. Informe Inventario. ");
    printf("\n\n0. Atras");
    printf("\n\n-----------------------------------");
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
    int pausa;
    printf("+--------+----------+-------------+------------+-----------+--------+----------+\n");
    printf("|   ID   |   Tipo   |   Nombre    |Valor Compra|Valor Venta|Cantidad|    Mes   |\n"); 
    printf("+--------+----------+-------------+------------+-----------+--------+----------+\n");
    if((*contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        }
    for(int i = 0; i < (*contProductos); i++){
        mostrarProductos(vectorProductos[i], i+1);
    }
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
}

int submenuActualizarProductos(int *contProductos, Producto vectorProductos[]){
    Producto elProducto;
    if((*contProductos)==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        return 0;
    }
	int prod;
    int id;
	printf("\n--------- Actualizar Producto ---------\n");
    printf(" ID     Activo\n");
    printf("_________________\n");
    printf("1101    Router\n");
    printf("1201    Antena\n");
    printf("1301    Estabilizador\n");
    printf("2101    Cable UTP\n");
    printf("2201    Conector RJ45\n");
    printf("2301    Grapas\n");
    printf("2401    Amarras\n");
    printf("_________________\n");
    printf("\n\n Ingrese una opcion. ");
    scanf("%d", &prod);
    LIMPIARPANTALLA

    printf("\n\nEnumerador  ID      Producto        Fecha\n");
    printf("_____________________________________________\n");
	for(int i = 0; i < (*contProductos); i++){
        if(vectorProductos[i].idProducto==prod){
            
            switch (vectorProductos[i].idProducto){
                case 1101:
                printf("\n    %2d.    %d    Router          %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 1201:
                printf("\n    %2d.    %d    Antena          %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 1301:
                printf("\n    %2d.    %d    Estabilizador   %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2101:
                printf("\n    %2d.    %d    Cable UTP       %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2201:
                printf("\n    %2d.    %d    Conector RJ45   %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2301:
                printf("\n    %2d.    %d    Grapas          %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2401:
                printf("\n    %2d.    %d    Amarras         %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;
            }
        }
        
    }
     printf("\n_____________________________________________\n");    
    printf("\nIngrese el enumerador del Producto: ");
    scanf("%d", &id);	
	LIMPIARPANTALLA;
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
    int prod;
	int id;
	int id;
    printf("\n--------- Eliminar Producto ---------\n");

    printf(" ID     Activo\n");
    printf("_________________\n");
    printf("1101    Router\n");
    printf("1201    Antena\n");
    printf("1301    Estabilizador\n");
    printf("2101    Cable UTP\n");
    printf("2201    Conector RJ45\n");
    printf("2301    Grapas\n");
    printf("2401    Amarras\n");
    printf("_________________\n");
    printf("\n\n Ingrese una opcion. ");
    scanf("%d", &prod);
    LIMPIARPANTALLA

    printf("\n\nEnumerador  ID      Producto        Fecha\n");
    printf("_____________________________________________\n");
    for(int i = 0; i < (*contProductos); i++){
        if(vectorProductos[i].idProducto==prod){
            
            switch (vectorProductos[i].idProducto){
                case 1101:
                printf("\n    %2d.    %d    Router          %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 1201:
                printf("\n    %2d.    %d    Antena          %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 1301:
                printf("\n    %2d.    %d    Estabilizador   %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2101:
                printf("\n    %2d.    %d    Cable UTP       %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2201:
                printf("\n    %2d.    %d    Conector RJ45   %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2301:
                printf("\n    %2d.    %d    Grapas          %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;

                case 2401:
                printf("\n    %2d.    %d    Amarras         %2d/%2d/%d", i+1, vectorProductos[i].idProducto, vectorProductos[i].fechaCompra.dia,vectorProductos[i].fechaCompra.mes,vectorProductos[i].fechaCompra.ano);
                break;
            }
        }
        
    }
    printf("\n_____________________________________________\n");    
    printf("\nIngrese el enumerador del Producto: ");
    scanf("%d", &id);
    LIMPIARPANTALLA;
    int productoEncontrado = -1;
    int i;
    int posicion;
    if(id<=(*contProductos)){
        productoEncontrado = 1;
        posicion = id-1;
        printf("Producto encontrado.\n");
        int pausa;
        printf("\nDigite 0 para confirmar la eliminacion del producto...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        eliminarProductos(contProductos, vectorProductos, posicion);
        printf("\nProducto eliminado correctamente. \n\n");
        LIMPIARPANTALLA;
    }
    LIMPIARPANTALLA;
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
    static int generadorID_Venta_local = 0;
    Venta miVenta = crearVenta(&generadorID_Venta_local, contVentas, contClientes, vectorClientes, contProductos, vectorProductos);
    if (*contVentas > 0 && miVenta.idVenta != 0) {
        vectorVentas[(*contVentas) - 1] = miVenta;     
    }
    LIMPIARPANTALLA;
}

void submenuMostrarVenta(Venta vectorVentas[], int *contVentas, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    int pausa;
    if((*contVentas)==0){
        printf("\nNinguna venta ha sido registrada.\n\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return;
        }
    for(int i = 0; i < (*contVentas); i++){
        mostrarVentas(vectorVentas[i], i, vectorProductos);
    }
    float totalIngresos = calcularIngresosRecursiva(vectorVentas, *contVentas, 0);
    printf("\n----------------------------------|");
    printf("\nINGRESOS TOTALES: $%.2f       |\n", totalIngresos);
    printf("----------------------------------|\n");
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
}

void submenuActualizarVenta(Venta vectorVentas[], int *contVentas, int contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    actualizarVenta(vectorVentas, contVentas, contClientes, vectorClientes, contProductos, vectorProductos);
    LIMPIARPANTALLA;
}

void submenuEliminarVenta(int *contVentas, Venta vectorVentas[]){
    if((*contVentas)==0){
        printf("\nNinguna venta ha sido registrada.\n\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return;
    }

    int id;
    printf("\n--------- Eliminar Venta ---------\n");
    printf("\nIngrese el ID de la venta: ");
    scanf("%d", &id);
    LIMPIARPANTALLA;
    int ventaEncontrada = -1;
    int i;
    int posicion;
    for(i=0; i<(*contVentas); i++){
        if(vectorVentas[i].idVenta == id){
            ventaEncontrada = 1;
            posicion = i;
            int pausa;
            printf("\n--------- Eliminacion de Venta ---------\n");
            printf("\n0. Cancelar. ");
            printf("\n1. Confirmar. ");
            printf("\n\n----------------------------------------");
            printf("\nIngrese la opcion: ");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            switch(pausa){
                case 0:
                    printf("La eliminacion fue cancelada.\n");
                    printf("\n\nDigite 0 para continuar...");
                    scanf("%d", &pausa);
                    LIMPIARPANTALLA;
                    break;
                case 1:
                    eliminarVenta(contVentas, vectorVentas, posicion);
                    break;
            }
            break;
        }
        LIMPIARPANTALLA;
    }
    if(ventaEncontrada == -1){
        printf("\nVenta no encontrada.\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);  
        LIMPIARPANTALLA;
    }
}

void gestionarMenus(int opcion, Cliente vectorClientes[], Producto vectorProductos[], Venta vectorVentas[], int *contClientes,int *contProductos, int *contVentas, int *contVectorproductos){
    Cliente miCliente;
    switch(opcion){
            case menuClientes: {
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
            case menuProductos:{
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
							int pausa;
                            printf("\nDigite 0 para continuar...");
                            scanf("%d", &pausa);
                            break;
                        case opcionActualizarProductos:
                            submenuActualizarProductos(contProductos, vectorProductos);
                            break;
                        case opcionEliminarProductos:
                            submenuEliminarProductos(contProductos, vectorProductos);
                            break;
                        case opcionInformeInventario:
                            informeInventario(*contProductos, vectorProductos);
							printf("\nDigite 0 para continuar...");
                            scanf("%d", &pausa);
                            break;
                    }
                }
            break;
            }

            case menuVentas:{
                int opcionGestionarVentas = 1;
                while(opcionGestionarVentas!=0){
                    menuGestionarVentas();
                    scanf("%d", &opcionGestionarVentas);
                    LIMPIARPANTALLA;
                    switch(opcionGestionarVentas){
                        case opcionCrearVentas:
                            submenuCrearVenta(vectorVentas, contVentas, *contClientes, vectorClientes, contProductos, vectorProductos);
                            break;
                        case opcionMostrarVentas:
                            submenuMostrarVenta(vectorVentas, contVentas, vectorProductos);
                            break;
                        case opcionActualizarVentas:
                            submenuActualizarVenta(vectorVentas, contVentas, *contClientes, vectorClientes, contProductos, vectorProductos);
                            break;
                        case opcionEliminarVentas:
                            submenuEliminarVenta(contVentas, vectorVentas);
                            break;
                    }
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
    cargarClientes(vectorClientes, &contClientes);
    cargarVentas(vectorVentas, &contVentas);
    cargarProductos(vectorProductos, &contProductos);
    int opcion = 1;
    while(opcion!=0){
        LIMPIARPANTALLA;
        menuPrincipal();
        scanf("%d", &opcion);
        LIMPIARPANTALLA;
        gestionarMenus(opcion, vectorClientes, vectorProductos, vectorVentas, &contClientes,&contProductos, &contVentas, &contVectorproductos);
    }
}

