# process-c

3 ejercicios acerca de procesos y señales en c. 
1) Realice un código en lenguaje C en el cual se creen dos procesos hijos, cada uno leerá una cadena de entrada estándar y la imprimirá carácter a carácter, finalmente, el proceso padre se encargará de imprimir la concatenación de ambas cadenas por salida estándar. 

2) Realice un código en lenguaje C en el cual un proceso hijo escriba su identificador de proceso en una tubería con nombre, el proceso padre deberá leerlo e imprimirlo en salida estándar. 

3) Realice un código en lenguaje C en el que proceso padre crea 1 proceso hijo el cual escribirá por pantalla un mensaje. El proceso padre es el encargado de enviar señales a los hijos indicando que deben detenerse o continuar ejecutándose. El proceso padre puede recibir por entrada estándar: ‘S’: Detiene al hijo. ‘G’: Reanuda al hijo. ‘F’: Detiene al proceso padre ‘C’: Crea al proceso hijo. Se debe realizar una función manejadora de señales, esta debe capturar Ctrl + C la cual mata al proceso hijo. Cuando el proceso padre crea al hijo este debe ejecutar el código provisto por el GDSO. Para lograr dicha funcionalidad válgase de usar la función Execlp().
