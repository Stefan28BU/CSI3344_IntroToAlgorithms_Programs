//
// Created by 徐宇帆 on 18/12/1.
//

#ifndef GP_DVC_DRAW_H
#define GP_DVC_DRAW_H

#include "SDL_Plotter.h"
#include "Button.h"
#include "Alpha.h"

void drawTitle(SDL_Plotter *g){
    int x = 80;
    int y = 10;
    drawM(g, x, y, 0, 0, 0, 3, 1);
    drawA(g, x+7, y, 0, 0, 0, 3, 1);
    drawT(g, x+13, y, 0, 0, 0, 3, 1);
    drawR(g, x+18, y, 0, 0, 0, 3, 1);
    drawI(g, x+24, y, 0, 0, 0, 3, 1);
    drawX(g, x+30, y, 0, 0, 0, 3, 1);

    drawM(g, x+42, y, 0, 0, 0, 3, 1);
    drawU(g, x+49, y, 0, 0, 0, 3, 1);
    drawL(g, x+55, y, 0, 0, 0, 3, 1);
    drawT(g, x+60, y, 0, 0, 0, 3, 1);
    drawI(g, x+65, y, 0, 0, 0, 3, 1);
    drawP(g, x+70, y, 0, 0, 0, 3, 1);
    drawL(g, x+76, y, 0, 0, 0, 3, 1);
    drawI(g, x+82, y, 0, 0, 0, 3, 1);
    drawC(g, x+87, y, 0, 0, 0, 3, 1);
    drawA(g, x+93, y, 0, 0, 0, 3, 1);
    drawT(g, x+99, y, 0, 0, 0, 3, 1);
    drawI(g, x+104, y, 0, 0, 0, 3, 1);
    drawO(g, x+109, y, 0, 0, 0, 3, 1);
    drawN(g, x+115, y, 0, 0, 0, 3, 1);

    x += 35;
    y += 10;
    drawR(g, x, y, 0, 0, 0, 3, 1);
    drawU(g, x+6, y, 0, 0, 0, 3, 1);
    drawN(g, x+12, y, 0, 0, 0, 3, 1);

    drawT(g, x+24, y, 0, 0, 0, 3, 1);
    drawI(g, x+29, y, 0, 0, 0, 3, 1);
    drawM(g, x+34, y, 0, 0, 0, 3, 1);
    drawE(g, x+41, y, 0, 0, 0, 3, 1);

}


void drawXaxis(SDL_Plotter *g, int x0, int y0){
    // draw axis
    for(int i = x0; i < x0 + 570; i++){
        g->plotPixel(i, y0, 0,0,0);
        g->plotPixel(i, y0 + 1, 0,0,0);
    }

    // draw scale
    for(int i = 0; i < 10; i++){
        g->plotPixel(x0 + 100, y0-4 + i, 0,0,0);
        g->plotPixel(x0 + 200, y0-4 + i, 0,0,0);
        g->plotPixel(x0 + 300, y0-4 + i, 0,0,0);
        g->plotPixel(x0 + 400, y0-4 + i, 0,0,0);
        g->plotPixel(x0 + 500, y0-4 + i, 0,0,0);
    }

    draw0(g, 55, 305, 0, 0, 0, 2, -1);

    draw5(g, 103, 305, 0, 0, 0, 2, -1);
    draw0(g, 108, 305, 0, 0, 0, 2, -1);

    draw1(g, 150, 305, 0, 0, 0, 2, -1);
    draw0(g, 155, 305, 0, 0, 0, 2, -1);
    draw0(g, 160, 305, 0, 0, 0, 2, -1);

    draw1(g, 200, 305, 0, 0, 0, 2, -1);
    draw5(g, 205, 305, 0, 0, 0, 2, -1);
    draw0(g, 210, 305, 0, 0, 0, 2, -1);

    draw2(g, 250, 305, 0, 0, 0, 2, -1);
    draw0(g, 255, 305, 0, 0, 0, 2, -1);
    draw0(g, 260, 305, 0, 0, 0, 2, -1);

    draw2(g, 300, 305, 0, 0, 0, 2, -1);
    draw5(g, 305, 305, 0, 0, 0, 2, -1);
    draw0(g, 310, 305, 0, 0, 0, 2, -1);

    draw_n(g, 350, 305, 0, 0, 0);
}

void drawYaxis(SDL_Plotter *g, int x0, int y0){
    for(int i = y0; i >= y0-500; i--){
        g->plotPixel(x0, i, 0, 0, 0);
        g->plotPixel(x0-1,i, 0,0,0);
    }

    draw_t(g, 25, 45, 0, 0, 0);
    draw_i(g, 30, 45, 0, 0, 0);
    draw_m(g, 35, 45, 0, 0, 0);
    draw_e(g, 45, 45, 0, 0, 0);
/*
	for(int i = 0; i < 10; i++){
		g->plotPixel(x0-4 + i, y0 -  50, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 100, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 150, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 200, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 250, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 300, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 350, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 400, 0,0,0);
    	g->plotPixel(x0-4 + i, y0 - 450, 0,0,0);
    }
    */
}


void Draw(SDL_Plotter *g, Button B, Button D, Button S, Button T){

    // Draw buttons
    B.draw(g);
    D.draw(g);
    S.draw(g);
    T.draw(g);

    // Draw x and y axis
    int x0 = 115;
    int y0 = 600;
    drawXaxis(g, x0, y0);
    drawYaxis(g, x0, y0);

    // Draw Title
    drawTitle(g);
}

#endif //GP_DVC_DRAW_H
