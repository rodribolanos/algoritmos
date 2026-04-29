

### Para ahorrarse tiempo al probar ejercicios


en vez de estar probando en el main a cada rato usan este trucazo:

(validos para Mac(puede que sirva para linux) y en el IDE Vscode)

1. dentro de /trucos/compilarfacil hay dos archivos, esos archivos  de configuracion.
2. poner esos archivos dentro del .vscode, son archivos que dicen como compilar.
3. hay un archivo "in" y un "out" esos ponganlos en el root del proyecto
4. se paran sobre un ejercicio cualquiera, por ejemplo apple-division.
5. Con VS Code en la terminal `Ctrl+Shift+B` (en windows darle run con vscode), esto ejecuta la tarea de compilación configurada en `.vscode/tasks.json`
6. en otra terminal desde root ejecutan `./main < in.txt > out.txt ` (en windows desde una terminal BASH (tiene que ser bash, sirve la de git) `./main.exe < in.txt > out.txt` )


Todo esto lee lo que esté en `in.txt` como input, e imprime en `out.txt`


Recomiendo tener al mismo abiertas las dos terminales asi cambian entre estas facilmente.


A codear!

