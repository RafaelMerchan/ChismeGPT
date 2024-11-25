# Proyecto: ChismeGPT

Este proyecto simula un sistema básico para procesar mensajes de dos tipos de usuarios: pre-pago y pos-pago. Los mensajes se procesan según reglas específicas para cada tipo de usuario.

---

## ¿Qué hace este programa?

1. **Núcleo (`core.c`)**:
   - Procesa mensajes de usuarios.
   - Prioriza mensajes de usuarios pos-pago.
   - Limita a 10 mensajes los enviados por usuarios pre-pago.
   - Maneja una cola de hasta 4 mensajes.

2. **Cliente (`client.c`)**:
   - Simula un cliente que envía mensajes uno por uno.


## Instrucciones para usar el programa

### Paso 1: Compilar los programas

Compilar core.c con:
	gcc core.c -o core
Compilar client.c con:
	gcc client.c -o client

### Paso 2: Ejecutar los programas

Abre una terminal y ejecuta el núcleo:
	./core
Abre otra terminal y ejecuta el cliente:
    	./client
**Cómo funciona**
    El núcleo recibe mensajes que envían los clientes.
    Procesa cada mensaje según las reglas:
        Los mensajes de usuarios pos-pago tienen prioridad.
        Los mensajes de usuarios pre-pago se limitan a 10.
    Cada mensaje tarda 500 ms en procesarse.

## Ejemplo de uso:
**Salida del núcleo (core.c):**

Procesando mensaje...
ID Usuario: 12
Tipo Usuario: P
Texto: Hola, soy el usuario 12
Mensaje procesado.

Procesando mensaje...
ID Usuario: 15
Tipo Usuario: R
Texto: Hola, soy el usuario 15
Mensaje procesado.

El usuario pre-pago ID 15 ha alcanzado su límite de mensajes.

**Salida del cliente (client.c):**

Cliente 1: Enviando mensaje 1...
Cliente 1: Enviando mensaje 2...
Cliente 1: Enviando mensaje 3...
