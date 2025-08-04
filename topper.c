#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int marks[5];
    float average;
};

void inputs(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        getchar();
        fgets(s[i].name, 50, stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';
        
        printf("Enter marks for 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
        }
    }
}

void Average(struct Student *s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s->marks[i];
    }
    s->average = total / 5.0;
}

void Topper(struct Student s[], int n) {
    int topper = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].average > s[topper].average) {
            topper = i;
        }
    }
    printf("\nTopper Details:\n");
    printf("ID: %d\n", s[topper].id);
    printf("Name: %s\n", s[topper].name);
    printf("Average Marks: %.2f\n", s[topper].average);
}

int main() {
    int n = 5;
    struct Student students[n];

    inputs(students, n);

    for (int i = 0; i < n; i++) {
        Average(&students[i]);
    }

    Topper(students, n);

    return 0;
}
