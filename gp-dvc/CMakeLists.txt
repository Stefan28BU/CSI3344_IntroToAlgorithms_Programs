cmake_minimum_required(VERSION 3.8)
project(gp_dvc)

set(CMAKE_CXX_STANDARD 11)


include_directories(/Library/Frameworks/SDL2_mixer.framework)
include_directories(/Library/Frameworks/SDL2.framework)
link_directories(/Library/Frameworks/SDL2_mixer.framework)
link_directories(/Library/Frameworks/SDL2.framework)

add_executable(gp_dvc main.cpp SDL_Plotter.h GraphFunc.h Matrix.h Brute_Force.h Divide_and_Conquer.h Strassen.h Draw.h Graph.h Button.h Alpha.h ThreadDC.h)

target_link_libraries(gp_dvc /Library/Frameworks/SDL2_mixer.framework)
target_link_libraries(gp_dvc /Library/Frameworks/SDL2.framework)