#include <iostream>
#include <libserialport.h>
#include<windows.h>


int main()
{

	// H�mta en port med namnet p� den
	struct sp_port* port;

	//Jag brukar koppla in min arduino i COM4-porten
	sp_return error = sp_get_port_by_name("COM4", &port);
	if (SP_OK != error)
	{
		std::cerr << "Error getting port: " << sp_last_error_message() << std::endl;
		return 1;
	}


	// �ppna en port f�r l�sning 
	error = sp_open(port, SP_MODE_READ);
	if (SP_OK != error)
	{
		std::cerr << "Error opening port: " << sp_last_error_message() << std::endl;
		sp_free_port(port);
		return 1;
	}




	//Matcha arduino-inst�llningarna f�r porten
	// s� att den matchar v�r ardunio.
	sp_set_baudrate(port, 9600);
	sp_set_bits(port, 8);
	sp_set_parity(port, SP_PARITY_NONE);
	sp_set_stopbits(port, 1);



	// L�sa data fr�n port

	while (true)
	{
		char buffer[256];
		int bytesRead = sp_blocking_read(port, buffer, sizeof(buffer), 1000);
		if (bytesRead <= 0) {
			std::cerr << "Error reading data: " << sp_last_error_message() << std::endl;
		}
		else {
			int a = 0;
			for (int i = 0; i < bytesRead; i++)
			{
				a += (buffer[i] * (2 ^ i));
			}
			std::cout << "Reading " << a << std::endl;
			a = 0;
		}
	}

	// St�ng och st�da upp sist i programmet
	sp_close(port);
	sp_free_port(port);

}

