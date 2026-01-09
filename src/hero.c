#include <stdio.h>
#include "hero.h"
#include "utils.h"

const char* roleToStr(Role r) {
    return (const char* []) { "Hero", "Villain", "Antihero", "Neutral" } [r] ;
}

const char* statusToStr(Status s) {
    return (const char* []) { "Active", "Sleeping", "On mission", "Injured", "Imprisoned" } [s] ;
}

Hero createHero(void) {
    Hero h;
    readString("Nickname: ", h.nickname, MAX_NAME);
    h.role = readInt("Role (0-Hero 1-Villain 2-Antihero 3-Neutral): ", 0, 3);
    readString("Power: ", h.power, MAX_POWER);
    h.threatLevel = readInt("Threat level (0-10): ", 0, 10);
    readString("District: ", h.district, MAX_DISTRICT);
    h.status = readInt("Status (0-Active 1-Sleeping 2-Mission 3-Injured 4-Imprisoned): ", 0, 4);
    return h;
}

void printHero(const Hero* h) {
    printf("%-15s | %-10s | %-10d | %-15s | %-12s | %s\n",
        h->nickname,
        roleToStr(h->role),
        h->threatLevel,
        h->district,
        statusToStr(h->status),
        h->power);
}

void editHero(Hero* h) {
    readString("New power: ", h->power, MAX_POWER);
    h->threatLevel = readInt("New threat level (0-10): ", 0, 10);
    readString("New district: ", h->district, MAX_DISTRICT);
    h->status = readInt("New status (0-4): ", 0, 4);
}
