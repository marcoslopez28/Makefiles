# Proyecto Makefile - Uso y documentación de Makefiles

## Descripción

En esta práctica se trabajó con Makefiles para comprender cómo ayudan a automatizar procesos de compilación, ejecución, limpieza y organización de proyectos de programación.

Primero se analizó el Makefile de ejemplo proporcionado en el repositorio del profesor, específicamente en la carpeta **julia**.

Después se desarrolló un proyecto propio llamado **Conversor de Temperatura para IoT**, en el cual se implementó un Makefile para automatizar la compilación, ejecución y limpieza del programa.

---

# Parte 1 - Análisis del Makefile de ejemplo (Julia)

## Breve explicación del proyecto

El proyecto de ejemplo llamado **julia** genera el conjunto de Julia, una representación gráfica matemática que posteriormente se convierte en una imagen `.png` utilizando gnuplot.

Este ejemplo permite observar cómo un Makefile puede automatizar no solo la compilación de un programa, sino también su ejecución, la generación de archivos intermedios y la creación de resultados visuales.

---

## Instrucciones para ejecutar

La ejecución se realizó en **MSYS2 UCRT64**, ya que este Makefile utiliza sintaxis estilo Linux como `./julia`, la cual funciona mejor en este entorno que en CMD de Windows.

### Entrar a la carpeta

```bash
cd /c/Users/nonba/OneDrive/Documentos/IoT/Embedded-Systems-IoT/Makefiles/julia
```

### Limpiar archivos generados

```bash
make clean
```

Este comando elimina:

* archivos objeto (`.o`)
* ejecutable `julia`
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

Aquí se puede observar la creación de:

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

Al final apareció el mensaje:

```bash
xdg-open: command not found
```

Esto no afectó el resultado, ya que el archivo `julia_set.png` sí fue generado correctamente. El error únicamente ocurrió porque MSYS2 no tiene instalado el comando `xdg-open` para abrir imágenes automáticamente.

---

## Explicación del Makefile

Se utilizó el comando:

```bash
cat Makefile
```

para visualizar el contenido y analizar su estructura.

### Variables principales

### CXX = g++

Define el compilador de C++ utilizado.

### CXXFLAGS = -std=c++23 -O3

Opciones de compilación:

* `-std=c++23` utiliza el estándar moderno de C++
* `-O3` aplica una optimización alta del programa

### GP = julia_set.gp

Archivo de gnuplot utilizado para generar la gráfica.

### APP = julia

Nombre del ejecutable final.

---

## Targets principales

### all

Ejecuta automáticamente:

* run
* plot
* open

Es el target principal.

---

### run

Ejecuta el programa compilado:

```bash
./julia
```

---

### plot

Genera la imagen final con:

```bash
gnuplot julia_set.gp
```

---

### open

Intenta abrir automáticamente la imagen generada.

---

### clean

Elimina todos los archivos generados para dejar limpio el proyecto.

---

## Automatización lograda

Gracias al Makefile no fue necesario ejecutar manualmente todos los comandos de compilación y graficación.

En lugar de escribir múltiples comandos, solo fue necesario ejecutar:

```bash
make
```

Esto demuestra cómo el Makefile ayuda a automatizar procesos y facilita el trabajo en proyectos más grandes.

---

# Parte 2 - Proyecto propio (Conversor de Temperatura para IoT)

## Breve explicación del proyecto

Se desarrolló un programa en lenguaje C que funciona como un conversor de temperatura.

Permite convertir:

1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
3. Celsius a Kelvin

Este proyecto fue elegido porque en aplicaciones IoT es común trabajar con sensores de temperatura, por lo que resulta un ejemplo sencillo pero relacionado con la materia.

---

## Estructura del proyecto

```text
makefile-temperatura-iot/
├── main.c
├── Makefile
├── README.md
├── .gitignore
└── evidencia/
```

---

## Instrucciones para ejecutar

En Windows con MinGW se utilizó:

### Compilar

```bat
mingw32-make
```

Esto genera:

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

Esto mantiene el repositorio limpio y profesional.

---

# Evidencias

En la carpeta **evidencia** se incluyen capturas de:

* ejecución del Makefile de ejemplo (julia)
* generación de archivos y gráfica
* contenido del Makefile del ejemplo
* compilación del proyecto propio
* ejecución del conversor de temperatura
* uso de `clean`
* uso de `rebuild`
* estructura final del repositorio

---

# Conclusión

El uso de Makefiles permite automatizar procesos importantes dentro de un proyecto de programación, especialmente en compilación, ejecución y limpieza de archivos.

Durante esta práctica se comprobó que tanto en el ejemplo del profesor como en el proyecto propio, el Makefile ayuda a reducir trabajo manual, evitar errores y mantener una mejor organización.

Además, el uso de `.gitignore` y una buena documentación en README hacen que el repositorio sea más limpio, entendible y fácil de compartir con otras personas.
