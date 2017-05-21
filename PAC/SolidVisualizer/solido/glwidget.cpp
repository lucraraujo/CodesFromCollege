#include "glwidget.h"
#include <QMouseEvent>
#include <fstream>
#include <string>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QStringList>

using namespace std;

// GLUT variables
/*
int glWidget::GLUTwindow = 0;
int glWidget::GLUTwindow_height = 800;
int glWidget::GLUTwindow_width = 800;

int glWidget::GLUTbutton[3] = { 0, 0, 0 };
int glWidget::GLUTarrows[4] = { 0, 0, 0, 0 };
int glWidget::GLUTmodifiers = 0;
*/
int glWidget::mouse[2] = { 0, 0 };

// Display variables

bool glWidget::scaling = 0;
bool glWidget::translating = 0;
bool glWidget::rotating = 0;
float glWidget::scale = 1.0;
float glWidget::center[3] = { 0.0, 0.0, 0.0 };
float glWidget::rotation[3] = { 0.0, 0.0, 0.0 };
float glWidget::translation[3] = { 0.0, 0.0, -4.0 };

// Mesh variables
glWidget::Mesh* glWidget::mesh = 0;
//char* glWidget::filename = 0;



glWidget::glWidget(char* file, QWidget *parent) : QGLWidget(parent)
{
    this->filename = file;
    mesh = new Mesh();
    ReadOffFile(filename);
}

void glWidget::initializeGL()
{
    // Initialize lights
    static GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    static GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glEnable(GL_LIGHT0);
    static GLfloat light1_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    // Initialize graphics modes
    glEnable(GL_DEPTH_TEST);

}

void glWidget::paintGL()
{

    // Setup viewing transformation
    glLoadIdentity();
    glScalef(scale, scale, scale);
    glTranslatef(translation[0], translation[1], 0.0);

    // Set projection transformation
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0, (GLfloat) GLUTwindow_width /(GLfloat) GLUTwindow_height, 0.1, 100.0);


    // Set camera transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translation[0], translation[1], translation[2]);
    glScalef(scale, scale, scale);
    glRotatef(rotation[0], 1.0, 0.0, 0.0);
    glRotatef(rotation[1], 0.0, 1.0, 0.0);
    glRotatef(rotation[2], 0.0, 0.0, 1.0);
    glTranslatef(-center[0], -center[1], -center[2]);

    // Clear window
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set lights
    static GLfloat light0_position[] = { 3.0, 4.0, 5.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    static GLfloat light1_position[] = { -3.0, -2.0, -3.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    // Set material
    static GLfloat material[] = { 1.0, 0.5, 0.5, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);


    // Draw faces
    if(mesh){
        for (int i = 0; i < mesh->nfaces; i++) {
            Face& face = mesh->faces[i];
            glBegin(GL_POLYGON);
            glNormal3fv(face.normal);
            for (int j = 0; j < face.nverts; j++) {
                Vertex *vert = face.verts[j];
                glVertex3f(vert->x, vert->y, vert->z);
            }
            glEnd();
        }
    }
}

int glWidget::ReadOffFile(const char *filename)
{
    ifstream leitor;
    leitor.open(filename);

    if(leitor.fail()){
        return false;
    }

    string off;
    leitor >> off;

    if(off != "OFF"){
        return 1;
    }

    int numVertices, numFaces, numArestas;
    leitor >> numVertices >> numFaces >> numArestas;

    //float x = 0;
    //float y = 0;
    //float z = 0;
    /*
    for (int i = 0; i < numVertices; ++i)
       mesh->verts.push_back(Vertex());
    for (int i = 0; i < numFaces; ++i)
        mesh->verts.push_back(Face());*/
    //mesh->verts = new Vertex[numVertices];
    //assert(mesh->verts);
    //mesh->faces = new Face[numFaces];
    //assert(mesh->faces);

    for(int i=0; i < numVertices; ++i){
        Vertex temp(0,0,0);
        //int x,y,z;
        leitor >> temp.x;
        leitor >> temp.y;
        leitor >> temp.z;
        mesh->verts.push_back(temp);
    }

    for(int i=0; i < numFaces; ++i){
        Face temp;
        //int x,y,z;
        //leitor >> temp.x;
        //leitor >> temp.y;
        //leitor >> temp.z;
        mesh->faces.push_back(temp);
    }


    while(mesh->nverts < numVertices)
    {

        int numVert = mesh->nverts;
        leitor >> mesh->verts[numVert].x >> mesh->verts[numVert].y >> mesh->verts[numVert].z;
        ++mesh->nverts;
    }

    while(mesh->nfaces < numFaces)
    {
        int numFaces = mesh->nfaces;

        leitor >> mesh->faces[numFaces].nverts;

        mesh->faces[numFaces].verts = new Vertex *[mesh->faces[numFaces].nverts];

        for (int i = 0; i < mesh->nverts; ++i)
        {
            leitor >> mesh->verts[i].x >> mesh->verts[i].y >> mesh->verts[i].z;
        }

        mesh->faces[numFaces].normal[0] = mesh->faces[numFaces].normal[1] = mesh->faces[numFaces].normal[2] = 0;
        Vertex *v1 = mesh->faces[numFaces].verts[mesh->faces[numFaces].nverts-1];
        for (int i = 0; i < mesh->faces[numFaces].nverts; i++) {
            Vertex *v2 = mesh->faces[numFaces].verts[i];
            mesh->faces[numFaces].normal[0] += (v1->y - v2->y) * (v1->z + v2->z);
            mesh->faces[numFaces].normal[1] += (v1->z - v2->z) * (v1->x + v2->x);
            mesh->faces[numFaces].normal[2] += (v1->x - v2->x) * (v1->y + v2->y);
            v1 = v2;
        }

        // Normalize normal for face
        float squared_normal_length = 0.0;
        squared_normal_length += mesh->faces[numFaces].normal[0]*mesh->faces[numFaces].normal[0];
        squared_normal_length += mesh->faces[numFaces].normal[1]*mesh->faces[numFaces].normal[1];
        squared_normal_length += mesh->faces[numFaces].normal[2]*mesh->faces[numFaces].normal[2];
        float normal_length = sqrt(squared_normal_length);
        if (normal_length > 1.0E-6) {
            mesh->faces[numFaces].normal[0] /= normal_length;
            mesh->faces[numFaces].normal[1] /= normal_length;
            mesh->faces[numFaces].normal[2] /= normal_length;
        }
        ++mesh->nfaces;

    }
    return 1;
}
void glWidget::resizeGL(int w, int h)
{
    // Resize window
    glViewport(0, 0, w, h);
    updateGL();
}

void glWidget::mousePressEvent(QMouseEvent *event)
{
    // Process mouse button event
    if (event->buttons() & Qt::LeftButton)
        rotating = true;
    if (event->buttons() & Qt::MiddleButton)
        scaling = true;
    if (event->buttons() & Qt::RightButton)
        translating = true;
    //if (rotating || scaling || translating)

    //y e x sao a posicao do mouse
    // Invert y coordinate
    int y = event->pos().y();
    int x = event->pos().x();
    int height = size().height();
    int width = size().width();
    y = height - y;

    // Process mouse motion event
    if (rotating) {
        // Rotate model
        rotation[0] += -0.5 * (y - mouse[1]);
        rotation[2] += 0.5 * (x - mouse[0]);
    }
    else if (scaling) {
        // Scale window
        scale *= exp(2.0 * (float) (x - mouse[0]) / (float) width);
    }
    else if (translating) {
        // Translate window
        translation[0] += 2.0 * (float) (x - mouse[0]) / (float) width;
        translation[1] += 2.0 * (float) (y - mouse[1]) / (float) height;
    }

    // Remember mouse position
    mouse[0] = x;
    mouse[1] = y;
    updateGL();
}
