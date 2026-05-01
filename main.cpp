#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float jetX = -1.2f;
char* studentName = "Tausai Matthew";
char* studentReg = "M240906";

void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void drawSmallText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

// ============= TASK F: JET FLYING ACROSS SCREEN =============
void drawJet(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Jet Body
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.15f, -0.05f);
    glVertex2f(0.25f, -0.05f);
    glVertex2f(0.25f, 0.05f);
    glVertex2f(-0.15f, 0.05f);
    glEnd();

    // Jet Nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.8f, 0.2f, 0.2f);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.35f, 0.04f);
    glVertex2f(0.35f, -0.04f);
    glEnd();

    // Cockpit
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.6f, 0.9f);
    glVertex2f(0.05f, 0.01f);
    glVertex2f(0.15f, 0.01f);
    glVertex2f(0.15f, 0.045f);
    glVertex2f(0.05f, 0.045f);
    glEnd();

    // Wings
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.2f, -0.12f);
    glVertex2f(0.25f, -0.05f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.2f, 0.12f);
    glVertex2f(0.25f, 0.05f);
    glEnd();

    glPopMatrix();

    // Label on Jet
    char label[100];
    sprintf(label, "%s - Jet", studentName);
    drawSmallText(x - 0.1f, y + 0.1f, label);
}

// ============= TASK A: SCENE USING GEOMETRIC PRIMITIVES =============

void drawSun() {
    // Sun body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.9f, 0.0f);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(-0.85f + 0.12f * cos(angle), 0.75f + 0.12f * sin(angle));
    }
    glEnd();

    // Sun rays
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.8f, 0.0f);
    for (int i = 0; i < 360; i += 45) {
        float angle = i * 3.14159f / 180.0f;
        float x = -0.85f;
        float y = 0.75f;
        glVertex2f(x + 0.12f * cos(angle), y + 0.12f * sin(angle));
        glVertex2f(x + 0.18f * cos(angle), y + 0.18f * sin(angle));
    }
    glEnd();

    // Label on Sun
    char label[100];
    sprintf(label, "%s\n%s - Sun", studentName, studentReg);
    drawSmallText(-0.95f, 0.82f, label);
}

void drawCloud(float x, float y) {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 360; i += 20) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + 0.08f * cos(angle), y + 0.05f * sin(angle));
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + 0.12f + 0.07f * cos(angle), y + 0.03f * sin(angle));
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + 0.06f + 0.07f * cos(angle), y + 0.07f * sin(angle));
    }
    glEnd();
}

void drawHouse() {
    // House body
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.8f, 0.5f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.9f, 0.2f);
    glEnd();

    // Roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.3f, 0.2f);
    glVertex2f(-0.95f, 0.2f);
    glVertex2f(-0.6f, 0.55f);
    glVertex2f(-0.25f, 0.2f);
    glEnd();

    // Door
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.3f, 0.1f);
    glVertex2f(-0.75f, -0.3f);
    glVertex2f(-0.65f, -0.3f);
    glVertex2f(-0.65f, 0.0f);
    glVertex2f(-0.75f, 0.0f);
    glEnd();

    // Door knob
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex2f(-0.67f, -0.15f);
    glEnd();

    // Window
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 0.9f);
    glVertex2f(-0.85f, -0.15f);
    glVertex2f(-0.8f, -0.15f);
    glVertex2f(-0.8f, -0.05f);
    glVertex2f(-0.85f, -0.05f);
    glEnd();

    // Window cross
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.85f, -0.1f);
    glVertex2f(-0.8f, -0.1f);
    glVertex2f(-0.825f, -0.15f);
    glVertex2f(-0.825f, -0.05f);
    glEnd();

    // Label on House
    char label[100];
    sprintf(label, "%s\n%s - House", studentName, studentReg);
    drawSmallText(-0.8f, 0.25f, label);
}

void drawTree(float x, float y) {
    // Trunk
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.3f, 0.1f);
    glVertex2f(x - 0.05f, y - 0.2f);
    glVertex2f(x + 0.05f, y - 0.2f);
    glVertex2f(x + 0.05f, y);
    glVertex2f(x - 0.05f, y);
    glEnd();

    // Leaves - bottom triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.6f, 0.2f);
    glVertex2f(x - 0.12f, y);
    glVertex2f(x + 0.12f, y);
    glVertex2f(x, y + 0.2f);
    glEnd();

    // Leaves - top triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.1f, 0.5f, 0.1f);
    glVertex2f(x - 0.1f, y + 0.1f);
    glVertex2f(x + 0.1f, y + 0.1f);
    glVertex2f(x, y + 0.28f);
    glEnd();

    // Label on Tree
    char label[100];
    sprintf(label, "%s - Tree", studentReg);
    drawSmallText(x - 0.08f, y + 0.32f, label);
}

void drawRoad() {
    // Road surface
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.35f);
    glVertex2f(-1.0f, -0.35f);
    glEnd();

    // Road center line
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.85f, -0.425f);
    glVertex2f(-0.65f, -0.425f);
    glVertex2f(-0.45f, -0.425f);
    glVertex2f(-0.25f, -0.425f);
    glVertex2f(-0.05f, -0.425f);
    glVertex2f(0.15f, -0.425f);
    glVertex2f(0.35f, -0.425f);
    glVertex2f(0.55f, -0.425f);
    glVertex2f(0.75f, -0.425f);
    glEnd();

    // Label on Road
    char label[100];
    sprintf(label, "%s - Road", studentReg);
    drawSmallText(-0.3f, -0.48f, label);
}

// ============= TASK B: FULL CARTOON CHARACTER =============
void drawCartoonCharacter() {
    // Head
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.8f, 0.6f);
    for (int i = 0; i < 360; i += 10) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(0.5f + 0.12f * cos(angle), 0.15f + 0.12f * sin(angle));
    }
    glEnd();

    // Eyes
    glPointSize(4.0f);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.46f, 0.20f);
    glVertex2f(0.54f, 0.20f);
    glEnd();

    // Eyebrows
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.44f, 0.24f);
    glVertex2f(0.48f, 0.23f);
    glVertex2f(0.56f, 0.24f);
    glVertex2f(0.52f, 0.23f);
    glEnd();

    // Smile
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.46f, 0.12f);
    glVertex2f(0.48f, 0.10f);
    glVertex2f(0.50f, 0.09f);
    glVertex2f(0.52f, 0.10f);
    glVertex2f(0.54f, 0.12f);
    glEnd();

    // Nose
    glBegin(GL_TRIANGLES);
    glColor3f(0.9f, 0.6f, 0.4f);
    glVertex2f(0.50f, 0.16f);
    glVertex2f(0.48f, 0.13f);
    glVertex2f(0.52f, 0.13f);
    glEnd();

    // Body
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.6f, 0.8f);
    glVertex2f(0.44f, -0.10f);
    glVertex2f(0.56f, -0.10f);
    glVertex2f(0.56f, 0.03f);
    glVertex2f(0.44f, 0.03f);
    glEnd();

    // Left Arm
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(0.44f, -0.02f);
    glVertex2f(0.35f, -0.05f);
    glVertex2f(0.32f, -0.12f);
    glEnd();

    // Left Hand
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.8f, 0.6f);
    for (int i = 0; i < 360; i += 30) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(0.32f + 0.03f * cos(angle), -0.12f + 0.03f * sin(angle));
    }
    glEnd();

    // Right Arm
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.8f, 0.6f);
    glVertex2f(0.56f, -0.02f);
    glVertex2f(0.65f, -0.05f);
    glVertex2f(0.68f, -0.12f);
    glEnd();

    // Right Hand
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.8f, 0.6f);
    for (int i = 0; i < 360; i += 30) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(0.68f + 0.03f * cos(angle), -0.12f + 0.03f * sin(angle));
    }
    glEnd();

    // Left Leg
    glBegin(GL_LINE_STRIP);
    glColor3f(0.2f, 0.6f, 0.8f);
    glVertex2f(0.47f, -0.10f);
    glVertex2f(0.45f, -0.25f);
    glVertex2f(0.41f, -0.30f);
    glEnd();

    // Right Leg
    glBegin(GL_LINE_STRIP);
    glColor3f(0.2f, 0.6f, 0.8f);
    glVertex2f(0.53f, -0.10f);
    glVertex2f(0.55f, -0.25f);
    glVertex2f(0.59f, -0.30f);
    glEnd();

    // Feet
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.6f, 0.8f);
    glVertex2f(0.39f, -0.32f);
    glVertex2f(0.44f, -0.32f);
    glVertex2f(0.44f, -0.28f);
    glVertex2f(0.39f, -0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.56f, -0.32f);
    glVertex2f(0.61f, -0.32f);
    glVertex2f(0.61f, -0.28f);
    glVertex2f(0.56f, -0.28f);
    glEnd();

    // Label on Cartoon Character
    char label[100];
    sprintf(label, "%s\n%s - Cartoon Self", studentName, studentReg);
    drawSmallText(0.35f, 0.28f, label);
}

// ============= TASK D: PERSONAL BUSINESS CARD =============
void drawBusinessCard() {
    // Card background
    glBegin(GL_QUADS);
    glColor3f(0.95f, 0.95f, 0.85f);
    glVertex2f(0.55f, -0.8f);
    glVertex2f(0.98f, -0.8f);
    glVertex2f(0.98f, -0.4f);
    glVertex2f(0.55f, -0.4f);
    glEnd();

    // Card border
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.55f, -0.8f);
    glVertex2f(0.98f, -0.8f);
    glVertex2f(0.98f, -0.4f);
    glVertex2f(0.55f, -0.4f);
    glEnd();

    // Decorative line
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.4f, 0.6f);
    glVertex2f(0.55f, -0.65f);
    glVertex2f(0.98f, -0.65f);
    glEnd();

    // Card text
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(0.58f, -0.45f, "TAUSAI MATTHEW BUSINESS CARD");
    drawText(0.58f, -0.52f, "Student ID: M240906");
    drawText(0.58f, -0.59f, "Computer Science");
    drawText(0.58f, -0.72f, "Great Zimbabwe University");
    drawText(0.58f, -0.77f, "Email: tmatthewtausaimakopa21@gmail.com");
}

// ============= DISPLAY FUNCTION =============
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Task A: Scene with house, trees, road, sun, clouds
    drawSun();
    drawCloud(-0.2f, 0.7f);
    drawCloud(0.4f, 0.65f);
    drawHouse();
    drawTree(-0.1f, -0.1f);
    drawTree(0.2f, -0.1f);
    drawRoad();

    // Task B: Full cartoon character
    drawCartoonCharacter();

    // Task D: Business card
    drawBusinessCard();

    // Task F: Animated jet
    drawJet(jetX, 0.82f);

    glutSwapBuffers();
}

// ============= ANIMATION FUNCTION =============
void update(int value) {
    jetX += 0.008f;
    if (jetX > 1.5f) jetX = -1.2f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// ============= KEYBOARD FUNCTION =============
void keyboard(unsigned char key, int x, int y) {
    if (key == 'q' || key == 'Q') {
        exit(0);
    }
}

// ============= INITIALIZATION =============
void initGL() {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -0.9, 1.0);
}

// ============= MAIN FUNCTION =============
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 750);
    glutCreateWindow("Computer Graphics Assignment - M240906 Tausai Matthew");
    initGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
