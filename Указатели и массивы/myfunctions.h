#pragma once

void binout(char, char = '\n');

unsigned int myrnd();
int myrnd(int a, int b);
double myrnd(double x, double y, int n = 3);
void myrnd(int* M, int size, int a, int b);
void myrnd(double* M, int size, double x, double y, int n);

void myout(int* M, int size, int nc = -1, int nw = 4);
void myout(double* M, int size, int nc = -1, int nw = 8, int nq = 3);

void mysrt(int* M, int size, bool inc = true);
void mysrt(double* M, int size, bool inc = true);

int mymax(int* M, int size);
int mymax(double* M, int size);

int mymin(int* M, int size);
int mymin(double* M, int size);