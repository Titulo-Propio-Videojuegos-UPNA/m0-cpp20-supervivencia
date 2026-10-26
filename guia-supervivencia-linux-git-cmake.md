# Guía de Supervivencia (2 horas): Terminal Linux/WSL2, CMake y Git

**¿Para quién es esta guía?**
Para cualquier estudiante que acceda al título propio con **60 ECTS superados (1.º de grado aprobado)** o desde **otras titulaciones de ingeniería (Industrial, Telecomunicación, Ciencia de Datos, Biomédica)** y que todavía **no haya cursado** las asignaturas de 2.º del Grado en Ingeniería Informática:
- *Sistemas Operativos* (`240304`, donde se introduce la consola POSIX/Linux y los procesos), y
- *Ingeniería del Software* (`240305`, donde se introduce el control de versiones y la automatización de proyectos).

No necesitas experiencia previa con la línea de comandos. Dedicando **2 horas** con esta guía antes de empezar el Semestre 1 (`B01`), dominarás exactamente los 15 comandos que usamos cada semana en el laboratorio.

---

## Parte 1. La terminal de Linux / WSL2 (30 minutos)

En desarrollo de C++ de tiempo real usamos una terminal de estilo Unix (en Linux nativo, macOS o **WSL2 Ubuntu** dentro de Windows) porque nos permite compilar, pasar detectores de errores de memoria (*sanitizers*) y ejecutar los mismos comandos que corren en los servidores de integración continua (GitHub Actions).

### 1.1. Cómo abrir tu entorno
- **En los ordenadores del laboratorio UPNA (Linux) o en tu Linux/macOS:** abre la aplicación *Terminal*.
- **En tu ordenador con Windows 10/11:** abre PowerShell y ejecuta `wsl --install` (instala Ubuntu por defecto). Una vez instalado, abre la app **Ubuntu** desde el menú Inicio.

### 1.2. Los 7 comandos esenciales para moverte por carpetas

En la terminal siempre estás situado dentro de una carpeta (el *directorio de trabajo*). Prueba estos comandos uno por uno:

```bash
# 1. ¿Dónde estoy ahora mismo? (Print Working Directory)
pwd

# 2. ¿Qué archivos y carpetas hay aquí? (List)
ls -la

# 3. Crear una carpeta nueva para tus prácticas (Make Directory)
mkdir -p ~/titulo-cpp/prueba

# 4. Entrar en una carpeta (Change Directory)
cd ~/titulo-cpp/prueba

# 5. Subir a la carpeta padre (dos puntos significan "nivel superior")
cd ..

# 6. Volver a entrar usando autocompletado: escribe "cd pru" y pulsa la tecla TAB
cd prueba

# 7. Ver el contenido de un archivo de texto en pantalla
cat nombre_archivo.cpp
```

> **Truco de supervivencia:** Nunca escribas rutas largas a mano. Escribe las 3 primeras letras y pulsa la tecla **`Tab`** para que la terminal rellene el resto sin errores tipográficos. Con las flechas **`↑`** y **`↓`** recuperas los comandos que ya ejecutaste.

---

## Parte 2. Del archivo `.cpp` al ejecutable y `CMake` (45 minutos)

### 2.1. Qué hace el compilador cuando hay varios archivos

Cuando escribes un programa C++, no mezclas todo en un único fichero de 5.000 líneas:
- Los archivos de cabecera (**`.h`**) declaran **qué existe** (la interfaz: nombres de estructuras, clases y funciones).
- Los archivos de código fuente (**`.cpp`**) definen **cómo funciona por dentro** (la implementación).

El proceso tiene dos pasos:
1. **Compilación (`-c`):** traduce cada `.cpp` por separado a código máquina intermedio (`.o`).
2. **Enlazado (*linking*):** une todos los `.o` y las bibliotecas (como `raylib` o `Catch2`) para generar el programa ejecutable final.

Puedes comprobarlo directamente con `g++` sobre los ejercicios del pre-curso `M0`:

```bash
# Compilar y ejecutar un único archivo con C++20 y símbolos de depuración (-g)
g++ -std=c++20 -Wall -Wextra -g 01_const.cpp -o 01_const
./01_const

# Compilar un programa dividido en dos archivos .cpp (ejercicio 08)
g++ -std=c++20 -Wall -Wextra -g 08_archivos/main.cpp 08_archivos/vec2.cpp -o 08_vec2
./08_vec2
```

> **Nota importante:** En Linux/WSL, si un programa no imprime nada y vuelve al *prompt* sin mensajes de `Assertion failed`, significa que **todas las comprobaciones (`assert`) han pasado correctamente** (código de salida `0`). Puedes verificar el código de salida del último programa con `echo $?`.

### 2.2. Por qué usamos `CMake` (y los 3 comandos que usarás todo el curso)

Cuando un proyecto tiene 10 archivos `.cpp`, tests unitarios y una biblioteca gráfica como `raylib`, invocar `g++` a mano es engorroso y propenso a errores. **`CMake`** lee una receta llamada `CMakeLists.txt` y construye todo el proyecto por ti en cualquier sistema operativo (Linux, Windows o macOS).

En **todos** los repositorios del título (`M0`, `B01`, `B02`) usarás siempre la misma secuencia de **3 comandos**:

```bash
# 1. CONFIGURAR: lee CMakeLists.txt y prepara la carpeta "build/" (solo hace falta la primera vez)
cmake -B build -S .

# 2. COMPILAR: traduce únicamente los archivos .cpp que hayas modificado
cmake --build build -j

# 3. PROBAR: ejecuta automáticamente toda la batería de tests y muestra el detalle si alguno falla
ctest --test-dir build --output-on-failure
```

#### Activar el detector de errores de memoria (*Sanitizers*)
En `B01` aprenderás que C++ tiene una ventaja clave cuando usas compiladores modernos (`g++` o `clang++`): puedes activar **AddressSanitizer (ASan)** y **UndefinedBehaviorSanitizer (UBSan)** para que el programa te avise al instante (con archivo y número de línea exacto) si accedes fuera de un `std::vector`, desreferencias un `nullptr` o dejas memoria sin liberar:

```bash
cmake -B build-san -S . -DJ1_SANITIZE=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build-san -j
ctest --test-dir build-san --output-on-failure
```

---

## Parte 3. Flujo básico de `Git` y GitHub (45 minutos)

**`Git`** es la máquina del tiempo de tu código: guarda fotografías verificables (*commits*) de tu avance para que nunca pierdas un trabajo que funcionaba hace media hora y para poder construir tu portfolio profesional en GitHub.

### 3.1. Configuración inicial (solo una vez en tu ordenador)

```bash
git config --global user.name "Tu Nombre y Apellido"
git config --global user.email "tu.correo@ejemplo.com"
```

### 3.2. El ciclo diario de 5 pasos

Cada vez que trabajes en un ejercicio o en tu proyecto `J1` de `B01`–`B02` o de Unreal en `B03`, seguirás siempre este ciclo:

```bash
# Paso 1 (solo el primer día): Descargar el repositorio a tu ordenador
git clone <URL_DEL_REPOSITORIO>
cd <NOMBRE_DE_LA_CARPETA>

# Paso 2: Comprobar qué archivos has modificado o creado
git status

# Paso 3: Revisar exactamente qué líneas has cambiado antes de guardar
git diff

# Paso 4: Preparar los archivos de código modificados y crear el punto de guardado (commit)
git add src/ tests/ CMakeLists.txt
git commit -m "Implementa movimiento con paso fijo e invariante de Vec2"

# Paso 5: Subir tus cambios al servidor remoto (GitHub)
git push
```

### 3.3. Regla de oro: qué NUNCA se sube a Git

Nunca subas la carpeta `build/`, ejecutables compilados (`.exe`, binarios) ni carpetas temporales de motores (`Binaries/`, `Intermediate/`, `Saved/` en Unreal Engine). Los repositorios del título ya incluyen un archivo **`.gitignore`** que los filtra automáticamente.

Antes de hacer `git commit`, ejecuta siempre **`git status`**: solo deben aparecer en verde archivos de código fuente (`.h`, `.cpp`), configuración (`CMakeLists.txt`, `.uproject`, `Config/`) y documentación (`README.md`).

---

## Lista de autoverificación (10 minutos)

Antes de tu primera sesión de `B01`, comprueba que puedes marcar estas 4 casillas en tu propio ordenador o en el aula:

- [ ] Abro una terminal en `evolucion/m0-cpp/ejercicios` y veo los archivos con `ls`.
- [ ] Ejecuto `cmake -B build -S . && cmake --build build` y se compilan los 8 ejercicios sin errores de compilación.
- [ ] Ejecuto `ctest --test-dir build --output-on-failure` y veo qué ejercicios pasan ya y cuáles están pendientes de completar.
- [ ] Ejecuto `git status` y `git log -n 3` para inspeccionar el estado y el historial del repositorio.
