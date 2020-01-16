#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CmdRec{
    char cmdName[13];
    int cmdCount;
}CmdRec;

int main() {
    CmdRec **cmdDbptr = (CmdRec**)malloc(500 * sizeof(CmdRec*));
    char *buffer = (char*)malloc((sizeof(char))*13);
    FILE *fp;
    char chArr[40] = {'\0'};
    char cmd[12] = {'\0'};
    int count1 = 0;
    int count2 = 0;

    fp = fopen("bash_history", "r");
    char ch;
    int fc = 0;
    //while (fgets(chArr, sizeof(chArr), stdin)) {
    while (fread(&ch,1,1,fp) == 1 ) {
        //while (fread(chArr, sizeof(char),1,stdin) == 1 ) {

        chArr[fc] = ch;

        fc++;

    }
    printf("%s", chArr);

    int cc = 0;
/*
    for (int s = 0; s < fc; s ++) {
        int bool1 = 0;


        cmd[s] = chArr[s];

        if (chArr[s] == ' ') {
            chArr[s] = '\0';
        }
        //printf("%d", cc);
        printf("%c", cmd[s]);
        bool1 = 0;

        //char *ptr;

        for (int j = 0; j < count2; j ++) {
            if (!strcmp(cmd, cmdDbptr[j]->cmdName)) {
                cmdDbptr[j]->cmdCount++;
                bool1 = 1;
            }
        }
        if (!bool1) {
            CmdRec *cmdptr = malloc(sizeof(CmdRec));
            strcpy(cmdptr->cmdName, cmd);
            cmdptr->cmdCount = 1;
            cmdDbptr[count2] = cmdptr;
            count2 ++;
        }
        count1++;

    }*/
    fclose(fp);
    printf("%d    \n", cc);
    printf("command     freq\n");
    int count3 = 0;

    do {
        int space;

        printf("%s", cmdDbptr[count3]->cmdName);

        if (cmdDbptr[count3]->cmdCount > 9) {
            space = 14 - strlen(cmdDbptr[count3]->cmdName);
            if (cmdDbptr[count3]->cmdCount > 99) {
                space = 13 - strlen(cmdDbptr[count3]->cmdName);
                if (cmdDbptr[count3]->cmdCount > 999) {
                    space = 12 - strlen(cmdDbptr[count3]->cmdName);
                }
            }
        }

        else {
            space = 15 - strlen(cmdDbptr[count3]->cmdName);
        }

        while (space > 0 ) {
            putchar(' ');
            space--;
        }
        printf("%d\n", cmdDbptr[count3]->cmdCount);
        count3 ++;
    } while (count3 < count1 && cmdDbptr[count3] != NULL);

    for (int i = 0; i < 500; i ++) {
        free(cmdDbptr[i]);
    }
    free(cmdDbptr);

    return 0;
}