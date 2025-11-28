#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPIARPANTALLA system("clear"); //cls 
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
    int cantidadVenta;
    Fecha fechaCompra;
} Producto;


typedef struct {
    int idCliente;
    char nombreCliente[50];
    Producto producto[100];
    float totalVenta;
    Fecha fechaDeVenta;
    int idVenta;
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
    char c__buffer2[20];
    fgets(c__buffer2, 20, stdin);
   
    switch(elProducto.tipoProducto){
        printf("\nNombre del Producto: "); 
        
        case 1:
        printf("\n1. Router. ");
        printf("\n2. Antena. ");
        printf("\n3. Estabilizador. ");
        printf("\n\n Ingrese una opcion. ");
        scanf("%d", &elProducto.nombreProducto);
        char c__buffer2[20];
        fgets(c__buffer2, 20, stdin);
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


    printf("Cantidad del producto: ");
    scanf("%d", &elProducto.CantidadProducto);
    
    printf("Fecha de Compra: ");
    scanf("%c", &elProducto.fechaCompra);
       
    
    printf("\nProducto registrado exitosamente. \n\n");
    return elProducto;
    
}


void mostrarProductos(Producto elProducto, int cont){
        printf("\n\n--------- Producto #%d ---------", cont);
        printf("\nID : %d", elProducto.idProducto);
        if(elProducto.tipoProducto==1){
            printf("\nTipo: Equipo");
        }else{
            printf("\nTipo: Insumo");
        }
                
        switch (elProducto.idProducto){
        case 1101:
        printf("\nNombre: Router");
        break;

        case 1201:
        printf("\nNombre: Antena");
        break;

        case 1301:
        printf("\nNombre: Estabilizador");
        break;

        case 2101:
        printf("\nNombre: Cable UTP");
        break;

        case 2201:
        printf("\nNombre: Conector RJ45");
        break;

        case 2301:
        printf("\nNombre: Grapas");
        break;

        case 2401:
        printf("\nNombre: Amarras");
        break;
    }
        printf("\nValor Compra: %d", elProducto.valorCompra);
        printf("\nValor Venta: %.0f", elProducto.valorVenta);
        printf("\nCantidad: %d", elProducto.CantidadProducto);
        printf("\nFecha de Compra: %f\n\n", elProducto.fechaCompra);
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

void eliminarProductos(int *contProductos, Producto vectorProductos[], int posicion){
    for(int i = posicion; i<(*contProductos)-1; i++){
        vectorProductos[i] = vectorProductos[i+1];
    }
    printf("\nProducto eliminado correctamente. \n\n");
    int pausa;
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
    (*contProductos)--;
}

//Funciones Venta

//Funcion para crear una venta
Venta crearVenta(int *contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[], int *contVentas, int *contVectorproductos){
    //Crear venta
    Venta miVenta;

    int idCliente = 0;
    int pausa;
    int igual = 0;
    int idProducto;
    int cantidadVenta = 0;
    char cerrarVenta = 'N';

    printf("--------- Crear Venta ---------\n");

    //Validar que haya clientes creados
    if (*contClientes == 0) {
        printf("\nAun no hay clientes creados, debes crear uno desde el menu principal\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        miVenta.idVenta = 0;
        return miVenta;
    }

    //Validar que hay productos creados
     if (*contProductos == 0) {
        printf("\nAun no hay productos creados, debes crear al menos uno\n");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        miVenta.idVenta = 0;
        return miVenta;
    }

    //Mostrar clientes creados

    //Ingresar ID cliente
    printf("Ingresa el ID del cliente:\n");
    scanf("%d", &idCliente);
    char c__buffer[20];
    fgets(c__buffer, 20, stdin);

    //Repetir hasta que se ingrese un ID de cliente valido
    while(igual == 0) {
        //Validar que si exista un cliente con ese ID
        for (int i = 0 ; i < *contClientes && igual == 0 ; i++) {
            if (vectorClientes[i].idCliente == idCliente) {
                //Asignar el nombre del cliente a la venta
                strcpy(miVenta.nombreCliente, vectorClientes[i].nombreCompleto);
                LIMPIARPANTALLA;
                //Ingresar fecha
                printf("\nIngresa la fecha para la venta:\n");
                //ingresar dia
                printf("\nIngresa el dia:\n");
                scanf("%d", &miVenta.fechaDeVenta.dia);
                c__buffer[20];
                fgets(c__buffer, 20, stdin);

                //ingresar mes
                printf("\nIngresa el mes:\n");
                scanf("%d", &miVenta.fechaDeVenta.mes);
                c__buffer[20];
                fgets(c__buffer, 20, stdin);

                //ingresar año
                printf("\nIngresa el anio:\n");
                scanf("%d", &miVenta.fechaDeVenta.ano);
                c__buffer[20];
                fgets(c__buffer, 20, stdin);

                igual = 1;
            }
        }

        if (igual == 0) {
            printf("\nNo existe cliente con ese ID\n");
            printf("Ingrese un ID valido:\n");
            scanf("%d", &idCliente);
            c__buffer[20];
            fgets(c__buffer, 20, stdin);
        }
    }

    //Si el ID del cliente es valido, continuamos con el programa
    if (igual == 1) {

        //Repetimos mientras no se cierre la venta
        while (cerrarVenta != 'S' && cerrarVenta != 's') {

            //Validamos que aun hayan productos en stock
            if (*contProductos == 0) {
                printf("\nYa no quedan mas productos en stock, la venta se cerrara.\n");

                //Si cerramos la venta, le damos su respectivo ID
                miVenta.idVenta = *contVentas+1;

                printf("\nVenta creada de manera satisfactoria\n");
                printf("\nDigite 0 para continuar...");
                scanf("%d", &pausa);

                return miVenta;
            }

            miVenta.idCliente = idCliente;
            printf("\nProductos disponibles:\n");
            submenuMostrarProductos(*contProductos, vectorProductos);
            printf("\nIngrese el ID del producto\n");
            scanf("%d", &idProducto);
            c__buffer[20];
            fgets(c__buffer, 20, stdin);

    
            igual = 0;
        
            //Repetir hasta que se ingrese un ID valido
            while (igual == 0) {
                //validar que si exista un producto con ese ID
                for (int i = 0 ; i < *contProductos && igual == 0 ; i++) {
                    if (vectorProductos[i].idProducto == idProducto && vectorProductos[i].CantidadProducto > 0) {

                        //Guardamos los datos del producto
                        miVenta.producto[*contVectorproductos].nombreProducto = vectorProductos[i].nombreProducto;
                        miVenta.producto[*contVectorproductos].tipoProducto = vectorProductos[i].tipoProducto;
                        miVenta.producto[*contVectorproductos].valorVenta = vectorProductos[i].valorVenta;

                        igual = 1;
                    }
                }

                //En caso de que no exista el ID, volver a preguntar
                if (igual == 0) {
                    printf("\nDebes ingresar un ID de producto valido y que tenga cantidad en stock\n");
                    scanf("%d", &idProducto);
                    c__buffer[20];
                    fgets(c__buffer, 20, stdin);
                }
            }

            //Ingresar el ID del producto
            miVenta.producto[*contVectorproductos].idProducto = idProducto;
            printf("\nIngrese la cantidad: \n");
            scanf("%d", &cantidadVenta);
            c__buffer[20];
            fgets(c__buffer, 20, stdin);

            igual = 0;

            //Repetimos hasta que se ingrese una cantidad adecuada
            while (igual == 0) {

                //Validamos que la cantidad sea menor o igual a lo que hay en stock
                for (int i = 0 ; i < *contProductos && igual == 0 ; i++) {
                    if (vectorProductos[i].idProducto == idProducto) {
                        if (cantidadVenta <= vectorProductos[i].CantidadProducto && cantidadVenta > 0) {
                            miVenta.producto[*contVectorproductos].cantidadVenta = cantidadVenta;
                            igual = 1;

                            //Restamos la cantidad de venta a la cantidad del producto en stock
                            vectorProductos[i].CantidadProducto -= cantidadVenta;
                            if (vectorProductos[i].CantidadProducto == 0) {
                                printf("\nEl producto ya no tiene unidades en stock\n");
                                eliminarProductos(contProductos, vectorProductos, i);
                            }
                        } else {
                            printf("\nNo existe esa cantidad, elige otro monto: \n");
                            scanf("%d", &cantidadVenta);
                            c__buffer[20];
                            fgets(c__buffer, 20, stdin);
                        }
                    }
                }
            }

            //Aumentamos el contador de los productos de la venta
            (*contVectorproductos)++;

            LIMPIARPANTALLA;
            printf("\nQuieres continuar igresando mas productos, o cerramos la venta?\n");
            printf("presiona S, si quieres cerrar la venta o presiona cualquier tecla para seguir registrando\n");
            scanf("%s", &cerrarVenta);
            c__buffer[20];
            fgets(c__buffer, 20, stdin);
        }

        //Si cerramos la venta, le damos su respectivo ID
        miVenta.idVenta = *contVentas+1;
        printf("\nVenta creada de manera satisfactoria\n");

        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);

        return miVenta;

    //Si no existe un ID de cliente valido, volver al menu    
    } else {
        printf("\nNo hay ningun cliente con ese ID");
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        miVenta.idVenta = 0;
        return miVenta;
    }
}

void mostrarVentas(Venta miVenta, int cont, int contVectorproductos){
    if (miVenta.idVenta != 0) {
        float totalVentaProductos = 0;

        printf("--------- Venta #%d ---------", cont);
        printf("\nID Venta: %d", miVenta.idVenta);
        printf("\nID Cliente: %d", miVenta.idCliente);
        printf("\nCliente: %s", miVenta.nombreCliente);
        printf("\nFecha Venta: %d-%d-%d\n", miVenta.fechaDeVenta.dia, miVenta.fechaDeVenta.mes, miVenta.fechaDeVenta.ano);
        printf("\nProductos:\n");

        //Recorremos todos los productos de la venta
        for (int i = 0 ; i < contVectorproductos ; i++) {
            if (miVenta.producto[i].idProducto != 0) {
                printf("\nID producto: %d", miVenta.producto[i].idProducto);
                printf("\nNombre producto: %d", miVenta.producto[i].nombreProducto);
                printf("\nTipo producto: %d", miVenta.producto[i].tipoProducto);
                printf("\nCantidad producto: %d", miVenta.producto[i].cantidadVenta);
                totalVentaProductos += miVenta.producto[i].cantidadVenta * miVenta.producto[i].valorVenta;
                printf("\nTotal producto: %f\n", miVenta.producto[i].cantidadVenta * miVenta.producto[i].valorVenta);
            }
        }

        printf("\n\nTotal venta: %f\n", totalVentaProductos);
    }
}

Venta actualizarVenta(Venta miVenta, int contVenta){
     int opcion = 1;
    while(opcion != 0){
        printf("\n--------- Actualizar Productos Venta ---------\n");
        printf("\n1. Cambiar producto. ");
        printf("\n2. Eliminar un producto. ");
        printf("\n\n0. Atras");
        printf("\n\n----------------------------------------");
        printf("\nIngrese la opcion: ");
        scanf("%d", &opcion);
        LIMPIARPANTALLA;
        char c__buffer2[20];
        fgets(c__buffer2, 20, stdin);
        switch(opcion){
            case 0:
                return miVenta;
                break;
            case 1:
                mostrarVentas(miVenta, contVenta, int contVectorproductos);
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
}

//Menus

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

    //Funciones submenu (Para resolver las tareas una por una con funciones, no bloques de codigo gigantes)

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



void submenuMostrarProductos(int contProductos, Producto vectorProductos[]){
    LIMPIARPANTALLA;
    if(contProductos==0){
        printf("\nNingun producto ha sido registrado.\n\n");
        }
    for(int i = 0; i < contProductos; i++){
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
            printf("\nDigite 0 para cancelar.");
            printf("\nDigite 0 para cancelar.");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            eliminarProductos(contProductos, vectorProductos, posicion);
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

//submenus Ventas

void submenuCrearVentas(Venta vectorVentas[], int *contVentas, int *contClientes, Cliente vectorClientes[], int *contProductos, Producto vectorProductos[], int *contVectorproductos){
    LIMPIARPANTALLA;
    Venta miVenta;
    miVenta = crearVenta(contClientes, vectorClientes, contProductos, vectorProductos, contVentas, contVectorproductos);
    if (miVenta.idVenta != 0) {
        vectorVentas[*contVentas] = miVenta;
        (*contVentas)++;
    }
    LIMPIARPANTALLA;
}

void submenuMostrarVentas(int contVentas, Venta vectorVentas[], int contVectorproductos){

    LIMPIARPANTALLA;
    if(contVentas==0){
        printf("\nNinguna venta ha sido registrada.\n\n");
    }

    for(int i = 0; i < contVentas; i++){
        mostrarVentas(vectorVentas[i], i+1, contVectorproductos);
    }

    int pausa;
    printf("\nDigite 0 para continuar...");
    scanf("%d", &pausa);
    LIMPIARPANTALLA;
}

void submenuActualizarVentas(int *contVentas, venta vectorVentas[]){
    LIMPIARPANTALLA;
    Venta miVenta;
    if((*contVentas)==0){
        printf("\nNo se ha registrado ninguna venta.\n\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
        return 0;
    }
    int id;
    printf("\n--------- Actualizar Venta ---------\n");
    printf("\nIngrese el ID de la venta: ");
    scanf("%d", &id);
    int ventaEncontrada = -1; //Si se encuentra la venta la variable es igual a 1, si es -1 no se encontro
    int i;
    for(i=0; i<(*contVentas); i++){
        if(vectorVentas[i].idVenta == id){ //Si el ID de la venta se encuentra en el vector Ventas entonces ventaEcontrada = 1
            ventaEncontrada = 1; //La venta se encontro
            int pausa;
            printf("\n\nVenta encontrada.\n");
            printf("\nDigite 0 para actualizar la informacion de los productos de la venta...");
            scanf("%d", &pausa);
            LIMPIARPANTALLA;
            miVenta = vectorVentas[i]; //Se encontro el vector de la venta a actualizar
            Venta ventaActualizada = actualizarVenta(miVenta); //La funcion devuelve la venta actualizado
            vectorVentas[i] = ventaActualizada; // la venta fue actualizada
            break;
        }
    }
    if(ventaEncontrada == -1){ //Si entra a este if es porque la venta no fue encontrada
        printf("\n\nVenta no encontrada.\n");
        int pausa;
        printf("\nDigite 0 para continuar...");
        scanf("%d", &pausa);
        LIMPIARPANTALLA;
    }
}

void gestionarMenus(int opcion, Cliente vectorClientes[], Producto vectorProductos[], Venta vectorVentas[], int *contClientes, int *contProductos, int *contVentas, int *contVectorproductos){
    Cliente miCliente;
    switch(opcion){
            case menuClientes:{
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
            }
            case menuProductos:;
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
                            submenuMostrarProductos(*contProductos, vectorProductos);
                            break;
                        case opcionActualizarProductos:
                            submenuActualizarProductos(contProductos, vectorProductos);
                            break;
                        case opcionEliminarProductos:
                            submenuEliminarProductos(contProductos, vectorProductos);
                            break;
                    }
                }
            break;

            case menuVentas:{
                int opcionGestionarVentas = 1;
                while(opcionGestionarVentas!=0){
                    menuGestionarVentas();
                    scanf("%d", &opcionGestionarVentas);
                    LIMPIARPANTALLA;
                    switch(opcionGestionarVentas){
                        case opcionCrearVentas:{
                            submenuCrearVentas(vectorVentas, contVentas, contClientes, vectorClientes, contProductos, vectorProductos, contVectorproductos);
                            break;
                        case opcionMostrarVentas:
                            submenuMostrarVentas(*contVentas, vectorVentas, *contVectorproductos);
                            break;
                        case opcionActualizarVentas:
                            submenuActualizarVentas(contVentas, vectorVentas);
                            break;
                        case opcionEliminarVentas:
                            
                            break;
                    }
                break;
                }
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


// En el codigo de eliminar, sale por pantalla que si esta seguro de eliminar, 0 para continuar, pero cual es la opcion para desistir de eliminar?
// toca vereificar las pausas porque como me quedo a mi en el "mostrar", no me gusto 
