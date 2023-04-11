# **Proyecto_RiosFranco**
## *Manual técnico*
* **Zoológico RF**
Nuestro proyecto consiste, de manera esencial en una pequeña simulación del cómo relacionar tres aspectos que se toman como relevantes dentro de un zoológico.
Por ejemplo, los hábitats, los animales y los alimentos. Y de la relación que existe entre estos y las normas básicas del funcionamiento del mismo.

* **Imagen del diagrama UML**
<https://embed.creately.com/pwIrrCnz8T0?token=kOUEDdjbMPlq1f4r&type=svg>

* **Funcionamiento del programa**
(En caso de que no se pueda visualizar la imagen. Dejaré la URL al lado de cada una)   
  * ![Inicio del programa](https://ibb.co/n7DXHcj) (<https://ibb.co/n7DXHcj>)
En el momento en el que el programa se ejecuta por primera vez, observamos que tiene un total de nueve opciones. Las cuáles se manejan a nivel de código con una función que permite al usuario realizar una cantidad indeterminada de tareas hasta que él digite el número 0, que indica que desea finalizar la ejecución del programa.

  * ![Agregar un hábitat](https://ibb.co/k9xR0JP) (<https://ibb.co/k9xR0JP>)
Para realizar esta acción, vemos que no se permite agregar un hábitat mientras este no sea uno de los cuatro que se predispusieron para la actividad (polar, desértico, selvático y acuático).
Además, podemos notar también que si deseamos agregar un hábitat que ya se encuentra en la lista, el programa se lo informará al usuario.
![Agregar un hábitat](https://ibb.co/rfxRmFP) (<https://ibb.co/rfxRmFP>)

  * ![Agregar un animal](https://ibb.co/dPr4wDN) (<https://ibb.co/dPr4wDN>)
Para realizar esta acción, también tenemos el manejo de ciertos errores que pueden ser comunes, por ejempplo indicar una edad que esté fuera del rango de las posibilidades, dar un nombre diferente al nombre de la dieta que se pide, y especialmente, revisar que el hábitat al que se quiere ingresar al animal sea válido y exista en nuestro sistema del zoológico.
En otro de los ejemplos que tenemos, podemos observar que incluso maneja un caso en el que el hábitat no solo no está creado; sino que no es posible que exista.
![Agregar un animal](https://ibb.co/Vj6T808) (<https://ibb.co/Vj6T808>)

   * ![Ver hábitats y animales disponibles](https://ibb.co/xLpzQmH) (<https://ibb.co/xLpzQmH>)
En el caso que tenemos, es bastante intuitivo el notar que se muestran los hábitats que se han ingresado al zoológico. Sin embargo, a todos les agregamos un animal, así que ahora agregaremo el habitat "acuático" y verificaremos cómo se muestra en la lista.
![Ver hábitats y animales disponibles](https://ibb.co/L6MSDgr) (<https://ibb.co/L6MSDgr>)
Como era posible deducir, se muestran todos los animales que se mostraban la vez pasada, pero además se muestra que hay un hábitat más disponible que no tiene aún ningún animal.

   * ![Jugar con un animal](https://ibb.co/K7j1Thr) (<https://ibb.co/K7j1Thr>)
Al seleccionar esta opción, nos encontraremos con lo que se muestra en la imagen anterior.
Lo primero será una lista de los animales disponibles y el hábitat en el que se encuentran. De esta manera parecía más sencillo el manejo de los animales (suponiendo que existan dos animales en hábitats diferentes que tengan nombres iguales).
Así, primero accederemos al hábitat y luego al animal con el que queramos jugar. Al final de esta ejecución veremos en pantalla el estado anterior de juego. así verificamos que cambió.
La mejor manera para comprobar que efectivamente el cambio se dio, es imprimir nuevamente la lista y verificar si en esta se refleja que el animal ya jugó.
![Jugó con el animal](https://ibb.co/wWTBwm4) (<https://ibb.co/wWTBwm4>)

   * ![Agregar un alimento al inventario](https://ibb.co/wWTBwm4https://ibb.co/NjF8YTv) (<https://ibb.co/wWTBwm4https://ibb.co/NjF8YTv>)
Para agregar un alimento al inventario, solo tendremos que dar dos datos, el primero el nombre del alimento y para qué tipo de alimentación es apto.
Para el caso de nuestro zoológico, consideraremos que los omnívoros poseen una dieta especial y única, de la misma manera que los carnívoros y hervíboros.

   * ![Ver lista de alimentos](https://ibb.co/h8LcWmm)(<https://ibb.co/h8LcWmm>)
Para visualizar las diferencias de mejor manera, adicionamos un nuevo alimento e imprimimos la lista que hasta el momento llevamos almacenada en el sistema.

  * ![Alimentar a un animal](https://ibb.co/5r6yZSc) (<https://ibb.co/5r6yZSc>)
El caso anterior se presenta cuando se logra alimentar a un animal con la dieta que le corresponde según su tipo de alimentación.
Sin embargo, también podemos ver cómo no permite alimentar a un animal cuando no es esa la dieta que le pertenece.
![Alimentar a un animal](https://ibb.co/VJfDtxb)(<https://ibb.co/VJfDtxb>)
Además de esto, vemos que al volver a mostrar la información del inventario, el alimento que utilizamos ya no va a estar.
![Ver lista de alimentos](https://ibb.co/JF6YfWg)

  * ![Enviar a un animal a dormir](https://ibb.co/bXnS2Zt)(<https://ibb.co/bXnS2Zt>)
Para realizar esta acción el programa seguirá la misma lógica que ha tenido para acceder a un animal.
Una vez hayamos llegado a este, el programa indicará las horas de sueño adecuadas para el animal.
Dicho esto, el programa solo permitirá que el animal se vaya a dormir si la cantidad de horas es igual a la cantidad de horas que requiere en su historial. De lo contrario, se mostrará un mensaje en pantalla que indique lo que sucede.


Lo anterior contiene toda la lógica y la comprensión básica del cómo las funciones se encargan de realizar lo que se necesita para que el sistema haga aquello para lo que fue creado.

Gracias por llegar hasta aquí. ¡Que tenga un maravilloso día!
