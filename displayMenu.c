#include <LiquidCrystal.h>

void display_selected (int selected_menu) {

	/* Determine selected menu*/
	if (selected_menu == i){
	  lcd.print("<");
	}  
	
};

/* 	Display either the first two or
	second two entries	*/
void display_menu (enum x, int y) {
	enum current_menu = x;
	int display_from = y;
	lcd.clear();
	for (i=0,J=display_from;i<2;i++,J++){
		lcd.setCursor(0, i);
		lcd.print(main_menu[current_menu][J]);
	}
}
