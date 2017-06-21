#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "openhashing.h"

#define M 13

int main() {
    THash hash;
    hashInitialization(&hash, M);
    hashInsert(&hash, "A", 13);
    hashInsert(&hash, "POOL", 10);
    hashInsert(&hash, "AND", 20);
    hashInsert(&hash, "HIS", 30);
    hashInsert(&hash, "MONEY", 10);
    hashInsert(&hash, "ARE", 10);
    hashInsert(&hash, "SOON", 10);
    hashInsert(&hash, "PARTED", 10);
    hashPrint(&hash);
    return 0;
}
