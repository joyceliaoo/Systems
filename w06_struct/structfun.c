#include <stdio.h>
#include <stdlib.h>

struct person {char * name; int age;};
struct person gen(char * new_name, int new_age);
void print_struct(struct person x);
struct person update(struct person x, int current_age);

struct person gen(char * new_name, int new_age){
  struct person p0;
  p0.name = new_name;
  p0.age = new_age;
  return p0;
}

void print_struct(struct person x){
  printf("name: %s, age: %d \n", x.name, x.age);
}

struct person update(struct person x, int current_age){
  x.age = current_age;
  return x;
}

int main(){
  //create new struct
  struct person p0 = gen("Mr. DW", 10);
  //prints new struct
  printf("Teacher 0: \n");
  print_struct(p0);

  //updates age
  printf("Teacher 0 grew old... \n");
  p0 = update(p0, 1000);
  print_struct(p0);

  printf("Teacher 1: \n");
  struct person p1 = gen("Mr. Holmes", 5);
  print_struct(p1);
  printf("Teacher 1 grew old too... \n");
  p1 = update(p1, 6);
  print_struct(p1);

  printf("Teacher 2: \n");
  struct person p2 = gen("Mr. Brooks", 1001);
  print_struct(p2);
  p2 = update(p2, 1234);
  printf("Teacher 2 as well... \n");
  print_struct(p2);

  printf("Teacher 3: \n");
  struct person p3 = gen("Mr. K", 200);
  print_struct(p3);
  p3 = update(p3, 404);
  printf("Same goes for teacher 3... \n");
  print_struct(p3);
  

  return 0;
}


  
