#include "Topic.hpp"
#include "Parser.hpp"

Topic::Topic()
{
}

Topic::Topic(const Topic &copy) : Command(copy)
{
	*this = copy;
}

Topic::~Topic()
{
}

Topic &Topic::operator=(const Topic &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

Topic::Topic(Data &data)
{
	this->data = data;
}

bool Topic::handles(std::string command)
{
	std::vector<std::string> result;

	result = split(command);
	return result[0].compare("TOPIC")== 0;
}

//TOPIC <canal> [:<nuevo_tema>]
std::string Topic::execute(std::string command, std::string clientName)
{
	std::string channelName;
	std::string newTopic;
	std::vector<std::string> splitCommand;
	unsigned int posChannel;
	unsigned int posOperator;

	splitCommand = split(command);
	channelName = splitCommand[1];
	newTopic = splitCommand[2];
	posOperator = 0;
	while(posOperator < data.getOperators().size() && data.getOperators()[posOperator].compare(clientName) != 0)
	{
		posOperator++;
	}
	if (posOperator == data.getOperators().size())
		return "error: only operators can change the topic of the channel";
	posChannel = 0;
	while(posChannel < data.getChannels().size() && data.getChannels()[posChannel].getName().compare(channelName) != 0)
	{
		posChannel++;
	}
	if (posChannel < data.getChannels().size())
	{
		data.getChannels()[posChannel].setTopic(newTopic);
	}
	else
		return "error: canal no encontrado";
	return ("OK");
}
