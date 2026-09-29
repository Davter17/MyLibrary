# libraryC - Proyecto de 42 School

Una biblioteca unificada en C que combina libft, get_next_line y ft_printf en una única biblioteca estática.

## Descripción General

Este proyecto unifica tres proyectos esenciales de la escuela 42 en una biblioteca completa:

- **libft**: Funciones de la biblioteca estándar de C (manipulación de cadenas, operaciones de memoria, clasificación de caracteres, listas enlazadas)
- **get_next_line**: Lectura de archivos línea por línea con soporte para múltiples FD
- **ft_printf**: Implementación personalizada de printf con especificadores de formato

## Estructura del Proyecto

```
libraryC/
├── src/           # Archivos fuente (.c)
├── inc/           # Archivos de cabecera
│   ├── libft.h
│   ├── get_next_line.h
│   └── ft_printf.h
├── .obj/          # Archivos objeto compilados (generados)
├── Makefile       # Configuración de compilación
└── libraryC.a     # Biblioteca compilada (generada)
```

## Compilación

### Compilación básica
```bash
make
```
Compila todas las funciones en `libraryC.a`.

### Compilación limpia
```bash
make re
```
Elimina todos los archivos compilados y recompila todo.

### Limpieza
```bash
make clean    # Elimina el directorio .obj/
make fclean   # Elimina .obj/ y libraryC.a
```

## Funciones

### Funciones de Libft

#### Verificación de Caracteres
- `ft_isalpha` - Verifica si el carácter es alfabético
- `ft_isdigit` - Verifica si el carácter es un dígito
- `ft_isalnum` - Verifica si el carácter es alfanumérico
- `ft_isascii` - Verifica si el carácter es ASCII
- `ft_isprint` - Verifica si el carácter es imprimible
- `ft_toupper` - Convierte a mayúsculas
- `ft_tolower` - Convierte a minúsculas

#### Operaciones con Cadenas
- `ft_strlen` - Calcula la longitud de una cadena
- `ft_strchr` - Localiza la primera ocurrencia de un carácter
- `ft_strrchr` - Localiza la última ocurrencia de un carácter
- `ft_strncmp` - Compara cadenas hasta n caracteres
- `ft_strnstr` - Localiza subcadena en una cadena
- `ft_strlcpy` - Copia cadena con límite de tamaño
- `ft_strlcat` - Concatena cadenas con límite de tamaño
- `ft_strdup` - Duplica una cadena
- `ft_substr` - Extrae subcadena
- `ft_strjoin` - Concatena dos cadenas
- `ft_strtrim` - Recorta caracteres de una cadena
- `ft_split` - Divide cadena por delimitador
- `ft_strmapi` - Aplica función a cada carácter
- `ft_striteri` - Aplica función a cada carácter (en su lugar)

#### Operaciones de Memoria
- `ft_memset` - Rellena memoria con valor de byte
- `ft_bzero` - Pone a cero un área de memoria
- `ft_memcpy` - Copia área de memoria
- `ft_memmove` - Copia área de memoria (maneja superposición)
- `ft_memchr` - Localiza byte en memoria
- `ft_memcmp` - Compara áreas de memoria

#### Conversión
- `ft_atoi` - Convierte cadena a entero
- `ft_itoa` - Convierte entero a cadena

#### Salida
- `ft_putchar_fd` - Envía carácter a descriptor de archivo
- `ft_putstr_fd` - Envía cadena a descriptor de archivo
- `ft_putendl_fd` - Envía cadena con salto de línea a descriptor de archivo
- `ft_putnbr_fd` - Envía entero a descriptor de archivo

#### Asignación de Memoria
- `ft_calloc` - Asigna e inicializa a cero memoria

#### Lista Enlazada (Bonus)
- `ft_lstnew` - Crea nuevo nodo de lista
- `ft_lstadd_front` - Añade nodo al principio
- `ft_lstadd_back` - Añade nodo al final
- `ft_lstsize` - Cuenta nodos en la lista
- `ft_lstlast` - Obtiene el último nodo
- `ft_lstdelone` - Elimina y libera un nodo
- `ft_lstclear` - Elimina y libera todos los nodos
- `ft_lstiter` - Aplica función a cada nodo
- `ft_lstmap` - Aplica función y crea nueva lista

### Get Next Line

| Función | Descripción |
|---------|-------------|
| `get_next_line` | Lee la siguiente línea de un descriptor de archivo |
| `ft_strjoin_and_replace` | Concatena dos cadenas, libera la primera |

### Especificadores de Formato de ft_printf

| Especificador | Descripción |
|---------------|-------------|
| `%c` | Carácter |
| `%s` | Cadena (maneja NULL) |
| `%p` | Dirección de puntero (hex con prefijo 0x, maneja NULL) |
| `%d` | Entero decimal con signo |
| `%i` | Entero decimal con signo |
| `%u` | Entero decimal sin signo |
| `%x` | Hexadecimal (minúsculas) |
| `%X` | Hexadecimal (mayúsculas) |
| `%%` | Signo de porcentaje |

## Ejemplo de Uso

```c
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"

int main(void)
{
    // Operaciones con cadenas de Libft
    char *str = ft_strdup("¡Hola, Mundo!");
    ft_printf("Cadena: %s (longitud: %d)\n", str, ft_strlen(str));
    
    // Get next line
    int fd = open("archivo.txt", O_RDONLY);
    char *linea;
    while ((linea = get_next_line(fd)))
    {
        ft_printf("Leído: %s", linea);
        free(linea);
    }
    close(fd);
    
    // Especificadores de formato de Printf
    ft_printf("Hex: %x | %X\n", 255, 255);
    ft_printf("Puntero: %p\n", main);
    ft_printf("Sin signo: %u\n", 4294967295U);
    
    // Operaciones con listas
    t_list *lista = ft_lstnew(ft_strdup("primero"));
    ft_lstadd_back(&lista, ft_lstnew(ft_strdup("segundo")));
    
    // Limpieza
    ft_lstclear(&lista, free);
    free(str);
    
    return 0;
}
```

## Compilación con Tu Proyecto

```bash
# Compilar libraryC
make

# Compilar tu proyecto con libraryC
gcc -I./inc tu_programa.c -L. -lraryC -o tu_programa
```

## Configuración

### Tamaño del Buffer para get_next_line

Define `BUFFER_SIZE` antes de incluir el header para cambiar el tamaño del buffer de lectura:

```c
#define BUFFER_SIZE 1024
#include "get_next_line.h"
```

## Calidad del Código

- Cumple con los estándares de norminette de la escuela 42
- Sin fugas de memoria (verificado con valgrind)
- Maneja casos extremos y condiciones de error
- Estructura de cabeceras unificada para fácil integración

## Requisitos

- Compilador GCC
- Make
- Entorno tipo Unix (Linux, macOS o WSL)

## Licencia

Este proyecto forma parte del plan de estudios de la escuela 42 y sigue sus directrices académicas.
