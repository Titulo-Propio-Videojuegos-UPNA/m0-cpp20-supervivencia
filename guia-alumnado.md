# M0: Nivelación C a C++20 y Supervivencia en Terminal, Git y CMake (Pre-curso antes de S1)

> **Fecha de verificación y consolidación:** `2026-10-25`

Es un **pre-curso autónomo y gratuito de nivelación**: **0 ECTS** y unas **15–20 horas** (`18 h` estimadas). No consume horas de las 200 h lectivas del título y está disponible **en el aula virtual tras iniciar sesión** en `/titulo-videojuegos/practicar` para que todo el alumnado —tanto de Ingeniería Informática como de otras ingenierías (Industrial, Telecomunicación, Ciencia de Datos)— entre al Semestre 1 con soltura en C++ moderno y herramientas de desarrollo.

## Cómo conecta M0 con el Semestre 1 (`Plan Definitivo · 2026-10-25`)

- **Semanas 1 a 5 de S1 (`B01`, 20 h — Sesiones `S1-01` a `S1-10`):** empezamos con **C++20 de sistemas**, modelo de memoria (*stack*, *heap*, RAII con `std::unique_ptr`, memoria contigua `std::vector` vs `TArray`), matemáticas 3D visuales y tu **Juego 1 — Arcade Espacial 3D (*Space Runner 3D*) en C++20** (`raylib 5.5`) a paso fijo (`dt = 1/60 s`) con tests en `Catch2` y *sanitizers* (**Pieza 1 de portfolio**).
- **Semanas 6 a 10 de S1 (`B02`, 20 h — Sesiones `S1-11` a `S1-20`):** entramos en **Unreal Engine 5 desde C++** (con filosofía *Blueprint = Data-Only Prefab*, sin programar lógica en grafos de nodos): programamos actores C++, colisiones, *Enhanced Input*, trazas físicas (`LineTraceSingleByChannel`) y `UMG` para construir el **Juego 2 — *Obstacle & Crypt Escape 3D*** (base de la **Pieza 2**).
- **Semanas 11 a 14 de S1 (`B03`, 14 h — Sesiones `S1-21` a `S1-27`):** diseñamos arquitectura modular en **C++ nativo para Unreal Engine 5** (`UActorComponent`, `TObjectPtr` con escudo anti-crash `ensure()`, `UPrimaryDataAsset`, `UGameInstanceSubsystem` y `Delegates` C++ → HUD) para entregar el **Juego 3 — *Arena Arcade / Toon Tanks 3D*** (**Pieza 2 de portfolio**). Todo el temario técnico nuevo cierra el **29 de abril**, dejando mayo para clínicas en aula sin deberes en casa antes de los exámenes del Grado.

Si vienes con **60 ECTS (1.º de grado aprobado)** o desde otra ingeniería y aún no has cursado *Sistemas Operativos* (`240304`) ni *Ingeniería del Software* (`240305`), empieza por la **[Guía de supervivencia de 2 horas: Terminal Linux/WSL2, CMake y Git](guia-supervivencia-linux-git-cmake.md)** incluida en esta misma carpeta.

**Compilador:** C++17 como mínimo (recomendado C++20, que es el estándar de la plantilla de S1).
- En Windows: Visual Studio 2022 Community, o WSL2 (Ubuntu) con `g++` o `clang++`.
- En Linux o macOS: `g++` o `clang++`.
- Para resolver los retos directamente en el navegador sin instalar nada: el laboratorio interactivo **Cppxom** en `/titulo-videojuegos/practicar` tras login o [Compiler Explorer](https://godbolt.org/).

---

## Tres claves para aprovechar el título desde el primer día

1. **Formación en ingeniería de software de tiempo real con triple salida laboral.** Lo que aprendes en el programa abre puertas en tres grandes mercados: **ingeniería C++20 y simulación/gemelos digitales 3D (Unreal Engine 5 + Python)**, **desarrollo de videojuegos y sistemas interactivos (UE5 C++ / multijugador / gráficos)**, e **ingeniería 3D/XR e interacción espacial con Unity 6 y C# (.NET)**.
2. **Construyes portfolio propio verificable desde el Semestre 1 (3 juegos 3D terminados en C++).** En el sector tecnológico y del videojuego, las mejores ofertas de prácticas y empleo valoran repositorios personales con código fuente limpio, tests automáticos y demostración visual ejecutable. En S1 terminarás con tu Arcade Espacial 3D en C++20 (`B01`, **Pieza 1 — Juego 1**) y dos juegos 3D en Unreal Engine 5 C++ (`B02` Obstáculos 3D + `B03` Arena Arcade 3D, **Pieza 2**).
3. **Fluidez real leyendo y escribiendo C++.** La inteligencia artificial es un excelente copiloto para consultar dudas conceptuales, pero en entrevistas técnicas y en la depuración de sistemas de tiempo real necesitas entender qué ocurre en cada línea y en cada byte de memoria. En `B01.3` aprenderás a auditar código asistido por IA con tests y *sanitizers*.

---

## Qué usar

### 0. Si nunca has usado terminal Linux, CMake o Git (2 h)

- Lee y ejecuta paso a paso [`guia-supervivencia-linux-git-cmake.md`](guia-supervivencia-linux-git-cmake.md). En dos horas tendrás dominados los comandos esenciales de consola, la compilación con `CMake` + `CTest` y el flujo diario de `Git`.

### 1. El temario interactivo de referencia (gratis): LearnCpp

**[LearnCpp.com](https://www.learncpp.com/)** está actualizado a C++ moderno y cuenta con cuestionarios cortos por lección. Léelo en su web y resuelve luego los ejercicios prácticos de este pack (en Ikasyn o en local).

Si ya programas en C, Python o Java por el Grado, **no necesitas empezar desde cero**: sigue la tabla de ruta de abajo y repasa únicamente los apartados que sean nuevos para ti.

### Referencias oficiales (para consulta puntual)

| Recurso | Para qué |
|---|---|
| [isocpp.org/get-started](https://isocpp.org/get-started) | Instalar y verificar un compilador moderno |
| [How to learn C++](https://isocpp.org/wiki/faq/how-to-learn-cpp) | Por qué **no hace falta pasar por C clásico** (`malloc`, `printf`, `#define`) para aprender C++ moderno |
| [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) | Buenas prácticas de C++ moderno; céntrate en las seis reglas resumidas más abajo |
| [cppreference.com](https://en.cppreference.com/) | Manual de referencia técnica (como un diccionario, no un tutorial secuencial) |

---

## Ruta recomendada (unas 15–20 h)

Después de revisar cada tema en LearnCpp, resuelve el ejercicio correspondiente en Ikasyn (**Cppxom**) o en tu equipo con la carpeta `ejercicios/`.

| Bloque | Horas | LearnCpp ([índice](https://www.learncpp.com/)) | Ejercicio | Objetivo práctico | Conexión con S1 (`B01–B03`) |
|---|---|---|---|---|---|
| 0. Terminal, CMake y Git | 1–2 | Cap. 0 + Lección 2.8 + [Guía de supervivencia](guia-supervivencia-linux-git-cmake.md) | `00-hola` (Ikasyn) | Compilar desde terminal con `g++`/`clang++` y `CMake` | `B01.1` y `B01.3` (CMake, Git y CTest desde la Semana 1) |
| 1. `const` | 1 | Lección 5.1, constantes y calificación `const` | `01_const` | Usar `const` por defecto en parámetros y métodos | `B01.1` (`S1-01`) |
| 2. Referencias | 2 | **Cap. 12**: referencias y paso por `const T&` | `02_referencias` | Evitar copias innecesarias de contenedores y *structs* | `B01.1` (`S1-01`) |
| 3. Punteros | 2 | **Cap. 12**: punteros, `nullptr`, indirección | `03_punteros` | Distinguir dirección (`&`) y desreferencia (`*`) con seguridad | `B01.1` y `B02.1` (`TObjectPtr` y actores/componentes en UE5) |
| 4. RAII | 2–3 | Cap. 19 y **Lecciones 22.1–22.5** (`std::unique_ptr`, `std::move`) | `04_raii` | Gestionar recursos automáticamente sin fugas de memoria | `B01.1` (RAII y *Arena Allocator*) |
| 5. Clases | 2–3 | **Caps. 14–15**: constructores, invariantes, cabecera y `.cpp` | `05_clase` | Diseñar una clase que garantice su invariante desde el constructor | `B01.2` y `B02.1` (entidades y actores C++) |
| 6. `virtual` | 2 | **Cap. 24** (herencia) y **Cap. 25** (`virtual`, `override`, destructor virtual) | `06_virtual` | Polimorfismo limpio y seguro mediante `override` | `B02.1` y `B03.1` (`AActor::BeginPlay` / `TickComponent` en UE5) |
| 7. Plantillas mínimas | 1–2 | **Lecciones 11.6 y 11.7**: plantillas de función | `07_plantillas` | Escribir una función genérica sencilla `template <typename T>` | `B01.2` y `B03.1` (`Cast<T>`, `TArray<T>`, `TSpan<T>`) |
| 8. Varios ficheros y `Vec2` | 2 | **Cap. 16** (`std::vector`), lecciones 2.8 y 15.2 (`.h` y `.cpp`) | `08_archivos` (`08-vec2`) | Separar interfaz (`.h`) e implementación (`.cpp`) con `Vec2` y `std::vector` | `B01.2` (matemáticas 3D visuales y paso fijo) |
| 9. Depurar (opcional) | 1 | **Cap. 3**: uso del depurador (*breakpoints*, pila de llamadas) | — | Poner un punto de ruptura e inspeccionar variables paso a paso | `B01.4` (`S1-10`: caza de bugs con ASan/UBSan) |

---

## Seis reglas de las C++ Core Guidelines que usaremos todo el año

1. **R.1 (RAII):** todo recurso (memoria, textura, archivo, socket) vive dentro de un objeto cuyo destructor lo libera automáticamente.
2. **R.11:** evita llamar a `new` y `delete` explícitamente en código de aplicación; usa valores en pila, arenas, `std::vector` o `std::make_unique` (y en UE5, `NewObject<T>()` / `CreateDefaultSubobject<T>()`).
3. **Con.1:** marca variables, referencias y métodos como `const` por defecto salvo que necesiten mutar estado.
4. **F.16:** pasa los tipos pequeños (`int`, `float`, `Vec2`) por valor y los objetos pesados (`std::string`, `std::vector`) como `const T&`.
5. **C.128:** en métodos polimórficos usa `override` explícitamente en las clases derivadas y declara siempre `virtual ~Base() = default;` en la clase base.
6. **P.4 / ES.20:** inicializa siempre todas tus variables al declararlas.

---

## Cómo comprobar tu progreso

El M0 es formativo y de autodiagnóstico (no resta nota ni bloquea el acceso). Sabrás que estás al 100 % cuando los ejercicios pasen en verde en **Ikasyn (Cppxom)** o con **`ctest`** en tu ordenador.

### Opción A: En el navegador con tu cuenta de Ikasyn (laboratorio Cppxom)

Entra directamente en **`/titulo-videojuegos/practicar`** → módulo **«Pre-curso M0 (`B00`)»**. En cada uno de los 9 ejercicios (`M0.00` a `M0.08`), completa la función o método pedido y pulsa **Ejecutar tests**.

### Opción B: En tu propio equipo con CMake y CTest

```bash
cd ejercicios
cmake -B build -S .
cmake --build build
ctest --test-dir build --output-on-failure
```
