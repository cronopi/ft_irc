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


NOTICE: Enviar un mensaje de notificación a un usuario o canal.
Comandos de informacións
WHO: Obtener información sobre los usuarios conectados a un canal.
WHOIS: verificar información sobre un usuario.
PING: Enviar un mensaje de ping al servidor IRC para comprobar su conectividad.
WHOIS: Obtener información sobre un usuario específico.
Comandos de administración

OPER: Identificarse como operador del servidor IRC.
PASS: Establecer la contraseña de operador.
KILL: Desconectar a un usuario del servidor IRC.
Estos son solo algunos de los comandos IRC más comunes. Hay muchos otros comandos disponibles, dependiendo del servidor IRC y la implementación específica. */


/*
	Si recibes CAP LS 302, responde con CAP END.
	Si recibes NICK, verifica si está en uso y responde adecuadamente.
	Si recibes USER, confirma que tienes ambos (NICK y USER) antes de permitir la conexión.
	Envía los mensajes de bienvenida (001, 002, etc.) para completar la conexión.

*/
