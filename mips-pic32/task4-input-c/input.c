#include <p32xxxx.h>
/**
 * Зажечь лампочку RD10 (chipKIT #8) по нажатию кнопки RF1 (chipKIT #4).
 */

/**
 * Настраиваем пины ввода-вывода.
 */
void setup() {
    // режим вывода для ножки RD10 (установить бит PORTD[10] в 0)
    TRISDCLR = 1 << 10;

    // режим ввода для ножки RF1 (устновить бит PORTF[1] в 1)
    TRISFSET = 1 << 1;
}

/**
 * Прочитать текущее значение кнопки: 1 - вкл, 0 - выкл.
 */
int readButton() {
    if(PORTF & 1 << 1)
        return 1;
    else
        return 0;
}

/**
 * Будем читать кнопку в бесконечном цикле и в зависимости от значения переключать лампочку.
 */
void on_off() {
    while(1) {
        if(readButton()) {
            // установить значение - включить лампочку
            PORTDSET = 1 << 10;
        } else {
            // очистить значение - выключить лампочку
            PORTDCLR = 1 << 10;
        }
    }
}

void main() {  
    setup();

    on_off();
}
