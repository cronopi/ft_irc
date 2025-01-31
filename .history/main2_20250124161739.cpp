// main.cpp

#include "Join.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    Join join(data);

    // Probar el acceso a los datos de Data a través de Join
    std::cout << "Clientes: " << join.getData().getClients().size() << std::endl;
    std::cout << "Canales: " << join.getData().getChannels().size() << std::endl;

    // Probar la modificación de los datos de Data a través de Join
    join.getData().addClient("cliente1");
    join.getData().addChannel("canal1");

    std::cout << "Clientes: " << join.getData().getClients().size() << std::endl;
    std::cout << "Canales: " << join.getData().getChannels().size() << std::endl;

    return 0;
}
