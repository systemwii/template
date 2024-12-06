#include "console.h"    // implicitly includes <stdio.h>, <gccore.h>

int main() {
    consoleInit();
    int buttons, ctr, presses;
    int fps = 30;
start:
    buttons = 0; ctr = 0; presses = 0;
    consoleClear();
    printf(CON_BLACK(CON_BGCYAN(" mash test ") " " CON_BGYELLOW(" %d fps ")) "\n", fps);
    printf("mash a/b/start; i will count inputs registered each second\n");
    printf("maximum is fps/2 with single button or fps with multiple buttons\n");
	printf("please ensure your console is set to 60Hz\n");
    printf("press x to restart, y to toggle 30/60 fps, z to exit\n\n");
    printf("press any combo of a/b/start to select buttons to listen to...\n");
    while (padScanOnNextFrame()) {
        buttons = PAD_ButtonsDown(0) & (PAD_BUTTON_A | PAD_BUTTON_B | PAD_BUTTON_START);
        if (PAD_ButtonsDown(0) & PAD_BUTTON_Y) {
            fps = fps == 30 ? 60 : 30; goto start;
        } else if (PAD_ButtonsDown(0) & PAD_TRIGGER_Z) {
            printf("\nexiting..."); return 0;
        } else if (buttons) {
            printf("%s", buttons & PAD_BUTTON_A ? "a " : "");
            printf("%s", buttons & PAD_BUTTON_B ? "b " : "");
            printf("%s", buttons & PAD_BUTTON_START ? "start " : "");
            printf("selected\n");
            break;
        }
    }
    while (padScanOnNextFrame()) {
        if (fps == 30) {VIDEO_WaitVSync();} // wait 1f to slow down to 30 fps
        if (ctr % fps == 0) {
            if (presses != 0) {printf(" %d\n", presses); presses = 0;}
            ctr = 0; presses = 0;
        }
        if (PAD_ButtonsDown(0) & PAD_BUTTON_X) {
            goto start;
        } else if (PAD_ButtonsDown(0) & PAD_BUTTON_Y) {
            fps = fps == 30 ? 60 : 30; goto start;
        } else if (PAD_ButtonsDown(0) & PAD_TRIGGER_Z) {
            printf("\nexiting..."); return 0;
        } else if (PAD_ButtonsDown(0) & buttons) {
            printf(".");
            presses++;
        } 
        ctr++;
    }
	printf("\ncontroller disconnected ._.\n");
    return 0;
}
