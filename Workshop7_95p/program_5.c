/*
 * program 5
 * program_5.c
 * Nguyen Tri Phuc - HE176442
 * date: 09.07.2022
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/// check if input plate is correct
int checkFormat(char *str)
{
    char s[20];
    int n = 0;
    while(*str)
        s[n] = *str, n++, str++;
    
    s[n] = '\0';
    if(n != 12)
        return 0;
    if(s[2] != '-')
        return 0;
    if(s[3] < 'A' || s[3] > 'Z')
        return 0;
    if(s[5] != ' ')
        return 0;
    if(s[9] != '.')
        return 0;
    int i;
    for(i = 0; i < 12; ++i)
    {
        if(i == 2 || i == 3 || i == 5 || i == 9)
            continue;
        if(s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}
/// check if plate is nice
int checkNice_plate(char *str)
{
    char s[12];
    int n = 0;
    while(*str)
        s[n] = *str, n++, str++;
    s[n] = '\0';
    
    int i;
    int arr[10];
    int id = 0;
    /// get all numbers into array
    for(i = 0; i < n; ++i)
    {
        if(i == 2 || i == 3 || i == 5 || i == 9)
            continue;
        arr[id] = s[i] - '0';
        id++;
    }

    int ok = 1;
    /// condition 1
    for(i = 3; i < 7; ++i)
        if(arr[i] >= arr[i+1])
            ok = 0;
    if(ok)
        return 1;

    /// condition 2 and 3 are the same
    if(arr[3] == arr[4] && arr[4] == arr[5] && arr[6] == arr[7])
        return 1;

    /// condition 4
    ok = 1;
    for(i = 3; i <= 7; ++i)
        if(arr[i] != 8 && arr[i] != 6)
            ok = 0;
    return ok;
}
int main()
{
    /* Implement */
    char plate[20];
    while(1)
    {
        printf("Enter the motorcycle license plate : ");
        scanf("%[^\n]s", plate);
        getchar();
        if(strlen(plate) == 1 && plate[0] == '0')
            break;
        if(checkFormat(plate) == 0)
        {
            printf("Wrong input format\n");
            continue;
        }
        if(checkNice_plate(plate))
            printf("YES\n");
        else
            printf("NO\n");
    }
    /* End of Implement */

    return 0;
}



