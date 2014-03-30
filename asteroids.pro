# qt 5 wants this may cause errors with 4
isEqual(QT_MAJOR_VERSION, 5) {cache() }
QT += core
QT +=opengl
TARGET=asteroids
CONFIG-=app_bundle
DESTDIR=./
OBJECTS_DIR=obj
SOURCES=src/main.cpp \
        src/GLFunctions.cpp \
        src/Vec4.cpp \
        src/Mat4.cpp \
        src/rigidbodies.cpp \
        src/rocket.cpp \
        src/asteroid.cpp \
        src/hud.cpp \
        src/world.cpp \
        src/camera.cpp \
        src/bullet.cpp \
        src/map.cpp \
        src/util.cpp


HEADERS+=include/GLFunctions.h \
         include/Vec4.h \
         include/Mat4.h \
        include/rigidbodies.h \
        include/rocket.h \
        include/asteroid.h \
        include/hud.h \
        include/world.h \
        include/camera.h \
        include/bullet.h \
        include/map.h \
        include/World.h \
        include/util.h

# add the ngl lib
# this is where to look for includes
INCLUDEPATH +=include "C:\Program Files\Common Files\SDL2\include"

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native

QMAKE_CXXFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CXXFLAGS)

LIBS+=$$system(sdl2-config  --libs)
message(output from sdl2-config --libs added to LIB=$$LIBS)

#LIBS += -L -lgl32 -lopengl32

LIBS += -L/usr/local/lib


macx:LIBS+= -framework OpenGL
macx:DEFINES+=DARWIN
linux-*:DEFINES+=LINUX
# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-g++:linux-g++-64 {
    DEFINES+= LINUX
    LIBS+= -lGLEW
}
linux-clang {
    DEFINES+= LINUX
    LIBS+= -lGLEW
}

#INCLUDEPATH += "C:\Program Files (x86)\Common Files\SDL2\include"
#LIBS += -L"C:\Program Files (x86)\Common Files\SDL2\lib" -lSDL2 -lSDL2_image
#LIBS +=  -lmingw32 -lSDLmain -lSDL
