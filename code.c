#include <stdio.h>
#include <stdlib.h>
int **allocate(int students, int cours){
    int **matrix;
    matrix=(int **)malloc(students*sizeof(int *));
    for(int i=0;i<students;i++){
        *(matrix+i)=(int *)malloc(cours*sizeof(int));
        if(*(matrix+i)==NULL){
            printf("unable to allocate memory");
            exit(EXIT_FAILURE);
        }
    }
    if(matrix==NULL){
        printf("unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    return matrix;
}
void getnotes(int **matrix,int students, int cours){
    for(int i=0;i<students;i++){
        printf("student %d: \n",i+1);
        for(int j=0;j<cours;j++){
            printf("enter the note of %d cour: ",j+1);
            scanf("%d",(*(matrix+i)+j));
        }
    }
}
void printarray(int **matrix, int students, int cours){
    for(int i=0;i<students;i++){
        for(int j=0;j<cours;j++){
            printf("%d",*(*(matrix+i)+j));
        }
        printf("\n");
    }
}
void max(int **matrix, int students, int cours){
    printf("highest note by course: ");
    for(int j=0;j<cours;j++){
        int max = *(*matrix+j);
        for(int i=0;i<students;i++){
            if(*(*(matrix+i)+j)>max){
                max = *(*(matrix+i)+j);
            }
        }
        printf("cours %d: %d\n ",j+1,max);
    }
}

void moycours(int **matrix, int students, int cours){
    printf("moyen by cours: \n");
    for(int j=0;j<cours;j++){
        double sum = 0.0;
        for(int i=0;i<students;i++){
            sum = sum + *(*(matrix+i)+j);
        }
        printf("moy of %d : %lf\n",j+1,sum/students);
    }
}
void moystudents(int **matrix, int students, int cours){
    printf("moyen by student: \n");
    for(int i=0;i<students;i++){
        double sum = 0.0;
        for(int j=0;j<cours;j++){
            sum = sum + *(*(matrix+i)+j);
        }
        printf("moy of %d: %lf\n",i+1,sum/cours);
    }
}
void Freememory(int **matrice, int lignes) {
    for (int i = 0; i < lignes; i++) {
        free(*(matrice + i));
    }
    free(matrice);
}
int main(){
    int students, cours;
    printf("plz enter students and cours: ");
    scanf("%d%d",&students,&cours);
    int **grades= allocate(students,cours);
    getnotes(grades,students,cours);
    printarray(grades,students,cours);
    max(grades,students,cours);
    moycours(grades,students,cours);
    moystudents(grades,students,cours);
    Freememory(grades,students);
    return 0;
}
