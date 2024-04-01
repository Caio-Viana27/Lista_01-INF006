//d = sqrt((xb - xa)^2 + )
#include <stdio.h>

typedef struct {
  int x;
  int y;
} points;

int main() {
  FILE *file;
  file = fopen("L0Q1.txt", "r");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo!");
    return 1;
  }

  points point;
  int i = 0;

  while(fscanf(file, "(%d, %d)", &point.x, &point.y) == 2) {
    printf("(%d, %d)\n", point.x, point.y);
    i++;
  }

  fclose(file);

  return 0;
}
/*#include <stdio.h>

typedef struct {
  int x;
  int y;
} points;

int main() {
  
  FILE *file;
  file = fopen("L0Q1.txt", "r");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo!");
  }

  points points[1000];

  /* for (int i = 0; file != EOF; i++) {
    
    if ((file -1) == '(') {
      fscanf(file, "%d", points.*x + i);
      
    }else if ((file -1) == ',') {
      fscanf(file, "%d", points.*y + i);
    }
  } */
  /* for (int i = 0; i < sizeof(points.x); i++) {
    printf("%d", points.*x + i);
    printf("%d", points.*y + i);
  } 
  
  fclose(file);
  
return 0;
}*/


