#ifndef HERO_H
#define HERO_H

#define MAX_NAME 100
#define MAX_POWER 200
#define MAX_DISTRICT 100

typedef enum {
    HERO,
    VILLAIN,
    ANTIHERO,
    NEUTRAL
} Role;

typedef enum {
    ACTIVE,
    SLEEPING,
    ON_MISSION,
    INJURED,
    IMPRISONED
} Status;

typedef struct {
    char nickname[MAX_NAME];
    Role role;
    char power[MAX_POWER];
    int threatLevel;
    char district[MAX_DISTRICT];
    Status status;
} Hero;

void printHero(const Hero* h);
Hero createHero(void);
void editHero(Hero* h);

#endif
