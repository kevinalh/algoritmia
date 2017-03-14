#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 350

void nombre_programa(char*, char*);

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Uso: %s file\n", argv[0]);
        return 0;
    }
    FILE *fp, *fw;
    char originalfile[MAX_LINE];
    strcpy(originalfile, argv[1]);
    if((fp = fopen(originalfile, "r")) == NULL) {
        printf("No se puede abrir el archivo: %s\n", originalfile);
        return 0;
    }
    char filename[MAX_LINE];
    if(argc >= 3) {
        strcpy(filename, argv[2]);
        fw = fopen(filename, "w");
    } else {
        snprintf(filename, sizeof(filename), "%s-tmp", originalfile);
        fw = fopen(filename, "w");
    }
    char line[MAX_LINE];
    char line2[MAX_LINE];
    char nombre[MAX_LINE];
    char nuevoc[MAX_LINE];
    strcpy(nuevoc, ".c");
    int copiado = 0;
    FILE *ft; // Archivos temporales de C
    while(fgets(line, sizeof(line), fp)) {
        if(copiado == 1) {
            copiado = strstr(line, "~~~") == line ? 0 : 1;
            if (copiado == 0) fputs(line, fw);
        } else if(strstr(line, "~~~") == line) {
            fputs(line, fw);
            nombre_programa(nombre, line);
            strcat(nombre, nuevoc);
            printf("%s\n", nombre);
            ft = fopen(nombre, "r");
            if(ft  == NULL) {
                printf("No se pudo abrir %s\n", nombre);
                return 1;
            } else {
                while(fgets(line2, sizeof(line2), ft)) {
                    fputs(line2, fw);
                }
                fclose(ft);
                copiado = 1;
            }
        } else {
            fputs(line, fw);
        }
    }
    char filenametmp[MAX_LINE];
    char originalfilebk[MAX_LINE];
    strcpy(filenametmp, ".bk");
    strcpy(originalfilebk, originalfile);
    strcat(originalfilebk, filenametmp);
    rename(originalfile, originalfilebk);
    rename(filename, originalfile);
    fclose(fp);
    fclose(fw);
    return 0;
}

void nombre_programa(char nombre[], char line[]) {
    const char* puntero;
    const char* puntero2;
    if(puntero = strstr(line, "#")) {
        puntero2 = strstr(puntero, " ");
        size_t len = puntero2 - puntero;
        strncpy(nombre, ++puntero, --len);
        nombre[len] = '\0';
    } else {
        printf("No se consiguió el ID de una línea\n");
    }
    return;
}
