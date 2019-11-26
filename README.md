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
El Tour de Francia es el evento anual más grande en el mundo del ciclismo. El tour consiste de 21 carreras repartidas en 23 días, las 21 carreras cubren al rededor de 3,300 kms y hay al rededor de 200 corredores. El  programa que realizamos es una simulación del Tour de Francia del 2020 específicamente. El programa cuenta con las 21 carreras que hay en el tour, a las carreras le añadimos la cantidad de km que hay en la carrera, si descansan el siguiente día o no, el lugar de salida y el lugar de llegada. El usuario debe de decir cuantos ciclistas hay en la carrera y el programa regresa quien gana cada una de las carreras, el tour, y cuanto tiempo le tomó realizar todas las carreras. El ganador del Tour es el ciclista que ganó la mayor cantidad de carreras. 

## 3. Solución secuencial

Primeramente, inicializamos con la información real de las fases de toda la carrera, para que realmente se pudiera ver un comportamiento real del algoritmo, condierando los kilómetros que se recorren en cada fase. 
Creamos una estructura llamada ciclista y otra llamada parada para almacenar los datos necesarios en ellos y poder diferenciarlos. 
Posteriormente, creamos tres ciclos anidados, el primer ciclo recorre todas las paradas de la carrera, el segundo recorre a los ciclistas de cada carrera y el tercero recorre los kilómetros de la fase en la que se encuentra.
En este último ciclo, el más adentrado. Se calcula una velocidad aleatoria, de entre 15 y 105 km/h, esto se debe a que la velocidad esta en constante cambio. Posteriormente se le suma al tiempo de los ciclistas 1/velocidad, para calcular el tiempo real. 
Durante las fases, encuentra quién tiene el menor tiempo y determina un ganador de la carrera para sumarle 1 punto al ganador. De esta manera, se calcula más adelante el ganador FINAL de la carrera y en caso de haber un empate lo muestra.

## 4. Análisis de los inhibidores del paralelismo

Un inhibidor que se presentó fue el de las variables compartidas, nuestra solución contenía tres ciclos anidados en donde se debía almacenar la suma de los tiempos de cada jugador y sus puntos obtenidos. Para eliminar este problema, creamos una estructura llamada ciclista, en donde uno de sus atributos era el tiempo de cada jugador y sus puntos. De esta manera, no existía ninguna variable compartida, lo cual facilitó la implementación del paralelismo. Unicamente existieron variables privadas para acceder a la información de los ciclistas, los contadores.

Otro inhibidor del paralelismo en el problema, era que los ciclistas debían esperarse terminando cada etapa de la carrera. Por lo que, no se podían paralelizar todos los ciclos para asegurar esa espera entre jugadores. 


## 5. Solución paralela

Como ya se mencionó con anterioridad en la solución paralela, nuestra solución cuentra con tres ciclos anidados para recorrer las fases, los ciclistas y cada kilómetro de las fases. 
El primer ciclo no se debía paralelizar, debido a que los ciclistas salen cada día a una diferente fase teniendo que dormir y esperar al resto. Por lo que, se paralelizaron los siguientes dos ciclos, para que diferentes hilos de ejecución trabajaran en cada ciclista y en el tiempo que les lleva recorrer cada kilómetro de la fase en la que se encuentran. 
Además, en la sección del código en la que se busca al ganador total de la carrera y a los empatados, cada uno de ellos un ciclo individual. Se paralelizó para repartir la búsqueda de los ganadores.
## 6. Tabla de resultados


*Se encuentra en la carpeta de Documentos, en el archivo de resultados*

## 7. Gráfica(s) comparativa(s)
*Se encuentra en la carpeta de Documentos, en el archivo de ProyectoFinal*



## 8. Interpretación de los resultados

Primeramente, ejecutamos el código en la máquina virtual. Notamos que el tiempo de ejecución del algoritmo paralelo era mayor debido a que la máquina virtual compite con otros hilos de ejecución de la computadora y a su vez el programa compite con sus propios hilos de ejecución haciendo que no sea una solución óptima con programación paralela. 
Al correrlo de manera nativa en el sistema operativo mac, notamos que seguía demorando más para la solución paralela que para la secuencial. Lo que nos lleva a notar que la libreria openmp genera un overhead muy pesado, haciendo que no para todas las soluciones sea conveniente aplicar paralelismo. Esto se nota en nuestra solución, ya que no se pudieron colapsar los ciclos, ni se pudo paralelizar todo, por lo que los resultados hacen lógica: deben dividirse la carga, competir por tiempo de procesamiento y después esperar a que terminen para volver a comenzar. 

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
