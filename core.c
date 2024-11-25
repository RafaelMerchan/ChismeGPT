#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Message {
    int id;
    char type;
    char text[256];
};

void processMessage(struct Message *msg) {
    printf("Procesando mensaje...\n");
    printf("ID Usuario: %d\n", msg->id);
    printf("Tipo Usuario: %c\n", msg->type);
    printf("Texto: %s\n", msg->text);
    usleep(500000);
    printf("Mensaje procesado.\n\n");
}

int main() {
    struct Message msgQueue[4];
    int queueSize = 0;
    int prepayCounts[100] = {0};

    printf("Core iniciado. Esperando mensajes...\n");

    while (1) {
        struct Message newMessage;
        newMessage.id = rand() % 100;
        newMessage.type = (rand() % 2 == 0) ? 'R' : 'P';
        snprintf(newMessage.text, 256, "Hola, soy el usuario %d", newMessage.id);

        if (queueSize < 4) {
            msgQueue[queueSize] = newMessage;
            queueSize++;
        } else {
            printf("Cola llena. Mensaje descartado.\n");
            usleep(300000);
            continue;
        }

        for (int i = 0; i < queueSize; i++) {
            struct Message *currentMsg = &msgQueue[i];

            if (currentMsg->type == 'R' && prepayCounts[currentMsg->id] >= 10) {
                printf("El usuario pre-pago ID %d ha alcanzado su límite de mensajes.\n", currentMsg->id);
            } else {
                if (currentMsg->type == 'R') {
                    prepayCounts[currentMsg->id]++;
                }
                processMessage(currentMsg);
            }
        }

        queueSize = 0;
    }

    return 0;
}
