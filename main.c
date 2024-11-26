#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void 단어의추가화면() {
    printf("단어의 추가를 하는 화면 입니다.\n");
    char second_command[100];
    while (1) {
        printf("명령어를 입력해주세요>>");
        fgets(second_command, sizeof(second_command), stdin);
        second_command[strcspn(second_command, "\n")] = '\0';
        if (strcmp(second_command, "나가기") == 0) {
            break;
        }
    }
}

void 암기연습화면() {
    printf("암기 연습을 위한 화면입니다.\n");
    char second_command[100];
    while (1) {
        printf("명령어를 입력해주세요>>");
        fgets(second_command, sizeof(second_command), stdin);
        second_command[strcspn(second_command, "\n")] = '\0';
        if (strcmp(second_command, "나가기") == 0) {
            break;
        }
    }
}

void 테스트화면() {
    printf("테스트를 위한 화면 입니다.\n");
    char second_command[100];
    while (1) {
        printf("명령어를 입력해주세요>>");
        fgets(second_command, sizeof(second_command), stdin);
        second_command[strcspn(second_command, "\n")] = '\0';
        if (strcmp(second_command, "나가기") == 0) {
            break;
        }
    }
}

void 통계화면() {
    printf("통계 화면 입니다.\n");
    char second_command[100];
    while (1) {
        printf("명령어를 입력해주세요>>");
        fgets(second_command, sizeof(second_command), stdin);
        second_command[strcspn(second_command, "\n")] = '\0';
        if (strcmp(second_command, "나가기") == 0) {
            break;
        }
    }
}

void command_execute(char *command){
    if(strcmp(command,"단어의추가")==0){
        단어의추가화면();
    }
    else if(strcmp(command,"암기연습")==0){
        암기연습화면();
    }
    else if(strcmp(command,"테스트")==0){
        테스트화면();
    }
    else if(strcmp(command,"통계")==0){
        통계화면();
    }
    else{
        printf("알 수 없는 명령어입니다.\n");
    }

}

int main(){
    char command[1000];
    while(1){
        printf("이곳은 시작화면 입니다. 명령어를 입력해주세요\n>>");
        fgets(command,sizeof(command),stdin);
        command[strcspn(command,"\n")]='\0';

        if(strcmp(command,"종료")==0){
            printf("프로그램을 종료합니다.\n");
            break;
        }
        
        command_execute(command);

    }
}