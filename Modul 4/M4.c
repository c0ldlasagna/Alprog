#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa
{
    struct{
        int semester;
        float ipk;
        char jurusan[32];
    } AcademicInfo;
    struct{
        char nama[32],alamat[64],npm[16];
    } PersonalInfo;
    char kesibukan[32];
} Mahasiswa;

Mahasiswa create() {
    Mahasiswa m;
    printf("Data Personal:\n");

    printf("Nama: ");
    fgets(m.PersonalInfo.nama, 32, stdin);
    m.PersonalInfo.nama[strcspn(m.PersonalInfo.nama, "\n")] = '\0';

    printf("NPM: ");
    fgets(m.PersonalInfo.npm, 32, stdin);
    m.PersonalInfo.npm[strcspn(m.PersonalInfo.npm, "\n")] = '\0';

    printf("Alamat: ");
    fgets(m.PersonalInfo.alamat, 64, stdin);
    m.PersonalInfo.alamat[strcspn(m.PersonalInfo.alamat, "\n")] = '\0';

    printf("Jurusan: ");
    fgets(m.AcademicInfo.jurusan, 32, stdin);
    m.AcademicInfo.jurusan[strcspn(m.AcademicInfo.jurusan, "\n")] = '\0';

    printf("Semester: ");
    scanf("%d", &m.AcademicInfo.semester);

    printf("IPK: ");
    scanf("%f", &m.AcademicInfo.ipk);

    while ((getchar()) != '\n');

    printf("Kesibukan: ");
    fgets(m.kesibukan, 32, stdin);
    m.kesibukan[strcspn(m.kesibukan, "\n")] = '\0';
    printf("Mahasiswa Ditambahkan!\n");
    return m;
}

void display(Mahasiswa m) {
    printf("%s - %s\n", m.PersonalInfo.nama, m.PersonalInfo.npm);
    printf("Alamat: %s\n", m.PersonalInfo.alamat);
    printf("Jurusan: %s\n", m.AcademicInfo.jurusan);
    printf("Semester %d\n", m.AcademicInfo.semester);
    printf("IPK %.2f\n", m.AcademicInfo.ipk);
    printf("Kesibukan: %s\n", m.kesibukan);
}
int main(){
    int capacity = 2; 
    Mahasiswa *list = (Mahasiswa*)malloc(capacity * sizeof(Mahasiswa));
    int count = 0; 
    while(1){
        printf("\nDatabase Kuliah\n---------------\n");
        printf("1. Show Mahasiswa\n2. Mahasiswa Baru\n3. Exit\n\n");
        int option;
        scanf("%d", &option);
        while ((getchar()) != '\n');
        switch (option)
        {
        case 1:
            printf("\nList Mahasiswa\n---------------\n\n");
            for (int i = 0; i < count; i++)
            {
                printf("%d. ", i + 1);
                display(list[i]);
                printf("\n");
            }
            break;
        case 2:
        printf("\nAdd Mahasiswa\n---------------\n");
            if (count == capacity)
            {
                capacity *= 2;
                list = (Mahasiswa*)realloc(list, capacity * sizeof(Mahasiswa));
            }
            list[count++] = create();
            break;
        case 3:
            printf("\nProgram selsai!\n");
            free(list);
            return 0;
        default:
            break;
        }
    }
    return 0;   
}