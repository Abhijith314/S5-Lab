#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {
    FILE *f1, *f2, *f3, *f4;
    char s[100], lab[30], opcode[30], opa[30], opcode1[30], opa1[30];
    int locctr, x = 0;
    f1 = fopen("inputprgm.txt", "r");
    f2 = fopen("optab.txt", "r");
    f3 = fopen("pass1out.txt", "w");
    f4 = fopen("symtab.txt", "w");

    while (fscanf(f1, "%s %s %s", lab, opcode, opa) != EOF) {
        if (strcmp(lab, "**") == 0) {
            if (strcmp(opcode, "START") == 0) {
                fprintf(f3, "%s %s %s", lab, opcode, opa);
                locctr = (int)strtol(opa, NULL, 16);
            } else {
                rewind(f2);
                x = 0;
                while (fscanf(f2, "%s%s", opcode1, opa1) != EOF) {
                    if (strcmp(opcode, opcode1) == 0) {
                        x = 1;
                    }
                }
                if (x == 1) {
                    fprintf(f3, "\n%X %s %s %s", locctr, lab, opcode, opa);
                    locctr += 0x03;
                }
            }
        } else {
            if (strcmp(opcode, "RESW") == 0) {
                fprintf(f3, "\n%X %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "%X %s\n", locctr, lab);
                locctr += 0x03 * atoi(opa);
            } else if (strcmp(opcode, "WORD") == 0) {
                fprintf(f3, "\n%X %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "%X %s\n", locctr, lab);
                locctr += 0x03;
            } else if (strcmp(opcode, "BYTE") == 0) {
                fprintf(f3, "\n%X %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "%X %s\n", locctr, lab);
                locctr += 0x01;
            } else if (strcmp(opcode, "RESB") == 0) {
                fprintf(f3, "\n%X %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "%X %s\n", locctr, lab);
                locctr += 0x01 * atoi(opa);
            } else {
                fprintf(f3, "\n%X %s %s %s", locctr, lab, opcode, opa);
                fprintf(f4, "%X %s\n", locctr, lab);
                locctr += atoi(opa);
            }
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}