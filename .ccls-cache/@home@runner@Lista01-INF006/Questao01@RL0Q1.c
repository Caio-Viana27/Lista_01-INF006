#include <stdio.h>

typedef struct {
  int x;
  int y;
} Point;

float distance(Point points[], int i);
float distanceZero(Point points[], int i);
float shortcut(Point points[], int j);
float squareRoot(float x);
float power(float x);

void quicksort (Point points[], int length);
void quicksort_recursion (Point points[], int low, int high);
int partition(Point points[], int low, int high);
void swap(Point points[], int i, int j);
void print_array(Point array[], int length);

int main() {

  FILE *file;
  file = fopen("L0Q1.in", "r");
  if (file == NULL) {
    printf("1Erro ao abrir o arquivo!\n");
    return 1;
  }

  char linha[1000];
  int linhasLidas = 1;

  while (fgets(linha, sizeof(linha), file) != NULL) {

    Point points[1000];
    int j = 0;
    for (int i = 0; linha[i] != '\0'; i++) {
      if (linha[i] == '(') {
        sscanf(linha + i, "(%d,%d)", &points[j].x, &points[j].y);
        j++;
      }
    }
    float distancia = 0;

    for (int i = 0; i < j-1; i++) {
      float resultado = distance(points, i);
      distancia += resultado;
    }
    float atalho;
    atalho = shortcut(points, j-1);

    quicksort (points, j);

    FILE *saida;
    saida = fopen("L0Q1_TESTE.out", "a");
    if (file == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return 1;
    }

    fprintf(saida, "points ");

    for (int i = 0; i < j; i++) {
      fprintf(saida, "(%d,%d) ", points[i].x, points[i].y);
    }
    fprintf(saida, "distance %.2f ", distancia);
    fprintf(saida, "shortcut %.2f\n", atalho);

    fclose(saida);
  }

  fclose(file);

  return 0;
}

float squareRoot(float x) {
  if (x < 0) {
    return -1;
  }
  float left = 0, right = x + 1;

  for (int i = 0; i < 2000; i++) {
    float middle = (left + right) / 2;
    if (middle * middle < x) {
      left = middle;
    } else {
      right = middle;
    }
  }
  return left;
}

float power(float x) {
  return x * x;
}

float distance(Point points[], int i) {

  float x = points[i].x - points[i+1].x;
  float y = points[i].y - points[i+1].y;
  float distancia = power(x) + power(y);
  return squareRoot(distancia);
}

float shortcut(Point points[], int j) {

  float x = points[0].x - points[j].x;
  float y = points[0].y - points[j].y;
  float distancia = power(x) + power(y);
  return squareRoot(distancia);
}

void quicksort (Point points[], int length) {
  quicksort_recursion(points, 0, length - 1);
}

void quicksort_recursion (Point points[], int low, int high) {

  if (low < high) {
  int pivot_index = partition(points, low, high);
  quicksort_recursion (points, low, pivot_index-1);  // Direito
  quicksort_recursion (points, pivot_index+1, high); // Esquerdo
  }
}

int partition(Point points[], int low, int high) {

  int i = low;

  for(int j = low; j < high; j++) {
    if(distanceZero(points, j) <= distanceZero(points, high)) {
      swap(points, i, j);
      i++;
    }
  }
  swap(points, i, high);
  return i;
}

void swap(Point points[], int i, int j) {
  Point temp = points[j];
  points[j] = points[i];
  points[i] = temp;
}

void print_array(Point points[], int length) {
  for (int i = 0; i < length; i++) {
    printf("(%d,%d) ", points[i].x, points[i].y);
  }
}

float distanceZero(Point points[], int i) {

  float x = points[i].x - 0;
  float y = points[i].y - 0;
  float distancia = power(x) + power(y);
  return squareRoot(distancia);
}