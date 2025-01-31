#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <iostream>
#include "Data.hpp"

class Command
{
	private:

	protected:
		Data data;

	public:
		Command();
		Command(const Command &copy);
		virtual ~Command();
		Command &operator=(const Command &copy);

		Command(Data &data);
		virtual bool handles(std::string command) = 0;
		virtual std::string execute(std::string command, std::string clientName) = 0;
};
#endif

/* Los comandos IRC

Comandos básicos

JOIN: Unirse a un canal.
PART: Dejar un canal.
QUIT: Desconectarse del servidor IRC.
NICK: Cambiar el nombre de usuario.
USER: Identificarse con el servidor IRC.
Comandos de canales

TOPIC: Establecer o cambiar el tema de un canal.
MODE: Cambiar los modos de un canal (por ejemplo, +o para dar permisos de operador).
INVITE: Invitar a un usuario a unirse a un canal.
KICK: Expulsar a un usuario de un canal.
Comandos de mensajes

PRIVMSG: Enviar un mensaje privado a un usuario.
NOTICE: Enviar un mensaje de notificación a un usuario o canal.
MSG: Enviar un mensaje a un canal o usuario.
Comandos de información

WHO: Obtener información sobre los usuarios conectados a un canal.
WHOIS: Obtener información sobre un usuario específico.
LIST: Obtener una lista de los canales disponibles.
Comandos de administración

OPER: Identificarse como operador del servidor IRC.
PASS: Establecer la contraseña de operador.
KILL: Desconectar a un usuario del servidor IRC.
Estos son solo algunos de los comandos IRC más comunes. Hay muchos otros comandos disponibles, dependiendo del servidor IRC y la implementación específica. */
