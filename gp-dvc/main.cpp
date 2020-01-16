/*
 *  Assignment title: CSI 3344 Group Project
 *  Program:          Algorithm Analysis
 *
 *  Group Members:
 *      Mackensi Holt
 *      Maggie Burton
 *      Yufan Xu
 *      Bo Fu
 *      Ryland Beaver
 *      File: main.cpp
 *
 *  Description:        This is the main file while we put everything together
 *                      and shows the project window
 *  Date created:       11/20/2018
 *  Date last modified: 12/3/2018
 *  Due Date:           12/3/2018
 */

/*
 * Data Abstraction:
 * 		data types:
 * 		    bool, int, struct, vector
 * 		Classes:
 * 		    SDL_Plotter, Button, Matrix, algoGraph
 * Input:
 * 		The program gets input from the user by responding to the mouse click
 * 		    on each button
 * Process:
 * 		Once the user clicked a button, the program will display the
 * 		    corresponding graph
 * Output:
 * 		The lines for each algorithm are displayed to the screen
 * Assumptions:
 * 		It is assumed that the user only wants correct result
 * 		It is assumed that the user only wants real solutions to the formula
 * 		It is assumed that, having been prompted to do so, the user wants
 * 		    valid data
 */

#include <iostream>
#include <cmath>
#include <vector>
#include "Button.h"
#include "Draw.h"
#include "Matrix.h"
#include "Divide_and_Conquer.h"
#include "Strassen.h"
#include "Brute_Force.h"
#include "GraphFunc.h"
#include <ratio>
#include <pthread.h>
#include "ThreadDC.h"
#include <semaphore.h>
#include <sys/types.h>

using namespace std;

#include<chrono>
using namespace std::chrono;

struct {
    SDL_Plotter *g;
    sem_t *drawSem;
    sem_t *updateSem;
    bool *updateNeeded;
} typedef plotSem;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

bool strassOn = false;
bool divCOn = false;
bool threadDivCOn = false;
bool bruteOn = false;
bool running = true;

vector<pair<int, int>> strass;
vector<pair<int, int>> divC;
vector<pair<int, int>> threadDivC;
vector<pair<int, int>> bruteForce;

int bruteCount;
int divCount;
int threadCount;
int strassCount;

/*
 * description: calculates strassen's run time
 * return: void
 * precondition: datas are valid
 * postcondition: time is calculated
 */
void *threadStrassTime(void *arg);

/*
 * description: calculates divide and conquer's run time
 * return: void
 * precondition: datas are valid
 * postcondition: time is calculated
 */
void *threadDivTimes(void *arg);

/*
 * description: calculates brute force's run time
 * return: void
 * precondition: datas are valid
 * postcondition: time is calculated
 */
void *threadBruteTimes(void *arg);

/*
 * description: calculates threaded Divide and conquer's run time
 * return: void
 * precondition: datas are valid
 * postcondition: time is calculated
 */
void *threadThreadTimes(void *arg);

/*
 * description: threaded plot data
 * return: void
 * precondition: datas are valid
 * postcondition: data is ploted
 */
void *threadPlot(void *arg);

int main( int argc, char** args )
{
    // Set up GUI
    SDL_Plotter *g;
    g = new SDL_Plotter(SCREEN_HEIGHT, SCREEN_WIDTH);

    // Initialize buttons and variables to control buttons
    int x,y;
    int y0 = SCREEN_HEIGHT - 120;
    int init = 60;
    int delta = 40;

    Button BruteForce('B', init, y0, 130, 60);
    Button DivideAndConquer('D', init + 130 + delta, y0, 200, 60);
    Button Strassens('S', init + 130 + 200 + delta*2, y0, 125, 60);
    Button Threaded('T', init + 130 + 200 + 125 + delta*3, y0, 110, 60);

    int ButtonDownTime = 50;
    int time = 0;
    bool B_swap = false;	//brute force
    bool D_swap = false;	//divide and conquer
    bool S_swap = false;	//strassens
    bool T_swap = false;	//threaded

    strass.push_back(pair<int, int>(0, 0));
    divC.push_back(pair<int, int>(0, 0));
    threadDivC.push_back(pair<int, int>(0, 0));
    bruteForce.push_back(pair<int, int>(0, 0));

    bruteCount = 4;
    divCount = 4;
    threadCount = 4;
    strassCount = 4;

    sem_t graphBlock;
    sem_t updateSem;
    sem_init(&graphBlock, 0, 1);
    sem_init(&updateSem, 0, 1);

    bool updateNeeded = true;

    plotSem threadArg;
    threadArg.g = g;
    threadArg.drawSem = &graphBlock;
    threadArg.updateSem = &updateSem;
    threadArg.updateNeeded = &updateNeeded;

    pthread_t strassThread;
    pthread_t bruteThread;
    pthread_t divThread;
    pthread_t threadThread;
    pthread_t plotThread;

    //creates threads for each function
    pthread_create(&strassThread, NULL, &threadStrassTime, (void*)&threadArg);
    pthread_create(&bruteThread, NULL, &threadBruteTimes, (void*)&threadArg);
    pthread_create(&divThread, NULL, &threadDivTimes, (void*)&threadArg);
    pthread_create(&threadThread, NULL, &threadThreadTimes, (void*)&threadArg);
    pthread_create(&plotThread, NULL, &threadPlot, (void*)&threadArg );

    //master loop for
    while (running)
    {
        Draw(g, BruteForce, DivideAndConquer, Strassens, Threaded);

        if (g->getQuit()) {
            running = false;
        }

        if(g->getMouseMotion(x,y)){

            if(BruteForce.isButton(x,y)){
                BruteForce.highlight(B_swap);
            }
            else if(DivideAndConquer.isButton(x,y)){
                DivideAndConquer.highlight(D_swap);
            }
            else if(Strassens.isButton(x,y)){
                Strassens.highlight(S_swap);
            }
            else if(Threaded.isButton(x,y)){
                Threaded.highlight(T_swap);
            }else{
                BruteForce.resetColor();
                DivideAndConquer.resetColor();
                Strassens.resetColor();
                Threaded.resetColor();
            }
        }

        if (g->getMouseDown(x, y)) {

            if(BruteForce.isButton(x,y)){
                BruteForce.swapColors();
                B_swap = true;
                bruteOn = !bruteOn;
                cout << "Toggle B" << endl;
            }
            else if(DivideAndConquer.isButton(x,y)){
                DivideAndConquer.swapColors();
                D_swap = true;
                divCOn = !divCOn;
                cout << "Toggle D" << endl;

            }
            else if(Strassens.isButton(x,y)){
                Strassens.swapColors();
                S_swap = true;
                strassOn = !strassOn;
                cout << "Toggle S" << endl;

            }
            else if(Threaded.isButton(x,y)){
                Threaded.swapColors();
                T_swap = true;
                threadDivCOn = !threadDivCOn;
                cout << "Toggle T" << endl;

            }
            time++;
        }

        if (time == ButtonDownTime) {
            if(B_swap){
                BruteForce.swapColors();
                B_swap = false;
            }
            else if(D_swap){
                DivideAndConquer.swapColors();
                D_swap = false;
            }
            else if(S_swap){
                Strassens.swapColors();
                S_swap = false;
            }
            else if(T_swap){
                Threaded.swapColors();
                T_swap = false;
            }
            time = 0;
        }

        if(time != 0) {
            time++;
        }
        if(g->kbhit()){
            g->getKey();
        }

        sem_wait(&graphBlock);
        g->update();
        sem_post(&graphBlock);
    }

    //wait for each thread
    pthread_join(strassThread, nullptr);
    pthread_join(bruteThread, nullptr);
    pthread_join(threadThread, nullptr);
    pthread_join(divThread, nullptr);
    pthread_join(plotThread, nullptr);

    sem_destroy(&graphBlock);
    delete g;

    return 0;
}

void *threadStrassTime(void *arg) {
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    int millis;

    while(running) {
        if (strassOn) {
            Matrix m(strassCount);
            Matrix n = m;
            Matrix o = m;

            t1 = high_resolution_clock::now();

            strassenR(m, n, o, strassCount);

            t2 = high_resolution_clock::now();

            auto dur = t2 - t1;
            millis = duration_cast<milliseconds>(dur).count();

            strass.push_back(pair<int, int>(strassCount, millis));
            strassCount *= 2;

            sem_wait(((plotSem*)arg)->updateSem);
            *(((plotSem*)arg)->updateNeeded) = true;
            sem_post(((plotSem*)arg)->updateSem);

        }
    }
}
void *threadDivTimes(void *arg) {
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    int millis;

    while(running) {
        if (divCOn) {
            Matrix m(divCount);
            Matrix n = m;
            t1 = high_resolution_clock::now();

            Divide_and_Conquer(m, n, 0, 0, 0, 0, divCount);

            t2 = high_resolution_clock::now();

            auto dur = t2 - t1;
            millis = duration_cast<milliseconds>(dur).count();
            divC.push_back(pair<int, int>(divCount, millis));
            divCount *= 2;

            sem_wait(((plotSem*)arg)->updateSem);
            *(((plotSem*)arg)->updateNeeded) = true;
            sem_post(((plotSem*)arg)->updateSem);

        }
    }
}
void *threadBruteTimes(void *arg) {
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    int millis;

    while(running) {
        if (bruteOn) {
            Matrix m(bruteCount);
            Matrix n = m;
            t1 = high_resolution_clock::now();
            Brute_Force(m, n);
            t2 = high_resolution_clock::now();
            auto dur = t2 - t1;
            millis = duration_cast<milliseconds>(dur).count();

            bruteForce.push_back(pair<int, int>(bruteCount, millis));
            bruteCount *= 2;

            sem_wait(((plotSem*)arg)->updateSem);
            *(((plotSem*)arg)->updateNeeded) = true;
            sem_post(((plotSem*)arg)->updateSem);

        }
    }
}
void *threadThreadTimes(void *arg) {
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    int millis;

    while(running) {
        if (threadDivCOn) {

            Matrix m(threadCount);
            Matrix n = m;

            t1 = high_resolution_clock::now();

            TDaC2(m, n, threadCount);

            t2 = high_resolution_clock::now();

            auto dur = t2 - t1;
            millis = duration_cast<milliseconds>(dur).count();


            threadDivC.push_back(pair<int, int>(strassCount, millis));
            threadCount *= 2;

            sem_wait(((plotSem*)arg)->updateSem);
            *(((plotSem*)arg)->updateNeeded) = true;
            sem_post(((plotSem*)arg)->updateSem);
        }
    }
}
void *threadPlot(void *arg) {
    algGraph linePlotter;
    while(running) {
        if (*(((plotSem*)arg)->updateNeeded)) {
            sem_wait(((plotSem *) arg)->updateSem);

            sem_wait(((plotSem *) arg)->drawSem);
            linePlotter.plot(*((plotSem *) arg)->g, strass, divC, threadDivC, bruteForce);
            sem_post(((plotSem *) arg)->drawSem);

            *(((plotSem*)arg)->updateNeeded) = false;
            sem_post(((plotSem *) arg)->updateSem);
        }
    }
}