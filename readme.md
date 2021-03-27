## **Tarea 1: Sincronización de "threads"** 
Del curso Sistema Operativos Avanzados, de la Maestría de Ciencias de la Computación del Tecnológico de Costa Rica.

##### Equipo de trabajo:
- Carvajal Barboza Nicole
- González Villanueva Ruben
- López Díaz Edisson
- Mena Kikut Otto
- Soto Rojas Cristina


# Uso del programa

#### Compilación
Se utiliza el compilador de GNU, el GCC, usando la siguiente línea:

`gcc main.c -o main -lpthread -lm -w`

- **main.c**: Nombre del archivo principal.
- **-o**: Indica el nombre del archivo de salida.
- **main**: Nombre del archivo de salida.
- **-lpthread**: Indica que se usarán *pthreads*.
- **-lm**: Indica que se usará *math*.
- **-w**: Indica que no imprima *warnings*.

#### Ejecución
Se usa el archivo de salida resultante de la compilación "**main**". Para ejecutarlo es suficiente con la siguiente línea:
`./main`

Sin embargo ésto ejecutará el programa con variables estándares que hemos definido, **para indicar cuántos carros vienen del éste y del oeste se usan los parámetros**, con la siguiente línea:

`./main 4 5` 

Donde el primero, el 4, indica la cantidad de carros que quieren ingresar desde el este/derecha, y el segundo, el 5, la cantidad de carros que quieren ingresar desde el oeste/izquierda.

# Opciones extras incluídas
Se incluyeron **dos parámetros extra que son opcionales** para indicar **el *lambda* que se usará para la función exponencial** para cada dirección, este/derecha y oeste/izquierda. Se hace uso de la siguiente manera:

`./main 4 5 6 7` 

Donde el tercero, el 6, indica el *lambda* el este/derecha, y el cuarto, el 7, el *lambda* para el oeste/izquierda.

# No funcional en el programa
Actualmente **todo funciona en el programa y se programó tal como se solicitó en el enunciado**.

<br /><br /><br />



-------------
# Otros
## Ejecuciones del programa
A continuación dos ejecuciones del programa, mostrando el comando de ejecución y las líneas impresas en consola del resultado.

### Caso 1
Ejecución:
`./main 3 3 15 15` 

Resultado:
```c
Parameters set at: East cars: 3, West cars: 3, East lambda: 15, West lambda: 15
Before Thread
===================Left Times ============== 
Time = 2.612782 
Time = 4.853285 
Time = 8.171958 
===================Right Times ============== 
Time = 17.620624 
Time = 35.221855 
Time = 62.820526 
===================Total Times and Direction ==============
Time = 2.612782 Direction = -1 
Time = 4.853285 Direction = -1 
Time = 8.171958 Direction = -1 
Time = 17.620624 Direction = 1 
Time = 35.221855 Direction = 1 
Time = 62.820526 Direction = 1 


 ** BEGIN PROCESS TO PASS THE BRIDGE ** 


-655395072 (Left  ⬅️) Arrived a new car! 🚙💨 
-655395072 (Left  ⬅️) I'm the fist, I allow the Left  ⬅️ direction 🟢 🟢 
-655395072 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 

-663787776 (Left  ⬅️) Arrived a new car! 🚙💨 
-663787776 (Left  ⬅️) It's my same direction 🟢 
-663787776 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 
-655395072 (Left  ⬅️) I passed the bridge 🟢 

-672180480 (Left  ⬅️) Arrived a new car! 🚙💨 
-672180480 (Left  ⬅️) It's my same direction 🟢 
-672180480 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 
-663787776 (Left  ⬅️) I passed the bridge 🟢 
-672180480 (Left  ⬅️) I passed the bridge 🟢 
-672180480 (Left  ⬅️) I was the last, the bridge is empty 🟡 


-680573184 (Right ➡️) Arrived a new car! 🚙💨 
-680573184 (Right ➡️) I'm the fist, I allow the Right ➡️ direction 🟢 🟢 
-680573184 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-680573184 (Right ➡️) I passed the bridge 🟢 
-680573184 (Right ➡️) I was the last, the bridge is empty 🟡 


-688965888 (Right ➡️) Arrived a new car! 🚙💨 
-688965888 (Right ➡️) I'm the fist, I allow the Right ➡️ direction 🟢 🟢 
-688965888 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-688965888 (Right ➡️) I passed the bridge 🟢 
-688965888 (Right ➡️) I was the last, the bridge is empty 🟡 


-697358592 (Right ➡️) Arrived a new car! 🚙💨 
-697358592 (Right ➡️) I'm the fist, I allow the Right ➡️ direction 🟢 🟢 
-697358592 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-697358592 (Right ➡️) I passed the bridge 🟢 
-697358592 (Right ➡️) I was the last, the bridge is empty 🟡 
```

### Caso 2
Ejecución:
`./main 7 6 2 3` 

Resultado:
```c
Parameters set at: East cars: 7, West cars: 6, East lambda: 2, West lambda: 3
Before Thread
===================Left Times ============== 
Time = 3.156758 
Time = 6.247203 
Time = 9.495758 
Time = 9.543585 
Time = 17.531501 
Time = 25.652481 
===================Right Times ============== 
Time = 3.773602 
Time = 7.449789 
Time = 10.267353 
Time = 13.422997 
Time = 15.114030 
Time = 19.688628 
Time = 19.851628 
===================Total Times and Direction ==============
Time = 3.156758 Direction = -1 
Time = 3.773602 Direction = 1 
Time = 6.247203 Direction = -1 
Time = 7.449789 Direction = 1 
Time = 9.495758 Direction = -1 
Time = 9.543585 Direction = -1 
Time = 10.267353 Direction = 1 
Time = 13.422997 Direction = 1 
Time = 15.114030 Direction = 1 
Time = 17.531501 Direction = -1 
Time = 19.688628 Direction = 1 
Time = 19.851628 Direction = 1 
Time = 25.652481 Direction = -1 


 ** BEGIN PROCESS TO PASS THE BRIDGE ** 


-993585408 (Left  ⬅️) Arrived a new car! 🚙💨 
-993585408 (Left  ⬅️) I'm the fist, I allow the Left  ⬅️ direction 🟢 🟢 
-993585408 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 

-1001978112 (Right ➡️) Arrived a new car! 🚙💨 
-1001978112 (Right ➡️) I'll wait because bridge is in use 🔴 

-1010370816 (Left  ⬅️) Arrived a new car! 🚙💨 
-1010370816 (Left  ⬅️) It's my same direction 🟢 
-1010370816 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 

-1018763520 (Right ➡️) Arrived a new car! 🚙💨 
-1018763520 (Right ➡️) I'll wait because bridge is in use 🔴 
-993585408  (Left  ⬅️) I passed the bridge 🟢 

-1027156224 (Left  ⬅️) Arrived a new car! 🚙💨 
-1027156224 (Left  ⬅️) It's my same direction 🟢 
-1027156224 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 

-1035548928 (Left  ⬅️) Arrived a new car! 🚙💨 
-1035548928 (Left  ⬅️) It's my same direction 🟢 
-1035548928 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 

-1043941632 (Right ➡️) Arrived a new car! 🚙💨 
-1043941632 (Right ➡️) I'll wait because bridge is in use 🔴 
-1010370816 (Left  ⬅️) I passed the bridge 🟢 

-1052334336 (Right ➡️) Arrived a new car! 🚙💨 
-1052334336 (Right ➡️) I'll wait because bridge is in use 🔴 

-1060727040 (Right ➡️) Arrived a new car! 🚙💨 
-1060727040 (Right ➡️) I'll wait because bridge is in use 🔴 
-1027156224 (Left  ⬅️) I passed the bridge 🟢 
-1035548928 (Left  ⬅️) I passed the bridge 🟢 
-1035548928 (Left  ⬅️) I was the last, the bridge is empty 🟡 

-1001978112 (Right ➡️) Now is my turn, I'll prepare to pass 🟡 
-1001978112 (Right ➡️) I'm the fist, I allow the Right ➡️ direction 🟢 🟢 
-1001978112 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1018763520 (Right ➡️) Now is my turn, I'll prepare to pass 🟡 
-1018763520 (Right ➡️) It's my same direction 🟢 
-1043941632 (Right ➡️) Now is my turn, I'll prepare to pass 🟡 
-1060727040 (Right ➡️) Now is my turn, I'll prepare to pass 🟡 
-1060727040 (Right ➡️) It's my same direction 🟢 
-1018763520 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1052334336 (Right ➡️) Now is my turn, I'll prepare to pass 🟡 
-1052334336 (Right ➡️) It's my same direction 🟢 
-1052334336 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1060727040 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1043941632 (Right ➡️) It's my same direction 🟢 
-1043941632 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 

-1069119744 (Left  ⬅️) Arrived a new car! 🚙💨 
-1069119744 (Left  ⬅️) I'll wait because bridge is in use 🔴 

-1077512448 (Right ➡️) Arrived a new car! 🚙💨 
-1077512448 (Right ➡️) It's my same direction 🟢 
-1077512448 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 

-1085905152 (Right ➡️) Arrived a new car! 🚙💨 
-1085905152 (Right ➡️) It's my same direction 🟢 
-1085905152 (Right ➡️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1001978112 (Right ➡️) I passed the bridge 🟢 
-1018763520 (Right ➡️) I passed the bridge 🟢 
-1052334336 (Right ➡️) I passed the bridge 🟢 
-1060727040 (Right ➡️) I passed the bridge 🟢 
-1043941632 (Right ➡️) I passed the bridge 🟢 
-1077512448 (Right ➡️) I passed the bridge 🟢 
-1085905152 (Right ➡️) I passed the bridge 🟢 
-1085905152 (Right ➡️) I was the last, the bridge is empty 🟡 


-1094297856 (Left  ⬅️) Arrived a new car! 🚙💨 
-1069119744 (Left  ⬅️) Now is my turn, I'll prepare to pass 🟡 
-1069119744 (Left  ⬅️) I'm the fist, I allow the Left  ⬅️ direction 🟢 🟢 
-1069119744 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1094297856 (Left  ⬅️) I'm the fist, I allow the Left  ⬅️ direction 🟢 🟢 
-1069119744 (Left  ⬅️) I passed the bridge 🟢 
-1069119744 (Left  ⬅️) I was the last, the bridge is empty 🟡 

-1094297856 (Left  ⬅️) I'll pass the bridge in a row, and now I'm the last 🟢 
-1094297856 (Left  ⬅️) I passed the bridge 🟢 
-1094297856 (Left  ⬅️) I was the last, the bridge is empty 🟡 
```

<br/><br/><br/><br/>
_ end line _
