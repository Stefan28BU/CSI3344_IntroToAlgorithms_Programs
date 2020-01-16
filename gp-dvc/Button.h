//
// Created by 徐宇帆 on 18/12/1.
//

#ifndef GP_DVC_BUTTON_H
#define GP_DVC_BUTTON_H

#include "SDL_Plotter.h"
#include "Alpha.h"

struct Color{
    int R, G, B;
};

class Button{
private:
    int x, y;
    int len, height;
    char type;
    Color Light;
    Color Norm;
    Color Dark;

    void setColors();
    void drawLighterElements(SDL_Plotter *g);
    void drawDarkerElements(SDL_Plotter *g);
    void drawButton_B(SDL_Plotter *g);
    void drawButton_D(SDL_Plotter *g);
    void drawButton_S(SDL_Plotter *g);
    void drawButton_T(SDL_Plotter *g);

public:
    Button(char type, int x, int y, int len, int height){
        this->type = type;
        this->x = x;
        this->y = y;
        this->len = len;
        this->height = height;

        this->setColors();
    }

    void draw(SDL_Plotter *g);
    bool isButton(int x, int y);
    void swapColors();
    void highlight(bool swap);
    void resetColor();
};

/*
 *    description: draw a button to the screen
 *  pre-condition:
 * post-condition:
 *         return: void
 */
void Button::draw(SDL_Plotter *g){
    if(this->type == 'B'){
        this->drawButton_B(g);
    }
    else if(this->type == 'D'){
        this->drawButton_D(g);
    }
    else if(this->type == 'S'){
        this->drawButton_S(g);
    }
    else if(this->type == 'T'){
        this->drawButton_T(g);
    }
}


bool Button::isButton(int x, int y) {
    bool isButton = false;

    if( (x >= this->x) && (x <= this->x + this->len) ){
        if( (y >= this->y) && (y <= this->y + this->height) ){
            isButton = true;
        }
    }

    return isButton;
}

void Button::swapColors(){
    int temp;

    temp = this->Light.R;
    this->Light.R = this->Dark.R;
    this->Dark.R = temp;

    temp = this->Light.G;
    this->Light.G = this->Dark.G;
    this->Dark.G = temp;

    temp = this->Light.B;
    this->Light.B = this->Dark.B;
    this->Dark.B = temp;
}

void Button::setColors(){
    if(this->type == 'B'){
        this->Norm.R = 0;
        this->Norm.G = 102;
        this->Norm.B = 255;

        this->Light.R = 102;
        this->Light.G = 163;
        this->Light.B = 255;

        this->Dark.R = 0;
        this->Dark.G = 71;
        this->Dark.B = 179;
    }
    else if(this->type == 'D'){
        this->Norm.R = 230;
        this->Norm.G = 0;
        this->Norm.B = 0;

        this->Light.R = 255;
        this->Light.G = 102;
        this->Light.B = 102;

        this->Dark.R = 153;
        this->Dark.G = 0;
        this->Dark.B = 0;
    }
    else if(this->type == 'S'){
        this->Norm.R = 0;
        this->Norm.G = 153;
        this->Norm.B = 51;

        this->Light.R = 0;
        this->Light.G = 204;
        this->Light.B = 68;

        this->Dark.R = 0;
        this->Dark.G = 102;
        this->Dark.B = 34;
    }
    else if(this->type == 'T'){
        this->Norm.R = 153;
        this->Norm.G = 0;
        this->Norm.B = 204;

        this->Light.R = 210;
        this->Light.G = 77;
        this->Light.B = 255;

        this->Dark.R = 96;
        this->Dark.G = 0;
        this->Dark.B = 128;
    }
}

void Button::highlight(bool swap){
    if(this->type == 'B'){
        this->Norm.R = 51;
        this->Norm.G = 133;
        this->Norm.B = 255;

        this->Light.R = 153;
        this->Light.G = 194;
        this->Light.B = 255;

        this->Dark.R = 0;
        this->Dark.G = 92;
        this->Dark.B = 230;
    }
    else if(this->type == 'D'){
        this->Norm.R = 255;
        this->Norm.G = 26;
        this->Norm.B = 26;

        this->Light.R = 255;
        this->Light.G = 153;
        this->Light.B = 153;

        this->Dark.R = 204;
        this->Dark.G = 0;
        this->Dark.B = 0;
    }
    else if(this->type == 'S'){
        this->Norm.R = 0;
        this->Norm.G = 179;
        this->Norm.B = 60;

        this->Light.R = 0;
        this->Light.G = 230;
        this->Light.B = 77;

        this->Dark.R = 0;
        this->Dark.G = 128;
        this->Dark.B = 43;
    }
    else if(this->type == 'T'){
        this->Norm.R = 191;
        this->Norm.G = 0;
        this->Norm.B = 255;

        this->Light.R = 223;
        this->Light.G = 128;
        this->Light.B = 255;

        this->Dark.R = 134;
        this->Dark.G = 0;
        this->Dark.B = 179;
    }
    if(swap){
        this->swapColors();
    }
}

void Button::resetColor(){
    this->setColors();
}

void Button::drawLighterElements(SDL_Plotter *g){
    int R = this->Light.R;
    int G = this->Light.G;
    int B = this->Light.B;

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < this->len - j; i++){
            g->plotPixel(this->x + i, this->y + j, R,G,B);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < this->height - i; j++){
            g->plotPixel(this->x + i, this->y + j, R,G,B);
        }
    }

    for(int k = 0; k < this->height - 12; k++){
        g->plotPixel(this->x + 6, this->y + 6 + k, R,G,B);
        g->plotPixel(this->x + this->len - 7, this->y + 6 + k, R,G,B);
    }
    for(int k = 0; k < this->len - 13; k++){
        g->plotPixel(this->x + 6 + k, this->y + 6, R,G,B);
        g->plotPixel(this->x + 6 + k, this->y + this->height - 8, R,G,B);
    }
}

void Button::drawDarkerElements(SDL_Plotter *g){
    int R = this->Dark.R;
    int G = this->Dark.G;
    int B = this->Dark.B;

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < this->len - j; i++){
            g->plotPixel(this->x + this->len - i - 1, this->y + this->height - j, R,G,B);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < this->height - i; j++){
            g->plotPixel(this->x + this->len - i - 1, this->y + this->height - j, R,G,B);
        }
    }

    for(int k = 1; k < this->height - 12; k++){
        g->plotPixel(this->x + 7, this->y + 6 + k, R,G,B);
        g->plotPixel(this->x + this->len - 6, this->y + 6 + k, R,G,B);
    }
    for(int k = 0; k < this->len - 14; k++){
        g->plotPixel(this->x + 7 + k, this->y + 7, R,G,B);
        g->plotPixel(this->x + 7 + k, this->y + this->height - 7, R,G,B);
    }

    g->plotPixel(this->x + this->len - 7, this->y + this->height - 7, R,G,B);
}



//brute force
void Button::drawButton_B(SDL_Plotter *g){

    // draw rectangle
    for(int i = 0; i < this->len; i++){
        for(int j = 0; j < this->height; j++){
            g->plotPixel(this->x + i, this->y + j, Norm.R, Norm.G, Norm.B);
        }
    }

    //draw lighter elements
    drawLighterElements(g);

    //draw darker elements
    drawDarkerElements(g);

    //draw words
    int x = this->x/2 + 7;
    int y = this->y/2 + 11;

    drawB(g, x, y, 255, 255, 255);
    drawR(g, x + 5, y, 255, 255, 255);
    drawU(g, x + 10, y, 255, 255, 255);
    drawT(g, x + 15, y, 255, 255, 255);
    drawE(g, x + 19, y, 255, 255, 255);

    drawF(g, x + 27, y, 255, 255, 255);
    drawO(g, x + 32, y, 255, 255, 255);
    drawR(g, x + 37, y, 255, 255, 255);
    drawC(g, x + 42, y, 255, 255, 255);
    drawE(g, x + 47, y, 255, 255, 255);
}

//divide and conquer
void Button::drawButton_D(SDL_Plotter *g){

    // draw rectangle
    for(int i = 0; i < this->len; i++){
        for(int j = 0; j < this->height; j++){
            g->plotPixel(this->x + i, this->y + j, Norm.R, Norm.G, Norm.B);
        }
    }

    //draw lighter elements
    drawLighterElements(g);

    //draw darker elements
    drawDarkerElements(g);

    //draw words
    int x = this->x/2 + 8;
    int y = this->y/2 + 11;

    drawD(g, x, y, 255, 255, 255);
    drawI(g, x + 5, y, 255, 255, 255);
    drawV(g, x + 9, y, 255, 255, 255);
    drawI(g, x + 15, y, 255, 255, 255);
    drawD(g, x + 19, y, 255, 255, 255);
    drawE(g, x + 24, y, 255, 255, 255);

    drawA(g, x + 32, y, 255, 255, 255);
    drawN(g, x + 37, y, 255, 255, 255);
    drawD(g, x + 42, y, 255, 255, 255);

    drawC(g, x + 50, y, 255, 255, 255);
    drawO(g, x + 55, y, 255, 255, 255);
    drawN(g, x + 60, y, 255, 255, 255);
    drawQ(g, x + 65, y, 255, 255, 255);
    drawU(g, x + 71, y, 255, 255, 255);
    drawE(g, x + 76, y, 255, 255, 255);
    drawR(g, x + 81, y, 255, 255, 255);
}

//Strassen's
void Button::drawButton_S(SDL_Plotter *g){

    // draw rectangle
    for(int i = 0; i < this->len; i++){
        for(int j = 0; j < this->height; j++){
            g->plotPixel(this->x + i, this->y + j, Norm.R, Norm.G, Norm.B);
        }
    }

    //draw lighter elements
    drawLighterElements(g);

    //draw darker elements
    drawDarkerElements(g);

    //draw words
    int x = this->x/2 + 8;
    int y = this->y/2 + 11;

    drawS(g, x, y, 255, 255, 255);
    drawT(g, x + 5, y, 255, 255, 255);
    drawR(g, x + 9, y, 255, 255, 255);
    drawA(g, x + 14, y, 255, 255, 255);
    drawS(g, x + 19, y, 255, 255, 255);
    drawS(g, x + 24, y, 255, 255, 255);
    drawE(g, x + 29, y, 255, 255, 255);
    drawN(g, x + 34, y, 255, 255, 255);
    drawApos(g, x + 39, y - 2, 255, 255, 255);
    drawS(g, x + 43, y, 255, 255, 255);
}

//threaded
void Button::drawButton_T(SDL_Plotter *g){

    // draw rectangle
    for(int i = 0; i < this->len; i++){
        for(int j = 0; j < this->height; j++){
            g->plotPixel(this->x + i, this->y + j, Norm.R, Norm.G, Norm.B);
        }
    }

    //draw lighter elements
    drawLighterElements(g);

    //draw darker elements
    drawDarkerElements(g);

    //draw words
    int x = this->x/2 + 8;
    int y = this->y/2 + 11;

    drawT(g, x, y, 255, 255, 255);
    drawH(g, x + 4, y, 255, 255, 255);
    drawR(g, x + 9, y, 255, 255, 255);
    drawE(g, x + 14, y, 255, 255, 255);
    drawA(g, x + 19, y, 255, 255, 255);
    drawD(g, x + 24, y, 255, 255, 255);
    drawE(g, x + 29, y, 255, 255, 255);
    drawD(g, x + 34, y, 255, 255, 255);
}

#endif //GP_DVC_BUTTON_H
