#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 3
#define FACES 6

// ť�� �� ����, ����, 16���� ����
char* colors[FACES] = { "white", "red", "blue", "green", "orange", "yellow" };
char letters[FACES] = { 'w', 'r', 'b', 'g', 'o', 'y' };
int hexColors[FACES] = { 0xFFF, 0xF00, 0x00F, 0x0F0, 0xFA0, 0xFF0 };

// ť�� �迭 (3x3x6)
int cube[LENGTH][LENGTH][FACES];

enum PrintMode { STRING, LETTER, HEX };

// ť�� �ʱ�ȭ
void initCube() {
    for (int i = 0; i < FACES; i++) {
        for (int j = 0; j < LENGTH; j++) {
            for (int k = 0; k < LENGTH; k++) {
                cube[j][k][i] = i;  // �� �鿡 ���� �ʱ�ȭ
            }
        }
    }
}

// ť�� ���
void printCube(enum PrintMode mode) {
    const char* labels[FACES] = { "Up", "Left", "Front", "Right", "Back", "Down" };
    for (int i = 0; i < FACES; i++) {
        printf("%s face:\n", labels[i]);
        for (int j = 0; j < LENGTH; j++) {
            for (int k = 0; k < LENGTH; k++) {
                switch (mode) {
                case STRING:
                    printf("%-7s", colors[cube[j][k][i]]);
                    break;
                case LETTER:
                    printf("%-7c", letters[cube[j][k][i]]);
                    break;
                case HEX:
                    printf("%#05X ", hexColors[cube[j][k][i]]);
                    break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

// ť���� ���� �ð�������� 90�� ȸ���ϴ� �Լ�
void rotateFace(int face) {
    int temp[LENGTH][LENGTH];

    // �� ����
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            temp[i][j] = cube[i][j][face];
        }
    }

    // �ð�������� 90�� ȸ��
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            cube[i][j][face] = temp[LENGTH - 1 - j][i];
        }
    }
}

// ť���� �� �鿡 ���� ȸ���ϴ� �Լ���
void rotateU() {  // Up �� ȸ��
    rotateFace(0);
}

void rotateL() {  // Left �� ȸ��
    rotateFace(1);
}

void rotateF() {  // Front �� ȸ��
    rotateFace(2);
}

void rotateR() {  // Right �� ȸ��
    rotateFace(3);
}

void rotateB() {  // Back �� ȸ��
    rotateFace(4);
}

void rotateD() {  // Down �� ȸ��
    rotateFace(5);
}

// ť���� �� ���� �������� ȸ���ϴ� �Լ���
void rotateUEdge() {
    int temp[LENGTH];
    // ��� ���� (Up ���� ���� ��� Down, Left, Right, Back ���� ��� ��)
    for (int i = 0; i < LENGTH; i++) {
        temp[i] = cube[0][i][0]; // Up-Left
    }
    for (int i = 0; i < LENGTH; i++) {
        cube[0][i][0] = cube[1][i][0]; // Left-Front
    }
    for (int i = 0; i < LENGTH; i++) {
        cube[1][i][0] = cube[2][i][0]; // Front-Right
    }
    for (int i = 0; i < LENGTH; i++) {
        cube[2][i][0] = temp[i]; // Back-Up
    }
}

void scrambleCube() {
    printf("Scrambling...\n");
    srand(time(0));

    // �������� ���� �� ȸ��
    for (int i = 0; i < 10; i++) {
        int face = rand() % FACES;

        switch (face) {
        case 0: rotateU(); printf("U "); break;
        case 1: rotateL(); printf("L "); break;
        case 2: rotateF(); printf("F "); break;
        case 3: rotateR(); printf("R "); break;
        case 4: rotateB(); printf("B "); break;
        case 5: rotateD(); printf("D "); break;
        }
    }
    printf("\n");
}

// ���� �Լ�
int main() {
    initCube();  // ť�� �ʱ�ȭ
    printf("Initial Cube:\n");
    printCube(STRING);  // ť�� ��� (STRING ���)

    scrambleCube();  // ť�� ����
    printf("Scrambled Cube:\n");
    printCube(STRING);  // ���� ť�� ��� (STRING ���)

    return 0;
}
