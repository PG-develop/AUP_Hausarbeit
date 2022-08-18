/* *******************************************************************************************
* Autor:				Patrick Gehrt
* Matr.Nr.:				214849
* 
* Erstelldatum:			08.08.2022
* letzte Bearbeitung:	18.08.2022
*
* Fach:					Algorithmen und Programmieren
* KursNr.:				I_ET_B_026
* Dozent:				Prof. Dr. Fröse
*
* Titel:				Zahlenratespiel
* 
* Beschreibung:
* In diesem Programm soll der Anwender eine zufällige generierte Zahl eraten. Die Zahl soll
* innerhalb zweier Grenzen generiert werden.
*
******************************************************************************************** */
#include <iostream>

#include "Application.hpp"

int main() {

	try
	{
		// Instanz - Anwendung instanziieren und ausführen
		std::unique_ptr<AUP_HA::Application> app(new AUP_HA::Application);
		app->run();
	}

	// Wenn einer unbehandelter Fehler auftritt, wird dieser hier bearbeitet.
	// z.B. für ein Fehlerlog
	catch (const std::exception& e)
	{
		std::cout << "Es ist ein unbehandelter Fehler aufgetreten: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}