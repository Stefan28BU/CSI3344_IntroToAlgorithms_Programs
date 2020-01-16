//============================================================================
// Name        : Alphabet.h
// Author      : Mackensi Holt
// Project     : Matrix Multiplication
// Description : Functions for drawing letters to the screen
// Date Created: 11/29/2018
//============================================================================

#ifndef GP_DVC_ALPHA_H
#define GP_DVC_ALPHA_H

//Description: plots a square of pixels on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a square is drawn on the SDL_Plotter
void drawSquare(SDL_Plotter *g, int i0, int j0, int R, int G, int B, int scale = 0){
    for(int i = i0; i < 3 + scale + i0; i++){
        for(int j = j0; j < 3 + scale + j0; j++){
            g->plotPixel(i,j,R,G,B);
        }
    }
}

//Description: plots an apostrophe on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an apostrophe is drawn on the SDL_Plotter
void drawApos(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,0,0},
            {0,0,1,0},
            {0,0,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'A' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'A' is drawn on the SDL_Plotter
void drawA(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'B' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'B' is drawn on the SDL_Plotter
void drawB(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'C' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'C' is drawn on the SDL_Plotter
void drawC(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {0,1,1,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'D' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'D' is drawn on the SDL_Plotter
void drawD(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'E' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'E' is drawn on the SDL_Plotter
void drawE(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,1,1,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,1,1,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'F' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'F' is drawn on the SDL_Plotter
void drawF(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,1,1,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'G' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'G' is drawn on the SDL_Plotter
void drawG(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'H' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'H' is drawn on the SDL_Plotter
void drawH(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'I' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'I' is drawn on the SDL_Plotter
void drawI(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][4] = {
            {1,1,1,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {1,1,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 4 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'J' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'J' is drawn on the SDL_Plotter
void drawJ(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,1,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {1,0,1,0,0},
            {1,0,1,0,0},
            {1,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'K' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'K' is drawn on the SDL_Plotter
void drawK(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][6] = {
            {1,0,0,0,1,0},
            {1,0,0,1,0,0},
            {1,0,1,0,0,0},
            {1,1,0,0,0,0},
            {1,0,1,0,0,0},
            {1,0,0,1,0,0},
            {1,0,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 6 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'L' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'L' is drawn on the SDL_Plotter
void drawL(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,1,1,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'M' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'M' is drawn on the SDL_Plotter
void drawM(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][6] = {
            {1,0,0,0,1,0},
            {1,1,0,1,1,0},
            {1,0,1,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 6 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'N' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'N' is drawn on the SDL_Plotter
void drawN(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,1,0},
            {1,1,0,1,0},
            {1,1,0,1,0},
            {1,0,1,1,0},
            {1,0,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'O' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'O' is drawn on the SDL_Plotter
void drawO(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'P' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'P' is drawn on the SDL_Plotter
void drawP(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'Q' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'Q' is drawn on the SDL_Plotter
void drawQ(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[8][6] = {
            {0,1,1,1,0,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,1,0,1,0},
            {0,1,1,1,0,0},
            {0,0,0,0,1,0}   };

    for(int i = y; i < 8 + y; i++){
        for(int j = x; j < 6 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'R' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'R' is drawn on the SDL_Plotter
void drawR(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,0,0},
            {1,0,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots an 'S' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: an 'S' is drawn on the SDL_Plotter
void drawS(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,1,1,1,0},
            {0,0,0,1,0},
            {0,0,0,1,0},
            {1,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'T' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'T' is drawn on the SDL_Plotter
void drawT(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][4] = {
            {1,1,1,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 4 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'U' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'U' is drawn on the SDL_Plotter
void drawU(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'V' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'V' is drawn on the SDL_Plotter
void drawV(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][6] = {
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {0,1,0,1,0,0},
            {0,1,0,1,0,0},
            {0,0,1,0,0,0},
            {0,0,1,0,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 6 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'X' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'X' is drawn on the SDL_Plotter
void drawX(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'Y' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'Y' is drawn on the SDL_Plotter
void drawY(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,1,0},
            {0,0,0,1,0},
            {0,0,0,1,0},
            {1,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '0' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '0' is drawn on the SDL_Plotter
void draw0(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,1,1,0},
            {1,1,1,1,0},
            {1,1,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '1' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '1' is drawn on the SDL_Plotter
void draw1(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,0,0},
            {1,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {0,0,1,0,0},
            {1,1,1,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '2' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '2' is drawn on the SDL_Plotter
void draw2(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,0,0},
            {1,0,0,1,0},
            {0,0,0,1,0},
            {0,0,1,0,0},
            {0,1,0,0,0},
            {1,0,0,0,0},
            {1,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '3' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '3' is drawn on the SDL_Plotter
void draw3(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,1,0},
            {0,0,0,1,0},
            {0,1,1,0,0},
            {0,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '4' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '4' is drawn on the SDL_Plotter
void draw4(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,1,0},
            {0,0,0,1,0},
            {0,0,0,1,0},
            {0,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '5' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '5' is drawn on the SDL_Plotter
void draw5(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {1,1,1,0,0},
            {0,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '6' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '6' is drawn on the SDL_Plotter
void draw6(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {1,1,1,0,0},
            {0,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '7' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '7' is drawn on the SDL_Plotter
void draw7(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {1,1,1,1,0},
            {0,0,0,1,0},
            {0,0,1,0,0},
            {0,1,1,0,0},
            {0,1,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '8' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '8' is drawn on the SDL_Plotter
void draw8(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,0,0,1,0},
            {0,1,1,0,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a '9' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a '9' is drawn on the SDL_Plotter
void draw9(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,1,1,0},
            {1,0,0,1,0},
            {0,0,0,1,0},
            {0,1,1,1,0},
            {0,0,0,1,0},
            {0,0,0,1,0},
            {0,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'n' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'n' is drawn on the SDL_Plotter
void draw_n(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][6] = {
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {1,0,1,1,0,0},
            {1,1,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0},
            {1,0,0,0,1,0}   };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 6 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'x' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'x' is drawn on the SDL_Plotter
void draw_x(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][6] = {
            {0,0,0,0,0,0},
            {1,0,0,0,1,0},
            {0,1,0,1,0,0},
            {0,0,1,0,0,0},
            {0,1,0,1,0,0},
            {1,0,0,0,1,0},
            {0,0,0,0,0,0}    };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 6 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 't' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 't' is drawn on the SDL_Plotter
void draw_t(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,0,0,0},
            {0,1,0,0,0},
            {1,1,1,0,0},
            {0,1,0,0,0},
            {0,1,0,0,0},
            {0,1,0,1,0},
            {0,0,1,0,0}    };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'i' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'i' is drawn on the SDL_Plotter
void draw_i(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,1,0,0,0},
            {0,0,0,0,0},
            {1,1,0,0,0},
            {0,1,0,0,0},
            {0,1,0,0,0},
            {0,1,0,1,0},
            {0,0,1,0,0}    };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'm' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'm' is drawn on the SDL_Plotter
void draw_m(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][8] = {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {1,0,1,1,0,1,1,0},
            {0,1,0,0,1,0,0,1},
            {0,1,0,0,1,0,0,1},
            {0,1,0,0,1,0,0,1},
            {0,1,0,0,1,0,0,1}    };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 8 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}

//Description: plots a 'e' on the SDL_Plotter
//Return:void
//Precondition: an SDL_Plotter exists and is running
//Postcondition: a 'e' is drawn on the SDL_Plotter
void draw_e(SDL_Plotter *g, int x, int y, int R, int G, int B, int scale = 2, int offset = 0){

    int letter[7][5] = {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,1,1,0,0},
            {1,0,0,1,0},
            {1,1,1,1,0},
            {1,0,0,0,0},
            {0,1,1,1,0}    };

    for(int i = y; i < 7 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letter[i-y][j-x] == 1){
                drawSquare(g, j*scale, i*scale, R, G, B, offset);
            }
        }
    }
}


#endif //GP_DVC_ALPHA_H
