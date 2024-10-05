#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>


int server_fd = -1;
struct sockaddr_in server_address;

void CreateSocket()
{
    if (server_fd >= 0)
    {
        std::cout << "Error1" << std::endl;
        return;
    }
    server_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        std::cout << "Error2" << std::endl;
        return;
    }

    int enable = 1;
    int r = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

}

void BindSocket()
{
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(80);


    int r = bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    if (r < 0)
    {
        std::cout << "Error - Binding" << std::endl;
        return;
    }
}

void Listen()
{
    int r = listen(server_fd, 128);

    if (r < 0)
    {
        std::cout << "Error - Listen" << std::endl;
        return;
    }
    struct sockaddr_in client_address;
    socklen_t address_length = sizeof(client_address);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &address_length);
    if (client_fd < 0)
    {
        std::cout << "Error - Accept" << std::endl;
    }

    std::cout << "Client accept" << std::endl;
    while(1);
}

void Run()
{
    while(true)
    {
        Listen();
    }
}

int main() {
    std::cout << "Server Running" << std::endl;
    CreateSocket();
    BindSocket();
    Run();
    return 0;
}

