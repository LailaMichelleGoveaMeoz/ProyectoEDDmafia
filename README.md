Descripción

Este proyecto consiste en la implementación de una estructura de datos tipo árbol binario en C++, utilizando una organización modular del código.

El programa hace uso de múltiples archivos fuente para separar responsabilidades, incluyendo la definición de nodos, la implementación del árbol y la ejecución principal. Además, utiliza un archivo externo en formato .csv como fuente de datos de entrada.

El objetivo del proyecto es demostrar el uso de estructuras dinámicas, específicamente árboles binarios, así como la correcta organización de un programa en múltiples archivos.

Estructura del Proyecto

El repositorio está organizado de la siguiente manera:

ProyectoEDDmafia/

├── bin/
│ └── data.csv
│
├── src/
│ ├── main.cpp
│ ├── node.cpp
│ ├── node.hpp
│ ├── tree.cpp
│ └── tree.hpp

Descripción de Archivos
main.cpp

Contiene la función principal del programa (main).
Se encarga de:

Iniciar la ejecución del programa
Gestionar la lectura del archivo de datos
Crear una instancia del árbol
Llamar a las funciones necesarias para procesar la información
node.hpp

Define la estructura del nodo del árbol binario.

Incluye:

El valor almacenado en el nodo
Punteros a los nodos hijo izquierdo y derecho
node.cpp

Implementa las funciones asociadas al nodo, como:

Constructor del nodo
Inicialización de valores y punteros
tree.hpp

Define la clase que representa el árbol binario.

Incluye:

La referencia al nodo raíz
Declaración de métodos para manipular el árbol
tree.cpp

Contiene la implementación de los métodos del árbol, tales como:

Inserción de nodos
Recorridos del árbol
Operaciones necesarias para procesar los datos cargados
data.csv

Archivo de entrada ubicado en la carpeta bin/.

Contiene los datos que serán utilizados por el programa
Los valores se leen y se utilizan para construir el árbol
Funcionamiento General

El programa sigue un flujo básico:

Se accede al archivo data.csv
Se leen los valores almacenados
Se construye un árbol binario utilizando dichos datos
Se ejecutan operaciones definidas en la clase Tree
Se muestran resultados en consola
Requisitos
Compilador de C++ compatible (g++)
Sistema operativo Windows, Linux o Mac
Consola o terminal
Compilación

Para compilar el proyecto, ubícate en la carpeta raíz y ejecuta:

g++ src/*.cpp -o programa

Ejecución

Una vez compilado, ejecutar:

./programa

Consideraciones
El programa depende de la existencia del archivo data.csv
La correcta ejecución depende del formato de los datos en el archivo
El código está organizado de forma modular para facilitar su comprensión
No se incluyen validaciones avanzadas de errores
Objetivo Académico

Este proyecto fue desarrollado con fines académicos para reforzar los siguientes conceptos:

Implementación de árboles binarios
Separación de código en múltiples archivos
Manejo básico de archivos
Autores
Laila Michelle Govea Meoz
Samantha Valentina Cubillán Gonzalez
