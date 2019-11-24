# *El Tour de Francia*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *Fernando Garrote de la Macorra* *A01027503*
2. *Alejandra Nissan Leizorek* *A01024682*

---
## 1. Aspectos generales

### 1.1 Requerimientos

A continuación se mencionan los requerimientos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir el problema a resolver.
* El proyecto deberá utilizar [OpenMP](https://www.openmp.org/) para la implementación del código paralelo.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.

### 1.2 Estructura del repositorio
El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# este archivo
    - secuencial		# Carpeta con la solución secuencial
    - paralelo			# Carpeta con la solución paralela
    - docs              # Carpeta con los documentos, tablas, gráficas, imágenes
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Descripción de la solución secuencial con referencia (enlace) al código secuencial alojado en la carpeta [secuencial](secuencial/).
* Análisis de los inhibidores de paralelismo presente y una explicación de cómo se solucionaron.
* Descripción de la solución paralela con referencia (enlace) al código paralelo alojado en la carpeta [paralelo](paralelo/).
* Tabla de resultados con los tiempos de ejecución medidos para cada variante de la solución secuencial vs. la solución paralela, teniendo en cuenta: 5 tamaños diferentes de las entradas, 5 opciones diferentes de números de CPU (threads), 4 ocpiones diferentes de balanceo (*auto, guided, static, dynamic*).
* Gráfica(s) comparativa(s) de los resultados obtenidos en las mediciones.
* Interpretación de los resultados obtenidos.
* Guía paso a paso para la ejecución del código y replicar los resultados obtenidos.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Descripción del problema

*[Incluya aquí la descripción del problema a resolver.]*
*El Tour de Francia es el evento anual más grande en el mundo del ciclismo. El tour consiste de 21 carreras repartidas en 23 días, las 21 carreras cubren al rededor de 3,300 kms y hay al rededor de 200 corredores. El  programa que realizamos es una simulación del Tour de Francia. El programa cuenta con las 21 carreras que hay en el tour, a las carreras le añadimos la cantidad de km que hay en la carrera, si descansan el siguiente día o no, el lugar de salida y el lugar de llegada. El usuario debe de decir cuantos ciclistas hay en la carrera y el programa regresa quien gana cada una de las carreras, el tour, y cuanto tiempo le tomó realizar todas las carreras. El ganador del Tour es el ciclista que ganó la mayor cantidad de carreras. *

## 3. Solución secuencial

*[Incluya aquí la descripción de la solución secuencial.]*

## 4. Análisis de los inhibidores del paralelismo

*[Incluya aquí el análisis de los inhibidores presentes en su problema, así como la solución a los mismos.]*
*Un inhibidor que se presentó fue el de las variables compartidas, nuestra solución contenía tres ciclos anidados en donde se debía almacenar la suma de los tiempos de cada jugador y sus puntos obtenidos. Para eliminar este problema, creamos una estructura llamada ciclista, en donde uno de sus atributos era el tiempo de cada jugador y sus puntos. De esta manera, no existía ninguna variable compartida, lo cual facilitó la implementación del paralelismo. Unicamente existieron variables privadas para acceder a la información de los ciclistas, los contadores.

Otro inhibidor del paralelismo en el problema, era que los ciclistas debían esperarse terminando cada etapa de la carrera. Por lo que, no se podían paralelizar todos los ciclos para asegurar esa espera entre jugadores. 
*

## 5. Solución paralela

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados

*[Incluya aquí la tabla con los resultados de las mediciones.]*



## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*


## 8. Interpretación de los resultados

*[Incluya aquí la interpretación de los resultados.]*

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
