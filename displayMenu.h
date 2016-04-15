/* Resources */
#ifndef MAIN_H_   /* Guard */
#define MAIN_H_

enum menu_number {

	MAINMENU = 0,
	CONTROL,
	MANUAL,
	SETVALUES,
	TEMPERATURE,
	HUMIDITY,

	SET,
	BACK,
	STANDBY
};

// Display menu strings
			//		___ MENU
			//		   ___ SUBMENU
			//			  ___ MEGETHOS LEKSIS
const char main_menu[6][3][14] = {
	{ 	"1.SET VALUES",
		"2.CONTROL", 
		""}

	{ "1.AUTO","2.MANUAL","3.BACK"}

	{ "1.TEMPERATURE","2.HUMIDITY","3.BACK"}

	{ "1.TEMPERATURE","2.HUMIDITY","3.BACK"}	

	{ "1.SET","2.BACK", ""}

	{ "1.SET","2.BACK", ""}
}
void display_menu (enum);
void display_selected (int);

#endif // MAIN_H_
