

#ifndef GP_DVC_GRAPHFUNCS_H
#define GP_DVC_GRAPHFUNCS_H
#include<vector>
#include<semaphore.h>
#include<sys/types.h>
#include"SDL_Plotter.h"
using namespace std;

const int graphR = 255;
const int graphG = 255;
const int graphB = 255;
const int threadR = 153;
const int threadG = 0;
const int threadB = 204;
const int strassR = 0;
const int strassG = 255;
const int strassB = 0;
const int divCR = 255;
const int divCG = 0;
const int divCB = 0;
const int bruteR = 0;
const int bruteG = 0;
const int bruteB = 255;

class algGraph {
private:
    vector<pair<int, int>> strassOld;
    vector<pair<int, int>> threadOld;
    vector<pair<int, int>> bruteOld;
    vector<pair<int, int>> divCOld;

    int maxX;
    int maxY;

    int grToPlotX(SDL_Plotter& g, int x);
    int grToPlotY(SDL_Plotter& g, int y);

    void erase(SDL_Plotter&);
    char plotLine(SDL_Plotter& g, vector<pair<int, int>> line, int red, int green, int blue, char c);

public:
    void plot(SDL_Plotter &g, vector<pair<int, int>> &strass, vector<pair<int, int>> &divC,
              vector<pair<int, int>> &threadDivC, vector<pair<int, int>> &bruteForce);
    algGraph();
    int getMaxX() const;

    int getMaxY() const;

};


algGraph::algGraph() {
    strassOld.push_back(pair<int, int>(0, 0));
    threadOld.push_back(pair<int, int>(0, 0));
    bruteOld.push_back(pair<int, int>(0, 0));
    divCOld.push_back(pair<int, int>(0, 0));
    this->maxX = 1000;
    this->maxY = 1000;
}

void algGraph::plot(SDL_Plotter &g, vector<pair<int, int>> &strass, vector<pair<int, int>> &divC,
                    vector<pair<int, int>> &threadDivC, vector<pair<int, int>> &bruteForce) {

    char exp = 0;
    erase(g);
    // Erase all lines to clean the graph
    //Can't erase lines one at a time because intersections would cause gaps


    exp = exp | plotLine(g, strass, strassR, strassG, strassB, 4);
    if (!(exp & 3)) {
        exp = exp | plotLine(g, threadDivC, threadR, threadG, threadB, 8);
        //cout << "called plot thread" << endl;
    }
    if (!(exp & 3)) {
        exp = exp | plotLine(g, bruteForce, bruteR, bruteG, bruteB, 16);
        //cout << "called plot brute" << endl;

    }
    if (!(exp & 3)) {
        exp = exp | plotLine(g, divC, divCR, divCG, divCB, 32);
        //cout << "called plot div" << endl;
    }

    //cout << "exp: " << (int)exp << endl;


    strassOld = strass;
    threadOld = threadDivC;
    bruteOld = bruteForce;
    divCOld = divC;



    if(exp) {
        erase(g);
        //Since rescale is needed, erase what was just plotted
        //Before the scale is changed
    }

    if(exp & 2) {
        if(this->maxX < strass.back().first) {
            this->maxX = strass.back().first + 5;
        }
        if(this->maxX < threadDivC.back().first) {
            this->maxX = threadDivC.back().first + 5;
        }
        if(this->maxX < bruteForce.back().first) {
            this->maxX = bruteForce.back().first + 5;
        }
        if(this->maxX < divC.back().first) {
            this->maxX = divC.back().first + 5;
        }
    }
    if(exp & 1) {
        if(this->maxY < strass.back().second) {
            this->maxY = strass.back().second + 5;
        }
        if(this->maxY < threadDivC.back().second) {
            this->maxY = threadDivC.back().second + 5;
        }
        if(this->maxY < bruteForce.back().second) {
            this->maxY = bruteForce.back().second + 5;
        }
        if(this->maxY < divC.back().second) {
            this->maxY = divC.back().second + 5;
        }
    }
    //Change the scale to whatever is needed

    if(exp) {
        plot(g, strass, divC, threadDivC, bruteForce);
    }
}

void algGraph::erase(SDL_Plotter& g) {
    plotLine(g, strassOld, graphR, graphG, graphB,  64);
    plotLine(g, threadOld, graphR, graphG, graphB, 64);
    plotLine(g, bruteOld, graphR, graphG, graphB, 64);
    plotLine(g, divCOld, graphR, graphG, graphB, 64);
}

char algGraph::plotLine(SDL_Plotter& g, vector<pair<int, int>> line, int red, int green, int blue, char c) {

    for(int i = 1; i < line.size(); i++) {


        if(line.back().second > this->maxY && c != 64) {
            cout << "Scale?" << endl;
            return c | 1;
        }
        if(line.back().first > this->maxX && c != 64) {
            //sem_post(sem);
            return c | 2;
        }

        double dX = line[i].first - line[i - 1].first;
        double dY = line[i].second - line[i-1].second;
        double m = dY / dX;
        double b = line[i].second - line[i].first * m;


        for(double x = line[i-1].first; x < line[i].first; x++) {
            for(double y = line[i-1].second; y < line[i].second; y++) {
                if( ((((y - b) / m) > x - this->maxX / 300 && ((y - b) / m) < x + this->maxX / 300 )
                     || ( m * x + b < y + this->maxY / 300 && m * x + b > y - this->maxY / 300 ))
                    && y < this->maxY && x < this->maxX) {
                    g.plotPixel(grToPlotX(g, x), grToPlotY(g, y), red, green, blue);
                }
            }
        }

    }
    //sem_post(sem);
    return 0;
}

int algGraph::grToPlotX(SDL_Plotter& g, int x) {
    double pctgX = (double)x / (double)this->maxX;
    return pctgX * 570 + 115;
}

int algGraph::grToPlotY(SDL_Plotter& g, int y) {
    double pctgY = (double)y / (double)this->maxY;
    return 800 - (pctgY * 500 + 200);
}

int algGraph::getMaxX() const {
    return maxX;
}

int algGraph::getMaxY() const {
    return maxY;
}
#endif //GP_DVC_GRAPHFUNCS_H
