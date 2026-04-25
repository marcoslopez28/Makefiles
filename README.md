# Proyecto Makefile - Documentación de Makefile

## Descripción

En esta práctica se trabajó con Makefiles para comprender cómo ayudan a automatizar procesos de compilación, ejecución, limpieza y organización de proyectos de programación, ambos proyectos son detallados en este documento.

Primero se analizó el Makefile de ejemplo proporcionado en el repositorio del profesor, en la carpeta **julia**.

Después se desarrolló un proyecto llamado **Conversor de Temperatura para IoT**, en el cual se agregó un Makefile para automatizar la compilación, ejecución y limpieza del programa.

---

# Parte 1 - Análisis del Makefile de ejemplo (Julia)

## Breve explicación del proyecto

El proyecto de ejemplo "**julia**" genera el conjunto de Julia, es una representación gráfica matemática que después se convierte en una imagen `.png` utilizando gnuplot. Este ejemplo permite observar cómo un Makefile puede automatizar no solo la compilación de un programa, sino también su ejecución, la generación de archivos y la creación de resultados.

---

## Instrucciones para ejecutar

La ejecución se realizó en **MSYS2 UCRT64**, ésta es una herramienta que permite usar en Windows una terminal parecida a Linux, junto con compiladores y utilidades que normalmente no vienen instaladas en Windows, ya que este Makefile utiliza sintaxis estilo Linux como `./julia`, la cual funciona mejor en este entorno que en CMD de Windows.

**Nota:** Si no se tiene instalado MSYS2 o MinGW, se puede seguir esta guía oficial de Visual Studio Code para descargarlo y configurarlo correctamente en Windows:

https://code.visualstudio.com/docs/cpp/config-mingw

---

### Entrar a la carpeta

```bash
cd /julia
```

### Limpiar archivos generados

```bash
make clean
```

Este comando elimina:

* archivos objeto (`.o`)
* ejecutables `julia`
* archivos `.txt`
* imágenes `.png`

---

### Ejecutar el Makefile completo

```bash
make
```

Esto realiza automáticamente:

* compilación del programa
* creación del ejecutable
* ejecución del programa
* generación de archivos de datos
* creación de la imagen final usando gnuplot

---

### Ver archivos generados

```bash
ls
```

Una vez eecutado el Makefile, quí se puede observar la creación de:

* `main.o`
* `julia`
* `julia_set.txt`
* `julia_set.png`

---

## Resultados obtenidos

Durante la ejecución se observó:

```bash
Compiling
Linking
RUN
Plot
gnuplot julia_set.gp
```

Esto confirma que el Makefile automatizó correctamente todo el proceso.

En algunos casos, al final puede aparecer el mensaje:

```bash
xdg-open: command not found
```

Esto no afecta el resultado. El error únicamente ocurrió porque MSYS2 no tiene instalado el comando `xdg-open` para abrir imágenes automáticamente.

---

## Explicación del Makefile Julia

Este Makefile sirve para automatizar todo el proceso de generar el conjunto de Julia, desde compilar el programa hasta crear la imagen final.

CXX = g++

Indica que se usará el compilador de C++.

CXXFLAGS = -std=c++23 -O3

Son opciones de compilación:

-std=c++23 usa una versión moderna de C++
-O3 hace que el programa funcione de forma más rápida y optimizada
APP = julia

Es el nombre del programa final que se crea.

GP = julia_set.gp

Es el archivo que usa gnuplot para generar la gráfica.

all

Es la opción principal.
Cuando se escribe:

make

el Makefile compila, ejecuta el programa, genera la gráfica e intenta abrir la imagen automáticamente.

run

Ejecuta el programa:

./julia

Esto genera los datos necesarios para la gráfica.

plot

Usa gnuplot para convertir los datos en una imagen .png.

gnuplot julia_set.gp
open

Intenta abrir automáticamente la imagen generada.

clean

Borra archivos generados como:

.o
ejecutable julia
archivos .txt
imagen .png

Sirve para dejar limpio el proyecto.

---

# Parte 2 - Proyecto propio (Conversor de Temperatura para IoT)

## Breve explicación del proyecto

Se desarrolló un programa en lenguaje C que funciona como un conversor de temperatura sencillo.

Puede convertir:

1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
3. Celsius a Kelvin

Hice éste proyecto porque en aplicaciones IoT es común trabajar con sensores de temperatura, por lo que me pareció un ejemplo sencillo pero relacionado con la materia.

---

## Estructura del proyecto

```text
makefile-temperatura-iot/
├── main.c
└── Makefile
```

---

## Instrucciones para ejecutar

Desde la terminal de Windows, con MinGW se utilizó:

### Compilar

```bat
mingw32-make
```

Esto nos genero:

* `main.o`
* `temperatura.exe`

---

### Ejecutar

```bat
mingw32-make run
```

Ejemplo:

```text
=== Conversor de Temperatura IoT ===

1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
3. Celsius a Kelvin

Seleccione una opcion: 2

Ingrese la temperatura: 80

Resultado: 26.67 °C
```

---

### Limpiar archivos generados

```bat
mingw32-make clean
```

Elimina:

* `main.o`
* `temperatura.exe`

---

### Rebuild

```bat
mingw32-make rebuild
```

Este comando primero limpia y después recompila completamente el proyecto.

---

## Explicación del Makefile

Se utilizó:

```bat
type Makefile
```

para visualizar su contenido.

### Variables principales

### CC = gcc

Define el compilador de C.

### CFLAGS = -Wall -Wextra -O2

Opciones de compilación:

* `-Wall` activa advertencias importantes
* `-Wextra` activa advertencias adicionales
* `-O2` optimiza el programa

### TARGET = temperatura

Nombre del ejecutable final.

### SRCS = main.c

Archivo fuente principal.

### OBJS = $(SRCS:.c=.o)

Convierte automáticamente archivos `.c` en archivos `.o`.

---

## Targets principales

### all

Compila todo el proyecto.

### run

Compila y ejecuta automáticamente.

### clean

Elimina archivos generados.

### rebuild

Limpia y recompila completamente.

### help

Muestra ayuda en terminal.

---

## Resultados obtenidos

Se comprobó que el Makefile automatiza correctamente:

* compilación
* ejecución
* limpieza
* reconstrucción del proyecto

Esto facilita el desarrollo, reduce errores y mejora la organización del proyecto.

---

# Uso de .gitignore

Se agregó un archivo `.gitignore` para evitar subir archivos innecesarios al repositorio, como ejecutables, archivos objeto y temporales.

Contenido utilizado:

```text
*.exe
*.o
*.log
*.tmp
*.bak
.DS_Store
```

---

# Evidencias

En la carpeta **evidencia** se incluyen capturas de:

* ejecución del Makefile de ejemplo (julia)
* generación de archivos
* contenido del Makefile del ejemplo
* compilación del proyecto propio
* ejecución del conversor de temperatura
* uso de `clean`
* uso de `rebuild`
* estructura final del repositorio

De igual manera, las evidencias pueden ser utlizadas como una guía de uso de los proyectos, ya que se muestra el paso a paso de su ejecución

---

# Conclusión

El uso de Makefiles permite automatizar procesos importantes dentro de un proyecto de programación, especialmente en compilación, ejecución y limpieza de archivos.

Durante esta práctica se comprobó que tanto en el ejemplo del profesor como en mi proyecto, el Makefile ayuda a reducir trabajo manual, evitar errores y mantener una mejor organización.
