#include <stdio.h>
#include <stdbool.h>

#define REPEAT (1 << 0)
#define SHUFFLE (2 << 1)
#define PLAYLIST_VISIBLE (3 << 2)
#define EQUALIZER (4 << 3)
#define CROSSFADE (5 << 4)
#define SLEEP_TIMER (6 << 5)
#define NOTIFICATIONS (7 << 6)
#define MUTE (8 << 7)

void enable_settings(unsigned char *settings, unsigned char setting) {
    *settings |= setting;
}

void disable_settings(unsigned char *settings, unsigned char setting) {
    *settings &= ~setting;
}
bool is_setting_enabled(unsigned char settings, unsigned char setting) {
   return (settings & setting) != 0;
}
void display_all_settings(unsigned char settings) {
    printf("Current settings: \n");

    if (settings & REPEAT) {
        printf("REPEAT: ON\n");
    } else {
        printf("REPEAT: OFF\n");
    }

    if (settings & SHUFFLE) {
        printf("SHUFFLE: ON\n");
    } else {
        printf("REPEAT: OFF\n");
    }

    if (settings & PLAYLIST_VISIBLE) {
        printf("PLAYLIST VISIBLE: ON\n");
    } else {
        printf("PLAYLIST VISIBLE: OFF\n");
    }

    if (settings & EQUALIZER) {
        printf("EQUALIZER: ON\n");
    } else {
        printf("EQUALIZER: OFF\n");
    }

    if (settings & CROSSFADE) {
        printf("CROSSFADE: ON\n");
    } else {
        printf("CROSSFADE: OFF\n");
    }

    if (settings & SLEEP_TIMER) {
        printf("SLEED TIMER: ON\n");
    } else {
        printf("SLEEP TIMER: OFF\n");
    }

    if (settings & NOTIFICATIONS) {
        printf("NOTIFICATIONS: ON\n");
    } else {
        printf("NOTIFICATIONS: OFF\n");
    }

    if (settings & MUTE) {
        printf("MUTE: ON\n");
    } else {
        printf("MUTE: OFF\n");
    }
}

int main() {
    unsigned char settings = 0;

    enable_settings(&settings, REPEAT);
    disable_settings(&settings, SHUFFLE);
    is_setting_enabled(settings, EQUALIZER);
    display_all_settings(settings);

    return 0;
}
