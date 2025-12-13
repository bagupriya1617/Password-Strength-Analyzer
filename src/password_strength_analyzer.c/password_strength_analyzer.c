#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i;

int hasUpper(char *p) {
    for( i = 0; p[i]; i++)
        if(isupper(p[i])) return 1;
    return 0;
}

int hasLower(char *p) {
    for( i = 0; p[i]; i++)
        if(islower(p[i])) return 1;
    return 0;
}

int hasDigit(char *p) {
    for( i = 0; p[i]; i++)
        if(isdigit(p[i])) return 1;
    return 0;
}

int hasSpecial(char *p) {
    for( i = 0; p[i]; i++)
        if(!isalnum(p[i])) return 1;
    return 0;
}

int hasRepeatedChars(char *p) {
    for( i = 0; p[i]; i++)
        if(p[i] == p[i+1]) return 1;
    return 0;
}

int hasCommonPattern(char *p) {
    if(strstr(p, "123") || strstr(p, "abc") || strstr(p, "password"))
        return 1;
    return 0;
}

int main() {
    char password[100];
    int score = 0;

    printf("Enter password: ");
    scanf("%s", password);

    int length = strlen(password);

    // Length scoring
    if(length >= 8) score += 2;
    if(length >= 12) score += 2;

    // Character variety
    if(hasLower(password)) score++;
    if(hasUpper(password)) score++;
    if(hasDigit(password)) score++;
    if(hasSpecial(password)) score++;

    // Weakness checks
    if(hasRepeatedChars(password)) score--;
    if(hasCommonPattern(password)) score--;

    // Display result
    printf("\nPassword Analysis:\n");
    printf("Length: %d\n", length);

    printf("Strength: ");
    if(score <= 2)
        printf("Very Weak\n");
    else if(score <= 4)
        printf("Weak\n");
    else if(score <= 6)
        printf("Medium\n");
    else if(score <= 8)
        printf("Strong\n");
    else
        printf("Very Strong\n");

    // Suggestions
    printf("\nSuggestions:\n");
    if(length < 8) printf("- Increase password length\n");
    if(!hasUpper(password)) printf("- Add uppercase letters\n");
    if(!hasLower(password)) printf("- Add lowercase letters\n");
    if(!hasDigit(password)) printf("- Add digits\n");
    if(!hasSpecial(password)) printf("- Add special characters\n");
    if(!hasCommonPattern(password)) printf("- Avoid Common Patterns\n");

    

    return 0;
}

