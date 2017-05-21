#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#include <vector>
//#include <string>

class glWidget : public QGLWidget
{
    Q_OBJECT
public:
    glWidget(char* file,QWidget *parent = 0);

protected:
    void initializeGL(); //glutinit
    void paintGL(); //glutredraw
    void resizeGL(int , int ); //glutresize
    void mousePressEvent(QMouseEvent *event);

public:

    struct Vertex {
        Vertex(int a, int b, int c) : x(a), y(b), z(c){}
        float x, y, z;
    };

    struct Face {
        Face() : nverts(0), verts(0) {}
        int nverts;
        Vertex **verts;
        float normal[3];
    };

    struct Mesh {
        Mesh() : nverts(0), nfaces(0){}
        int nverts;
        std::vector<Vertex> verts;
        int nfaces;
        std::vector<Face> faces;
    };

    int ReadOffFile(const char *filename);
    //void setFile(std::string file){filename = file;}

    ////////////////////////////////////////////////////////////
    // GLOBAL VARIABLES
    ////////////////////////////////////////////////////////////

    // Program arguments

    char* filename;

    // GLUT variables

    //static int GLUTwindow;
    //static int GLUTwindow_height;
    //static int GLUTwindow_width;
    static int mouse[2];
    //static int GLUTbutton[3];
    //static int GLUTarrows[4];
    //static int GLUTmodifiers;

    // Display variables

    static bool scaling;
    static bool translating;
    static bool rotating;
    static float scale;
    static float center[3];
    static float rotation[3];
    static float translation[3];

    // Mesh variables

    static Mesh* mesh;


};

#endif // GLWIDGET_H
