#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <limits.h>

#define FALSE 0
#define TRUE 1

typedef struct {
  char name[10];
  int age;
  int sex;
} person;

void set_person(person *);
void get_person(person);

int main() {
  int i = 0, j, size = 1;
  person *pperson = (person *)malloc(sizeof(person)*size);

  while(TRUE){
    set_person(&pperson[i]);
    if(pperson[i].age < 0) break;
    i++;
    if(i>=size){
      size+=1;
      pperson = realloc(pperson, sizeof(person)*size);
      printf("reallocが実行されました -> size: %d\n", size);
    }
  }

  printf("%s\n", " - - - - - - - - - - - - - - - - - - - - - - - -");

  for(j=0;j<i;j++){
    get_person(pperson[j]);
  }
  free(pperson);
  return 0;
}

// scanf関数は、予期せぬ値が入力されると、その値を読み込まず、ストリーム上に残してしまう。
// scanf は良くないらしい？

void set_person(person *person){
  printf("%s", "名前を入力してください: ");
  scanf("%s", person->name);
  printf("%s", "年齢を入力してください: ");
  // ここで %d で吸収できない 'a' とかが入力されると、予期せぬ数値がストリームに残ったままdo while文へ突入する
  // 1879048192 とかが入力ストリームに残っちゃって0~2でないため、無限ループ
  while(scanf("%d", &person->age) != 1){
    printf("%s", "適切な数値を入力してください: ");
    // rewind(stdin);
    if(fseek(stdin, 0L, SEEK_SET) != 0){
      printf("%s\n", "fseek失敗");
      return;
    }
  }
  do {
    printf("%s", "性別(0 is woman, 1 is man, 2 is other)を入力してください: ");
    scanf("%d", &person->sex);
  } while(!(person->sex == 0 || person->sex == 1 || person->sex == 2));
}

void get_person(person person){
  switch (person.sex) {
    case 0:
      printf("名前: %s, 年齢: %d, 性別: %s\n", person.name, person.age, "woman");
      break;
    case 1:
      printf("名前: %s, 年齢: %d, 性別: %s\n", person.name, person.age, "man");
      break;
    case 2:
      printf("名前: %s, 年齢: %d, 性別: %s\n", person.name, person.age, "other");
      break;
  }
}


/*

static int count;

if(person->age == -1){
  return -1*count;
}

return count;

 */
