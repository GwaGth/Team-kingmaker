#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100   // 최대 단어 수
#define MAX_LENGTH 100  // 단어의 최대 길이

typedef struct Word {
    char word[MAX_LENGTH];   // 단어
    char meaning[MAX_LENGTH]; // 의미
} Word;

Word* wordList;  // 동적으로 할당된 단어 목록
int wordCount = 0; // 현재 단어 수

// 함수 선언
void addWord();
void displayWords();
void saveToFile();
void practiceWord();
void testWord();
void statics();
void manageWord() {
    int flag = 0;
    int choice;
    while (1) {
        if (flag != 0) {
            break;
        }
        printf("\n=== 단어 관리 시스템 ===\n");
        printf("1. 단어 추가\n");
        printf("2. 모든 단어 보기\n");
        printf("3. 파일로 저장\n");
        printf("4. 뒤로가기\n");
        printf("작업을 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addWord();
            break;
        case 2:
            displayWords();
            break;
        case 3:
            saveToFile();
            break;
        case 4:
            free(wordList); // 동적 메모리 해제
            printf("프로그램을 종료합니다.\n");
            flag = 1;
            break;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }
};

// 단어 추가
void addWord() {
    if (wordCount >= MAX_WORDS) {
        printf("단어 목록이 가득 찼습니다. 더 이상 추가할 수 없습니다!\n");
        return;
    }

    char tempWord[MAX_LENGTH], tempMeaning[MAX_LENGTH];

    printf("단어를 입력하세요: ");
    scanf_s("%s", tempWord, (unsigned)_countof(tempWord));

    // 중복 단어 확인
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, tempWord) == 0) {
            printf("이미 존재하는 단어입니다. 추가할 수 없습니다.\n");
            return;
        }
    }

    printf("단어의 의미를 입력하세요: ");
    scanf_s("%s", tempMeaning, (unsigned)_countof(tempMeaning));

    // 단어를 목록에 추가
    strcpy_s(wordList[wordCount].word, MAX_LENGTH, tempWord);
    strcpy_s(wordList[wordCount].meaning, MAX_LENGTH, tempMeaning);
    wordCount++;
    printf("단어가 성공적으로 추가되었습니다!\n");
}

// 모든 단어 보기
void displayWords() {
    if (wordCount == 0) {
        printf("현재 단어가 없습니다. 단어를 먼저 추가하세요.\n");
        return;
    }

    printf("\n=== 단어 목록 ===\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%d. %s: %s\n", i + 1, wordList[i].word, wordList[i].meaning);
    }
}

// 파일로 단어 저장
void saveToFile() {
    FILE* file;
    fopen_s(&file, "wordlist.txt", "w");
    if (file == NULL) {
        printf("파일 저장에 실패했습니다!\n");
        return;
    }

    for (int i = 0; i < wordCount; i++) {
        fprintf(file, "%s %s\n", wordList[i].word, wordList[i].meaning);
    }

    fclose(file);
    printf("단어가 파일에 성공적으로 저장되었습니다.\n");
}

// 단어연습
void practiceWord() {
    int choice;
    int flag = 0;
    while (1) {
        if (flag == 1) {
            break;
        }
        printf("\n=== 단어 연습 ==\n");
        printf("1.뒤로가기\n");
        // 내용추가해야함
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("뒤로갑니다.\n");
            flag = 1;
            break;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }
}

void testWord() {
    int choice;
    int flag = 0;
    while (1) {
        if (flag == 1) {
            break;
        }
        printf("\n=== 단어 테스트 ==\n");
        printf("1.뒤로가기\n");
        // 내용추가해야함
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("뒤로갑니다.\n");
            flag = 1;
            break;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }
};

void statics() {
    int choice;
    int flag = 0;
    while (1) {
        if (flag == 1) {
            break;
        }
        printf("\n=== 통계 ==\n");
        printf("1.뒤로가기\n");
        // 내용추가해야함
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("뒤로갑니다.\n");
            flag = 1;
            break;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }
};

int main() {
    wordList = (Word*)malloc(MAX_WORDS * sizeof(Word)); // 동적 메모리 할당
    if (wordList == NULL) {
        printf("메모리 할당에 실패했습니다!\n");
        return 1;
    }

    int choice;

    while (1) {
        printf("\n=== 시작화면 ===\n");
        printf("1. 단어 관리\n");
        printf("2. 단어 연습\n");
        printf("3. 테스트\n");
        printf("4. 통계\n");
        printf("5. 종료\n");
        printf("작업을 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            manageWord();
            break;
        case 2:
            practiceWord();
            break;
        case 3:
            testWord();
            break;
        case 4:
            statics();
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
        }
    }
    return 0;
}