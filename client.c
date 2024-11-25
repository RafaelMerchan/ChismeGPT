#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sendMessage(int clientId) {
    for (int i = 0; i < 5; i++) {
        printf("Cliente %d: Enviando mensaje %d...\n", clientId, i + 1);
        sleep(1);
    }
}

int main() {
    int clientId = rand() % 100;
    printf("Cliente iniciado con ID: %d\n", clientId);

    sendMessage(clientId);

    printf("Cliente %d terminó de enviar mensajes.\n", clientId);
    return 0;
}
