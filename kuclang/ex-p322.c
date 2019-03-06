#include <stdio.h>

void get_max_min(int *, int *);
void get_max_and_min(int *, int *, int);

int main() {
  int input[10];
  int ans[2];
  int i;
  for(i=0;i<10;i++){
    if(scanf("%d", &input[i]) != 1){
      return -1;
    }
    if(input[i] != -1 && (0 > input[i] || input[i] > 100)){
      printf("%s\n", "0~100の数値を入力してください");
      i--;
      continue;
    }
    if(input[i] == -1) break;
    printf("input[%d] = %d\n", i, input[i]);
  }
  // get_max_and_min(ans, input, i);
  get_max_min(ans, input);
  printf("min: %d\nmax: %d\n", ans[0], ans[1]);
  return 0;
}

void get_max_min(int *answer, int *array){
  int i = 0;
  // answer[0] is min;
  answer[0] = 101;
  // answer[1] is max;
  answer[1] = -1;
  while(array[i] != -1 && i < 10){
    if(array[i] < answer[0]) answer[0] = array[i];
    if(array[i] > answer[1]) answer[1] = array[i];
    i++;
  }
}

void get_max_and_min(int *answer, int *array, int index){
  // answer[0] is min;
  answer[0] = 101;
  // answer[1] is max;
  answer[1] = -1;
  for(int i=0;i<index;i++){
    if(array[i] == -1) break;
    if(array[i] < answer[0]) answer[0] = array[i];
    if(array[i] > answer[1]) answer[1] = array[i];
  }
}
