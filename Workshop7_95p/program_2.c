/*
 * program 2
 * program_2.c
 * Nguyen Tri Phuc - HE176442
 * date: 08.07.2022
 */
#include<stdio.h>
#include<string.h>

int main() {
	/* Input */
	printf("Enter your name: ");
	char name[100];
	scanf("%[^\n]s", name);
	getchar();
	/* End of Input */

	/* Implement */
	int n = strlen(name); /// length of user's name
	char mail_add[100]; /// string before @ in mail address
	int id = 0; /// index of current character in mail_add
	int i;
	/* Convert all letter character to lower letter */
	for(i = 0; i < n; ++i)
		if(name[i] >= 'A' && name[i] <= 'Z')
			name[i] += 32;
	if(name[0] >= 'a' && name[0] <= 'z')
	{
		mail_add[id] = name[0];
		id++;
	}
	int pos_name; /// index of charater in the last word(last name)
	/* add headding character in each word to mail address */
	for(i = 1; i < n; ++i)
		if('a' <= name[i] && name[i] <= 'z' && name[i-1] == ' ')
		{
			mail_add[id] = name[i];
			id++;
			pos_name = i+1;
		}
	/* add last word(last name) to mail address */
	while(pos_name < n && 'a' <= name[pos_name] && name[pos_name] <= 'z')
	{
		mail_add[id] = name[pos_name];
		id++;
		pos_name++;
	}	
	name[id] = '\0'; /// make it to be string type
	/* End of Implement */

	/* Output */
	printf("Your FPT maill will be: %s", mail_add);
	printf("@fpt.edu.vn");
	/* End of Output */

    return 0;
}



