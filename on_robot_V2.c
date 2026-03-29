/* Program to turn on the robot */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h> //Configuração de portas seriais

int main() 
{
    int fd;
    struct termios options;

    fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY); //Habilita leitura + escrita e ???

    if (fd < 0) 
    {
        perror("Erro ao abrir porta");
        return 1;
    }

    tcgetattr(fd, &options); //Pega configurações atuais da porta

    cfsetispeed(&options, B115200); //Ajusta velocidade de leitura
    cfsetospeed(&options, B115200); //Ajusta velocidade de saída

    options.c_cflag |= (CLOCAL | CREAD); //Ativa leitura e impede interferências
    options.c_cflag &= ~PARENB; //Desativa paridade -detecção de erro
    options.c_cflag &= ~CSTOPB; //Ativa bit de parada de transmissão
    options.c_cflag &= ~CSIZE; //Limpa configração anterior
    options.c_cflag |= CS8; //Define tamanho opara 8 bits

    tcsetattr(fd, TCSANOW, &options); //Carrega configurações na porta (8N1)

    unsigned char command = 128;

    write(fd, &command, 1);

    close(fd);

    return 0;
}