#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <iostream>
#include "Data.hpp"

class Command
{
	private:

	protected:
		Data *data;

	public:
		Command();
		Command(const Command &copy);
		virtual ~Command();
		Command &operator=(const Command &copy);

		Command(Data *data);
		virtual bool handles(std::string command) = 0;
		virtual std::string execute(std::string command, size_t i) = 0;
};
#endif

/* Los comandos IRC

Comandos de mensajes
NOTICE: Enviar un mensaje de notificación a un usuario o canal.
MSG: Enviar un mensaje a un canal o usuario.
Comandos de informacións

WHO: Obtener información sobre los usuarios conectados a un canal.
WHOIS: Obtener información sobre un usuario específico.
Comandos de administración

OPER: Identificarse como operador del servidor IRC.
PASS: Establecer la contraseña de operador.
KILL: Desconectar a un usuario del servidor IRC.
Estos son solo algunos de los comandos IRC más comunes. Hay muchos otros comandos disponibles, dependiendo del servidor IRC y la implementación específica. */
