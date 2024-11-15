#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 3
#define FACES 6

// 큐브 면 색상, 문자, 16진수 색상
char* colors[FACES] = { "white", "red", "blue", "green", "orange", "yellow" };
char letters[FACES] = { 'w', 'r', 'b', 'g', 'o', 'y' };
int hexColors[FACES] = { 0xFFF, 0xF00, 0x00F, 0x0F0, 0xFA0, 0xFF0 };

// 큐브 배열 (3x3x6)
int cube[LENGTH][LENGTH][FACES];

enum PrintMode { STRING, LETTER, HEX };

// 큐브 초기화
void initCube() {
    for (int i = 0; i < FACES; i++) {
        for (int j = 0; j < LENGTH; j++) {
            for (int k = 0; k < LENGTH; k++) {
                cube[j][k][i] = i;  // 각 면에 색상 초기화
            }
        }
    }
}

// 큐브 출력
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

// 큐브의 면을 시계방향으로 90도 회전하는 함수
void rotateFace(int face) {
    int temp[LENGTH][LENGTH];

    // 면 복사
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            temp[i][j] = cube[i][j][face];
        }
    }

    // 시계방향으로 90도 회전
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            cube[i][j][face] = temp[LENGTH - 1 - j][i];
        }
    }
}

// 큐브의 각 면에 대해 회전하는 함수들
void rotateU() {  // Up 면 회전
    rotateFace(0);
}

void rotateL() {  // Left 면 회전
    rotateFace(1);
}

void rotateF() {  // Front 면 회전
    rotateFace(2);
}

void rotateR() {  // Right 면 회전
    rotateFace(3);
}

void rotateB() {  // Back 면 회전
    rotateFace(4);
}

void rotateD() {  // Down 면 회전
    rotateFace(5);
}

// 큐브의 각 면의 엣지들을 회전하는 함수들
void rotateUEdge() {
    int temp[LENGTH];
    // 상단 엣지 (Up 면의 위쪽 행과 Down, Left, Right, Back 면의 상단 줄)
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

    // 랜덤으로 여러 번 회전
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

// 메인 함수
int main() {
    initCube();  // 큐브 초기화
    printf("Initial Cube:\n");
    printCube(STRING);  // 큐브 출력 (STRING 모드)

    scrambleCube();  // 큐브 섞기
    printf("Scrambled Cube:\n");
    printCube(STRING);  // 섞인 큐브 출력 (STRING 모드)

    return 0;
}
