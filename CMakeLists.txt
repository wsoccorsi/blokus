cmake_minimum_required(VERSION 3.8)
project(blokus)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fpermissive")

find_package (OpenGL REQUIRED)
find_package (GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(main.cpp ${SOURCE_FILES} Blokus.cpp Blokus.h MainWindow.cpp MainWindow.h TileGrid.cpp TileGrid.h Drawable.cpp Drawable.h Tile.cpp Tile.h Tray.cpp Tray.h Piece.cpp Piece.h Clickable.cpp Clickable.h Player.cpp Player.h Coordinate.cpp Coordinate.h CallbackManager.cpp CallbackManager.h Board.cpp Board.h EventListener.h)

target_link_libraries (main.cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} m dl pthread)